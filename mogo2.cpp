/*
 * mogo2.cpp : �������� �N���C�A���g chirrup
 *      �������� API �𗘗p���邽�߂̊e�폈���Q
 *          written by H.Tsujimura  14 Jun 2007
 *
 *      Copyright (c) 2007 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/mogo2.cpp $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 28    09/04/28 20:52 Tsujimura543
 * �^�C���A�E�g�擾�������K�莞�ԓ��ɏI���Ȃ��ꍇ�̏�����ύX
 * (�X���b�h�����I�������ł͂Ȃ��A�C�x���g�ʒm�������̗p)
 * 
 * 27    09/03/10 22:14 Tsujimura543
 * GetStringFromJSON() �Ƀo�b�t�@�I�[�o�[�����΍�����{
 * 
 * 26    08/12/04 18:19 Tsujimura543
 * �R�[�h�����A���艻��Ƃ����{
 * 
 * 25    08/09/03 19:21 Tsujimura543
 * delete [] response; ����^�C�~���O���C��
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
 * 20    07/09/27 18:35 Tsujimura543
 * �u���������v�ɑΉ�����
 * 
 * 19    07/07/23 14:57 Tsujimura543
 * GetUserFromJSON() ���̍�Ɨp�������̈�T�C�Y�𑝂₷
 * (����̂܂܂��ƃ������̈�j�󂪋N���邱�Ƃ�����̂ŁA�΍�����{)
 * 
 * 18    07/07/19 21:35 Tsujimura543
 * �^�C���X�^���v�֘A�̏����� VC++ 6 / VC++ 2005 ���ʃR�[�h�ɕύX
 * 
 * 17    07/07/05 0:50 Tsujimura543
 * (1) GetStatFromJSON(), GetUserTimeline() �̈�����ύX
 * (2) TWITTER_USER �\���̂̕ύX(orig_userName��ǉ�)�ɔ����C��
 * (3) MakeMessageForScreen() �� MakeMessageForLogging() ��p��
 * 
 * 16    07/07/03 13:46 Tsujimura543
 * Visual Studio 2005 �ł̃r���h���ʂ𔽉f
 * 
 * 15    07/06/26 16:01 Tsujimura543
 * PostUpdate() ���Ŋm�ۂ��� request �̃T�C�Y���C��
 * 
 * 14    07/06/25 21:10 Tsujimura543
 * memcpy() ���g���Ă����Ƃ�����R�s�[�R���X�g���N�^���g���悤�ɏC��
 * 
 * 13    07/06/25 18:03 Tsujimura543
 * DeleteReserved(), DeleteReserved2() �֘A�A�R�[�h�𐮗�
 * 
 * 12    07/06/22 18:06 Tsujimura543
 * SetStatFromJSON() �� fix
 * 
 * 11    07/06/21 19:15 Tsujimura543
 * SetUserAgent() �� CService ���̃��\�b�h�Ɉ�{������
 * 
 * 10    07/06/21 13:36 Tsujimura543
 * PostUpdate() ���Ŋm�ۂ��Ă��� request �̃T�C�Y������������ꍇ��
 * ���邱�Ƃ������B�T�C�Y�̌v�Z���C������
 * 
 * 9     07/06/20 20:55 Tsujimura543
 * [No.xxx] �� [ID: xxx] �ɕύX
 * 
 * 8     07/06/20 19:28 Tsujimura543
 * GetStatusID() �𓱓�
 * 
 * 7     07/06/19 23:01 Tsujimura543
 * CService �𓱓����A�\�[�X�R�[�h�𐮗�����
 * 
 * 6     07/06/19 17:39 Tsujimura543
 * GetMogo2ScreenName() �� GetScreenName() �ɕύX
 * 
 * 5     07/06/19 0:42 Tsujimura543
 * ���O�t�@�C���ɂ�������ID���L�^����悤�ɂ���
 * 
 * 4     07/06/15 21:23 Tsujimura543
 * �u���������v�̃R�����g���e�ɑΉ�
 * 
 * 3     07/06/15 19:15 Tsujimura543
 * friends_timeline �΍�A�ǉ�
 * 
 * 2     07/06/15 17:48 Tsujimura543
 * friends_timeline �̎擾���Ɏw�肷�� since �̒l�����Ԍo�߂Ƌ���
 * �ǂ�ǂ�ߋ������ɑk���Ă����Ă��܂����ۂɑΏ�
 * 
 * 1     07/06/14 23:00 Tsujimura543
 * �V�K�쐬 (����m�F�ς�)
 */

