/*
 * TumblrEditDialog.h  : Twitter �N���C�A���g chirrup
 *      �摜�t�@�C���A�b�v���[�h�_�C�A���O �w�b�_�[�t�@�C��
 *          written by H.Tsujimura  6 Dec 2007
 *
 *      Copyright (c) 2007, 2008 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/UploadImageDialog.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 7     08/07/31 21:12 Tsujimura543
 * Wassr �ւ̃A�b�v���[�h�ɑΉ�
 * 
 * 6     08/02/07 22:36 Tsujimura543
 * copyright �\�����C�� (2008 ��ǉ�)
 * 
 * 5     08/01/24 14:46 Tsujimura543
 * �������e�Ώې؂�ւ��@�\������
 * 
 * 4     07/12/19 13:26 Tsujimura543
 * �A�b�v���[�h���悤�Ƃ��Ă���摜�t�@�C���̃v���r���[�\����ǉ�
 * 
 * 3     07/12/10 21:26 Tsujimura543
 * m_targetName ��ǉ�
 * 
 * 2     07/12/06 4:08 Tsujimura543
 * �]���ȃR�����g���폜
 * 
 * 1     07/12/06 4:07 Tsujimura543
 * �V�K�쐬
 */

#if !defined(AFX_UPLOADIMAGEDIALOG_H__611D9141_FB80_42D5_8B21_EB7984C25B3A__INCLUDED_)
#define AFX_UPLOADIMAGEDIALOG_H__611D9141_FB80_42D5_8B21_EB7984C25B3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CUploadImageDialog �_�C�A���O

class CUploadImageDialog : public CDialog
{
// �R���X�g���N�V����
public:
	CUploadImageDialog(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^
    ~CUploadImageDialog();

    CString m_targetName;

    bool    m_gyazo;
    bool    m_flickr;
    bool    m_tumblr;
    bool    m_hatenaFotolife;
    bool    m_wassr;

    bool    m_sim_gyazo;
    bool    m_sim_flickr;
    bool    m_sim_tumblr;
    bool    m_sim_hatenaFotolife;
    bool    m_sim_wassr;

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CUploadImageDialog)
	enum { IDD = IDD_UPLOAD_IMAGE_DIALOG };
	CString	m_filename;
	CString	m_caption;
	//}}AFX_DATA

// �I�[�o�[���C�h
	//{{AFX_VIRTUAL(CUploadImageDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
    HBITMAP m_bitmap;
    HCURSOR m_hCursor;

    bool    IsInner( int id, WORD wX, WORD wY );
    void    SetStaticEdge( int idx, bool status );

	// ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CUploadImageDialog)
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
    afx_msg void OnDisplayToolTip(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_UPLOADIMAGEDIALOG_H__611D9141_FB80_42D5_8B21_EB7984C25B3A__INCLUDED_)
