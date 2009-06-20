/*
 * flickr.c : Twitter �N���C�A���g chirrup
 *      Flickr �֘A�e�폈���Q
 *          written by H.Tsujimura  9 Jan 2008
 *
 *      Copyright (c) 2008 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/flickr.c $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 6     09/04/22 21:31 Tsujimura543
 * GetAccessTokenOnFlickr() ���Łu����^����v�̂���߂��Ƃ���MessageBox
 * �ŕ\�����镶����ύX
 * 
 * 5     09/04/22 21:11 Tsujimura543
 * �u�ݒ�v�_�C�A���O�����Flickr�F�؂̃A�N�Z�X�g�[�N��(frob)���擾�ł���
 * �悤�ɂ���
 * 
 * 4     08/12/04 18:19 Tsujimura543
 * �R�[�h�����A���艻��Ƃ����{
 * 
 * 3     08/01/23 17:41 Tsujimura543
 * �ُ�n�������C��
 * 
 * 2     08/01/09 23:33 Tsujimura543
 * process global �� static �ȃ������̈�� thread local �� static
 * �ɕύX����
 * 
 * 1     08/01/09 23:01 Tsujimura543
 * �ŏ��̔� (����m�F�ς�)
 */

#include <time.h>
#include "xmlRpc.h"
#include "multipart.h"
#include "utility.h"
#include "flickr.h"
#include "MD5.h"

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/chirrup/flickr.c 1     09/05/14 3:50 tsupo $";
#endif

#ifdef  _MSC_VER
#define Thread  __declspec( thread )
#else
#define Thread
#endif

char *
ToLower( char *p )
{
    char    *s = p;
    while ( *s ) {
        if ( (*s >= 'A') && (*s <= 'Z') )
            *s = (char)((*s - 'A') + 'a');
        s++;
    }

    return ( p );
}


// api.flickr.com/services/upload �p signature ��������
char    *
getSinganureForFlickr(
        const char *secret,
        const char *flickrKey,
        const char *flickrToken,
        const char *title,
        const char *description
    )
{
    char                *p = NULL;
    Thread static char  signature[BUFSIZ];

    signature[0] = NUL;
    strcpy( signature, secret );

    sprintf( signature + strlen(signature),
             "api_key%s",
             flickrKey );

    sprintf( signature + strlen(signature),
             "auth_token%s",
             flickrToken );

    if ( description ) {
        if ( *description )
            sprintf( signature + strlen(signature),
                     "description%s",
                     description );
        else
            strcat( signature, "description" );
    }

    if ( title ) {
        if ( *title )
            sprintf( signature + strlen(signature),
                     "title%s",
                     title );
        else
            strcat( signature, "title" );
    }

    p = MD5(signature);
    if ( p )
        strcpy( signature, ToLower( p ) );
    else
        signature[0] = NUL;

    return ( signature );
}

// flickr.auth.getFrob �p signature ��������
char    *
getSinganureForGetFrob(
        const char *flickrSecret,
        const char *flickrKey
    )
{
    char                *p = NULL;
    Thread static char  signature[BUFSIZ];

    signature[0] = NUL;
    strcpy( signature, flickrSecret );

    sprintf( signature + strlen(signature),
             "api_key%s",
             flickrKey );

    sprintf( signature + strlen(signature),
             "method%s",
             "flickr.auth.getFrob" );

    p = MD5(signature);
    if ( p )
        strcpy( signature, ToLower( p ) );
    else
        signature[0] = NUL;

    return ( signature );
}

// flickr.com/services/auth �p signature �������� (write ���w��)
char    *
getSinganureForAuth(
        const char *flickrSecret,
        const char *flickrKey,
        const char *frob
    )
{
    char                *p = NULL;
    Thread static char  signature[BUFSIZ];

    signature[0] = NUL;
    strcpy( signature, flickrSecret );

    sprintf( signature + strlen(signature),
             "api_key%s",
             flickrKey );

    sprintf( signature + strlen(signature),
             "frob%s",
             frob );

    sprintf( signature + strlen(signature),
             "perms%s",
             "write" );

    p = MD5(signature);
    if ( p )
        strcpy( signature, ToLower( p ) );
    else
        signature[0] = NUL;

    return ( signature );
}

