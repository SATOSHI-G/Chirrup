/*
 * SettingGyazo.cpp : Twitter �N���C�A���g chirrup
 *      �ݒ�_�C�A���O(Gyazo) �C���v�������e�[�V���� �t�@�C��
 *          written by H.Tsujimura  10 Dec 2007
 *
 *      Copyright (c) 2007, 2008 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/SettingGyazo.cpp $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 3     08/01/10 17:22 Tsujimura543
 * CTabDialog2 �𓱓����A�\�[�X�R�[�h�𐮗�����
 * 
 * 2     07/12/19 16:12 Tsujimura543
 * Tumblr �� Gyazo �ɃA�b�v���[�h�����t�@�C���� URL ���L�^����@�\��
 * �ǉ����邽�߂̃v���p�e�B��ǉ�
 * 
 * 1     07/12/10 16:38 Tsujimura543
 * �V�K�쐬
 */

#include "chirrup.h"
#include "chirrupDlg.h"
#include "SettingGyazo.h"

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/chirrup/SettingGyazo.cpp 1     09/05/14 3:50 tsupo $";
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSettingGyazo �_�C�A���O

CSettingGyazo::CSettingGyazo(CWnd* pParent /*=NULL*/)
	: CTabDialog2(CSettingGyazo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSettingGyazo)
	//}}AFX_DATA_INIT
}

// �u�ݒ�_�C�A���O�v�ł́u�K�p�v�{�^������������
void CSettingGyazo::Accept()
{
    if ( m_initialized && m_chirrup ) {
        m_chirrup->SetGyazo( m_applied, m_writeLogfile, m_logFilename );
    }
}

// ���݂́u�ݒ�v���擾
void CSettingGyazo::LoadSetting()
{
    if ( !m_initialized ) {
        if ( m_chirrup ) {
            m_chirrup->GetGyazo( m_applied, m_writeLogfile, m_logFilename );
        }
    }
}

void CSettingGyazo::DoDataExchange(CDataExchange* pDX)
{
	CTabDialog2::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSettingGyazo)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSettingGyazo, CTabDialog2)
	//{{AFX_MSG_MAP(CSettingGyazo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
