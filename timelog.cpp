/*
 * timelog.cpp : Timelog �N���C�A���g chirrup
 *      Timelog API �𗘗p���邽�߂̊e�폈���Q
 *          written by H.Tsujimura  20 Jun 2007
 *
 *      Copyright (c) 2007 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/timelog.cpp $
 * 
 * 2     09/06/18 1:33 tsupo
 * 2.01��
 * 
 * 32    09/06/11 10:28 Tsujimura543
 * Timelog ���e���̃��X�|���X���󕶎���ɕύX���ꂽ�̂ɔ����C��
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 31    09/04/28 20:52 Tsujimura543
 * �^�C���A�E�g�擾�������K�莞�ԓ��ɏI���Ȃ��ꍇ�̏�����ύX
 * (�X���b�h�����I�������ł͂Ȃ��A�C�x���g�ʒm�������̗p)
 * 
 * 30    09/03/10 22:14 Tsujimura543
 * GetStringFromJSON() �Ƀo�b�t�@�I�[�o�[�����΍�����{
 * 
 * 29    08/12/04 18:19 Tsujimura543
 * �R�[�h�����A���艻��Ƃ����{
 * 
 * 28    08/11/17 16:31 Tsujimura543
 *  Visual Studio 2008 �ł̃r���h���ʂ𔽉f
 * 
 * 27    08/09/03 19:21 Tsujimura543
 * delete [] response; ����^�C�~���O���C��
 * 
 * 26    08/08/20 19:18 Tsujimura543
 * �������Ɋ܂܂�� URL �Ɣ����{���̊Ԃɋ󔒕�����}������悤�ɂ���
 * 
 * 25    08/07/16 15:27 Tsujimura543
 * Timelog �́u�]���v�ɑΉ�����
 * 
 * 24    07/12/19 18:44 Tsujimura543
 * http �֘A�֐��Ăяo���܂��𐮗�
 * 
 * 23    07/12/19 17:17 Tsujimura543
 * _http_postBASIC() �̈�����ǉ�
 * 
 * 22    07/12/19 16:56 Tsujimura543
 * _http_getBASIC() �̈�����ǉ�
 * 
 * 21    07/12/14 16:03 Tsujimura543
 * http_getBASIC() �� _http_getBASIC() �ɒu��
 * 
 * 20    07/08/16 19:53 Tsujimura543
 * Timelog �́u�����v�� permalink �֔�ׂ�悤�ɂ��� ([link] ���N���b�N)
 * 
 * 19    07/07/19 21:35 Tsujimura543
 * �^�C���X�^���v�֘A�̏����� VC++ 6 / VC++ 2005 ���ʃR�[�h�ɕύX
 * 
 * 18    07/07/05 0:50 Tsujimura543
 * (1) GetStatFromJSON(), GetUserTimeline() �̈�����ύX
 * (2) TWITTER_USER �\���̂̕ύX(orig_userName��ǉ�)�ɔ����C��
 * (3) MakeMessageForScreen() �� MakeMessageForLogging() ��p��
 * 
 * 17    07/07/03 13:46 Tsujimura543
 * Visual Studio 2005 �ł̃r���h���ʂ𔽉f
 * 
 * 16    07/06/26 16:01 Tsujimura543
 * PostUpdate() ���Ŋm�ۂ��� request �̃T�C�Y���C��
 * 
 * 15    07/06/25 23:12 Tsujimura543
 * reserve, reserve2 �܂����C��
 * 
 * 14    07/06/25 19:18 Tsujimura543
 * ~CTimelog() ���C��
 * 
 * 13    07/06/25 18:47 Tsujimura543
 * tag ��\������悤�ɂ��Ă݂�
 * 
 * 12    07/06/22 20:44 Tsujimura543
 * SetStatFromJSON() ���C��
 * 
 * 11    07/06/22 18:43 Tsujimura543
 * ���[�U��(�X�N���[����)�ɃV���[�v�G���R�[�h���ꂽ�������܂܂��ꍇ
 * �̓f�R�[�h����悤�ɂ���
 * 
 * 10    07/06/22 18:02 Tsujimura543
 * SetStatFromJSON() �� fix
 * 
 * 9     07/06/22 18:00 Tsujimura543
 * �u�����v�{�������Ɂu> �R�����g�惆�[�U���v��t������悤�ɂ���
 * 
 * 8     07/06/21 22:05 Tsujimura543
 * �_�C���N�g���b�Z�[�W�̑���M���������� (�폜�͖�����)
 * 
 * 7     07/06/21 19:15 Tsujimura543
 * SetUserAgent() �� CService ���̃��\�b�h�Ɉ�{������
 * 
 * 6     07/06/21 18:16 Tsujimura543
 * status ID �i�[�̈�Ń������I�[�o�[��������������\����
 * ���邱�Ƃ������������߁A�΍�����{
 * 
 * 5     07/06/21 13:43 Tsujimura543
 * ���O�ɍڂ��郁�b�Z�[�WID�̖����� @���[�UID ��t������
 * (���X�|���X���e���Ɏg�p����)
 * 
 * 4     07/06/20 20:55 Tsujimura543
 * [RID: .xxx] �� [ID: xxx] �ɕύX
 * 
 * 3     07/06/20 19:28 Tsujimura543
 * GetStatusID() �𓱓�
 * 
 * 2     07/06/20 17:05 Tsujimura543
 * timeline �̎擾�� status �̓��e�Ɋւ��āA���삷�邱�Ƃ��m�F
 * 
 * 1     07/06/20 14:06 Tsujimura543
 * �V�K�쐬 (�b���)
 */

