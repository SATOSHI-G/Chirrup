/*
 * wassr.cpp : Wassr �N���C�A���g chirrup
 *      Wassr API �𗘗p���邽�߂̊e�폈���Q
 *          written by H.Tsujimura  14 Jun 2007
 *
 *      Copyright (c) 2007, 2008 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/wassr.cpp $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 45    09/04/28 20:52 Tsujimura543
 * �^�C���A�E�g�擾�������K�莞�ԓ��ɏI���Ȃ��ꍇ�̏�����ύX
 * (�X���b�h�����I�������ł͂Ȃ��A�C�x���g�ʒm�������̗p)
 * 
 * 44    09/03/10 22:14 Tsujimura543
 * GetStringFromJSON() �Ƀo�b�t�@�I�[�o�[�����΍�����{
 * 
 * 43    08/12/04 18:19 Tsujimura543
 * �R�[�h�����A���艻��Ƃ����{
 * 
 * 42    08/11/21 15:57 Tsujimura543
 * (API ���g��Ȃ����@�ł�)�摜���e���Ăтł���悤�ɂȂ������Ƃ��m�F
 * 
 * 41    08/11/21 15:52 Tsujimura543
 * (1) �摜�̓��e���ł��Ȃ��Ȃ��Ă��܂��Ă���(login�Ɏ��s����悤�ɂȂ��Ă�
 *     �܂��Ă���)���̌��������A�΍�����{����
 * (2) API �o�R�ł̉摜���e������ (�������A���̂Ƃ���AAPI�o�R�ł̉摜���e
 *     �͐������Ă��Ȃ�)
 * 
 * 40    08/11/17 16:31 Tsujimura543
 *  Visual Studio 2008 �ł̃r���h���ʂ𔽉f
 * 
 * 39    08/10/21 23:58 Tsujimura543
 * �u�C�C�l!�v API �̃��X�|���X�����񂪕ύX���ꂽ�̂ɔ����C�������{
 * 
 * 38    08/08/02 2:23 Tsujimura543
 * GetChannelList() ��ǉ�
 * 
 * 37    08/08/01 4:35 Tsujimura543
 * �摜�̓��e���u�`�����l���v�Ή�����
 * 
 * 36    08/08/01 3:33 Tsujimura543
 * �`�����l���ւ̓��e�ɑΉ� (�����̓��� #�`�����l���� ������ƁA
 * ���̃`�����l���ɓ��e����)
 * 
 * 35    08/08/01 2:39 Tsujimura543
 * Wassr �ւ̉摜�̓��e�ɑΉ�
 * 
 * 34    08/07/08 17:50 Tsujimura543
 * AddFriend(), RemoveFriend(), SetFavorite() �� request �̃T�C�Y�𓝈�
 * 
 * 33    08/07/08 17:45 Tsujimura543
 * AddFriend() �� RemoveFriend() ������
 * 
 * 32    08/07/08 14:51 Tsujimura543
 * Wassr �́u�C�C�l!�v�ɑΉ�
 * 
 * 31    08/04/22 22:13 Tsujimura543
 * ���O�ɋL�^���鎞���� GMT �̂܂܂Ȃ̂� JST �ɕύX (�C��)
 * 
 * 30    08/02/08 23:12 Tsujimura543
 * MakeMessageForScreen() ��ύX�A�X�N���[�����ł͂Ȃ����[�U����
 * �\������悤�ɂ���
 * 
 * 29    08/02/07 22:36 Tsujimura543
 * copyright �\�����C�� (2008 ��ǉ�)
 * 
 * 28    08/02/06 20:51 Tsujimura543
 * CWassr::GetUserFromJSON() ���C���A�X�N���[�������G�����݂̂ō\����
 * ���l�́A�X�N���[���������[�U���ő�p����悤�ɂ��Ă݂�
 * 
 * 27    07/12/19 18:44 Tsujimura543
 * http �֘A�֐��Ăяo���܂��𐮗�
 * 
 * 26    07/12/19 17:17 Tsujimura543
 * _http_postBASIC() �̈�����ǉ�
 * 
 * 25    07/12/19 16:56 Tsujimura543
 * _http_getBASIC() �̈�����ǉ�
 * 
 * 24    07/12/14 16:03 Tsujimura543
 * http_getBASIC() �� _http_getBASIC() �ɒu��
 * 
 * 23    07/07/19 21:35 Tsujimura543
 * �^�C���X�^���v�֘A�̏����� VC++ 6 / VC++ 2005 ���ʃR�[�h�ɕύX
 * 
 * 22    07/07/05 0:50 Tsujimura543
 * (1) GetStatFromJSON(), GetUserTimeline() �̈�����ύX
 * (2) TWITTER_USER �\���̂̕ύX(orig_userName��ǉ�)�ɔ����C��
 * (3) MakeMessageForScreen() �� MakeMessageForLogging() ��p��
 * 
 * 21    07/07/03 13:24 Tsujimura543
 * Visual Studio 2005 �ł̃r���h���ʂ𔽉f
 * 
 * 20    07/06/26 16:01 Tsujimura543
 * PostUpdate() ���Ŋm�ۂ��� request �̃T�C�Y���C��
 * 
 * 19    07/06/25 21:10 Tsujimura543
 * memcpy() ���g���Ă����Ƃ�����R�s�[�R���X�g���N�^���g���悤�ɏC��
 * 
 * 18    07/06/25 18:03 Tsujimura543
 * DeleteReserved(), DeleteReserved2() �֘A�A�R�[�h�𐮗�
 * 
 * 17    07/06/22 18:06 Tsujimura543
 * SetStatFromJSON() �� fix
 * 
 * 16    07/06/21 19:15 Tsujimura543
 * SetUserAgent() �� CService ���̃��\�b�h�Ɉ�{������
 * 
 * 15    07/06/21 13:36 Tsujimura543
 * PostUpdate() ���Ŋm�ۂ��Ă��� request �̃T�C�Y������������ꍇ��
 * ���邱�Ƃ������B�T�C�Y�̌v�Z���C������
 * 
 * 14    07/06/20 20:55 Tsujimura543
 * [RID: .xxx] �� [ID: xxx] �ɕύX
 * 
 * 13    07/06/20 19:28 Tsujimura543
 * GetStatusID() �𓱓�
 * 
 * 12    07/06/19 23:01 Tsujimura543
 * CService �𓱓����A�\�[�X�R�[�h�𐮗�����
 * 
 * 11    07/06/19 0:42 Tsujimura543
 * ���O�t�@�C���ɂ�������ID���L�^����悤�ɂ���
 * 
 * 10    07/06/18 22:13 Tsujimura543
 * Regulize() ���C���B�G����������ƕ����������錏�͉����B
 * ����ȊO�ŁAShift_JIS �͈̔͊O�̕���������Ɖ����錏�͖������B
 * 
 * 9     07/06/16 0:54 Tsujimura543
 * friends_timeline �̉{������ RID ���\������Ȃ��s����C��
 * (JoinTimeline() �� RID ��t�����Y��Ă���[�C�����Y��])
 * 
 * 8     07/06/15 22:20 Tsujimura543
 * �u���X�v�̓��e�ɑΉ�
 * 
 * 7     07/06/15 19:59 Tsujimura543
 * �R�����g��ǉ�
 * 
 * 6     07/06/15 17:37 Tsujimura543
 * Wassr ���L�̕�������(�G�������������Ǝv����)�΍��ǉ�
 * 
 * 5     07/06/14 23:03 Tsujimura543
 * �R�����g��ǉ�
 * 
 * 4     07/06/14 21:11 Tsujimura543
 * ���O�o�͎��́u�X�N���[�����v�� UTF-8 �ɂȂ��Ă��Ȃ������s����C��
 * 
 * 3     07/06/14 19:17 Tsujimura543
 * �\�[�X�𐮗�
 * 
 * 2     07/06/14 19:06 Tsujimura543
 * friends_timeline �� user_timeline ���������āATwitter �݊���
 * friends_timeline �𐶐����鏈����ǉ�
 * 
 * 1     07/06/14 17:55 Tsujimura543
 * �V�K�쐬 (�b���)
 */

