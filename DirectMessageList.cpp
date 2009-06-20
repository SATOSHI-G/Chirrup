/*
 * DirectMessageList.cpp : Twitter �N���C�A���g chirrup
 *      �_�C���N�g���b�Z�[�{���_�C�A���O �C���v�������e�[�V���� �t�@�C��
 *          written by H.Tsujimura  25 Apr 2007
 *
 *      Copyright (c) 2007 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/DirectMessageList.cpp $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 13    09/03/31 23:29 Tsujimura543
 * Twitter �� OAuth �Ή����� ����7
 * 
 * 12    07/09/26 20:05 Tsujimura543
 * �_�C���N�g���b�Z�[�W�\���_�C�A���O����уv���t�B�[���\���_�C�A���O
 * �\���������C���_�C�A���O�̃X�e�[�^�X�o�[���X�V����悤�ɂ���
 * (�X�e�[�^�X�o�[�������낤�Ƃ���null�|�C���^�Q�Ƃŗ�����o�O�����)
 * 
 * 11    07/08/31 18:21 Tsujimura543
 * Twitter �̃_�C���N�g���b�Z�[�W�̃^�C���X�^���v��GMT�̂܂ܕ\������Ă���
 * ���Ƃ������BJST�ŕ\������悤�ɏC��
 * 
 * 10    07/06/22 17:42 Tsujimura543
 * �u��M�ҁv���\������悤�ɂ���
 * 
 * 9     07/06/21 22:11 Tsujimura543
 * Timelog �̃_�C���N�g���b�Z�[�W�̑���M�ɑΉ� (����m�F�ς�)
 * 
 * 8     07/06/21 20:34 Tsujimura543
 * Timelog �ɑΉ�
 * 
 * 7     07/06/21 20:26 Tsujimura543
 * Twitter�ȊO�ɂ��Ή�(�ł���悤�ɂ���)
 * 
 * 6     07/06/13 15:53 Tsujimura543
 * �_�C���N�g���b�Z�[�W�̍폜�@�\��ǉ�
 * 
 * 5     07/04/27 19:39 Tsujimura543
 * Twitter API �֘A�̏����� Twitter.cpp �ɏW�񂵂��̂ɔ����C�������{
 * 
 * 4     07/04/26 20:59 Tsujimura543
 * ���t�@�N�^�����O
 * 
 * 3     07/04/26 20:42 Tsujimura543
 * ���t�@�N�^�����O
 * 
 * 2     07/04/26 20:40 Tsujimura543
 * �_�C���N�g���b�Z�[�W�̖{���� URL ���܂܂��ꍇ�A�N���b�N�ł���悤�ɂ���
 * 
 * 1     07/04/26 0:20 Tsujimura543
 * �V�K�쐬
 */

#include "chirrup.h"
#include "chirrupDlg.h"
#include "timelog.h"
#include "DirectMessageList.h"
#include "DirectMessage.h"

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/chirrup/DirectMessageList.cpp 1     09/05/14 3:50 tsupo $";
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDirectMessageList �_�C�A���O

CDirectMessageList::CDirectMessageList(CWnd* pParent /*=NULL*/)
	: CDialog(CDirectMessageList::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDirectMessageList)
	m_sender = _T("");
	m_dateTime = _T("");
	m_recipient = _T("");
	//}}AFX_DATA_INIT

    m_dm   = NULL;
	m_text = _T("");
    m_numOfMessages    = 0;
    m_currentIndex     = 0;
    m_useOAuth         = false;
    m_oauthToken       = _T("");
    m_oauthTokenSecret = _T("");

    m_serviceType      = CTwitterTimeline::SVC_TWITTER;
}

