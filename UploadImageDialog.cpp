/*
 * UploadImageDialog.cpp : Twitter �N���C�A���g chirrup
 *      �摜�t�@�C���A�b�v���[�h�_�C�A���O �C���v�������e�[�V���� �t�@�C��
 *          written by H.Tsujimura  6 Dec 2007
 *
 *      Copyright (c) 2007, 2008 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/UploadImageDialog.cpp $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 8     08/07/31 21:12 Tsujimura543
 * Wassr �ւ̃A�b�v���[�h�ɑΉ�
 * 
 * 7     08/02/07 22:36 Tsujimura543
 * copyright �\�����C�� (2008 ��ǉ�)
 * 
 * 6     08/01/24 14:46 Tsujimura543
 * �������e�Ώې؂�ւ��@�\������
 * 
 * 5     07/12/25 19:13 Tsujimura543
 * �v���r���[�\���̈�T�C�Y�̌v�Z����ύX
 * 
 * 4     07/12/19 13:29 Tsujimura543
 * �]���ȏ������폜
 * 
 * 3     07/12/19 13:26 Tsujimura543
 * �A�b�v���[�h���悤�Ƃ��Ă���摜�t�@�C���̃v���r���[�\����ǉ�
 * 
 * 2     07/12/10 21:26 Tsujimura543
 * m_targetName ��ǉ�
 * 
 * 1     07/12/06 4:07 Tsujimura543
 * �V�K�쐬
 */

#include "chirrup.h"
#include "UploadImageDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/chirrup/UploadImageDialog.cpp 1     09/05/14 3:50 tsupo $";
#endif

#if (WINVER >= 0x0500)
//#define IDC_HAND    MAKEINTRESOURCE(32649)
#ifdef IDC_HAND
#undef IDC_HAND
#endif
#endif /* WINVER >= 0x0500 */
#define IDC_HAND    IDC_HAND2

/////////////////////////////////////////////////////////////////////////////
// CUploadImageDialog �_�C�A���O

CUploadImageDialog::CUploadImageDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CUploadImageDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUploadImageDialog)
	m_filename = _T("");
	m_caption = _T("");
	//}}AFX_DATA_INIT

    m_targetName = _T("�t�@�C����");
    m_bitmap     = NULL;

    m_gyazo              = false;
    m_flickr             = false;
    m_tumblr             = false;
    m_hatenaFotolife     = false;
    m_wassr              = false;

    m_sim_gyazo          = false;
    m_sim_flickr         = false;
    m_sim_tumblr         = false;
    m_sim_hatenaFotolife = false;
    m_sim_wassr          = false;

    m_hCursor = AfxGetApp()->LoadCursor( IDC_HAND );
}

CUploadImageDialog::~CUploadImageDialog()
{
    if ( m_bitmap )
        DeleteObject( m_bitmap );
}

void CUploadImageDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUploadImageDialog)
	DDX_Text(pDX, IDC_IMAGE_FILENAME, m_filename);
	DDV_MaxChars(pDX, m_filename, 512);
	DDX_Text(pDX, IDC_CAPTION, m_caption);
	DDV_MaxChars(pDX, m_caption, 2048);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CUploadImageDialog, CDialog)
	//{{AFX_MSG_MAP(CUploadImageDialog)
	ON_WM_SHOWWINDOW()
	ON_WM_SETCURSOR()
    ON_NOTIFY(TTN_NEEDTEXT, 0, OnDisplayToolTip)
	ON_WM_CONTEXTMENU()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUploadImageDialog �ǉ����\�b�h

bool CUploadImageDialog::IsInner( int id, WORD wX, WORD wY )
{
    CRect   rcClient;
    CStatic *s = (CStatic *)GetDlgItem( id );
    bool    ret = false;

    s->GetWindowRect( &rcClient );
    if ( (wX >= rcClient.left) && (wX <= rcClient.right)  &&
         (wY >= rcClient.top)  && (wY <= rcClient.bottom)    )
        ret = true;

    return ( ret );
}

void CUploadImageDialog::SetStaticEdge( int idx, bool status )
{
    CStatic *sp = (CStatic *)GetDlgItem( idx );

    if ( status ) {
        // "���ڂ�"��Ԃɂ���
        sp->ModifyStyleEx( 0, WS_EX_STATICEDGE, SWP_DRAWFRAME );
    }
    else {
        // "���ڂ�"��Ԃ���������
        sp->ModifyStyleEx( WS_EX_STATICEDGE, 0, SWP_DRAWFRAME );

        // "���ڂ�"��� �� ���ڂ�łȂ���Ԃ̕ω���A�A�C�R���̉����̕\����
        // �����̂ŁA�ĕ`�悵�Ă���
        sp->RedrawWindow();
    }
}

