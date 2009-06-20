/*
 * CTwitterManager.cpp : Twitter �N���C�A���g chirrup
 *       Twitter �֘A�Ǘ����戵���@�\ �C���v�������e�[�V���� �t�@�C��
 *          written by H.Tsujimura  20 Jun 2007
 *
 *      Copyright (c) 2007 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/CTwitterManager.cpp $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 15    09/05/12 17:16 Tsujimura543
 * �u�X���b�h�N�������v���e�^�C�����C���擾�������Ăяo���^�C�~���O��
 * �㏑������悤�ɕύX (�T�[�r�X���� �� �^�C�����C������ �ɕύX)
 * 
 * 14    09/04/16 16:11 Tsujimura543
 * �V�K�C���X�g�[������ OAuth �F�ؐݒ肵�����ƁA�X�N���[�����̎擾�Ɏ��s
 * ���铙�AOAuth �Ή����ɍ�肱��ł��܂����o�O���C��
 * 
 * 13    09/03/31 23:29 Tsujimura543
 * Twitter �� OAuth �Ή����� ����7
 * 
 * 12    09/03/31 21:27 Tsujimura543
 * Twitter �� OAuth �Ή����� ����5
 * 
 * 11    09/03/30 22:37 Tsujimura543
 * Twitter �� OAuth �Ή����� ����2
 * 
 * 10    08/07/16 4:13 Tsujimura543
 * �u�������e�Ώہv�̐ݒ���u�ݒ�v�_�C�A���O�ł��ݒ�ł���悤�ɂ���
 * 
 * 9     08/07/14 14:22 Tsujimura543
 * �^�C�����C���擾�����́uAPI���s�񐔐����΍�v������
 * 
 * 8     07/12/19 18:44 Tsujimura543
 * http �֘A�֐��Ăяo���܂��𐮗�
 * 
 * 7     07/08/25 0:45 Tsujimura543
 * �u�������v�ɑΉ� (�\��)
 * 
 * 6     07/08/17 22:51 Tsujimura543
 * �u�����̃X�N���[�������L���b�V������v�悤�ɂ����e���ŁAm_service ��
 * ���[�U���ƃp�X���[�h�̏��������s�Ȃ��Ȃ��܂܁A(���Ȃ��Ƃ��ŏ���
 * 1���)�������s�Ȃ��邱�Ƃ������B�ŏ���timeline�擾�̃^�C�~���O��
 * �̏�������������ꂽ
 * 
 * 5     07/08/06 17:31 Tsujimura543
 * Twitter �� API ���s�񐔐����ɒ�G����̂�h���d�g�݂𓱓�
 * 
 * 4     07/07/05 0:47 Tsujimura543
 * CChirrupDialog::ExecuteUpdate(CManager *p) �o�R�� Twitter �� Replies
 * �̎擾�������Ăяo����Ȃ��s��ɑΏ�
 * 
 * 3     07/06/22 22:51 Tsujimura543
 * m_replies.m_serviceType �̏�������ǉ�
 * 
 * 2     07/06/20 15:46 Tsujimura543
 * InitTimelineInfo() ��p�~
 * 
 * 1     07/06/20 5:17 Tsujimura543
 * �V�K�쐬 (Twitter ��p CManager)
 */

#include "chirrup.h"
#include "chirrupDlg.h"
#include "parameter.h"
#include "twitter.h"
#include "CTwitterManager.h"
#include "http.h"

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/chirrup/CTwitterManager.cpp 1     09/05/14 3:50 tsupo $";
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CTwitterManager::CTwitterManager()
    : CManager( CTwitterTimeline::SVC_TWITTER )
{
    m_twitterHealthy        = true;
    m_lastUpdated           = 0;
    m_replies.m_serviceType = CTwitterTimeline::SVC_TWITTER;
}

CTwitterManager::~CTwitterManager()
{
    m_replies.FinishLogging();
}


void CTwitterManager::SetConfig(
                            CString username,
                            CString password,
                            CString oauthToken,
                            CString oauthTokenSecret,
                            BOOL useOAuth,
                            BOOL useBASIC,
                            BOOL checkMultiPost,
                            TIMELINE_INFO sFriendsTimeline,
                            TIMELINE_INFO sPublicTimeline,
                            TIMELINE_INFO sUserTimeline,
                            TIMELINE_INFO sReplies
                        )
{
    CManager::SetConfig( username, password,
                         checkMultiPost,
                         sFriendsTimeline,
                         sPublicTimeline,
                         sUserTimeline );
    m_oauthToken       = oauthToken;
    m_oauthTokenSecret = oauthTokenSecret;
    m_useOAuth         = useOAuth ? true : false;
    m_useBASIC         = useBASIC ? true : false;
    m_sReplies         = sReplies;
}


