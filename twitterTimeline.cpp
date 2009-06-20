/*
 * twitterTimeline.cpp : Twitter �N���C�A���g chirrup
 *      timeline �֘A�e�폈���Q
 *          written by H.Tsujimura  4 Apr 2007 / 25 May 2007
 *
 *      Copyright (c) 2007, 2008, 2009 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/twitterTimeline.cpp $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 32    09/04/16 19:22 Tsujimura543
 * LoadUserIcon() ���C���B���[�U�A�C�R���̕\���^�C�~���O�A�k�������E�k����
 * ��ύX����
 * 
 * 31    09/03/31 23:29 Tsujimura543
 * Twitter �� OAuth �Ή����� ����7
 * 
 * 30    08/09/02 18:36 Tsujimura543
 * �͂Ăȃn�C�N�̃A�C�R���\�������������Ȃ錏�A�Ώ����Ă݂�
 * 
 * 29    08/08/22 20:21 Tsujimura543
 * �u�͂Ăȃn�C�N�v�֘A�A����m�F�I��
 * 
 * 28    08/08/22 18:42 Tsujimura543
 * �u�͂Ăȃn�C�N�v�Ή�
 * 
 * 27    08/07/31 18:19 Tsujimura543
 * �u�`�����l���v�ɑΉ�
 * 
 * 26    08/07/14 13:54 Tsujimura543
 * �A�C�R�����u�\���̈�T�C�Y�ɍ��킹�ĉ摜���k���\������v�悤�ɂ���
 * 
 * 25    08/04/22 22:14 Tsujimura543
 * �^�C�����C���̉{���͂��邪���O�͋L�^���Ȃ��Ƃ����ݒ�̏ꍇ�ł�
 * ���O���L�^����Ă��܂����Ƃ�����s��ɑΏ�
 * 
 * 24    08/02/07 22:36 Tsujimura543
 * copyright �\�����C�� (2008 ��ǉ�)
 * 
 * 23    08/01/07 14:55 Tsujimura543
 * �s�v�ɂȂ����������폜
 * 
 * 22    08/01/07 14:43 Tsujimura543
 * �f�t�H���g�A�C�R���̕\�������� LoadDefaultUserIcon() �Ƃ���
 * �����B���[�U�A�C�R���擾���s�����f�t�H���g�A�C�R����\������
 * �悤�ɂ��Ă݂�
 * 
 * 21    07/11/26 19:42 Tsujimura543
 * LoadTimeline() ���C�� (�����ł��؂�^�C�~���O�𑁂�����)
 * 
 * 20    07/11/26 19:34 Tsujimura543
 * LoadTimeline() ���� TCP/IP �̃^�C���A�E�g�����������ꍇ�́A�����ɏ�����
 * �ł��؂��ă��^�[������悤�ɂ���
 * 
 * 19    07/09/13 16:00 Tsujimura543
 * �\�[�X�R�[�h�𐮗�
 * 
 * 18    07/09/13 15:55 Tsujimura543
 * InitTimeline() ���C���Bm_numOfUsers �̒l�� 0 �̂Ƃ��ł���������
 * �悤�ɂ���
 * 
 * 17    07/07/05 22:29 Tsujimura543
 * LoadUserIcon() ���ł̉摜�擾���� http �ʐM�̃^�C���A�E�g���Ԃ�
 * 15�b�ɂ��Ă݂�
 * 
 * 16    07/07/05 16:08 Tsujimura543
 * GetServiceName() ��ǉ�
 * 
 * 15    07/07/04 20:06 Tsujimura543
 * m_logFileExtention �̃f�t�H���g�l���C�� (".txt" �� "txt")
 * 
 * 14    07/07/03 13:39 Tsujimura543
 * LoadUserIcon() �� Haru.fm �ɑΉ�������
 * 
 * 13    07/06/27 18:13 Tsujimura543
 * haru.fm �ɑΉ�
 * 
 * 12    07/06/21 23:18 Tsujimura543
 * LoadUserIcon() �ŁATimelog �Ɋւ��Ă��A���[�U�A�C�R���� URL ���s����
 * �Ƃ��̑Ή�������ǉ�
 * 
 * 11    07/06/21 22:40 Tsujimura543
 * LoadUserIcon() ��ύX�A���[�U�A�C�R���� URL ���s���ȏꍇ�ATwitter
 * �� ShowUser API ���g���ăA�C�R���� URL ���擾����悤�ɂ���
 * 
 * 10    07/06/21 21:42 Tsujimura543
 * LoadUserIcon() ���C���BTimelog �̃_�C���N�g���b�Z�[�W���M�_�C�A���O
 * �\�����Ɋ��҂���A�C�R�����\���ł���悤�ɂ���
 * 
 * 9     07/06/20 17:36 Tsujimura543
 * Timelog �Ή�
 * 
 * 8     07/06/18 19:07 Tsujimura543
 * LoadUserIcon() ��ύX�A���������̃��[�U�A�C�R���L���b�V������
 * �t�@�C���̓��� M ��t����悤�ɂ���
 * 
 * 7     07/06/18 18:52 Tsujimura543
 * LoadUserIcon() �𓱓����A���[�U�A�C�R���̕\����������{������
 * 
 * 6     07/06/13 0:12 Tsujimura543
 * (1) TIMELINE_INFO �֘A fix
 * (2) �����ݒ�t�@�C���ǂݏ�����V�������O�t�@�C���Ǘ��d�l�ɑΉ�������
 * 
 * 5     07/06/12 19:49 Tsujimura543
 * ���O�t�@�C�����̖����ɓ��t�𖄂ߍ��ނ��Ƃ��ł���悤�ɂ���
 * 
 * 4     07/06/06 19:05 Tsujimura543
 * ���O���t�@�C���ɏ����o���@�\������
 * 
 * 3     07/05/29 3:56 Tsujimura543
 * Jaiku (�� public_timeline �̉{��) �ɑΉ�
 * 
 * 2     07/05/25 23:03 Tsujimura543
 * ���t�@�N�^�����O
 * 
 * 1     07/05/25 20:16 Tsujimura543
 * �V�K�쐬 (chirrupDlg.cpp ���番���A�Ɨ�)
 */

