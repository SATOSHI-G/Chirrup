/*
 * SettingProxy.h  : Twitter �N���C�A���g chirrup
 *      CSettingProxy �N���X�̐錾����уC���^�[�t�F�C�X�̒�`
 *          written by H.Tsujimura  9 Mar 2007 / 6 Apr 2007 / 26 Nov 2007
 *
 *      Copyright (c) 2007 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/SettingProxy.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 4     08/12/19 20:50 Tsujimura543
 * UpdateDataEx() ��ǉ�
 * 
 * 3     07/11/26 18:04 Tsujimura543
 * proxy�ݒ�֘A�ڍs��ƁA����
 * 
 * 2     07/11/26 17:57 Tsujimura543
 * CProxyInfoDialog ��p�~���ACSettingProxy �Ɉڍs
 * 
 * 1     07/11/26 17:30 Tsujimura543
 * �ŏ��̔�
 */

#if !defined(AFX_SETTINGPROXY_H__EDD3BA49_903D_45FF_8677_BEF6EFAF382B__INCLUDED_)
#define AFX_SETTINGPROXY_H__EDD3BA49_903D_45FF_8677_BEF6EFAF382B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSettingProxy �_�C�A���O

class CSettingProxy : public CDialog
{
// �R���X�g���N�V����
public:
	CSettingProxy(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

    // �u�ݒ�_�C�A���O�v�ł́u�K�p�v�{�^������������
    void    Accept();

    // ���݂́u�ݒ�v���擾
    void    LoadSetting();

    // �ݒ肵�悤�Ƃ��Ă���l�̃`�F�b�N
    BOOL    UpdateDataEx();

    CChirrupDlg *m_chirrup;

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CSettingProxy)
	enum { IDD = IDD_TAB_PROXY };
	BOOL	m_useProxy;
	CString	m_proxyServerName;
	UINT	m_proxyPortNumber;
	CString	m_proxyUserName;
	CString	m_proxyPassword;
	//}}AFX_DATA

// �I�[�o�[���C�h
	//{{AFX_VIRTUAL(CSettingProxy)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
    bool    m_initialized;

	// ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CSettingProxy)
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnUseProxy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

    void SetCheckProxy();
    CSettingProxy( CSettingProxy &dlg );
    CSettingProxy   operator = ( CSettingProxy &dlg );
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_SETTINGPROXY_H__EDD3BA49_903D_45FF_8677_BEF6EFAF382B__INCLUDED_)
