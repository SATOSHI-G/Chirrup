/*
 * FriendDialog.cpp : Twitter �N���C�A���g chirrup
 *      �v���t�B�[���\���_�C�A���O �C���v�������e�[�V���� �t�@�C��
 *          written by H.Tsujimura  14 Apr 2007
 *
 *      Copyright (c) 2007 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/FriendDialog.cpp $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 17    09/03/31 23:29 Tsujimura543
 * Twitter �� OAuth �Ή����� ����7
 * 
 * 16    08/07/08 17:46 Tsujimura543
 * Wassr �� friend �� add �� remove �ɂ��Ή�����
 * 
 * 15    07/09/26 20:05 Tsujimura543
 * �_�C���N�g���b�Z�[�W�\���_�C�A���O����уv���t�B�[���\���_�C�A���O
 * �\���������C���_�C�A���O�̃X�e�[�^�X�o�[���X�V����悤�ɂ���
 * (�X�e�[�^�X�o�[�������낤�Ƃ���null�|�C���^�Q�Ƃŗ�����o�O�����)
 * 
 * 14    07/09/06 19:46 Tsujimura543
 * �]���ȃR�����g���폜
 * 
 * 13    07/06/27 18:13 Tsujimura543
 * haru.fm �ɑΉ�
 * 
 * 12    07/06/20 17:36 Tsujimura543
 * Timelog �Ή�
 * 
 * 11    07/06/18 18:52 Tsujimura543
 * LoadUserIcon() �𓱓����A���[�U�A�C�R���̕\����������{������
 * 
 * 10    07/06/15 19:40 Tsujimura543
 * Wassr �� �������� �ɑΉ�
 * 
 * 9     07/06/04 21:12 Tsujimura543
 * friend �� add/remove �������̃A�C�R���� ICONERROR ����
 * ICONINFORMATION �ɕύX
 * 
 * 8     07/06/04 21:11 Tsujimura543
 * friend �� add �� remove ������ (for Twitter)
 * 
 * 7     07/05/29 3:56 Tsujimura543
 * Jaiku (�� public_timeline �̉{��) �ɑΉ�
 * 
 * 6     07/04/27 19:31 Tsujimura543
 * URL �����ݒ�̏ꍇ�̓}�E�X�J�[�\���̌`���w�J�[�\���ɕς���̂�}��
 * 
 * 5     07/04/26 20:56 Tsujimura543
 * �u�ŋ߂̔����v�� URL ���܂܂��ꍇ�́A�N���b�N�ł���悤�ɂ���
 * 
 * 4     07/04/26 15:50 Tsujimura543
 * �v���t�B�[���A�C�R���Ƀc�[���`�b�v�\����ǉ�
 * 
 * 3     07/04/24 23:47 Tsujimura543
 * �R�����g���C��
 * 
 * 2     07/04/23 16:45 Tsujimura543
 * (1) �u�ŋ߂̔����v��\������悤�ɂ���
 * (2) ���[�U�̃A�C�R�����N���b�N����ƁA���̃��[�U�� Twitter �y�[�W�ɔ�ׂ�
 *     �悤�ɂ���
 * 
 * 1     07/04/14 2:05 Tsujimura543
 * �ŏ��̔�
 */

#include "chirrup.h"
#include "chirrupDlg.h"
#include "FriendDialog.h"
#include "wassr.h"
extern "C" {
#include "utility.h"
}

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/chirrup/FriendDialog.cpp 1     09/05/14 3:50 tsupo $";
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#if (WINVER >= 0x0500)
//#define IDC_HAND    MAKEINTRESOURCE(32649)
#ifdef IDC_HAND
#undef IDC_HAND
#endif
#endif /* WINVER >= 0x0500 */
#define IDC_HAND    IDC_HAND2

/////////////////////////////////////////////////////////////////////////////
// CFriendDialog �_�C�A���O

CFriendDialog::CFriendDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CFriendDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFriendDialog)
	//}}AFX_DATA_INIT

    m_hCursor = AfxGetApp()->LoadCursor( IDC_HAND );
    m_user.bitmap      = NULL;
    m_allocated        = false;
    m_mode             = SHOW_PROFILE;
    m_username         = _T("");
    m_password         = _T("");
    m_oauthToken       = _T("");
    m_oauthTokenSecret = _T("");
    m_useOAuth         = false;
}

CFriendDialog::~CFriendDialog()
{
    if ( m_allocated )
        if ( m_user.bitmap )
            DeleteObject( m_user.bitmap );
    m_cFont.DeleteObject();
}

void CFriendDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFriendDialog)
	DDX_Control(pDX, IDC_EDIT_LAST_STATUS, m_lastStatusCtrl);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFriendDialog, CDialog)
	//{{AFX_MSG_MAP(CFriendDialog)
	ON_BN_CLICKED(IDC_FRIEND_URL, OnFriendUrl)
	ON_WM_SHOWWINDOW()
	ON_WM_SETCURSOR()
	ON_BN_CLICKED(IDC_PROFILE_ICON, OnProfileIcon)
    ON_NOTIFY(TTN_NEEDTEXT, 0, OnDisplayToolTip)
	ON_BN_CLICKED(IDC_MANAGE_FRIEND, OnManageFriend)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFriendDialog ���b�Z�[�W �n���h��

BOOL CFriendDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();

    EnableToolTips(TRUE);

	return TRUE;
}

void CFriendDialog::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
    if ( bShow ) {
        LOGFONT tLogFont;
        CFont   *cWndFont;

        cWndFont = GetFont(); 
        cWndFont->GetLogFont( &tLogFont );
        tLogFont.lfUnderline = 1;
        m_cFont.CreateFontIndirect( &tLogFont );

        CStatic *s = (CStatic *)GetDlgItem( IDC_PROFILE_ICON );
        CTwitterTimeline::SVC_TYPE  type = CTwitterTimeline::SVC_TWITTER;
        m_allocated = LoadUserIcon( s, &m_user, type, m_cacheDir );

        s = (CStatic *)GetDlgItem( IDC_DESCRIPTION );
        s->SetWindowText( m_user.description );

        s = (CStatic *)GetDlgItem( IDC_NAME );
        s->SetWindowText( m_user.name );

        s = (CStatic *)GetDlgItem( IDC_SCREENNAME );
        s->SetWindowText( m_user.screenName );

        s = (CStatic *)GetDlgItem( IDC_LOCATION );
        s->SetWindowText( m_user.location );

        s = (CStatic *)GetDlgItem( IDC_FRIEND_URL );
        s->SetWindowText( m_user.url );
        s->SetFont( &m_cFont, TRUE );   // URL�������t���ŕ\������

        CString title = m_user.screenName;
        title += "����̃v���t�B�[��";
        this->SetWindowText( title );

        char    lastStatus[MAX_DESCRIPTION_LEN];

        if ( m_user.lastStatus[0] )
            strcpy( lastStatus, m_user.lastStatus );
        else {
            lastStatus[0] = NUL;
            getLastStatus( m_user.screenName, lastStatus );
        }

        m_lastStatusCtrl.SetAutoUrlDetect();
        m_lastStatusCtrl.SetWindowText( lastStatus[0]
                                            ? lastStatus
                                            : _T("...") );

        CButton *bp = (CButton *)GetDlgItem( IDC_MANAGE_FRIEND );
        if ( m_mode == SHOW_PROFILE ) {
            bp->ShowWindow( SW_HIDE );
        }
        else {
            bp->ShowWindow( SW_SHOW );
            if ( m_mode == ADD_FRIEND )
                bp->SetWindowText( "friend �ɂ���" );
            else
                bp->SetWindowText( "friend ����O��" );

            bp = (CButton *)GetDlgItem( IDOK );
            bp->SetWindowText( "�L�����Z��" );
        }
    }	
}

void CFriendDialog::OnFriendUrl() 
{
    if ( !strncmp( m_user.url, "http://",  7 ) ||
         !strncmp( m_user.url, "https://", 8 )    ) {
	    CString cmd;
	    cmd = m_user.url;
        ShellExecute( NULL, "open", cmd, NULL, NULL, SW_SHOWNORMAL );
    }
}

void CFriendDialog::OnProfileIcon() 
{
    CString cmd = _T("");

    if ( strstr( m_user.profileImageURL, "jaiku.com" ) ||
         strstr( m_user.profileImageURL, "wassr.jp" )     ) {
        cmd = m_user.url;
    }
    else if ( strstr( m_user.profileImageURL, "mogo2.jp" ) ) {
	    cmd = _T("http://mogo2.jp/");
    	cmd += m_user.id;
    }
    else if ( strstr( m_user.profileImageURL, "timelog.jp" ) ) {
	    cmd = _T("http://timelog.jp/?");
    	cmd += m_user.id;
    }
    else if ( strstr( m_user.profileImageURL, "haru.fm" ) ) {
	    cmd = _T("http://haru.fm/mypost/");
    	cmd += m_user.id;
    }
    else {
	    cmd = _T("http://twitter.com/");
    	cmd += m_user.screenName;
    }
    ShellExecute( NULL, "open", cmd, NULL, NULL, SW_SHOWNORMAL );
}