#include "chirrup.h"
#include "chirrupDlg.h"

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/chirrup/twitterTimeline.cpp 1     09/05/14 3:50 tsupo $";
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CTwitterTimeline::CTwitterTimeline()
{
    m_checkTimeline    = false;
    m_checkChannel     = false;
    m_checkLogFile     = false;
    m_logFileBaseName  = _T("timeline");
    m_logFileExtention = _T("txt");

	m_messages         = _T("");
    m_numOfUsers       = 0;
    m_users            = NULL;

    m_stat             = new TWITTER_STATUS[MAX_NUMOFSTATUS];
    m_numOfStats       = 0;

    m_logging          = false;
    m_logFileName[0]   = NUL;
    m_logFp            = NULL;

    m_serviceType      = SVC_TWITTER;
}

CTwitterTimeline::~CTwitterTimeline()
{
    if ( m_logFp )
        FinishLogging();

    if ( m_users ) {
        int i;
        for ( i = 0; i < MAX_NUMOFFRIENDS; i++ ) {
            if ( m_users[i].bitmap )
                DeleteObject( m_users[i].bitmap );
        }
        delete [] m_users;
    }
    if ( m_stat )
        delete [] m_stat;
}


bool
CTwitterTimeline::InitTimeline()
{
    bool    cnt = true;
    int     i;

    if ( m_numOfUsers == 0 ) {
        if ( !m_users ) {
            m_users = new TWITTER_USER[MAX_NUMOFFRIENDS];
            for ( i = 0; i < MAX_NUMOFFRIENDS; i++ ) {
                m_users[i].id[0]   = NUL;
                m_users[i].name[0] = NUL;
                m_users[i].bitmap  = NULL;
            }
        }
    }
    else {
        for ( i = 0; i < MAX_NUMOFFRIENDS; i++ ) {
            m_users[i].id[0]   = NUL;
            m_users[i].name[0] = NUL;
            if ( m_users[i].bitmap )
                DeleteObject( m_users[i].bitmap );
            m_users[i].bitmap  = NULL;
        }
        m_numOfUsers = 0;
    }

    return ( cnt );
}

