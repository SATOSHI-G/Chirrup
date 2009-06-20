/*
 * SettingDialog.cpp : Twitter �N���C�A���g chirrup
 *      �ݒ�_�C�A���O(����) �C���v�������e�[�V���� �t�@�C��
 *          written by H.Tsujimura  7 Jun 2007
 *
 *      Copyright (c) 2007, 2008 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/SettingDialog.cpp $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 20    08/12/19 20:53 Tsujimura543
 * CheckDlgData() ������ CSettingProxy �� UpdateDataEx() ��
 * �Ăяo���悤�ɂ��Ă݂�
 * 
 * 19    08/08/22 18:41 Tsujimura543
 * �u�͂Ăȃn�C�N�v�Ή�
 * 
 * 18    08/07/08 16:56 Tsujimura543
 * �c�����ɏ��������鏈�������������
 * 
 * 17    08/07/08 15:41 Tsujimura543
 * �f�B�X�v���C�̏c�����̑傫��(����)�� 800px �ȉ��̏ꍇ�́A�\������
 * �_�C�A���O�̑傫�����c�����ɏ���������悤�ɂ��Ă݂�
 * 
 * 16    08/01/19 0:37 Tsujimura543
 * (1) �u�������v �� �u������ / �͂Ăȁv �ɕύX
 * (2) �͂ĂȊ֘A�� CTabDialog2 �Ɉڍs
 * 
 * 15    08/01/10 19:22 Tsujimura543
 * CTabDialog2 �𓱓��A�R�[�h�𐮗�����
 * 
 * 14    08/01/09 17:08 Tsujimura543
 * Flickr �Ή�
 * 
 * 13    07/12/10 16:39 Tsujimura543
 * Gyazo �Ή�
 * 
 * 12    07/11/26 20:03 Tsujimura543
 * isNecessaryToCheckProxyInfo() ���g���āA�G���[�������̏���������������
 * 
 * 11    07/11/26 17:46 Tsujimura543
 * �uproxy�ݒ�v�^�u��active�ɂȂ��Ă����ԂŋN���ł���I�v�V������ǉ�
 * 
 * 10    07/11/26 17:31 Tsujimura543
 * �uproxy�ݒ�v���^�u�̂P�Ƃ��Ď�荞��
 * 
 * 9     07/11/26 16:02 Tsujimura543
 * ���t�@�N�^�����O
 * 
 * 8     07/11/05 23:35 Tsujimura543
 * tumblr �ɑΉ�
 * 
 * 7     07/08/25 0:14 Tsujimura543
 * �u�������v�ɑΉ�
 * 
 * 6     07/06/27 18:12 Tsujimura543
 * haru.fm �ɑΉ�
 * 
 * 5     07/06/20 14:06 Tsujimura543
 * Timelog �Ή���
 * 
 * 4     07/06/14 21:12 Tsujimura543
 * �u���������v�ɑΉ�
 * 
 * 3     07/06/14 16:58 Tsujimura543
 * Wassr �ɑΉ�
 * 
 * 2     07/06/07 15:47 Tsujimura543
 * CTabDialog �𓱓��A�R�[�h�𐮗����Ă݂�
 * 
 * 1     07/06/07 1:43 Tsujimura543
 * �V�K�쐬 (�^�u�I���`���̐ݒ�_�C�A���O��V���ɗp�ӂ���)
 */

#include "chirrup.h"
#include "chirrupDlg.h"
#include "SettingDialog.h"

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/chirrup/SettingDialog.cpp 1     09/05/14 3:50 tsupo $";
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSettingDialog �_�C�A���O

#define DISPLAY_HEIGHT_LIMIT    800

CSettingDialog::CSettingDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CSettingDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSettingDialog)
	//}}AFX_DATA_INIT

    m_dlg[CS_TWITTER]     = &m_dlg00;
    m_dlg[CS_JAIKU]       = &m_dlg01;
    m_dlg[CS_WASSR]       = &m_dlg02;
    m_dlg[CS_MOGO2]       = &m_dlg03;
    m_dlg[CS_TIMELOG]     = &m_dlg04;
    m_dlg[CS_HARUFM]      = &m_dlg05;
    m_dlg[CS_HATENAHAIKU] = &m_dlg06;
    m_dlg[CS_HATENA]      = &m_dlg07;
    m_dlg[CS_TUMBLR]      = &m_dlg08;
    m_dlg[CS_GYAZO]       = &m_dlg09;
    m_dlg[CS_FLICKR]      = &m_dlg10;
    m_dlg[CS_PROXY]       = &m_dlg11;

    m_numOfTabs    = 0;
    m_chirrup      = NULL;
    m_settingProxy = false;
    m_resized      = false;
}

void CSettingDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSettingDialog)
	DDX_Control(pDX, IDC_TAB_SETTING, m_tabSetting);
	//}}AFX_DATA_MAP
}

