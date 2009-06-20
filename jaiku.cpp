/*
 * jaiku.cpp : Jaiku �N���C�A���g chirrup
 *      Jaiku API �𗘗p���邽�߂̊e�폈���Q
 *          written by H.Tsujimura  28 May 2007
 *
 *      Copyright (c) 2007 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/jaiku.cpp $
 * 
 * 2     09/05/15 2:34 tsupo
 * �u1.140�Ł�1.141�Łv�ł̕ύX�_����荞��
 * 
 * 44    09/05/14 14:55 Tsujimura543
 * Jaiku �� OAuth �̃��N�G�X�g�g�[�N������уA�N�Z�X�g�[�N���擾����
 * ���X�|���X�̌`�����ς����(���s���܂܂���悤�ɂȂ����A��)�̂�
 * �����C�������{
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 43    09/04/28 20:52 Tsujimura543
 * �^�C���A�E�g�擾�������K�莞�ԓ��ɏI���Ȃ��ꍇ�̏�����ύX
 * (�X���b�h�����I�������ł͂Ȃ��A�C�x���g�ʒm�������̗p)
 * 
 * 42    09/04/16 4:08 Tsujimura543
 * public_timeline �擾���� OAuth �F�؂��g��Ȃ��悤�ɏC��
 * 
 * 41    09/04/16 3:40 Tsujimura543
 * Jaiku �́u����ID�v�A�u�R�����gID�v�̎d�l�ύX�ɔ����C�������{
 * 
 * 40    09/04/16 1:40 Tsujimura543
 * Jaiku �� OAuth �Ή� (�Â�)
 * 
 * 39    09/04/15 1:17 Tsujimura543
 * Jaiuku �� OAuth �Ή�����
 * 
 * 38    09/03/10 22:14 Tsujimura543
 * GetStringFromJSON() �Ƀo�b�t�@�I�[�o�[�����΍�����{
 * 
 * 37    08/12/04 18:19 Tsujimura543
 * �R�[�h�����A���艻��Ƃ����{
 * 
 * 36    07/12/19 18:44 Tsujimura543
 * http �֘A�֐��Ăяo���܂��𐮗�
 * 
 * 35    07/12/17 23:23 Tsujimura543
 * RegulateCode() �����ɔ����Atimeline �̕\�������������Ȃ錻�ۂ���������
 * ���܂������A�������������A�Ή����� (����m�F�ς�)
 * 
 * 34    07/12/12 19:09 Tsujimura543
 * RegulateCode() �𓱓��BUTF-8 �ɂ͑��݂��邪 CP932 �ɂ͑��݂��Ȃ�����
 * �ɂ��āA����������ԂɂȂ�̂��\�Ȍ���h���悤�ɂ��Ă݂�
 * 
 * 33    07/07/19 21:35 Tsujimura543
 * �^�C���X�^���v�֘A�̏����� VC++ 6 / VC++ 2005 ���ʃR�[�h�ɕύX
 * 
 * 32    07/07/05 1:25 Tsujimura543
 * (1) GetUserTimeline() �̈�����ύX
 * (2) MakeMessageForScreen() �� MakeMessageForLogging() �����ۂ�
 *     �g���悤�ɂ���
 * 
 * 31    07/07/05 0:50 Tsujimura543
 * (1) TWITTER_USER �\���̂̕ύX(orig_userName��ǉ�)�ɔ����C��
 * (2) MakeMessageForScreen() �� MakeMessageForLogging() ��p��
 * 
 * 30    07/07/03 13:46 Tsujimura543
 * Visual Studio 2005 �ł̃r���h���ʂ𔽉f
 * 
 * 29    07/06/26 16:34 Tsujimura543
 * �]���ȃR�����g���폜
 * 
 * 28    07/06/26 16:32 Tsujimura543
 * Jaiku �̃����N�ɑΉ�(���邽�߂� TWITTER_STATUS �� reserved ���g�p)
 * 
 * 27    07/06/25 18:03 Tsujimura543
 * DeleteReserved(), DeleteReserved2() �֘A�A�R�[�h�𐮗�
 * 
 * 26    07/06/22 18:06 Tsujimura543
 * SetJaikuPresenceFromJSON() �� fix
 * 
 * 25    07/06/21 19:15 Tsujimura543
 * SetUserAgent() �� CService ���̃��\�b�h�Ɉ�{������
 * 
 * 24    07/06/21 18:16 Tsujimura543
 * status ID �i�[�̈�Ń������I�[�o�[��������������\����
 * ���邱�Ƃ������������߁A�΍�����{
 * 
 * 23    07/06/21 1:08 Tsujimura543
 * PostPresence() ���Ŋm�ۂ��Ă��� request �̃T�C�Y������������ꍇ��
 * ���邱�Ƃ������B�T�C�Y�̌v�Z���C������
 * 
 * 22    07/06/20 23:35 Tsujimura543
 * �ُ�n��������������
 * 
 * 21    07/06/20 20:54 Tsujimura543
 * (1) [No.xxx] �� [ID: xxx] �ɕύX
 * (2) GetTitleFromJSON() ���ŃV���[�v�G���R�[�h������̃f�R�[�h������悤
 *     �ɂ���
 * 
 * 20    07/06/20 19:28 Tsujimura543
 * GetStatusID() �𓱓�
 * 
 * 19    07/06/20 2:14 Tsujimura543
 * CJaiku �� CTwitter �̔h���N���X���� CService �̔h���N���X�ɕύX
 * (���邽�߂ɏ������z�֐��ɑΉ�����_�~�[�̊֐���ǉ�)
 * 
 * 18    07/06/20 0:30 Tsujimura543
 * �R�����g��ǉ�
 * 
 * 17    07/06/19 23:05 Tsujimura543
 * CService �����ɔ����C�������{
 * 
 * 16    07/06/19 0:42 Tsujimura543
 * ���O�t�@�C���ɂ�������ID���L�^����悤�ɂ���
 * 
 * 15    07/06/15 23:36 Tsujimura543
 * presence ID, comemnt ID ��\������悤�ɂ��Ă݂�
 * 
 * 14    07/06/13 19:39 Tsujimura543
 * Jaiku2Twitter() ���C���AJaiku ���[�U�̃v���t�B�[���\�����ɁAlastStatus
 * ���\�������悤�ɂ���
 * 
 * 13    07/06/08 23:56 Tsujimura543
 * Content �̓��e����łȂ��ꍇ�́ATitle �ƈꏏ�Ƀ��O�ɏo�͂���悤��
 * ���Ă݂�
 * 
 * 12    07/06/07 19:56 Tsujimura543
 * ���t�@�N�^�����O
 * 
 * 11    07/06/07 4:17 Tsujimura543
 * GetJaikuPresenceFromJSON() �����C (�������Q�ƃG���[�ŗ�����s�)
 * 
 * 10    07/06/07 3:27 Tsujimura543
 * ���O�t�@�C���̃^�C���X�^���v��9���Ԃ�������18���Ԃ����s����C��
 * 
 * 9     07/06/06 23:11 Tsujimura543
 * ���O���t�@�C���ɏ����o���@�\������
 * 
 * 8     07/06/04 18:23 Tsujimura543
 * Jaiku �� friends_timeline �Ή� (����m�F�ς�)
 * 
 * 7     07/06/04 14:51 Tsujimura543
 * _http_get() �� _http_post() �̃v���g�^�C�v�錾�� twitter.h �Ɉړ�
 * 
 * 6     07/05/29 12:48 Tsujimura543
 * Jaiku �� friends_timeline �Ή�(�r��)
 * 
 * 5     07/05/29 6:50 Tsujimura543
 * C1001 �G���[�΍�
 * 
 * 4     07/05/29 5:43 Tsujimura543
 * Jaiku �ւ̓��e���T�|�[�g
 * 
 * 3     07/05/29 5:13 Tsujimura543
 * Jaiku �� user_timeline �̉{���ɑΉ�
 * 
 * 2     07/05/29 4:34 Tsujimura543
 * Jaiku �� public_timeline �̉{���@�\�A���� (����m�F�ς�)
 * 
 * 1     07/05/29 1:47 Tsujimura543
 * �ŏ��̔� (������)
 */