void
CTwitterTimeline::MoveTimeline()
{
    int i, j;

    for ( i = 0; i < m_numOfStats; i++ ) {
        for ( j = 0; j < MAX_NUMOFFRIENDS; j++ ) {
            if ( m_users[j].id[0] ) {
                if ( !strcmp( m_users[j].id, m_stat[i].user.id ) )
                    break;
            }
            else {
                m_users[j]   = m_stat[i].user;
                m_numOfUsers = j;
                break;
            }
        }
    }
}

void
CTwitterTimeline::LoadTimeline(
                        CChirrupDlg *cp,
                        CString     cacheDir
                    )
{
    CStatic *sp;
    int     i;

    for ( i = 0; i < MAX_NUMOFFRIENDS; i++ ) {
        if ( isNecessaryToCheckProxyInfo() )
            break;
        sp = (CStatic *)cp->GetDlgItem( IDC_FRIEND001 + i );
        LoadUserIcon( sp, &(m_users[i]), m_serviceType, cacheDir );
    }
}


void CTwitterTimeline::SetLogFileSpec( TIMELINE_INFO s )
{
    m_checkTimeline = s.checkTimeline;
    m_checkChannel  = s.checkChannel;
    m_checkLogFile  = s.checkLogFile;

    if ( s.logFileName.GetLength() > 0 ) {
        char    filename[MAX_PATH];
        strcpy( filename, s.logFileName );

        char    *p = strrchr( filename, '.' );
        if ( p ) {
            m_logFileExtention = p + 1;

            char    temp[MAX_PATH];
            strncpy( temp, filename, p - filename );
            temp[p - filename] = NUL;
            m_logFileBaseName = temp;
        }
        else
            m_logFileBaseName = filename;
    }

    if ( (m_checkTimeline || m_checkChannel) &&
         (m_logFileBaseName.GetLength() > 0)    ) {
        StartLogging();
        if ( m_checkLogFile )
            WriteLog( "\r\n*** logging start ***\r\n" );
    }
}


void CTwitterTimeline::StartLogging()
{
    if ( m_logFp )
        FinishLogging();

    if ( m_checkLogFile ) {
        time_t      t   = time( NULL );
        struct tm   *tm = localtime( &t );

        sprintf( m_logFileName,
                 "%s_%04d%02d%02d.%s",
                 (const char *)m_logFileBaseName,
                 tm->tm_year + 1900,
                 tm->tm_mon  + 1,
                 tm->tm_mday,
                 (const char *)m_logFileExtention );
    }
    else
        sprintf( m_logFileName, "%s_%s.%s",
                 (const char *)GetServiceName(),
                 (const char *)m_logFileBaseName,
                 (const char *)m_logFileExtention );

    if ( m_checkLogFile ) {
        m_logFp = fopen( m_logFileName, "ab+" );
        if ( m_logFp )
            m_logging = true;
    }
}

void CTwitterTimeline::FinishLogging()
{
    if ( m_logFp ) {
        fclose( m_logFp );
        m_logFp = NULL;
    }

    m_logging = false;
}

void CTwitterTimeline::WriteLog( const char *str )
{
    if ( m_logging && m_logFp ) {
        fputs( str, m_logFp );

        // �r���ŃA�v���P�[�V����(���邢�� OS)���N���b�V�����ă��O�t�@�C��
        // �������Ă��܂��A�Ƃ������Ԃ�����邽�߂ɖ���t�@�C������āA
        // �J������
        FinishLogging();
        StartLogging();
    }
}