// flickr.auth.getToken �p signature ��������
char    *
getSinganureForGetToken(
        const char *flickrSecret,
        const char *flickrKey,
        const char *frob
    )
{
    char                *p = NULL;
    Thread static char  signature[BUFSIZ];

    signature[0] = NUL;
    strcpy( signature, flickrSecret );

    sprintf( signature + strlen(signature),
             "api_key%s",
             flickrKey );

    sprintf( signature + strlen(signature),
             "frob%s",
             frob );

    sprintf( signature + strlen(signature),
             "method%s",
             "flickr.auth.getToken" );

    p = MD5(signature);
    if ( p )
        strcpy( signature, ToLower( p ) );
    else
        signature[0] = NUL;

    return ( signature );
}


// frob �̎擾
char    *
getFlickrFROB(
        const char *flickrKey,
        const char *flickrSecret,
        char       *frob
    )
{
    char    req[BUFSIZ];
    char    url[BUFSIZ + BUFSIZ];
    char    res[BUFSIZ + BUFSIZ];
    size_t  sz = BUFSIZ + BUFSIZ;

    // flickr.auth.getFrob
    sprintf( req,
             "method=flickr.auth.getFrob&"
             "api_key=%s&"
             "api_sig=%s",
             flickrKey,
             getSinganureForGetFrob( flickrSecret, flickrKey ) );
    sprintf( url, "http://flickr.com/services/rest/?%s", req );

    setUpReceiveBuffer( res, sz );
    http_get( url, res );
    if ( *res ) {
        char    *p;

        p = strstr( res, "<frob>" );
        if ( p ) {
            char    *q;

            p += 6;
            q = strstr( p, "</frob>" );
            if ( q ) {
                strncpy( frob, p, q - p );
                frob[q - p] = NUL;
            }
        }
    }

    return ( frob );
}

// �uFlickr �g�[�N���v�̎擾
char    *
getFlickrToken(
        const char *flickrKey,
        const char *flickrSecret,
        const char *frob,
        char       *flickrToken,
        char       *flickrNSID
    )
{
    char    req[BUFSIZ];
    char    url[BUFSIZ + BUFSIZ];
    char    res[BUFSIZ + BUFSIZ];
    size_t  sz = BUFSIZ + BUFSIZ;
    int     retry = 20;
    BOOL    done  = FALSE;

    // flickr.auth.getToken
    sprintf( req,
             "method=flickr.auth.getToken&"
             "api_key=%s&"
             "frob=%s&"
             "api_sig=%s",
             flickrKey,
             frob,
             getSinganureForGetToken( flickrSecret, flickrKey, frob ) );
    sprintf( url, "http://flickr.com/services/rest/?%s", req );

    do {
        setUpReceiveBuffer( res, sz );
        http_get( url, res );
        if ( *res ) {
            char    *p;

            p = strstr( res, "<token>" );
            if ( p ) {
                char    *q;

                p += 7;
                q = strstr( p, "</token>" );
                if ( q ) {
                    strncpy( flickrToken, p, q - p );
                    flickrToken[q - p] = NUL;
                    done = TRUE;
                }
            }

            p = strstr( res, " nsid=\"" );
            if ( p ) {
                char    *q;

                p += 7;
                q = strchr( p, '"' );
                if ( q ) {
                    strncpy( flickrNSID, p, q - p );
                    flickrNSID[q - p] = NUL;
                }
            }

            if ( done )
                break;
        }
        retry--;
        if ( retry > 0 )
            Sleep( 2000 );
    } while ( retry > 0 );

    return ( flickrToken );
}

// �uFlickr ���[�U���v�̎擾
char    *
getFlickrUserName(
        const char *flickrKey,
        const char *flickrNSID,
        char       *flickrUserName
    )
{
    char    req[BUFSIZ];
    char    url[BUFSIZ + BUFSIZ];
    char    res[BUFSIZ + BUFSIZ];
    size_t  sz = BUFSIZ + BUFSIZ;

    // flickr.people.getInfo (�w�� NSID �̃��[�U���̎擾)
    sprintf( req,
             "method=flickr.people.getInfo&"
             "api_key=%s&"
             "user_id=%s",
             flickrKey,
             flickrNSID ); // ����API�� api_sig �s�v
    sprintf( url, "http://flickr.com/services/rest/?%s", req );

    setUpReceiveBuffer( res, sz );
    http_get( url, res );
    if ( *res ) {
        char    *p;

        p = strstr( res, "<photosurl>http://www.flickr.com/photos/" );
        if ( p ) {
            char    *q;

            p += 40;
            q = strstr( p, "/</photosurl>" );
            if ( q ) {
                strncpy( flickrUserName, p, q - p );
                flickrUserName[q - p] = NUL;
            }
        }
    }

    return ( flickrUserName );
}


