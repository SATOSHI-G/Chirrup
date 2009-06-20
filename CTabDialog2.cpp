/*
 * CTabDialog2.cpp : Twitter �N���C�A���g chirrup
 *      �ݒ�_�C�A���O2(�^�u�\��t����������) �C���v�������e�[�V���� �t�@�C��
 *          written by H.Tsujimura  10 Dec 2007 / 10 Jan 2008
 *
 *      Copyright (c) 2007, 2008 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/CTabDialog2.cpp $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 1     08/01/10 17:21 Tsujimura543
 * ��SettingGyazo.cpp�����ɐV�K�쐬 (SettingGyazo, SettingFlickr�̋��ʕ�
 * ����ێ�����N���X�Ƃ��Đ݌v�B����̑Ή��T�[�r�X�����������ł��e�Ղ�
 * ����ړI������)
 */

#include "chirrup.h"
#include "chirrupDlg.h"
#include "CTabDialog2.h"

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/chirrup/CTabDialog2.cpp 1     09/05/14 3:50 tsupo $";
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTabDialog2 �_�C�A���O

CTabDialog2::CTabDialog2( UINT nIDTemplate, CWnd* pParentWnd )
	: CDialog(nIDTemplate, pParentWnd)
{
	//{{AFX_DATA_INIT(CTabDialog2)
	m_applied = FALSE;
	m_writeLogfile = FALSE;
	m_logFilename = _T("");
	//}}AFX_DATA_INIT

    m_initialized = false;
    m_chirrup     = NULL;
}

void CTabDialog2::InputFileName( CString &targetFilename, int id )
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

void    CTabDialog2::SetCheckApplied()
{
    CButton *bp = (CButton *)GetDlgItem(IDC_WRITE_LOGFILE);
    bp->EnableWindow( m_applied );

    SetCheckWriteLogfile();
}

void    CTabDialog2::SetCheckWriteLogfile()
{
    CEdit   *ep = (CEdit *)GetDlgItem(IDC_EDIT_LOGFILENAME);
    ep->EnableWindow( m_applied && m_writeLogfile );
}

void CTabDialog2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTabDialog2)
	DDX_Check(pDX, IDC_APPLIED, m_applied);
	DDX_Check(pDX, IDC_WRITE_LOGFILE, m_writeLogfile);
	DDX_Text(pDX, IDC_EDIT_LOGFILENAME, m_logFilename);
	DDV_MaxChars(pDX, m_logFilename, 256);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTabDialog2, CDialog)
	//{{AFX_MSG_MAP(CTabDialog2)
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(IDC_BUTTON_FILESPEC, OnButtonFilespec)
	ON_BN_CLICKED(IDC_APPLIED, OnApplied)
	ON_BN_CLICKED(IDC_WRITE_LOGFILE, OnWriteLogfile)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTabDialog2 ���b�Z�[�W �n���h��

void CTabDialog2::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);

    if ( bShow ) {
        LoadSetting();

        CButton *bp = (CButton *)GetDlgItem( IDC_APPLIED );
        bp->SetCheck( m_applied );

        bp = (CButton *)GetDlgItem( IDC_WRITE_LOGFILE );
        bp->SetCheck( m_writeLogfile );

        CEdit   *ep = (CEdit *)GetDlgItem(IDC_EDIT_LOGFILENAME);
        ep->SetWindowText( m_logFilename );

        SetCheckApplied();

        m_initialized = true;
    }
    else {
        CEdit   *ep = (CEdit *)GetDlgItem(IDC_EDIT_LOGFILENAME);
        ep->GetWindowText( m_logFilename );
    }
}

void CTabDialog2::OnApplied() 
{
    CButton *bp = (CButton *)GetDlgItem( IDC_APPLIED );
    m_applied = bp->GetCheck();

    SetCheckApplied();
}

void CTabDialog2::OnWriteLogfile() 
{
    CButton *bp = (CButton *)GetDlgItem( IDC_WRITE_LOGFILE );
    m_writeLogfile = bp->GetCheck();

    SetCheckWriteLogfile();
}

void CTabDialog2::OnButtonFilespec() 
{
    InputFileName( m_logFilename, IDC_EDIT_LOGFILENAME );
}
