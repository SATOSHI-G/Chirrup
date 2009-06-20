/*
 * CTabDialog2.h : Twitter �N���C�A���g chirrup
 *      CTabDialog2 �N���X�̐錾����уC���^�[�t�F�C�X�̒�`
 *          written by H.Tsujimura  10 Dec 2007 / 10 Jan 2008
 *
 *      Copyright (c) 2007, 2008 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/CTabDialog2.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 2     08/01/10 17:20 Tsujimura543
 * �R�����g���C��
 * 
 * 1     08/01/10 17:19 Tsujimura543
 * ��SettingGyazo.h�����ɐV�K�쐬 (SettingGyazo, SettingFlickr�̋��ʕ���
 * ��ێ�����N���X�Ƃ��Đ݌v�B����̑Ή��T�[�r�X�����������ł��e�Ղɂ�
 * ��ړI������)
 */

#ifndef __TAB_DIALOG2_H__
#define __TAB_DIALOG2_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTabDialog2 �_�C�A���O

class CTabDialog2 : public CDialog
{
// �R���X�g���N�V����
public:
    CTabDialog2( UINT nIDTemplate, CWnd* pParentWnd = NULL );

    // �u�ݒ�_�C�A���O�v�ł́u�K�p�v�{�^������������
    virtual void    Accept() = 0;

    // ���݂́u�ݒ�v���擾
    virtual void    LoadSetting() = 0;

    // ���O�t�@�C�����ݒ�
    void    InputFileName( CString &targetFilename, int id );

    // �摜�A�b�v���[�h�ΏۂƂ��邩�ۂ��̐ݒ�
    void    SetCheckApplied();

    // ���O�t�@�C�����c�����ۂ��̐ݒ�
    void    SetCheckWriteLogfile();

    CChirrupDlg *m_chirrup;

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CTabDialog2)
	BOOL	m_applied;
	BOOL	m_writeLogfile;
	CString	m_logFilename;
	//}}AFX_DATA

// �I�[�o�[���C�h
	//{{AFX_VIRTUAL(CTabDialog2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
    bool    m_initialized;

	// ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CTabDialog2)
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnButtonFilespec();
	afx_msg void OnApplied();
	afx_msg void OnWriteLogfile();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif  /* __TAB_DIALOG2_H__ */
