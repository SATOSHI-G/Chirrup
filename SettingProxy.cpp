/*
 * SettingProxy.cpp : Twitter �N���C�A���g chirrup
 *      �ݒ�_�C�A���O(proxy�ݒ�) �C���v�������e�[�V���� �t�@�C��
 *          written by H.Tsujimura  9 Mar 2007 / 6 Apr 2007 / 26 Nov 2007
 *
 *      Copyright (c) 2007 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/SettingProxy.cpp $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 6     08/12/19 21:27 Tsujimura543
 * �܂� m_initialized �� false �̏�Ԃ� UpdateDataEx() ���Ăяo���ꂽ
 * �ꍇ�̂��Ƃ��l������悤�ɂ���
 * 
 * 5     08/12/19 20:50 Tsujimura543
 * UpdateDataEx() ��ǉ�
 * 
 * 4     08/07/14 17:56 Tsujimura543
 * m_proxyPortNumber �ɕ��̒l�������Ă����ԂŃ_�C�A���O��
 * �Ăяo���ꂽ�ꍇ�́A�������� m_proxyPortNumber �� 0 �ɂ���
 * �悤�ɂ���
 * 
 * 3     07/11/26 18:04 Tsujimura543
 * proxy�ݒ�֘A�ڍs��ƁA����
 * 
 * 2     07/11/26 17:57 Tsujimura543
 * CProxyInfoDialog ��p�~���ACSettingProxy �Ɉڍs
 * 
 * 1     07/11/26 17:30 Tsujimura543
 * �ŏ��̔�
 */

#include "chirrup.h"
#include "chirrupDlg.h"
#include "SettingProxy.h"

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/chirrup/SettingProxy.cpp 1     09/05/14 3:50 tsupo $";
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSettingProxy �_�C�A���O

CSettingProxy::CSettingProxy(CWnd* pParent /*=NULL*/)
	: CDialog(CSettingProxy::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSettingProxy)
	m_useProxy = FALSE;
	m_proxyServerName = _T("");
	m_proxyPortNumber = 0;
	m_proxyUserName = _T("");
	m_proxyPassword = _T("");
	//}}AFX_DATA_INIT

    m_initialized = false;
    m_chirrup     = NULL;
}

// �u�ݒ�_�C�A���O�v�ł́u�K�p�v�{�^������������
void CSettingProxy::Accept()
{
    if ( m_initialized && m_chirrup ) {
        m_chirrup->SetProxy( m_useProxy,
                             m_proxyServerName, m_proxyPortNumber,
                             m_proxyUserName, m_proxyPassword );
    }
}

// ���݂́u�ݒ�v���擾
void CSettingProxy::LoadSetting()
{
    if ( !m_initialized ) {
        if ( m_chirrup ) {
            m_chirrup->GetProxy( m_useProxy,
                                 m_proxyServerName, m_proxyPortNumber,
                                 m_proxyUserName, m_proxyPassword );
        }
    }
}

// �ݒ肵�悤�Ƃ��Ă���l�̃`�F�b�N
BOOL CSettingProxy::UpdateDataEx()
{
    if ( !m_initialized )
        return ( TRUE );

    BOOL    ret = TRUE;
    CString str;
    CEdit   *p = (CEdit *)GetDlgItem(IDC_EDIT_PROXY_PORT_NUMBER);
    p->GetWindowText( str );

    int portNumber =
        (str.GetLength() > 0) && (str[0] >= '1') && (str[0] <= '9')
            ? (unsigned int)atol( str )
            : -1;
    if ( portNumber == -1 ) {
        MessageBox( "proxy�T�[�o�̃|�[�g�ԍ��� 0 �` 65535 �͈̔͂̐�����"
                    "�w�肵�Ă�������  ",
                    "proxy�T�[�o�̃|�[�g�ԍ�",
                    MB_OK|MB_ICONWARNING );
        ret = FALSE;
    }

    return ( ret );
}

