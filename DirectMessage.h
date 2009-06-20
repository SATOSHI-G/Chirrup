/*
 * DirectMessage.h : Twitter �N���C�A���g chirrup
 *      �_�C���N�g���b�Z�[�W���M�_�C�A���O �w�b�_�[�t�@�C��
 *          written by H.Tsujimura  25 Apr 2007
 *
 *      Copyright (c) 2007 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/DirectMessage.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 6     09/03/31 23:29 Tsujimura543
 * Twitter �� OAuth �Ή����� ����7
 * 
 * 5     07/09/06 19:42 Tsujimura543
 * �_�~�[�̃R�s�[�R���X�g���N�^�A������Z�q�� private �Ƃ��ē����B
 * �m��Ȃ������Ƀ������m��(�Ɖ�����Y��)����������\����r���B
 * 
 * 4     07/06/21 19:46 Tsujimura543
 * Timelog �ɂ��Ή�
 * 
 * 3     07/04/27 19:39 Tsujimura543
 * Twitter API �֘A�̏����� Twitter.cpp �ɏW�񂵂��̂ɔ����C�������{
 * 
 * 2     07/04/26 15:50 Tsujimura543
 * �v���t�B�[���A�C�R���Ƀc�[���`�b�v�\����ǉ�
 * 
 * 1     07/04/25 16:18 Tsujimura543
 * �ŏ��̔�
 */

#if !defined(AFX_DIRECTMESSAGE_H__B02D011D_95DF_4DC4_A3BB_54C9EE30D64B__INCLUDED_)
#define AFX_DIRECTMESSAGE_H__B02D011D_95DF_4DC4_A3BB_54C9EE30D64B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDirectMessage �_�C�A���O

class CDirectMessage : public CDialog
{
// �R���X�g���N�V����
public:
	CDirectMessage(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^
    ~CDirectMessage();

    HCURSOR                     m_hCursor;
    CFont                       m_cFont;
    TWITTER_USER                m_user;
    CString                     m_cacheDir;
    bool                        m_allocated;

    CString                     m_username;
    CString                     m_password;
    CString                     m_oauthToken;
    CString                     m_oauthTokenSecret;
    bool                        m_useOAuth;
    CTwitterTimeline::SVC_TYPE  m_serviceType;

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CDirectMessage)
	enum { IDD = IDD_DIRECTMESSAGE_DIALOG };
	CString	m_directMessage;
	//}}AFX_DATA

// �I�[�o�[���C�h
	//{{AFX_VIRTUAL(CDirectMessage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// ���b�Z�[�W�}�b�v�֐�
	//{{AFX_MSG(CDirectMessage)
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnProfileIcon();
    afx_msg void OnDisplayToolTip(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
    CDirectMessage( CDirectMessage &dlg );
    CDirectMessage  operator = ( CDirectMessage &dlg );
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_DIRECTMESSAGE_H__B02D011D_95DF_4DC4_A3BB_54C9EE30D64B__INCLUDED_)
