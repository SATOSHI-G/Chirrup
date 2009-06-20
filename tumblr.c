/*
 * tumblr.c : Twitter �N���C�A���g chirrup
 *      tumblr �֘A�e�폈���Q
 *          written by H.Tsujimura  5 Nov 2007
 *
 *      Copyright (c) 2007, 2008, 2009 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/tumblr.c $
 * 
 * 3     09/05/31 20:42 tsupo
 * 1.142��
 * 
 * 16    09/05/29 19:22 Tsujimura543
 * ����A�J�E���g�ŕ��� tumbleblog ���J�݂��Ă���ꍇ�̓��e��
 * tumbleblog ���w�肵�Ă̓��e���\�ɂ���
 * 
 * 2     09/05/27 1:29 tsupo
 * xmlRPC 1.266�őΉ�
 * 
 * 15    09/05/26 18:08 Tsujimura543
 * URL �n�[�h�R�[�f�B���O�ӏ������炵��
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 14    08/02/14 22:48 Tsujimura543
 * �u�� �� &Lt; �ɉ�������A�� �� &Gt; �ɉ������肷�錏�̑΍�v�����{
 * 
 * 13    08/02/13 0:10 Tsujimura543
 * tumblr �ւ� Quote ���e���ɃR�����g����������ɓ��e�ł���悤�ɂ���
 * 
 * 12    07/12/19 18:47 Tsujimura543
 * loginTumblr() �� __http_postBASIC() ���g���łɈڍs
 * 
 * 11    07/12/14 14:49 Tsujimura543
 * checkResultOnTumblr() ���C���Aphoto �̃A�b�v���[�h��������B���̌x��
 * �ɂ��Ή�����
 * 
 * 10    07/12/13 19:08 Tsujimura543
 * Gyazo�֘A�̊֐��Q�� gyazo.c �Ƃ��ĕ����Ɨ�������
 * 
 * 9     07/12/10 23:04 Tsujimura543
 * postPhotoWithUrlOnTumblr() �� caption �ȗ����̓����ύX
 * 
 * 8     07/12/10 21:21 Tsujimura543
 * postPhotoWithUrlOnTumblr() ��ǉ�
 * 
 * 7     07/12/10 18:10 Tsujimura543
 * tumblr �ւ̓��e�֘A������ fix
 * 
 * 6     07/12/10 16:39 Tsujimura543
 * Gyazo �ւ̓��e�����֘A�� fix
 * 
 * 5     07/12/06 19:50 Tsujimura543
 * Gyazo �ɉ摜���A�b�v���[�h����@�\������
 * (������͕ʃt�@�C���Ƃ��ĕ�������)
 * 
 * 4     07/12/06 1:29 Tsujimura543
 * postPhotoOnTumblr() ��ǉ�
 * 
 * 3     07/11/12 19:04 Tsujimura543
 * ���e���s���ɃG���[���b�Z�[�W��\���\�ȏꍇ�́A�\������悤�ɂ���
 * 
 * 2     07/11/07 3:39 Tsujimura543
 * ���Ă��锭���� ���p���� Tumblr �֓��e����@�\���쐬
 * 
 * 1     07/11/05 23:56 Tsujimura543
 * �ŏ��̔�
 */


#include <time.h>
#include "xmlRpc.h"
#include "multipart.h"
#include "utility.h"
#include "tumblr.h"
#include "http.h"

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/chirrup/tumblr.c 3     09/05/31 20:42 tsupo $";
#endif