/////////////////////////////////////////////////////////////////////////////
// CUploadImageDialog ���b�Z�[�W �n���h��

BOOL CUploadImageDialog::OnInitDialog() 
{
    CDialog::OnInitDialog();

    EnableToolTips(TRUE);

    return TRUE;
}

void CUploadImageDialog::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);

    if ( bShow ) {
        CEdit   *p;

        if ( m_filename.GetLength() > 0 ) {
            p = (CEdit *)GetDlgItem( IDC_IMAGE_FILENAME );
            p->SetWindowText( m_filename );

            // �A�b�v���[�h���悤�Ƃ��Ă���摜�̃v���r���[(�T���l�C��)��\��
            CImage  image;
            int     height = 0;
            int     width  = 0;
            if ( !strncmp( m_filename, "http://",  7 ) ||
                 !strncmp( m_filename, "https://", 8 )    ) {
                m_bitmap = image.HttpOpen( m_filename );
            }
            else {
                m_bitmap = image.LoadImageFile( m_filename );
            }

            if ( m_bitmap ) {
                BITMAP  bmp;
                GetObject( m_bitmap, sizeof ( bmp ), (LPSTR)&bmp );
                height = bmp.bmHeight;
                width  = bmp.bmWidth;

                CStatic *sp = (CStatic *)GetDlgItem( IDC_BITMAP_THUMBNAIL );

                CRect   rect;
                CEdit   *ep = (CEdit *)GetDlgItem( IDC_CAPTION );
                ep->GetWindowRect( &rect );
                int     maxSq = (((rect.bottom - rect.top) - 2) * 12) / 10;

                sp->SetBitmap( m_bitmap );
                if ( (height > maxSq) || (width > maxSq) ) {
                    // �\���̈�T�C�Y�ɍ��킹�ĉ摜���k���\������
                    int sig = ((max(height, width)) + (maxSq - 1)) / maxSq;
                    sp->SetWindowPos( sp->GetTopWindow(),
                                      0, 0, width/sig, height/sig,
                                      SWP_NOMOVE );
                }
            }
        }
        if ( m_caption.GetLength() > 0 ) {
            p = (CEdit *)GetDlgItem( IDC_CAPTION );
            p->SetWindowText( m_caption );
        }

        if ( m_targetName.GetLength() > 0 ) {
            CStatic *sp = (CStatic *)GetDlgItem( IDC_TARGET_NAME );
            sp->SetWindowText( m_targetName );
        }

        m_sim_gyazo          = m_gyazo;
        m_sim_flickr         = m_flickr;
        m_sim_tumblr         = m_tumblr;
        m_sim_hatenaFotolife = m_hatenaFotolife;
        m_sim_wassr          = m_wassr;

        SetStaticEdge( IDC_GYAZO,          m_sim_gyazo );
        SetStaticEdge( IDC_FLICKR,         m_sim_flickr );
        SetStaticEdge( IDC_TUMBLR,         m_sim_tumblr );
        SetStaticEdge( IDC_HATENAFOTOLIFE, m_sim_hatenaFotolife );
        SetStaticEdge( IDC_WASSR,          m_sim_wassr );
    }
}

BOOL CUploadImageDialog::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
    if ( nHitTest == HTCLIENT ) {
        static int targetIDC[] = {
            IDC_GYAZO,
            IDC_FLICKR,
            IDC_TUMBLR,
            IDC_HATENAFOTOLIFE,
            IDC_WASSR,
            -1
        };

		DWORD   dwPos = GetMessagePos();
		WORD    wX    = LOWORD( dwPos );
		WORD    wY    = HIWORD( dwPos );

        int i;
        for ( i = 0; targetIDC[i] > 0; i++ ) {
            if ( IsInner( targetIDC[i], wX, wY ) ) {
			    SetCursor( m_hCursor );
                return TRUE;
            }
        }
    }
	
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}

