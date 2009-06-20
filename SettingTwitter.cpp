/*
 * SettingTwitter.cpp : Twitter �N���C�A���g chirrup
 *      �ݒ�_�C�A���O(Twitter) �C���v�������e�[�V���� �t�@�C��
 *          written by H.Tsujimura  7 Jun 2007
 *
 *      Copyright (c) 2007 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/SettingTwitter.cpp $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 11    09/04/16 17:39 Tsujimura543
 * �F�ؕ��@�I���_�C�A���O����߂��Ă����Ƃ��ɁA���[�U���ƃp�X���[�h��
 * ���f�����Y��Ă����̂𔽉f������悤�ɏC�� (OAuth�Ή����̃o�O)
 * 
 * 10    09/03/31 21:27 Tsujimura543
 * Twitter �� OAuth �Ή����� ����5
 * 
 * 9     09/03/30 22:37 Tsujimura543
 * Twitter �� OAuth �Ή����� ����2
 * 
 * 8     08/07/16 4:13 Tsujimura543
 * �u�������e�Ώہv�̐ݒ���u�ݒ�v�_�C�A���O�ł��ݒ�ł���悤�ɂ���
 * 
 * 7     07/07/05 0:41 Tsujimura543
 * (friends_timeline �̉{�������Ȃ��ݒ�̏ꍇ)Replies �̃t�@�C�����̐ݒ�
 * ���ł��Ȃ��s��ɑΏ�
 * 
 * 6     07/06/13 19:18 Tsujimura543
 * Twitter �� Replies �̉{���A���O�o�͂ɑΉ�
 * 
 * 5     07/06/13 0:12 Tsujimura543
 * (1) TIMELINE_INFO �֘A fix
 * (2) �����ݒ�t�@�C���ǂݏ�����V�������O�t�@�C���Ǘ��d�l�ɑΉ�������
 * 
 * 4     07/06/12 17:51 Tsujimura543
 * Twitter �� Jaiku �ŋ��ʉ��ł��镔���͋��ʉ����A���ʉ�����������
 * CTabDialog �Ɉڊ�
 * 
 * 3     07/06/11 18:39 Tsujimura543
 * Twitter �� user_timeline �̉{�����T�|�[�g
 * 
 * 2     07/06/07 15:47 Tsujimura543
 * CTabDialog �𓱓��A�R�[�h�𐮗����Ă݂�
 * 
 * 1     07/06/07 1:43 Tsujimura543
 * �V�K�쐬 (�^�u�I���`���̐ݒ�_�C�A���O��V���ɗp�ӂ���)
 */

#include "chirrup.h"
#include "chirrupDlg.h"
#include "SettingTwitter.h"
#include "TwitterAuthSelectDialog.h"

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/chirrup/SettingTwitter.cpp 1     09/05/14 3:50 tsupo $";
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSettingTwitter �_�C�A���O

CSettingTwitter::CSettingTwitter(CWnd* pParent /*=NULL*/)
	: CTabDialog(CSettingTwitter::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSettingTwitter)
	m_logFile_replies = _T("");
	m_checkReplies = FALSE;
	m_checkLogFileReplies = FALSE;
	//}}AFX_DATA_INIT

    m_useOAuth = false;
    m_useBASIC = false;
    m_oauthToken       = _T("");
    m_oauthTokenSecret = _T("");
}

void CSettingTwitter::DoDataExchange(CDataExchange* pDX)
{
	CTabDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSettingTwitter)
	DDX_Text(pDX, IDC_EDIT_LOGFILENAME4, m_logFile_replies);
	DDV_MaxChars(pDX, m_logFile_replies, 1024);
	DDX_Check(pDX, IDC_CHECK_REPLIES, m_checkReplies);
	DDX_Check(pDX, IDC_CHECK_REPLIES2, m_checkLogFileReplies);
	//}}AFX_DATA_MAP
}

// �u�ݒ�_�C�A���O�v�ł́u�K�p�v�{�^������������
void CSettingTwitter::Accept()
{
    if ( m_initialized && m_chirrup ) {
        TIMELINE_INFO sFriendsTimeline;
        TIMELINE_INFO sPublicTimeline;
        TIMELINE_INFO sUserTimeline;
        TIMELINE_INFO sReplies;

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

        setTimelineInfo( sReplies,
                         m_logFile_replies,
                         m_checkReplies,
                         m_checkLogFileReplies );

        m_chirrup->SetTwitter( m_username, m_password,
                               m_oauthToken, m_oauthTokenSecret,
                               m_useOAuth, m_useBASIC,
                               m_checkMultiPost,
                               sFriendsTimeline,
                               sPublicTimeline,
                               sUserTimeline,
                               sReplies );
    }
}