BOOL
checkResultOnTumblr( const char *response )
{
    int ret = FALSE;

    long    postID = atol( response );
    if ( postID > 0 )
        ret = TRUE; // ���e����
    else {
        char    errorString[BUFSIZ];
        char    *p;

        errorString[0] = NUL;
        p = strstr( response, "Tumblr is undergoing maintenance" );
        if ( p )
            strcpy( errorString, "���݁ATumblr �̓����e�i���X���ł�" );
        else {
            p = strstr( response,
                        "You've exceeded your daily post limit." );
            if ( !p )
                p = strstr( response,
                            "You've exceeded your daily photo upload limit.");
            if ( p )
                strcpy( errorString,
                        "���ł�1�����̓��e�񐔏���܂œ��e���Ă��܂�" );
        }

        if ( errorString[0] ) {
            strcat( errorString, "      " );
            MessageBox( NULL, errorString, "tumblr ���e���s",
                        MB_OK|MB_ICONERROR );
        }
    }

    return ( ret );
}

BOOL
postTumblr(
    const char *targetURL,  // (I) tumblr �ɓ��e����L���� URL
    const char *quote,      // (I) tumblr �ɓ��e����L���́u���e�v
    const char *title,      // (I) tumblr �ɓ��e����L���́u�薼�v
    const char *comment,    // (I) tumblr �ɓ��e����L���́u�R�����g�v
    const char *username,   // (I) tumblr �� login ����Ƃ��̃��[���A�h���X
    const char *password,   // (I) �p�X���[�h
    const char *group )     // (I) ���e�� tumbleblog ID �܂��̓O���[�v��
{
    BOOL    ret = FALSE;
    char    *request;
    char    *response;
    char    *source;
    char    *p;
    size_t  sz = MAX_CONTENT_SIZE;
    char    *targetTitle;
    char    *targetQuote;
    char    *targetComment = NULL;

    targetTitle = (char *)malloc( strlen(title) * 6 + 1 );
    if ( !targetTitle )
        return ( ret );
    targetQuote = (char *)malloc( strlen(quote) * 6 + 1 );
    if ( !targetQuote ) {
        free( targetTitle );
        return ( ret );
    }

    if ( comment && *comment ) {
        targetComment = (char *)malloc( strlen(comment) * 6 + 1 );
        if ( !targetComment ) {
            free( targetQuote );
            free( targetTitle );
            return ( ret );
        }
    }

    source  = (char *)malloc( sz );
    if ( !source ) {
        if ( targetComment )
            free( targetComment );
        free( targetQuote );
        free( targetTitle );
        return ( ret );
    }
    request  = (char *)malloc( sz );
    if ( !request ) {
        free( source );
        if ( targetComment )
            free( targetComment );
        free( targetQuote );
        free( targetTitle );
        return ( ret );
    }
    response = (char *)malloc( sz );
    if ( !response ) {
        free( request );
        free( source );
        if ( targetComment )
            free( targetComment );
        free( targetQuote );
        free( targetTitle );
        return ( ret );
    }
    memset( request, 0x00, MAX_CONTENT_SIZE );

    p = any2utf( title );
    strcpy( targetTitle, p ? p : title );
    /* �� �� &Lt; �ɉ�������A�� �� &Gt; �ɉ������肷�錏�̑΍� */
    if ( strstr( targetTitle, "\342\211\253" ) )    // &raquo;
        replaceString( targetTitle, "\342\211\253", "\302\273" );
    if ( strstr( targetTitle, "\342\211\252" ) )    // &laquo;
        replaceString( targetTitle, "\342\211\252", "\302\253" );
    if ( strchr( targetTitle, '<' ) )
        replaceStringEx( targetTitle );

    p = any2utf( quote );
    strcpy( targetQuote, p ? p : quote );
    /* �� �� &Lt; �ɉ�������A�� �� &Gt; �ɉ������肷�錏�̑΍� */
    if ( strstr( targetQuote, "\342\211\253" ) )    // &raquo;
        replaceString( targetQuote, "\342\211\253", "\302\273" );
    if ( strstr( targetQuote, "\342\211\252" ) )    // &laquo;
        replaceString( targetQuote, "\342\211\252", "\302\253" );
    if ( strchr( targetQuote, '<' ) )
        replaceStringEx( targetQuote );

    if ( targetComment ) {
        p = any2utf( comment );
        strcpy( targetComment, p ? p : comment );
        /* �� �� &Lt; �ɉ�������A�� �� &Gt; �ɉ������肷�錏�̑΍� */
        if ( strstr( targetComment, "\342\211\253" ) )    // &raquo;
            replaceString( targetComment, "\342\211\253", "\302\273" );
        if ( strstr( targetComment, "\342\211\252" ) )    // &laquo;
            replaceString( targetComment, "\342\211\252", "\302\253" );
        if ( strchr( targetComment, '<' ) )
            replaceStringEx( targetComment );
    }

    sprintf( source,
             "<a href=\"%s\">%s</a>",
             targetURL,
             targetTitle );
    if ( targetComment )
        sprintf( source + strlen(source),
                 "\r\n%s",
                 targetComment );

    sprintf( request,
             "email=%s&"
             "password=%s&"
             "type=quote&"
             "quote=%s&",
             username,
             password,
             encodeURL( targetQuote ) );
    sprintf( request + strlen(request),
             "source=%s&",
             encodeURL( source ) );
    if ( group && *group )
        sprintf( request + strlen(request),
                 "group=%s&",
                 group );
    sprintf( request + strlen(request),
             "generator=%s",
             "Chirrup" );

    setUpReceiveBuffer( response, sz );
    http_post( APIURL_TUMBLR_WRITE,
               "application/x-www-form-urlencoded",
               request, response );

    if ( *response )
        ret = checkResultOnTumblr( response );

    free( response );
    free( request  );
    free( source );
    if ( targetComment )
        free( targetComment );
    free( targetQuote );
    free( targetTitle );

    return ( ret );
}