CString
CTwitterTimeline::GetServiceName()
{
    CString s = _T("");

    switch ( m_serviceType ) {
    case SVC_TWITTER:
        s = _T("Twitter");
        break;
    case SVC_JAIKU:
        s = _T("Jaiku");
        break;
    case SVC_WASSR:
        s = _T("Wassr");
        break;
    case SVC_MOGO2:
        s = _T("Mogo2");
        break;
    case SVC_TIMELOG:
        s = _T("Timelog");
        break;
    case SVC_HARUFM:
        s = _T("HaruFm");
        break;
    case SVC_HATENAHAIKU:
        s = _T("HatenaHaiku");
        break;
    }

    return ( s );
}


/* utility */
bool
LoadDefaultUserIcon( TWITTER_USER               *u,
                     CTwitterTimeline::SVC_TYPE &type,
                     const char                 *cacheDir )
{
    CImage  img;
    bool    allocated = false;
    char    filename[MAX_PATH];
    char    *defaultImageURL = TWITTER_DEFAULT_IMAGE;

    switch ( type ) {
    case CTwitterTimeline::SVC_JAIKU:
        defaultImageURL = JAIKU_DEFAULT_IMAGE;
        break;
    case CTwitterTimeline::SVC_WASSR:
        defaultImageURL = WASSR_DEFAULT_IMAGE;
        break;
    case CTwitterTimeline::SVC_MOGO2:
        defaultImageURL = MOGO2_DEFAULT_IMAGE;
        break;
    case CTwitterTimeline::SVC_TIMELOG:
        defaultImageURL = TIMELOG_DEFAULT_IMAGE;
        break;
    case CTwitterTimeline::SVC_HARUFM:
        defaultImageURL = HARUFM_DEFAULT_IMAGE;
        break;
    case CTwitterTimeline::SVC_HATENAHAIKU:
        defaultImageURL = HATENAHAIKU_DEFAULT_IMAGE;
        break;
    }

    sprintf( filename,
             "%s%s",
             cacheDir,
             strrchr( defaultImageURL, '/' ) + 1 );

    if ( u->bitmap )
        DeleteObject( u->bitmap );
    u->bitmap = img.HttpOpen( defaultImageURL, filename );
    if ( u->bitmap )
        allocated = true;

    return ( allocated );
}