BOOL CSettingDialog::CheckDlgData()
{
    if ( m_activePage == CS_PROXY ) {
        BOOL    ret = ((CSettingProxy *)m_dlg[m_activePage])->UpdateDataEx();
        if ( ret == FALSE )
            return ( ret );
    }
    return ( m_dlg[m_activePage]->UpdateData() );
}

int CSettingDialog::DispCurrentTab( int activeTab /* = 0 */ )
{
    if ( activeTab != 0 )
        m_tabSetting.SetCurSel( activeTab );

    m_activePage = m_tabSetting.GetCurSel();
    int nPages   = m_tabSetting.GetItemCount();

    for ( int i = 0; i < nPages; i++ )
        if ( i != m_activePage )
            m_dlg[i]->ShowWindow( SW_HIDE );

    m_dlg[m_activePage]->ShowWindow( SW_SHOW );

    if ( (m_height <= DISPLAY_HEIGHT_LIMIT) && !m_resized ) {
        // �������T�C�Y�̃_�C�A���O��\������
        CRect   rcClient;
        int     tabSettingDiffY = 0;    // �^�u�̌��ˑ��ŕύX����K�v������
        int     clientDiffY     = tabSettingDiffY + 20; // 20 = �{�^���̌���(20px)

        GetClientRect( &rcClient );
        rcClient.bottom -= tabSettingDiffY;
        MoveWindow( &rcClient );

        m_tabSetting.GetWindowRect( &rcClient );
        rcClient.bottom -= clientDiffY;
        m_tabSetting.MoveWindow( &rcClient );

        m_resized = true;
    }

    return ( m_activePage );
}

BEGIN_MESSAGE_MAP(CSettingDialog, CDialog)
	//{{AFX_MSG_MAP(CSettingDialog)
	ON_BN_CLICKED(IDC_BUTTON_ACCEPT, OnButtonAccept)
	ON_WM_SIZE()
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSettingDialog ���b�Z�[�W �n���h��

BOOL CSettingDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

    if ( m_height <= DISPLAY_HEIGHT_LIMIT ) {
        int     height      = 0;
        int     width       = 0;
        int     buttonDiffX = 4;    // �{�^���ƃ{�^���̊�(������)�� 4px �󂯂�

        CRect   rectM;
        CButton *bp = (CButton *)GetDlgItem( IDOK );
     // if ( bp->GetSafeHwnd() && bp->IsWindowEnabled() ) {
            bp->GetWindowRect( &rectM );
            height = rectM.bottom - rectM.top;
            width  = rectM.right  - rectM.left;
            buttonDiffX += width;

            rectM.top    = m_base + 2;
            rectM.bottom = rectM.top + height;
            rectM.left   = (m_dialogWidth - (buttonDiffX * 3)) / 2 + 2;
            rectM.right  = rectM.left + width;
            bp->MoveWindow( rectM );
            bp->EnableWindow();

     // }

        CRect   rectM2;
        bp = (CButton *)GetDlgItem( IDCANCEL );
     // if ( bp->GetSafeHwnd() && bp->IsWindowEnabled() ) {
            bp->GetWindowRect( &rectM2 );
            height = rectM2.bottom - rectM2.top;
            width  = rectM2.right  - rectM2.left;
            rectM2.top    = rectM.top;
            rectM2.bottom = rectM2.top  + height;
            rectM2.left   = rectM.left  + buttonDiffX;
            rectM2.right  = rectM2.left + width;
            bp->MoveWindow( rectM2 );
            bp->EnableWindow();
     // }

        CRect   rectM3;
        bp = (CButton *)GetDlgItem( IDC_BUTTON_ACCEPT );
     // if ( bp->GetSafeHwnd() && bp->IsWindowEnabled() ) {
            bp->GetWindowRect( &rectM3 );
            height = rectM3.bottom - rectM3.top;
            width  = rectM3.right  - rectM3.left;
            rectM3.top    = rectM2.top;
            rectM3.bottom = rectM3.top  + height;
            rectM3.left   = rectM2.left + buttonDiffX;
            rectM3.right  = rectM3.left + width;
            bp->MoveWindow( rectM3 );
            bp->EnableWindow();
     // }
    }

    return TRUE;
}

void CSettingDialog::OnButtonAccept() 
{
    if ( CheckDlgData() == FALSE )
        return;

    switch ( m_activePage ) {
    case CS_HATENA:
    case CS_TUMBLR:
    case CS_GYAZO:
    case CS_FLICKR:
        ((CTabDialog2 *)m_dlg[m_activePage])->Accept();
        break;

    case CS_PROXY:
        ((CSettingProxy *)m_dlg[m_activePage])->Accept();
        break;

    default:
        ((CTabDialog *)m_dlg[m_activePage])->Accept();
        break;
    }
}

void CSettingDialog::OnOK() 
{
    int nPages = m_tabSetting.GetItemCount();

    CWaitCursor cur;    // �}�E�X�J�[�\���������v�\��
    for ( int i = 0; i < nPages; i++ ) {
        m_activePage = i;
        if ( CheckDlgData() == FALSE )
            return;
        OnButtonAccept();

        if ( isNecessaryToCheckProxyInfo() )
            RedrawWindow();
    }
	CDialog::OnOK();
}