BOOL
postPhotoOnTumblr(
    const char *filename,   // (I) tumblr �ɓ��e����摜�̃t�@�C����
    size_t     filesize,    // (I) tumblr �ɓ��e����摜�̃t�@�C���T�C�Y
    const char *caption,    // (I) tumblr �ɓ��e����摜�́u�����v
    const char *username,   // (I) tumblr �� login ����Ƃ��̃��[���A�h���X
    const char *password,   // (I) �p�X���[�h
    const char *group,      // (I)   ���e�� tumbleblog ID �܂��̓O���[�v��
    char       *url )       // (O) �A�b�v���[�h��URL
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
    char    *targetCaption;
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

    if ( !caption || !(*caption) )
        caption = " ";
    targetCaption = (char *)malloc( strlen(caption) * 6 + 1 );
    if ( !targetCaption ) {
        free( imageData );
        return ( ret );
    }

    request  = (char *)malloc( sz1 );
    if ( !request ) {
        free( targetCaption );
        free( imageData );
        return ( ret );
    }
    response = (char *)malloc( sz2 );
    if ( !response ) {
        free( request );
        free( targetCaption );
        free( imageData );
        return ( ret );
    }
    memset( request, 0x00, sz1 );

    p = any2utf( caption );
    strcpy( targetCaption, p ? p : caption );
    /* �� �� &Lt; �ɉ�������A�� �� &Gt; �ɉ������肷�錏�̑΍� */
    if ( strstr( targetCaption, "\342\211\253" ) )    // &raquo;
        replaceString( targetCaption, "\342\211\253", "\302\273" );
    if ( strstr( targetCaption, "\342\211\252" ) )    // &laquo;
        replaceString( targetCaption, "\342\211\252", "\302\253" );
    if ( strchr( targetCaption, '<' ) )
        replaceStringEx( targetCaption );

    // �A�b�v���[�h����t�@�C���̏����Z�b�g
    strcpy( fInfo.type, "application/unknown" );    /* �b�� */
    strcpy( fInfo.name, filename );

    p = base64( (unsigned char*)imageData, filesize );
    if ( !p ) {
        base64( NULL, 0 );
        free( response );
        free( request );
        free( targetCaption );
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
                               "email", 0, username, NULL ) );
    strcat( tail, 
            makeMultiPartItem( separator, MULITIPART_ITEM_TYPE_STRING,
                               "password", 0, password, NULL ) );
    strcat( tail, 
            makeMultiPartItem( separator, MULITIPART_ITEM_TYPE_STRING,
                               "type", 0, "photo", NULL ) );

    szz  =  strlen( tail );
    tail += szz;
    szz  =  0;
    p    =  makeMultiPartItem( separator, MULITIPART_ITEM_TYPE_FILE,
                               "data", 0, (char *)&fInfo, &szz );
    memcpy( tail, p, szz );
    tail += szz;

    strcat( tail,
            makeMultiPartItem( separator, MULITIPART_ITEM_TYPE_STRING,
                               "caption", 0, targetCaption, NULL ) );
    if ( group && *group )
        strcat( tail,
                makeMultiPartItem( separator, MULITIPART_ITEM_TYPE_STRING,
                                   "group", 0, group, NULL ) );
    strcat( tail, 
            makeMultiPartItem( separator, MULITIPART_ITEM_TYPE_STRING,
                               "generator", 0, "Chirrup", NULL ) );
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
    http_post( APIURL_TUMBLR_WRITE,
               contentType,
               request, response );

    if ( *response ) {
        ret = checkResultOnTumblr( response );
        if ( ret && url && group && *group ) {
            if ( strchr( group, '.' ) )
                    sprintf( url, "http://%s/post/%s",
                             group, response );
        }
    }

    base64( NULL, 0 );
    free( response );
    free( request  );
    free( targetCaption );
    free( imageData );

    return ( ret );
}