BOOL CFriendDialog::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	if ( nHitTest == HTCLIENT ) {
        // URL �Ƀ}�E�X�|�C���^��������A�w�J�[�\����\������
		DWORD   dwPos = GetMessagePos();
		WORD    wX    = LOWORD( dwPos );
		WORD    wY    = HIWORD( dwPos );
		CPoint  poCursor( wX, wY );
		CRect   rcClient;

        CStatic *s;
        if ( m_user.url[0] ) {
            s = (CStatic *)GetDlgItem( IDC_FRIEND_URL );
            s->GetWindowRect( &rcClient );
            if ( (wX >= rcClient.left) && (wX <= rcClient.right)  &&
                 (wY >= rcClient.top)  && (wY <= rcClient.bottom)    ) {
			    SetCursor( m_hCursor );
                return TRUE;
            }
        }

        s = (CStatic *)GetDlgItem( IDC_PROFILE_ICON );
        s->GetWindowRect( &rcClient );
        if ( (wX >= rcClient.left) && (wX <= rcClient.right)  &&
             (wY >= rcClient.top)  && (wY <= rcClient.bottom)    ) {
			SetCursor( m_hCursor );
            return TRUE;
        }
	}

    m_lastStatusCtrl.m_chirrupDlg->SetPaneText( 0, _T(" ") );
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}

#ifdef  _MSC_VER
#pragma warning ( disable: 4100 )
#endif
void CFriendDialog::OnDisplayToolTip(NMHDR* pNMHDR, LRESULT* pResult)
{
    TOOLTIPTEXT *tp = (TOOLTIPTEXT *)pNMHDR;

    if ( (tp->uFlags & TTF_IDISHWND) == TTF_IDISHWND ) {
        int id = ::GetDlgCtrlID( (HWND)tp->hdr.idFrom );
        const char  *text = NULL;

        switch ( id ) {
        case IDC_PROFILE_ICON:
            text = m_user.screenName;
            break;
        }

        if ( text && *text )
            strcat( tp->szText, text );
    }
}
#ifdef  _MSC_VER
#pragma warning ( default: 4100 )
#endif

void CFriendDialog::OnManageFriend() 
{
    if ( m_mode == SHOW_PROFILE )
        return;

    if ( !m_useOAuth                         &&
         ((m_username.GetLength() == 0) ||
          (m_password.GetLength() == 0)    )    )
        return;

    bool    ret = false;

    if ( strstr( m_user.profileImageURL, "wassr.jp" ) ) {
        CWassr  t;
        t.m_username = m_username;
        t.m_password = m_password;

        if ( m_mode == ADD_FRIEND )
            ret = t.AddFriend( m_user.id );
        else if ( m_mode == REMOVE_FRIEND )
            ret = t.RemoveFriend( m_user.id );
    }
    else {
        CTwitter    t;
        t.m_username         = m_username;
        t.m_password         = m_password;
        t.m_useOAuth         = m_useOAuth;
        t.m_oauthToken       = m_oauthToken;
        t.m_oauthTokenSecret = m_oauthTokenSecret;

        if ( m_mode == ADD_FRIEND )
            ret = t.AddFriend( m_user.id );
        else if ( m_mode == REMOVE_FRIEND )
            ret = t.RemoveFriend( m_user.id );
    }

    if ( ret == false )
        MessageBox( m_mode == ADD_FRIEND
                        ? "friend �� add �Ɏ��s���܂�������  "
                        : "friend �� remove �Ɏ��s���܂���",
                    m_mode == ADD_FRIEND
                        ? "�t�����h�ǉ����s"
                        : "�t�����h�폜���s",
                    MB_OK|MB_ICONERROR );
    else {
        CString msg = m_user.screenName;
        msg += "����� friend ";
        msg += m_mode == ADD_FRIEND
                ? "�ɂ��܂����B    "
                : "����O���܂����B    ";

        MessageBox( msg,
                    m_mode == ADD_FRIEND
                        ? "�t�����h�ǉ�����"
                        : "�t�����h�폜����",
                    MB_OK|MB_ICONINFORMATION );

        m_mode = SHOW_PROFILE;
        CButton *bp = (CButton *)GetDlgItem( IDC_MANAGE_FRIEND );
        bp->ShowWindow( SW_HIDE );

        bp = (CButton *)GetDlgItem( IDOK );
        bp->SetWindowText( "OK" );
    }
}
