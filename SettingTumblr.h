/*
 * SettingTumblr.h  : Twitter �N���C�A���g chirrup
 *      CSettingTumblr �N���X�̐錾����уC���^�[�t�F�C�X�̒�`
 *          written by H.Tsujimura  5 Nov 2007
 *
 *      Copyright (c) 2007, 2008, 2009 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/SettingTumblr.h $
 * 
 * 2     09/05/31 20:42 tsupo
 * 1.142��
 * 
 * 5     09/05/29 19:22 Tsujimura543
 * ����A�J�E���g�ŕ��� tumbleblog ���J�݂��Ă���ꍇ�̓��e��
 * tumbleblog ���w�肵�Ă̓��e���\�ɂ���
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 4     08/01/10 19:21 Tsujimura543
 * CTabDialog2 �𓱓��A�R�[�h�𐮗�����
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

#if !defined(AFX_SETTINGTUMBLR_H__CF4D808A_A0F4_40A0_8135_31141219E2A6__INCLUDED_)
#define AFX_SETTINGTUMBLR_H__CF4D808A_A0F4_40A0_8135_31141219E2A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CTabDialog2.h"

#define MAX_BLOGS       30  /* �b��l */

/////////////////////////////////////////////////////////////////////////////
// CSettingTumblr �_�C�A���O

class CSettingTumblr : public CTabDialog2
{
// �R���X�g���N�V����
public:
	CSettingTumblr(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

    // �u�ݒ�_�C�A���O�v�ł́u�K�p�v�{�^������������
    void    Accept();

    // ���݂́u�ݒ�v���擾
    void    LoadSetting();

    void    SetCheckApplied();

    CString m_blogID;

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CSettingTumblr)
	enum { IDD = IDD_TAB_TUMBLR };
	BOOL	m_useTumblr;
	CString	m_username;
	CString	m_password;
	CString	m_blogName;
	//}}AFX_DATA

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CSettingTumblr)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CSettingTumblr)
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnUseTumblr();
	afx_msg void OnApplied();
	afx_msg void OnButtonSelectTarget();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
    CSettingTumblr( CSettingTumblr &dlg );
    CSettingTumblr  operator = ( CSettingTumblr &dlg );
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_SETTINGTUMBLR_H__CF4D808A_A0F4_40A0_8135_31141219E2A6__INCLUDED_)