BOOL
postPhotoWithUrlOnTumblr(
    const char *photoURL,   // (I) tumblr �ɓ��e����摜��URL
    const char *caption,    // (I) tumblr �ɓ��e����摜�́u�����v
    const char *username,   // (I) tumblr �� login ����Ƃ��̃��[���A�h���X
    const char *password,   // (I) �p�X���[�h
    const char *group,      // (I)   ���e�� tumbleblog ID �܂��̓O���[�v��
    char       *url )       // (O) �A�b�v���[�h��URL
{
    BOOL    ret = FALSE;
    char    *p;
    char    *targetCaption;
    char    *request;
    char    *response;
    size_t  sz = MAX_CONTENT_SIZE;
    char    tempCaption[MAX_DESCRIPTION_LEN];

    tempCaption[0] = NUL;
    if ( !caption || !(*caption) ) {
        sprintf( tempCaption, "via <a href=\"%s\">%s</a>", photoURL, photoURL );
        caption = tempCaption;
    }
    targetCaption = (char *)malloc( strlen(caption) * 6 + 1 );
    if ( !targetCaption )
        return ( ret );

    request  = (char *)malloc( sz );
    if ( !request ) {
        free( targetCaption );
        return ( ret );
    }
    response = (char *)malloc( sz );
    if ( !response ) {
        free( request );
        free( targetCaption );
        return ( ret );
    }
    memset( request, 0x00, sz );

    p = any2utf( caption );
    strcpy( targetCaption, p ? p : caption );

    /* �� �� &Lt; �ɉ�������A�� �� &Gt; �ɉ������肷�錏�̑΍� */
    if ( strstr( targetCaption, "\342\211\253" ) )    // &raquo;
        replaceString( targetCaption, "\342\211\253", "\302\273" );
    if ( strstr( targetCaption, "\342\211\252" ) )    // &laquo;
        replaceString( targetCaption, "\342\211\252", "\302\253" );
    if ( strchr( targetCaption, '<' ) )
        replaceStringEx( targetCaption );

    if ( strstr( targetCaption, "<a " )  )
        strcpy( targetCaption, encodeURL( targetCaption ) );

    sprintf( request,
             "email=%s&"
             "password=%s&"
             "type=photo&"
             "source=%s&",
             username,
             password,
             encodeURL(photoURL) );
    sprintf( request + strlen(request),
             "caption=%s&",
             targetCaption );
    if ( group && *group )
        sprintf( request + strlen(request),
                 "group=%s&",
                 group );
    sprintf( request + strlen(request),
             "generator=%s",
             "Chirrup" );

    setUpReceiveBuffer( response, sz );
    http_post( APIURL_TUMBLR_WRITE,
               "application/x-www-form-urlencoded",
               request, response );

    if ( *response ) {
        ret = checkResultOnTumblr( response );
        if ( ret && url && group && *group ) {
            if ( strchr( group, '.' ) )
                    sprintf( url, "http://%s/post/%s",
                             group, response );
        }
    }

    free( response );
    free( request  );
    free( targetCaption );

    return ( ret );
}


