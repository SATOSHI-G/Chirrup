/*
 * SettingGyazo.h  : Twitter �N���C�A���g chirrup
 *      CSettingGyazo �N���X�̐錾����уC���^�[�t�F�C�X�̒�`
 *          written by H.Tsujimura  10 Dec 2007
 *
 *      Copyright (c) 2007, 2008 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/SettingGyazo.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 3     08/01/10 17:22 Tsujimura543
 * CTabDialog2 �𓱓����A�\�[�X�R�[�h�𐮗�����
 * 
 * 2     07/12/19 16:12 Tsujimura543
 * Tumblr �� Gyazo �ɃA�b�v���[�h�����t�@�C���� URL ���L�^����@�\��
 * �ǉ����邽�߂̃v���p�e�B��ǉ�
 * 
 * 1     07/12/10 16:38 Tsujimura543
 * �V�K�쐬
 */

#if !defined(AFX_SETTINGGYAZO_H__AF2C6374_830A_4ECF_AEE2_4FEF0B416342__INCLUDED_)
#define AFX_SETTINGGYAZO_H__AF2C6374_830A_4ECF_AEE2_4FEF0B416342__INCLUDED_

#include "CTabDialog2.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSettingGyazo �_�C�A���O

class CSettingGyazo : public CTabDialog2
{
// �R���X�g���N�V����
public:
	CSettingGyazo(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

    // �u�ݒ�_�C�A���O�v�ł́u�K�p�v�{�^������������
    void    Accept();

    // ���݂́u�ݒ�v���擾
    void    LoadSetting();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CSettingGyazo)
	enum { IDD = IDD_TAB_GYAZO };
	//}}AFX_DATA

// �I�[�o�[���C�h
	//{{AFX_VIRTUAL(CSettingGyazo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CSettingGyazo)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
    CSettingGyazo( CSettingGyazo &dlg );
    CSettingGyazo   operator = ( CSettingGyazo &dlg );
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_SETTINGGYAZO_H__AF2C6374_830A_4ECF_AEE2_4FEF0B416342__INCLUDED_)