#include "chirrup.h"
#include "twitter.h"
#include "twitterTimeline.h"
#include "jaiku.h"
#include "http.h"
extern "C" {
#include "utility.h"
#include "sha1.h"
}
#include "widechar.h"

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/chirrup/jaiku.cpp 2     09/05/15 2:34 tsupo $";
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

CJaiku::CJaiku() : CService()
{
    m_apiKey = _T("");

    m_stat   = NULL;
    m_stat2  = NULL;
    m_stat3  = NULL;

#ifdef  _DEBUG
    m_serviceName   = _T("jaiku");
#endif
    m_serviceSymbol = _T("Jaiku");
}

CJaiku::~CJaiku()
{
    if ( m_log ) {
        delete [] m_log;
        m_log = NULL;
    }

    if ( m_stat ) {
        delete [] m_stat;
        m_stat = NULL;
    }
    if ( m_stat2 ) {
        delete [] m_stat2;
        m_stat2 = NULL;
    }
    if ( m_stat3 ) {
        delete [] m_stat3;
        m_stat3 = NULL;
    }
}

void CJaiku::DeleteReserved(TWITTER_STATUS *sp)
{
    if ( sp && sp->reserved ) {
        CString *p = (CString *)(sp->reserved);
        delete p;
        sp->reserved = NULL;
    }
}

void CJaiku::DeleteReserved2(TWITTER_STATUS *sp)
{
    if ( sp && sp->reserved2 ) {
    }
}

// �����𓊍e
bool
CJaiku::PostPresence( CString monologue, ProceedingDialog *pdlg )
{
    bool    ret = false;
    size_t  sz  = MAX_CONTENT_SIZE;
    size_t  len = monologue.GetLength() * 18;
    char    *request  = new char[BUFSIZ + len + 1];
    char    *response = new char[sz];
    char    url[MAX_URLLENGTH];
    char    cid[MAX_KEYLENGTH];

    strcpy( url, "http://api.jaiku.com/json" );
    cid[0] = NUL;
    if ( !strncmp( monologue, ">>", 2 ) ) {
        strncpy( cid, ((const char *)monologue) + 2, MAX_KEYLENGTH - 2 );
        cid[MAX_KEYLENGTH - 2] = NUL;

        char    *p = strchr( cid, ' ' );
        if ( p ) {
            *p = NUL;
            monologue = strchr( monologue, ' ' ) + 1;
        }
    }

    char        *p = sjis2utf( monologue );

    if ( request && response ) {
        if ( m_useOAuth ) {
            // OAuth �F��
            delete [] request;
            request = new char[sz];

            char    key[MAX_KEYLENGTH * 2];
            char    base[MAX_CONTENT_SIZE];
            char    param[MAX_CONTENT_SIZE];

            key[0]   = NUL;
            base[0]  = NUL;
            param[0] = NUL;

            sprintf( request, "%s", p ? p : (const char *)monologue );
            p = GetTinyURL( request );
            sprintf( param,
                     "message=%s&"
                     "method=post&"
                     "nick=%s&",
                     encodeURLi( p ? p : monologue, FALSE ),
                     (const char *)m_username );
            MakeOAuthBase( url, "POST", key, base, param );

            sprintf( param + strlen(param),
                     "&"
                     "user=%s",
                     (const char *)m_username );
            MakeOAuthRequest( url, "POST", request, key, base, param );
        }
        else {
            // �]���̔F��
            sprintf( request, "status=%s",
                     encodeURL( p ? p : (const char *)monologue ) );
            setUpReceiveBuffer( response, sz );
            sprintf( request,
                     "user=%s&"
                     "personal_key=%s&"
                     "method=%s&"
                     "message=%s&",
                     (const char *)m_username,
                     (const char *)m_apiKey,
#ifdef  JAIKU_LEGACY_API
                     "presence.send",
#else
                     "post",
#endif
                     encodeURL( p ) );
#ifdef  FEATURE_NOT_AVAILABLE
            if ( cid[0] ) {
                /*
                sprintf( url,
                         "http://api.jaiku.com/presence/%s/json",
                         cid );
                */
                sprintf( request,
                         "user=%s&"
                         "personal_key=%s&"
                         "method=%s&"
                         "presence=%s&"
                         "message=%s&",
                         m_username,
                         m_apiKey,
                         "presence.send",
                         cid,
                         encodeURL( p ) );
            }
#endif
        }
        SetUserAgent();
        setUpReceiveBuffer( response, sz );
        _http_post( url, request, response, pdlg );
        if ( *response ) {
            if ( strstr( response, "{\"status\":\"ok\"}" ) )
                ret = true;
        }
    }

    if ( response )
        delete [] response;
    if ( request )
        delete [] request;

    return ( ret );
}


