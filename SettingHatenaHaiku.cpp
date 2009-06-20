/*
 * SettingHatenaHaiku.cpp : �͂Ăȃn�C�N �N���C�A���g chirrup
 *      �ݒ�_�C�A���O(�͂Ăȃn�C�N) �C���v�������e�[�V���� �t�@�C��
 *          written by H.Tsujimura  22 Aug 2008
 *
 *      Copyright (c) 2008 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/SettingHatenaHaiku.cpp $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 3     08/08/22 21:53 Tsujimura543
 * �u�q���g�v�\�������̏������C��
 * 
 * 2     08/08/22 18:41 Tsujimura543
 * ����m�F�I��
 * 
 * 1     08/08/22 17:34 Tsujimura543
 * �V�K�쐬
 */

#include "chirrup.h"
#include "chirrupDlg.h"
#include "SettingHatenaHaiku.h"

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/chirrup/SettingHatenaHaiku.cpp 1     09/05/14 3:50 tsupo $";
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#if (WINVER >= 0x0500)
//#define IDC_HAND    MAKEINTRESOURCE(32649)
#ifdef IDC_HAND
#undef IDC_HAND
#endif
#endif /* WINVER >= 0x0500 */
#define IDC_HAND    IDC_HAND2

/////////////////////////////////////////////////////////////////////////////
// CSettingHatenaHaiku �_�C�A���O

CSettingHatenaHaiku::CSettingHatenaHaiku(CWnd* pParent /*=NULL*/)
	: CTabDialog(CSettingHatenaHaiku::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSettingHatenaHaiku)
	//}}AFX_DATA_INIT

    m_hCursor = AfxGetApp()->LoadCursor( IDC_HAND );
}

CSettingHatenaHaiku::~CSettingHatenaHaiku()
{
    m_cFont.DeleteObject();
}

// �u�ݒ�_�C�A���O�v�ł́u�K�p�v�{�^������������
void CSettingHatenaHaiku::Accept()
{
    if ( m_initialized && m_chirrup ) {
        TIMELINE_INFO sFriendsTimeline;
        TIMELINE_INFO sPublicTimeline;
        TIMELINE_INFO sUserTimeline;

        setTimelineInfo( sFriendsTimeline,
                         m_logFile_friendsTimeline,
                         m_checkFriendsTimeline,
                         m_checkLogFileFriendsTimeline );

        setTimelineInfo( sPublicTimeline,
                         m_logFile_publicTimeline,
                         m_checkPublicTimeline,
                         m_checkLogFilePublicTimeline );

        setTimelineInfo( sUserTimeline,
                         m_logFile_userTimeline,
                         m_checkUserTimeline,
                         m_checkLogFileUserTimeline );

        m_chirrup->SetHatenaHaiku( m_username, m_password,
                                   m_checkMultiPost,
                                   sFriendsTimeline,
                                   sPublicTimeline,
                                   sUserTimeline );
    }
}

// ���݂́u�ݒ�v���擾
void CSettingHatenaHaiku::LoadSetting()
{
    if ( !m_initialized ) {
        if ( m_chirrup ) {
            TIMELINE_INFO sFriendsTimeline;
            TIMELINE_INFO sPublicTimeline;
            TIMELINE_INFO sUserTimeline;

            m_chirrup->GetHatenaHaiku( m_username, m_password,
                                       m_checkMultiPost,
                                       sFriendsTimeline,
                                       sPublicTimeline,
                                       sUserTimeline );

            getTimelineInfo( sFriendsTimeline,
                             m_logFile_friendsTimeline,
                             m_checkFriendsTimeline,
                             m_checkLogFileFriendsTimeline );

            getTimelineInfo( sPublicTimeline,
                             m_logFile_publicTimeline,
                             m_checkPublicTimeline,
                             m_checkLogFilePublicTimeline );

            getTimelineInfo( sUserTimeline,
                             m_logFile_userTimeline,
                             m_checkUserTimeline,
                             m_checkLogFileUserTimeline );
        }

        LOGFONT tLogFont;
        CFont   *cWndFont;

        cWndFont = GetFont(); 
        cWndFont->GetLogFont( &tLogFont );
        tLogFont.lfUnderline = 1;
        m_cFont.CreateFontIndirect( &tLogFont );

        CStatic *s = (CStatic *)GetDlgItem( IDC_URL_HATENAHAIKU_SETTING );
        s->SetFont( &m_cFont, TRUE );
    }
}

void CSettingHatenaHaiku::DoDataExchange(CDataExchange* pDX)
{
	CTabDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSettingHatenaHaiku)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSettingHatenaHaiku, CTabDialog)
	//{{AFX_MSG_MAP(CSettingHatenaHaiku)
	ON_BN_CLICKED(IDC_URL_HATENAHAIKU_SETTING, OnUrlHatenaHaikuSetting)
	ON_WM_SETCURSOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSettingHatenaHaiku ���b�Z�[�W �n���h��

void CSettingHatenaHaiku::OnUrlHatenaHaikuSetting() 
{
	CString cmd;
	cmd.LoadString( IDS_URL_HATENAHAIKU_SETTING );
    ShellExecute( NULL, "open", cmd, NULL, NULL, SW_SHOWNORMAL );
}

BOOL CSettingHatenaHaiku::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	if ( nHitTest == HTCLIENT ) {
        // Web �� URL�����[���A�h���X�Ƀ}�E�X�|�C���^��������A
        // �w�J�[�\����\������
		DWORD   dwPos = GetMessagePos();
		WORD    wX    = LOWORD( dwPos );
		WORD    wY    = HIWORD( dwPos );
		CPoint  poCursor( wX, wY );
		CRect   rcClient;

        CStatic *s = (CStatic *)GetDlgItem( IDC_URL_HATENAHAIKU_SETTING );
        s->GetWindowRect( &rcClient );
        if ( (wX >= rcClient.left) && (wX <= rcClient.right)  &&
             (wY >= rcClient.top)  && (wY <= rcClient.bottom)    ) {
			SetCursor( m_hCursor );
            return TRUE;
        }
	}

	return CTabDialog::OnSetCursor(pWnd, nHitTest, message);
}
