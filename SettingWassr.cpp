/*
 * SettingWassr.cpp : Twitter �N���C�A���g chirrup
 *      �ݒ�_�C�A���O(Wassr) �C���v�������e�[�V���� �t�@�C��
 *          written by H.Tsujimura  14 Jun 2007
 *
 *      Copyright (c) 2007, 2008 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/SettingWassr.cpp $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 5     08/07/31 20:59 Tsujimura543
 * SetCheckFriendsTimeline() ��ǉ�
 * 
 * 4     08/07/31 20:13 Tsujimura543
 * OnButtonSettingUpload() ���C���Bm_applied �̒l�����f����Ȃ��s���
 * �C��
 * 
 * 3     08/07/31 19:34 Tsujimura543
 * �u�`�����l���v�Ɓu�摜�̓��e�v�ɑΉ�
 * 
 * 2     08/07/16 4:13 Tsujimura543
 * �u�������e�Ώہv�̐ݒ���u�ݒ�v�_�C�A���O�ł��ݒ�ł���悤�ɂ���
 * 
 * 1     07/06/14 16:58 Tsujimura543
 * �V�K�쐬 (����m�F�ς�)
 */

#include "chirrup.h"
#include "chirrupDlg.h"
#include "SettingWassr.h"
#include "SettingUploadWassr.h"

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/chirrup/SettingWassr.cpp 1     09/05/14 3:50 tsupo $";
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSettingWassr �_�C�A���O

CSettingWassr::CSettingWassr(CWnd* pParent /*=NULL*/)
	: CTabDialog(CSettingWassr::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSettingWassr)
	m_applied = FALSE;
	m_checkChannel = FALSE;
	//}}AFX_DATA_INIT

    m_writeLogfileForUpload = FALSE;
    m_logFilenameForUpload  = _T("");
}

void CSettingWassr::DoDataExchange(CDataExchange* pDX)
{
	CTabDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSettingWassr)
	DDX_Check(pDX, IDC_APPLIED, m_applied);
	DDX_Check(pDX, IDC_CHECK_CHANNEL, m_checkChannel);
	//}}AFX_DATA_MAP
}

// �u�ݒ�_�C�A���O�v�ł́u�K�p�v�{�^������������
void CSettingWassr::Accept()
{
    if ( m_initialized && m_chirrup ) {
        TIMELINE_INFO sFriendsTimeline;
        TIMELINE_INFO sPublicTimeline;
        TIMELINE_INFO sUserTimeline;

        setTimelineInfo( sFriendsTimeline,
                         m_logFile_friendsTimeline,
                         m_checkFriendsTimeline,
                         m_checkChannel,
                         m_checkLogFileFriendsTimeline );

        CTabDialog::setTimelineInfo(
                         sPublicTimeline,
                         m_logFile_publicTimeline,
                         m_checkPublicTimeline,
                         m_checkLogFilePublicTimeline );

        CTabDialog::setTimelineInfo(
                         sUserTimeline,
                         m_logFile_userTimeline,
                         m_checkUserTimeline,
                         m_checkLogFileUserTimeline );

        m_chirrup->SetWassr( m_username, m_password,
                             m_checkMultiPost,
                             m_applied,
                             m_writeLogfileForUpload,
                             m_logFilenameForUpload,
                             sFriendsTimeline,
                             sPublicTimeline,
                             sUserTimeline );
    }
}