// timeline ���擾
CString
CJaiku::GetTimeline(
            CString          &messages,
            JAIKU_STATUS     **stat,
            long             &numOfStats,
            TIMELINE_TYPE    timelineType,
            const char       *endPointURL,
            CTwitterTimeline *timeline,
            ProceedingDialog *pdlg )
{
    CChirrupApp *ap = (CChirrupApp *)AfxGetApp();

    if ( timeline->m_numOfStats > 0 ) {
        if ( !(*stat) ) {
            *stat = new JAIKU_STATUS[MAX_NUMOFSTATUS];
            numOfStats = 0;
        }

        Twitter2Jaiku( *stat, timeline->m_stat, timeline->m_numOfStats );
        numOfStats = timeline->m_numOfStats;
    }

    size_t  sz = MAX_CONTENT_SIZE * 16;
    char    *response = new char[sz];
    if ( response ) {
        CString url = endPointURL;

        if ( (timelineType != PUBLIC_TIMELINE) && m_useOAuth ) {
            // OAuth �F��
            char    *request = new char[sz];
            char    targetURL[MAX_URLLENGTH];
            char    *p = strchr( url, '?' );
            bool    userTimeline = false;
            if ( p ) {
                strncpy( targetURL, url, p - url );
                targetURL[p - url] = NUL;
                userTimeline = true;
            }
            else
                strcpy( targetURL, url );

            char    key[MAX_KEYLENGTH * 2];
            char    base[MAX_CONTENT_SIZE];
            char    param[MAX_CONTENT_SIZE];

            key[0]   = NUL;
            base[0]  = NUL;
            param[0] = NUL;
            MakeOAuthBase( targetURL, "GET", key, base, param );

            if ( userTimeline )
                sprintf( param + strlen(param),
                         "&"
                         "user=%s",
                         (const char *)m_username );
            MakeOAuthRequest( targetURL, "GET", request, key, base, param );

            SetUserAgent();
            setUpReceiveBuffer( response, sz );
            _http_getBASIC(request, NULL, NULL, response, NULL, NULL);
            delete [] request;
        }
        else {
            // �]���̔F��
            SetUserAgent();
            setUpReceiveBuffer( response, sz );
            _http_get( url, response, pdlg );
        }
        if ( response[0] && !strstr( response, "<!DOCTYPE" ) ) {
            GetJaikuPresenceFromJSON( response, timelineType );
            WriteLog( timeline );

            int             i;
            TWITTER_STATUS  ts;
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
                                    "CJaiku::GetTimeline()",
                                    MB_OK|MB_ICONWARNING );
#endif
                        break;
                    }
                }

                ts.createdAt = (*stat)[i].createdAt;
                strcpy( ts.id,              (*stat)[i].id );
                strcpy( ts.text,            (*stat)[i].title );
                strcpy( ts.user.screenName, (*stat)[i].user.nick ); 

                MakeMessageForScreen( messages, &ts );
                if ( messages.GetLength() >= (MAX_CONTENT_SIZE / 2) )
                    break;
            }
        }

        delete [] response;
    }

    timeline->m_numOfStats = numOfStats;
    if ( timeline->m_numOfStats > 0 ) {
        int i;
        for ( i = 0; i < timeline->m_numOfStats; i++ ) {
            if ( ap->m_event ) {
                DWORD   r = WaitForSingleObject( ap->m_event, 0 );
                if ( r == WAIT_OBJECT_0 ) {
                    // ��ƒ��f
                    ResetEvent( ap->m_event );
#ifdef  _DEBUG
                    MessageBox( NULL,
                                "��ƒ��f",
                                "CJaiku::GetTimeline()",
                                MB_OK|MB_ICONWARNING );
#endif
                    break;
                }
            }

            Jaiku2Twitter( *(timeline->m_stat + i), *((*stat) + i) );
        }
    }

    return ( messages );
}


// public_timeline ���擾
CString
CJaiku::GetPublicTimeline(
            CTwitterTimeline *timeline,
            ProceedingDialog *pdlg )
{
    // public stream
    GetTimeline( m_messages2,
                 &m_stat2,
                 m_numOfStats2,
                 PUBLIC_TIMELINE,
                 "http://jaiku.com/feed/json",
                 timeline,
                 pdlg );

    return ( m_messages2 );
}