// �摜�t�@�C���� Flickr �ɓ��e����
BOOL
postPhotoOnFlickr(
    const char *filename,       // (I)   Flickr �ɓ��e����摜�̃t�@�C����
    size_t     filesize,        // (I)   Flickr �ɓ��e����摜�̃t�@�C���T�C�Y
    const char *title,          // (I)   Flickr �ɓ��e����摜�́u�薼�v
    const char *caption,        // (I)   Flickr �ɓ��e����摜�́u�����v
    const char *flickrKey,      // (I)   Flickr API�L�[
    const char *flickrSecret,   // (I)   signature�������ɕt�����镶����
    char       *flickrToken,    // (I/O) Flickr �g�[�N��
    char       *flickrUserName, // (I/O) Flickr ���[�U��
    char       *url )           // (O)   �A�b�v���[�h��URL
{
    BOOL    ret = FALSE;
    char    *request;
    char    *response;
    char    *imageData;
    char    *signature;
    char    *targetTitle;
    char    *targetCaption;
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
    BOOL    r;

    char    flickrNSID[256];

    if ( !flickrToken || !flickrUserName )
        return ( ret );

    // Flickr �F��
    flickrNSID[0] = NUL;
    r = GetAccessTokenOnFlickr( flickrKey,   flickrSecret,
                                flickrToken, flickrUserName, flickrNSID );
    if ( !r )
        return ( ret );

    // signature ����
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

    if ( !caption || !(*caption) )
        caption = " ";
    targetCaption = (char *)malloc( strlen(caption) * 6 + 1 );
    if ( !targetCaption ) {
        free( targetTitle );
        return ( ret );
    }

    p = any2utf( title );
    strcpy( targetTitle, p ? p : title );

    p = any2utf( caption );
    strcpy( targetCaption, p ? p : caption );

    signature = getSinganureForFlickr( flickrSecret,
                                       flickrKey, flickrToken,
                                       targetTitle, targetCaption );

    // �A�b�v���[�h
    imageData = (char *)malloc( filesize + 1 );
    if ( !imageData ) {
        free( targetCaption );
        free( targetTitle );
        return ( ret );
    }

    fp = fopen( filename, "rb" );
    if ( !fp ) {
        free( imageData );
        free( targetCaption );
        free( targetTitle );
        return ( ret );
    }
    fread( imageData, filesize, 1, fp );
    fclose( fp );

    request  = (char *)malloc( sz1 );
    if ( !request ) {
        free( imageData );
        free( targetCaption );
        free( targetTitle );
        return ( ret );
    }
    response = (char *)malloc( sz2 );
    if ( !response ) {
        free( request );
        free( imageData );
        free( targetCaption );
        free( targetTitle );
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
        free( targetCaption );
        free( targetTitle );
        return ( ret );
    }
    fInfo.bits = (unsigned char *)p;

    // multipart/form-data �̑g�ݗ���
    getSendBufferPointer( request, base );
    tail = base;

    sprintf( contentType, "multipart/form-data; boundary=%s", separator );
    strcpy( tail, 
            makeMultiPartItem( separator, MULITIPART_ITEM_TYPE_STRING,
                               "api_key", 0, flickrKey, NULL ) );
    strcat( tail, 
            makeMultiPartItem( separator, MULITIPART_ITEM_TYPE_STRING,
                               "auth_token", 0, flickrToken, NULL ) );
    strcat( tail, 
            makeMultiPartItem( separator, MULITIPART_ITEM_TYPE_STRING,
                               "api_sig", 0, signature, NULL ) );

    szz  =  strlen( tail );
    tail += szz;
    szz  =  0;
    p    =  makeMultiPartItem( separator, MULITIPART_ITEM_TYPE_FILE,
                               "photo", 0, (char *)&fInfo, &szz );
    memcpy( tail, p, szz );
    tail += szz;

    if ( title ) {
        if ( *title )
            strcpy( tail, 
                    makeMultiPartItem(
                                separator, MULITIPART_ITEM_TYPE_STRING,
                                "title", 0, targetTitle, NULL ) );
        else
            strcpy( tail, 
                    makeMultiPartItem(
                                separator, MULITIPART_ITEM_TYPE_STRING,
                                "title", 0, "", NULL ) );
        szz  =  strlen( tail );
        tail += szz;
    }

    if ( caption ) {
        if ( *caption )
            strcpy( tail, 
                    makeMultiPartItem(
                                separator, MULITIPART_ITEM_TYPE_STRING,
                                "description", 0, targetCaption, NULL ) );
        else
            strcpy( tail, 
                    makeMultiPartItem(
                                separator, MULITIPART_ITEM_TYPE_STRING,
                                "description", 0, "", NULL ) );
        szz  =  strlen( tail );
        tail += szz;
    }

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
    http_post( "http://api.flickr.com/services/upload/",
               contentType,
               request, response );

    if ( *response ) {
        p = strstr( response, "<photoid>" );
        if ( p ) {
            ret = TRUE;

            if ( url ) {
                char    *q;
                char    photoID[BUFSIZ];

                p += 9;
                q = strstr( p, "</photoid>" );
                if ( q ) {
                    strncpy( photoID, p, q - p );
                    photoID[q - p] = NUL;
                    sprintf( url, "http://www.flickr.com/photos/%s/%s/",
                             flickrUserName[0] ? flickrUserName : flickrNSID,
                             photoID );
                }
            }
        }
    }

    base64( NULL, 0 );
    free( response );
    free( request  );
    free( imageData );
    free( targetCaption );
    free( targetTitle );

    return ( ret );
}