int
getBlogIDsTumblr(
    const char *userName,       // (I) ���[�U�� (���[���A�h���X)
    const char *password,       // (I) �p�X���[�h
    int        *numberOfBlogs,  // (I) �擾����/�擾���� blog ���̐�
    BLOGINF    *blogInfo )      // (O) �擾���� blog ���
{
    char    cookie[MAX_COOKIE_LEN];
    char    url[MAX_URLLENGTH];
    char    name[MAX_BLOGNAMELENGTH];
    char    id[MAX_BLOGIDLENGTH];
    int     numOfBlogs = 0;
    size_t  sz  = MAX_CONTENT_SIZE;
    BOOL    ret = FALSE;
    char    request[BUFSIZ];
    char    *response = (char *)malloc( sz );

    if ( !response )
        return ( ret );

    cookie[0] = NUL;
    sprintf( request,
             "email=%s&"
             "password=%s",
             userName, password );

    setUpReceiveBuffer( response, sz );
    http_postEx( APIURL_TUMBLR_ACOUNT,
                 "application/x-www-form-urlencoded",
                 request, response, cookie );

    if ( *response ) {
        char    *p = strstr( response, "<tumblelog title=\"" );
        char    *q;
        char    *r;
        char    *s;

        while ( p ) {
            url[0]  = NUL;
            name[0] = NUL;
            id[0]   = NUL;
            blogInfo[numOfBlogs].blogName[0] = NUL;
            blogInfo[numOfBlogs].url[0]      = NUL;
            blogInfo[numOfBlogs].blogID[0]   = NUL;

            p += 18;
            q = strchr( p, '"' );
            r = strstr( p, "/>" );
            if ( !q || !r )
                break;

            if ( q < r ) {
                strncpy( name, p, q - p );
                name[q - p] = NUL;
                s = utf2sjis( name );
                strcpy( blogInfo[numOfBlogs].blogName, s ? s : name );

                p = q + 1;
            }

            q = strstr( p, "url=\"" );
            if ( q && (q < r) ) {
                p = q + 5;
                q = strchr( p, '"' );
                if ( q && (q < r) ) {
                    strncpy( url, p, q - p );
                    url[q - p] = NUL;
                    strcpy( blogInfo[numOfBlogs].url, url );

                    s = strstr( url, "http://" );
                    if ( s ) {
                        strcpy( blogInfo[numOfBlogs].blogID, s + 7 );
                        s = blogInfo[numOfBlogs].blogID;
                        if ( s[strlen(s) - 1] == '/' )
                            s[strlen(s) - 1] = NUL;
                    }

                    p = q + 1;
                }
            }
            else
                strcpy( blogInfo[numOfBlogs].url, "(private)" );

            q = strstr( p, "id=\"" );
            if ( q && (q < r) ) {
                p = q + 4;
                q = strchr( p, '"' );
                if ( q && (q < r) ) {
                    strncpy( id, p, q - p );
                    id[q - p] = NUL;
                    strcpy( blogInfo[numOfBlogs].blogID, id );

                    p = q + 1;
                }
            }

            q = p;
            p = strstr( q, "<tumblelog title=\"" );
            numOfBlogs++;

            if ( numOfBlogs >= *numberOfBlogs )
                break;
        }

        ret = TRUE;
        *numberOfBlogs = numOfBlogs;
    }

    free( response );

    return ( numOfBlogs );
}
