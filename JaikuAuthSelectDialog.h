/*
 * JaikuAuthSelectDialog.h  : Jaiku �N���C�A���g chirrup
 *      JaikuAuthSelectDialog �N���X�̐錾����уC���^�[�t�F�C�X�̒�`
 *          written by H.Tsujimura  14 Apr 2009
 *
 *      Copyright (c) 2009 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/JaikuAuthSelectDialog.h $
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
 * 1     09/04/14 23:36 Tsujimura543
 * �ŏ��̔�
 */

#if !defined(AFX_JAIKUAUTHSELECTDIALOG_H__311097BB_6721_4E4D_ADF7_CB435EE92C9D__INCLUDED_)
#define AFX_JAIKUAUTHSELECTDIALOG_H__311097BB_6721_4E4D_ADF7_CB435EE92C9D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// JaikuAuthSelectDialog �_�C�A���O

class JaikuAuthSelectDialog : public CDialog
{
// �R���X�g���N�V����
public:
	JaikuAuthSelectDialog(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^
    ~JaikuAuthSelectDialog();

    bool    m_useOAuth;
    bool    m_useBASIC;
    CString m_oauthToken;
    CString m_oauthTokenSecret;

// �_�C�A���O �f�[�^
	//{{AFX_DATA(JaikuAuthSelectDialog)
	enum { IDD = IDD_JAIKU_AUTH_DIALOG };
	CString	m_username;
	CString	m_password;
	//}}AFX_DATA

// �I�[�o�[���C�h
	//{{AFX_VIRTUAL(JaikuAuthSelectDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(JaikuAuthSelectDialog)
	afx_msg void OnButtonGetToken();
	afx_msg void OnRadioBasic();
	afx_msg void OnRadioOauth();
	afx_msg void OnUrlJaikuApiKey();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

    void    ShowCurrentStatus( bool rescan = false );

    HCURSOR m_hCursor;
    CFont   m_cFont;

private:
    JaikuAuthSelectDialog( JaikuAuthSelectDialog &dlg );
    JaikuAuthSelectDialog operator = ( JaikuAuthSelectDialog &dlg );
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_JAIKUAUTHSELECTDIALOG_H__311097BB_6721_4E4D_ADF7_CB435EE92C9D__INCLUDED_)