void CTwitterManager::GetConfig(
                            CString &username,
                            CString &password,
                            CString &oauthToken,
                            CString &oauthTokenSecret,
                            BOOL &useOAuth,
                            BOOL &useBASIC,
                            BOOL &checkMultiPost,
                            TIMELINE_INFO &sFriendsTimeline,
                            TIMELINE_INFO &sPublicTimeline,
                            TIMELINE_INFO &sUserTimeline,
                            TIMELINE_INFO &sReplies
                        )
{
    CManager::GetConfig( username, password,
                         checkMultiPost,
                         sFriendsTimeline,
                         sPublicTimeline,
                         sUserTimeline );
    oauthToken       = m_oauthToken;
    oauthTokenSecret = m_oauthTokenSecret;
    useOAuth         = m_useOAuth ? TRUE : FALSE;
    useBASIC         = m_useBASIC ? TRUE : FALSE;
    sReplies         = m_sReplies;
}

void CTwitterManager::SetLogFileSpec()
{
    CManager::SetLogFileSpec();
    m_replies.SetLogFileSpec( m_sReplies );
}

void CTwitterManager::WriteKeys(
                        FILE          *fp,
                        char          *key,
                        unsigned char **secret,
                        bool          &done )
{
    CManager::WriteKeys( fp, key, secret, done );
    CManager::WriteKeys( fp, &m_sReplies, "Replies" );
}

bool CTwitterManager::EvalKeys(
                        const char          *p,
                        const unsigned char *rsaString,
                        char                *encrypted )
{
    bool    ret = CManager::EvalKeys( p, rsaString, encrypted );
    if ( ret == false )
        ret = CManager::EvalKeys( &m_sReplies, "Replies", p );

    return ( ret );
}


void CTwitterManager::ExecuteUpdate(
                    CStatic          *sp,
                    bool             useTwitStar,
                    CChirrupDlg      *cdlg,
                    ProceedingDialog *pdlg
                )
{
    if ( m_sFriendsTimeline.checkTimeline ||
         m_sPublicTimeline.checkTimeline  ||
         m_sUserTimeline.checkTimeline       ) {
        CString msg = m_serviceName;
        msg += _T(": ���擾���c�c");
        sp->SetWindowText( msg );

        CTwitterTimeline    *tp1 = NULL;
        CTwitterTimeline    *tp2 = NULL;
        CTwitterTimeline    *tp3 = NULL;
        CTwitterTimeline    *tp4 = NULL;

        if ( m_twitterHealthy ) {
            time_t  t1 = time( NULL );

            if ( m_useOAuth                          ||
                 ( (m_username.GetLength() > 0) &&
                   (m_password.GetLength() > 0)    )    ) {
                SetUpUserInfo();
                m_service->m_useTwitStar = useTwitStar;
                tp1 = GetPublicTimeline();
                tp2 = GetFriendsTimeline();
                tp3 = GetUserTimeline();
                tp4 = GetReplies();
            }

            if ( tp1 && m_sPublicTimeline.checkTimeline ) {
                cdlg->m_startTime_updateThread = CTime::GetCurrentTime();
                tp1->m_messages = m_service->GetPublicTimeline( tp1, pdlg );
            }

            int period = 0; // for API���s�񐔐����΍�
            if ( tp2 && m_sFriendsTimeline.checkTimeline )
                period++;
            if ( tp3 && m_sUserTimeline.checkTimeline )
                period++;
            if ( tp4 && m_sReplies.checkTimeline )
                period++;
            period *= 60;

         // if ( t1 >= m_lastUpdated + period ) {
                if ( tp2 && m_sFriendsTimeline.checkTimeline ) {
                    cdlg->m_startTime_updateThread = CTime::GetCurrentTime();
                    if ( (tp1 && m_sPublicTimeline.checkTimeline) )
                        Sleep( 1000 );
                    tp2->m_messages =
                                m_service->GetFriendsTimeline( tp2, pdlg );
                }

                if ( tp3 && m_sUserTimeline.checkTimeline ) {
                    cdlg->m_startTime_updateThread = CTime::GetCurrentTime();
                    if ( (tp1 && m_sPublicTimeline.checkTimeline)  ||
                         (tp2 && m_sFriendsTimeline.checkTimeline)    )
                        Sleep( 1000 );
                    tp3->m_messages = m_service->GetUserTimeline( tp3, pdlg );
                }

                if ( tp4 && m_sReplies.checkTimeline ) {
                    cdlg->m_startTime_updateThread = CTime::GetCurrentTime();
                    if ( (tp1 && m_sPublicTimeline.checkTimeline)  ||
                         (tp2 && m_sFriendsTimeline.checkTimeline) ||
                         (tp3 && m_sUserTimeline.checkTimeline)       )
                        Sleep( 1000 );
                    tp4->m_messages =
                            ((CTwitter *)m_service)->GetReplies( tp4, pdlg );
                }
         // }

            time_t  t2 = time( NULL );
            m_twitterHealthy = (t2 - t1 >= 2 * 60) ? false : true;
            m_lastUpdated    = t2;
        }
        else {
            size_t  sz = BUFSIZ * 4;
            char    response[BUFSIZ * 4];

            setUpReceiveBuffer( response, sz );
            _http_get( "http://twitter.com/", response, pdlg );
            if ( *response )
                m_twitterHealthy = true;
        }
    }
}