#include "chirrup.h"
#include "twitter.h"
#include "twitterTimeline.h"
#include "wassr.h"
#include "http.h"
extern "C" {
#include "utility.h"
#include "multipart.h"
}

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/chirrup/wassr.cpp 1     09/05/14 3:50 tsupo $";
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#ifdef  _MSC_VER
#define Thread  __declspec( thread )
#else
#define Thread
#endif

CWassr::CWassr() : CService()
{
#ifdef  _DEBUG
    m_serviceName   = _T("wassr");
#endif
    m_serviceSymbol = _T("Wassr");
}

CWassr::~CWassr()
{
}

void CWassr::DeleteReserved( TWITTER_STATUS *sp )
{
    if ( sp && sp->reserved ) {
    }
}

void CWassr::DeleteReserved2( TWITTER_STATUS *sp )
{
    if ( sp && sp->reserved2 ) {
    }
}

/*
 *  Wassr API
 */

// �����𓊍e
bool
CWassr::PostUpdate( CString monologue, ProceedingDialog *pdlg )
{
    bool        ret = false;
    size_t      sz  = MAX_CONTENT_SIZE;
    size_t      len = monologue.GetLength() * 18;
    char        *request  = new char[39 + MAX_KEYLENGTH + len + 1];
    char        *response = new char[sz];
    const char  *url = "http://api.wassr.jp/update.json";
    char        rid[MAX_KEYLENGTH];
#define MAX_CHANNEL_LEN 128
    char        channel[MAX_CHANNEL_LEN];

    rid[0]     = NUL;
    channel[0] = NUL;
    if ( !strncmp( monologue, ">>", 2 ) ) {
        strncpy( rid, ((const char *)monologue) + 2, MAX_KEYLENGTH - 2 );
        rid[MAX_KEYLENGTH - 2] = NUL;

        char    *p = strchr( rid, ' ' );
        if ( p ) {
            *p = NUL;
            monologue = strchr( monologue, ' ' ) + 1;
        }
    }
    if ( monologue[0] == '#' ) {
        const char	*p = strchr( monologue, ' ' );
        if ( p ) {
            url = "http://api.wassr.jp/channel_message/update.json";
            strncpy( channel, ((const char *)monologue) + 1, MAX_CHANNEL_LEN - 2 );

            char    *q = strchr( channel, ' ' );
            if ( q ) {
                *q = NUL;
                monologue = p + 1;
            }
        }
    }

    char    *p = sjis2utf( monologue );
    if ( request && response ) {
        sprintf( request,
                 "%s=%s&"
                 "source=%s",
                 channel[0] ? "body" : "status",
                 encodeURL( p ? p : monologue ),
                 "Chirrup" );
        if ( rid[0] )
            sprintf( request + strlen(request),
                     "&reply_status_rid=%s",
                     rid );
        if ( channel[0] )
            sprintf( request + strlen(request),
                     "&name_en=%s",
                     channel );
        SetUserAgent();
        setUpReceiveBuffer( response, sz );
        _http_postBASIC( url, m_username, m_password,
                         request, response, NULL, pdlg );
        if ( *response ) {
            if ( strstr( response, "\"text\"" )         ||
                 strstr( response, "{\"error\":null}" )    )
                ret = true;
        }
    }

    if ( response )
        delete [] response;
    if ( request )
        delete [] request;

    return ( ret );
}

// friends_timeline ���擾
CString
CWassr::GetFriendsTimeline(
                CTwitterTimeline *timeline,
                ProceedingDialog *pdlg
            )
{
    return ( CService::GetFriendsTimeline(
                            "http://api.wassr.jp/friends_timeline.json",
                            timeline,
                            pdlg ) );
}

