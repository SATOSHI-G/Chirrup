/*
 * SettingDialog.h  : Twitter �N���C�A���g chirrup
 *      CSettingDialog �N���X�̐錾����уC���^�[�t�F�C�X�̒�`
 *          written by H.Tsujimura  7 Jun 2007
 *
 *      Copyright (c) 2007, 2008 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/SettingDialog.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 17    08/08/22 18:41 Tsujimura543
 * �u�͂Ăȃn�C�N�v�Ή�
 * 
 * 16    08/07/08 15:45 Tsujimura543
 * OnInitDialog() ��錾����ʒu���ړ�
 * 
 * 15    08/07/08 15:41 Tsujimura543
 * �f�B�X�v���C�̏c�����̑傫��(����)�� 800px �ȉ��̏ꍇ�́A�\������
 * �_�C�A���O�̑傫�����c�����ɏ���������悤�ɂ��Ă݂�
 * 
 * 14    08/01/09 17:08 Tsujimura543
 * Flickr �Ή�
 * 
 * 13    07/12/10 16:39 Tsujimura543
 * Gyazo �Ή�
 * 
 * 12    07/11/26 17:46 Tsujimura543
 * �uproxy�ݒ�v�^�u��active�ɂȂ��Ă����ԂŋN���ł���I�v�V������ǉ�
 * 
 * 11    07/11/26 17:31 Tsujimura543
 * �uproxy�ݒ�v���^�u�̂P�Ƃ��Ď�荞��
 * 
 * 10    07/11/26 16:02 Tsujimura543
 * ���t�@�N�^�����O
 * 
 * 9     07/11/05 23:35 Tsujimura543
 * tumblr �ɑΉ�
 * 
 * 8     07/09/06 19:42 Tsujimura543
 * �_�~�[�̃R�s�[�R���X�g���N�^�A������Z�q�� private �Ƃ��ē����B
 * �m��Ȃ������Ƀ������m��(�Ɖ�����Y��)����������\����r���B
 * 
 * 7     07/08/25 0:14 Tsujimura543
 * �u�������v�ɑΉ�
 * 
 * 6     07/06/27 18:12 Tsujimura543
 * haru.fm �ɑΉ�
 * 
 * 5     07/06/20 14:06 Tsujimura543
 * Timelog �Ή���
 * 
 * 4     07/06/14 21:12 Tsujimura543
 * �u���������v�ɑΉ�
 * 
 * 3     07/06/14 16:58 Tsujimura543
 * Wassr �ɑΉ�
 * 
 * 2     07/06/07 15:47 Tsujimura543
 * CTabDialog �𓱓��A�R�[�h�𐮗����Ă݂�
 * 
 * 1     07/06/07 1:43 Tsujimura543
 * �V�K�쐬 (�^�u�I���`���̐ݒ�_�C�A���O��V���ɗp�ӂ���)
 */

#if !defined(AFX_SETTINGDIALOG_H__14EE08E8_5445_4DB4_A528_B1D67BA4DBD5__INCLUDED_)
#define AFX_SETTINGDIALOG_H__14EE08E8_5445_4DB4_A528_B1D67BA4DBD5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SettingTwitter.h"
#include "SettingJaiku.h"
#include "SettingWassr.h"
#include "SettingMogo2.h"
#include "SettingTimelog.h"
#include "SettingHaruFm.h"
#include "SettingHatenaHaiku.h"
#include "SettingHatena.h"
#include "SettingTumblr.h"
#include "SettingGyazo.h"
#include "SettingFlickr.h"
#include "SettingProxy.h"

/////////////////////////////////////////////////////////////////////////////
// CSettingDialog �_�C�A���O

class CSettingDialog : public CDialog
{
// �R���X�g���N�V����
public:
	CSettingDialog(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CSettingDialog)
	enum { IDD = IDD_SETTING_DIALOG };
	CTabCtrl	m_tabSetting;
	//}}AFX_DATA

// �I�[�o�[���C�h
	//{{AFX_VIRTUAL(CSettingDialog)
	protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
public:
    CChirrupDlg         *m_chirrup;

#define NUM_OF_TABS     12                  // �^�u�̑���
    int                 m_numOfTabs;        // �^�u�̑���

    CDialog             *m_dlg[NUM_OF_TABS];// �e�^�u�ɓ\��t���Ă���_�C�A���O
    int                 m_activePage;       // �I������Ă���^�u
    bool                m_settingProxy; // �uproxy�ݒ�v�^�u��active��ԂŋN��

    // �_�C�A���O����
    CSettingTwitter     m_dlg00;
    CSettingJaiku       m_dlg01;
    CSettingWassr       m_dlg02;
    CSettingMogo2       m_dlg03;
    CSettingTimelog     m_dlg04;
    CSettingHaruFm      m_dlg05;
    CSettingHatenaHaiku m_dlg06;
    CSettingHatena      m_dlg07;
    CSettingTumblr      m_dlg08;
    CSettingGyazo       m_dlg09;
    CSettingFlickr      m_dlg10;
    CSettingProxy       m_dlg11;

    // �_�C�A���O���
    enum    {
        CS_TWITTER = 0,
        CS_JAIKU,
        CS_WASSR,
        CS_MOGO2,
        CS_TIMELOG,
        CS_HARUFM,
        CS_HATENAHAIKU,
        CS_HATENA,
        CS_TUMBLR,
        CS_GYAZO,
        CS_FLICKR,
        CS_PROXY
    };

    // �^�u�؂�ւ�
    int     DispCurrentTab( int activeTab = 0 );

protected:
    // �f�[�^�̐������`�F�b�N
    BOOL    CheckDlgData();

	// ���b�Z�[�W�}�b�v�֐�
	//{{AFX_MSG(CSettingDialog)
	afx_msg void OnButtonAccept();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
    CSettingDialog( CSettingDialog &dlg );
    CSettingDialog  operator = ( CSettingDialog &dlg );

    int     m_width;
    int     m_height;
    int     m_base;
    int     m_dialogWidth;
    bool    m_resized;
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_SETTINGDIALOG_H__14EE08E8_5445_4DB4_A528_B1D67BA4DBD5__INCLUDED_)