bool
LoadUserIcon( CStatic                    *sp,
              TWITTER_USER               *u,
              CTwitterTimeline::SVC_TYPE &type,
              const char                 *cacheDir,
              CString                    username         /* = _T("") */,
              CString                    password         /* = _T("") */,
              bool                       useOAuth         /* = false  */,
              CString                    oauthToken       /* = _T("") */,
              CString                    oauthTokenSecret /* = _T("") */ )
{
    CImage  img;
    bool    allocated = false;

    if ( !(u->id[0]) )
        allocated = LoadDefaultUserIcon( u, type, cacheDir );
    else if ( !(u->profileImageURL[0]) ) {
        if ( type == CTwitterTimeline::SVC_TWITTER ) {
            CTwitter        t;
            TWITTER_USER    uu;

            t.m_username          = username;
            t.m_password          = password;
            t.m_useOAuth          = useOAuth;
            t.m_oauthToken        = oauthToken;
            t.m_oauthTokenSecret  = oauthTokenSecret;
            uu.profileImageURL[0] = NUL;
            uu = t.ShowUser( u->id );
            if ( uu.profileImageURL[0] )
                strcpy( u->profileImageURL, uu.profileImageURL );
        }
        else if ( type == CTwitterTimeline::SVC_TIMELOG ) {
            sprintf( u->profileImageURL,
                     "http://timelog.jp/images/user/%s_m.jpg",
                     u->id );
        }
    }

    if ( !(u->bitmap) /* && !allocated */ ) {
        char    *p;
        char    filename[MAX_PATH];

        if ( strstr( u->profileImageURL, "jaiku.com" ) )
            type = CTwitterTimeline::SVC_JAIKU;
        else if ( strstr( u->profileImageURL, "wassr.jp" ) )
            type = CTwitterTimeline::SVC_WASSR;
        else if ( strstr( u->profileImageURL, "mogo2.jp" ) )
            type = CTwitterTimeline::SVC_MOGO2;
        else if ( strstr( u->profileImageURL, "timelog.jp" ) )
            type = CTwitterTimeline::SVC_TIMELOG;
        else if ( strstr( u->profileImageURL, "haru.fm" ) )
            type = CTwitterTimeline::SVC_HARUFM;
        else if ( strstr( u->profileImageURL, "hatena.ne.jp" ) )
            type = CTwitterTimeline::SVC_HATENAHAIKU;

        if ( type == CTwitterTimeline::SVC_JAIKU )
            sprintf( filename,
                     "%sJ%s",
                     cacheDir,
                     u->id );
        else if ( type == CTwitterTimeline::SVC_MOGO2 )
            sprintf( filename,
                     "%sM%s",
                     cacheDir,
                     u->id );
        else if ( type == CTwitterTimeline::SVC_TIMELOG )
            sprintf( filename,
                     "%sTL_%s",
                     cacheDir,
                     u->id );
        else if ( type == CTwitterTimeline::SVC_HARUFM )
            sprintf( filename,
                     "%sHF_%s",
                     cacheDir,
                     u->id );
        else if ( type == CTwitterTimeline::SVC_HATENAHAIKU )
            sprintf( filename,
                     "%sHH_%s",
                     cacheDir,
                     u->id );
        else
            sprintf( filename,
                     "%s%s",
                     cacheDir,
                     u->id );
        p = strrchr( u->profileImageURL, '.' );
        if ( p && (type != CTwitterTimeline::SVC_HARUFM) ) {
            strcat( filename, p );
            p = strrchr( filename, '?' );
            if ( p )
                *p = NUL;
        }
        else {
            if ( (type == CTwitterTimeline::SVC_TIMELOG) ||
                 (type == CTwitterTimeline::SVC_HARUFM)     )
                strcat( filename, ".jpg" );
        }

        setTimeoutTime( 15 );
        u->bitmap = img.HttpOpen( u->profileImageURL, filename );
        setTimeoutTime( DEFAULT_HTTP_TIMEOUT );
        if ( u->bitmap )
            allocated = true;
        else
            allocated = LoadDefaultUserIcon( u, type, cacheDir );
    }

    if ( u->bitmap ) {
        // �摜���傫���Ă͂ݏo���ꍇ�͏k������
        int     height = 0;
        int     width  = 0;
        int     maxSq  = 50; /* Jaiku */
        BITMAP  bmp;
        GetObject( u->bitmap, sizeof ( bmp ), (LPSTR)&bmp );
        height = bmp.bmHeight;
        width  = bmp.bmWidth;

        switch ( type ) {
        case CTwitterTimeline::SVC_TWITTER:
        case CTwitterTimeline::SVC_HARUFM:
            maxSq  = 48;
            break;
        case CTwitterTimeline::SVC_JAIKU:
        case CTwitterTimeline::SVC_HATENAHAIKU: /* 64x64 */
            maxSq  = 50;
            break;
        case CTwitterTimeline::SVC_MOGO2:
            maxSq  = 30;
            break;
        case CTwitterTimeline::SVC_TIMELOG:
            maxSq  = 35;
            break;
        case CTwitterTimeline::SVC_WASSR:
            maxSq  = 32;
            break;
        }

        maxSq = (int)(maxSq * 1.02);
        sp->ShowWindow( FALSE );
        sp->SetBitmap( u->bitmap );
        if ( (height > maxSq) || (width > maxSq) ) {
            // �\���̈�T�C�Y�ɍ��킹�ĉ摜���k���\������
            int sig = ((max(height, width)) + (maxSq - 1)) / maxSq;
            sp->SetWindowPos( sp->GetTopWindow(),
                              0, 0, width/sig, height/sig,
                              SWP_NOMOVE );
        }
        sp->ShowWindow( TRUE );
    }
    return ( allocated );
}