// user_timeline ���擾
CString CJaiku::GetUserTimeline(
                    CTwitterTimeline *timeline,
                    ProceedingDialog *pdlg )
{
    // user's stream
    CString url = "http://";
    url += m_username;
    url += ".jaiku.com/feed/json";

    GetTimeline( m_messages3,
                 &m_stat3,
                 m_numOfStats3,
                 USER_TIMELINE,
                 url,
                 timeline,
                 pdlg );

    return ( m_messages3 );
}


// friends_timeline ���擾
CString
CJaiku::GetFriendsTimeline(
            CTwitterTimeline *timeline,
            ProceedingDialog *pdlg )
{
    // contacts stream
    CString url = "http://";
    url += m_username;
    url += ".jaiku.com/contacts/feed/json?user=";
    url += m_username;
    url += "&personal_key=";
    url += m_apiKey;

    GetTimeline( m_messages,
                 &m_stat,
                 m_numOfStats,
                 FRIENDS_TIMELINE,
                 url,
                 timeline,
                 pdlg );

    return ( m_messages );
}

// �����̃X�N���[�����̎擾
CString CJaiku::GetScreenName()
{
    return ( m_username );
}


void    CJaiku::Jaiku2Twitter( TWITTER_STATUS &ts, JAIKU_STATUS js )
{
    ts.createdAt = js.createdAt;
    strcpy( ts.id, js.id );
    strcpy( ts.text, js.title );

    if ( js.url[0] ) {
        CString *p  = new CString( js.url );
        ts.reserved = p;
    }

    Jaiku2Twitter( ts.user, js.user );
    strcpy( ts.user.lastStatus, js.title );
}

void    CJaiku::Jaiku2Twitter( TWITTER_USER &tu, JAIKU_USER ju )
{
    char    id[BUFSIZ];
    char    *p = strstr( ju.avatar, "/avatar_" );

    id[0] = NUL;
    if ( p ) {
        char    *q;

        p += 8;
        q = strchr( p, '_' );
        if ( !q )
            q = strchr( p, '.' );
        if ( q ) {
            strncpy( id, p, q - p );
            id[q - p] = NUL;
        }
    }

    strcpy( tu.id, id );
    if ( ju.lastName[0] )
        sprintf( tu.name, "%s %s", ju.firstName, ju.lastName );
    else
        strcpy( tu.name, ju.firstName );
    strcpy( tu.screenName, ju.nick );
    tu.location[0]    = NUL;
    tu.description[0] = NUL;
    strcpy( tu.profileImageURL, ju.avatar );
    strcpy( tu.url, ju.url );
    strcpy( tu.lastStatus, "" );
    tu.bitmap = ju.bitmap;
}



void
CJaiku::Twitter2Jaiku(
            JAIKU_STATUS   *js,
            TWITTER_STATUS *ts,
            long           numOfStats )
{
    int         i;
    CChirrupApp *ap = (CChirrupApp *)AfxGetApp();

    for ( i = 0; i < numOfStats; i++ ) {
        if ( ap->m_event ) {
            DWORD   r = WaitForSingleObject( ap->m_event, 0 );
            if ( r == WAIT_OBJECT_0 ) {
                // ��ƒ��f
                ResetEvent( ap->m_event );
#ifdef  _DEBUG
                MessageBox( NULL,
                            "��ƒ��f",
                            "CJaiku::Twitter2Jaiku()",
                            MB_OK|MB_ICONWARNING );
#endif
                break;
            }
        }

        js[i].createdAt = ts[i].createdAt;
        strcpy( js[i].id, ts[i].id );
        strcpy( js[i].title, ts[i].text );

        if ( ts[i].reserved ) {
            CString *p = (CString *)(ts[i].reserved);
            strcpy( js[i].url, (const char *)(*p) );
            DeleteReserved( &(ts[i]) );
        }

        Twitter2Jaiku( &(js[i].user), &(ts[i].user) );
    }
}

void
CJaiku::Twitter2Jaiku(
            JAIKU_USER   *ju,
            TWITTER_USER *tu )
{
    strcpy( ju->nick, tu->screenName );
    strcpy( ju->firstName, tu->name );
    ju->lastName[0] = NUL;
    strcpy( ju->avatar, tu->profileImageURL );
    strcpy( ju->url, tu->url );
    ju->bitmap = tu->bitmap;
}


void
CJaiku::SetJaikuPresenceFromJSON(
                const char   *q,
                const char   *s,
                JAIKU_STATUS *sp,
                CString      &message
            )
{
    sp->createdAtRelative[0] = NUL;
    sp->content[0]           = NUL;
    sp->icon[0]              = NUL;
    sp->url[0]               = NUL;
    sp->comments             = 0;
    sp->location[0]          = NUL;
    sp->orig_text[0]         = NUL;

    sp->createdAt = GetCreatedAtFromJSON(q, s);

#ifdef  JAIKU_LEGACY_TIMELINE
    int presence = 0;
    int id       = GetIdFromJSON(q, s, presence);

    if ( presence == 0 )
        sprintf( sp->id, "%d", id );
    else
        sprintf( sp->id, "%d-%d", presence, id );
#else
    char    presence[MAX_KEYLENGTH * 2 + 2];
    char    id[MAX_KEYLENGTH * 2 + 2];

    strcpy( id, GetIdFromJSON( q, s, presence ) );

    if ( presence[0] == NUL )
        strcpy( sp->id, id );
    else
        sprintf( sp->id, "%s-%s", presence, id );
#endif
    strcpy( sp->title, GetTitleFromJSON(q, s, sp->orig_text) );

    GetStringFromJSON( sp->url, MAX_URLLENGTH, "\"url\"", q, s );
    sp->user = GetUserFromJSON(q, s);


    TWITTER_STATUS  ts;

    ts.createdAt = sp->createdAt;
    strcpy( ts.id,        sp->id );
    strcpy( ts.text,      sp->title );
    strcpy( ts.orig_text, sp->orig_text );
    strcpy( ts.user.screenName,    sp->user.nick ); 
    strcpy( ts.user.orig_userName, sp->user.nick ); 

    MakeMessageForScreen( message, &ts );
    MakeMessageForLogging( &ts );
}

