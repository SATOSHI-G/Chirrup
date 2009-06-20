/*
 * CTabDialog.h : Twitter �N���C�A���g chirrup
 *      CTabDialog �N���X�̐錾����уC���^�[�t�F�C�X�̒�`
 *          written by H.Tsujimura  7 Jun 2007
 *
 *      Copyright (c) 2007 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/CTabDialog.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 6     08/07/16 4:13 Tsujimura543
 * �u�������e�Ώہv�̐ݒ���u�ݒ�v�_�C�A���O�ł��ݒ�ł���悤�ɂ���
 * 
 * 5     07/09/06 19:39 Tsujimura543
 * �\�[�X�R�[�h�𐮗�
 * 
 * 4     07/06/13 0:12 Tsujimura543
 * (1) TIMELINE_INFO �֘A fix
 * (2) �����ݒ�t�@�C���ǂݏ�����V�������O�t�@�C���Ǘ��d�l�ɑΉ�������
 * 
 * 3     07/06/12 17:54 Tsujimura543
 * (1) Twitter �� Jaiku �ŋ��ʉ��ł��镔���� CTagDialog �Ɉړ�
 * (2) �ݒ荀�ڂ�ǉ� (�{���ΏۂƂ��邩�A���O�̃t�@�C�����ɓ��t��t��
 *     ���邩)
 * 
 * 2     07/06/07 15:47 Tsujimura543
 * CTabDialog �𓱓��A�R�[�h�𐮗����Ă݂�
 * 
 * 1     07/06/07 15:45 Tsujimura543
 * �V�K�쐬 (SettingTwitter, SettingJaiku �̋��ʕ�����ێ�����N���X��
 * ���Đ݌v�B����̑Ή��T�[�r�X�����������ł��e�Ղɂ���ړI������)
 */

#ifndef __TAB_DIALOG_H__
#define __TAB_DIALOG_H__

/////////////////////////////////////////////////////////////////////////////
// CTabDialog �_�C�A���O

class CTabDialog : public CDialog
{
public:
    CTabDialog( UINT nIDTemplate, CWnd* pParentWnd = NULL );

    // �u�ݒ�_�C�A���O�v�ł́u�K�p�v�{�^������������
    virtual void    Accept() = 0;

    // ���݂́u�ݒ�v���擾
    virtual void    LoadSetting() = 0;

    // ���O�t�@�C�����ݒ�
    void    InputFileName( CString &targetFilename, int id );

    void setTimelineInfo( TIMELINE_INFO &s,
                          CString       logFile,
                          BOOL          checkTimeline,
                          BOOL          checkLogFile );
    void getTimelineInfo( TIMELINE_INFO s,
                          CString       &logFile,
                          BOOL          &checkTimeline,
                          BOOL          &checkLogFile );

    CChirrupDlg *m_chirrup;

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CTabDialog)
	CString	m_username;
	CString	m_password;
	CString	m_logFile_friendsTimeline;
	CString	m_logFile_publicTimeline;
	CString	m_logFile_userTimeline;
	BOOL	m_checkFriendsTimeline;
	BOOL	m_checkPublicTimeline;
	BOOL	m_checkUserTimeline;
	BOOL	m_checkLogFileFriendsTimeline;
	BOOL	m_checkLogFilePublicTimeline;
	BOOL	m_checkLogFileUserTimeline;
    BOOL    m_checkMultiPost;
	//}}AFX_DATA

// �I�[�o�[���C�h
	//{{AFX_VIRTUAL(CTabDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
    bool    m_initialized;

	// ���b�Z�[�W�}�b�v�֐�
	//{{AFX_MSG(CTabDialog)
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnButtonFilespec();
	afx_msg void OnButtonFilespec2();
	afx_msg void OnButtonFilespec3();
	afx_msg void OnCheckFriendsTimeline();
	afx_msg void OnCheckPublicTimeline();
	afx_msg void OnCheckUserTimeline();
	afx_msg void OnCheckPublicTimeline2();
	afx_msg void OnCheckUserTimeline2();
	afx_msg void OnCheckFriendsTimeline2();
	afx_msg void OnCheckMultiPost();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
    void SetCheckFriendsTimeline();
    void SetCheckPublicTimeline();
    void SetCheckUserTimeline();
    void SetCheckMultiPost();
};

#endif  /* __TAB_DIALOG_H__ */