#include "chirrup.h"
#include "twitter.h"
#include "twitterTimeline.h"
#include "timelog.h"
#include "http.h"
extern "C" {
#include "utility.h"
}

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/chirrup/timelog.cpp 2     09/06/18 1:33 tsupo $";
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

CTimelog::CTimelog() : CService()
{
    m_numOfMessages = 0;
    m_dm            = NULL;

#ifdef  _DEBUG
    m_serviceName   = _T("timelog");
#endif
    m_serviceSymbol = _T("Timelog");
}

CTimelog::~CTimelog()
{
    if ( m_log ) {
        delete [] m_log;
        m_log = NULL;
    }

    int i;
    if ( m_stat ) {
        for ( i = m_numOfStats; i > 0; i-- ) {
            DeleteReserved( &(m_stat[i - 1]) );
            DeleteReserved2( &(m_stat[i - 1]) );
        }
        delete [] m_stat;
        m_stat = NULL;
    }
    if ( m_stat2 ) {
        for ( i = m_numOfStats2; i > 0; i-- ) {
            DeleteReserved( &(m_stat2[i - 1]) );
            DeleteReserved2( &(m_stat2[i - 1]) );
        }
        delete [] m_stat2;
        m_stat2 = NULL;
    }
    if ( m_stat3 ) {
        for ( i = m_numOfStats3; i > 0; i-- ) {
            DeleteReserved( &(m_stat3[i - 1]) );
            DeleteReserved2( &(m_stat3[i - 1]) );
        }
        delete [] m_stat3;
        m_stat3 = NULL;
    }
}

void CTimelog::DeleteReserved( TWITTER_STATUS *sp )
{
    if ( sp && sp->reserved ) {
        TWITTER_USER *u;
        u = (TWITTER_USER *)(sp->reserved);
        delete u;
        sp->reserved = NULL;
    }
}

void CTimelog::DeleteReserved2( TWITTER_STATUS *sp )
{
    if ( sp && sp->reserved2 ) {
        TIMELOG_TAGS *t;
        t = (TIMELOG_TAGS *)(sp->reserved2);
        delete t;
        sp->reserved2 = NULL;
    }
}

/*
 *  Timelog API
 */

