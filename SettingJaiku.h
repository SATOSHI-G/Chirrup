/*
 * SettingJaiku.h  : Twitter �N���C�A���g chirrup
 *      CSettingJaiku �N���X�̐錾����уC���^�[�t�F�C�X�̒�`
 *          written by H.Tsujimura  7 Jun 2007
 *
 *      Copyright (c) 2007, 2009 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/SettingJaiku.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 6     09/04/15 1:17 Tsujimura543
 * Jaiuku �� OAuth �Ή�����
 * 
 * 5     07/09/06 19:42 Tsujimura543
 * �_�~�[�̃R�s�[�R���X�g���N�^�A������Z�q�� private �Ƃ��ē����B
 * �m��Ȃ������Ƀ������m��(�Ɖ�����Y��)����������\����r���B
 * 
 * 4     07/08/31 19:22 Tsujimura543
 * �upersonal_key �̎擾���@�v�Ɋւ���q���g��\������悤�ɂ���
 * 
 * 3     07/06/12 17:51 Tsujimura543
 * Twitter �� Jaiku �ŋ��ʉ��ł��镔���͋��ʉ����A���ʉ�����������
 * CTabDialog �Ɉڊ�
 * 
 * 2     07/06/07 15:47 Tsujimura543
 * CTabDialog �𓱓��A�R�[�h�𐮗����Ă݂�
 * 
 * 1     07/06/07 1:43 Tsujimura543
 * �V�K�쐬 (�^�u�I���`���̐ݒ�_�C�A���O��V���ɗp�ӂ���)
 */

#if !defined(AFX_SETTINGJAIKU_H__2BDA6908_8B32_443C_917D_B20CB677A6CB__INCLUDED_)
#define AFX_SETTINGJAIKU_H__2BDA6908_8B32_443C_917D_B20CB677A6CB__INCLUDED_

#include "CTabDialog.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSettingJaiku �_�C�A���O

class CSettingJaiku : public CTabDialog
{
// �R���X�g���N�V����
public:
	CSettingJaiku(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

    void    Accept();       // �u�ݒ�_�C�A���O�v�ł́u�K�p�v�{�^������������
    void    LoadSetting();  // ���݂́u�ݒ�v���擾

    bool    m_useOAuth;
    bool    m_useBASIC;
    CString m_oauthToken;
    CString m_oauthTokenSecret;

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CSettingJaiku)
	enum { IDD = IDD_TAB_JAIKU };
	//}}AFX_DATA

// �I�[�o�[���C�h
	//{{AFX_VIRTUAL(CSettingJaiku)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// ���b�Z�[�W�}�b�v�֐�
	//{{AFX_MSG(CSettingJaiku)
	afx_msg void OnButtonSetAuth();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

    void    ShowCurrentStatus();

private:
    CSettingJaiku( CSettingJaiku &dlg );
    CSettingJaiku   operator = ( CSettingJaiku &dlg );
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_SETTINGJAIKU_H__2BDA6908_8B32_443C_917D_B20CB677A6CB__INCLUDED_)
