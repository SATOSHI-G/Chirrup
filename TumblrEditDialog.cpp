/*
 * TumblrEditDialog.cpp : Twitter �N���C�A���g chirrup
 *      Tumblr(�� Quote)���e���e�ҏW�_�C�A���O �C���v�������e�[�V���� �t�@�C��
 *          written by H.Tsujimura  6 Nov 2007
 *
 *      Copyright (c) 2007, 2008, 2009 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/TumblrEditDialog.cpp $
 * 
 * 3     09/05/31 20:42 tsupo
 * 1.142��
 * 
 * 6     09/05/29 19:22 Tsujimura543
 * ����A�J�E���g�ŕ��� tumbleblog ���J�݂��Ă���ꍇ�̓��e��
 * tumbleblog ���w�肵�Ă̓��e���\�ɂ���
 * 
 * 2     09/05/27 1:29 tsupo
 * xmlRPC 1.266�őΉ�
 * 
 * 5     09/05/26 18:08 Tsujimura543
 * URL �n�[�h�R�[�f�B���O�ӏ������炵��
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 4     09/03/12 19:26 Tsujimura543
 * CTumblrEditDialog �_�C�A���O���d�N���ł��Ȃ��悤�ɂ���
 * 
 * 3     09/03/10 17:48 Tsujimura543
 * CTumblrEditDialog �����[�_���_�C�A���O���烂�[�h���X�_�C�A���O�ɕύX
 * 
 * 2     08/02/12 23:21 Tsujimura543
 * �u�R�����g�v����ǉ�
 * 
 * 1     07/11/06 21:46 Tsujimura543
 * �ŏ��̔�
 */

#include "chirrup.h"
#include "TumblrEditDialog.h"
extern "C" {
#include "tumblr.h"
}

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/chirrup/TumblrEditDialog.cpp 3     09/05/31 20:42 tsupo $";
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTumblrEditDialog �_�C�A���O

CTumblrEditDialog   *CTumblrEditDialog::m_instance = NULL;

CTumblrEditDialog   *CTumblrEditDialog::Instance()
{
    if ( m_instance == NULL )
        m_instance = new CTumblrEditDialog;

    return m_instance;
}

CTumblrEditDialog::CTumblrEditDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CTumblrEditDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTumblrEditDialog)
	m_quote = _T("");
	m_title = _T("");
	m_url = _T("");
	m_comment = _T("");
	//}}AFX_DATA_INIT

    Create( IDD_TUMBLR_DIALOG );
}

void CTumblrEditDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTumblrEditDialog)
	DDX_Text(pDX, IDC_EDIT_QUOTE, m_quote);
	DDV_MaxChars(pDX, m_quote, 1024);
	DDX_Text(pDX, IDC_EDIT_TITLE, m_title);
	DDV_MaxChars(pDX, m_title, 256);
	DDX_Text(pDX, IDC_EDIT_URL, m_url);
	DDV_MaxChars(pDX, m_url, 512);
	DDX_Text(pDX, IDC_EDIT_COMMENT, m_comment);
	DDV_MaxChars(pDX, m_comment, 512);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTumblrEditDialog, CDialog)
	//{{AFX_MSG_MAP(CTumblrEditDialog)
	ON_WM_SHOWWINDOW()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTumblrEditDialog ���b�Z�[�W �n���h��

void CTumblrEditDialog::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialog::OnShowWindow(bShow, nStatus);
	
    if ( bShow ) {
        CEdit   *p;
        if ( m_quote.GetLength() > 0 ) {
            p = (CEdit *)GetDlgItem( IDC_EDIT_QUOTE );
            p->SetWindowText( m_quote );
        }

        if ( m_comment.GetLength() > 0 ) {
            p = (CEdit *)GetDlgItem( IDC_EDIT_COMMENT );
            p->SetWindowText( m_comment );
        }

        if ( m_url.GetLength() > 0 ) {
            p = (CEdit *)GetDlgItem( IDC_EDIT_URL );
            p->SetWindowText( m_url );
        }

        if ( m_title.GetLength() > 0 ) {
            p = (CEdit *)GetDlgItem( IDC_EDIT_TITLE );
            p->SetWindowText( m_title );
        }
    }
}

void CTumblrEditDialog::OnOK()
{
	if ( (m_quote.GetLength() == 0) ||
         (m_url.GetLength()   == 0)    )
        return;

    CString targetURL     = m_url;
    CString targetContent = m_quote;
    CString tagetTitle    = m_title;

    if ( targetURL.GetLength() == 0 )
        targetURL.LoadString( IDS_URL_TUMBLR );
    if ( tagetTitle.GetLength() == 0 )
        tagetTitle = _T( "Tumblr" );

    if ( targetContent.GetLength() > 0 ) {
        ShowWindow( SW_HIDE );

        CWaitCursor cur;// �}�E�X�J�[�\���������v�\��
        BOOL        b;
        b = postTumblr( targetURL,  targetContent,
                        tagetTitle, m_comment,
                        m_tumblrID, m_tumblrPassword,
                        m_tumblrGroup );
        if ( b ) {
            // ����
            MessageBox( "tumblr �ɓ��e���܂���        ",
                        "tumblr ���e����",
                        MB_OK|MB_ICONINFORMATION );
        }
        else
            MessageBox( "���܁A������ƖZ�����́B"
                        "�܂��A���Ƃł�蒼���Ă�!    ",
                        "����Ԃ��",
                        MB_OK|MB_ICONWARNING );
    }

    DestroyWindow();
 // CDialog::OnOK();
}

void CTumblrEditDialog::OnCancel() 
{
    DestroyWindow();
 // CDialog::OnCancel();
}

void CTumblrEditDialog::PostNcDestroy() 
{
    delete m_instance;
    m_instance = NULL;
 // CDialog::PostNcDestroy();
}
