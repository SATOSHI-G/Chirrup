/*
 * capture.cpp : Twitter �N���C�A���g chirrup
 *      ��ʃL���v�`���[�֘A �C���v�������e�[�V���� �t�@�C��
 *          written by H.Tsujimura  14 Dec 2007
 *
 *      Copyright (c) 2007 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      Some Rights Reserved.
 *
 *      tnj���� gyazoowin �̃\�[�X���Q�l�ɂ��Ă��܂�
 *          http://nothing.sh/blog/archives/44
 *
 *      gyazoowin �Ƃ̈Ⴂ�́Agdiplus.dll ���g�키����ɁA�{�⌫����
 *      bmp2png ���g�����ƂŁAgdiplus.dll ���Ȃ����ł������悤�ɂ���
 *      ����Ƃ���ł��B�L�p�ȃ\�[�X�R�[�h�����J���Ă��������Ă���tnj���A
 *      �{�⌫���̂���l�Ɋ��ӂ��܂�
 *
 * $Log: /comm/chirrup/capture.cpp $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 6     07/12/17 19:51 Tsujimura543
 * capture�֘A�̕ϐ��A�֐����N���X�Ƃ��Ă܂Ƃ߂Ă݂�
 * 
 * 5     07/12/17 18:51 Tsujimura543
 * savePNG() �� CImage::SavePngFile() �Ɉڍs
 * 
 * 4     07/12/15 6:47 Tsujimura543
 * MessageBox() �ŕ\�����镶�����C�� (�f�o�b�O�p)
 * 
 * 3     07/12/15 6:11 Tsujimura543
 * �O����s���̘g�����������������Ă݂�
 * 
 * 2     07/12/15 5:10 Tsujimura543
 * �L���v�`���ɐ������APNG�t�@�C���������ł���Ƃ���܂œ�����m�F�B
 * 2��ڈȍ~�̃L���v�`�����s���A�O����s���̔j���̘g���c���Ă��܂����ۂ���
 * 
 * 1     07/12/15 2:26 Tsujimura543
 * �b��� (�܂��A���܂������Ă��Ȃ��Ƃ��낪����)
 */

#include "chirrup.h"
#include "CImage.h"
#include <sys/stat.h>

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/chirrup/capture.cpp 1     09/05/14 3:50 tsupo $";
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

LRESULT CALLBACK
WndProcForCapture( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam );

// �R���X�g���N�^
CCapture::CCapture() {
    m_dlgForCapture             = NULL;
    m_hInstForCapture           = NULL;
    m_szWindowClass             = NULL;
    m_ofX                       = 0;
    m_ofY                       = 0;
    m_paramUploadImage.dlg      = NULL;
    m_paramUploadImage.filetype = FTYPE_UNKNOWN;
    m_paramUploadImage.filename = _T("");
    m_paramUploadImage.filesize = 0;
    m_paramUploadImage.url      = _T("");
    m_paramUploadImage.caption  = _T("");
}

// ������
BOOL
CCapture::InitInstance( CChirrupDlg *dlg, HWND &hWndForCapture )
{
    m_dlgForCapture   = dlg;
    CChirrupApp *ap   = (CChirrupApp *)AfxGetApp();
    m_hInstForCapture = ap->m_hInstance;
    m_szWindowClass   = _T("CHIRRUP");

    WNDCLASSEX wc;

    wc.cbSize        = sizeof ( WNDCLASSEX );
    wc.style         = 0;                           // WM_PAINT �𑗂�Ȃ�
    wc.lpfnWndProc   = WndProcForCapture;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = m_hInstForCapture;
    wc.hIcon         = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
    wc.hCursor       = LoadCursor(NULL, IDC_CROSS); // + �̃J�[�\��
    wc.hbrBackground = 0;                           // �w�i���ݒ肵�Ȃ�
    wc.lpszMenuName  = 0;
    wc.lpszClassName = m_szWindowClass;
    wc.hIconSm       = NULL;

    RegisterClassEx( &wc );

    int x, y, w, h;

#ifndef SM_XVIRTUALSCREEN
#define SM_XVIRTUALSCREEN       76
#define SM_YVIRTUALSCREEN       77
#define SM_CXVIRTUALSCREEN      78
#define SM_CYVIRTUALSCREEN      79
#endif

    // ���z�X�N���[���S�̂��J�o�[
    x = GetSystemMetrics(SM_XVIRTUALSCREEN);
    y = GetSystemMetrics(SM_YVIRTUALSCREEN);
    w = GetSystemMetrics(SM_CXVIRTUALSCREEN);
    h = GetSystemMetrics(SM_CYVIRTUALSCREEN);

    // x, y �̃I�t�Z�b�g�l���o���Ă���
    m_ofX = x;
    m_ofY = y;

	// ���S�ɓ��߂����E�B���h�E�����
    hWndForCapture =
        CreateWindowEx(
                WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW | WS_EX_TOPMOST
#if (_WIN32_WINNT >= 0x0500)
              | WS_EX_NOACTIVATE
#endif
                ,
                m_szWindowClass, NULL, WS_POPUP,
                CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,
                NULL, NULL, m_hInstForCapture, NULL );

    // ���Ȃ�����...?
    if ( !hWndForCapture ) {
        dlg->m_inCapturing = false;
        return ( FALSE );
    }
	
    // �S��ʂ𕢂�
    ::MoveWindow(hWndForCapture, x, y, w, h, FALSE);

    // nCmdShow �𖳎� (SW_MAXIMIZE �Ƃ������ƍ���)
    ::ShowWindow(hWndForCapture, SW_SHOW);
    ::UpdateWindow(hWndForCapture);

    return ( TRUE );
}


