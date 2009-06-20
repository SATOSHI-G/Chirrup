/*
 * CTabDialog.cpp : Twitter �N���C�A���g chirrup
 *      �ݒ�_�C�A���O(�^�u�\��t����������) �C���v�������e�[�V���� �t�@�C��
 *          written by H.Tsujimura  7 Jun 2007
 *
 *      Copyright (c) 2007 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/CTabDialog.cpp $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 6     08/07/16 4:13 Tsujimura543
 * �u�������e�Ώہv�̐ݒ���u�ݒ�v�_�C�A���O�ł��ݒ�ł���悤�ɂ���
 * 
 * 5     07/06/18 22:35 Tsujimura543
 * ���[�U���̍ő勖�e����32�o�C�g����64�o�C�g�֕ύX
 * 
 * 4     07/06/13 0:12 Tsujimura543
 * (1) TIMELINE_INFO �֘A fix
 * (2) �����ݒ�t�@�C���ǂݏ�����V�������O�t�@�C���Ǘ��d�l�ɑΉ�������
 * 
 * 3     07/06/12 17:54 Tsujimura543
 * (1) Twitter �� Jaiku �ŋ��ʉ��ł��镔���� CTagDialog �Ɉړ�
 * (2) �ݒ荀�ڂ�ǉ� (�{���ΏۂƂ��邩�A���O�̃t�@�C�����ɓ��t��t��
 *     ���邩)
 * 
 * 2     07/06/07 15:47 Tsujimura543
 * CTabDialog �𓱓��A�R�[�h�𐮗����Ă݂�
 * 
 * 1     07/06/07 15:45 Tsujimura543
 * �V�K�쐬 (SettingTwitter, SettingJaiku �̋��ʕ�����ێ�����N���X��
 * ���Đ݌v�B����̑Ή��T�[�r�X�����������ł��e�Ղɂ���ړI������)
 */

#include "chirrup.h"
#include "chirrupDlg.h"
#include "CTabDialog.h"

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/chirrup/CTabDialog.cpp 1     09/05/14 3:50 tsupo $";
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTabDialog �_�C�A���O

CTabDialog::CTabDialog( UINT nIDTemplate, CWnd* pParentWnd )
	: CDialog(nIDTemplate, pParentWnd)
{
	//{{AFX_DATA_INIT(CTabDialog)
	m_username = _T("");
	m_password = _T("");
	m_logFile_friendsTimeline = _T("");
	m_logFile_publicTimeline = _T("");
	m_logFile_userTimeline = _T("");
	m_checkFriendsTimeline = FALSE;
	m_checkPublicTimeline = FALSE;
	m_checkUserTimeline = FALSE;
	m_checkLogFileFriendsTimeline = FALSE;
	m_checkLogFilePublicTimeline = FALSE;
	m_checkLogFileUserTimeline = FALSE;
    m_checkMultiPost = FALSE;
	//}}AFX_DATA_INIT

    m_initialized = false;
    m_chirrup     = NULL;
}

void CTabDialog::InputFileName( CString &targetFilename, int id )
{
    CFileDialog *fileDlg = NULL;
    CString     fileName;
    CString     fileType;
    const char  *fileExtention;
    const char  *fileDefault = NULL;

    fileExtention = "txt";
    fileType = _T("�e�L�X�g�t�@�C�� (*.txt)|*.txt||");

    if ( fileExtention )
        fileDlg = new CFileDialog( FALSE, fileExtention, fileDefault,
                                   OFN_CREATEPROMPT,
                                   fileType );
    if ( fileDlg ) {
        if ( fileDlg->DoModal() == IDOK )
            fileName = fileDlg->GetPathName();
        delete fileDlg;

        if ( fileName.GetLength() > 0 ) {
            targetFilename = fileName;

            CEdit   *p = (CEdit *)GetDlgItem( id );
            p->SetWindowText( targetFilename );
        }
    }
}

void CTabDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTabDialog)
	DDX_Text(pDX, IDC_EDIT_USERNAME, m_username);
	DDV_MaxChars(pDX, m_username, 64);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_password);
	DDV_MaxChars(pDX, m_password, 32);
	DDX_Text(pDX, IDC_EDIT_LOGFILENAME, m_logFile_friendsTimeline);
	DDV_MaxChars(pDX, m_logFile_friendsTimeline, 1024);
	DDX_Text(pDX, IDC_EDIT_LOGFILENAME2, m_logFile_publicTimeline);
	DDV_MaxChars(pDX, m_logFile_publicTimeline, 1024);
	DDX_Text(pDX, IDC_EDIT_LOGFILENAME3, m_logFile_userTimeline);
	DDV_MaxChars(pDX, m_logFile_userTimeline, 1024);
	DDX_Check(pDX, IDC_CHECK_FRIENDS_TIMELINE, m_checkFriendsTimeline);
	DDX_Check(pDX, IDC_CHECK_PUBLIC_TIMELINE, m_checkPublicTimeline);
	DDX_Check(pDX, IDC_CHECK_USER_TIMELINE, m_checkUserTimeline);
	DDX_Check(pDX, IDC_CHECK_FRIENDS_TIMELINE2, m_checkLogFileFriendsTimeline);
	DDX_Check(pDX, IDC_CHECK_PUBLIC_TIMELINE2, m_checkLogFilePublicTimeline);
	DDX_Check(pDX, IDC_CHECK_USER_TIMELINE2, m_checkLogFileUserTimeline);
	DDX_Check(pDX, IDC_CHECK_MULTIPOST, m_checkMultiPost);
	//}}AFX_DATA_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CTabDialog �ǉ����\�b�h

void CTabDialog::SetCheckFriendsTimeline()
{
    CButton *bp;
    CEdit   *ep = (CEdit *)GetDlgItem( IDC_EDIT_LOGFILENAME );

    if ( m_checkFriendsTimeline ) {
        ep->SetReadOnly( FALSE );

        bp = (CButton *)GetDlgItem( IDC_CHECK_FRIENDS_TIMELINE2 );
        bp->EnableWindow( TRUE );

        bp = (CButton *)GetDlgItem( IDC_BUTTON_FILESPEC );
        bp->EnableWindow( TRUE );
    }
    else {
        ep->SetReadOnly( TRUE );

        bp = (CButton *)GetDlgItem( IDC_CHECK_FRIENDS_TIMELINE2 );
        bp->EnableWindow( FALSE );

        bp = (CButton *)GetDlgItem( IDC_BUTTON_FILESPEC );
        bp->EnableWindow( FALSE );
    }
}

void CTabDialog::SetCheckPublicTimeline()
{
    CButton *bp;
    CEdit   *ep = (CEdit *)GetDlgItem( IDC_EDIT_LOGFILENAME2 );

    if ( m_checkPublicTimeline ) {
        ep->SetReadOnly( FALSE );

        bp = (CButton *)GetDlgItem( IDC_CHECK_PUBLIC_TIMELINE2 );
        bp->EnableWindow( TRUE );

        bp = (CButton *)GetDlgItem( IDC_BUTTON_FILESPEC2 );
        bp->EnableWindow( TRUE );
    }
    else {
        ep->SetReadOnly( TRUE );

        bp = (CButton *)GetDlgItem( IDC_CHECK_PUBLIC_TIMELINE2 );
        bp->EnableWindow( FALSE );

        bp = (CButton *)GetDlgItem( IDC_BUTTON_FILESPEC2 );
        bp->EnableWindow( FALSE );
    }
}

