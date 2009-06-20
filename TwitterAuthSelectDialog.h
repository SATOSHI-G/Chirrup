/*
 * TwitterAuthSelectDialog.h  : Twitter �N���C�A���g chirrup
 *      TwitterAuthSelectDialog �N���X�̐錾����уC���^�[�t�F�C�X�̒�`
 *          written by H.Tsujimura  31 Mar 2009
 *
 *      Copyright (c) 2009 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/TwitterAuthSelectDialog.h $
 * 
 * 2     09/05/15 2:34 tsupo
 * �u1.140�Ł�1.141�Łv�ł̕ύX�_����荞��
 * 
 * 2     09/05/14 14:52 Tsujimura543
 * ���[�U�����ݒ��ԂŖ{�_�C�A���O���N�������Ƃ��A���[�U������͌�A
 * ���W�I�{�^�����N���b�N����ƁA���[�U���̗����N���A����Ă��܂��s�
 * �ɑΏ�
 *
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 1     09/03/31 20:12 Tsujimura543
 * �ŏ��̔�
 */

#if !defined(AFX_TWITTERAUTHSELECTDIALOG_H__3AF04211_4EFA_4331_B597_3226D621FF1E__INCLUDED_)
#define AFX_TWITTERAUTHSELECTDIALOG_H__3AF04211_4EFA_4331_B597_3226D621FF1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// TwitterAuthSelectDialog �_�C�A���O

class TwitterAuthSelectDialog : public CDialog
{
// �R���X�g���N�V����
public:
	TwitterAuthSelectDialog(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

    bool    m_useOAuth;
    bool    m_useBASIC;
    CString m_oauthToken;
    CString m_oauthTokenSecret;

// �_�C�A���O �f�[�^
	//{{AFX_DATA(TwitterAuthSelectDialog)
	enum { IDD = IDD_TWITTER_AUTH_DIALOG };
	CString	m_username;
	CString	m_password;
	//}}AFX_DATA

// �I�[�o�[���C�h
	//{{AFX_VIRTUAL(TwitterAuthSelectDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(TwitterAuthSelectDialog)
	afx_msg void OnButtonGetToken();
	afx_msg void OnRadioBasic();
	afx_msg void OnRadioOauth();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

    void    ShowCurrentStatus( bool rescan = false );

private:
    TwitterAuthSelectDialog( TwitterAuthSelectDialog &dlg );
    TwitterAuthSelectDialog operator = ( TwitterAuthSelectDialog &dlg );
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_TWITTERAUTHSELECTDIALOG_H__3AF04211_4EFA_4331_B597_3226D621FF1E__INCLUDED_)