// ���o�[�o���h��`��
VOID
CCapture::DrawRubberband(HDC hdc, LPRECT newRect, BOOL erase)
{
    static BOOL firstDraw = TRUE;   // 1 ��ڂ͑O�̃o���h�̏������s��Ȃ�
    static RECT lastRect  = {0};    // �Ō�ɕ`�悵���o���h

    // XOR �ŕ`��
    int hPreRop = SetROP2( hdc, R2_XORPEN );

    // �_��
    HPEN    hPen = CreatePen( PS_DOT , 1, 0 );
    SelectObject( hdc, hPen );
    SelectObject( hdc, GetStockObject(NULL_BRUSH) );

    if ( !firstDraw ) {
        // �O�̂�����
        Rectangle( hdc, lastRect.left, lastRect.top,
                   lastRect.right + 1, lastRect.bottom + 1 );
    }
    else {
        firstDraw = FALSE;
    }

    // �V�������W���L��
    lastRect = *newRect;

    if ( !erase ) {
        // �g��`��
        Rectangle( hdc, lastRect.left, lastRect.top, 
                   lastRect.right + 1, lastRect.bottom + 1 );
    }

    // �㏈��
    SetROP2( hdc, hPreRop );
    DeleteObject( hPen );
}

// ���b�Z�[�W���[�v
LRESULT CALLBACK
CCapture::WindowProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
    HDC         hdc;
    static BOOL onClip   = FALSE;
    static RECT clipRect = {0, 0, 0, 0};

    switch ( message ) {
    case WM_RBUTTONDOWN:
        // �L�����Z��
        onClip = FALSE;
        if ( m_dlgForCapture )
            m_dlgForCapture->OnEndCapture();
     // DestroyWindow(hWnd);
        break;

    case WM_MOUSEMOVE:
		if ( onClip ) {
			// �V�������W���Z�b�g
			clipRect.right  = LOWORD(lParam) + m_ofX;
			clipRect.bottom = HIWORD(lParam) + m_ofY;
			
			hdc = GetDC(NULL);
			DrawRubberband(hdc, &clipRect, FALSE);
			ReleaseDC(NULL, hdc);
		}
		break;

    case WM_LBUTTONDOWN:
        if ( !onClip ) {
            // �N���b�v�J�n
            onClip = TRUE;

            // �O��̐�������
            HDC hdc = GetDC(NULL);
            DrawRubberband(hdc, &clipRect, TRUE);

            // �����ʒu���Z�b�g
            clipRect.left = LOWORD(lParam) + m_ofX;
            clipRect.top  = HIWORD(lParam) + m_ofY;

            // �}�E�X���L���v�`��
            SetCapture(hWnd);
        }
        break;

    case WM_LBUTTONUP:
		if ( onClip ) {
            // �N���b�v�I��
            onClip = FALSE;

            // �}�E�X�̃L���v�`��������
            ReleaseCapture();

            // �V�������W���Z�b�g
            clipRect.right  = LOWORD(lParam) + m_ofX;
            clipRect.bottom = HIWORD(lParam) + m_ofY;

            // ��ʂɒ��ڕ`��C���Č`
            HDC hdc = GetDC(NULL);

            // ��������
            DrawRubberband(hdc, &clipRect, TRUE);

            // ���W�`�F�b�N
            if ( clipRect.right  < clipRect.left ) {
                int tmp = clipRect.left;
                clipRect.left   = clipRect.right;
                clipRect.right  = tmp;
            }
            if ( clipRect.bottom < clipRect.top  ) {
                int tmp = clipRect.top;
                clipRect.top    = clipRect.bottom;
                clipRect.bottom = tmp;
            }

            // �摜�̃L���v�`��
            int iWidth, iHeight;
            iWidth  = clipRect.right  - clipRect.left + 1;
            iHeight = clipRect.bottom - clipRect.top  + 1;

            if ( iWidth == 0 || iHeight == 0 ) {
                // �摜�ɂȂ��ĂȂ�, �Ȃɂ����Ȃ�
                ReleaseDC(NULL, hdc);
                if ( m_dlgForCapture )
                    m_dlgForCapture->OnEndCapture();
             // DestroyWindow(hWnd);
                break;
            }

            // �r�b�g�}�b�v�o�b�t�@���쐬
            HBITMAP newBMP = CreateCompatibleBitmap( hdc, iWidth, iHeight );
            HDC	    newDC  = CreateCompatibleDC( hdc );

            // �֘A�Â�
            SelectObject( newDC, newBMP );

            // �摜���擾
            BitBlt( newDC, 0, 0, iWidth, iHeight, 
                    hdc, clipRect.left, clipRect.top, SRCCOPY );

            // �E�B���h�E���B��!
            ShowWindow( hWnd, SW_HIDE );
			
            // �e���|�����t�@�C����������
            TCHAR   tmpDir[MAX_PATH];
            TCHAR   tmpFile[MAX_PATH];
            GetTempPath( MAX_PATH, tmpDir );
            GetTempFileName( tmpDir, TEMPFILE_BASE, 0, tmpFile );

            CImage  image;
            if ( image.SavePngFile( tmpFile, newBMP ) ) {
#ifdef  _DEBUG
                ::MessageBox( NULL,
                              "�L���v�`���[���ʂ�PNG�t�@�C���ɕۑ����܂���  ",
                              "�t�@�C���ۑ�����",
                              MB_OK|MB_ICONINFORMATION);
#endif  /* _DEBUG */

                // �A�b�v���[�h
                // �摜�t�@�C�����ǂ����`�F�b�N
                struct stat s;
                if ( !stat( tmpFile, &s ) ) {
                    int             height = 0;
                    int             width  = 0;
                    CHIRRUP_FTYPE   ftype  = m_dlgForCapture->GetImageSize(
                                                    tmpFile, height, width );

                    if ( (height > 0) && (width > 0) ) {
                        m_paramUploadImage.dlg      = m_dlgForCapture;
                        m_paramUploadImage.filetype = ftype;
                        m_paramUploadImage.filename = tmpFile;
                        m_paramUploadImage.filesize = s.st_size;
                        m_paramUploadImage.url      = _T("");
                        m_paramUploadImage.caption  = _T("");

                        // �A�b�v���[�h�������s�Ȃ��X���b�h���N��
                        m_dlgForCapture->UploadImage( &m_paramUploadImage );
                    }
                }
            }

            // ��n��
         // DeleteFile(tmpFile);
                // ����: �A�b�v���[�h������ʃX���b�h�ōs�Ȃ��Ă���(�܂��A
                //       �A�b�v���[�h�������ł���\��������)���߁A���̃^
                //       �C�~���O�Ńt�@�C���������͔̂�����

            DeleteDC(newDC);
            DeleteObject(newBMP);

            ReleaseDC(NULL, hdc);

            if ( m_dlgForCapture )
                m_dlgForCapture->OnEndCapture();
         // DestroyWindow(hWnd);
        }
        break;

    case WM_DESTROY:
        if ( m_dlgForCapture )
            m_dlgForCapture->OnEndCapture();
     // PostQuitMessage(0);
        break;

    default:
        return DefWindowProc( hWnd, message, wParam, lParam );
        break;
    }

    return 0;
}


LRESULT CALLBACK
WndProcForCapture( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
    CChirrupApp     *ap = (CChirrupApp *)AfxGetApp();
    if ( ap && ap->m_capture )
        return ( ap->m_capture->WindowProc( hWnd, message, wParam, lParam ) );

    return 0;
}
