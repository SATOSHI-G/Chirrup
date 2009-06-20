/*
 * SettingTimelog.h  : Twitter �N���C�A���g chirrup
 *      CSettingTimelog �N���X�̐錾����уC���^�[�t�F�C�X�̒�`
 *          written by H.Tsujimura  20 Jun 2007
 *
 *      Copyright (c) 2007 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/SettingTimelog.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 3     07/09/06 19:42 Tsujimura543
 * �_�~�[�̃R�s�[�R���X�g���N�^�A������Z�q�� private �Ƃ��ē����B
 * �m��Ȃ������Ƀ������m��(�Ɖ�����Y��)����������\����r���B
 * 
 * 2     07/06/20 11:21 Tsujimura543
 * �]���ȍs���폜
 * 
 * 1     07/06/20 11:20 Tsujimura543
 * �V�K�쐬
 */

#if !defined(AFX_SETTINGTIMELOG_H__F048AB2C_F829_4B57_B7E8_03140C24D958__INCLUDED_)
#define AFX_SETTINGTIMELOG_H__F048AB2C_F829_4B57_B7E8_03140C24D958__INCLUDED_

#include "CTabDialog.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSettingTimelog �_�C�A���O

class CSettingTimelog : public CTabDialog
{
// �R���X�g���N�V����
public:
	CSettingTimelog(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CSettingTimelog)
	enum { IDD = IDD_TAB_TIMELOG };
	//}}AFX_DATA

    void    Accept();       // �u�ݒ�_�C�A���O�v�ł́u�K�p�v�{�^������������
    void    LoadSetting();  // ���݂́u�ݒ�v���擾

// �I�[�o�[���C�h
	//{{AFX_VIRTUAL(CSettingTimelog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// ���b�Z�[�W�}�b�v�֐�
	//{{AFX_MSG(CSettingTimelog)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
    CSettingTimelog( CSettingTimelog &dlg );
    CSettingTimelog operator = ( CSettingTimelog &dlg );
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_SETTINGTIMELOG_H__F048AB2C_F829_4B57_B7E8_03140C24D958__INCLUDED_)
