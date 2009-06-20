/*
 * CChannelWassr.h  : Wassr �N���C�A���g chirrup
 *      CChannelWassr �N���X�̐錾����уC���^�[�t�F�C�X�̒�`
 *          written by H.Tsujimura  1 Aug 2008
 *
 *      Copyright (c) 2008 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/ChannelWassr.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 1     08/08/02 3:40 Tsujimura543
 * �V�K�쐬 (���̂Ƃ���A�P�Ɉꗗ�\�����邾���̋@�\�����Ȃ�)
 */

#if !defined(AFX_CHANNELWASSR_H__F80A6B8A_FB03_481D_B4E3_E616BAE9EC11__INCLUDED_)
#define AFX_CHANNELWASSR_H__F80A6B8A_FB03_481D_B4E3_E616BAE9EC11__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CChannelWassr �_�C�A���O

class CChannelWassr : public CDialog
{
// �R���X�g���N�V����
public:
	CChannelWassr(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^
    ~CChannelWassr();

    WASSR_CHANNEL_LIST  *m_wassrChannelList;
    long                m_numOfChannels;

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CChannelWassr)
	enum { IDD = IDD_CHANNEL_WASSR };
	CListCtrl	m_listCtr;
	//}}AFX_DATA

// �I�[�o�[���C�h
	//{{AFX_VIRTUAL(CChannelWassr)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
#define CHNLLST_NUM_OF_COLUMNS   2

    CImageList  m_imglst;
    long        m_numOfColumns;

    _TCHAR      *m_columnLabel[CHNLLST_NUM_OF_COLUMNS];
    int         m_columnFmt[CHNLLST_NUM_OF_COLUMNS];
    int         m_columnWidth[CHNLLST_NUM_OF_COLUMNS];

	// ���b�Z�[�W�}�b�v�֐�
	//{{AFX_MSG(CChannelWassr)
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_CHANNELWASSR_H__F80A6B8A_FB03_481D_B4E3_E616BAE9EC11__INCLUDED_)
