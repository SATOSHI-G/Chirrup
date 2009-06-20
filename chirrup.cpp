/*
 * chirrup.cpp : Twitter �N���C�A���g chirrup
 *      CChirrupApp �{��
 *          written by H.Tsujimura  4 Apr 2007
 *
 *      Copyright (c) 2007, 2008 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/chirrup.cpp $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 12    09/04/28 20:52 Tsujimura543
 * �^�C���A�E�g�擾�������K�莞�ԓ��ɏI���Ȃ��ꍇ�̏�����ύX
 * (�X���b�h�����I�������ł͂Ȃ��A�C�x���g�ʒm�������̗p)
 * 
 * 11    09/04/15 1:17 Tsujimura543
 * Jaiuku �� OAuth �Ή�����
 * 
 * 10    09/03/30 22:36 Tsujimura543
 * Twitter �� OAuth �Ή����� ����2
 * 
 * 9     09/03/30 22:19 Tsujimura543
 * Twitter �� OAuth �Ή�����
 * 
 * 8     08/09/16 17:40 Tsujimura543
 * �p�ꃂ�[�h�Ή�����
 * 
 * 7     08/02/07 22:36 Tsujimura543
 * copyright �\�����C�� (2008 ��ǉ�)
 * 
 * 6     08/01/08 21:07 Tsujimura543
 * flickr �Ή����� (�� 08/01/09 22:27 �Ή�����)
 * 
 * 5     07/12/20 16:36 Tsujimura543
 * �����ݒ�t�@�C�����܂����݂��Ȃ���ԂŋN�������Ƃ���proxy�ݒ菈����2��
 * �����Ă��܂��s����C��
 * 
 * 4     07/12/17 19:52 Tsujimura543
 * capture �֘A�̕ϐ��A�֐��� CCapture �N���X�Ƃ��Ă܂Ƃ߂����Ƃɔ���
 * �C�������{
 * 
 * 3     07/09/06 19:46 Tsujimura543
 * �]���ȃR�����g���폜
 * 
 * 2     07/04/27 22:28 Tsujimura543
 * �v���N�V�֘A�̐ݒ��ێ����郁���o�[�� CChirrupApp �Ɉړ�
 * 
 * 1     07/04/05 2:06 Tsujimura543
 * �ŏ��̔�
 */

#include "chirrup.h"
#include "AboutDlg.h"

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/chirrup/chirrup.cpp 1     09/05/14 3:50 tsupo $";
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChirrupApp

BEGIN_MESSAGE_MAP(CChirrupApp, CWinApp)
	//{{AFX_MSG_MAP(CChirrupApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChirrupApp �N���X�̍\�z

CChirrupApp::CChirrupApp()
{
    LCID    langCode;
    m_langCode = langCode = getLanguageCode();
    if ( m_langCode != 0x0411 ) {
        m_langCode = 0x0409;  // �u���{��v�ȊO�̏ꍇ�͋����I�Ɂu�p��v�ɂ���
        if ( langCode != m_langCode )
            setLanguageCode( m_langCode );
    }

    m_isUsedProxy   = false;
    m_proxyServer   = _T("");
    m_proxyPort     = -1;
    m_proxyUserName = _T("");
    m_proxyPassword = _T("");
	m_chirrpDlg     = NULL;
    m_capture       = NULL;
    m_event         = NULL;

    m_fKey          = _T("");
    m_fSecret       = _T("");
    m_tcKey         = _T("");
    m_tcSecret      = _T("");
    m_jcKey         = _T("");
    m_jcSecret      = _T("");
}

/////////////////////////////////////////////////////////////////////////////
// �B��� CChirrupApp �I�u�W�F�N�g

CChirrupApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CChirrupApp �N���X�̏�����

BOOL CChirrupApp::InitInstance()
{
	// �W���I�ȏ���������
#ifdef _AFXDLL
	Enable3dControls();			// ���L DLL ���� MFC ���g���ꍇ
#else
	Enable3dControlsStatic();	// MFC �ƐÓI�Ƀ����N����ꍇ
#endif

	CChirrupDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
	}
	else if (nResponse == IDCANCEL)
	{
	}

	return FALSE;
}


#ifdef  _MSC_VER
#pragma warning ( disable: 4100 )
#endif
void CChirrupApp::WinHelp(DWORD dwData, UINT nCmd) 
{
 // CWinApp::WinHelp(dwData, nCmd);
}
#ifdef  _MSC_VER
#pragma warning ( default: 4100 )
#endif

// �_�C�A���O�����s���邽�߂̃A�v���P�[�V���� �R�}���h
void CChirrupApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}
