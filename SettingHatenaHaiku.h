/*
 * SettingHatenaHaiku.h  : �͂Ăȃn�C�N �N���C�A���g chirrup
 *      CSettingHatenaHaiku �N���X�̐錾����уC���^�[�t�F�C�X�̒�`
 *          written by H.Tsujimura  22 Aug 2008
 *
 *      Copyright (c) 2008 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/SettingHatenaHaiku.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 1     08/08/22 17:34 Tsujimura543
 * �V�K�쐬
 */

#if !defined(AFX_SETTINGHATENAHAIKU_H__11A61EDE_FEEF_4A64_9643_8D36FDC8300F__INCLUDED_)
#define AFX_SETTINGHATENAHAIKU_H__11A61EDE_FEEF_4A64_9643_8D36FDC8300F__INCLUDED_

#include "CTabDialog.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSettingHatenaHaiku �_�C�A���O

class CSettingHatenaHaiku : public CTabDialog
{
// �R���X�g���N�V����
public:
	CSettingHatenaHaiku(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^
    ~CSettingHatenaHaiku();

    void    Accept();       // �u�ݒ�_�C�A���O�v�ł́u�K�p�v�{�^������������
    void    LoadSetting();  // ���݂́u�ݒ�v���擾

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CSettingHatenaHaiku)
	enum { IDD = IDD_TAB_HATENAHAIKU };
	//}}AFX_DATA

// �I�[�o�[���C�h
	//{{AFX_VIRTUAL(CSettingHatenaHaiku)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// ���b�Z�[�W�}�b�v�֐�
	//{{AFX_MSG(CSettingHatenaHaiku)
	afx_msg void OnUrlHatenaHaikuSetting();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

    HCURSOR m_hCursor;
    CFont   m_cFont;

private:
    CSettingHatenaHaiku( CSettingHatenaHaiku &dlg );
    CSettingHatenaHaiku  operator = ( CSettingHatenaHaiku &dlg );
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_SETTINGHATENAHAIKU_H__11A61EDE_FEEF_4A64_9643_8D36FDC8300F__INCLUDED_)
