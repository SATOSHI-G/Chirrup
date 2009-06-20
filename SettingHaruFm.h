/*
 * SettingHaruFm.h  : Twitter �N���C�A���g chirrup
 *      CSettingHaruFm �N���X�̐錾����уC���^�[�t�F�C�X�̒�`
 *          written by H.Tsujimura  27 Jun 2007
 *
 *      Copyright (c) 2007 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/SettingHaruFm.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 2     07/09/06 19:42 Tsujimura543
 * �_�~�[�̃R�s�[�R���X�g���N�^�A������Z�q�� private �Ƃ��ē����B
 * �m��Ȃ������Ƀ������m��(�Ɖ�����Y��)����������\����r���B
 * 
 * 1     07/06/27 14:11 Tsujimura543
 * �V�K�쐬
 */

#if !defined(AFX_SETTINGHARUFM_H__96BD8761_6129_4B7F_A9B3_07EE821E884B__INCLUDED_)
#define AFX_SETTINGHARUFM_H__96BD8761_6129_4B7F_A9B3_07EE821E884B__INCLUDED_

#include "CTabDialog.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSettingHaruFm �_�C�A���O

class CSettingHaruFm : public CTabDialog
{
// �R���X�g���N�V����
public:
	CSettingHaruFm(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

    void    Accept();       // �u�ݒ�_�C�A���O�v�ł́u�K�p�v�{�^������������
    void    LoadSetting();  // ���݂́u�ݒ�v���擾

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CSettingHaruFm)
	enum { IDD = IDD_TAB_HARUFM };
	//}}AFX_DATA

// �I�[�o�[���C�h
	//{{AFX_VIRTUAL(CSettingHaruFm)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// ���b�Z�[�W�}�b�v�֐�
	//{{AFX_MSG(CSettingHaruFm)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
    CSettingHaruFm( CSettingHaruFm &dlg );
    CSettingHaruFm  operator = ( CSettingHaruFm &dlg );
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_SETTINGHARUFM_H__96BD8761_6129_4B7F_A9B3_07EE821E884B__INCLUDED_)
