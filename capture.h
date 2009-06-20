/*
 * capture.h  : Twitter �N���C�A���g chirrup
 *      ��ʃL���v�`���[�֘A �w�b�_ �t�@�C��
 *          written by H.Tsujimura  14 Dec 2007 / 17 Dec 2007
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
 *      ���Ԃ�AWindows 98 �ł������Ǝv���܂��BWindows 95 �̏ꍇ�� OSR2
 *      �ȍ~(�������� IE5.x ���ڂ��Ă����)�łȂ��Ɠ����Ȃ����������
 *      ����BWindows NT �̏ꍇ�� SP6 �Ȃ瓮���Ǝv���܂����A����ȑO����
 *      �����Ȃ���������܂���(SP4 �ȍ~�Ȃ���v?)�B
 *
 * $Log: /comm/chirrup/capture.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 1     07/12/17 19:50 Tsujimura543
 * �V�K�쐬 (capture�֘A�̕ϐ��A�֐����N���X�Ƃ��Ă܂Ƃ߂Ă݂�)
 */

#if !defined(__CAPTURE_H__A07B8677_638F_45CA_8C84_9324D00DA47B__INCLUDED_)
#define __CAPTURE_H__A07B8677_638F_45CA_8C84_9324D00DA47B__INCLUDED_

class CCapture
{
public:
    CCapture();

    BOOL
    InitInstance( CChirrupDlg *dlg, HWND &hWndForCapture );

    LRESULT CALLBACK
    WindowProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam );

private:
    CChirrupDlg         *m_dlgForCapture;
    HINSTANCE           m_hInstForCapture;
    TCHAR               *m_szWindowClass;
    int                 m_ofX;
    int                 m_ofY;
    PARAM_UPLOADIMAGE   m_paramUploadImage; 

    VOID
    DrawRubberband(HDC hdc, LPRECT newRect, BOOL erase);

    CCapture( CCapture &obj );
    CCapture    operator = ( CCapture &obj );
};

#endif  /* __CAPTURE_H__A07B8677_638F_45CA_8C84_9324D00DA47B__INCLUDED_ */