// �A�N�Z�X�g�[�N���̎擾
BOOL
GetAccessTokenOnFlickr(
    const char *flickrKey,      // (I)   Flickr API�L�[
    const char *flickrSecret,   // (I)   signature�������ɕt�����镶����
    char       *flickrToken,    // (I/O) Flickr �g�[�N��
    char       *flickrUserName, // (I/O) Flickr ���[�U��
    char       *flickrNSID )    // (I/O) Flickr NSID
{
    BOOL    ret = FALSE;
    int     r;
    char    frob[2048];

    flickrNSID[0] = NUL;
    frob[0]       = NUL;

    if ( !flickrToken || !flickrUserName )
        return ( ret );

    // Flickr �F��
    if ( !(*flickrToken) || !(*flickrUserName) ) {
        char    authURL[BUFSIZ + BUFSIZ];

        // frob �̎擾
        getFlickrFROB( flickrKey, flickrSecret, frob );
        if ( !(frob[0]) )
            return ( ret );

        // �u���E�U�N�� -- ���[�U�ɃA�N�Z�X�������߂�
        sprintf( authURL,
                 "http://flickr.com/services/auth/?"
                 "api_key=%s&"
                 "perms=write&"
                 "frob=%s&"
                 "api_sig=%s",
                 flickrKey,
                 frob,
                 getSinganureForAuth( flickrSecret, flickrKey, frob ) );

        ShellExecute( NULL, "open", authURL, NULL, NULL, SW_SHOWNORMAL );

        // ���[�U�̋��҂�
        r = MessageBox( NULL,
            "Chirrup �� Flickr �ɃA�N�Z�X���鋖��^���Ă��������B\r\n"
            "����^���I�������AOK �{�^���������Ă��������B\r\n"
            "����^�������Ȃ��ꍇ�� �L�����Z�� �{�^���������Ă��������B  ",
            "Flickr �ւ̃A�N�Z�X����", MB_OKCANCEL|MB_ICONINFORMATION );
        if ( r != IDOK ) {
            MessageBox( NULL,
                        "Flickr �F�ؗp�A�N�Z�X�g�[�N���̎擾�𒆎~���܂��B  ",
                        "Flickr �F��", MB_OK|MB_ICONWARNING );
            return ( ret );
        }

        // token �擾
        getFlickrToken( flickrKey, flickrSecret, frob,
                        flickrToken, flickrNSID );
        if ( !(*flickrToken) )
            return ( ret );
    }

    // Flickr ���[�U���̎擾 (�A�b�v���[�h�� URL ���m�肷�邽�߂ɕK�v)
    if ( !(*flickrUserName) ) {
        if ( flickrNSID && *flickrNSID )
            getFlickrUserName( flickrKey, flickrNSID, flickrUserName );
        else
            strcpy( flickrUserName, flickrNSID );
    }

    if ( *flickrToken && *flickrUserName )
        ret = TRUE;

    return ( ret );
}
