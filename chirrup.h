/*
 * chirrup.h  : Twitter �N���C�A���g chirrup
 *      ���C���w�b�_�[�t�@�C��
 *          written by H.Tsujimura  4 Apr 2007
 *
 *      Copyright (c) 2007, 2008 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/chirrup.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 14    09/04/28 20:52 Tsujimura543
 * �^�C���A�E�g�擾�������K�莞�ԓ��ɏI���Ȃ��ꍇ�̏�����ύX
 * (�X���b�h�����I�������ł͂Ȃ��A�C�x���g�ʒm�������̗p)
 * 
 * 13    09/04/15 1:17 Tsujimura543
 * Jaiuku �� OAuth �Ή�����
 * 
 * 12    09/03/30 22:36 Tsujimura543
 * Twitter �� OAuth �Ή����� ����2
 * 
 * 11    09/03/30 22:19 Tsujimura543
 * Twitter �� OAuth �Ή�����
 * 
 * 10    08/09/16 17:40 Tsujimura543
 * �p�ꃂ�[�h�Ή�����
 * 
 * 9     08/02/07 22:36 Tsujimura543
 * copyright �\�����C�� (2008 ��ǉ�)
 * 
 * 8     08/01/08 21:07 Tsujimura543
 * flickr �Ή����� (�� 08/01/09 22:27 �Ή�����)
 * 
 * 7     07/12/20 16:36 Tsujimura543
 * �����ݒ�t�@�C�����܂����݂��Ȃ���ԂŋN�������Ƃ���proxy�ݒ菈����2��
 * �����Ă��܂��s����C��
 * 
 * 6     07/12/17 19:52 Tsujimura543
 * capture �֘A�̕ϐ��A�֐��� CCapture �N���X�Ƃ��Ă܂Ƃ߂����Ƃɔ���
 * �C�������{
 * 
 * 5     07/09/06 19:42 Tsujimura543
 * �_�~�[�̃R�s�[�R���X�g���N�^�A������Z�q�� private �Ƃ��ē����B
 * �m��Ȃ������Ƀ������m��(�Ɖ�����Y��)����������\����r���B
 * 
 * 4     07/05/11 21:29 Tsujimura543
 * �u���E�U�ŉ{������ URL �� Twitter �ɑ��M����Ƃ��A���� Web �y�[�W��
 * �^�C�g�����擾���đ��M����悤�ɂ���
 * 
 * 3     07/04/27 19:37 Tsujimura543
 * Twitter API �֘A�̍\���̂̒�`�� Twitter.h �ֈړ�
 * 
 * 2     07/04/24 23:48 Tsujimura543
 * GetUrlInBrowsing() �̃v���g�^�C�v�錾��ǉ�
 * 
 * 1     07/04/05 2:06 Tsujimura543
 * �ŏ��̔�
 */

#if !defined(AFX_CHIRRUP_H__AAFFDE06_EFA5_46F2_BCE5_C7315B7175AC__INCLUDED_)
#define AFX_CHIRRUP_H__AAFFDE06_EFA5_46F2_BCE5_C7315B7175AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Windows �w�b�_�[����w�ǎg�p����Ȃ��X�^�b�t�����O���܂��B

#ifdef  _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

#include <afxwin.h>         // MFC �̃R�A����ѕW���R���|�[�l���g
#include <afxext.h>         // MFC �̊g������
#include <afxdtctl.h>		// MFC �� Internet Explorer 4 �R���� �R���g���[�� �T�|�[�g
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC �� Windows �R���� �R���g���[�� �T�|�[�g
#endif // _AFX_NO_AFXCMN_SUPPORT

#include "resource.h"		// ���C�� �V���{��
#include "Twitter.h"
#include "chirrupDlg.h"
#include "capture.h"

CString GetUrlInBrowsing( CString &pageTitle );

/////////////////////////////////////////////////////////////////////////////
// CChirrupApp  �A�v���P�[�V���� ���C��

class CChirrupApp : public CWinApp
{
public:
	CChirrupApp();

// �I�[�o�[���C�h
	//{{AFX_VIRTUAL(CChirrupApp)
	public:
	virtual BOOL InitInstance();
	virtual void WinHelp(DWORD dwData, UINT nCmd = HELP_CONTEXT);
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
    bool        m_isUsedProxy;      // proxy ���g�����ۂ�
    CString     m_proxyServer;      // proxy �T�[�o��
    long        m_proxyPort;        // proxy �|�[�g�ԍ�
    CString     m_proxyUserName;    // proxy ���[�U��
    CString     m_proxyPassword;    // proxy �p�X���[�h

    CString     m_fKey;
    CString     m_fSecret;
    CString     m_tcKey;
    CString     m_tcSecret;
    CString     m_jcKey;
    CString     m_jcSecret;

	CChirrupDlg	*m_chirrpDlg;
    CCapture    *m_capture;

    HANDLE  m_event;

    LCID    m_langCode; // ����(0x0409: �p��(�A�����J), 0x0411: ���{��, �c�c)

	//{{AFX_MSG(CChirrupApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
    CChirrupApp( CChirrupApp &obj );
    CChirrupApp operator = ( CChirrupApp &obj );
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_CHIRRUP_H__AAFFDE06_EFA5_46F2_BCE5_C7315B7175AC__INCLUDED_)
