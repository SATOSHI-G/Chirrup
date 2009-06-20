/*
 * SettingTwitter.h  : Twitter �N���C�A���g chirrup
 *      CSettingTwitter �N���X�̐錾����уC���^�[�t�F�C�X�̒�`
 *          written by H.Tsujimura  7 Jun 2007
 *
 *      Copyright (c) 2007 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/SettingTwitter.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 8     09/03/31 21:27 Tsujimura543
 * Twitter �� OAuth �Ή����� ����5
 * 
 * 7     09/03/30 22:37 Tsujimura543
 * Twitter �� OAuth �Ή����� ����2
 * 
 * 6     07/09/06 19:42 Tsujimura543
 * �_�~�[�̃R�s�[�R���X�g���N�^�A������Z�q�� private �Ƃ��ē����B
 * �m��Ȃ������Ƀ������m��(�Ɖ�����Y��)����������\����r���B
 * 
 * 5     07/06/13 19:18 Tsujimura543
 * Twitter �� Replies �̉{���A���O�o�͂ɑΉ�
 * 
 * 4     07/06/12 17:51 Tsujimura543
 * Twitter �� Jaiku �ŋ��ʉ��ł��镔���͋��ʉ����A���ʉ�����������
 * CTabDialog �Ɉڊ�
 * 
 * 3     07/06/11 18:39 Tsujimura543
 * Twitter �� user_timeline �̉{�����T�|�[�g
 * 
 * 2     07/06/07 15:47 Tsujimura543
 * CTabDialog �𓱓��A�R�[�h�𐮗����Ă݂�
 * 
 * 1     07/06/07 1:43 Tsujimura543
 * �V�K�쐬 (�^�u�I���`���̐ݒ�_�C�A���O��V���ɗp�ӂ���)
 */

#if !defined(AFX_SETTINGTWITTER_H__A5999D22_180C_4DC7_BE21_5763B2A73D67__INCLUDED_)
#define AFX_SETTINGTWITTER_H__A5999D22_180C_4DC7_BE21_5763B2A73D67__INCLUDED_

#include "CTabDialog.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSettingTwitter �_�C�A���O

class CSettingTwitter : public CTabDialog
{
// �R���X�g���N�V����
public:
	CSettingTwitter(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

    void    Accept();       // �u�ݒ�_�C�A���O�v�ł́u�K�p�v�{�^������������
    void    LoadSetting();  // ���݂́u�ݒ�v���擾

    bool    m_useOAuth;
    bool    m_useBASIC;
    CString m_oauthToken;
    CString m_oauthTokenSecret;

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CSettingTwitter)
	enum { IDD = IDD_TAB_TWITTER };
	CString	m_logFile_replies;
	BOOL	m_checkReplies;
	BOOL	m_checkLogFileReplies;
	//}}AFX_DATA

// �I�[�o�[���C�h
	//{{AFX_VIRTUAL(CSettingTwitter)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// ���b�Z�[�W�}�b�v�֐�
	//{{AFX_MSG(CSettingTwitter)
	afx_msg void OnButtonFilespec4();
	afx_msg void OnCheckReplies();
	afx_msg void OnCheckReplies2();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnButtonSetAuth();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

    void    SetCheckReplies();
    void    ShowCurrentStatus();

private:
    CSettingTwitter( CSettingTwitter &dlg );
    CSettingTwitter operator = ( CSettingTwitter &dlg );
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_SETTINGTWITTER_H__A5999D22_180C_4DC7_BE21_5763B2A73D67__INCLUDED_)