// �����𓊍e
bool
CTimelog::PostUpdate( CString monologue, ProceedingDialog *pdlg )
{
    bool        ret = false;
    size_t      sz  = MAX_CONTENT_SIZE;
    size_t      len = monologue.GetLength() * 18;
    char        *request  = new char[14 + MAX_KEYLENGTH + len + 1];
    char        *response = new char[sz];
    const char  *url = "http://api.timelog.jp/new.asp";
    char        rid[MAX_KEYLENGTH];

    rid[0] = NUL;
    if ( !strncmp( monologue, ">>", 2 ) ) {
        strncpy( rid, ((const char *)monologue) + 2, MAX_KEYLENGTH - 2 );
        rid[MAX_KEYLENGTH - 2] = NUL;

        char    *p = strchr( rid, ' ' );
        if ( p ) {
            *p = NUL;
            monologue = strchr( monologue, ' ' ) + 1;
        }
    }

    char    *p = sjis2utf( monologue );
    if ( request && response ) {
        sprintf( request,
                 "text=%s",
                 encodeURL( p ? p : monologue ) );
        if ( rid[0] )
            sprintf( request + strlen(request),
                     "&remsgid=%s",
                     rid );
        SetUserAgent();
        setUpReceiveBuffer( response, sz );
        _http_postBASIC( url, m_username, m_password,
                         request, response, NULL, pdlg );
        if ( *response ) {
            if ( strstr( response, "OK" ) )
                ret = true;
        }
        else {
            unsigned short status = getStatusCode();
            if ( status / 100 == 2 )    // 200 OK (�` 299) �Ȃ琬���Ƃ݂Ȃ�
                ret = true; /* ���e���� */
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
CTimelog::GetFriendsTimeline(
                CTwitterTimeline *timeline,
                ProceedingDialog *pdlg
            )
{
    return ( CService::GetFriendsTimeline(
                            "http://api.timelog.jp/friends_msg.asp",
                            timeline,
                            pdlg ) );
}

// public_timeline ���擾
CString
CTimelog::GetPublicTimeline(
                CTwitterTimeline *timeline,
                ProceedingDialog *pdlg
            )
{
    return ( CService::GetPublicTimeline(
                            "http://api.timelog.jp/public_msg.asp",
                            timeline,
                            pdlg ) );
}

// user_timeline ���擾
CString
CTimelog::GetUserTimeline(
                CTwitterTimeline *timeline,
                ProceedingDialog *pdlg
            )
{
    return ( CService::GetUserTimeline( 
                            "http://api.timelog.jp/my_msg.asp",
                            timeline,
                            pdlg ) );
}

// �w�� status �� favorites �ɂ��� (�u�]���v������)
bool CTimelog::SetFavorite( const char *statusID )
{
    size_t  sz  = MAX_CONTENT_SIZE;
    char    *request  = new char[MAX_KEYLENGTH + 1];
    char    *response = new char[sz];
    char    url[MAX_URLLENGTH];
    bool    ret = false;
    char    id[MAX_KEYLENGTH + 1];
    char    ac[MAX_USERIDLEN + 1];

    if ( request && response ) {
        const char	*p = strchr( statusID, '@' );
        if ( p ) {
            strncpy( id, statusID, p - statusID );
            id[p - statusID] = NUL;
            strcpy( ac, p + 1 );

            sprintf( request,
                     "id=%s&"
                     "ac=%s",
                     id, ac );
        }
        else
            sprintf( request,
                     "id=%s",
                     statusID );
        strcpy( url, "http://timelog.jp/addstar.asp" );
        SetUserAgent();
        setUpReceiveBuffer( response, sz );
        _http_postBASIC( url, m_username, m_password,
                         request, response, NULL, NULL );
        if ( *response ) {
            char    *p = strstr( response, "timelog" );
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
CString CTimelog::GetScreenName()
{
    TWITTER_USER    user;
    CString         screenName = _T("");
    size_t          sz  = MAX_CONTENT_SIZE;
    char            *response = new char[sz];
    char            url[MAX_URLLENGTH];
 // bool            ret = false;

    if ( response ) {
        strcpy( url, "http://api.timelog.jp/show.asp?fmt=json" );
        SetUserAgent();
        setUpReceiveBuffer( response, sz );
        _http_getBASIC( url, m_username, m_password, response, NULL, NULL );
        if ( *response ) {
            /*
             * JSON �̏ꍇ�A�ȉ��̂悤�ȃt�H�[�}�b�g�Ń��X�|���X���Ԃ�
             *   {"timelog":[
             *   {"id":"���[�U��",
             *   "name":"�X�N���[����",
             *   "url":"Timelog �̃��[�U�y�[�W URL",
             *   "image":"���[�U�A�C�R��(��)URL",
             *   "prof_url":"�u���O����URL",
             *   "prof_msg":"���ȏЉ�",
             *   "tags":"�^�O"
             *   }
             *   ]
             */
            char    *p = strstr( response, "\"timelog\"" );
            if ( p ) {
             // ret  = true;
                user = GetUserFromJSON( response,
                                        response + strlen( response ) );
                screenName = user.screenName;
            }
        }

        delete [] response;
    }

    return ( screenName );
}

// �_�C���N�g���b�Z�[�W����M
TWITTER_DIRECT_MESSAGE  *
CTimelog::RecvDirectMessages( int              &numOfMessages,
                              ProceedingDialog *pdlg )
{
    char    url[MAX_URLLENGTH];
    size_t  sz  = MAX_CONTENT_SIZE * MAX_NUM_OF_DIRECTMESSAGES;
    char    *response = new char[sz];
 // bool    failure   = true;

    m_numOfMessages = 0;
    sprintf( url,
             "http://api.timelog.jp/direct_msg.asp?cnt=%d",
             MAX_NUM_OF_DIRECTMESSAGES );

    if ( !m_dm || !response ) {
        numOfMessages = m_numOfMessages;
        return ( NULL );
    }

    SetUserAgent();
    setUpReceiveBuffer( response, sz );
    _http_getBASIC( url, m_username, m_password, response, NULL, pdlg );
    if ( *response ) {
        if ( strstr( response, "<author>" ) ) {
            char        *p, *q, *r;
            char        *s, *t;
            CString     temp;
            struct tm   ttmm;

         // failure = false;
            p = response;
            while ( *p ) {
                q = strstr( p, "<entry>" );
                if ( !q )
                    break;
                p = q + 7;
                r = strstr( p, "</entry>" );
                if ( !r )
                    break;

                // id
                temp = GetStringFromXML( p, "id", r );
                strcpy( m_dm[m_numOfMessages].id, temp );

                // memo
                temp = GetStringFromXML( p, "memo", r );
                strcpy( m_dm[m_numOfMessages].text, temp );

                // author
                s = strstr( p, "<author>" );
                if ( s && (s < r) ) {
                    s += 8;
                    t = strstr( s, "</author>" );
                    if ( t && (t < r) ) {
                        // id
                        temp = GetStringFromXML( s, "id", t );
                        strcpy( m_dm[m_numOfMessages].sender.id, temp );

                        // name
                        temp = GetStringFromXML( s, "name", t );
                        strcpy(m_dm[m_numOfMessages].sender.screenName, temp);
                    }
                }

                // toid
                temp = GetStringFromXML( p, "toid", r );
                strcpy( m_dm[m_numOfMessages].recipient.id, temp );

                // toname
                temp = GetStringFromXML( p, "toname", r );
                strcpy( m_dm[m_numOfMessages].recipient.screenName, temp );

                // created_at
                m_dm[m_numOfMessages].createdAt =
                        CTime(
                          timelocal(
                            GetTimeFromXML(p, "modified").GetLocalTm(&ttmm)));
                // deleted
                m_dm[m_numOfMessages].deleted = false;

                m_numOfMessages++;
                if ( m_numOfMessages >= MAX_NUM_OF_DIRECTMESSAGES )
                    break;
            }
        }
    }
    delete [] response;

    numOfMessages = m_numOfMessages;

    return ( m_dm );
}

// �_�C���N�g���b�Z�[�W�𑗐M
bool
CTimelog::SendDirectMessage( CString userID,
                             CString message )
{
    bool    ret = false;
    CString monologue = _T("/D @");
    monologue += userID;
    monologue += _T(" ");
    monologue += message;

    ret = PostUpdate( monologue, NULL );
    return ( ret );
}

// �_�C���N�g���b�Z�[�W���폜
#pragma warning ( disable: 4100 )
bool
CTimelog::DeleteDirectMessage( const char *messageID )
{
    return ( false );
}
#pragma warning ( default: 4100 )

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
 * Timelog �̃��X�|���X�̃t�H�[�}�b�g (JSON �̏ꍇ)
 *  {"timelog":[
 *  {
 *  "id":"���[�U��",
 *  "name":"�X�N���[����",
 *  "msg":"�X�e�[�^�X",
 *  "toid":"",
 *  "toname":"",
 *  "tododate":" ",
 *  "msgid":"�X�e�[�^�XID",
 *  "replyid":"",
 *  "url":"�X�e�[�^�XURL",
 *  "tag":"�^�O",
 *  "date":"�^�C���X�^���v(���{����)",
 *  "imagen":"���[�U�A�C�R��(��)URL",
 *  "imagem":"���[�U�A�C�R��(��)URL",
 *  "images":"���[�U�A�C�R��(��)URL"
 *  }
 *  ,
 *   ......
 *  ]}
 */

CString
CTimelog::GetTimeline(
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
        url += _T("?cnt=50&fmt=json");

        SetUserAgent();
        setUpReceiveBuffer( response, sz );
        if ( t != PUBLIC_TIMELINE )
            _http_getBASIC( url, m_username, m_password, response, NULL, pdlg );
        else
            _http_get( url, response, pdlg );
        if ( response[0] ) {
            char    *p = strchr( response, '[' );
            GetStatFromJSON( p ? p : response, stat, numOfStats );
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
                                    "CTimelog::GetTimeline()",
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

CString CTimelog::GetStatusID(
                        const char *p,
                        const char *terminator
                    )
{
    return ( GetIdFromJSON( p, terminator ) );
}

void CTimelog::SetStatFromJSON(
                        const char       *p,
                        const char       *s,
                        TWITTER_STATUS   *sp,
                        CString          &message
                    )
{
    TWITTER_USER    *u;
    TIMELOG_TAGS    *tag;

    sp->createdAt = GetCreatedAtFromJSON(p, s);
    strcpy( sp->id, GetIdFromJSON(p, s) );

    strcpy( sp->text,
            GetTextFromJSON( p, s, sp->orig_text ) );

    char    *pp;
    char    *qq;
    pp = strstr( sp->text, "http://" );
    if ( !pp )
        pp = strstr( sp->text, "https://" );
    if ( pp ) {
        qq = pp + strlen(pp);
        while ( qq >= pp ) {
            *(qq + 1) = *qq;
            qq--;
        }

        *pp = ' ';
    }

    sp->user = GetUserFromJSON( p, s );

    u = GetRecipientUserFromJSON( p, s );
    sp->reserved = (void *)u;

    tag = GetTagsFromJSON( p, s );
    sp->reserved2 = (void *)tag;

    strcpy( sp->user.lastStatus, sp->text );

    MakeMessageForScreen( message, sp );
    MakeMessageForLogging( sp );
}


CTime
CTimelog::GetCreatedAtFromJSON( const char *q, const char *terminator )
{
    CTime   t;
    bool    done = false;
    char    temp[MAX_DATELENGTH];

    // "date"
    GetStringFromJSON( temp, MAX_DATELENGTH, "\"date\"", q, terminator );
    if ( temp[0] ) {
        int yyyy, mm, dd, HH, MM, SS;

        getDateTimeFromDateString( temp,
                                   &yyyy, &mm, &dd,
                                   &HH,   &MM, &SS );
        t = CTime( yyyy, mm, dd, HH, MM, SS, 0 );
        done = true;
    }

    if ( !done )
        t = CTime::GetCurrentTime();

    return ( t );
}

CString
CTimelog::GetIdFromJSON( const char *p, const char *terminator )
{
    char    msgid[MAX_KEYLENGTH * 2 + 2];
    CString id;

    // "msgid"
    msgid[0] = NUL;
    GetStringFromJSON( msgid, MAX_KEYLENGTH * 2 + 2, "\"msgid\"",
                       p, terminator );
    id = msgid;

    return ( id );
}

TWITTER_USER
CTimelog::GetUserFromJSON(
                const char *p,
                const char *terminator
            )
{
    TWITTER_USER    u;
    char            temp[BUFSIZ];
    char            temp2[BUFSIZ];

    //    "name"
    strcpy( u.id,
            GetUserLoginIdFromJSON( p, terminator ) );
    strcpy( u.name, u.id );

    //    "profile_image_url"
    u.profileImageURL[0] = NUL;
    GetStringFromJSON( u.profileImageURL, MAX_URLLENGTH, "\"imagem\"",
                       p, terminator );
    if ( u.profileImageURL[0] == NUL )
        sprintf( u.profileImageURL,
                 "http://timelog.jp/images/user/%s_m.jpg",
                 u.id );

    //    "description"
    u.description[0] = NUL;
    temp[0]          = NUL;
    GetStringFromJSON( temp, MAX_DESCRIPTION_LEN, "\"prof_msg\"",
                       p, terminator );
    if ( temp[0] )
        strcpy( u.description, temp );

    //    "location"
    u.location[0] = NUL;

    //    "screen_name"
    GetStringFromJSON( temp, MAX_KEYLENGTH, "\"name\"", p, terminator,
                       false, temp2 );
    strcpy( u.screenName, temp );
    strcpy( u.orig_userName, temp2 );
    if ( strchr( u.screenName, '&' ) ) {
        strcpy( u.screenName,
                decodeNumericReference( decodeString( u.screenName ) ) );
        strcpy( u.orig_userName,
                decodeNumericReference( decodeString( u.orig_userName ) ) );
    }

    //    "url"
    sprintf( u.url, "http://timelog.jp/?%s", u.id );

    u.lastStatus[0] = NUL;
    u.bitmap        = NUL;

    return ( u );
}

TWITTER_USER    *
CTimelog::GetRecipientUserFromJSON(
                const char *p,
                const char *terminator
            )
{
    TWITTER_USER    *u = NULL;
    char            temp[BUFSIZ];
    char            temp2[BUFSIZ];

    //    "toid"
    GetStringFromJSON( temp, MAX_KEYLENGTH, "\"toid\"", p, terminator );
    if ( temp[0] == NUL )
        return ( u );

    u = new TWITTER_USER;
    if ( !u )
        return ( u );

    strcpy( u->id, temp );

    //    "toname"
    GetStringFromJSON( u->name, MAX_KEYLENGTH, "\"toname\"", p, terminator,
                       false, temp2 );
    if ( strchr( u->name, '&' ) ) {
        strcpy( u->name, decodeNumericReference( decodeString( u->name ) ) );
        strcpy( temp2,
                decodeNumericReference( decodeString( temp2 ) ) );
    }
    strcpy( u->orig_userName, temp2 );

    //    "profile_image_url"
    sprintf( u->profileImageURL,
             "http://timelog.jp/images/user/%s_m.jpg",
             u->id );

    //    "description"
    u->description[0] = NUL;

    //    "location"
    u->location[0] = NUL;

    //    "screen_name"
    strcpy( u->screenName, u->name );

    //    "url"
    sprintf( u->url, "http://timelog.jp/?%s", u->id );

    u->lastStatus[0] = NUL;
    u->bitmap        = NUL;

    return ( u );
}

TIMELOG_TAGS    *
CTimelog::GetTagsFromJSON(
                 const char *p,
                 const char *terminator
             )
{
    TIMELOG_TAGS    *tag = NULL;
    char            temp[BUFSIZ * 16];
    char            temp2[BUFSIZ * 16 * 2];

    // "tag"
    GetStringFromJSON( temp, MAX_LOGICALLINELEN * 2, "\"tag\"", p, terminator,
                       false, temp2 );
    if ( temp[0] ) {
        if ( strchr( temp, '&' ) ) {
            strcpy( temp, decodeNumericReference( decodeString( temp ) ) );
            strcpy( temp2,
                    decodeNumericReference( decodeString( temp2 ) ) );
        }

        int len = strlen( temp );
        if ( temp[len - 1] == ',' )
            temp[len - 1] = NUL;

        len = strlen( temp2 );
        if ( temp2[len - 1] == ',' )
            temp2[len - 1] = NUL;

        tag = new TIMELOG_TAGS;
        strcpy( tag->tag, temp );
        strcpy( tag->orig_tag, temp2 );
    }

    return ( tag );
}

char            *
CTimelog::GetUserLoginIdFromJSON(
                const char *p,
                const char *terminator
            )
{
    Thread static char  temp[BUFSIZ * 16];

    // "id"
    GetStringFromJSON( temp, BUFSIZ * 16, "\"id\"", p, terminator );

    return ( temp );
}

char            *
CTimelog::GetTextFromJSON(
                const char *q,
                const char *terminator,
                char       *origString /* = NULL */
            )
{
    Thread static char  temp[BUFSIZ * 16];

    // "msg"
    GetStringFromJSON( temp, BUFSIZ * 16, "\"msg\"", q, terminator,
                       false, origString );

    // tinyurl ������ URL �ɓW�J
    ExpandTinyURL( temp );
    if ( origString && origString[0] ) {
        ExpandTinyURL( origString );
        if ( strchr( origString, '&' ) )
            strcpy( origString,
                    decodeNumericReference( decodeString( origString ) ) );
    }

    return ( strchr( temp, '&' )
                ? decodeNumericReference( decodeString( temp ) )
                : temp );
}


void
CTimelog::MakeMessageForScreen(
            CString        &message,
            TWITTER_STATUS *sp )
{
    TWITTER_USER    *u;
    TIMELOG_TAGS    *tag;

    u   = (TWITTER_USER *)(sp->reserved);
    tag = (TIMELOG_TAGS *)(sp->reserved2);

    message += sp->user.screenName;
    message += _T(": ");
    message += EscapeQuote(sp->text);

    if ( u ) {
        message += _T(" > ");
        message += u->screenName;
    }
    if ( tag ) {
        message += _T(" [tag:");
        message += tag->tag;
        message += _T("]");
    }

    message += _T(" ��");
    message += _T(" [link][ID: ");
    message += sp->id;
    message += _T("@");
    message += sp->user.id;
    message += _T("]\r\n");
}

void
CTimelog::MakeMessageForLogging( TWITTER_STATUS *sp )
{
    TWITTER_USER    *u;
    TIMELOG_TAGS    *tag;

    if ( !m_log )
        m_log = new TWITTER_LOG[MAX_NUMOFSTATUS + 1];

    if ( m_log && (m_numOfLogs < MAX_NUMOFSTATUS) ) {
        sprintf( m_log[m_numOfLogs].orig_text,
                 "%s",
                 sp->orig_text );

        u   = (TWITTER_USER *)(sp->reserved);
        tag = (TIMELOG_TAGS *)(sp->reserved2);

        if ( u )
            sprintf( m_log[m_numOfLogs].orig_text +
                        strlen(m_log[m_numOfLogs].orig_text),
                     " > %s",
                     u->orig_userName );
        if ( tag )
            sprintf( m_log[m_numOfLogs].orig_text +
                        strlen(m_log[m_numOfLogs].orig_text),
                     " [tag: %s]",
                     tag->orig_tag );

        sprintf( m_log[m_numOfLogs].orig_text +
                        strlen(m_log[m_numOfLogs].orig_text),
                 " [ID: %s]",
                 sp->id );
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
