/*
 * CManager.cpp : Twitter �N���C�A���g chirrup
 *       �e�T�[�r�X���̊e��Ǘ����戵���@�\ �C���v�������e�[�V���� �t�@�C��
 *          written by H.Tsujimura  19 Jun 2007
 *
 *      Copyright (c) 2007 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/CManager.cpp $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 28    09/05/12 17:16 Tsujimura543
 * �u�X���b�h�N�������v���e�^�C�����C���擾�������Ăяo���^�C�~���O��
 * �㏑������悤�ɕύX (�T�[�r�X���� �� �^�C�����C������ �ɕύX)
 * 
 * 27    09/04/16 16:11 Tsujimura543
 * �V�K�C���X�g�[������ OAuth �F�ؐݒ肵�����ƁA�X�N���[�����̎擾�Ɏ��s
 * ���铙�AOAuth �Ή����ɍ�肱��ł��܂����o�O���C��
 * 
 * 26    09/04/16 1:33 Tsujimura543
 * Jaiku �� OAuth �ɂ��Ή�����
 * 
 * 25    09/03/31 23:29 Tsujimura543
 * Twitter �� OAuth �Ή����� ����7
 * 
 * 24    09/03/31 21:39 Tsujimura543
 * Twitter �� OAuth �Ή����� ����6
 * 
 * 23    09/03/31 21:27 Tsujimura543
 * Twitter �� OAuth �Ή����� ����5
 * 
 * 22    09/03/30 22:19 Tsujimura543
 * Twitter �� OAuth �Ή�����
 * 
 * 21    08/12/04 18:19 Tsujimura543
 * �R�[�h�����A���艻��Ƃ����{
 * 
 * 20    08/08/22 18:42 Tsujimura543
 * �u�͂Ăȃn�C�N�v�Ή�
 * 
 * 19    08/07/31 18:34 Tsujimura543
 * �u�`�����l���v�ɑΉ�
 * 
 * 18    08/07/16 4:13 Tsujimura543
 * �u�������e�Ώہv�̐ݒ���u�ݒ�v�_�C�A���O�ł��ݒ�ł���悤�ɂ���
 * 
 * 17    07/08/30 18:07 Tsujimura543
 * �R�����g�𐮗�
 * 
 * 16    07/08/30 18:04 Tsujimura543
 * �u�����̃X�N���[�������L���b�V������v�悤�ɂ����̂Ɓu���p���Ă��Ȃ�
 * �T�[�r�X�̃������m�ۂ���߂�v�悤�ɂ����e���ŁAJaiku �� m_apiKey ��
 * ���������s�Ȃ��Ȃ��܂܁A(���Ȃ��Ƃ��ŏ���1���)�������s�Ȃ��邱��
 * �������B�ŏ���timeline�擾�̃^�C�~���O�Ŗ����I�ɏ���������悤�ɂ���
 * 
 * 15    07/08/28 1:56 Tsujimura543
 * �������e�Ώۂɂ���T�[�r�X��I���ł���悤�ɂ���
 * 
 * 14    07/08/25 0:45 Tsujimura543
 * �u�������v�ɑΉ� (�\��)
 * 
 * 13    07/08/17 23:01 Tsujimura543
 * SetConfig() ���C���B���[�U�����p�X���[�h���ύX���Ă��Ȃ��ꍇ��
 * GetScreenName() ���Ă΂Ȃ��悤�ɂ��� (�ĂԕK�v���Ȃ�)
 * 
 * 12    07/08/09 14:23 Tsujimura543
 * �����̃X�N���[�������L���b�V������悤�ɂ���
 * 
 * 11    07/07/05 2:15 Tsujimura543
 * friends_timeline �̃��O�t�@�C���������ݒ�̏ꍇ�A���� timeline �̃��O
 * �t�@�C�����̐ݒ肪�ۑ�����Ȃ��s��ɑΏ�
 * 
 * 10    07/07/05 0:38 Tsujimura543
 * ExecuteUpdate() ��2�����ł̕�������
 * 
 * 9     07/06/27 18:13 Tsujimura543
 * haru.fm �ɑΉ�
 * 
 * 8     07/06/25 19:13 Tsujimura543
 * ~CManager() ���C���A�e�T�[�r�X���̃f�X�g���N�^�𖾎��I��
 * �Ăяo���悤�ɂ���
 * 
 * 7     07/06/22 22:49 Tsujimura543
 * �R���X�g���N�^���C���AserviceType �̒l�������鏈���������Ă���
 * 
 * 6     07/06/20 15:46 Tsujimura543
 * InitTimelineInfo() ��p�~
 * 
 * 5     07/06/20 14:07 Tsujimura543
 * Timelog �Ή���
 * 
 * 4     07/06/20 5:16 Tsujimura543
 * CheckKeys() �Ɉ�����ǉ�
 * 
 * 3     07/06/20 3:16 Tsujimura543
 * �ݒ�t�@�C���̓ǂݏ��������� chirrupDlg ���� CManager ��
 * CJaikuManager �Ɉڂ���
 * 
 * 2     07/06/20 1:55 Tsujimura543
 * Jaiku ��p������ CJaikuManager �֕���
 * 
 * 1     07/06/19 21:16 Tsujimura543
 * ���܂� CChirrupDlg ���ł���Ă����e�T�[�r�X���Ǘ��A���䂷�鏈����
 * ���o�� CManager �Ƃ��ēƗ�������
 */