// public_timeline ���擾
CString
CWassr::GetPublicTimeline(
                CTwitterTimeline *timeline,
                ProceedingDialog *pdlg
            )
{
    return ( CService::GetPublicTimeline(
                            "http://api.wassr.jp/public_timeline.json",
                            timeline,
                            pdlg ) );
}

// user_timeline ���擾
CString
CWassr::GetUserTimeline(
                CTwitterTimeline *timeline,
                ProceedingDialog *pdlg
            )
{
    return ( CService::GetUserTimeline( 
                            "http://api.wassr.jp/user_timeline.json",
                            timeline,
                            pdlg ) );
}

// �w�胆�[�U�� friend �ɂ���
bool CWassr::AddFriend( const char *userID )
{
    size_t  sz  = MAX_CONTENT_SIZE;
    char    *request  = new char[MAX_KEYLENGTH + 1];
    char    *response = new char[sz];
    char    url[MAX_URLLENGTH];
    bool    ret = false;

    if ( request && response ) {
        sprintf( url,
                 "http://api.wassr.jp/friendships/create/%s.json",
                 userID );
        sprintf( request,
                 "source=%s",
                 "Chirrup" );
        SetUserAgent();
        setUpReceiveBuffer( response, sz );
        _http_postBASIC( url, m_username, m_password,
                         request, response, NULL, NULL );
        if ( *response ) {
            char    *p = strstr( response, "ok" );
            if ( p )
                ret = true;
        }
    }

    if ( response )
        delete [] response;
    if ( request )
        delete [] request;

    return ( ret );
}

// �w�胆�[�U�� friend ����O��
bool CWassr::RemoveFriend( const char *userID )
{
    size_t  sz  = MAX_CONTENT_SIZE;
    char    *request  = new char[MAX_KEYLENGTH + 1];
    char    *response = new char[sz];
    char    url[MAX_URLLENGTH];
    bool    ret = false;

    if ( request && response ) {
        sprintf( url,
                 "http://api.wassr.jp/friendships/destroy/%s.json",
                 userID );
        sprintf( request,
                 "source=%s",
                 "Chirrup" );
        SetUserAgent();
        setUpReceiveBuffer( response, sz );
        _http_postBASIC( url, m_username, m_password,
                         request, response, NULL, NULL );
        if ( *response ) {
            char    *p = strstr( response, "ok" );
            if ( p )
                ret = true;
        }
    }

    if ( response )
        delete [] response;
    if ( request )
        delete [] request;

    return ( ret );
}

// �w�� status �� favorites �ɂ��� (�u�C�C�l!�v������)
bool CWassr::SetFavorite( const char *statusID )
{
    size_t  sz  = MAX_CONTENT_SIZE;
    char    *request  = new char[MAX_KEYLENGTH + 1];
    char    *response = new char[sz];
    char    url[MAX_URLLENGTH];
    bool    ret = false;

    if ( request && response ) {
        sprintf( url, "http://api.wassr.jp/favorites/create/%s.json",
                 statusID );
        sprintf( request,
                 "source=%s",
                 "Chirrup" );
        SetUserAgent();
        setUpReceiveBuffer( response, sz );
        _http_postBASIC( url, m_username, m_password,
                         request, response, NULL, NULL );
        if ( *response ) {
            char    *p = strstr( response, "ok" );
            if ( p )
                ret = true;
        }
    }

    if ( response )
        delete [] response;
    if ( request )
        delete [] request;

    return ( ret );
}

// �����̃X�N���[�����̎擾
CString CWassr::GetScreenName()
{
    TWITTER_USER    user;
    CString         screenName = _T("");
    size_t          sz  = MAX_CONTENT_SIZE;
    char            *response = new char[sz];
    char            url[MAX_URLLENGTH];
 // bool            ret = false;

    if ( response ) {
        strcpy( url, "http://api.wassr.jp/show.json" );
        SetUserAgent();
        setUpReceiveBuffer( response, sz );
        _http_getBASIC( url, m_username, m_password, response, NULL, NULL );
        if ( *response ) {
            char    *p = strstr( response, "\"screen_name\"" );
            if ( p ) {
             // ret  = true;
                user = GetUserFromJSON( response, response + strlen(response),
                                        "dummy" );
                screenName = user.screenName;
            }
        }

        delete [] response;
    }

    return ( screenName );
}


/*
 * Twitter �̃��X�|���X�̃t�H�[�}�b�g (JSON �̏ꍇ)
 *  [{"created_at":"�^�C���X�^���v",
 *    "text":"�X�e�[�^�X",
 *    "id":�X�e�[�^�XID,
 *    "user":{"name":"���[�U��(firstname + lastname)",
 *            "description":"���ȏЉ�",
 *            "location":"���Z�n",
 *            "url":"���[�U��Web�y�[�WURL",
 *            "id":���[�UID,
 *            "protected":�v���e�N�g���Ă��邩�ۂ�,
 *            "profile_image_url":"���[�U�A�C�R��URL",
 *            "screen_name":"�X�N���[����"
 *   ......
 *  ]
 *
 * Wassr �̃��X�|���X�̃t�H�[�}�b�g (JSON �̏ꍇ)
 *  [{"link":"�X�e�[�^�XURL",
 *    "epoch":�^�C���X�^���v(1970�N1��1��0��0��0�b����̌o�ߕb��),
 *    "user_login_id":"���[�U�̃��O�C��ID",
 *    "rid":"�X�e�[�^�XID",
 *    "photo_url":null,
 *    "photo_thumbnail_url":null,
 *    "html":"�X�e�[�^�X(text/html)",
 *    "text":"�X�e�[�^�X(text/plain)",
 *    "user":{"screen_name":"�X�N���[����"}},
 *   ......
 *  ]
 *  (2007�N6��15���ɁArid, photo_url, photo_thumbnail_url ���ǉ����ꂽ)
 *
 * �������� �̃��X�|���X�̃t�H�[�}�b�g (JSON �̏ꍇ)
 *  [{"created_at":"�^�C���X�^���v",
 *    "text":"�X�e�[�^�X",
 *    "id":�X�e�[�^�XID,
 *    "res_count":���X�|���X��,
 *    "user":{"screen_name":"�X�N���[����",
 *            "description":"���ȏЉ�",
 *            "profile_image_url":"���[�U�A�C�R��URL",
 *            "url":"���[�U��Web�y�[�WURL",
 *            "id":���[�UID}},
 *   ......
 *  ]
 */