CString
CJaiku::GetJaikuPresenceFromJSON(
                const char    *p,
                TIMELINE_TYPE t /* = FRIENDS_TIMELINE */
            )
{
    CString         message = _T("");
    const char      *q, *s;
    const char      *delim  = "},";
    const char      *delim2 = "}    ]";
    bool            update  = true;
    int             cnt     = 0;
    char            id[MAX_KEYLENGTH * 2 + 2];
    JAIKU_STATUS    **sp;
    long            *status;

    m_numOfLogs = 0;

    switch ( t ) {
    case FRIENDS_TIMELINE:
        sp     = &m_stat;
        status = &m_numOfStats;
        break;
    case PUBLIC_TIMELINE:
        sp     = &m_stat2;
        status = &m_numOfStats2;
        break;
    case USER_TIMELINE:
        sp     = &m_stat3;
        status = &m_numOfStats3;
        break;
    default:
        return ( message );
    }

    q = CutWhiteSpaces( decodeContents( (char *)p ) );
#ifdef  _DEBUG
    FILE    *fp = fopen( "./jaiku.json", "w" );
    if ( fp ) {
        fputs( q, fp );
        fclose( fp );
    }
#endif
    
    while ( q && *q ) {
        if ( *q == '{' )
            break;
        q++;
    }
    if ( !q || (*q != '{') )
        return ( message );

    s = strstr( q, "\"stream\": [" );
    if ( s )
        q = s + 11;

    while ( q && *q ) {
        if ( !(*sp) ) {
            *sp = new JAIKU_STATUS[MAX_NUMOFSTATUS];
            *status = 0;
            update = false;
        }

        if ( *q == '[' )
            q++;
        if ( *q == ',' )
            q++;
        if ( *q == '{' )
            q++;

        s = strstr( q, delim );
        if ( !s )
            s = strstr( q, delim2 );
        if ( !s )
            break;

        if ( update ) {
            int     i;
            bool    found    = false;
#ifdef  JAIKU_LEGACY_TIMELINE
            int     presence = 0;
            int     identify = GetIdFromJSON(q, s, presence);

            if ( presence == 0 )
                sprintf( id, "%d", identify );
            else
                sprintf( id, "%d-%d", presence, identify );
#else
            char    presence[MAX_KEYLENGTH * 2 + 2];
            char    identify[MAX_KEYLENGTH * 2 + 2];

            strcpy( identify, GetIdFromJSON( q, s, presence ) );

            if ( presence[0] == NUL )
                strcpy( id, identify );
            else
                sprintf( id, "%s-%s", presence, identify );
#endif

            for ( i = 0; i < *status; i++ ) {
                // �d���`�F�b�N
                if ( !strcmp( id, (*sp)[i].id ) ) {
                    found = true;
                    break;
                }
            }
            if ( found ) {
                q = s + 2;
                continue;
            }

            for ( i = *status; i > cnt; i-- ) {
                if ( i >= MAX_NUMOFSTATUS )
                    continue;
                (*sp)[i] = (*sp)[i - 1];
            }

            SetJaikuPresenceFromJSON( q, s, &(*sp)[cnt], message );
            cnt++;
        }
        else
            SetJaikuPresenceFromJSON( q, s, &(*sp)[*status], message );

        q = s + 2;
        if ( update && (*status >= MAX_NUMOFSTATUS) )
            *status = MAX_NUMOFSTATUS - 1;
        (*status)++;
        if ( ((!update) && (*status >= MAX_NUMOFSTATUS)) ||
             (message.GetLength() >= 32000)                      )
            break;
    }

    return ( message );
}


JAIKU_USER
CJaiku::GetUserFromJSON( const char *q,
                         const char *terminator )
{
    JAIKU_USER  u;
    char        temp[BUFSIZ];
    const char  *p;

    // "user"
    temp[0] = NUL;
    u.firstName[0] = NUL;
    u.lastName[0]  = NUL;
    u.avatar[0]    = NUL;
    u.nick[0]      = NUL;
    u.url[0]       = NUL;
    p = strstr( q, "\"user\"" );
    if ( p && (p < terminator) ) {
        p += 6;
        while ( (p < terminator) && *p && (*p != ':') )
            p++;
        if ( *p == ':' ) {
            while ( (p < terminator) && *p && (*p != '{') )
                p++;
        }

        //    "first_name"
        GetStringFromJSON(temp, MAX_NAMELEN, "\"first_name\"", p, terminator);
        strcpy( u.firstName, temp );

        //    "last_name"
        GetStringFromJSON(temp, MAX_NAMELEN, "\"last_name\"", p, terminator);
        strcpy( u.lastName, temp );

        //    "avatar"
        GetStringFromJSON( temp, MAX_URLLENGTH, "\"avatar\"",
                           p, terminator, true );
        strcpy( u.avatar, temp );

        //    "nick"
        GetStringFromJSON( temp, MAX_KEYLENGTH, "\"nick\"", p, terminator );
        strcpy( u.nick, temp );

        //    "url"
        GetStringFromJSON( temp, MAX_URLLENGTH, "\"url\"", p, terminator );
        strcpy( u.url, temp );
    }

    u.bitmap = NUL;

    return ( u );
}

