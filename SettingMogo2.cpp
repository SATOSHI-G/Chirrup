/*
 * SettingMogo2.cpp : Twitter �N���C�A���g chirrup
 *      �ݒ�_�C�A���O(��������) �C���v�������e�[�V���� �t�@�C��
 *          written by H.Tsujimura  14 Jun 2007
 *
 *      Copyright (c) 2007 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/SettingMogo2.cpp $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 2     08/07/16 4:13 Tsujimura543
 * �u�������e�Ώہv�̐ݒ���u�ݒ�v�_�C�A���O�ł��ݒ�ł���悤�ɂ���
 * 
 * 1     07/06/14 19:46 Tsujimura543
 * �V�K�쐬
 */

#include "chirrup.h"
#include "chirrupDlg.h"
#include "SettingMogo2.h"

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/chirrup/SettingMogo2.cpp 1     09/05/14 3:50 tsupo $";
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSettingMogo2 �_�C�A���O

CSettingMogo2::CSettingMogo2(CWnd* pParent /*=NULL*/)
	: CTabDialog(CSettingMogo2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSettingMogo2)
	//}}AFX_DATA_INIT
}

// �u�ݒ�_�C�A���O�v�ł́u�K�p�v�{�^������������
void CSettingMogo2::Accept()
{
    if ( m_initialized && m_chirrup ) {
        TIMELINE_INFO sFriendsTimeline;
        TIMELINE_INFO sPublicTimeline;
        TIMELINE_INFO sUserTimeline;

        setTimelineInfo( sFriendsTimeline,
                         m_logFile_friendsTimeline,
                         m_checkFriendsTimeline,
                         m_checkLogFileFriendsTimeline );

        setTimelineInfo( sPublicTimeline,
                         m_logFile_publicTimeline,
                         m_checkPublicTimeline,
                         m_checkLogFilePublicTimeline );

        setTimelineInfo( sUserTimeline,
                         m_logFile_userTimeline,
                         m_checkUserTimeline,
                         m_checkLogFileUserTimeline );

        m_chirrup->SetMogo2( m_username, m_password,
                             m_checkMultiPost,
                             sFriendsTimeline,
                             sPublicTimeline,
                             sUserTimeline );
    }
}

// ���݂́u�ݒ�v���擾
void CSettingMogo2::LoadSetting()
{
    if ( !m_initialized ) {
        if ( m_chirrup ) {
            TIMELINE_INFO sFriendsTimeline;
            TIMELINE_INFO sPublicTimeline;
            TIMELINE_INFO sUserTimeline;

            m_chirrup->GetMogo2( m_username, m_password,
                                 m_checkMultiPost,
                                 sFriendsTimeline,
                                 sPublicTimeline,
                                 sUserTimeline );

            getTimelineInfo( sFriendsTimeline,
                             m_logFile_friendsTimeline,
                             m_checkFriendsTimeline,
                             m_checkLogFileFriendsTimeline );

            getTimelineInfo( sPublicTimeline,
                             m_logFile_publicTimeline,
                             m_checkPublicTimeline,
                             m_checkLogFilePublicTimeline );

            getTimelineInfo( sUserTimeline,
                             m_logFile_userTimeline,
                             m_checkUserTimeline,
                             m_checkLogFileUserTimeline );
        }
    }
}

void CSettingMogo2::DoDataExchange(CDataExchange* pDX)
{
	CTabDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSettingMogo2)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSettingMogo2, CTabDialog)
	//{{AFX_MSG_MAP(CSettingMogo2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