CString
CWassr::GetTimeline(
                CString          &messages,
                TWITTER_STATUS   **stat,
                long             &numOfStats,
                TIMELINE_TYPE    t,
                const char       *endPointURL,
                CTwitterTimeline *timeline,
                ProceedingDialog *pdlg
            )
{
    CChirrupApp *ap = (CChirrupApp *)AfxGetApp();

    if ( timeline->m_numOfStats > 0 ) {
        if ( !(*stat) ) {
            *stat = new TWITTER_STATUS[MAX_NUMOFSTATUS];
            numOfStats = 0;
        }
        int i;
        for ( i = 0; i < timeline->m_numOfStats; i++ )
            (*stat)[i] = (timeline->m_stat)[i];
        numOfStats = timeline->m_numOfStats;
    }

    size_t  sz = MAX_CONTENT_SIZE * 16;
    char    *response = new char[sz];
    if ( response ) {
        CString url = endPointURL;

        SetUserAgent();
        setUpReceiveBuffer( response, sz );
        if ( t != PUBLIC_TIMELINE )
            _http_getBASIC(url, m_username, m_password, response, NULL, pdlg);
        else
            _http_get( url, response, pdlg );
        if ( response[0] ) {
            GetStatFromJSON( response, stat, numOfStats );
            WriteLog( timeline );

            int i;
            messages = _T("");
            for ( i = 0; i < numOfStats; i++ ) {
                if ( ap->m_event ) {
                    DWORD   r = WaitForSingleObject( ap->m_event, 0 );
                    if ( r == WAIT_OBJECT_0 ) {
                        // ��ƒ��f
                        ResetEvent( ap->m_event );
#ifdef  _DEBUG
                        MessageBox( NULL,
                                    "��ƒ��f",
                                    "CWassr::GetTimeline()",
                                    MB_OK|MB_ICONWARNING );
#endif
                        break;
                    }
                }

                MakeMessageForScreen( messages, &((*stat)[i]) );
                if ( messages.GetLength() >= (MAX_CONTENT_SIZE / 2) )
                    break;
            }
        }

        delete [] response;
    }

    timeline->m_numOfStats = numOfStats;
    if ( timeline->m_numOfStats > 0 ) {
        int i;
        for ( i = 0; i < numOfStats; i++ )
            (timeline->m_stat)[i] = (*stat)[i];
    }

    return ( messages );
}

CString CWassr::GetStatusID(
                        const char *p,
                        const char *terminator
                    )
{
    return ( GetIdFromJSON( p, terminator ) );
}

void CWassr::SetStatFromJSON(
                        const char       *p,
                        const char       *s,
                        TWITTER_STATUS   *sp,
                        CString          &message
                    )
{
    char    userName[MAX_NAMELEN];
    char    orig_text[MAX_DESCRIPTION_LEN];

    sp->createdAt = GetCreatedAtFromJSON(p, s);
    strcpy( sp->id, GetIdFromJSON(p, s) );

    strcpy( sp->text,
            GetTextFromJSON( p, s, orig_text ) );
    Regulize( sp->text, orig_text );

    sprintf( sp->orig_text, "%s",
             (const char *)GetHtmlFromJSON( p, s ) );
    if ( sp->orig_text[0] == NUL )
        strcpy( sp->orig_text, orig_text );

    strcpy( userName,
            GetUserLoginIdFromJSON( p, s ) );
    sp->user = GetUserFromJSON( p, s, userName );

    strcpy( sp->user.lastStatus, sp->text );

    MakeMessageForScreen( message, sp );
    MakeMessageForLogging( sp );
}


long
CWassr::GetEpochFromJSON( const char *p, const char *terminator )
{
    long    epoch;

    // "epoch"
    epoch = GetIntegerFromJSON( "\"epoch\"", p, terminator );

    return ( epoch );
}

CString
CWassr::GetIdFromJSON( const char *p, const char *terminator )
{
    char    *pp;
    char    link[MAX_PATH];
    CString id;

    // "link"
    GetStringFromJSON( link, MAX_PATH, "\"link\"", p, terminator );
    pp = strrchr( link, '/' );
    if ( pp )
        id = pp + 1;
    else {
        // epoch �ő�p
        sprintf( link, "%d", GetEpochFromJSON(p, terminator) );
        id = link;
    }

    return ( id );
}

CString
CWassr::GetHtmlFromJSON( const char *p, const char *terminator )
{
    char    text[MAX_DESCRIPTION_LEN];
    char    orig_text[MAX_DESCRIPTION_LEN];
    CString html;

    // "html"
    GetStringFromJSON( text, MAX_DESCRIPTION_LEN, "\"html\"", p, terminator,
                       false, orig_text );
    html = orig_text;

    return ( html );
}

CTime
CWassr::GetCreatedAtFromJSON( const char *p, const char *terminator )
{
    CTime   t;
    long    epoch;

    // "epoch"
    epoch = GetEpochFromJSON( p, terminator );

    t = CTime( epoch );

    return ( t );
}