char            *
CJaiku::GetTitleFromJSON(
                const char *q,
                const char *terminator,
                char       *origString /* = NULL */
            )
{
                  char  temp11[BUFSIZ * 16];    // content (Shift_JIS)
                  char  temp12[BUFSIZ * 16];    // content (original)
    Thread static char  temp21[BUFSIZ * 16];    // title (Shift_JIS)
                  char  temp22[BUFSIZ * 16];    // title (original)
                  char  temp31[BUFSIZ * 16];    // entry_title (Shift_JIS)
                  char  temp32[BUFSIZ * 16];    // entry_title (original)

    // "content"
    temp11[0] = NUL;
    temp12[0] = NUL;
    GetStringFromJSON( temp11, BUFSIZ * 16, "\"content\"",
                       q, terminator, false, temp12 );

    // "title"
    temp21[0] = NUL;
    temp22[0] = NUL;
    GetStringFromJSON( temp21, BUFSIZ * 16, "\"title\"",
                       q, terminator, false, temp22 );

    // "entry_title"
    temp31[0] = NUL;
    temp32[0] = NUL;
    GetStringFromJSON( temp31, BUFSIZ * 16, "\"entry_title\"",
                       q, terminator, false, temp32 );

    // �\���p temp11/temp21
    if ( temp11[0] ) {
        // "content" �����݂���ꍇ
        if ( !strncmp( temp21, "Comment from ", 13 ) ) {
            char    *p = strstr( temp21, " on " );
            if ( p && temp31[0] ) {
                *(p + 4) = NULL;
                strcat( temp21, temp31 );
            }
            strcat( temp21, "\r\n  " );
        }
        else
            strcat( temp21, " -- " );
        strcat( temp21, temp11 );
    }
 // else {
 //     // "content" �����݂��Ȃ��ꍇ
 //     ;   // temp21 �����̂܂܎g��
 // }

    // ���O�o�͗p temp12/temp22
    if ( temp12[0] ) {
        // "content" �����݂���ꍇ
        if ( !strncmp( temp22, "Comment from ", 13 ) ) {
            char    *p = strstr( temp22, " on " );
            if ( p && temp32[0] ) {
                *(p + 4) = NULL;
                strcat( temp22, temp32 );
            }
            strcat( temp22, "\r\n\t" );
        }
        else
            strcat( temp22, " -- " );
        strcat( temp22, temp12 );
    }
 // else {
 //     // "content" �����݂��Ȃ��ꍇ
 //     ;   // temp22 �����̂܂܎g��
 // }

    if ( origString )
        strcpy( origString, temp22 );

    strcpy( temp21, RegulateCode( origString, temp21 ) );
    char    *p = strchr( temp21, '\t' );
    if ( p ) {
        char    *temp211 = new char[(p - temp21) + 1];
        char    *temp212 = new char[strlen(p + 1) + 1];

        strncpy( temp211, temp21, p - temp21 );
        temp211[p - temp21] = NUL;

        strcpy( temp212, p + 1 );

        sprintf( temp21, "%s  %s", temp211, temp212 );

        delete [] temp212;
        delete [] temp211;
    }

    // tinyurl ������ URL �ɓW�J
    ExpandTinyURL( temp21 );
    if ( origString && origString[0] ) {
        ExpandTinyURL( origString );
        if ( strchr( origString, '&' ) )
            strcpy( origString,
                    decodeNumericReference( decodeString( origString ) ) );
    }

    return ( strchr( temp21, '&' )
                ? decodeNumericReference( decodeString( temp21 ) )
                : temp21 );
}

#ifdef  JAIKU_LEGACY_TIMELINE
int
CJaiku::GetIdFromJSON( const char *q, const char *terminator, int &presence )
{
    int id = 0;

    presence = 0;

    // "id"
    id = GetIntegerFromJSON( "\"id\"", q, terminator );

    if ( id == 0 ) {
        // "comment_id"
        id = GetIntegerFromJSON( "\"comment_id\"", q, terminator );

        char    url[MAX_URLLENGTH];
        GetStringFromJSON( url, MAX_URLLENGTH, "\"url\"", q, terminator );

        char    *p = strrchr( url, '/' );
        if ( p ) {
            p++;

            char    *q = strchr( p, '#' );
            if ( q ) {
                *q = NUL;
                presence = atol( p );
            }
        }
    }

    return ( id );
}
#else
char    *
CJaiku::GetIdFromJSON( const char *q, const char *terminator, char *presence )
{
    Thread static char  id[MAX_KEYLENGTH * 2 + 2];

    presence[0] = NUL;

    // "id"
    GetStringFromJSON( id, MAX_KEYLENGTH * 2, "\"id\"", q, terminator );

    if ( id[0] == NUL ) {
        // "comment_id"
        GetStringFromJSON( id, MAX_KEYLENGTH * 2, "\"comment_id\"", q, terminator );

        char    url[MAX_URLLENGTH];
        GetStringFromJSON( url, MAX_URLLENGTH, "\"url\"", q, terminator );

        char    *p = strrchr( url, '/' );
        if ( p ) {
            p++;

            char    *q = strchr( p, '#' );
            if ( q ) {
                *q = NUL;
                strcpy( presence, p );
            }
        }
    }

    return ( id );
}
#endif


// �ȉ��A�_�~�[
#pragma warning ( disable: 4100 )
CString CJaiku::GetTimeline(
                        CString          &messages,
                        TWITTER_STATUS   **stat,
                        long             &numOfStats,
                        TIMELINE_TYPE    t,
                        const char       *endPointURL,
                        CTwitterTimeline *timeline,
                        ProceedingDialog *pdlg )
{
    return ( _T("") );
}
#pragma warning ( default: 4100 )