#ifdef  _MSC_VER
#pragma warning ( disable: 4100 )
#endif
BOOL CSettingDialog::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
    LPNMHDR pNMHDR      = (LPNMHDR)lParam;
    int     nActivePage = -1;

    switch ( pNMHDR->code ) {
    case TCN_SELCHANGE:
        nActivePage = DispCurrentTab();
        break;
    }

    return ( TRUE );
}
#ifdef  _MSC_VER
#pragma warning ( default: 4100 )
#endif

void CSettingDialog::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);

    CRect   rcClient;
    GetClientRect( &rcClient );
    m_tabSetting.MoveWindow( &rcClient );

    CRect   rcTabCtrl;
    m_tabSetting.GetClientRect( &rcTabCtrl );

    int nPages = m_tabSetting.GetItemCount();
    int nRow   = m_tabSetting.GetRowCount();

    CRect   rcTabZero;
    m_tabSetting.GetItemRect( 0, &rcTabZero );

    int         iTabHeight = rcTabZero.Size().cy;
    const int   border     = 5;

    CRect   rcTabDisp;
    rcTabDisp.top    = iTabHeight * nRow + border;
    rcTabDisp.left   = border;
    rcTabDisp.right  = rcTabCtrl.right  - border;
    rcTabDisp.bottom = rcTabCtrl.bottom - border - 30;
    m_base           = rcTabDisp.bottom;
    m_dialogWidth    = rcTabCtrl.right - rcTabCtrl.left;

    for ( int i = 0; i < nPages; i++ )
        m_dlg[i]->MoveWindow( &rcTabDisp );
}

int CSettingDialog::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
    m_width  = GetSystemMetrics(SM_CXSCREEN);
    m_height = GetSystemMetrics(SM_CYSCREEN);

    BOOL    bResult;
    if ( m_height <= DISPLAY_HEIGHT_LIMIT )
        bResult = m_tabSetting.Create( WS_CHILD | WS_VISIBLE,
                                       CRect(0, 0, 0, 0), this,
                                       IDD_SETTING_DIALOG );
    else
        bResult = m_tabSetting.Create( WS_CHILD | WS_VISIBLE | TCS_MULTILINE,
                                       CRect(0, 0, 0, 0), this,
                                       IDD_SETTING_DIALOG );
    if ( bResult == FALSE )
		return ( -1 );

    // �e�^�u�̕����̐ݒ�
    TCITEM  tc;

    const char *title[] = {
        "Twitter",
        "Jaiku",
        "Wassr",
        "��������",
        "Timelog",
        "Haru.fm",
        "�͂Ăȃn�C�N",
        "������ / �͂Ă�",
        "tumblr",
        "Gyazo",
        "Flickr",
        "proxy�ݒ�",
        NULL
    };

    const char * const *p;
    for ( p = title; *p; p++ ) {
        tc.mask = TCIF_TEXT;
        tc.pszText = (char *)(*p);
        m_tabSetting.InsertItem( m_numOfTabs++, &tc );
    }

    ASSERT( m_numOfTabs == NUM_OF_TABS );

    // �f�t�H���g�̃^�u��I��
    m_tabSetting.SetCurSel( 0 );

    // �e�^�u�ɓ\��t����_�C�A���O�� Create
    LPCTSTR idd[] = {
        (LPCTSTR)IDD_TAB_TWITTER,
        (LPCTSTR)IDD_TAB_JAIKU,
        (LPCTSTR)IDD_TAB_WASSR,
        (LPCTSTR)IDD_TAB_MOGO2,
        (LPCTSTR)IDD_TAB_TIMELOG,
        (LPCTSTR)IDD_TAB_HARUFM,
        (LPCTSTR)IDD_TAB_HATENAHAIKU,
        (LPCTSTR)IDD_TAB_HATENA,
        (LPCTSTR)IDD_TAB_TUMBLR,
        (LPCTSTR)IDD_TAB_GYAZO,
        (LPCTSTR)IDD_TAB_FLICKR,
        (LPCTSTR)IDD_TAB_PROXY
    };

    for ( int i = 0; i < m_numOfTabs; i++ ) {
        bResult = m_dlg[i]->Create( idd[i], this );
        if ( bResult == FALSE )
    		return ( -1 );

        switch ( i ) {
        case CS_HATENA:
        case CS_TUMBLR:
        case CS_GYAZO:
        case CS_FLICKR:
            ((CTabDialog2 *)m_dlg[i])->m_chirrup = m_chirrup;
            break;

        case CS_PROXY:
            ((CSettingProxy *)m_dlg[i])->m_chirrup = m_chirrup;
            break;

        default:
            ((CTabDialog *)m_dlg[i])->m_chirrup = m_chirrup;
            break;
        }
    }

    // �f�t�H���g�̃^�u��\��
    m_activePage = m_settingProxy ? CS_PROXY : CS_TWITTER;
    DispCurrentTab( m_activePage );

	return ( 0 );
}