void CTabDialog::SetCheckUserTimeline()
{
    CButton *bp;
    CEdit   *ep = (CEdit *)GetDlgItem( IDC_EDIT_LOGFILENAME3 );

    if ( m_checkUserTimeline ) {
        ep->SetReadOnly( FALSE );

        bp = (CButton *)GetDlgItem( IDC_CHECK_USER_TIMELINE2 );
        bp->EnableWindow( TRUE );

        bp = (CButton *)GetDlgItem( IDC_BUTTON_FILESPEC3 );
        bp->EnableWindow( TRUE );
    }
    else {
        ep->SetReadOnly( TRUE );

        bp = (CButton *)GetDlgItem( IDC_CHECK_USER_TIMELINE2 );
        bp->EnableWindow( FALSE );

        bp = (CButton *)GetDlgItem( IDC_BUTTON_FILESPEC3 );
        bp->EnableWindow( FALSE );
    }
}

void CTabDialog::setTimelineInfo(
                        TIMELINE_INFO &s,
                        CString       logFile,
                        BOOL          checkTimeline,
                        BOOL          checkLogFile
                    )
{
    s.logFileName   = logFile;
    s.checkTimeline = checkTimeline ? true : false;
    s.checkLogFile  = checkLogFile  ? true : false;
}

void CTabDialog::getTimelineInfo(
                        TIMELINE_INFO s,
                        CString       &logFile,
                        BOOL          &checkTimeline,
                        BOOL          &checkLogFile
                    )
{
    logFile = s.logFileName;
    checkTimeline = s.checkTimeline ? TRUE : FALSE;
    checkLogFile  = s.checkLogFile  ? TRUE : FALSE;
}

BEGIN_MESSAGE_MAP(CTabDialog, CDialog)
	//{{AFX_MSG_MAP(CTabDialog)
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(IDC_BUTTON_FILESPEC, OnButtonFilespec)
	ON_BN_CLICKED(IDC_BUTTON_FILESPEC2, OnButtonFilespec2)
	ON_BN_CLICKED(IDC_BUTTON_FILESPEC3, OnButtonFilespec3)
	ON_BN_CLICKED(IDC_CHECK_FRIENDS_TIMELINE, OnCheckFriendsTimeline)
	ON_BN_CLICKED(IDC_CHECK_PUBLIC_TIMELINE, OnCheckPublicTimeline)
	ON_BN_CLICKED(IDC_CHECK_USER_TIMELINE, OnCheckUserTimeline)
	ON_BN_CLICKED(IDC_CHECK_PUBLIC_TIMELINE2, OnCheckPublicTimeline2)
	ON_BN_CLICKED(IDC_CHECK_USER_TIMELINE2, OnCheckUserTimeline2)
	ON_BN_CLICKED(IDC_CHECK_FRIENDS_TIMELINE2, OnCheckFriendsTimeline2)
	ON_BN_CLICKED(IDC_CHECK_MULTIPOST, OnCheckMultiPost)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTabDialog ���b�Z�[�W �n���h��

void CTabDialog::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
    if ( bShow ) {
        LoadSetting();

        CEdit   *p = (CEdit *)GetDlgItem(IDC_EDIT_USERNAME);
        p->SetWindowText( m_username );

        p = (CEdit *)GetDlgItem(IDC_EDIT_PASSWORD);
        p->SetWindowText( m_password );

        CButton *bp = (CButton *)GetDlgItem( IDC_CHECK_MULTIPOST );
        bp->SetCheck( m_checkMultiPost );

        p = (CEdit *)GetDlgItem(IDC_EDIT_LOGFILENAME);
        p->SetWindowText( m_logFile_friendsTimeline );

        p = (CEdit *)GetDlgItem(IDC_EDIT_LOGFILENAME2);
        p->SetWindowText( m_logFile_publicTimeline );

        p = (CEdit *)GetDlgItem(IDC_EDIT_LOGFILENAME3);
        p->SetWindowText( m_logFile_userTimeline );

        bp = (CButton *)GetDlgItem( IDC_CHECK_FRIENDS_TIMELINE );
        bp->SetCheck( m_checkFriendsTimeline );
        
        bp = (CButton *)GetDlgItem( IDC_CHECK_PUBLIC_TIMELINE );
        bp->SetCheck( m_checkPublicTimeline );
        
        bp = (CButton *)GetDlgItem( IDC_CHECK_USER_TIMELINE );
        bp->SetCheck( m_checkUserTimeline );

        bp = (CButton *)GetDlgItem( IDC_CHECK_FRIENDS_TIMELINE2 );
        bp->SetCheck( m_checkLogFileFriendsTimeline );
        
        bp = (CButton *)GetDlgItem( IDC_CHECK_PUBLIC_TIMELINE2 );
        bp->SetCheck( m_checkLogFilePublicTimeline );
        
        bp = (CButton *)GetDlgItem( IDC_CHECK_USER_TIMELINE2 );
        bp->SetCheck( m_checkLogFileUserTimeline );

        SetCheckFriendsTimeline();
        SetCheckPublicTimeline();
        SetCheckUserTimeline();

        m_initialized = true;
    }
    else {
        CEdit   *p = (CEdit *)GetDlgItem(IDC_EDIT_USERNAME);
        p->GetWindowText( m_username );

        p = (CEdit *)GetDlgItem(IDC_EDIT_PASSWORD);
        p->GetWindowText( m_password );

        p = (CEdit *)GetDlgItem(IDC_EDIT_LOGFILENAME);
        p->GetWindowText( m_logFile_friendsTimeline );

        p = (CEdit *)GetDlgItem(IDC_EDIT_LOGFILENAME2);
        p->GetWindowText( m_logFile_publicTimeline );

        p = (CEdit *)GetDlgItem(IDC_EDIT_LOGFILENAME3);
        p->GetWindowText( m_logFile_userTimeline );
    }
}