// ���݂́u�ݒ�v���擾
void CSettingTwitter::LoadSetting()
{
    if ( !m_initialized ) {
        if ( m_chirrup ) {
            TIMELINE_INFO sFriendsTimeline;
            TIMELINE_INFO sPublicTimeline;
            TIMELINE_INFO sUserTimeline;
            TIMELINE_INFO sReplies;

            BOOL    useOAuth = m_useOAuth ? TRUE : FALSE;
            BOOL    useBASIC = m_useBASIC ? TRUE : FALSE;
            m_chirrup->GetTwitter( m_username, m_password,
                                   m_oauthToken, m_oauthTokenSecret,
                                   useOAuth, useBASIC,
                                   m_checkMultiPost,
                                   sFriendsTimeline,
                                   sPublicTimeline,
                                   sUserTimeline,
                                   sReplies );
            m_useOAuth = useOAuth ? true : false;
            m_useBASIC = useBASIC ? true : false;

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

            getTimelineInfo( sReplies,
                             m_logFile_replies,
                             m_checkReplies,
                             m_checkLogFileReplies );
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
// CSettingTwitter �ǉ����\�b�h

void CSettingTwitter::SetCheckReplies()
{
    CButton *bp;
    CEdit   *ep = (CEdit *)GetDlgItem( IDC_EDIT_LOGFILENAME4 );

    if ( m_checkReplies ) {
        ep->SetReadOnly( FALSE );

        bp = (CButton *)GetDlgItem( IDC_CHECK_REPLIES2 );
        bp->EnableWindow( TRUE );

        bp = (CButton *)GetDlgItem( IDC_BUTTON_FILESPEC4 );
        bp->EnableWindow( TRUE );
    }
    else {
        ep->SetReadOnly( TRUE );

        bp = (CButton *)GetDlgItem( IDC_CHECK_REPLIES2 );
        bp->EnableWindow( FALSE );

        bp = (CButton *)GetDlgItem( IDC_BUTTON_FILESPEC4 );
        bp->EnableWindow( FALSE );
    }
}

void CSettingTwitter::ShowCurrentStatus()
{
    CStatic *sp = (CStatic *)GetDlgItem(IDC_CURRENT_AUTH);

    if ( !m_useOAuth && !m_useBASIC )
        sp->SetWindowText( _T("[���݂̐ݒ�: ���ݒ�]") );
    else if ( m_useOAuth )
        sp->SetWindowText( _T("[���݂̐ݒ�: OAuth�F�؂��g��]") );
    else
        sp->SetWindowText( _T("[���݂̐ݒ�: BASIC�F�؂��g��]") );
}

BEGIN_MESSAGE_MAP(CSettingTwitter, CTabDialog)
	//{{AFX_MSG_MAP(CSettingTwitter)
	ON_BN_CLICKED(IDC_BUTTON_FILESPEC4, OnButtonFilespec4)
	ON_BN_CLICKED(IDC_CHECK_REPLIES, OnCheckReplies)
	ON_BN_CLICKED(IDC_CHECK_REPLIES2, OnCheckReplies2)
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(IDC_BUTTON_SET_AUTH, OnButtonSetAuth)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CSettingTwitter::OnShowWindow(BOOL bShow, UINT nStatus) 
{
    CTabDialog::OnShowWindow(bShow, nStatus);

    if ( bShow ) {
        ShowCurrentStatus();

        CEdit   *p = (CEdit *)GetDlgItem(IDC_EDIT_LOGFILENAME4);
        p->SetWindowText( m_logFile_replies );

        CButton *bp = (CButton *)GetDlgItem( IDC_CHECK_REPLIES );
        bp->SetCheck( m_checkReplies );

        bp = (CButton *)GetDlgItem( IDC_CHECK_REPLIES2 );
        bp->SetCheck( m_checkLogFileReplies );

        SetCheckReplies();
    }
    else {
        CEdit   *p = (CEdit *)GetDlgItem(IDC_EDIT_LOGFILENAME4);
        p->GetWindowText( m_logFile_replies );
    }	
}

void CSettingTwitter::OnButtonFilespec4() 
{
    InputFileName( m_logFile_replies, IDC_EDIT_LOGFILENAME4 );
}

void CSettingTwitter::OnCheckReplies() 
{
    CButton *bp = (CButton *)GetDlgItem( IDC_CHECK_REPLIES );
    m_checkReplies = bp->GetCheck();

    SetCheckReplies();
}

void CSettingTwitter::OnCheckReplies2() 
{
    CButton *bp = (CButton *)GetDlgItem( IDC_CHECK_REPLIES2 );
    m_checkLogFileReplies = bp->GetCheck();
}

void CSettingTwitter::OnButtonSetAuth() 
{
    TwitterAuthSelectDialog dlg;

    dlg.m_username = m_username;
    dlg.m_password = m_password;
    dlg.m_oauthToken       = m_oauthToken;
    dlg.m_oauthTokenSecret = m_oauthTokenSecret;

    dlg.m_useOAuth = m_useOAuth;
    dlg.m_useBASIC = m_useBASIC;

    int result = dlg.DoModal();
    if ( result == IDOK ) {
        m_username = dlg.m_username;
        m_password = dlg.m_password;

        m_oauthToken       = dlg.m_oauthToken;
        m_oauthTokenSecret = dlg.m_oauthTokenSecret;

        m_useOAuth = dlg.m_useOAuth;
        m_useBASIC = dlg.m_useBASIC;

        CEdit   *p = (CEdit *)GetDlgItem(IDC_EDIT_USERNAME);
        p->SetWindowText( m_username );

        p = (CEdit *)GetDlgItem(IDC_EDIT_PASSWORD);
        p->SetWindowText( m_password );

        ShowCurrentStatus();
    }
}
