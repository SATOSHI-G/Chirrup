/*
 * SettingFlickr.h  : Twitter �N���C�A���g chirrup
 *      CSettingFlickr �N���X�̐錾����уC���^�[�t�F�C�X�̒�`
 *          written by H.Tsujimura  9 Jan 2008
 *
 *      Copyright (c) 2008 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/SettingFlickr.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 4     09/04/22 21:11 Tsujimura543
 * �u�ݒ�v�_�C�A���O�����Flickr�F�؂̃A�N�Z�X�g�[�N��(frob)���擾�ł���
 * �悤�ɂ���
 * 
 * 3     08/01/10 17:51 Tsujimura543
 * �p���~�X���C��
 * 
 * 2     08/01/10 17:22 Tsujimura543
 * CTabDialog2 �𓱓����A�\�[�X�R�[�h�𐮗�����
 * 
 * 1     08/01/09 17:07 Tsujimura543
 * �V�K�쐬
 */

#if !defined(AFX_SETTINGFLICKR_H__5F242F58_0C7D_4E75_96E1_1FE9DDBBDEAC__INCLUDED_)
#define AFX_SETTINGFLICKR_H__5F242F58_0C7D_4E75_96E1_1FE9DDBBDEAC__INCLUDED_

#include "CTabDialog2.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSettingFlickr �_�C�A���O

class CSettingFlickr : public CTabDialog2
{
// �R���X�g���N�V����
public:
	CSettingFlickr(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

    // �u�ݒ�_�C�A���O�v�ł́u�K�p�v�{�^������������
    void    Accept();

    // ���݂́u�ݒ�v���擾
    void    LoadSetting();

    CString m_flickrToken;
    CString m_flickrUserName;

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CSettingFlickr)
	enum { IDD = IDD_TAB_FLICKR };
	//}}AFX_DATA

// �I�[�o�[���C�h
	//{{AFX_VIRTUAL(CSettingFlickr)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CSettingFlickr)
	afx_msg void OnButtonGetToken();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

    void    ShowCurrentStatus();

private:
    CSettingFlickr( CSettingFlickr &dlg );
    CSettingFlickr  operator = ( CSettingFlickr &dlg );
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_SETTINGFLICKR_H__5F242F58_0C7D_4E75_96E1_1FE9DDBBDEAC__INCLUDED_)