#include "chirrup.h"
#include "chirrupDlg.h"
#include "parameter.h"
#include "twitter.h"
#include "jaiku.h"
#include "wassr.h"
#include "mogo2.h"
#include "timelog.h"
#include "haruFm.h"
#include "hatenaHaiku.h"

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/chirrup/CManager.cpp 1     09/05/14 3:50 tsupo $";
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CManager::CManager()
{
    m_serviceName      = _T("");
    m_screenName       = _T("");
    m_username         = _T("");
    m_password         = _T("");
    m_oauthToken       = _T("");
    m_oauthTokenSecret = _T("");
    m_service          = NULL;
    m_useOAuth         = false;
    m_useBASIC         = false;
    m_simultaneousPost = false;
}

CManager::CManager( CTwitterTimeline::SVC_TYPE serviceType )
{
    m_serviceName      = _T("");
    m_screenName       = _T("");
    m_username         = _T("");
    m_password         = _T("");
    m_oauthToken       = _T("");
    m_oauthTokenSecret = _T("");
    m_useOAuth         = false;
    m_useBASIC         = false;
    m_service          = NULL;

    switch ( serviceType ) {
    case CTwitterTimeline::SVC_TWITTER:
        m_serviceName   = _T("Twitter");
        m_serviceSymbol = _T("Twitter");
        m_service       = new CTwitter;
        break;

    case CTwitterTimeline::SVC_JAIKU:
        m_serviceName   = _T("Jaiku");
        m_serviceSymbol = _T("Jaiku");
        m_service       = new CJaiku;
        break;

    case CTwitterTimeline::SVC_WASSR:
        m_serviceName   = _T("Wassr");
        m_serviceSymbol = _T("Wassr");
        m_service       = new CWassr;
        break;

    case CTwitterTimeline::SVC_MOGO2:
        m_serviceName   = _T("��������");
        m_serviceSymbol = _T("Mogo2");
        m_service       = new CMogo2;
        break;

    case CTwitterTimeline::SVC_TIMELOG:
        m_serviceName   = _T("Timelog");
        m_serviceSymbol = _T("Timelog");
        m_service       = new CTimelog;
        break;

    case CTwitterTimeline::SVC_HARUFM:
        m_serviceName   = _T("Haru.fm");
        m_serviceSymbol = _T("HaruFm");
        m_service       = new CHaruFm;
        break;

    case CTwitterTimeline::SVC_HATENAHAIKU:
        m_serviceName   = _T("�͂Ăȃn�C�N");
        m_serviceSymbol = _T("HatenaHaiku");
        m_service       = new CHatenaHaiku;
        break;
    }

    m_simultaneousPost              = false;
    m_friendsTimeline.m_serviceType = serviceType;
    m_userTimeline.m_serviceType    = serviceType;
    m_publicTimeline.m_serviceType  = serviceType;
}