// ���݂́u�ݒ�v���擾
void CSettingWassr::LoadSetting()
{
    if ( !m_initialized ) {
        if ( m_chirrup ) {
            TIMELINE_INFO sFriendsTimeline;
            TIMELINE_INFO sPublicTimeline;
            TIMELINE_INFO sUserTimeline;

            m_chirrup->GetWassr( m_username, m_password,
                                 m_checkMultiPost,
                                 m_applied,
                                 m_writeLogfileForUpload,
                                 m_logFilenameForUpload,
                                 sFriendsTimeline,
                                 sPublicTimeline,
                                 sUserTimeline );

            getTimelineInfo( sFriendsTimeline,
                             m_logFile_friendsTimeline,
                             m_checkFriendsTimeline,
                             m_checkChannel,
                             m_checkLogFileFriendsTimeline );

            CTabDialog::getTimelineInfo(
                             sPublicTimeline,
                             m_logFile_publicTimeline,
                             m_checkPublicTimeline,
                             m_checkLogFilePublicTimeline );

            CTabDialog::getTimelineInfo(
                             sUserTimeline,
                             m_logFile_userTimeline,
                             m_checkUserTimeline,
                             m_checkLogFileUserTimeline );
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
// CSettingWassr �ǉ����\�b�h

void CSettingWassr::SetCheckApplied()
{
    CButton *p = (CButton *)GetDlgItem(IDC_BUTTON_SETTING_UPLOAD);
    p->EnableWindow( m_applied );
}

void CSettingWassr::SetCheckFriendsTimeline()
{
    CButton *bp = (CButton *)GetDlgItem( IDC_CHECK_CHANNEL );
    bp->EnableWindow( m_checkFriendsTimeline );
}

void CSettingWassr::setTimelineInfo(
                        TIMELINE_INFO &s,
                        CString       logFile,
                        BOOL          checkTimeline,
                        BOOL          checkChannel,
                        BOOL          checkLogFile
                    )
{
    CTabDialog::setTimelineInfo( s, logFile, checkTimeline, checkLogFile );
    s.checkChannel = checkChannel ? true : false;
}

void CSettingWassr::getTimelineInfo(
                        TIMELINE_INFO s,
                        CString       &logFile,
                        BOOL          &checkTimeline,
                        BOOL          &checkChannel,
                        BOOL          &checkLogFile
                    )
{
    CTabDialog::getTimelineInfo( s, logFile, checkTimeline, checkLogFile );
    checkChannel = s.checkChannel ? TRUE : FALSE;
}

BEGIN_MESSAGE_MAP(CSettingWassr, CTabDialog)
	//{{AFX_MSG_MAP(CSettingWassr)
	ON_BN_CLICKED(IDC_BUTTON_SETTING_UPLOAD, OnButtonSettingUpload)
	ON_BN_CLICKED(IDC_APPLIED, OnApplied)
	ON_BN_CLICKED(IDC_CHECK_CHANNEL, OnCheckChannel)
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(IDC_CHECK_FRIENDS_TIMELINE, OnCheckFriendsTimeline)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSettingWassr ���b�Z�[�W �n���h��

void CSettingWassr::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CTabDialog::OnShowWindow(bShow, nStatus);

    if ( bShow ) {
        CButton *bp = (CButton *)GetDlgItem( IDC_CHECK_CHANNEL );
        bp->SetCheck( m_checkChannel );

        bp = (CButton *)GetDlgItem( IDC_APPLIED );
        bp->SetCheck( m_applied );

        SetCheckApplied();
        SetCheckFriendsTimeline();
    }
}

void CSettingWassr::OnButtonSettingUpload() 
{
    CSettingUploadWassr dlg;

    dlg.m_applied      = m_applied;
    dlg.m_writeLogfile = m_writeLogfileForUpload;
    dlg.m_logFilename  = m_logFilenameForUpload;

    int ret = dlg.DoModal();
    if ( ret == IDOK ) {
        m_applied               = dlg.m_applied;
        m_writeLogfileForUpload = dlg.m_writeLogfile;
        m_logFilenameForUpload  = dlg.m_logFilename;

        if ( !m_applied ) {
            CButton *bp = (CButton *)GetDlgItem( IDC_APPLIED );
            bp->SetCheck( m_applied );
            SetCheckApplied();
        }
    }
}

void CSettingWassr::OnApplied() 
{
    CButton *bp = (CButton *)GetDlgItem( IDC_APPLIED );
    m_applied = bp->GetCheck();

    SetCheckApplied();
}

void CSettingWassr::OnCheckChannel() 
{
    CButton *bp = (CButton *)GetDlgItem( IDC_CHECK_CHANNEL );
    m_checkChannel = bp->GetCheck();	
}

void CSettingWassr::OnCheckFriendsTimeline() 
{
    CTabDialog::OnCheckFriendsTimeline();
    SetCheckFriendsTimeline();
}
