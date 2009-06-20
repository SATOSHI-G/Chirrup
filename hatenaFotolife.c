/*
 * hatenaFotolife.c : Twitter �N���C�A���g chirrup
 *      �͂Ăȃt�H�g���C�t �֘A�e�폈���Q
 *          written by H.Tsujimura  19 Jan 2008
 *
 *      Copyright (c) 2008 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/hatenaFotolife.c $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 2     08/01/23 17:39 Tsujimura543
 * ���� + ����m�F�A����
 * 
 * 1     08/01/19 0:30 Tsujimura543
 * �ŏ��̔� (�X�P���g��)
 */


#include <time.h>
#include "xmlRpc.h"
#include "multipart.h"
#include "utility.h"
#include "hatenaFotolife.h"
#include "http.h"

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/chirrup/hatenaFotolife.c 1     09/05/14 3:50 tsupo $";
#endif


// �͂Ăȃt�H�g���C�t �Ɂu�摜�v�𓊍e����
BOOL
postPhotoOnHatenaFotolife(
    const char  *filename,       // (I) ���e����摜�̃t�@�C����
    size_t      filesize,        // (I) ���e����摜�̃t�@�C���T�C�Y
    MIMAGE_TYPE filetype,        // (I) ���e����摜�̃t�@�C�����
    const char  *title,          // (I) ���e����摜�́u�薼�v
    const char  *hatenaID,       // (I) �͂Ă� ID
    const char  *hatenaPassword, // (I) �͂Ă� �p�X���[�h
    char        *url )           // (O) �A�b�v���[�h��URL
{
    BOOL    ret = FALSE;
    char    wsse[BUFSIZ];
    char    endpoint[MAX_URLLENGTH];
    char    *request;
    char    *response;
    char    *imageData;
    char    *p;
    size_t  sz1    = filesize * 6 + BUFSIZ;
    size_t  sz2    = MAX_CONTENT_SIZE;
    size_t  szBase = 0;
    FILE    *fp;
    FILEINF fInfo;
    char    *targetTitle;
    int     blogKind;

    // ����
    if ( !title || !(*title) ) {
        p = strrchr( filename, '/' );
        if ( !p )
            p = strrchr( filename, '\\' );
        if ( !p )
            p = strrchr( filename, ':' );
        if ( p ) {
            p++;
            title = p;
        }
        else
            title = " ";
    }
    targetTitle = (char *)malloc( strlen(title) * 6 + 1 );
    if ( !targetTitle ) {
        return ( ret );
    }

    p = any2utf( title );
    strcpy( targetTitle, p ? p : title );

    // �A�b�v���[�h
    imageData = (char *)malloc( filesize + 1 );
    if ( !imageData ) {
        free( targetTitle );
        return ( ret );
    }

    fp = fopen( filename, "rb" );
    if ( !fp ) {
        free( imageData );
        free( targetTitle );
        return ( ret );
    }
    fread( imageData, filesize, 1, fp );
    fclose( fp );

    request  = (char *)malloc( sz1 );
    if ( !request ) {
        free( imageData );
        free( targetTitle );
        return ( ret );
    }
    response = (char *)malloc( sz2 );
    if ( !response ) {
        free( request );
        free( imageData );
        free( targetTitle );
        return ( ret );
    }
    memset( request, 0x00, sz1 );

    // �A�b�v���[�h����t�@�C���̏����Z�b�g
    strcpy( fInfo.type, "application/unknown" );    /* �b�� */
    strcpy( fInfo.name, filename );

    p = base64( (unsigned char *)imageData, filesize );
    if ( !p ) {
        base64( NULL, 0 );
        free( response );
        free( request );
        free( imageData );
        free( targetTitle );
        return ( ret );
    }
    szBase     = strlen( p );
    fInfo.bits = (unsigned char *)malloc( szBase + 1 );
    if ( !fInfo.bits ) {
        base64( NULL, 0 );
        free( response );
        free( request );
        free( imageData );
        free( targetTitle );
        return ( ret );
    }
    strcpy( (char *)fInfo.bits, p );

    if ( sz1 < szBase ) {
        size_t  sz11 = szBase + BUFSIZ;
        char    *pp  = (char *)realloc( request, sz11 );

        if ( pp ) {
            sz1     = sz11;
            request = pp;
            memset( request, 0x00, sz1 );
        }
    }

    // POST /atom/post
    //  <entry xmlns="http://purl.org/atom/ns#">
    //      <title>Sample</title>
    //      <content mode="base64" type="image/jpeg">/9j/2wCEAAQDAwQDAw.../9n/AA==</content>
    //  </entry>

    memset( wsse, 0x00, BUFSIZ );

    blogKind = BLOGKIND_HATENA;
    makeWSSE( hatenaID, hatenaPassword, wsse, blogKind );

    sprintf( endpoint, "%s/post", HATENA_F_ENDPOINT_URL );

    sprintf( request,
           "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>\r\n"
             "<entry xmlns=\"http://purl.org/atom/ns#\">\r\n"
             "<title>%s</title>\r\n"
             "<content mode=\"base64\" type=\"image/%s\">",
             targetTitle,
             filetype == MITYPE_JPG ? "jpeg" :
             filetype == MITYPE_GIF ? "gif" :
             filetype == MITYPE_PNG ? "png" :
             filetype == MITYPE_BMP ? "bmp" :
                                      "unknown" );
    sprintf( request + strlen(request),
             "%s",
             fInfo.bits );
    sprintf( request + strlen(request),
             "</content>\r\n"
             "</entry>" );

    http_postW( endpoint, wsse, NULL, NULL, request, response );

    if ( *response ) {
        p = strstr( response,
                    "<link rel=\"alternate\" type=\"text/html\" href=\"" );
        if ( p ) {
            char    *q;

            p += 45;
            q = strchr( p, '"' );
            if ( q ) {
                strncpy( url, p, q - p );
                url[q - p] = NUL;
                ret = TRUE;
            }
        }
    }

    base64( NULL, 0 );
    free( fInfo.bits );
    free( response );
    free( request );
    free( imageData );
    free( targetTitle );

    return ( ret );
}