void CTabDialog::OnButtonFilespec() 
{
    InputFileName( m_logFile_friendsTimeline, IDC_EDIT_LOGFILENAME );
}

void CTabDialog::OnButtonFilespec2() 
{
    InputFileName( m_logFile_publicTimeline, IDC_EDIT_LOGFILENAME2 );
}

void CTabDialog::OnButtonFilespec3() 
{
    InputFileName( m_logFile_userTimeline, IDC_EDIT_LOGFILENAME3 );
}


void CTabDialog::OnCheckFriendsTimeline() 
{
    CButton *bp = (CButton *)GetDlgItem( IDC_CHECK_FRIENDS_TIMELINE );
    m_checkFriendsTimeline = bp->GetCheck();

    SetCheckFriendsTimeline();
}

void CTabDialog::OnCheckPublicTimeline() 
{
    CButton *bp = (CButton *)GetDlgItem( IDC_CHECK_PUBLIC_TIMELINE );
    m_checkPublicTimeline = bp->GetCheck();

    SetCheckPublicTimeline();
}

void CTabDialog::OnCheckUserTimeline() 
{
    CButton *bp = (CButton *)GetDlgItem( IDC_CHECK_USER_TIMELINE );
    m_checkUserTimeline = bp->GetCheck();

    SetCheckUserTimeline();
}

void CTabDialog::OnCheckFriendsTimeline2() 
{
    CButton *bp = (CButton *)GetDlgItem( IDC_CHECK_FRIENDS_TIMELINE2 );
    m_checkLogFileFriendsTimeline = bp->GetCheck();
}

void CTabDialog::OnCheckPublicTimeline2() 
{
    CButton *bp = (CButton *)GetDlgItem( IDC_CHECK_PUBLIC_TIMELINE2 );
    m_checkLogFilePublicTimeline = bp->GetCheck();
}

void CTabDialog::OnCheckUserTimeline2() 
{
    CButton *bp = (CButton *)GetDlgItem( IDC_CHECK_USER_TIMELINE2 );
    m_checkLogFileUserTimeline = bp->GetCheck();
}

void CTabDialog::OnCheckMultiPost() 
{
    CButton *bp = (CButton *)GetDlgItem( IDC_CHECK_MULTIPOST );
    m_checkMultiPost = bp->GetCheck();
}