CManager::~CManager()
{
    m_friendsTimeline.FinishLogging();
    m_publicTimeline.FinishLogging();
    m_userTimeline.FinishLogging();

    if ( m_service ) {
        if ( !m_serviceSymbol.Compare("Twitter") ) {
            CTwitter    *p = (CTwitter *)m_service;
            delete p;
            m_service = NULL;
        }
        else if ( !m_serviceSymbol.Compare("Jaiku") ) {
            CJaiku  *p = (CJaiku *)m_service;
            delete p;
            m_service = NULL;
        }
        else if ( !m_serviceSymbol.Compare("Wassr") ) {
            CWassr  *p = (CWassr *)m_service;
            delete p;
            m_service = NULL;
        }
        else if ( !m_serviceSymbol.Compare("Mogo2") ) {
            CMogo2  *p = (CMogo2 *)m_service;
            delete p;
            m_service = NULL;
        }
        else if ( !m_serviceSymbol.Compare("Timelog") ) {
            CTimelog    *p = (CTimelog *)m_service;
            delete p;
            m_service = NULL;
        }
        else if ( !m_serviceSymbol.Compare("HaruFm") ) {
            CHaruFm *p = (CHaruFm *)m_service;
            delete p;
            m_service = NULL;
        }
        else if ( !m_serviceSymbol.Compare("HatenaHaiku") ) {
            CHatenaHaiku    *p = (CHatenaHaiku *)m_service;
            delete p;
            m_service = NULL;
        }
        else {
            delete m_service;
            m_service = NULL;
        }
    }
}

void CManager::SetConfig(
                  CString username,
                  CString password,
                  BOOL checkMultiPost,
                  TIMELINE_INFO sFriendsTimeline,
                  TIMELINE_INFO sPublicTimeline,
                  TIMELINE_INFO sUserTimeline
              )
{
    bool    needToReset = false;
    if ( m_username.Compare( username ) ||
         m_password.Compare( password )    )
        needToReset = true;
    m_service->m_username = m_username = username;
    m_service->m_password = m_password = password;

    if ( needToReset ) {
        // screen�� (��)�ݒ�
        GetScreenName();
    }

    m_simultaneousPost = checkMultiPost ? true : false;
    m_sFriendsTimeline = sFriendsTimeline;
    m_sPublicTimeline  = sPublicTimeline;
    m_sUserTimeline    = sUserTimeline;
}

void CManager::GetConfig(
                  CString &username,
                  CString &password,
                  BOOL &checkMultiPost,
                  TIMELINE_INFO &sFriendsTimeline,
                  TIMELINE_INFO &sPublicTimeline,
                  TIMELINE_INFO &sUserTimeline
              )
{
    username = m_username;
    password = m_password;
    checkMultiPost   = m_simultaneousPost ? TRUE : FALSE;
    sFriendsTimeline = m_sFriendsTimeline;
    sPublicTimeline  = m_sPublicTimeline;
    sUserTimeline    = m_sUserTimeline;
}