void CSettingProxy::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSettingProxy)
	DDX_Check(pDX, IDC_USE_PROXY, m_useProxy);
	DDX_Text(pDX, IDC_EDIT_PROXY_SERVER_NAME, m_proxyServerName);
	DDV_MaxChars(pDX, m_proxyServerName, 384);
	DDX_Text(pDX, IDC_EDIT_PROXY_PORT_NUMBER, m_proxyPortNumber);
	DDV_MinMaxUInt(pDX, m_proxyPortNumber, 0, 65535);
	DDX_Text(pDX, IDC_EDIT_PROXY_USER_NAME, m_proxyUserName);
	DDV_MaxChars(pDX, m_proxyUserName, 32);
	DDX_Text(pDX, IDC_EDIT_PROXY_PASSWORD, m_proxyPassword);
	DDV_MaxChars(pDX, m_proxyPassword, 32);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSettingProxy, CDialog)
	//{{AFX_MSG_MAP(CSettingProxy)
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(IDC_USE_PROXY, OnUseProxy)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSettingProxy �ǉ����\�b�h

void CSettingProxy::SetCheckProxy()
{
    CEdit   *p = (CEdit *)GetDlgItem(IDC_EDIT_PROXY_SERVER_NAME);
    p->EnableWindow( m_useProxy );

    p = (CEdit *)GetDlgItem(IDC_EDIT_PROXY_PORT_NUMBER);
    p->EnableWindow( m_useProxy );

    p = (CEdit *)GetDlgItem(IDC_EDIT_PROXY_USER_NAME);
    p->EnableWindow( m_useProxy );

    p = (CEdit *)GetDlgItem(IDC_EDIT_PROXY_PASSWORD);
    p->EnableWindow( m_useProxy );
}

/////////////////////////////////////////////////////////////////////////////
// CSettingProxy ���b�Z�[�W �n���h��

void CSettingProxy::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);

    if ( bShow ) {
        LoadSetting();

        CEdit   *p = (CEdit *)GetDlgItem(IDC_EDIT_PROXY_SERVER_NAME);
        p->SetWindowText( m_proxyServerName );

        char    str[BUFSIZ];
        str[0] = NUL;
        if ( m_proxyPortNumber > 0 )
            sprintf( str, "%d", m_proxyPortNumber );
        else                        /* {@@} */
            m_proxyPortNumber = 0;  /* {@@} */
        p = (CEdit *)GetDlgItem(IDC_EDIT_PROXY_PORT_NUMBER);
        p->SetWindowText( str );

        p = (CEdit *)GetDlgItem(IDC_EDIT_PROXY_USER_NAME);
        p->SetWindowText( m_proxyUserName );

        p = (CEdit *)GetDlgItem(IDC_EDIT_PROXY_PASSWORD);
        p->SetWindowText( m_proxyPassword );

        CButton *bp = (CButton *)GetDlgItem( IDC_USE_PROXY );
        bp->SetCheck( m_useProxy );

        SetCheckProxy();

        m_initialized = true;
    }
    else {
        CEdit   *p = (CEdit *)GetDlgItem(IDC_EDIT_PROXY_SERVER_NAME);
        p->GetWindowText( m_proxyServerName );

        CString str;
        p = (CEdit *)GetDlgItem(IDC_EDIT_PROXY_PORT_NUMBER);
        p->GetWindowText( str );
        m_proxyPortNumber = (unsigned int)atol( str );

        p = (CEdit *)GetDlgItem(IDC_EDIT_PROXY_USER_NAME);
        p->GetWindowText( m_proxyUserName );

        p = (CEdit *)GetDlgItem(IDC_EDIT_PROXY_PASSWORD);
        p->GetWindowText( m_proxyPassword );
    }
}

void CSettingProxy::OnUseProxy() 
{
    CButton *bp = (CButton *)GetDlgItem( IDC_USE_PROXY );
    m_useProxy  = bp->GetCheck();

    SetCheckProxy();
}
