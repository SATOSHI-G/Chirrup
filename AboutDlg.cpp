/*
 * AboutDlg.cpp : Twitter �N���C�A���g chirrup
 *      �Ő�(�o�[�W�����ԍ�)�\��
 *
 *          written by H.Tsujimura  4 Apr 2007
 *
 *      Copyright (c) 2007 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/AboutDlg.cpp $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 4     09/03/23 21:06 Tsujimura543
 * libpng �� zlib �̔Ő����\������悤�ɂ���
 * 
 * 3     08/11/27 15:18 Tsujimura543
 * OpenSSL �� iconv �̔Ő���\������悤�ɂ���
 * 
 * 2     07/06/13 1:25 Tsujimura543
 * �_�C�A���O�ɕ\������o�[�W�����ԍ��������\�[�X�t�@�C������
 * �E���Ă���悤�ɂ���
 * 
 * 1     07/04/05 2:06 Tsujimura543
 * �ŏ��̔�
 */

#include "chirrup.h"
#include "AboutDlg.h"
#include "png.h"

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/chirrup/AboutDlg.cpp 1     09/05/14 3:50 tsupo $";
#endif

#if (WINVER >= 0x0500)
//#define IDC_HAND    MAKEINTRESOURCE(32649)
#ifdef IDC_HAND
#undef IDC_HAND
#endif
#endif /* WINVER >= 0x0500 */
#define IDC_HAND    IDC_HAND2


/* libpng �Ő��擾 */
char    *
getLibpngVersion( char *buf, size_t bufSize )
{
    char        *p = buf;
    char        *q;
    size_t      sz = bufSize;
    static char version[BUFSIZ];

    if ( !buf || (bufSize == 0) ) {
        p  = version;
        sz = BUFSIZ;
    }

    q = png_get_copyright(NULL);
    while ( (*q == ' ') || (*q == '\t') || (*q == '\r') || (*q == '\n') )
        q++;
    strncpy( p, q, sz - 1 );
    p[sz - 1] = NUL;

    return ( p );
}

/* zlib �Ő��擾 */
char    *
getZlibVersion( char *buf, size_t bufSize )
{
    char        *p = buf;
    size_t      sz = bufSize;
    static char version[BUFSIZ];

    sprintf( version, "zlib: %s", zlibVersion() );

    if ( buf && (bufSize > 0) ) {
        strncpy( p, version, sz - 1 );
        p[sz - 1] = NUL;
    }
    else
        p = version;

    return ( p );
}

/////////////////////////////////////////////////////////////////////////////
// �A�v���P�[�V�����̃o�[�W�������Ŏg���Ă��� CAboutDlg �_�C�A���O

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT

    m_hCursor = AfxGetApp()->LoadCursor( IDC_HAND );
}

CAboutDlg::~CAboutDlg()
{
    m_cFont.DeleteObject();
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	ON_BN_CLICKED(IDC_MAIL_ADDR, OnMailAddr)
	ON_BN_CLICKED(IDC_WEB_URL, OnWebUrl)
	ON_WM_SETCURSOR()
	ON_WM_SHOWWINDOW()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


void CAboutDlg::OnMailAddr() 
{
	CString cmd;
	cmd.LoadString( IDS_MAIL_ADDR );
    ShellExecute( NULL, "open", cmd, NULL, NULL, SW_SHOWNORMAL );
}

void CAboutDlg::OnWebUrl() 
{
	CString cmd;
	cmd.LoadString( IDS_WEB_URL );
    ShellExecute( NULL, "open", cmd, NULL, NULL, SW_SHOWNORMAL );
}

BOOL CAboutDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	if ( nHitTest == HTCLIENT ) {
        // Web �� URL�����[���A�h���X�Ƀ}�E�X�|�C���^��������A
        // �w�J�[�\����\������
		DWORD   dwPos = GetMessagePos();
		WORD    wX    = LOWORD( dwPos );
		WORD    wY    = HIWORD( dwPos );
		CPoint  poCursor( wX, wY );
		CRect   rcClient;

        CStatic *s = (CStatic *)GetDlgItem( IDC_MAIL_ADDR );
        s->GetWindowRect( &rcClient );
        if ( (wX >= rcClient.left) && (wX <= rcClient.right)  &&
             (wY >= rcClient.top)  && (wY <= rcClient.bottom)    ) {
			SetCursor( m_hCursor );
            return TRUE;
        }

        s = (CStatic *)GetDlgItem( IDC_WEB_URL );
        s->GetWindowRect( &rcClient );
        if ( (wX >= rcClient.left) && (wX <= rcClient.right)  &&
             (wY >= rcClient.top)  && (wY <= rcClient.bottom)    ) {
			SetCursor( m_hCursor );
            return TRUE;
        }
	}

	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}

void CAboutDlg::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
    if ( bShow ) {
        // Web �� URL�ƃ��[���A�h���X�������t���ŕ\������
        LOGFONT tLogFont;
        CFont   *cWndFont;

        cWndFont = GetFont(); 
        cWndFont->GetLogFont( &tLogFont );
        tLogFont.lfUnderline = 1;
        m_cFont.CreateFontIndirect( &tLogFont );

        CStatic *s = (CStatic *)GetDlgItem( IDC_MAIL_ADDR );
        s->SetFont( &m_cFont, TRUE );

        s = (CStatic *)GetDlgItem( IDC_WEB_URL );
        s->SetFont( &m_cFont, TRUE );

    	CString version;
    	version.LoadString( IDS_VERSION );
        CString title = _T("chirrup Version ");
        title += version;

        s = (CStatic *)GetDlgItem( IDC_VERSION );
        s->SetWindowText( title );

        // OpenSSL �Ő��\��
        char    buf[BUFSIZ];
        size_t  sz = BUFSIZ;

        s = (CStatic *)GetDlgItem( IDC_OPENSSL );
        s->SetWindowText( getOpenSSLversion( buf, sz ) );

        // iconv �Ő��\��
        s = (CStatic *)GetDlgItem( IDC_ICONV );
        s->SetWindowText( getIconvVersion( buf, sz ) );

        // libpng �Ő��\��
        s = (CStatic *)GetDlgItem( IDC_LIBPNG );
        s->SetWindowText( getLibpngVersion( buf, sz ) );

        // zlib �Ő��\��
        s = (CStatic *)GetDlgItem( IDC_ZLIB );
        s->SetWindowText( getZlibVersion( buf, sz ) );
    }
}