#include "chirrup.h"
#include "mogo2.h"
#include "twitterTimeline.h"
#include "http.h"
extern "C" {
#include "utility.h"
}

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/chirrup/mogo2.cpp 1     09/05/14 3:50 tsupo $";
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

CMogo2::CMogo2() : CService()
{
#ifdef  _DEBUG
    m_serviceName   = _T("mogo2");
#endif
    m_serviceSymbol = _T("Mogo2");
}

CMogo2::~CMogo2()
{
}

void CMogo2::DeleteReserved(TWITTER_STATUS *sp)
{
    if ( sp && sp->reserved ) {
    }
}

void CMogo2::DeleteReserved2(TWITTER_STATUS *sp)
{
    if ( sp && sp->reserved2 ) {
    }
}

/*
 *  �������� API
 */

// �����𓊍e
bool
CMogo2::PostUpdate( CString monologue, ProceedingDialog *pdlg )
{
    bool        ret = false;
    size_t      sz  = MAX_CONTENT_SIZE;
    size_t      len = monologue.GetLength() * 18;
    char        *request  = new char[7 + len + 1];
    char        *response = new char[sz];
    const char  *url = "http://api.mogo2.jp/statuses/update.json";
    char        *p = sjis2utf( monologue );

    if ( request && response ) {
        sprintf( request,
                 "status=%s",
                 encodeURL( p ? p : monologue ) );
        SetUserAgent();
        setUpReceiveBuffer( response, sz );
        _http_postBASIC( url, m_username, m_password,
                         request, response, NULL, pdlg );
        if ( *response ) {
            if ( strstr( response, "\"created_at\"" ) )
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
CMogo2::GetFriendsTimeline(
                CTwitterTimeline *timeline,
                ProceedingDialog *pdlg
            )
{
    return ( CService::GetFriendsTimeline(
                 "http://api.mogo2.jp/statuses/friends_timeline.json",
                 timeline,
                 pdlg ) );
}

// public_timeline ���擾
CString
CMogo2::GetPublicTimeline(
                CTwitterTimeline *timeline,
                ProceedingDialog *pdlg
            )
{
    return ( CService::GetPublicTimeline(
                 "http://api.mogo2.jp/statuses/public_timeline.json",
                 timeline,
                 pdlg ) );
}

// user_timeline ���擾
CString
CMogo2::GetUserTimeline(
                CTwitterTimeline *timeline,
                ProceedingDialog *pdlg
            )
{
    return ( CService::GetUserTimeline( 
                     "http://api.mogo2.jp/statuses/user_timeline.json",
                     timeline,
                     pdlg ) );
}

// �����̃X�N���[�����̎擾
CString CMogo2::GetScreenName()
{
    TWITTER_USER    user;
    CString         screenName = _T("");
    size_t          sz  = MAX_CONTENT_SIZE;
    char            *response = new char[sz];
    char            url[MAX_URLLENGTH];
 // bool            ret = false;

    if ( response ) {
        strcpy( url, "http://api.mogo2.jp/statuses/user_timeline.xml" );
        SetUserAgent();
        setUpReceiveBuffer( response, sz );
        _http_getBASIC( url, m_username, m_password, response, NULL, NULL );
        if ( *response ) {
            char    *p = strstr( response, "<screen_name>" );
            if ( p ) {
             // ret  = true;
                user = GetUserFromXML(response, response + strlen(response));
                screenName = user.screenName;
            }
        }

        delete [] response;
    }

    return ( screenName );
}



CString
CMogo2::GetTimeline(
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
        if ( *stat && (t != FRIENDS_TIMELINE) ) {
            /* ����: friends_timeline �̂Ƃ��� since �w�莞�̃��X�|���X��  */
            /*       �������� (�O��擾�������ōŌÂ̔����ȑO�̔������Ԃ�  */
            /*       �Ă���)���߁AFRIENDS_TIMELINE �̂Ƃ��Ɍ����ẮAsince */
            /*       �w����s�Ȃ��̂���߂邱�Ƃɂ���                      */
            CTime   time   = CTime( 2000, 1, 1, 0, 0, 0, 0 );
            CTime   recent = time;

            int i;
            for ( i = 0; i < timeline->m_numOfStats; i++ ) {
                time = (*stat)[i].createdAt;
                if ( (time - recent).GetTotalSeconds() > 0 )
                    recent = time;
            }

            recent -= 24 * 60 * 60;
            url += "?since=";
            url += encodeDateTime(recent.Format("%a, %d %b %Y %H:%M:%S GMT"));
                // Tue%2C+27+Mar+2007+22%3A55%3A48+GMT
        }

        SetUserAgent();
        setUpReceiveBuffer( response, sz );
        // ���������� public_timeline �̎擾�ɂ� BASIC �F�؂��K�v
     // if ( t != PUBLIC_TIMELINE )
            _http_getBASIC(url, m_username, m_password, response, NULL, pdlg);
     // else
     //     _http_get( url, response, pdlg );
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
                                    "CMogo2::GetTimeline()",
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

CString CMogo2::GetStatusID(
                        const char *p,
                        const char *terminator
                    )
{
    CString s = GetIdFromJSON( p, terminator );
    return ( s );
}

void CMogo2::SetStatFromJSON(
                        const char       *q,
                        const char       *s,
                        TWITTER_STATUS   *sp,
                        CString          &message
                    )
{
    sp->createdAt = GetCreatedAtFromJSON(q, s);
    strcpy( sp->id, GetIdFromJSON(q, s) );
    strcpy( sp->text,
            GetTextFromJSON( q, s, sp->orig_text ) );
    sp->user = GetUserFromJSON( q, s );

    strcpy( sp->user.lastStatus, sp->text );

    MakeMessageForScreen( message, sp );
    MakeMessageForLogging( sp );
}

TWITTER_USER
CMogo2::GetUserFromJSON(
                const char *q,
                const char *terminator
            )
{
    TWITTER_USER    u;
    char            temp[BUFSIZ * 2];
    char            temp2[BUFSIZ * 4];
    const char      *p;

    // "user"
    temp[0] = NUL;
    p = strstr( q, "\"user\"" );
    if ( p && (p < terminator) ) {
        int id;

        p += 6;
        while ( (p < terminator) && *p && (*p != ':') )
            p++;
        if ( *p == ':' ) {
            while ( (p < terminator) && *p && (*p != '{') )
                p++;

            //    "profile_image_url"
            GetStringFromJSON( temp, MAX_URLLENGTH, "\"profile_image_url\"",
                               p, terminator, true );
            strcpy( u.profileImageURL, temp );

            //    "description"
            GetStringFromJSON( temp, MAX_DESCRIPTION_LEN, "\"description\"",
                               p, terminator );
            strcpy( u.description, temp );

            //    "location"
            u.location[0] = NUL;

            //    "id"
            id = GetIntegerFromJSON( "\"id\"", p, terminator );
            sprintf( u.id, "%d", id );

            //    "screen_name"
            GetStringFromJSON( temp, MAX_KEYLENGTH, "\"screen_name\"",
                               p, terminator, false, temp2 );
            strcpy( u.screenName, temp );
            strcpy( u.name, temp );
            strcpy( u.orig_userName, temp2 );

            //    "url"
            GetStringFromJSON(temp, MAX_URLLENGTH, "\"url\"", p, terminator);
            strcpy( u.url, temp );
        }
    }

    u.lastStatus[0] = NUL;
    u.bitmap        = NUL;

    return ( u );
}


void
CMogo2::MakeMessageForScreen(
            CString        &message,
            TWITTER_STATUS *sp )
{
    message += EscapeQuote(sp->user.screenName);
    message += _T(": ");
    message += EscapeQuote(sp->text);

    message += _T(" ");
    if ( m_useTwitStar )
        message += _T("��");
    message += _T("[ID: ");
    message += sp->id;
    message += _T("]\r\n");
}

void
CMogo2::MakeMessageForLogging( TWITTER_STATUS *sp )
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
