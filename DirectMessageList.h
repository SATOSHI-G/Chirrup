/*
 * DirectMessageList.h : Twitter �N���C�A���g chirrup
 *      �_�C���N�g���b�Z�[�W�{���_�C�A���O �w�b�_�[�t�@�C��
 *          written by H.Tsujimura  25 Apr 2007
 *
 *      Copyright (c) 2007 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/DirectMessageList.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 12    09/03/31 23:29 Tsujimura543
 * Twitter �� OAuth �Ή����� ����7
 * 
 * 11    07/11/06 21:45 Tsujimura543
 * �R�����g���C��
 * 
 * 10    07/09/26 20:05 Tsujimura543
 * �_�C���N�g���b�Z�[�W�\���_�C�A���O����уv���t�B�[���\���_�C�A���O
 * �\���������C���_�C�A���O�̃X�e�[�^�X�o�[���X�V����悤�ɂ���
 * (�X�e�[�^�X�o�[�������낤�Ƃ���null�|�C���^�Q�Ƃŗ�����o�O�����)
 * 
 * 9     07/09/06 19:42 Tsujimura543
 * �_�~�[�̃R�s�[�R���X�g���N�^�A������Z�q�� private �Ƃ��ē����B
 * �m��Ȃ������Ƀ������m��(�Ɖ�����Y��)����������\����r���B
 * 
 * 8     07/06/22 17:42 Tsujimura543
 * �u��M�ҁv���\������悤�ɂ���
 * 
 * 7     07/06/21 22:11 Tsujimura543
 * Timelog �̃_�C���N�g���b�Z�[�W�̑���M�ɑΉ� (����m�F�ς�)
 * 
 * 6     07/06/21 20:26 Tsujimura543
 * Twitter�ȊO�ɂ��Ή�(�ł���悤�ɂ���)
 * 
 * 5     07/06/13 15:53 Tsujimura543
 * �_�C���N�g���b�Z�[�W�̍폜�@�\��ǉ�
 * 
 * 4     07/04/27 19:39 Tsujimura543
 * Twitter API �֘A�̏����� Twitter.cpp �ɏW�񂵂��̂ɔ����C�������{
 * 
 * 3     07/04/26 20:42 Tsujimura543
 * ���t�@�N�^�����O
 * 
 * 2     07/04/26 20:40 Tsujimura543
 * �_�C���N�g���b�Z�[�W�̖{���� URL ���܂܂��ꍇ�A�N���b�N�ł���悤�ɂ���
 * 
 * 1     07/04/26 0:20 Tsujimura543
 * �V�K�쐬
 */

#if !defined(AFX_DIRECTMESSAGELIST_H__ACC3DBA8_23E8_474C_A441_F9A0654727A2__INCLUDED_)
#define AFX_DIRECTMESSAGELIST_H__ACC3DBA8_23E8_474C_A441_F9A0654727A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDirectMessageList �_�C�A���O

class CDirectMessageList : public CDialog
{
// �R���X�g���N�V����
public:
	CDirectMessageList(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CDirectMessageList)
	enum { IDD = IDD_DIRECTMESSAGE_LIST_DIALOG };
	CRichEditEx	m_textCtrl;
	CString	m_sender;
	CString	m_dateTime;
	CString	m_recipient;
	//}}AFX_DATA

    CTwitterTimeline::SVC_TYPE  m_serviceType;
    TWITTER_DIRECT_MESSAGE      *m_dm;
    int                         m_numOfMessages;
    int                         m_currentIndex;

    CString                     m_cacheDir;
    CString                     m_screenName;
    CString                     m_username;
    CString                     m_password;

    CString                     m_oauthToken;
    CString                     m_oauthTokenSecret;
    bool                        m_useOAuth;

// �I�[�o�[���C�h
	//{{AFX_VIRTUAL(CDirectMessageList)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
    void    DisplayDirectMessage( int index );

	CString m_text;

	// ���b�Z�[�W�}�b�v�֐�
	//{{AFX_MSG(CDirectMessageList)
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnButtonNext();
	afx_msg void OnButtonPrev();
	afx_msg void OnButtonReply();
	afx_msg void OnButtonDelete();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
    CDirectMessageList( CDirectMessageList &dlg );
    CDirectMessageList  operator = ( CDirectMessageList &dlg );
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_DIRECTMESSAGELIST_H__ACC3DBA8_23E8_474C_A441_F9A0654727A2__INCLUDED_)
