/*
 * SettingMogo2.h  : Twitter �N���C�A���g chirrup
 *      CSettingMogo2 �N���X�̐錾����уC���^�[�t�F�C�X�̒�`
 *          written by H.Tsujimura  14 Jun 2007
 *
 *      Copyright (c) 2007 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/SettingMogo2.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 2     07/09/06 19:42 Tsujimura543
 * �_�~�[�̃R�s�[�R���X�g���N�^�A������Z�q�� private �Ƃ��ē����B
 * �m��Ȃ������Ƀ������m��(�Ɖ�����Y��)����������\����r���B
 * 
 * 1     07/06/14 19:46 Tsujimura543
 * �V�K�쐬
 */

#if !defined(AFX_SETTINGMOGO2_H__5BB4F9EC_25AE_4C92_97D0_C3EF0F2A3CF4__INCLUDED_)
#define AFX_SETTINGMOGO2_H__5BB4F9EC_25AE_4C92_97D0_C3EF0F2A3CF4__INCLUDED_

#include "CTabDialog.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSettingMogo2 �_�C�A���O

class CSettingMogo2 : public CTabDialog
{
// �R���X�g���N�V����
public:
	CSettingMogo2(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

    void    Accept();       // �u�ݒ�_�C�A���O�v�ł́u�K�p�v�{�^������������
    void    LoadSetting();  // ���݂́u�ݒ�v���擾

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CSettingMogo2)
	enum { IDD = IDD_TAB_MOGO2 };
	//}}AFX_DATA

// �I�[�o�[���C�h
	//{{AFX_VIRTUAL(CSettingMogo2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// ���b�Z�[�W�}�b�v�֐�
	//{{AFX_MSG(CSettingMogo2)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
    CSettingMogo2( CSettingMogo2 &dlg );
    CSettingMogo2   operator = ( CSettingMogo2 &dlg );
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_SETTINGMOGO2_H__5BB4F9EC_25AE_4C92_97D0_C3EF0F2A3CF4__INCLUDED_)
