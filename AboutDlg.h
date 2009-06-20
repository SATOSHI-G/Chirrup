/*
 * AboutDlg.h  : Twitter �N���C�A���g chirrup
 *      �Ő�(�o�[�W�����ԍ�)�\���_�C�A���O �w�b�_�[�t�@�C��
 *          written by H.Tsujimura  4 Apr 2007
 *
 *      Copyright (c) 2007 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/AboutDlg.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 3     07/09/06 19:46 Tsujimura543
 * �]���ȃR�����g���폜
 * 
 * 2     07/09/06 19:42 Tsujimura543
 * �_�~�[�̃R�s�[�R���X�g���N�^�A������Z�q�� private �Ƃ��ē����B
 * �m��Ȃ������Ƀ������m��(�Ɖ�����Y��)����������\����r���B
 * 
 * 1     07/04/05 2:06 Tsujimura543
 * �ŏ��̔�
 */

#if !defined(AFX_CHIRRUP_H__AAFFDE06_EFA5_46F2_BCE5_AF68C87D0A07__INCLUDED_)
#define AFX_CHIRRUP_H__AAFFDE06_EFA5_46F2_BCE5_AF68C87D0A07__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// �A�v���P�[�V�����̃o�[�W�������Ŏg���Ă��� CAboutDlg �_�C�A���O

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
	~CAboutDlg();

    HCURSOR m_hCursor;
    CFont   m_cFont;

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �̃T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	//{{AFX_MSG(CAboutDlg)
	afx_msg void OnMailAddr();
	afx_msg void OnWebUrl();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
    CAboutDlg( CAboutDlg &dlg );
    CAboutDlg   operator = ( CAboutDlg &dlg );
};

#endif  // AFX_CHIRRUP_H__AAFFDE06_EFA5_46F2_BCE5_AF68C87D0A07__INCLUDED_