void CManager::ExecuteUpdate(
                    CStatic          *sp,
                    bool             useTwitStar,
                    CChirrupDlg      *cdlg,
                    ProceedingDialog *pdlg
                )
{
    if ( m_sFriendsTimeline.checkTimeline ||
         m_sFriendsTimeline.checkChannel  ||
         m_sPublicTimeline.checkTimeline  ||
         m_sUserTimeline.checkTimeline       ) {
        CString msg = m_serviceName;
        msg += _T(": ���擾���c�c");
        sp->SetWindowText( msg );

        SetUpUserInfo();
        m_service->m_useTwitStar = useTwitStar;

        CTwitterTimeline    *tp1 = NULL;
        CTwitterTimeline    *tp2 = NULL;
        CTwitterTimeline    *tp3 = NULL;

        if ( m_useOAuth                          ||
             ( (m_username.GetLength() > 0) &&
               (m_password.GetLength() > 0)    )    ) {
            m_service->m_useOAuth = m_useOAuth;
            if ( m_useOAuth ) {
                m_service->m_oauthToken       = m_oauthToken;
                m_service->m_oauthTokenSecret = m_oauthTokenSecret;
            }

            tp1 = GetPublicTimeline();
            tp2 = GetFriendsTimeline();
            tp3 = GetUserTimeline();
        }

        if ( tp1 && m_sPublicTimeline.checkTimeline ) {
            cdlg->m_startTime_updateThread = CTime::GetCurrentTime();
            tp1->m_messages = m_service->GetPublicTimeline( tp1, pdlg );
        }

        if ( tp2 &&
             (m_sFriendsTimeline.checkTimeline ||
              m_sFriendsTimeline.checkChannel    ) ) {
            cdlg->m_startTime_updateThread = CTime::GetCurrentTime();
            if ( (tp1 && m_sPublicTimeline.checkTimeline) )
                Sleep( 1000 );
            tp2->m_messages = m_service->GetFriendsTimeline( tp2, pdlg );
        }

        if ( tp3 && m_sUserTimeline.checkTimeline ) {
            cdlg->m_startTime_updateThread = CTime::GetCurrentTime();
            if ( (tp1 && m_sPublicTimeline.checkTimeline) ||
                 (tp2 &&
                  (m_sFriendsTimeline.checkTimeline ||
                   m_sFriendsTimeline.checkChannel    )     ) )
                Sleep( 1000 );
            tp3->m_messages = m_service->GetUserTimeline( tp3, pdlg );
        }
    }
}

bool CManager::ExecutePost( 
                    CString          monologue,
                    CStatic          *sp,
                    ProceedingDialog *pdlg
                )
{
    bool    ret = false;
    CString msg = m_serviceName;
    msg += _T(": �����𓊍e���c�c");
    sp->SetWindowText( msg );

    SetUpUserInfo();
    ret = m_service->PostUpdate( monologue, pdlg );

    return ( ret );
}

void CManager::GetScreenName()
{
    if ( m_useOAuth                          ||
         ( (m_username.GetLength() > 0) &&
           (m_password.GetLength() > 0)    )    ) {
        SetUpUserInfo();
        m_screenName = m_service->GetScreenName();
    }
}

void CManager::SetUpUserInfo()
{
    m_service->m_useOAuth           = m_useOAuth;
    m_service->m_username           = m_username;
    if ( !m_serviceSymbol.Compare("Jaiku") )
        ((CJaiku *)m_service)->m_apiKey = m_password;
    else
        m_service->m_password           = m_password;
    m_service->m_oauthToken         = m_oauthToken;
    m_service->m_oauthTokenSecret   = m_oauthTokenSecret;
}

void CManager::SetLogFileSpec()
{
    m_friendsTimeline.SetLogFileSpec( m_sFriendsTimeline );
    m_publicTimeline.SetLogFileSpec( m_sPublicTimeline );
    m_userTimeline.SetLogFileSpec( m_sUserTimeline );
}


