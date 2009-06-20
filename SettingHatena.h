/*
 * SettingHatena.h  : Twitter �N���C�A���g chirrup
 *      CSettingHatena �N���X�̐錾����уC���^�[�t�F�C�X�̒�`
 *          written by H.Tsujimura  24 Aug 2007
 *
 *      Copyright (c) 2007, 2008 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/SettingHatena.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 3     08/01/19 2:10 Tsujimura543
 * �͂Ăȃt�H�g���C�t�Ή�
 * 
 * 2     07/09/06 19:42 Tsujimura543
 * �_�~�[�̃R�s�[�R���X�g���N�^�A������Z�q�� private �Ƃ��ē����B
 * �m��Ȃ������Ƀ������m��(�Ɖ�����Y��)����������\����r���B
 * 
 * 1     07/08/25 0:14 Tsujimura543
 * �ŏ��̔�
 */

#if !defined(AFX_SETTINGHATENA_H__451793F9_B9B5_4484_83A7_EC89547F4438__INCLUDED_)
#define AFX_SETTINGHATENA_H__451793F9_B9B5_4484_83A7_EC89547F4438__INCLUDED_

#include "CTabDialog2.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSettingHatena �_�C�A���O

class CSettingHatena : public CTabDialog2
{
// �R���X�g���N�V����
public:
	CSettingHatena(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

    // �u�ݒ�_�C�A���O�v�ł́u�K�p�v�{�^������������
    void    Accept();

    // ���݂́u�ݒ�v���擾
    void    LoadSetting();

    void    SetCheckApplied();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CSettingHatena)
	enum { IDD = IDD_TAB_HATENA };
	BOOL	m_useTwitStar;
	CString	m_username;
	CString	m_password;
	//}}AFX_DATA

// �I�[�o�[���C�h
	//{{AFX_VIRTUAL(CSettingHatena)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// ���b�Z�[�W�}�b�v�֐�
	//{{AFX_MSG(CSettingHatena)
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnUseTwitstar();
	afx_msg void OnApplied();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
    CSettingHatena( CSettingHatena &dlg );
    CSettingHatena  operator = ( CSettingHatena &dlg );
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_SETTINGHATENA_H__451793F9_B9B5_4484_83A7_EC89547F4438__INCLUDED_)