TWITTER_USER
CWassr::GetUserFromJSON(
                const char *p,
                const char *terminator,
                const char *userName
            )
{
    TWITTER_USER    u;
    char            temp[BUFSIZ];
    char            temp2[BUFSIZ];
    const char      *pp;

    // "user"
    temp[0] = NUL;
    pp = strstr( p, "\"user\"" );
    if ( pp && (pp < terminator) ) {
        pp += 6;
        while ( (pp < terminator) && *pp && (*pp != ':') )
            pp++;
        if ( *pp == ':' ) {
            while ( (pp < terminator) && *pp && (*pp != '{') )
                pp++;

            //    "name"
            strcpy( u.name, userName );

            //    "profile_image_url"
            sprintf( u.profileImageURL,
                     "http://wassr.jp/user/%s/profile_img.png.32",
                     u.name );

            //    "description"
            u.description[0] = NUL;

            //    "location"
            u.location[0] = NUL;

            //    "id"
            strcpy( u.id, userName );

            //    "screen_name"
            GetStringFromJSON( temp, MAX_KEYLENGTH, "\"screen_name\"",
                               pp, terminator, false, temp2 );
            Regulize( temp, temp2 );
            strcpy( u.screenName, *temp ? temp : u.name );
            strcpy( u.orig_userName, temp2 );

            //    "url"
            sprintf( u.url, "http://wassr.jp/user/%s", u.name );
        }
    }

    u.lastStatus[0] = NUL;
    u.bitmap        = NUL;

    return ( u );
}

char            *
CWassr::GetUserLoginIdFromJSON(
                const char *p,
                const char *terminator
            )
{
    Thread static char  temp[BUFSIZ * 16];

    // "user_login_id"
    GetStringFromJSON(temp, BUFSIZ * 16, "\"user_login_id\"", p, terminator);

    return ( temp );
}