void CJaiku::SetStatFromJSON(
                    const char     *p,
                    const char     *s,
                    TWITTER_STATUS *sp,
                    CString        &message )
{
    sp->createdAt = GetCreatedAtFromJSON( p, s );

#ifdef  JAIKU_LEGACY_TIMELINE
    int presence = 0;
    int id       = GetIdFromJSON( p, s, presence );

    if ( presence == 0 )
        sprintf( sp->id, "%d", id );
    else
        sprintf( sp->id, "%d-%d", presence, id );
#else
    char    presence[MAX_KEYLENGTH * 2 + 2];
    char    id[MAX_KEYLENGTH * 2 + 2];

    strcpy( id, GetIdFromJSON( p, s, presence ) );

    if ( presence[0] == NUL )
        strcpy( sp->id, id );
    else
        sprintf( sp->id, "%s-%s", presence, id );
#endif
    strcpy( sp->text, GetTitleFromJSON( p, s, sp->orig_text) );

    Jaiku2Twitter( sp->user, GetUserFromJSON( p, s ) );

    MakeMessageForScreen( message, sp );
    MakeMessageForLogging( sp );
}

#pragma warning ( disable: 4100 )
CString CJaiku::GetStatusID(
                    const char *p,
                    const char *terminator )
{
    return ( _T("") );
}
#pragma warning ( default: 4100 )


void
CJaiku::MakeMessageForScreen(
            CString        &message,
            TWITTER_STATUS *sp )
{
    message += sp->user.screenName;
    message += _T(": ");
    message += EscapeQuote(sp->text);

    message += _T(" [ID: ");
    message += sp->id;
    message += _T("]\r\n");
}

void
CJaiku::MakeMessageForLogging( TWITTER_STATUS *sp )
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


bool
CJaiku::GetToken(
        const char *response,
        CString    &oauthToken,
        CString    &oauthTokenSecret
    )
{
    bool    ret = false;

    if ( response && *response ) {
        char    oauth_token[BUFSIZ];
        char    oauth_token_secret[BUFSIZ];

        char    *p = strstr( response, "oauth_token=" );
        if ( p ) {
            p += 12;

            char    *q = strchr( p, '&' );
            if ( q ) {
                strncpy( oauth_token, p, q - p );
                oauth_token[q - p] = NUL;
            }
            else {
                q = strstr( p, "\r\n" );
                if ( q ) {
                    strncpy( oauth_token, p, q - p );
                    oauth_token[q - p] = NUL;
                }
                else
                    strcpy( oauth_token, p );
            }

            oauthToken = oauth_token;
        }

        p = strstr( response, "oauth_token_secret=" );
        if ( p ) {
            p += 19;

            char    *q = strchr( p, '&' );
            if ( q ) {
                strncpy( oauth_token_secret, p, q - p );
                oauth_token_secret[q - p] = NUL;
            }
            else {
                q = strstr( p, "\r\n" );
                if ( q ) {
                    strncpy( oauth_token_secret, p, q - p );
                    oauth_token_secret[q - p] = NUL;
                }
                else
                    strcpy( oauth_token_secret, p );
            }

            oauthTokenSecret = oauth_token_secret;
        }

        if ( (oauthToken.GetLength()       > 0) &&
             (oauthTokenSecret.GetLength() > 0)    )
            ret = true;
    }

    return ( ret );
}


bool
CJaiku::GetRequestToken(
        const char *consumerKey,
        const char *consumerSecret,
        CString    &oauthToken,
        CString    &oauthTokenSecret
    )
{
    bool    ret = false;

    time_t  t  = time( NULL );
    size_t  sz = MAX_CONTENT_SIZE * 16;
    char    base[MAX_CONTENT_SIZE];
    char    param[MAX_CONTENT_SIZE];
    char    nonce[MAX_KEYLENGTH];
    char    key[MAX_KEYLENGTH * 2];

    char    *request  = new char[sz];
    char    *response = new char[sz];

    CString targetURL = _T("");
    targetURL.LoadString(IDS_URL_JAIKU_REQUEST_TOKEN);

    strcpy( nonce, getNonce(NULL) );

    sprintf( key, "%s&", encodeURLi( consumerSecret, FALSE ) );

    sprintf( base,
             "GET&"
             "%s&",
             encodeURLi( targetURL, FALSE ) );
    sprintf( param,
             "oauth_consumer_key=%s&"
             "oauth_nonce=%s&"
             "oauth_signature_method=HMAC-SHA1&"
             "oauth_timestamp=%ld&"
             "oauth_version=1.0",
             consumerKey,
             nonce,
             t );

    MakeOAuthRequest( targetURL, "GET", request, key, base, param );

    SetUserAgent();
    setUpReceiveBuffer( response, sz );
    _http_getBASIC( request, NULL, NULL, response, NULL, NULL );
    ret = GetToken( response, oauthToken, oauthTokenSecret );

    delete [] response;
    delete [] request;

    return ( ret );
}

