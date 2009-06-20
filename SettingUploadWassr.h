/*
 * CSettingUploadWassr.h  : Wassr �N���C�A���g chirrup
 *      CSettingUploadWassr �N���X�̐錾����уC���^�[�t�F�C�X�̒�`
 *          written by H.Tsujimura  31 Jul 2008
 *
 *      Copyright (c) 2008 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/SettingUploadWassr.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 3     08/07/31 20:30 Tsujimura543
 * �_�~�[�̃R�s�[�R���X�g���N�^�A������Z�q�� private �Ƃ��ē����B
 * �m��Ȃ������Ƀ������m��(�Ɖ�����Y��)����������\����r���B
 * 
 * 2     08/07/31 20:26 Tsujimura543
 * �u�󋵂ɉ��������͉\/�s�̐ؑ֏����v���C��
 * 
 * 1     08/07/31 17:34 Tsujimura543
 * �V�K�쐬
 */

#if !defined(AFX_SETTINGUPLOADWASSR_H__B4430269_93D1_4DF9_ADCE_80A53556266B__INCLUDED_)
#define AFX_SETTINGUPLOADWASSR_H__B4430269_93D1_4DF9_ADCE_80A53556266B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSettingUploadWassr �_�C�A���O

class CSettingUploadWassr : public CDialog
{
// �R���X�g���N�V����
public:
	CSettingUploadWassr(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

    // ���O�t�@�C�����ݒ�
    void    InputFileName( CString &targetFilename, int id );

    // �摜�A�b�v���[�h�ΏۂƂ��邩�ۂ��̐ݒ�
    void    SetCheckApplied();

    // ���O�t�@�C�����c�����ۂ��̐ݒ�
    void    SetCheckWriteLogfile();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CSettingUploadWassr)
	enum { IDD = IDD_SETTING_UPLOAD_WASSR };
	BOOL	m_applied;
	BOOL	m_writeLogfile;
	CString	m_logFilename;
	//}}AFX_DATA

// �I�[�o�[���C�h
	//{{AFX_VIRTUAL(CSettingUploadWassr)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// ���b�Z�[�W�}�b�v�֐�
	//{{AFX_MSG(CSettingUploadWassr)
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnWriteLogfile();
	afx_msg void OnButtonFilespec();
	afx_msg void OnApplied();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
    CSettingUploadWassr( CSettingUploadWassr &dlg );
    CSettingUploadWassr operator = ( CSettingUploadWassr &dlg );
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_SETTINGUPLOADWASSR_H__B4430269_93D1_4DF9_ADCE_80A53556266B__INCLUDED_)
