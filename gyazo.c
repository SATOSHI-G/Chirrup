/*
 * gyazo.c : Twitter �N���C�A���g chirrup
 *      Gyazo �֘A�e�폈���Q
 *          written by H.Tsujimura  6 Dec 2007 / 13 Dec 2007
 *
 *      Copyright (c) 2007 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/gyazo.c $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 1     07/12/13 19:14 Tsujimura543
 * Gyazo�֘A�̊֐��Q�� tumblr.c ���番���Ɨ�������
 */

#include <time.h>
#include "xmlRpc.h"
#include "multipart.h"
#include "utility.h"
#include "gyazo.h"

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/chirrup/gyazo.c 1     09/05/14 3:50 tsupo $";
#endif


char    *
getIDforGyazo( char *gyazoID )
{
    char    *p = NULL;

    if ( gyazoID ) {
        if ( *gyazoID )
            p = gyazoID;    // ���łɐݒ�ς݂� ID ���g���܂킷
        else {
            // �ŏ��̓��e���s���������� ID �𐶐��A�ݒ肷��
            char        timebuf[MAX_DATELENGTH];
            struct tm   *dt;
            time_t      now	= time( NULL );

            dt = localtime( &now );
            strftime( timebuf, MAX_DATELENGTH, "%Y%m%d%H%M%S", dt );

            strcpy( gyazoID, timebuf );
            p = gyazoID;
        }
    }

    return ( p );
}

BOOL
postPhotoOnGyazo(
    const char *filename,   // (I)   Gyazo �ɓ��e����摜�̃t�@�C����
    size_t     filesize,    // (I)   Gyazo �ɓ��e����摜�̃t�@�C���T�C�Y
    char       *gyazoID,    // (I/O) Gyazo ID
    char       *url )       // (O)   �A�b�v���[�h��URL
{
    BOOL    ret = FALSE;
    char    *request;
    char    *response;
    char    *imageData;
    char    *p;
    char    *base;
    char    *tail;
    size_t  sz1 = filesize * 6 + BUFSIZ;
    size_t  sz2 = MAX_CONTENT_SIZE;
    size_t  szz = 0;
    FILE    *fp;
    char    contentType[MAX_LOGICALLINELEN];
    char    *separator = getMultiPartID();
    FILEINF fInfo;

    imageData = (char *)malloc( filesize + 1 );
    if ( !imageData ) {
        return ( ret );
    }

    fp = fopen( filename, "rb" );
    if ( !fp ) {
        free( imageData );
        return ( ret );
    }
    fread( imageData, filesize, 1, fp );
    fclose( fp );

    request  = (char *)malloc( sz1 );
    if ( !request ) {
        free( imageData );
        return ( ret );
    }
    response = (char *)malloc( sz2 );
    if ( !response ) {
        free( request );
        free( imageData );
        return ( ret );
    }
    memset( request, 0x00, sz1 );

    // �A�b�v���[�h����t�@�C���̏����Z�b�g
    strcpy( fInfo.type, "application/unknown" );    /* �b�� */
    strcpy( fInfo.name, filename );

    p = base64( (unsigned char*)imageData, filesize );
    if ( !p ) {
        base64( NULL, 0 );
        free( response );
        free( request );
        free( imageData );
        return ( ret );
    }
    fInfo.bits = (unsigned char *)p;

    // multipart/form-data �̑g�ݗ���
    getSendBufferPointer( request, base );
    tail = base;

    sprintf( contentType, "multipart/form-data; boundary=%s", separator );

    strcpy( tail, 
            makeMultiPartItem( separator, MULITIPART_ITEM_TYPE_STRING,
                               "id", 0, getIDforGyazo( gyazoID ), NULL ) );

    szz  =  strlen( tail );
    tail += szz;
    szz  =  0;
    p    =  makeMultiPartItem( separator, MULITIPART_ITEM_TYPE_FILE,
                               "imagedata", 0, (char *)&fInfo, &szz );
    memcpy( tail, p, szz );
    tail += szz;

    sprintf( tail + strlen( tail ), "--%s--\r\n", separator );
    szz  =  strlen( tail );
    tail += szz;

    makeMultiPartItem( separator, MULITIPART_ITEM_TYPE_BUFFERFREE,
                       NULL, 0, NULL, NULL );

    // ���N�G�X�g���s
    setTimeoutTime( DEFAULT_HTTP_TIMEOUT * (1 + (filesize / (1024 * 1024))) );
                                    // �T�C�Y�ɔ�Ⴕ���^�C���A�E�g���Ԃ�ݒ�
    szz = tail - base;
    setUpSendBuffer( request, szz, base );
    setUpReceiveBuffer( response, sz2 );
    http_post( "http://gyazo.com/upload.cgi",
               contentType,
               request, response );

    if ( *response ) {
        if ( !strncmp( response, "http://gyazo.com/", 17 ) ) {
            ret = TRUE;
            if ( url )
                strcpy( url, response );
        }
    }

    base64( NULL, 0 );
    free( response );
    free( request  );
    free( imageData );

    return ( ret );
}