bool
CJaiku::GetAccessToken(
        const char *consumerKey,
        const char *consumerSecret,
        CString    &oauthToken,
        CString    &oauthTokenSecret
    )
{
    bool    ret = false;

    if ( !consumerKey    || !(*consumerKey)    ||
         !consumerSecret || !(*consumerSecret)    )
        return ( ret );

    // request token �擾
    CString _oauthToken       = _T("");
    CString _oauthTokenSecret = _T("");
    if ( !GetRequestToken( consumerKey, consumerSecret,
                           _oauthToken, _oauthTokenSecret ) ) {
        MessageBox( NULL,
                    "���N�G�X�g�g�[�N���̎擾�Ɏ��s���܂����B  ",
                    "�A�N�Z�X���~", MB_OK|MB_ICONERROR );
        return ( ret );
    }

    // �u���E�U�N�� -- ���[�U�ɃA�N�Z�X�������߂�
    CString targetURL = _T("");
    targetURL.LoadString(IDS_URL_JAIKU_AUTHORIZE);

    char    url[MAX_URLLENGTH];
    sprintf( url,
             "%s?"
             "oauth_token=%s&"
             "perms=%s",
             targetURL,
             _oauthToken,
             "write" );
    ShellExecute( NULL, "open", url, NULL, NULL, SW_SHOWNORMAL );

    // ���[�U�̋��҂�
    int r = MessageBox( NULL,
            "Chirrup �� Jaiku �ɃA�N�Z�X���鋖��^���Ă��������B\r\n"
            "����^���I�������AOK �{�^���������Ă��������B\r\n"
            "����^�������Ȃ��ꍇ�� �L�����Z�� �{�^���������Ă��������B  ",
            "Jaiku �ւ̃A�N�Z�X����", MB_OKCANCEL|MB_ICONINFORMATION );
    if ( r != IDOK ) {
        MessageBox( NULL,
                    "Jaiku �ւ̃A�N�Z�X�𒆎~���܂��B  ",
                    "�A�N�Z�X���~", MB_OK|MB_ICONWARNING );
        return ( ret );
    }

    // access token �擾
    time_t  t  = time( NULL );
    size_t  sz = MAX_CONTENT_SIZE * 16;
    char    base[MAX_CONTENT_SIZE];
    char    param[MAX_CONTENT_SIZE];
    char    nonce[MAX_KEYLENGTH];
    char    key[MAX_KEYLENGTH * 2];

    char    *request  = new char[sz];
    char    *response = new char[sz];

    targetURL = _T("");
    targetURL.LoadString(IDS_URL_JAIKU_ACCESS_TOKEN);

    strcpy( nonce, getNonce(NULL) );

    sprintf( key,
             "%s&",
             encodeURLi( consumerSecret, FALSE ) );
    sprintf( key + strlen(key),
             "%s",
             encodeURLi( _oauthTokenSecret, FALSE ) );

    sprintf( base,
             "GET&"
             "%s&",
             encodeURLi( targetURL, FALSE ) );
    sprintf( param,
             "oauth_consumer_key=%s&"
             "oauth_nonce=%s&"
             "oauth_signature_method=HMAC-SHA1&"
             "oauth_timestamp=%ld&"
             "oauth_token=%s&"
             "oauth_version=1.0",
             consumerKey,
             nonce,
             t,
             _oauthToken );

    MakeOAuthRequest( targetURL, "GET", request, key, base, param );

    SetUserAgent();
    setUpReceiveBuffer( response, sz );
    _http_getBASIC( request, NULL, NULL, response, NULL, NULL );
    ret = GetToken( response, oauthToken, oauthTokenSecret );

    if ( ret ) {
        m_oauthToken       = oauthToken;
        m_oauthTokenSecret = oauthTokenSecret;
    }
    else
        MessageBox( NULL,
                    "�A�N�Z�X�g�[�N���̎擾�Ɏ��s���܂����B  ",
                    "�A�N�Z�X���~", MB_OK|MB_ICONERROR );

    delete [] response;
    delete [] request;

    return ( ret );
}


void
CJaiku::MakeOAuthBase(
        const char *url,
        const char *method,
        char       *key,
        char       *base,
        char       *param
    )
{
    CChirrupApp *ap = (CChirrupApp *)AfxGetApp();
    time_t      t   = time( NULL );
    char        nonce[MAX_KEYLENGTH];

    strcpy( nonce, getNonce(NULL) );

    sprintf( key,
             "%s&",
             encodeURLi( ap->m_jcSecret, FALSE ) );
    sprintf( key + strlen(key),
             "%s",
             encodeURLi( m_oauthTokenSecret, FALSE ) );

    sprintf( base,
             "%s&"
             "%s&",
             method,
             encodeURLi( url, FALSE ) );

    sprintf( param[0] ? param + strlen(param) : param,
             "oauth_consumer_key=%s&"
             "oauth_nonce=%s&"
             "oauth_signature_method=HMAC-SHA1&"
             "oauth_timestamp=%ld&"
             "oauth_token=%s&"
             "oauth_version=1.0",
             ap->m_jcKey,
             nonce,
             t,
             m_oauthToken );
}


void
CJaiku::MakeOAuthRequest(
        const char *url,
        const char *method,
        char       *request,
        char       *key,
        char       *base,
        char       *param
    )
{
    char    digest[SHA1HashSize * 4];

    sprintf( base + strlen(base),
             "%s",
             encodeURLi(param, FALSE) );

    memset( digest, 0x00, SHA1HashSize );
    hmac_sha1( (unsigned char *)base, strlen(base),
               (unsigned char *)key, strlen(key),
               digest );
    strcpy( digest, base64( (unsigned char *)digest, SHA1HashSize ) );

    if ( !strcmpi( method, "GET" ) )
        sprintf( request,
                 "%s?"
                 "%s&"
                 "oauth_signature=%s",
                 url,
                 param,
                 encodeURLi( digest, TRUE ) );
    else
        sprintf( request,
                 "%s&"
                 "oauth_signature=%s",
                 param,
                 encodeURLi( digest, TRUE ) );
}


bool
CJaiku::CheckOAuthResult( const char *response )
{
    bool    ret = true;
    unsigned short responseCode = getStatusCode();

    if ( (responseCode == 401) ||
         strstr(response, "maintenance") ||
         strstr(response, "{\"status\":\"error\"") ) {
        MessageBox(
            NULL,
            "OAuth �F�؂Ɏ��s�A�������͉��炩�̃G���[���������܂����B\r\n"
            "���̃G���[�������ꍇ�́u�]���̔F�؁v�̕������g�����������B  ",
            "OAuth �F�؃G���[",
            MB_OK|MB_ICONERROR );
        ret = false;
    }

    return ( ret );
}

char    *
CJaiku::CutWhiteSpaces( char *p )
{
    char    *ret = p;
    char    *q, *r;

    while ( ( q = strstr( p, "\n  " ) ) != NULL ) {
        r = q + 3;
        while ( (*r == ' ') || (*r == '\t') || (*r == '\r') || (*r == '\n') )
            r++;

        strcpy( q, r );
    }

    return ( ret );
}