// Wassr �G����(�̕�������)�΍�
char    *
CWassr::Regulize( char *text, const char *origText )
{
    const char  *q = strchr( origText, (unsigned char)0xEE );
#if 0
    if ( q                                                                &&
         ( ( ((unsigned char)(*(q + 1)) == (unsigned char)0x92) &&
             ((unsigned char)(*(q + 2)) == (unsigned char)0xAC)    ) ||
           ( ((unsigned char)(*(q + 1)) == (unsigned char)0x9B) &&
             ((unsigned char)(*(q + 2)) == (unsigned char)0xB7)    ) ||
           ( ((unsigned char)(*(q + 1)) == (unsigned char)0xAA) &&
             ((unsigned char)(*(q + 2)) >= (unsigned char)0x80)    ) ||
           ( ((unsigned char)(*(q + 1)) == (unsigned char)0xAD) &&
             ((unsigned char)(*(q + 2)) >= (unsigned char)0x80)    )    )    ) {
#else
    if ( q                                                                &&
         ( ( ((unsigned char)(*(q + 1)) >= (unsigned char)0x92) &&
             ((unsigned char)(*(q + 2)) >= (unsigned char)0x80)    )    )    ) {
#endif
        strcpy( text, origText );

        char    *r;
        do {
            r = strchr( text, (unsigned char)0xEE );
            if ( r                                                                &&
                 ( ( ((unsigned char)(*(r + 1)) >= (unsigned char)0x92) &&
                     ((unsigned char)(*(r + 2)) >= (unsigned char)0x80)    )    )    )
                strcpy( r, r + 3 );
            else
                break;
        } while ( r );

        char    *p = any2sjis( text );
        if ( p )
            strcpy( text, p );
    }

    return ( text );
}


void
CWassr::MakeMessageForScreen(
            CString        &message,
            TWITTER_STATUS *sp )
{
    message += sp->user.name;
    message += _T(": ");
    message += EscapeQuote(sp->text);

    message += _T(" ��");
    message += _T(" [ID: ");
    message += sp->id;
    message += _T("]\r\n");
}

void
CWassr::MakeMessageForLogging( TWITTER_STATUS *sp )
{
    if ( !m_log )
        m_log = new TWITTER_LOG[MAX_NUMOFSTATUS + 1];

    if ( m_log && (m_numOfLogs < MAX_NUMOFSTATUS) ) {
        sprintf( m_log[m_numOfLogs].orig_text,
                 "%s [ID: %s]",
                 sp->orig_text, sp->id );
        strcpy( m_log[m_numOfLogs].orig_userName, sp->user.orig_userName );

        m_log[m_numOfLogs].createdAt = sp->createdAt.GetTime();

        struct tm   ttmm;
     // struct tm   *tm = sp->createdAt.GetGmtTm( &ttmm );
        struct tm   *tm = sp->createdAt.GetLocalTm( &ttmm );

        m_log[m_numOfLogs].createdAt_yyyy = tm->tm_year + 1900;
        m_log[m_numOfLogs].createdAt_mm   = tm->tm_mon + 1;
        m_log[m_numOfLogs].createdAt_dd   = tm->tm_mday;
        m_log[m_numOfLogs].createdAt_HH   = tm->tm_hour;
        m_log[m_numOfLogs].createdAt_MM   = tm->tm_min;
        m_log[m_numOfLogs].createdAt_SS   = tm->tm_sec;
        m_numOfLogs++;
    }
}


// �Q�����̃`�����l���̈ꗗ�̎擾
WASSR_CHANNEL_LIST  *
CWassr::GetChannelList( int &numOfChannels )
{
    WASSR_CHANNEL_LIST  *wp = NULL;
    size_t              sz  = MAX_CONTENT_SIZE;
    char                *response = new char[sz];
    char                url[MAX_URLLENGTH];
 // bool                ret = false;

    numOfChannels = 0;

    if ( response ) {
        sprintf( url,
                 "http://api.wassr.jp/channel_user/user_list.json?"
                 "login_id=%s",
                 (const char *)m_username );
        SetUserAgent();
        setUpReceiveBuffer( response, sz );
        _http_getBASIC( url, m_username, m_password, response, NULL, NULL );
        if ( *response ) {
            if ( strstr( response, "\"channels\"" ) ) {
             // ret  = true;

                char    *p = response;
                char    *q;
                while ( ( q = strstr( p, "\"image_url\":\"" ) ) != NULL ) {
                    numOfChannels++;
                    p = q + 13;
                }

                p = strstr( response, "[{" );
                q = strstr( response, "]}" );
                if ( p && (p < q) ) {
                    wp = new WASSR_CHANNEL_LIST[numOfChannels];
                    for ( int i = 0; i < numOfChannels; i++ ) {
                        GetStringFromJSON( wp[i].image_url, MAX_URLLENGTH,
                                           "\"image_url\"", p, q );
                        GetStringFromJSON( wp[i].title, MAX_CATNAMELENGTH,
                                           "\"title\"", p, q );
                        GetStringFromJSON( wp[i].name_en, MAX_NAMELEN,
                                           "\"name_en\"", p, q );

                        p = strchr( p, '}' );
                        if ( !p )
                            break;
                        p++;
                    }
                }
            }
        }

        delete [] response;
    }

    return ( wp );
}



// �ȉ��A�摜���e�֘A

// Wassr �Ƀ��O�C������
bool
CWassr::loginWassr(
                const char *username,
                const char *password,
                char       *cookie,
                char       *key,
                const char *channel,
                char       *channel_rid
            )
{
    bool    ret = false;
    size_t  sz  = MAX_CONTENT_SIZE;
    char    request[BUFSIZ];
    char    *response = new char[sz];
    char    *p, *q;

    if ( response ) {
        // login ��ʂ��擾
        key[0]    = NUL;
        cookie[0] = NUL;
        SetUserAgent();
        setUpReceiveBuffer( response, sz );
        _http_getBASIC( "http://wassr.jp/",
                        NULL, NULL,
                        response, cookie, NULL );
        if ( *response ) {
            p = strstr( response, "action=\"/account/login\"" );
            if ( p ) {
                p += 23;
                q = strstr( p, "name=\"CSRFPROTECT\"" );
                if ( q ) {
                    p = q + 18;
                    q = strstr( p, "value=\"" );
                    if ( q ) {
                        p = q + 7;
                        q = strchr( p, '"' );
                        if ( p ) {
                            strncpy( key, p, q - p );
                            key[q - p] = NUL;
                        }
                    }
                }
            }
        }

        if ( key[0] ) {
            // login ����
            sprintf( request,
                     "CSRFPROTECT=%s",
                     key );
            sprintf( request + strlen(request),
                     "&login_id=%s",
                     username );
            sprintf( request + strlen(request),
                     "&login_pw=%s",
                     password );
            sprintf( request + strlen(request),
                     "&session_forever=on" );

            key[0] = NUL;
            SetUserAgent();
            setReferer( "http://wassr.jp/" );   /* @@ */
            setUpReceiveBuffer( response, sz );
            _http_postBASIC( "http://wassr.jp/account/login",
                             NULL, NULL,
                             request, response, cookie, NULL );
            if ( *response ) {
                p = strstr( response, "action=\"/my/status/add\"" );
                if ( p ) {
                    p += 23;
                    q = strstr( p, "name=\"CSRFPROTECT\"" );
                    if ( q ) {
                        p = q + 18;
                        q = strstr( p, "value=\"" );
                        if ( q ) {
                            p = q + 7;
                            q = strchr( p, '"' );
                            if ( p ) {
                                strncpy( key, p, q - p );
                                key[q - p] = NUL;
                                ret = true;
                            }
                        }
                    }
                }

                if ( channel && channel[0] ) {
                    char    targetString[BUFSIZ];

                    sprintf( targetString,
                             "<a href=\"/channel/%s\"", channel );
                    p = strstr( response, targetString );
                    if ( p ) {
                        p += strlen( targetString );
                        q = strstr( p, "channel_rid=\"" );
                        if ( q ) {
                            p = q + 13;
                            q = strchr( p, '"' );
                            if ( q ) {
                                strncpy( channel_rid, p, q - p );
                                channel_rid[q - p] = NUL;
                            }
                        }
                    }
                }
            }
        }

        delete [] response;
    }

    return ( ret );
}

// ���e�����摜�� URL ���擾
char    *
CWassr::getPhotoURL( const char *response, const char *channel, char *url )
{
    const char  *p;
    const char  *q;
    char        targetString[BUFSIZ];
    char        *ret = NULL;

    if ( channel[0] )
        sprintf( targetString,
                 "<img src=\"/channel/%s/messages/",
                 channel );
    else
        sprintf( targetString,
                 "<img src=\"/user/%s/statuses/",
                 (const char *)m_username );

    p = strstr( response, targetString );
    if ( p ) {
        p += 10;
        q = strstr( p, "/photo_thumbnail" );
        if ( q )
            q += strlen("/photo");
        else
            q = strchr( p, '"' );
        if ( q ) {
            strncpy( targetString, p, q - p );
            targetString[q - p] = NUL;
            sprintf( url, "http://wassr.jp%s", targetString );

            ret = url;
        }
    }

    return ( ret );
}

// �摜��ǂݍ���
BOOL
CWassr::readImageData(
        const char *filename,
        size_t     filesize,
        FILEINF    *fInfo )
{
    BOOL    ret = FALSE;
    char    *imageData;
    FILE    *fp;

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

    // �A�b�v���[�h����t�@�C���̏����Z�b�g
    strcpy( fInfo->type, "application/unknown" );    /* �b�� */
    strcpy( fInfo->name, filename );

    char *p = base64( (unsigned char*)imageData, filesize );
    if ( !p ) {
        base64( NULL, 0 );
        free( imageData );
        return ( ret );
    }
    fInfo->bits = (unsigned char *)p;

    ret = TRUE;
    free( imageData );

    return ( ret );
}

// ���e�p�� request ��g�ݗ���
size_t
CWassr::makeRequestForPhoto(
        char          *request,
        char          *contentType,
        const char    *key,
        const char    *caption,
        const char    *channel_rid,
        const FILEINF *fInfo )
{
    char    *separator = getMultiPartID();
    char    *base;
    char    *tail;
    char    *p;
    size_t  szz = 0;

    getSendBufferPointer( request, base );
    tail = base;

    sprintf( contentType, "multipart/form-data; boundary=%s", separator );

    strcpy( tail, 
            makeMultiPartItem( separator, MULITIPART_ITEM_TYPE_STRING,
                               "CSRFPROTECT", 0, key, NULL ) );

    szz  =  strlen( tail );
    tail += szz;
    szz  =  0;
    p    =  makeMultiPartItem( separator, MULITIPART_ITEM_TYPE_FILE,
                               "image", 0, (char *)fInfo, &szz );
    memcpy( tail, p, szz );
    tail += szz;

    strcat( tail,
            makeMultiPartItem( separator, MULITIPART_ITEM_TYPE_STRING,
                               "channel_rid", 0,
                               channel_rid[0] ? channel_rid : "", NULL ) );

    strcat( tail,
            makeMultiPartItem( separator, MULITIPART_ITEM_TYPE_STRING,
                               "message", 0, caption, NULL ) );
    strcat( tail, 
            makeMultiPartItem( separator, MULITIPART_ITEM_TYPE_STRING,
                               "source", 0, "Chirrup", NULL ) );
    sprintf( tail + strlen( tail ), "--%s--\r\n", separator );
    szz  =  strlen( tail );
    tail += szz;

    setUpSendBuffer( request, szz, base );
    makeMultiPartItem( separator, MULITIPART_ITEM_TYPE_BUFFERFREE,
                       NULL, 0, NULL, NULL );

    szz = tail - base;
    setUpSendBuffer( request, szz, base );

    return ( szz );
}

// �摜�𓊍e
BOOL
CWassr::PostPhoto(
    const char *filename,// (I)   ���e����摜�̃t�@�C����
    size_t     filesize, // (I)   ���e����摜�̃t�@�C���T�C�Y
    const char *caption, // (I)   ���e����摜�Ƃ�������ɓ��e����u�����v
    char       *url,     // (O)   �A�b�v���[�h��URL
    char       *cookie,  // (I/O) �N�b�L�[
    const char *key,            // (I)   CSRF�΍�L�[
    const char *channel,        // (I) �`�����l����
    const char *channel_rid )   // (I) �`�����l��ID
{
    BOOL    ret = FALSE;
    char    *request;
    char    *response;
    char    *p;
    size_t  sz1 = filesize * 6 + BUFSIZ;
    size_t  sz2 = MAX_CONTENT_SIZE;
    char    *targetCaption;
    char    contentType[MAX_LOGICALLINELEN];
    FILEINF fInfo;

    // ���e���悤�Ƃ��Ă���摜�t�@�C����ǂݍ���
    if ( !readImageData( filename, filesize, &fInfo ) )
        return ( ret );

    if ( !caption || !(*caption) )
        caption = " ";
    targetCaption = (char *)malloc( strlen(caption) * 6 + 1 );
    if ( !targetCaption ) {
        return ( ret );
    }
    p = any2utf( caption );
    strcpy( targetCaption, p ? p : caption );
    strcat( targetCaption, " (posted by Chirrup)" );

    request  = (char *)malloc( sz1 );
    if ( !request ) {
        free( targetCaption );
        return ( ret );
    }
    response = (char *)malloc( sz2 );
    if ( !response ) {
        free( request );
        free( targetCaption );
        return ( ret );
    }
    memset( request, 0x00, sz1 );

    // multipart/form-data �̑g�ݗ���
    makeRequestForPhoto( request, contentType, key,
                         targetCaption, channel_rid, &fInfo );

    // ���N�G�X�g���s
    setTimeoutTime( DEFAULT_HTTP_TIMEOUT * (1 + (filesize / (1024 * 1024))) );
                                    // �T�C�Y�ɔ�Ⴕ���^�C���A�E�g���Ԃ�ݒ�
    setReferer( "http://wassr.jp/my" ); /* @@ */
    setUpReceiveBuffer( response, sz2 );
    http_postEx( "http://wassr.jp/my/status/add",
                 contentType,
                 request, response, cookie );
    if ( *response ) {
        if ( getPhotoURL( response, channel, url ) )
            ret = TRUE;
    }

    base64( NULL, 0 );
    free( response );
    free( request  );
    free( targetCaption );

    return ( ret );
}

BOOL
CWassr::PostPhoto(
    const char  *filename, // (I) ���e����摜�̃t�@�C����
    size_t      filesize,  // (I) ���e����摜�̃t�@�C���T�C�Y
    const char  *caption,  // (I) ���e����摜�Ƃ�������ɓ��e����u�����v
    char        *url )     // (O) �A�b�v���[�h��URL
{
    BOOL    ret = FALSE;
    char    key[MAX_KEYLENGTH + 1];
    char    cookie[MAX_COOKIE_LEN];
    char    channel[MAX_CHANNEL_LEN];
    char    channel_rid[MAX_KEYLENGTH + 1];

    key[0]         = NUL;
    cookie[0]      = NUL;
    channel[0]     = NUL;
    channel_rid[0] = NUL;

    if ( *caption == '#' ) {
        const char  *p = strchr( caption, ' ' );
        if ( p ) {
            strncpy( channel, caption + 1, MAX_CHANNEL_LEN - 2 );

            char    *q = strchr( channel, ' ' );
            if ( q ) {
                *q = NUL;
                caption = p + 1;
            }
        }
    }

    // Wassr �� login
    if ( loginWassr(m_username,m_password,cookie,key,channel,channel_rid) ) {
        // �摜�� POST
        ret = PostPhoto( filename, filesize, caption,
                         url, cookie, key,
                         channel, channel_rid );
    }

    return ( ret );
}


/*
 * (API �o�R�ł�)�摜���e
 */

// ���e�p�� request ��g�ݗ���
size_t
CWassr::makeRequestForPhotoViaAPI(
        char          *request,
        char          *contentType,
        const char    *caption,
        const char    *channel,
        const char    *rid,
        const FILEINF *fInfo )
{
    char    *separator = getMultiPartID();
    char    *base;
    char    *tail;
    char    *p;
    size_t  szz = 0;

    getSendBufferPointer( request, base );
    tail = base;

    sprintf( contentType, "multipart/form-data; boundary=%s", separator );

    strcpy( tail, 
            makeMultiPartItem( separator, MULITIPART_ITEM_TYPE_STRING,
                               "source", 0, "Chirrup", NULL ) );

    szz  =  strlen( tail );
    tail += szz;
    szz  =  0;
    p    =  makeMultiPartItem( separator, MULITIPART_ITEM_TYPE_FILE,
                               "image", 0, (char *)fInfo, &szz );
    memcpy( tail, p, szz );
    tail += szz;

    strcpy( tail, 
            makeMultiPartItem( separator, MULITIPART_ITEM_TYPE_STRING,
                               "reply_status_rid", 0,
                               rid[0] ? rid : "", NULL ) );

    strcpy( tail + strlen(tail),
            makeMultiPartItem( separator, MULITIPART_ITEM_TYPE_STRING,
                               channel[0] ? "body" : "status", 0,
                               caption, NULL ) );

    if ( channel[0] )
        strcpy( tail + strlen(tail), 
                makeMultiPartItem( separator, MULITIPART_ITEM_TYPE_STRING,
                                   "name_en", 0, channel, NULL ) );

    sprintf( tail + strlen( tail ), "--%s--\r\n", separator );
    szz  =  strlen( tail );
    tail += szz;

    setUpSendBuffer( request, szz, base );
    makeMultiPartItem( separator, MULITIPART_ITEM_TYPE_BUFFERFREE,
                       NULL, 0, NULL, NULL );

    szz = tail - base;
    setUpSendBuffer( request, szz, base );

    return ( szz );
}

// �摜�𓊍e
BOOL
CWassr::PostPhotoViaAPI(
    const char *filename,   // (I) ���e����摜�̃t�@�C����
    size_t     filesize,    // (I) ���e����摜�̃t�@�C���T�C�Y
    const char *caption,    // (I) ���e����摜�Ƃ�������ɓ��e����u�����v
    const char *rid,        // (I) ���񓊍e����u�����v�̕ԐM�Ώہu����ID�v
    char       *url,        // (O) �A�b�v���[�h��URL
    const char *channel )   // (I) �`�����l����
{
    BOOL    ret = FALSE;
    char    *request;
    char    *response;
    char    *p;
    size_t  sz1 = filesize * 6 + BUFSIZ;
    size_t  sz2 = MAX_CONTENT_SIZE;
    char    *targetCaption;
    char    contentType[MAX_LOGICALLINELEN];
    FILEINF fInfo;

    // ���e���悤�Ƃ��Ă���摜�t�@�C����ǂݍ���
    if ( !readImageData( filename, filesize, &fInfo ) )
        return ( ret );

    if ( !caption || !(*caption) )
        caption = " ";
    targetCaption = (char *)malloc( strlen(caption) * 6 + 1 );
    if ( !targetCaption ) {
        return ( ret );
    }
    p = any2utf( caption );
    strcpy( targetCaption, p ? p : caption );

    request  = (char *)malloc( sz1 );
    if ( !request ) {
        free( targetCaption );
        return ( ret );
    }
    response = (char *)malloc( sz2 );
    if ( !response ) {
        free( request );
        free( targetCaption );
        return ( ret );
    }
    memset( request, 0x00, sz1 );

    // multipart/form-data �̑g�ݗ���
    makeRequestForPhotoViaAPI( request, contentType,
                               targetCaption, channel, rid, &fInfo );

    // ���N�G�X�g���s
    setTimeoutTime( DEFAULT_HTTP_TIMEOUT * (1 + (filesize / (1024 * 1024))) );
                                    // �T�C�Y�ɔ�Ⴕ���^�C���A�E�g���Ԃ�ݒ�

    SetUserAgent();
    setUpReceiveBuffer( response, sz2 );

    _http_postBASIC( channel[0]
                        ? "http://api.wassr.jp/channel_message/update.json"
                        : "http://api.wassr.jp/update.json",
                     m_username, m_password,
                     request, response, NULL, NULL );
    if ( *response ) {
        if ( strstr( response, "\"text\"" )         ||
             strstr( response, "{\"error\":null}" )    ) {
            if ( getPhotoURL( response, channel, url ) )
                ret = TRUE;
        }
    }

    base64( NULL, 0 );
    free( response );
    free( request  );
    free( targetCaption );

    return ( ret );
}

BOOL
CWassr::PostPhotoViaAPI(
    const char  *filename, // (I) ���e����摜�̃t�@�C����
    size_t      filesize,  // (I) ���e����摜�̃t�@�C���T�C�Y
    const char  *caption,  // (I) ���e����摜�Ƃ�������ɓ��e����u�����v
    char        *url )     // (O) �A�b�v���[�h��URL
{
    BOOL    ret = FALSE;
    CString     monologue = caption;
    char        rid[MAX_KEYLENGTH];
    char        channel[MAX_CHANNEL_LEN];

    rid[0]     = NUL;
    channel[0] = NUL;
    if ( !strncmp( monologue, ">>", 2 ) ) {
        strncpy( rid, ((const char *)monologue) + 2, MAX_KEYLENGTH - 2 );
        rid[MAX_KEYLENGTH - 2] = NUL;

        char    *p = strchr( rid, ' ' );
        if ( p ) {
            *p = NUL;
            monologue = strchr( monologue, ' ' ) + 1;
        }
    }
    if ( monologue[0] == '#' ) {
        const char	*p = strchr( monologue, ' ' );
        if ( p ) {
            strncpy( channel, ((const char *)monologue) + 1, MAX_CHANNEL_LEN - 2 );

            char    *q = strchr( channel, ' ' );
            if ( q ) {
                *q = NUL;
                monologue = p + 1;
            }
        }
    }

    // �摜�� POST
    ret = PostPhotoViaAPI( filename, filesize, monologue, rid, url, channel );
    return ( ret );
}