void CManager::WriteKeys(
                    FILE          *fp,
                    char          *key,
                    unsigned char **secret,
                    bool          &done )
{
    char    target[BUFSIZ];

    if ( m_username.GetLength() > 0 ) {
        sprintf( target, "usernameFor%s", (const char *)m_serviceSymbol );
        writeKey( fp, target, m_username );
    }

    if ( m_password.GetLength() > 0 ) {
        sprintf( target, "passwordFor%s", (const char *)m_serviceSymbol );
        writeKey( fp, target, m_password, key, secret, done );
    }

    if ( m_useOAuth || m_useBASIC ) {
        sprintf( target, "useOAuthFor%s", (const char *)m_serviceSymbol );
        writeKey( fp, target, m_useOAuth );

        sprintf( target, "useBasicFor%s", (const char *)m_serviceSymbol );
        writeKey( fp, target, m_useBASIC );
    }

    if ( m_oauthToken.GetLength() > 0 ) {
        sprintf( target, "oauthTokenFor%s", (const char *)m_serviceSymbol );
        writeKey( fp, target, m_oauthToken, key, secret, done );
    }
    if ( m_oauthTokenSecret.GetLength() > 0 ) {
        sprintf( target, "oauthTokenSecretFor%s",
                 (const char *)m_serviceSymbol );
        writeKey( fp, target, m_oauthTokenSecret, key, secret, done );
    }

    if ( m_screenName.GetLength() > 0 ) {
        sprintf( target, "screennameFor%s", (const char *)m_serviceSymbol );
        writeKey( fp, target, m_screenName );
    }

    sprintf( target, "simultaneousPostAs%s", (const char *)m_serviceSymbol );
    writeKey( fp, target, m_simultaneousPost );

    WriteKeys( fp, &m_sFriendsTimeline, "Friends" );
    WriteKeys( fp, &m_sPublicTimeline,  "Public"  );
    WriteKeys( fp, &m_sUserTimeline,    "User"    );
}

void CManager::WriteKeys(
                    FILE                *fp,
                    const TIMELINE_INFO *t,
                    const char          *timelineType )
{
    char    target[BUFSIZ];

    sprintf( target, "check%sTimelineFor%s",
             timelineType, (const char *)m_serviceSymbol );
    writeKey( fp, target, t->checkTimeline );

    sprintf( target, "check%sChannelFor%s",
             timelineType, (const char *)m_serviceSymbol );
    writeKey( fp, target, t->checkChannel );

    if ( t->logFileName.GetLength() > 0 ) {
        sprintf( target, "logFileNameOf%sTimelineFor%s",
                 timelineType, (const char *)m_serviceSymbol );
        writeKey( fp, target, t->logFileName );
    }

    sprintf( target, "checkLogFileOf%sTimelineFor%s",
             timelineType, (const char *)m_serviceSymbol );
    writeKey( fp, target, t->checkLogFile );
}

bool CManager::CheckKeys(
                        const char          *p,
                        const unsigned char *rsaString,
                        char                *encrypted,
                        bool                &ret )
{
    bool    cont = false;
    char    target[BUFSIZ];
    bool    checkPassword         = true;
    bool    checkOauthToken       = true;
    bool    checkOauthTokenSecret = true;

    sprintf( target, "passwordFor%sEncrypted",
             (const char *)m_serviceSymbol );
    if ( evalKey( p, target, encrypted ) ) {
        checkKey( m_password,
                  (unsigned char *)encrypted,
                  rsaString,
                  checkPassword );
        cont = true;
    }

    if ( cont == false ) {
        sprintf( target, "oauthTokenFor%sEncrypted",
                 (const char *)m_serviceSymbol );
        if ( evalKey( p, target, encrypted ) ) {
            checkKey( m_oauthToken,
                      (unsigned char *)encrypted,
                      rsaString,
                      checkOauthToken );
            cont = true;
        }
    }

    if ( cont == false ) {
        sprintf( target, "oauthTokenSecretFor%sEncrypted",
                 (const char *)m_serviceSymbol );
        if ( evalKey( p, target, encrypted ) ) {
            checkKey( m_oauthTokenSecret,
                      (unsigned char *)encrypted,
                      rsaString,
                      checkOauthTokenSecret );
            cont = true;
        }
    }

    ret &= (checkPassword & checkOauthToken & checkOauthTokenSecret);

    return ( cont );
}