void CDirectMessageList::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDirectMessageList)
	DDX_Control(pDX, IDC_EDIT_TEXT, m_textCtrl);
	DDX_Text(pDX, IDC_EDIT_SENDER, m_sender);
	DDV_MaxChars(pDX, m_sender, 160);
	DDX_Text(pDX, IDC_EDIT_DATETIME, m_dateTime);
	DDV_MaxChars(pDX, m_dateTime, 160);
	DDX_Text(pDX, IDC_EDIT_RECIPIENT, m_recipient);
	DDV_MaxChars(pDX, m_recipient, 160);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDirectMessageList, CDialog)
	//{{AFX_MSG_MAP(CDirectMessageList)
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(IDC_BUTTON_NEXT, OnButtonNext)
	ON_BN_CLICKED(IDC_BUTTON_PREV, OnButtonPrev)
	ON_BN_CLICKED(IDC_BUTTON_REPLY, OnButtonReply)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_WM_SETCURSOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void    CDirectMessageList::DisplayDirectMessage( int index )
{
    if ( !m_dm || (m_numOfMessages == 0) )
        return;

    const char  *format = "%Y�N%m��%d�� %H��%M��%S�b";
    if ( m_serviceType == CTwitterTimeline::SVC_TWITTER )
        m_dateTime = m_dm[index].createdAt.Format( format );
    else
        m_dateTime = m_dm[index].createdAt.FormatGmt( format );
    m_sender    = m_dm[index].sender.screenName;
    m_recipient = m_dm[index].recipient.screenName;
    m_text      = m_dm[index].text;

    CEdit   *p = (CEdit *)GetDlgItem( IDC_EDIT_DATETIME );
    p->SetWindowText( m_dateTime );

    p = (CEdit *)GetDlgItem( IDC_EDIT_SENDER );
    p->SetWindowText( m_sender );
    p = (CEdit *)GetDlgItem( IDC_EDIT_RECIPIENT );
    p->SetWindowText( m_recipient );

    CButton *bp;
    bp = (CButton *)GetDlgItem( IDC_BUTTON_PREV );
    bp->EnableWindow( index == 0 ? FALSE : TRUE );

    bp = (CButton *)GetDlgItem( IDC_BUTTON_NEXT );
    bp->EnableWindow( index == m_numOfMessages - 1 ? FALSE : TRUE );

    char    temp[BUFSIZ * 2];
    sprintf( temp, "�_�C���N�g���b�Z�[�W (%d ������ %d ����)",
             m_numOfMessages, index + 1 );
    SetWindowText( temp );

    bp = (CButton *)GetDlgItem( IDC_BUTTON_DELETE );
    if ( m_dm[index].deleted ) {
        bp->EnableWindow( FALSE );
        m_textCtrl.SetReadOnly( TRUE );
        m_textCtrl.EnableWindow( FALSE );
    }
    else {
        bp->EnableWindow( TRUE );
        m_textCtrl.SetReadOnly( FALSE );
        m_textCtrl.EnableWindow( TRUE );
    }
    if ( m_serviceType != CTwitterTimeline::SVC_TWITTER )
        bp->EnableWindow( FALSE );

    bp = (CButton *)GetDlgItem( IDC_BUTTON_REPLY );
    if ( !m_sender.Compare( m_screenName ) )
        bp->EnableWindow( FALSE );
    else
        bp->EnableWindow( TRUE );

    m_textCtrl.SetWindowText( m_text );
    m_textCtrl.SetFocus();
}

/////////////////////////////////////////////////////////////////////////////
// CDirectMessageList ���b�Z�[�W �n���h��

void CDirectMessageList::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);

    if ( bShow ) {
        m_textCtrl.SetAutoUrlDetect();
    	DisplayDirectMessage( m_currentIndex );
    }
}

void CDirectMessageList::OnButtonNext() 
{
    if ( m_currentIndex < m_numOfMessages - 1 ) {
        m_currentIndex++;
    	DisplayDirectMessage( m_currentIndex );
    }
}

void CDirectMessageList::OnButtonPrev() 
{
    if ( m_currentIndex >= 1 ) {
        m_currentIndex--;
    	DisplayDirectMessage( m_currentIndex );
    }
}

void CDirectMessageList::OnButtonReply() 
{
    CDirectMessage  dlg;

    dlg.m_serviceType      = m_serviceType;
    dlg.m_username         = m_username;
    dlg.m_password         = m_password;
    dlg.m_useOAuth         = m_useOAuth;
    dlg.m_oauthToken       = m_oauthToken;
    dlg.m_oauthTokenSecret = m_oauthTokenSecret;
    dlg.m_user             = m_dm[m_currentIndex].sender;
    dlg.m_cacheDir         = m_cacheDir;
    dlg.DoModal();
}

void CDirectMessageList::OnButtonDelete() 
{
    int ret = MessageBox( "���̃_�C���N�g���b�Z�[�W���폜���܂���?  ",
                          "�_�C���N�g���b�Z�[�W�폜",
                          MB_YESNO|MB_ICONQUESTION );

    if ( ret == IDYES ) {
        CWaitCursor cur;    // �}�E�X�J�[�\���������v�\��

        if ( m_serviceType == CTwitterTimeline::SVC_TWITTER ) {
            CTwitter    t;
            t.m_username = m_username;
            t.m_password = m_password;
            t.m_useOAuth = m_useOAuth;
            t.m_oauthToken       = m_oauthToken;
            t.m_oauthTokenSecret = m_oauthTokenSecret;

            t.DeleteDirectMessage(m_dm[m_currentIndex].id);
        }
        else if ( m_serviceType == CTwitterTimeline::SVC_TIMELOG ) {
            CTimelog    t;
            t.m_username = m_username;
            t.m_password = m_password;

            t.DeleteDirectMessage(m_dm[m_currentIndex].id);
        }

        m_dm[m_currentIndex].deleted = true;

        CButton *bp = (CButton *)GetDlgItem( IDC_BUTTON_DELETE );
        bp->EnableWindow( FALSE );
        m_textCtrl.SetReadOnly( TRUE );
        m_textCtrl.EnableWindow( FALSE );
    }
}

BOOL CDirectMessageList::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
    m_textCtrl.m_chirrupDlg->SetPaneText( 0, _T(" ") );
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}