#ifdef  _MSC_VER
#pragma warning ( disable: 4100 )
#endif
void CUploadImageDialog::OnDisplayToolTip(NMHDR* pNMHDR, LRESULT* pResult)
{
    TOOLTIPTEXT *tp = (TOOLTIPTEXT *)pNMHDR;

    if ( (tp->uFlags & TTF_IDISHWND) == TTF_IDISHWND ) {
        int id = ::GetDlgCtrlID( (HWND)tp->hdr.idFrom );
        CString text = _T("");

        switch ( id ) {
        case IDC_GYAZO:
            text = _T("Gyazo");
            text += _T(" (�������e�Ώ�");
            text += m_sim_gyazo ? _T(")") : _T("�O)");
            break;
        case IDC_FLICKR:
            text = _T("flickr");
            text += _T(" (�������e�Ώ�");
            text += m_sim_flickr ? _T(")") : _T("�O)");
            break;
        case IDC_TUMBLR:
            text = _T("tumblr");
            text += _T(" (�������e�Ώ�");
            text += m_sim_tumblr ? _T(")") : _T("�O)");
            break;
        case IDC_HATENAFOTOLIFE:
            text = _T("�͂Ăȃt�H�g���C�t");
            text += _T(" (�������e�Ώ�");
            text += m_sim_hatenaFotolife ? _T(")") : _T("�O)");
            break;
        case IDC_WASSR:
            text = _T("Wassr");
            text += _T(" (�������e�Ώ�");
            text += m_sim_wassr ? _T(")") : _T("�O)");
            break;
        }

        if ( text.GetLength() > 0 )
            strcat( tp->szText, text );
    }
}
#ifdef  _MSC_VER
#pragma warning ( default: 4100 )
#endif

#ifdef  _MSC_VER
#pragma warning ( disable: 4100 )
#endif
void CUploadImageDialog::OnContextMenu(CWnd* pWnd, CPoint point) 
{
    DWORD   dwPos     = GetMessagePos();
    WORD    wX        = LOWORD( dwPos );
    WORD    wY        = HIWORD( dwPos );
    bool    onOff     = false;
    int     targetIDC = 0;

    if ( IsInner( IDC_GYAZO, wX, wY ) ) {
        if ( m_gyazo ) {
            targetIDC = IDC_GYAZO;
            onOff     = m_sim_gyazo;
        }
    }
    else if ( IsInner( IDC_FLICKR, wX, wY ) ) {
        if ( m_flickr ) {
            targetIDC = IDC_FLICKR;
            onOff     = m_sim_flickr;
        }
    }
    else if ( IsInner( IDC_TUMBLR, wX, wY ) ) {
        if ( m_tumblr ) {
            targetIDC = IDC_TUMBLR;
            onOff     = m_sim_tumblr;
        }
    }
    else if ( IsInner( IDC_HATENAFOTOLIFE, wX, wY ) ) {
        if ( m_hatenaFotolife ) {
            targetIDC = IDC_HATENAFOTOLIFE;
            onOff     = m_sim_hatenaFotolife;
        }
    }
    else if ( IsInner( IDC_WASSR, wX, wY ) ) {
        if ( m_wassr ) {
            targetIDC = IDC_WASSR;
            onOff     = m_sim_wassr;
        }
    }

    if ( targetIDC == 0 )
        return;

    CPoint  cMenuPt;
    GetCursorPos( &cMenuPt );

#define IDC_MENU_SWITCH_ON      1
#define IDC_MENU_SWITCH_OFF     2
    CMenu   menu;
    menu.CreatePopupMenu();
    menu.AppendMenu( MF_STRING, IDC_MENU_SWITCH_ON,
                     "�������e�Ώۂɂ��� (&S)" );
    menu.AppendMenu( MF_STRING, IDC_MENU_SWITCH_OFF,
                     "�������e�Ώۂ���O�� (&X)" );

    if ( onOff )
        menu.EnableMenuItem( IDC_MENU_SWITCH_ON, MF_GRAYED );
    if ( !onOff )
        menu.EnableMenuItem( IDC_MENU_SWITCH_OFF, MF_GRAYED );

    int iCommand =
        menu.TrackPopupMenu(
            TPM_LEFTALIGN | TPM_BOTTOMALIGN | TPM_RETURNCMD | TPM_LEFTBUTTON,
            cMenuPt.x, cMenuPt.y, this, NULL );

    if ( (iCommand == IDC_MENU_SWITCH_ON)  ||
         (iCommand == IDC_MENU_SWITCH_OFF)    ) {
        switch ( targetIDC ) {
        case IDC_GYAZO:
            m_sim_gyazo = !(m_sim_gyazo);
            SetStaticEdge( targetIDC, m_sim_gyazo );
            break;
        case IDC_FLICKR:
            m_sim_flickr = !(m_sim_flickr);
            SetStaticEdge( targetIDC, m_sim_flickr );
            break;
        case IDC_TUMBLR:
            m_sim_tumblr = !(m_sim_tumblr);
            SetStaticEdge( targetIDC, m_sim_tumblr );
            break;
        case IDC_HATENAFOTOLIFE:
            m_sim_hatenaFotolife = !(m_sim_hatenaFotolife);
            SetStaticEdge( targetIDC, m_sim_hatenaFotolife );
            break;
        case IDC_WASSR:
            m_sim_wassr = !(m_sim_wassr);
            SetStaticEdge( targetIDC, m_sim_wassr );
            break;
        }
    }

    menu.DestroyMenu();	
}
#ifdef  _MSC_VER
#pragma warning ( default: 4100 )
#endif
