/*
 * SettingWassr.h  : Twitter �N���C�A���g chirrup
 *      CSettingWassr �N���X�̐錾����уC���^�[�t�F�C�X�̒�`
 *          written by H.Tsujimura  14 Jun 2007
 *
 *      Copyright (c) 2007, 2008 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/SettingWassr.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 5     08/07/31 20:59 Tsujimura543
 * SetCheckFriendsTimeline() ��ǉ�
 * 
 * 4     08/07/31 19:34 Tsujimura543
 * �u�`�����l���v�Ɓu�摜�̓��e�v�ɑΉ�
 * 
 * 3     07/09/06 19:42 Tsujimura543
 * �_�~�[�̃R�s�[�R���X�g���N�^�A������Z�q�� private �Ƃ��ē����B
 * �m��Ȃ������Ƀ������m��(�Ɖ�����Y��)����������\����r���B
 * 
 * 2     07/06/20 11:21 Tsujimura543
 * �]���ȍs���폜
 * 
 * 1     07/06/14 16:58 Tsujimura543
 * �V�K�쐬 (����m�F�ς�)
 */

#if !defined(AFX_SETTINGWASSR_H__8A1786C7_48CB_4EE4_B031_72F4F30972CD__INCLUDED_)
#define AFX_SETTINGWASSR_H__8A1786C7_48CB_4EE4_B031_72F4F30972CD__INCLUDED_

#include "CTabDialog.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSettingWassr �_�C�A���O

class CSettingWassr : public CTabDialog
{
// �R���X�g���N�V����
public:
	CSettingWassr(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

    void    Accept();       // �u�ݒ�_�C�A���O�v�ł́u�K�p�v�{�^������������
    void    LoadSetting();  // ���݂́u�ݒ�v���擾
    void    SetCheckFriendsTimeline();
    void    SetCheckApplied();

    void    setTimelineInfo( TIMELINE_INFO &s,
                             CString       logFile,
                             BOOL          checkTimeline,
                             BOOL          checkChannel,
                             BOOL          checkLogFile );
    void    getTimelineInfo( TIMELINE_INFO s,
                             CString       &logFile,
                             BOOL          &checkTimeline,
                             BOOL          &checkChannel,
                             BOOL          &checkLogFile );

	CString	m_logFilenameForUpload;
	BOOL	m_writeLogfileForUpload;

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CSettingWassr)
	enum { IDD = IDD_TAB_WASSR };
	BOOL	m_applied;
	BOOL	m_checkChannel;
	//}}AFX_DATA

// �I�[�o�[���C�h
	//{{AFX_VIRTUAL(CSettingWassr)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// ���b�Z�[�W�}�b�v�֐�
	//{{AFX_MSG(CSettingWassr)
	afx_msg void OnButtonSettingUpload();
	afx_msg void OnApplied();
	afx_msg void OnCheckChannel();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnCheckFriendsTimeline();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
    CSettingWassr( CSettingWassr &dlg );
    CSettingWassr   operator = ( CSettingWassr &dlg );
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_SETTINGWASSR_H__8A1786C7_48CB_4EE4_B031_72F4F30972CD__INCLUDED_)
