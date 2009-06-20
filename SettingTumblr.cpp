/*
 * SettingTumblr.cpp : Twitter �N���C�A���g chirrup
 *      �ݒ�_�C�A���O(tumblr) �C���v�������e�[�V���� �t�@�C��
 *          written by H.Tsujimura  5 Nov 2007
 *
 *      Copyright (c) 2007, 2008, 2009 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/SettingTumblr.cpp $
 * 
 * 3     09/06/20 17:32 tsupo
 * 2.02��
 * 
 * 8     09/06/19 17:11 Tsujimura543
 * ���[�U��(���[���A�h���X)�ƃp�X���[�h��ݒ肵������Ɂu�ύX�v�{�^����
 * �����Ă��Atumbleblog �ꗗ���擾�ɍs���Ȃ��s��ɑΏ�
 * 
 * 2     09/05/31 20:42 tsupo
 * 1.142��
 * 
 * 7     09/05/29 19:22 Tsujimura543
 * ����A�J�E���g�ŕ��� tumbleblog ���J�݂��Ă���ꍇ�̓��e��
 * tumbleblog ���w�肵�Ă̓��e���\�ɂ���
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 6     08/01/18 23:54 Tsujimura543
 * CTabDialog2 �Ɉڍs���؂�Ă��Ȃ������Ƃ�������S�Ɉڍs������
 * 
 * 5     08/01/10 19:21 Tsujimura543
 * CTabDialog2 �𓱓��A�R�[�h�𐮗�����
 * 
 * 4     07/12/19 19:06 Tsujimura543
 * OnShowWindow() ���� IDC_WRITE_LOGFILE ���W�I�{�^���̏�Ԃ��A�N�����_
 * �̐ݒ�l�Ɋ�Â��ĕ\�����鏈���������Ă���
 * 
 * 3     07/12/19 16:12 Tsujimura543
 * Tumblr �� Gyazo �ɃA�b�v���[�h�����t�@�C���� URL ���L�^����@�\��
 * �ǉ����邽�߂̃v���p�e�B��ǉ�
 * 
 * 2     07/12/06 1:58 Tsujimura543
 * tumblr �ւ̉摜�̓��e�ɑΉ�
 * 
 * 1     07/11/05 23:35 Tsujimura543
 * �ŏ��̔�
 */

#include "chirrup.h"
#include "tumblr.h"
#include "chirrupDlg.h"
#include "SettingTumblr.h"
#include "BlogIDSelectDlg.h"

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/chirrup/SettingTumblr.cpp 3     09/06/20 17:32 tsupo $";
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSettingTumblr �_�C�A���O

CSettingTumblr::CSettingTumblr(CWnd* pParent /*=NULL*/)
	: CTabDialog2(CSettingTumblr::IDD, pParent)
{
    m_blogID = _T("");

	//{{AFX_DATA_INIT(CSettingTumblr)
	m_useTumblr = FALSE;
	m_username = _T("");
	m_password = _T("");
	m_blogName = _T("");
	//}}AFX_DATA_INIT
}

// �u�ݒ�_�C�A���O�v�ł́u�K�p�v�{�^������������
void CSettingTumblr::Accept()
{
    if ( m_initialized && m_chirrup ) {
        m_chirrup->SetTumblr( m_username, m_password,
                              m_blogID, m_blogName,
                              m_useTumblr, m_applied,
                              m_writeLogfile, m_logFilename );
    }
}

// ���݂́u�ݒ�v���擾
void CSettingTumblr::LoadSetting()
{
    if ( !m_initialized ) {
        if ( m_chirrup ) {
            m_chirrup->GetTumblr( m_username, m_password,
                                  m_blogID, m_blogName,
                                  m_useTumblr, m_applied,
                                  m_writeLogfile, m_logFilename );
        }
    }
}

void CSettingTumblr::DoDataExchange(CDataExchange* pDX)
{
	CTabDialog2::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSettingTumblr)
	DDX_Check(pDX, IDC_USE_TUMBLR, m_useTumblr);
	DDX_Text(pDX, IDC_EDIT_USERNAME, m_username);
	DDV_MaxChars(pDX, m_username, 64);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_password);
	DDV_MaxChars(pDX, m_password, 64);
	DDX_Text(pDX, IDC_EDIT_BLOGNAME, m_blogName);
	DDV_MaxChars(pDX, m_blogName, 256);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSettingTumblr, CTabDialog2)
	//{{AFX_MSG_MAP(CSettingTumblr)
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(IDC_USE_TUMBLR, OnUseTumblr)
	ON_BN_CLICKED(IDC_APPLIED, OnApplied)
	ON_BN_CLICKED(IDC_BUTTON_SELECT_TARGET, OnButtonSelectTarget)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSettingTumblr �ǉ����\�b�h

void CSettingTumblr::SetCheckApplied()
{
    CEdit   *p = (CEdit *)GetDlgItem(IDC_EDIT_USERNAME);
    p->EnableWindow( m_useTumblr || m_applied );

    p = (CEdit *)GetDlgItem(IDC_EDIT_PASSWORD);
    p->EnableWindow( m_useTumblr || m_applied );

    CButton *bp = (CButton *)GetDlgItem(IDC_BUTTON_SELECT_TARGET);
    bp->EnableWindow( m_useTumblr || m_applied );

    bp = (CButton *)GetDlgItem(IDC_WRITE_LOGFILE);
    bp->EnableWindow( m_applied );

    SetCheckWriteLogfile();
}

/////////////////////////////////////////////////////////////////////////////
// CSettingTumblr ���b�Z�[�W �n���h��

void CSettingTumblr::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CTabDialog2::OnShowWindow(bShow, nStatus);

    if ( bShow ) {
        CEdit   *p = (CEdit *)GetDlgItem(IDC_EDIT_USERNAME);
        p->SetWindowText( m_username );

        p = (CEdit *)GetDlgItem(IDC_EDIT_PASSWORD);
        p->SetWindowText( m_password );

        if ( m_blogID.GetLength() == 0 )
            m_blogName.LoadString(IDS_DEFAULT_TARGET);
        p = (CEdit *)GetDlgItem( IDC_EDIT_BLOGNAME );
        p->SetWindowText( m_blogName );

        CButton *bp = (CButton *)GetDlgItem( IDC_USE_TUMBLR );
        bp->SetCheck( m_useTumblr );

        SetCheckApplied();
    }
    else {
        CEdit   *p = (CEdit *)GetDlgItem(IDC_EDIT_USERNAME);
        p->GetWindowText( m_username );

        p = (CEdit *)GetDlgItem(IDC_EDIT_PASSWORD);
        p->GetWindowText( m_password );
    }
}

void CSettingTumblr::OnUseTumblr() 
{
    CButton *bp = (CButton *)GetDlgItem( IDC_USE_TUMBLR );
    m_useTumblr = bp->GetCheck();

    SetCheckApplied();
}

void CSettingTumblr::OnApplied() 
{
    CButton *bp = (CButton *)GetDlgItem( IDC_APPLIED );
    m_applied = bp->GetCheck();

    SetCheckApplied();
}

void CSettingTumblr::OnButtonSelectTarget() 
{
    CBlogIDSelectDlg    dlg;
    int                 r;
    BLOGINF             blogInfo[MAX_BLOGS];
    int                 numOfBlogs = MAX_BLOGS;

    CWaitCursor cur;    // �}�E�X�J�[�\���������v�\��

    CEdit   *p = (CEdit *)GetDlgItem(IDC_EDIT_USERNAME);
    p->GetWindowText( m_username );

    p = (CEdit *)GetDlgItem(IDC_EDIT_PASSWORD);
    p->GetWindowText( m_password );

    r = getBlogIDsTumblr( m_username, m_password,
                          &numOfBlogs, blogInfo );
    if ( r <= 0 )
        return;

    m_blogID   = blogInfo[0].blogID;    // primary Blog
    m_blogName = blogInfo[0].blogName;  // primary Blog

    if ( r > 1 ) {
        dlg.initialize( blogInfo, numOfBlogs );
        int res = dlg.DoModal();
        if ( (res == IDOK) && (dlg.m_blogIDlistIndex != -1) ) {
            if ( (dlg.m_blogIDlistIndex >= 0)         &&
                 (dlg.m_blogIDlistIndex < numOfBlogs)    ) {
                r = dlg.m_blogIDlistIndex;

                m_blogID   = blogInfo[r].blogID;
                m_blogName = blogInfo[r].blogName;
            }
        }
    }

    p = (CEdit *)GetDlgItem( IDC_EDIT_BLOGNAME );
    p->SetWindowText( m_blogName );
}
