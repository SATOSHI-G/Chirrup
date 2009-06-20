/*
 * TumblrEditDialog.h  : Twitter �N���C�A���g chirrup
 *      Tumblr(�� Quote)���e���e�ҏW�_�C�A���O �w�b�_�[�t�@�C��
 *          written by H.Tsujimura  6 Nov 2007
 *
 *      Copyright (c) 2007, 2008, 2009 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/TumblrEditDialog.h $
 * 
 * 2     09/05/31 20:42 tsupo
 * 1.142��
 * 
 * 5     09/05/29 19:22 Tsujimura543
 * ����A�J�E���g�ŕ��� tumbleblog ���J�݂��Ă���ꍇ�̓��e��
 * tumbleblog ���w�肵�Ă̓��e���\�ɂ���
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 4     09/03/12 19:26 Tsujimura543
 * CTumblrEditDialog �_�C�A���O���d�N���ł��Ȃ��悤�ɂ���
 * 
 * 3     09/03/10 17:48 Tsujimura543
 * CTumblrEditDialog �����[�_���_�C�A���O���烂�[�h���X�_�C�A���O�ɕύX
 * 
 * 2     08/02/12 23:21 Tsujimura543
 * �u�R�����g�v����ǉ�
 * 
 * 1     07/11/06 21:46 Tsujimura543
 * �ŏ��̔�
 */

#if !defined(AFX_TUMBLREDITDIALOG_H__E83ADE31_D70F_49F6_B5DE_467FFA1F4EA3__INCLUDED_)
#define AFX_TUMBLREDITDIALOG_H__E83ADE31_D70F_49F6_B5DE_467FFA1F4EA3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTumblrEditDialog �_�C�A���O

class CTumblrEditDialog : public CDialog
{
// �R���X�g���N�V����
protected:
	CTumblrEditDialog(CWnd* pParent = NULL);

public:
    static CTumblrEditDialog    *Instance();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CTumblrEditDialog)
	enum { IDD = IDD_TUMBLR_DIALOG };
	CString	m_quote;
	CString	m_title;
	CString	m_url;
	CString	m_comment;
	//}}AFX_DATA

    CString m_tumblrID;
    CString m_tumblrPassword;
    CString m_tumblrGroup;

// �I�[�o�[���C�h
	//{{AFX_VIRTUAL(CTumblrEditDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CTumblrEditDialog)
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
    CTumblrEditDialog( CTumblrEditDialog &dlg );
    CTumblrEditDialog   operator = ( CTumblrEditDialog &dlg );

    static CTumblrEditDialog    *m_instance;
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_TUMBLREDITDIALOG_H__E83ADE31_D70F_49F6_B5DE_467FFA1F4EA3__INCLUDED_)
