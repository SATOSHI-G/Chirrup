/*
 * FriendDialog.h  : Twitter �N���C�A���g chirrup
 *      �v���t�B�[���\���_�C�A���O �w�b�_�[�t�@�C��
 *          written by H.Tsujimura  14 Apr 2007
 *
 *      Copyright (c) 2007 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/FriendDialog.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 9     09/03/31 23:29 Tsujimura543
 * Twitter �� OAuth �Ή����� ����7
 * 
 * 8     07/11/06 21:45 Tsujimura543
 * �R�����g���C��
 * 
 * 7     07/09/06 19:42 Tsujimura543
 * �_�~�[�̃R�s�[�R���X�g���N�^�A������Z�q�� private �Ƃ��ē����B
 * �m��Ȃ������Ƀ������m��(�Ɖ�����Y��)����������\����r���B
 * 
 * 6     07/06/04 21:11 Tsujimura543
 * friend �� add �� remove ������ (for Twitter)
 * 
 * 5     07/04/26 20:56 Tsujimura543
 * �u�ŋ߂̔����v�� URL ���܂܂��ꍇ�́A�N���b�N�ł���悤�ɂ���
 * 
 * 4     07/04/26 15:50 Tsujimura543
 * �v���t�B�[���A�C�R���Ƀc�[���`�b�v�\����ǉ�
 * 
 * 3     07/04/24 23:47 Tsujimura543
 * �R�����g���C��
 * 
 * 2     07/04/23 16:45 Tsujimura543
 * (1) �u�ŋ߂̔����v��\������悤�ɂ���
 * (2) ���[�U�̃A�C�R�����N���b�N����ƁA���̃��[�U�� Twitter �y�[�W�ɔ�ׂ�
 *     �悤�ɂ���
 * 
 * 1     07/04/14 2:05 Tsujimura543
 * �ŏ��̔�
 */

#if !defined(AFX_FRIENDDIALOG_H__DB3048A5_DEBF_4446_ACF8_8EB460D8B0C5__INCLUDED_)
#define AFX_FRIENDDIALOG_H__DB3048A5_DEBF_4446_ACF8_8EB460D8B0C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFriendDialog �_�C�A���O

class CFriendDialog : public CDialog
{
// �R���X�g���N�V����
public:
	CFriendDialog(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^
	~CFriendDialog();

    HCURSOR         m_hCursor;
    CFont           m_cFont;
    TWITTER_USER    m_user;     // profile �\���Ώۃ��[�U
    CString         m_cacheDir;
    bool            m_allocated;
    enum dialogMode {
        SHOW_PROFILE,
        ADD_FRIEND,
        REMOVE_FRIEND
    }               m_mode;
    CString         m_username;
    CString         m_password;
    CString         m_oauthToken;
    CString         m_oauthTokenSecret;
    bool            m_useOAuth;

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CFriendDialog)
	enum { IDD = IDD_PROFILE_DIALOG };
	CRichEditEx	m_lastStatusCtrl;
	//}}AFX_DATA

// �I�[�o�[���C�h
	//{{AFX_VIRTUAL(CFriendDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// ���b�Z�[�W�}�b�v�֐�
	//{{AFX_MSG(CFriendDialog)
	afx_msg void OnFriendUrl();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnProfileIcon();
    afx_msg void OnDisplayToolTip(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	afx_msg void OnManageFriend();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
    CFriendDialog( CFriendDialog &dlg );
    CFriendDialog   operator = ( CFriendDialog &dlg );
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_FRIENDDIALOG_H__DB3048A5_DEBF_4446_ACF8_8EB460D8B0C5__INCLUDED_)