bool CManager::EvalKeys(
                    const char          *p,
                    const unsigned char *rsaString,
                    char                *encrypted )
{
    bool    ret = false;
    char    target[BUFSIZ];

    sprintf( target, "usernameFor%s", (const char *)m_serviceSymbol );
    if ( evalKey( p, target, m_username ) )
        ret = true;
    if ( ret == false ) {
        sprintf( target, "passwordFor%sEncrypted",
                 (const char *)m_serviceSymbol );
        if ( evalKey( p, target, encrypted ) ) {
            extractKey( m_password,
                        (unsigned char *)encrypted,
                        (unsigned char *)rsaString );
            ret = true;
        }
    }

    if ( ret == false ) {
        sprintf( target, "useOAuthFor%s",
                 (const char *)m_serviceSymbol );
        if ( evalKey( p, target, m_useOAuth ) )
            ret = true;
    }
    if ( ret == false ) {
        sprintf( target, "useBasicFor%s",
                 (const char *)m_serviceSymbol );
        if ( evalKey( p, target, m_useBASIC ) )
            ret = true;
    }

    if ( ret == false ) {
        sprintf( target, "oauthTokenFor%sEncrypted",
                 (const char *)m_serviceSymbol );
        if ( evalKey( p, target, encrypted ) ) {
            extractKey( m_oauthToken,
                        (unsigned char *)encrypted,
                        (unsigned char *)rsaString );
            ret = true;
        }
    }
    if ( ret == false ) {
        sprintf( target, "oauthTokenSecretFor%sEncrypted",
                 (const char *)m_serviceSymbol );
        if ( evalKey( p, target, encrypted ) ) {
            extractKey( m_oauthTokenSecret,
                        (unsigned char *)encrypted,
                        (unsigned char *)rsaString );
            ret = true;
        }
    }

    if ( ret == false ) {
        sprintf( target, "screennameFor%s",
                 (const char *)m_serviceSymbol );
        if ( evalKey( p, target, m_screenName ) )
            ret = true;
    }
    if ( ret == false ) {
        sprintf( target, "simultaneousPostAs%s",
                 (const char *)m_serviceSymbol );
        if ( evalKey( p, target, m_simultaneousPost ) )
            ret = true;
    }
    if ( ret == false )
        ret = EvalKeys( &m_sFriendsTimeline, "Friends", p );
    if ( ret == false )
        ret = EvalKeys( &m_sPublicTimeline,  "Public",  p );
    if ( ret == false )
        ret = EvalKeys( &m_sUserTimeline,    "User",    p );

    return ( ret );
}

bool CManager::EvalKeys(
                    TIMELINE_INFO *t,
                    const char    *timelineType,
                    const char    *p )
{
    bool    ret = false;
    char    target[BUFSIZ];

    if ( ret == false ) {
        sprintf( target, "check%sTimelineFor%s",
                 timelineType, (const char *)m_serviceSymbol );
        if ( evalKey( p, target, t->checkTimeline ) )
            ret = true;
    }

    if ( ret == false ) {
        sprintf( target, "check%sChannelFor%s",
                 timelineType, (const char *)m_serviceSymbol );
        if ( evalKey( p, target, t->checkChannel ) )
            ret = true;
    }

    if ( ret == false ) {
        sprintf( target, "logFileNameOf%sTimelineFor%s",
                 timelineType, (const char *)m_serviceSymbol );
        if ( evalKey( p, target, t->logFileName ) )
            ret = true;
    }

    if ( ret == false ) {
        sprintf( target, "checkLogFileOf%sTimelineFor%s",
                 timelineType, (const char *)m_serviceSymbol );
        if ( evalKey( p, target, t->checkLogFile ) )
            ret = true;
    }

    return ( ret );
}

