/*
 * SettingJaiku.cpp : Twitter �N���C�A���g chirrup
 *      �ݒ�_�C�A���O(Jaiku) �C���v�������e�[�V���� �t�@�C��
 *          written by H.Tsujimura  7 Jun 2007
 *
 *      Copyright (c) 2007, 2008, 2009 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/SettingJaiku.cpp $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 9     09/04/16 17:39 Tsujimura543
 * �F�ؕ��@�I���_�C�A���O����߂��Ă����Ƃ��ɁA���[�U���ƃp�X���[�h��
 * ���f�����Y��Ă����̂𔽉f������悤�ɏC�� (OAuth�Ή����̃o�O)
 * 
 * 8     09/04/16 1:31 Tsujimura543
 * ShowCurrentStatus() �ŕ\�����镶�����C��
 * 
 * 7     09/04/15 1:17 Tsujimura543
 * Jaiuku �� OAuth �Ή�����
 * 
 * 6     08/07/16 4:13 Tsujimura543
 * �u�������e�Ώہv�̐ݒ���u�ݒ�v�_�C�A���O�ł��ݒ�ł���悤�ɂ���
 * 
 * 5     07/08/31 19:22 Tsujimura543
 * �upersonal_key �̎擾���@�v�Ɋւ���q���g��\������悤�ɂ���
 * 
 * 4     07/06/13 0:12 Tsujimura543
 * (1) TIMELINE_INFO �֘A fix
 * (2) �����ݒ�t�@�C���ǂݏ�����V�������O�t�@�C���Ǘ��d�l�ɑΉ�������
 * 
 * 3     07/06/12 17:51 Tsujimura543
 * Twitter �� Jaiku �ŋ��ʉ��ł��镔���͋��ʉ����A���ʉ�����������
 * CTabDialog �Ɉڊ�
 * 
 * 2     07/06/07 15:47 Tsujimura543
 * CTabDialog �𓱓��A�R�[�h�𐮗����Ă݂�
 * 
 * 1     07/06/07 1:43 Tsujimura543
 * �V�K�쐬 (�^�u�I���`���̐ݒ�_�C�A���O��V���ɗp�ӂ���)
 */

#include "chirrup.h"
#include "chirrupDlg.h"
#include "SettingJaiku.h"
#include "JaikuAuthSelectDialog.h"

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/chirrup/SettingJaiku.cpp 1     09/05/14 3:50 tsupo $";
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSettingJaiku �_�C�A���O

CSettingJaiku::CSettingJaiku(CWnd* pParent /*=NULL*/)
	: CTabDialog(CSettingJaiku::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSettingJaiku)
	//}}AFX_DATA_INIT

    m_useOAuth = false;
    m_useBASIC = false;
    m_oauthToken       = _T("");
    m_oauthTokenSecret = _T("");
}

// �u�ݒ�_�C�A���O�v�ł́u�K�p�v�{�^������������
void CSettingJaiku::Accept()
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

        m_chirrup->SetJaiku( m_username, m_password,
                             m_oauthToken, m_oauthTokenSecret,
                             m_useOAuth, m_useBASIC,
                             m_checkMultiPost,
                             sFriendsTimeline,
                             sPublicTimeline,
                             sUserTimeline );
    }
}

// ���݂́u�ݒ�v���擾
void CSettingJaiku::LoadSetting()
{
    if ( !m_initialized ) {
        if ( m_chirrup ) {
            TIMELINE_INFO sFriendsTimeline;
            TIMELINE_INFO sPublicTimeline;
            TIMELINE_INFO sUserTimeline;

            BOOL    useOAuth = m_useOAuth ? TRUE : FALSE;
            BOOL    useBASIC = m_useBASIC ? TRUE : FALSE;
            m_chirrup->GetJaiku( m_username, m_password,
                                 m_oauthToken, m_oauthTokenSecret,
                                 useOAuth, useBASIC,
                                 m_checkMultiPost,
                                 sFriendsTimeline,
                                 sPublicTimeline,
                                 sUserTimeline );
            m_useOAuth = useOAuth ? true : false;
            m_useBASIC = useBASIC ? true : false;

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

        ShowCurrentStatus();
    }
}

void CSettingJaiku::DoDataExchange(CDataExchange* pDX)
{
	CTabDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSettingJaiku)
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_password);
	DDV_MaxChars(pDX, m_password, 64);
	//}}AFX_DATA_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CSettingJaiku �ǉ����\�b�h

void CSettingJaiku::ShowCurrentStatus()
{
    CStatic *sp = (CStatic *)GetDlgItem(IDC_CURRENT_AUTH);

    if ( !m_useOAuth && !m_useBASIC )
        sp->SetWindowText( _T("[���݂̐ݒ�: ���ݒ�]") );
    else if ( m_useOAuth )
        sp->SetWindowText( _T("[���݂̐ݒ�: OAuth�F�؂��g��]") );
    else
        sp->SetWindowText( _T("[���݂̐ݒ�: �]���̔F�؂��g��]") );
}

BEGIN_MESSAGE_MAP(CSettingJaiku, CTabDialog)
	//{{AFX_MSG_MAP(CSettingJaiku)
	ON_BN_CLICKED(IDC_BUTTON_SET_AUTH, OnButtonSetAuth)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSettingJaiku ���b�Z�[�W �n���h��

void CSettingJaiku::OnButtonSetAuth() 
{
    JaikuAuthSelectDialog dlg;

    dlg.m_username = m_username;
    dlg.m_password = m_password;
    dlg.m_oauthToken       = m_oauthToken;
    dlg.m_oauthTokenSecret = m_oauthTokenSecret;

    dlg.m_useOAuth = m_useOAuth;
    dlg.m_useBASIC = m_useBASIC;

    int result = dlg.DoModal();
    if ( result == IDOK ) {
        m_username = dlg.m_username;
        m_password = dlg.m_password;
        m_oauthToken       = dlg.m_oauthToken;
        m_oauthTokenSecret = dlg.m_oauthTokenSecret;

        m_useOAuth = dlg.m_useOAuth;
        m_useBASIC = dlg.m_useBASIC;

        CEdit   *p = (CEdit *)GetDlgItem(IDC_EDIT_USERNAME);
        p->SetWindowText( m_username );

        p = (CEdit *)GetDlgItem(IDC_EDIT_PASSWORD);
        p->SetWindowText( m_password );

        ShowCurrentStatus();
    }
}
