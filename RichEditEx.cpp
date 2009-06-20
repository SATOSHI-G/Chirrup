/*
 * RichEditEx.cpp  : Twitter �N���C�A���g chirrup
 *      URL �N���b�J�u���ȃ��b�`�G�f�B�b�g�R���g���[��
 *                                          �C���v�������e�[�V���� �t�@�C��
 *          written by H.Tsujimura  26 Apr 2007
 *
 *      Copyright (c) 2007, 2008, 2009 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/RichEditEx.cpp $
 * 
 * 2     09/05/31 20:42 tsupo
 * 1.142��
 * 
 * 74    09/05/29 19:22 Tsujimura543
 * ����A�J�E���g�ŕ��� tumbleblog ���J�݂��Ă���ꍇ�̓��e��
 * tumbleblog ���w�肵�Ă̓��e���\�ɂ���
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 73    09/04/16 16:26 Tsujimura543
 * Twitter �� OAuth �Ή����̃R�[�f�B���O�~�X�C�� (fav �֘A)
 * 
 * 72    09/04/16 3:39 Tsujimura543
 * Jaiku �̃R�����gID��\�������邽�߁ASetWhity() ��ύX(�b��)
 * 
 * 71    09/03/31 23:29 Tsujimura543
 * Twitter �� OAuth �Ή����� ����7
 * 
 * 70    09/03/12 19:26 Tsujimura543
 * CTumblrEditDialog �_�C�A���O���d�N���ł��Ȃ��悤�ɂ���
 * 
 * 69    09/03/10 17:48 Tsujimura543
 * CTumblrEditDialog �����[�_���_�C�A���O���烂�[�h���X�_�C�A���O�ɕύX
 * 
 * 68    09/03/09 17:13 Tsujimura543
 * DragStart() �� dataSource �̉���^�C�~���O�������Ɩ�肪�N����
 * (�܂��Q�ƒ��̃X���b�h�A�v���Z�X�����݂���ꍇ�͉�����Ă͂����Ȃ�)
 * ���Ƃ������B����^�C�~���O��ς��Ă݂�
 * 
 * 67    08/11/10 19:26 Tsujimura543
 * �������j���[�ɁwTwitter ���� [�V]�x�ƁwTwitter ���� [�{��]�x��ǉ�
 * 
 * 66    08/09/04 19:27 Tsujimura543
 * �͂Ăȃn�C�N �� source (from XXX) �ɑΉ�
 * 
 * 65    08/08/22 20:32 Tsujimura543
 * �u�͂Ăȃn�C�N�v�֘A�A���C��
 * 
 * 64    08/08/22 19:54 Tsujimura543
 * �u�͂Ăȃn�C�N�v�֘A�A����m�F�I��
 * 
 * 63    08/08/22 18:42 Tsujimura543
 * �u�͂Ăȃn�C�N�v�Ή�
 * 
 * 62    08/08/19 20:16 Tsujimura543
 * SetFavoriteOnTwitter() ���ďC��
 * 
 * 61    08/08/19 17:30 Tsujimura543
 * SetFavoriteOnTwitter() �� status ID �̒��o�����܂������Ȃ����Ƃ�
 * ����s����C��
 * 
 * 60    08/08/18 20:05 Tsujimura543
 * Twitter �� statusID ���w�肵�Ă� reply �ɑΉ����邽�߁A
 * �u>>statusID @���[�U���v�L�@�𓱓�����
 * 
 * 59    08/07/16 15:36 Tsujimura543
 * �n�[�h�R�[�f�B���O���Ă���ӏ����������炷
 * 
 * 58    08/07/16 15:27 Tsujimura543
 * Timelog �́u�]���v�ɑΉ�����
 * 
 * 57    08/07/08 14:51 Tsujimura543
 * Wassr �́u�C�C�l!�v�ɑΉ�
 * 
 * 56    08/03/18 11:52 Tsujimura543
 * �R�����g�𐮗�
 * 
 * 55    08/03/18 11:49 Tsujimura543
 * DragStart() �Ő������� InternetShortcut �t�@�C�������ςɂ���
 * (�t�@�C�������Œ肾�ƁA.NET Framework ��œ��삵�Ă���A�v���P�[�V����
 *  �փh���b�v�����Ƃ��ɁA�ŏ��Ƀh���b�v�����Ƃ��� URL ��񂪂����ƗL����
 *  �Ȃ��Ă��܂��Ă��āA�ʂ� URL ���h���b�v���Ă����f����Ȃ����Ƃ�������
 *  �����߁A�΍�Ƃ��āA�t�@�C������s�x�ς���悤�ɂ���)
 * 
 * 54    08/02/14 20:28 Tsujimura543
 * PostTumblr() ���C��
 * (�u�� �� &Lt; �ɉ�������A�� �� &Gt; �ɉ������肷�錏�̑΍�v�̈��)
 * 
 * 53    08/02/13 0:10 Tsujimura543
 * tumblr �ւ� Quote ���e���ɃR�����g����������ɓ��e�ł���悤�ɂ���
 * 
 * 52    08/02/07 22:36 Tsujimura543
 * copyright �\�����C�� (2008 ��ǉ�)
 * 
 * 51    08/02/05 23:28 Tsujimura543
 * alt+F �ɂ��u�����v�����N���́A�������񖳌��ɂ���
 * 
 * 50    08/02/05 23:11 Tsujimura543
 * alt+F �ł� ctrl+F �Ɠ������������s����悤�ɂ���
 * (�������Aalt+F �̏ꍇ�́A�Ȃ��������o��B�����o�Ȃ��悤�ɂ�����@�͕s��)
 * 
 * 49    08/02/05 22:38 Tsujimura543
 * Alt�L�[�� down/up ���o�������ǉ� (���̂Ƃ���AAlt�L�[�֘A�͖��g�p)
 * 
 * 48    08/02/05 22:29 Tsujimura543
 * F3�L�[�����ŕ������������AShift+F3�ŕ������������ɂȂ�悤�ɂ��Ă݂�
 * 
 * 47    08/02/05 21:37 Tsujimura543
 * m_findMatchCase �� m_findMatchWholeWord �̏����l�� true ����
 * false �ɕύX����
 * 
 * 46    08/02/05 21:33 Tsujimura543
 * F3�L�[�����ł��u�����v�@�\���N���ł���悤�ɂ���
 * 
 * 45    08/02/04 18:13 Tsujimura543
 * �����@�\����
 *   (1) ���������ւ̌������T�|�[�g
 *   (2) �����p�p�����[�^�̈ꎞ�L�����T�|�[�g
 *   (3) �I�[�g�X�N���[���Ή�
 * 
 * 44    08/02/01 23:16 Tsujimura543
 * m_findDialog->Create() �Ŏw�肷��t���O�̒l��ύX
 * 
 * 43    08/02/01 23:11 Tsujimura543
 * ctrl+F �ɂ��u�����v�������I�Ɏ���
 * 
 * 42    08/01/28 14:50 Tsujimura543
 * �������A���������A���C�ɓ���Atumblr �ւ̓��e�����s�����Ƃ��ɂ�
 * �_�C�A���O���o���悤�ɂ���
 * 
 * 41    07/12/20 15:26 Tsujimura543
 * Visual Studio 2005 �ɂ��R���p�C���`�F�b�N���ʂ𔽉f
 * 
 * 40    07/11/08 23:53 Tsujimura543
 * Twitter�����Abuzztter�AGoogle�AYahoo! �Ƃ̘A��(����)�@�\��ǉ�
 * 
 * 39    07/11/07 3:39 Tsujimura543
 * ���Ă��锭���� ���p���� Tumblr �֓��e����@�\���쐬
 * 
 * 38    07/09/27 20:57 Tsujimura543
 * �E�N���b�N�@�\���T�|�[�g(�I�𒆂̕�����̃N���b�v�{�[�h�ւ̃R�s�[�A
 * �\������Ă��镶����̑S�I��)
 * 
 * 37    07/09/27 18:35 Tsujimura543
 * �u���������v�ɑΉ�����
 * 
 * 36    07/09/18 22:29 Tsujimura543
 * �����N�̃h���b�O�� CF_HDROP �ɂ���(�f�X�N�g�b�v���t�H���_�ւ̃h���b�O
 * �ɂ��Ή�����)
 * 
 * 35    07/09/18 18:59 Tsujimura543
 * COleDataSource �ȕϐ����A�N���X���v���p�e�B���烍�[�J���ϐ��ɕύX
 * 
 * 34    07/09/18 16:59 Tsujimura543
 * �����N�̃h���b�O���T�|�[�g (���܂̂Ƃ��� CF_TEXT �Ƃ��đ��o���Ă���)
 * 
 * 33    07/09/14 19:13 Tsujimura543
 * �����N�������}�E�X�I�[�o�[�����Ƃ��ɁAURL ���X�e�[�^�X�o�[�ɕ\������
 * �悤�ɂ���
 * 
 * 32    07/09/12 18:30 Tsujimura543
 * OnLButtonDblClk() �����t�@�N�^�����O
 * 
 * 31    07/09/07 14:16 Tsujimura543
 * Timelog �� [link] �ɑΉ������e���ŃR�����g�Ԃ����̑}�������񐶐�
 * ���������܂��������Ȃ��Ȃ��Ă��܂��Ă������Ƃ������B�C�������{
 * 
 * 30    07/08/28 18:16 Tsujimura543
 * �u���C�ɓ���v�Ɓu�������v�̓o�^�������ɕ\������_�C�A���O�̌��f����
 * �C��
 * 
 * 29    07/08/27 16:35 Tsujimura543
 * �� ���N���b�N���Ă��A�^�[�Q�b�g�ƂȂ�URL�̐����Ɏ��s���āA�͂ĂȃX�^�[
 * �Ł�������Ƃ���܂ŏ������i�܂��ɏI����Ă��܂����Ƃ�����s���
 * �Ώ�
 * 
 * 28    07/08/25 1:53 Tsujimura543
 * �u�������v�Ή� (���ۂɁ�������)
 * 
 * 27    07/08/17 18:03 Tsujimura543
 * Twitter �� �� �@�\������
 * 
 * 26    07/08/16 19:53 Tsujimura543
 * Timelog �́u�����v�� permalink �֔�ׂ�悤�ɂ��� ([link] ���N���b�N)
 * 
 * 25    07/07/25 18:17 Tsujimura543
 * Wassr �̃����N�ɑΉ�
 * 
 * 24    07/07/23 15:01 Tsujimura543
 * Twitter �� source (from XXX) �ɑΉ�
 * 
 * 23    07/07/03 17:52 Tsujimura543
 * �\�[�X�𐮗�
 * 
 * 22    07/07/03 17:45 Tsujimura543
 * haru.fm �̃^�O�ɑΉ�
 * 
 * 21    07/07/03 14:55 Tsujimura543
 * haru.fm �̃R�����g�ɂ������N�𒣂�悤�ɂ���
 * 
 * 20    07/07/03 13:52 Tsujimura543
 * (1) Visual Studio 2005 �ł̃r���h���ʂ𔽉f
 * (2) Haru.fm �Ή�
 * 
 * 19    07/06/26 21:48 Tsujimura543
 * Jaiku �̃����N�֘A�A����
 * 
 * 18    07/06/26 19:53 Tsujimura543
 * ���������̃����N�ɑΉ�
 * 
 * 17    07/06/26 15:10 Tsujimura543
 * Jaiku �̃����N�ɑΉ�
 * 
 * 16    07/06/26 0:29 Tsujimura543
 * CRichEditEx �� m_timeline ��ǉ����ATwitter �� status �����N�֔��
 * ���߂̏������ȗ�������
 * 
 * 15    07/06/26 0:10 Tsujimura543
 * SetLinkTwitter() ��ǉ����ATwitter �� status �y�[�W�֒��ڔ�ׂ�悤�ɂ���
 * 
 * 14    07/06/25 23:13 Tsujimura543
 * SetLink(), SetLinkTimelog() ��ǉ�
 * 
 * 13    07/06/23 0:10 Tsujimura543
 * SetWhity() ��ύX�A���b�Z�[�WID(�X�e�[�^�XID)�̕\���̎d����ς��Ă݂�
 * 
 * 12    07/06/22 17:44 Tsujimura543
 * OnLButtonDblClk() ���C�� (�u>>���b�Z�[�WID�v�̒���ɑS�p�󔒕���������
 * �Ɣ����S�����R�s�[���Ă��܂����ۂɑΏ�)
 * 
 * 11    07/06/21 14:48 Tsujimura543
 * m_targetUser ��p�~
 * 
 * 10    07/06/21 14:45 Tsujimura543
 * �u�����v���_�u���N���b�N���������ŁA�u�����v���͗��ɃR�����g�Ԃ��p����
 * ���\���ł���悤�ɂ���
 * 
 * 9     07/06/21 1:09 Tsujimura543
 * OnLButtonDblClk() ���C���ATimelog �� status ID (���b�Z�[�WID��0����
 * �n�܂邱�Ƃ����邱�Ƃ�������������)
 * 
 * 8     07/06/20 21:16 Tsujimura543
 * �X�e�[�^�XID�̐F�͎b��
 * 
 * 7     07/06/20 21:08 Tsujimura543
 * SetWhity() ��ǉ�
 * 
 * 6     07/06/15 23:08 Tsujimura543
 * Jaiku �̃R�����g�ɂ��Ή�
 * 
 * 5     07/06/15 21:34 Tsujimura543
 * Wassr �́u���X�v�ɂ��Ή�
 * 
 * 4     07/06/15 21:23 Tsujimura543
 * �u���������v�̃R�����g���e�ɑΉ�
 * 
 * 3     07/04/28 0:22 Tsujimura543
 * m_targetUser ��ǉ��B�_�u���N���b�N�����s�� Twitter �̃X�N���[������
 * ���݂���Ίi�[����悤�ɂ���
 * 
 * 2     07/04/27 22:26 Tsujimura543
 * SetStrong() ��ǉ�
 * 
 * 1     07/04/26 20:16 Tsujimura543
 * �V�K�쐬
 */

#include "chirrup.h"
#include "chirrupDlg.h"
#include "TumblrEditDialog.h"
#include "RichEditEx.h"
#include "haruFm.h"
#include "wassr.h"
#include "timelog.h"
extern "C" {
#include "twitStar.h"
#include "tumblr.h"
#include "utility.h"
}

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/chirrup/RichEditEx.cpp 2     09/05/31 20:42 tsupo $";
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


static UINT WM_FINDREPLACE = ::RegisterWindowMessage(FINDMSGSTRING);

/////////////////////////////////////////////////////////////////////////////
// CRichEditEx

CRichEditEx::CRichEditEx()
{
    m_chirrupDlg              = NULL;
    m_serviceType             = CTwitterTimeline::SVC_TWITTER;
    m_username                = _T("");
    m_password                = _T("");
    m_hatenaID                = _T("");
    m_hatenaPassword          = _T("");
    m_twitterUseOAuth         = false;
    m_twitterOauthToken       = _T("");
    m_twitterOauthTokenSecret = _T("");
    m_text                    = _T("");
    m_active                  = false;

    m_findDialog         = NULL;
    m_findBuf            = NULL;
    m_findMatchCase      = false;
    m_findMatchWholeWord = false;
    m_findSearchDown     = true;
    m_shiftKeyDown       = false;
    m_altKeyDown         = false;
}

CRichEditEx::~CRichEditEx()
{
    if ( m_findBuf ) {
        delete m_findBuf;
        m_findBuf = NULL;
    }

    if ( m_findDialog ) {
        delete m_findDialog;
        m_findDialog = NULL;
    }
}

BEGIN_MESSAGE_MAP(CRichEditEx, CRichEditCtrl)
	//{{AFX_MSG_MAP(CRichEditEx)
    ON_NOTIFY_REFLECT_EX(EN_LINK, OnLink)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
    ON_WM_CHAR()
    ON_WM_KEYDOWN()
    ON_WM_KEYUP()
    ON_WM_SYSKEYDOWN()
    ON_WM_SYSKEYUP()
    ON_REGISTERED_MESSAGE( WM_FINDREPLACE, OnFind )
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRichEditEx �ǉ����\�b�h

void CRichEditEx::SetAutoUrlDetect()
{
    SendMessage( EM_AUTOURLDETECT, 1, 0 );

    long    evt =  GetEventMask();
    evt |= ENM_LINK | EN_SETFOCUS ;
    SetEventMask( evt );
}

// �w�蕶����������\��
void CRichEditEx::SetStrong( CString target )
{
    FINDTEXTEX  t;
    CHARFORMAT  c;
    char        buf[BUFSIZ];
    int         loc  = 0;
    int         len  = target.GetLength();
    bool        done = false;

    memset( buf, 0x00, BUFSIZ );
    strcpy( buf, target );

    SetSel( 0, -1 );
    GetSelectionCharFormat( c );
    c.dwMask    = CFM_BOLD;
    c.dwEffects = 0;
    SetSelectionCharFormat( c );
    SetSel( -1, -1 );

    do {
        t.chrg.cpMin = loc;
        t.chrg.cpMax = -1;
        t.lpstrText  = buf;

        FindText( FR_MATCHCASE, &t );

        if ( t.chrgText.cpMin >= 0 ) {
            SetSel( t.chrgText );
            GetSelectionCharFormat( c );
            c.dwMask    = CFM_BOLD;
            c.dwEffects = CFE_BOLD;
            SetSelectionCharFormat( c );
            SetSel( -1, -1 );

            loc = t.chrgText.cpMin + len + 1;
        }
        else
            done = true;
    } while ( !done );
}

void CRichEditEx::SetWhity()
{
    FINDTEXTEX  t1;
    FINDTEXTEX  t2;
    CHARFORMAT  c;
    char        buf1[BUFSIZ];
    char        buf2[BUFSIZ];
    int         loc     = 0;
    CString     target1 = _T("[ID: ");
    CString     target2 = _T("]");
    int         len     = target1.GetLength();
    bool        done    = false;

    memset( buf1, 0x00, BUFSIZ );
    strcpy( buf1, target1 );
    memset( buf2, 0x00, BUFSIZ );
    strcpy( buf2, target2 );

    SetSel( 0, -1 );
    GetSelectionCharFormat( c );
    c.dwMask    = CFM_COLOR;
    c.dwEffects = 0;
    SetSelectionCharFormat( c );
    SetSel( -1, -1 );

    do {
        done = true;
        t1.chrg.cpMin = loc;
        t1.chrg.cpMax = -1;
        t1.lpstrText  = buf1;

        FindText( FR_MATCHCASE, &t1 );

        if ( t1.chrgText.cpMin >= 0 ) {
            t2.chrg.cpMin = t1.chrgText.cpMin + len;
            t2.chrg.cpMax = -1;
            t2.lpstrText  = buf2;

            FindText( FR_MATCHCASE, &t2 );

            if ( t2.chrgText.cpMin >= 0 ) {
                SetSel( t1.chrgText.cpMin, t2.chrgText.cpMax );
                GetSelectionCharFormat( c );
                c.dwMask      = CFM_COLOR|CFM_SIZE;
             // c.dwEffects   = CFE_BOLD;
                if ( (t2.chrgText.cpMax - t1.chrgText.cpMin >= 48) &&
                     (t2.chrgText.cpMax - t1.chrgText.cpMin <= 70)    ) {
                    c.crTextColor = 0x00F0F0F0;   // 0x00bbggrr
                    c.yHeight = 1;
                }
                else {
                    c.crTextColor = 0x00BBCCDD;   // 0x00bbggrr
                    c.yHeight = 162;
                }
                SetSelectionCharFormat( c );
                SetSel( -1, -1 );

                loc  = t2.chrgText.cpMin + 1;
                done = false;
            }
        }
    } while ( !done );
}

void CRichEditEx::SetLinkTimelog()
{
    FINDTEXTEX  t1;
    FINDTEXTEX  t2;
    FINDTEXTEX  t3;
    CHARFORMAT  c;
    char        buf1[BUFSIZ];
    char        buf2[BUFSIZ];
    char        buf3[BUFSIZ];
    int         loc     = 0;
    CString     target1 = _T("[tag:");
    CString     target2 = _T("]");
    CString     target3 = _T(",");
    int         len1    = target1.GetLength();
    int         len2    = target2.GetLength();
    int         len3    = target3.GetLength();
    bool        done    = false;

    memset( buf1, 0x00, BUFSIZ );
    strcpy( buf1, target1 );
    memset( buf2, 0x00, BUFSIZ );
    strcpy( buf2, target2 );
    memset( buf3, 0x00, BUFSIZ );
    strcpy( buf3, target3 );

    do {
        done = true;
        t1.chrg.cpMin = loc;
        t1.chrg.cpMax = -1;
        t1.lpstrText  = buf1;

        FindText( FR_MATCHCASE, &t1 );

        if ( t1.chrgText.cpMin >= 0 ) {
            t2.chrg.cpMin = t1.chrgText.cpMin + len1;
            t2.chrg.cpMax = -1;
            t2.lpstrText  = buf2;
            FindText( FR_MATCHCASE, &t2 );

            t3.chrg.cpMin = t1.chrgText.cpMin + len1;
            t3.chrg.cpMax = -1;
            t3.lpstrText  = buf3;
            FindText( FR_MATCHCASE, &t3 );

            if ( t2.chrgText.cpMin >= 0 ) {
                if ( (t3.chrgText.cpMin < 0)                 ||
                     (t3.chrgText.cpMin > t2.chrgText.cpMin)    ) {
                    // [tag: xxx]
                    SetSel( t1.chrgText.cpMin + len1,
                            t2.chrgText.cpMax - len2 );
                    GetSelectionCharFormat( c );
                    c.dwMask      = CFM_LINK;
                    c.dwEffects   = CFE_LINK;
                    SetSelectionCharFormat( c );
                    SetSel( -1, -1 );
                }
                else if ( t3.chrgText.cpMin <= t2.chrgText.cpMin ) {
                    // [tag: xxx,
                    SetSel( t1.chrgText.cpMin + len1,
                            t3.chrgText.cpMax - len3 );
                    GetSelectionCharFormat( c );
                    c.dwMask      = CFM_LINK;
                    c.dwEffects   = CFE_LINK;
                    SetSelectionCharFormat( c );
                    SetSel( -1, -1 );

                    loc = t3.chrgText.cpMin + len3;

                    // yyy,...,
                    do {
                        done = true;
                        t3.chrg.cpMin = loc;
                        t3.chrg.cpMax = -1;
                        t3.lpstrText  = buf3;
                        FindText( FR_MATCHCASE, &t3 );

                        if ( (t3.chrgText.cpMin >= 0)                 &&
                             (t3.chrgText.cpMin <= t2.chrgText.cpMin)    ) {
                            SetSel( loc, t3.chrgText.cpMax - len3 );
                            GetSelectionCharFormat( c );
                            c.dwMask      = CFM_LINK;
                            c.dwEffects   = CFE_LINK;
                            SetSelectionCharFormat( c );
                            SetSel( -1, -1 );

                            loc = t3.chrgText.cpMin + len3;
                            done = false;
                        }
                    } while ( !done );

                    // ,zzz]
                    SetSel( loc, t2.chrgText.cpMax - len2 );
                    GetSelectionCharFormat( c );
                    c.dwMask      = CFM_LINK;
                    c.dwEffects   = CFE_LINK;
                    SetSelectionCharFormat( c );
                    SetSel( -1, -1 );
                }

                loc  = t2.chrgText.cpMin + len2;
                done = false;
            }
        }
    } while ( !done );
}

void CRichEditEx::SetLinkTimelog2()
{
    FINDTEXTEX  t1;
    CHARFORMAT  c;
    char        buf1[BUFSIZ];
    int         loc     = 0;
    CString     target1 = _T("[link][ID: ");
    int         len     = target1.GetLength();
    bool        done    = false;

    memset( buf1, 0x00, BUFSIZ );
    strcpy( buf1, target1 );

    do {
        done = true;
        t1.chrg.cpMin = loc;
        t1.chrg.cpMax = -1;
        t1.lpstrText  = buf1;

        FindText( FR_MATCHCASE, &t1 );

        if ( t1.chrgText.cpMin >= 0 ) {
            SetSel( t1.chrgText.cpMin + 1, t1.chrgText.cpMin + 5 );
            GetSelectionCharFormat( c );
            c.dwMask    = CFM_LINK;
            c.dwEffects = CFE_LINK;
            SetSelectionCharFormat( c );
            SetSel( -1, -1 );

            loc  = t1.chrgText.cpMin + len;
            done = false;
        }
    } while ( !done );
}

void CRichEditEx::SetLinkTwitter()
{
    FINDTEXTEX  t1;
    FINDTEXTEX  t2;
    CHARFORMAT  c;
    char        buf1[BUFSIZ];
    char        buf2[BUFSIZ];
    int         loc     = 0;
    CString     target1 = _T("[ID: ");
    CString     target2 = _T("]");
    int         len     = target1.GetLength();
    bool        done    = false;

    memset( buf1, 0x00, BUFSIZ );
    strcpy( buf1, target1 );
    memset( buf2, 0x00, BUFSIZ );
    strcpy( buf2, target2 );

    do {
        done = true;
        t1.chrg.cpMin = loc;
        t1.chrg.cpMax = -1;
        t1.lpstrText  = buf1;

        FindText( FR_MATCHCASE, &t1 );

        if ( t1.chrgText.cpMin >= 0 ) {
            t2.chrg.cpMin = t1.chrgText.cpMin + len;
            t2.chrg.cpMax = -1;
            t2.lpstrText  = buf2;

            FindText( FR_MATCHCASE, &t2 );

            if ( t2.chrgText.cpMin >= 0 ) {
                SetSel( t1.chrgText.cpMin + len, t2.chrgText.cpMax - 1 );
                GetSelectionCharFormat( c );
                c.dwMask    = CFM_LINK;
                c.dwEffects = CFE_LINK;
                SetSelectionCharFormat( c );
                SetSel( -1, -1 );

                loc  = t2.chrgText.cpMin + 1;
                done = false;
            }
        }
    } while ( !done );
}

void CRichEditEx::SetLinkTwitter2()
{
    FINDTEXTEX  t1;
    FINDTEXTEX  t2;
    CHARFORMAT  c;
    char        buf1[BUFSIZ];
    char        buf2[BUFSIZ];
    int         loc     = 0;
    CString     target1 = _T("(from *");
    CString     target2 = _T("*)");
    int         len     = target1.GetLength();
    bool        done    = false;

    memset( buf1, 0x00, BUFSIZ );
    strcpy( buf1, target1 );
    memset( buf2, 0x00, BUFSIZ );
    strcpy( buf2, target2 );

    do {
        done = true;
        t1.chrg.cpMin = loc;
        t1.chrg.cpMax = -1;
        t1.lpstrText  = buf1;

        FindText( FR_MATCHCASE, &t1 );

        if ( t1.chrgText.cpMin >= 0 ) {
            t2.chrg.cpMin = t1.chrgText.cpMin + len;
            t2.chrg.cpMax = -1;
            t2.lpstrText  = buf2;

            FindText( FR_MATCHCASE, &t2 );

            if ( t2.chrgText.cpMin >= 0 ) {
                SetSel( t1.chrgText.cpMin + len, t2.chrgText.cpMax - 2 );
                GetSelectionCharFormat( c );
                c.dwMask    = CFM_LINK;
                c.dwEffects = CFE_LINK;
                SetSelectionCharFormat( c );
                SetSel( -1, -1 );

                loc  = t2.chrgText.cpMin + 1;
                done = false;
            }
        }
    } while ( !done );
}

void CRichEditEx::SetLinkTwitter3()
{
    FINDTEXTEX  t1;
    FINDTEXTEX  t2;
    CHARFORMAT  c;
    char        buf1[BUFSIZ];
    char        buf2[BUFSIZ];
    int         loc     = 0;
    CString     target1 = _T("��[ID: ");
    CString     target2 = _T("�� / ��[ID: ");
    int         len1    = target1.GetLength();
    int         len2    = target2.GetLength();
    bool        done    = false;

    memset( buf1, 0x00, BUFSIZ );
    strcpy( buf1, target1 );
    memset( buf2, 0x00, BUFSIZ );
    strcpy( buf2, target2 );

    do {
        done = true;
        t1.chrg.cpMin = loc;
        t1.chrg.cpMax = -1;
        t1.lpstrText  = buf1;

        FindText( FR_MATCHCASE, &t1 );

        if ( t1.chrgText.cpMin >= 0 ) {
            SetSel( t1.chrgText.cpMin, t1.chrgText.cpMin + 2 );
            GetSelectionCharFormat( c );
            c.dwMask    = CFM_LINK;
            c.dwEffects = CFE_LINK;
            SetSelectionCharFormat( c );
            SetSel( -1, -1 );

            loc  = t1.chrgText.cpMin + len1;
            done = false;
        }
        else {
            t2.chrg.cpMin = loc;
            t2.chrg.cpMax = -1;
            t2.lpstrText  = buf2;

            FindText( FR_MATCHCASE, &t2 );

            if ( t2.chrgText.cpMin >= 0 ) {
                SetSel( t2.chrgText.cpMin, t2.chrgText.cpMin + 2 );
                GetSelectionCharFormat( c );
                c.dwMask    = CFM_LINK;
                c.dwEffects = CFE_LINK;
                SetSelectionCharFormat( c );
             // SetSel( -1, -1 );

                SetSel( t2.chrgText.cpMin + 5, t2.chrgText.cpMin + 7 );
                GetSelectionCharFormat( c );
                c.dwMask    = CFM_LINK;
                c.dwEffects = CFE_LINK;
                SetSelectionCharFormat( c );
                SetSel( -1, -1 );

                loc  = t2.chrgText.cpMin + len2;
                done = false;
            }
        }

    } while ( !done );
}

void CRichEditEx::SetLinkStar( bool useStar )
{
    FINDTEXTEX  t;
    CHARFORMAT  c;
    char        buf[BUFSIZ];
    int         loc    = 0;
    CString     target = _T("��[ID: ");
    int         len    = target.GetLength();
    bool        done   = false;

    if ( !useStar ) {
        target = _T("�� [ID: ");
        len    = target.GetLength();
    }

    memset( buf, 0x00, BUFSIZ );
    strcpy( buf, target );

    do {
        done = true;
        t.chrg.cpMin = loc;
        t.chrg.cpMax = -1;
        t.lpstrText  = buf;

        FindText( FR_MATCHCASE, &t );

        if ( t.chrgText.cpMin >= 0 ) {
            SetSel( t.chrgText.cpMin, t.chrgText.cpMin + 2 );
            GetSelectionCharFormat( c );
            c.dwMask    = CFM_LINK;
            c.dwEffects = CFE_LINK;
            SetSelectionCharFormat( c );
            SetSel( -1, -1 );

            loc  = t.chrgText.cpMin + len;
            done = false;
        }
    } while ( !done );
}

void CRichEditEx::SetLinkStar2()
{
    FINDTEXTEX  t;
    CHARFORMAT  c;
    char        buf[BUFSIZ];
    int         loc    = 0;
    CString     target = _T("�� [link][ID: ");
    int         len    = target.GetLength();
    bool        done   = false;

    memset( buf, 0x00, BUFSIZ );
    strcpy( buf, target );

    do {
        done = true;
        t.chrg.cpMin = loc;
        t.chrg.cpMax = -1;
        t.lpstrText  = buf;

        FindText( FR_MATCHCASE, &t );

        if ( t.chrgText.cpMin >= 0 ) {
            SetSel( t.chrgText.cpMin, t.chrgText.cpMin + 2 );
            GetSelectionCharFormat( c );
            c.dwMask    = CFM_LINK;
            c.dwEffects = CFE_LINK;
            SetSelectionCharFormat( c );
            SetSel( -1, -1 );

            loc  = t.chrgText.cpMin + len;
            done = false;
        }
    } while ( !done );
}

void CRichEditEx::SetLinkJaiku()
{
    FINDTEXTEX  t1;
    FINDTEXTEX  t2;
    FINDTEXTEX  t3;
    FINDTEXTEX  t4;
    FINDTEXTEX  t5;
    CHARFORMAT  c;
    char        buf1[BUFSIZ];
    char        buf2[BUFSIZ];
    char        buf3[BUFSIZ];
    char        buf4[BUFSIZ];
    char        buf5[BUFSIZ];
    int         loc     = 0;
    CString     target1 = _T(": ");
    CString     target2 = _T(" [ID: ");
    CString     target3 = _T("Comment from ");
    CString     target4 = _T(" on ");
    CString     target5 = _T("\r\n  ");
    int         len1    = target1.GetLength();
    int         len2    = target2.GetLength();
    int         len3    = target3.GetLength();
    int         len4    = target4.GetLength();
 // int         len5    = target5.GetLength();
    bool        done    = false;

    memset( buf1, 0x00, BUFSIZ );
    strcpy( buf1, target1 );
    memset( buf2, 0x00, BUFSIZ );
    strcpy( buf2, target2 );
    memset( buf3, 0x00, BUFSIZ );
    strcpy( buf3, target3 );
    memset( buf4, 0x00, BUFSIZ );
    strcpy( buf4, target4 );
    memset( buf5, 0x00, BUFSIZ );
    strcpy( buf5, target5 );

    do {
        done = true;
        t1.chrg.cpMin = loc;
        t1.chrg.cpMax = -1;
        t1.lpstrText  = buf1;

        FindText( FR_MATCHCASE, &t1 );

        if ( t1.chrgText.cpMin >= 0 ) {
            t2.chrg.cpMin = t1.chrgText.cpMin + len1;
            t2.chrg.cpMax = -1;
            t2.lpstrText  = buf2;

            FindText( FR_MATCHCASE, &t2 );

            if ( t2.chrgText.cpMin >= 0 ) {
                t3.chrg.cpMin = t1.chrgText.cpMin + len1;
                t3.chrg.cpMax = -1;
                t3.lpstrText  = buf3;

                FindText( FR_MATCHCASE, &t3 );

                if ( (t3.chrgText.cpMin >= 0)                &&
                     (t3.chrgText.cpMin < t2.chrgText.cpMin)    ) {
                    t4.chrg.cpMin = t3.chrgText.cpMin + len3;
                    t4.chrg.cpMax = -1;
                    t4.lpstrText  = buf4;

                    FindText( FR_MATCHCASE, &t4 );

                    if ( t4.chrgText.cpMin >= 0 ) {
                        t5.chrg.cpMin = t4.chrgText.cpMin + len4;
                        t5.chrg.cpMax = -1;
                        t5.lpstrText  = buf5;

                        FindText( FR_MATCHCASE, &t5 );

                        if ( t5.chrgText.cpMin >= 0 ) {
                            SetSel( t4.chrgText.cpMin + len4,
                                    t5.chrgText.cpMin );
                            GetSelectionCharFormat( c );
                            c.dwMask    = CFM_LINK;
                            c.dwEffects = CFE_LINK;
                            SetSelectionCharFormat( c );
                            SetSel( -1, -1 );
                        }
                    }
                }
                else {
                    SetSel( t1.chrgText.cpMin + len1, t2.chrgText.cpMin );

                    CString text = GetSelText();
                    if ( !strncmp( text, "http", 4 ) ) {
                        int l = text.Find( ' ' );
                        if ( l >= 0 ) {
                            SetSel( t1.chrgText.cpMin + len1 + l + 1,
                                    t2.chrgText.cpMin );
                        }
                    }

                    GetSelectionCharFormat( c );
                    c.dwMask    = CFM_LINK;
                    c.dwEffects = CFE_LINK;
                    SetSelectionCharFormat( c );
                    SetSel( -1, -1 );
                }

                loc  = t2.chrgText.cpMin + len2;
                done = false;
            }
        }
    } while ( !done );
}

void CRichEditEx::SetLinkMogo2()
{
    FINDTEXTEX  t1;
    CHARFORMAT  c;
    char        buf1[BUFSIZ];
    int         loc     = 0;
    CString     target1 = _T(">>");
    int         len     = target1.GetLength();
    bool        done    = false;

    memset( buf1, 0x00, BUFSIZ );
    strcpy( buf1, target1 );

    do {
        done = true;
        t1.chrg.cpMin = loc;
        t1.chrg.cpMax = -1;
        t1.lpstrText  = buf1;

        FindText( FR_MATCHCASE, &t1 );

        if ( t1.chrgText.cpMin >= 0 ) {
            SetSel( t1.chrgText.cpMin,
                    t1.chrgText.cpMin + len + MAX_KEYLENGTH );
            CString text = GetSelText();

            int     i;
            int     l = text.GetLength();
            char    cc;
            for ( i = 2; i < l; i++ ) {
               cc = text[i];
               if ( (cc >= '0') && (cc <= '9') )
                   continue;
               break;
            }

            SetSel( t1.chrgText.cpMin, t1.chrgText.cpMin + i );

            GetSelectionCharFormat( c );
            c.dwMask    = CFM_LINK;
            c.dwEffects = CFE_LINK;
            SetSelectionCharFormat( c );
            SetSel( -1, -1 );

            loc  = t1.chrgText.cpMax;
            done = false;
        }
    } while ( !done );
}

void CRichEditEx::SetLink()
{
    switch ( m_serviceType ) {
    case CTwitterTimeline::SVC_TWITTER:
        SetLinkTwitter();
        SetLinkTwitter2();
        SetLinkTwitter3();
        break;

    case CTwitterTimeline::SVC_JAIKU:
        SetLinkJaiku();
        break;
    
    case CTwitterTimeline::SVC_MOGO2:
        SetLinkMogo2();
        SetLinkTwitter();
        SetLinkStar( true );
        break;

    case CTwitterTimeline::SVC_TIMELOG:
        SetLinkTimelog();
        SetLinkStar2();
        SetLinkTimelog2();
        break;

    case CTwitterTimeline::SVC_HARUFM:
        SetLinkTwitter();
        SetLinkTimelog();
        break;

    case CTwitterTimeline::SVC_WASSR:
        SetLinkTwitter();
        SetLinkStar( false );
        break;

    case CTwitterTimeline::SVC_HATENAHAIKU:
        SetLinkTwitter();
        SetLinkTwitter2();
        SetLinkStar( true );
        break;
    }
}

void CRichEditEx::GetTargetUser( CString &targetUser, long startPos )
{
    char    *p, *q;
    CString text;

    SetSel( 0, -1 );
    text = GetSelText();
    SetSel( -1, -1 );

    char    *temp = new char[text.GetLength() + 2];
    if ( !temp )
        return;

    strcpy( temp, text );
    p = temp + startPos;
    while ( (p > temp) && (*p != '\n') )
        p--;
    if ( *p == '\n' )
        p++;

    q = strchr( p, ':' );
    if ( q ) {
        long    ss = p - temp;
        long    ee = q - temp;

        SetSel( ss, ee );
        text = GetSelText();
     // SetSel( -1, -1 );

        if ( text.GetLength() )
            targetUser = text;

        bool    mogo2 = false;
        if ( !strncmp( q + 2, ">>", 2 ) ) {
            // for ��������
            char    *r = q + 2;
            if ( (*(r + 2) >= '1') && (*(r + 2) <= '9') ) {
                char    *s = strchr( r, ' ' );
                char    *t = strstr( r, "�@");
                if ( t && s && (t < s) )
                    s = t;
                if ( s ) {
                    char    *temp2 = new char[(s - r) + 2];

                    if ( temp2 ) {
                        strncpy( temp2, r, s - r );
                        temp2[s - r] = NUL;
                        targetUser = temp2; // �㏑��

                        delete [] temp2;
                    }

                    mogo2 = true;
                }
            }
        }
        if (!mogo2                                           &&
         // (m_serviceType != CTwitterTimeline::SVC_TWITTER) &&
            (m_serviceType != CTwitterTimeline::SVC_HARUFM)     ) {
            // for Wassr, Jaiku, Timelog, ��������
            char    *r = strstr( q, " [ID: " );
            if ( !r ) {
                // for Timelog
                r = strstr( q, " [link][ID: " );
                if ( r )
                    r += 6;
            }
            if ( !r ) {
                // for Twitter
                r = strstr( q, "��[ID: " );
                if ( !r )
                    r = strstr( q, "��[ID: " );
                if ( r )
                    r += 1;
            }
            if ( r                                               &&
                 ( ((*(r + 6) >= '0') && (*(r + 6) <= '9')) ||
                   ((*(r + 6) >= 'a') && (*(r + 6) <= 'z')) ||
                   ((*(r + 6) >= 'A') && (*(r + 6) <= 'Z'))    )    ) {
                r += 6;

                char    *s = strchr( r, ']' );
                char    *t = strchr( r, '-' );  // for Jaiku
                if ( s && t && (s > t) )        // for Jaiku
                    s = t;                      // for Jaiku
                if ( s ) {
                    char    *u = strchr( r, '@' );  // for Timelog
                    if ( u )
                        if ( u > s )
                            u = NULL;

                    char    *temp2 = new char[(s - r) + 2 + (u ? 1 : 0)];
                    if ( temp2 ) {
                        if ( u ) {
                            // for Timelog
                            size_t  len = u - r;
                            strncpy( temp2, r, len );
                            temp2[len] = ' ';
                            strncpy( temp2 + (len + 1), u, s - u );
                            len = (len + 1) + (s - u);
                            temp2[len] = NUL;
                        }
                        else {
                            strncpy( temp2, r, s - r );
                            temp2[s - r] = NUL;
                        }

                        if (m_serviceType == CTwitterTimeline::SVC_TWITTER) {
                            // for Twitter
                            targetUser = _T(" @") + targetUser;
                            targetUser = temp2 + targetUser;
                            targetUser = _T(">>") + targetUser;
                        }
                        else {
                            targetUser = _T(">>");
                            targetUser += temp2;
                        }

                        delete [] temp2;
                    }

                    mogo2 = true;
                }
            }
        }
    }

    delete [] temp;
}

void CRichEditEx::GetTargetURL(
            CString &targetURL,
            CString &targetContent,
            long    startPos
        )
{
    const char	*p, *q, *r;
    CString		text;
    CString		url = _T("");

    SetSel( 0, -1 );
    text = GetSelText();
    SetSel( -1, -1 );

    char    *temp = new char[text.GetLength() + 2];
    if ( !temp )
        return;

    strcpy( temp, text );
    p = temp + startPos;
    while ( (p > temp) && (*p != '\n') )
        p--;
    if ( *p == '\n' )
        p++;

    r = q = strstr( p, " [ID: " );
    if ( !q ) {
        r = q = strstr( p, "��[ID: " );
        if ( !q )
            r = q = strstr( p, "��[ID: " );
        if ( q )
            q++;
    }
    if ( !q ) {
        // for Timelog
        r = q = strstr( p, " [link][ID: " );
        if ( q )
            q += 6;
    }
    if ( q                                               &&
         ( ((*(q + 6) >= '0') && (*(q + 6) <= '9')) ||
           ((*(q + 6) >= 'a') && (*(q + 6) <= 'z')) ||
           ((*(q + 6) >= 'A') && (*(q + 6) <= 'Z'))    )    ) {
        q += 6;

        const char  *s = strchr( q, ']' );
        const char	*t = strchr( q, '-' );  // for Jaiku
        if ( s && t && (s > t) )			// for Jaiku
            s = t;							// for Jaiku
        if ( s ) {
            char    buf[BUFSIZ];

            strncpy( buf, q, s - q );
            buf[s - q] = NUL;
            url = buf;
        }
    }

    if ( url.GetLength() > 0 ) {
        CString url2   = _T("");
        ENLINK  *pLink = NULL;

        switch ( m_serviceType ) {
        case CTwitterTimeline::SVC_TWITTER:
            GetLinkTwitter( url, url2, pLink );
            break;

        case CTwitterTimeline::SVC_JAIKU:
            GetLinkJaiku( url, url2 );
            break;

        case CTwitterTimeline::SVC_MOGO2:
            GetLinkMogo2( url, url2, pLink );
            break;

        case CTwitterTimeline::SVC_TIMELOG:
            GetLinkTimelog( url, url2, pLink );
            break;

        case CTwitterTimeline::SVC_HARUFM:
            GetLinkHaruFm( url, url2 );
            break;

        case CTwitterTimeline::SVC_WASSR:
            GetLinkWassr( url, url2, pLink );
            break;

        case CTwitterTimeline::SVC_HATENAHAIKU:
            GetLinkHatenaHaiku( url, url2, pLink );
            break;
        }

        if ( url2.GetLength() > 0 )
            targetURL = url2;
    }

    if ( targetContent.GetLength() > 0 ) {
        p = strstr( targetContent, "[ID:" );
        if ( p ) {
            char    *buf = new char[targetContent.GetLength() + 1];

            strcpy( buf, p );

            q = strstr( buf, "�� / ��[ID:" );
            if ( !q )
                q = strstr( buf, "��[ID:" );
            if ( !q )
                q = strstr( buf, "[link][ID:" );
            if ( !q )
                q = strstr( buf, "[ID:" );
            if ( q )
                *(char *)q = NUL;
            targetContent = buf;

            delete [] buf;
        }
    }
    else if ( r ) {
        char    *buf = new char[(r - p) + 1];

        strncpy( buf, p, r - p );
        buf[r - p] = NUL;
        targetContent = buf;

        delete [] buf;
    }

    delete [] temp;
}

void CRichEditEx::PostTumblr( CString targetURL, CString targetContent )
{
    CString             tagetTitle = decodeURL( getTitle( targetURL ) );
    CTumblrEditDialog   *dlg = CTumblrEditDialog::Instance();

    if ( dlg ) {
        dlg->ShowWindow( SW_HIDE );
        dlg->m_url     = targetURL;
        dlg->m_quote   = targetContent;
        dlg->m_title   = tagetTitle;
        dlg->m_comment = _T("");
        dlg->m_tumblrID       = m_tumblrID;
        dlg->m_tumblrPassword = m_tumblrPassword;
        dlg->m_tumblrGroup    = m_tumblrGroup;
        dlg->ShowWindow( SW_SHOW );
    }
}

bool
CRichEditEx::DragStart( CString &url )
{
    bool            ret         = false;
    COleDataSource  *dataSource = NULL;

#ifdef  DRAG_WITH_CF_TEXT
    HGLOBAL hData = GlobalAlloc( GHND, url.GetLength() + BUFSIZ );
    char    *ptr  = (char *)GlobalLock( hData );

    strcpy( ptr, url );
    GlobalUnlock( hData );

    dataSource = new COleDataSource;
    if ( dataSource ) {
        dataSource->Empty();
        dataSource->CacheGlobalData( CF_TEXT, hData );

        COleDropSource  ds;
        DROPEFFECT      dropEffect = dataSource->DoDragDrop(
                                        DROPEFFECT_COPY | DROPEFFECT_MOVE,
                                        NULL, &ds );
        if ( dropEffect == DROPEFFECT_MOVE ) {
            ret = true;
            url = _T("");
        }
    }
#else   /* !DRAG_WITH_CF_TEXT */
    char    filename[MAX_PATH];
    time_t  t = time(NULL);
    sprintf( filename, "%s\\chirrup_work_%d.url", getenv( "TEMP" ), t );

    FILE    *fp = fopen( filename, "w" );
    if ( fp ) {
        fprintf( fp, "[InternetShortcut]\nURL=%s\n", (const char *)url );
        fclose( fp );

        CRect   rcClient;
        m_chirrupDlg->GetWindowRect( &rcClient );

        DROPFILES   df;
        df.pFiles = sizeof ( DROPFILES );
        df.pt.x   = 0;
        df.pt.y   = 0;
        df.fNC    = FALSE;
        df.fWide  = FALSE;

        HGLOBAL hData = GlobalAlloc( GHND,
                                     sizeof ( DROPFILES ) +
                                                url.GetLength() + BUFSIZ );
        char    *ptr  = (char *)GlobalLock( hData );
        memcpy( (DROPFILES *)ptr, &df, sizeof ( DROPFILES ) );
        memcpy( ptr + sizeof ( DROPFILES ), filename, strlen(filename) + 1 );
        GlobalUnlock( hData );

        dataSource = new COleDataSource;
        if ( dataSource ) {
            dataSource->Empty();
            dataSource->CacheGlobalData( CF_HDROP, hData );

            CChirrupDropSource  ds;
            DROPEFFECT          dropEffect = dataSource->DoDragDrop(
                                                            DROPEFFECT_COPY |
                                                            DROPEFFECT_MOVE |
                                                            DROPEFFECT_LINK,
                                                            &rcClient, &ds );
            if ( (dropEffect != DROPEFFECT_NONE) ||
                 ds.isDragStarted()                 ) {
                ret = true;
                url = _T("");
            }
        }

        unlink( filename );
    }
#endif  /* !DRAG_WITH_CF_TEXT */

    if ( !ret )
        ShellExecute( NULL, "open", url, NULL, NULL, SW_SHOWNORMAL );

    if ( dataSource )
        delete dataSource;

    return ( ret );
}


void
CRichEditEx::SetFavoriteOnTwitter( CString &url, ENLINK *pLink )
{
    m_chirrupDlg->SetPaneText(0, _T("���C�ɓ���ɓo�^"));
    if ( pLink->msg == WM_SETCURSOR )
        return;

    bool        b = false;
    CHARRANGE   chrg;
    chrg.cpMin = pLink->chrg.cpMin + strlen("��[ID: ");
    chrg.cpMax = chrg.cpMin + MAX_NAMELEN;
    SetSel( chrg );
    url = GetSelText();
    SetSel( -1, -1 );
    if ( url.GetLength() >= 1 ) {
        char		buf[BUFSIZ];
        char		tmp[MAX_NAMELEN + 2];

        strncpy( tmp, url, MAX_NAMELEN );
        tmp[MAX_NAMELEN] = NUL;

        const char  *p = strchr( tmp, ':' );
        if ( p && (*(p + 1) == ' ') &&
             ((p == tmp) || ((p > tmp) && (*(p - 1) == 'D'))) )
            strcpy( buf, p + 2 );
        else
            strcpy( buf, url );
        p = strchr( buf, ']' );
        if ( p )
            *(char *)p = NUL;
        if ( (buf[0] >= '1')                          &&
             (buf[0] <= '9')                          &&
             (m_twitterUseOAuth                  ||
              ((m_username.GetLength() > 0) &&
               (m_password.GetLength() > 0)    )    )    ) {
            CWaitCursor cur;// �}�E�X�J�[�\���������v�\��
            CTwitter    t;
            t.m_username         = m_username;
            t.m_password         = m_password;
            t.m_useOAuth         = m_twitterUseOAuth;
            t.m_oauthToken       = m_twitterOauthToken;
            t.m_oauthTokenSecret = m_twitterOauthTokenSecret;
            b = t.SetFavorite( buf );
        }
    }

    if ( b ) {
        // ����
        MessageBox( "���C�ɓ���ɓo�^���܂���        ",
                    "���C�ɓ���o�^����",
                    MB_OK|MB_ICONINFORMATION );
    }
    else
        MessageBox( "���܁A������ƖZ�����́B"
                    "�܂��A���Ƃł�蒼���Ă�!    ",
                    "��������",
                    MB_OK|MB_ICONWARNING );
}

void
CRichEditEx::SetFavoriteOnWassr( CString &url, ENLINK *pLink )
{
    m_chirrupDlg->SetPaneText(0, _T("�C�C�l! �ɓo�^"));
    if ( pLink->msg == WM_SETCURSOR )
        return;

    bool        b = false;
    CHARRANGE   chrg;
    chrg.cpMin = pLink->chrg.cpMin + strlen("�� [ID: ");
    chrg.cpMax = chrg.cpMin + MAX_NAMELEN;
    SetSel( chrg );
    url = GetSelText();
    SetSel( -1, -1 );
    if ( url.GetLength() >= 1 ) {
        char		buf[BUFSIZ];
        strcpy( buf, url );
        char    *p = strchr( buf, ']' );
        if ( p )
            *(char *)p = NUL;
        if ( (m_username.GetLength() > 0) &&
             (m_password.GetLength() > 0)    ) {
            CWaitCursor cur;// �}�E�X�J�[�\���������v�\��
            CWassr      t;
            t.m_username = m_username;
            t.m_password = m_password;
            b = t.SetFavorite( buf );
        }
    }

    if ( b ) {
        // ����
        MessageBox( "�C�C�l! �ɓo�^���܂���        ",
                    "�C�C�l! �o�^����",
                    MB_OK|MB_ICONINFORMATION );
    }
    else
        MessageBox( "���܁A������ƖZ�����́B"
                    "�܂��A���Ƃł�蒼���Ă�!    ",
                    "�킳��",
                    MB_OK|MB_ICONWARNING );
}

void
CRichEditEx::SetFavoriteOnTimelog( CString &url, ENLINK *pLink )
{
    m_chirrupDlg->SetPaneText(0, _T("���̃������u�]���v"));
    if ( pLink->msg == WM_SETCURSOR )
        return;

    bool        b = false;
    CHARRANGE   chrg;
    chrg.cpMin = pLink->chrg.cpMin + strlen("�� [link][ID: ");
    chrg.cpMax = chrg.cpMin + MAX_KEYLENGTH + MAX_USERIDLEN;
    SetSel( chrg );
    url = GetSelText();
    SetSel( -1, -1 );
    if ( url.GetLength() >= 1 ) {
        char		buf[BUFSIZ];
        strcpy( buf, url );
        char    *p = strchr( buf, ']' );
        if ( p )
            *(char *)p = NUL;
        if ( (m_username.GetLength() > 0) &&
             (m_password.GetLength() > 0)    ) {
            CWaitCursor cur;// �}�E�X�J�[�\���������v�\��
            CTimelog    t;
            t.m_username = m_username;
            t.m_password = m_password;
            b = t.SetFavorite( buf );
        }
    }

    if ( b ) {
        // ����
        MessageBox( "�u�]���v���܂���        ",
                    "�u�]���v�o�^����",
                    MB_OK|MB_ICONINFORMATION );
    }
    else
        MessageBox( "���܁A������ƖZ�����́B"
                    "�܂��A���Ƃł�蒼���Ă�!    ",
                    "Timelog",
                    MB_OK|MB_ICONWARNING );
}

void
CRichEditEx::SetHatenaStarOnTwitter(
                CString &url,
                CString &url2,
                ENLINK *pLink
            )
{
    m_chirrupDlg->SetPaneText(0,_T("�u�������v�ɓo�^"));
    if ( pLink->msg == WM_SETCURSOR )
        return;

    bool        b = false;
    CHARRANGE   chrg;
    chrg.cpMin = pLink->chrg.cpMin + strlen("��[ID: ");
    chrg.cpMax = chrg.cpMin + MAX_NAMELEN;
    SetSel(chrg);
    url = GetSelText();
    SetSel( -1, -1 );
    if ( url.GetLength() >= 1 ) {
        char		buf[BUFSIZ];
        const char  *q = strchr( url, ']' );
        const char	*p = strchr( url, ':' );
        if ( p && (!q || (p < q)) )
            strcpy( buf, p + 2 );
        else
            strcpy( buf, url );
        p = strchr( buf, ']' );
        if ( p )
            *(char *)p = NUL;
        if ( (m_hatenaID.GetLength() > 0)       &&
             (m_hatenaPassword.GetLength() > 0)    ) {
            int i;
            for ( i = 0; i < m_timeline->m_numOfStats; i++ ) {
                if ( !strcmp( m_timeline->m_stat[i].id, buf ) ) {
                    CString username = _T("");
                    username = m_timeline->m_stat[i].user.screenName;
                    if ( username.GetLength() > 0 ) {
                        url2  = _T("http://twitter.com/");
                        url2 += username;
                        url2 += _T("/statuses/");
                        url2 += buf;

                        CWaitCursor cur;// �}�E�X�J�[�\���������v�\��
                        b = setHatenaStar( url2,
                                           m_hatenaID,
                                           m_hatenaPassword ) ? true : false;
                        url2 = _T("");
                        break;
                    }
                }
            }
        }
    }

    if ( b ) {
        // ����
        MessageBox( "�������܂���!        ",
                    "�u�������v�o�^����",
                    MB_OK|MB_ICONINFORMATION );
    }
    else
        MessageBox( "���܁A������ƖZ�����́B"
                    "�܂��A���Ƃł�蒼���Ă�!    ",
                    "�͂ĂȂ����",
                    MB_OK|MB_ICONWARNING );
}

void
CRichEditEx::SetHatenaStarOnMogo2(
                CString &url,
                CString &url2,
                ENLINK *pLink
            )
{
    m_chirrupDlg->SetPaneText(0,_T("�u���������v�ɓo�^"));
    if ( pLink->msg == WM_SETCURSOR )
        return;

    bool        b = false;
    CHARRANGE   chrg;
    chrg.cpMin = pLink->chrg.cpMin + strlen("��[ID: ");
    chrg.cpMax = chrg.cpMin + MAX_NAMELEN;
    SetSel(chrg);
    url = GetSelText();
    SetSel( -1, -1 );
    if ( url.GetLength() >= 1 ) {
        char		buf[BUFSIZ];
        const char  *q = strchr( url, ']' );
        const char	*p = strchr( url, ':' );
        if ( p && (!q || (p < q)) )
            strcpy( buf, p + 2 );
        else
            strcpy( buf, url );
        p = strchr( buf, ']' );
        if ( p )
            *(char *)p = NUL;
        if ( (m_hatenaID.GetLength() > 0)       &&
             (m_hatenaPassword.GetLength() > 0)    ) {
            int i;
            for ( i = 0; i < m_timeline->m_numOfStats; i++ ) {
                if ( !strcmp( m_timeline->m_stat[i].id, buf ) ) {
                    url2  = _T("http://mogo2.jp/comment/");
                    url2 += buf;

                    CWaitCursor cur;// �}�E�X�J�[�\���������v�\��
                    b = setHatenaStar( url2,
                                       m_hatenaID,
                                       m_hatenaPassword ) ? true : false;
                    url2 = _T("");
                    break;
                }
            }
        }
    }

    if ( b ) {
        // ����
        MessageBox( "�������܂���!        ",
                    "�u���������v�o�^����",
                    MB_OK|MB_ICONINFORMATION );
    }
    else
        MessageBox( "���܁A������ƖZ�����́B"
                    "�܂��A���Ƃł�蒼���Ă�!    ",
                    "�͂ĂȂ����",
                    MB_OK|MB_ICONWARNING );
}

void
CRichEditEx::SetHatenaStarOnHatenaHaiku(
                CString &url,
                CString &url2,
                ENLINK *pLink
            )
{
    m_chirrupDlg->SetPaneText(0,_T("�u�͂ĂȃX�^�[�v�ɓo�^"));
    if ( pLink->msg == WM_SETCURSOR )
        return;

    bool        b = false;
    CHARRANGE   chrg;
    chrg.cpMin = pLink->chrg.cpMin + strlen("��[ID: ");
    chrg.cpMax = chrg.cpMin + MAX_NAMELEN;
    SetSel(chrg);
    url = GetSelText();
    SetSel( -1, -1 );
    if ( url.GetLength() >= 1 ) {
        char		buf[BUFSIZ];
        const char  *q = strchr( url, ']' );
        const char	*p = strchr( url, ':' );
        if ( p && (!q || (p < q)) )
            strcpy( buf, p + 2 );
        else
            strcpy( buf, url );
        p = strchr( buf, ']' );
        if ( p )
            *(char *)p = NUL;
        if ( (m_hatenaID.GetLength() > 0)       &&
             (m_hatenaPassword.GetLength() > 0)    ) {
            CString username = _T("");
            int     i;
            for ( i = 0; i < m_timeline->m_numOfStats; i++ ) {
                if ( !strcmp( m_timeline->m_stat[i].id, buf ) ) {
                    username = m_timeline->m_stat[i].user.id;
                    if ( username.GetLength() > 0 ) {
                        url2  = _T("http://h.hatena.ne.jp/");
                        url2 += username;
                        url2 += _T("/");
                        url2 += buf;

                        CWaitCursor cur;// �}�E�X�J�[�\���������v�\��
                        b = setHatenaStar( url2,
                                           m_hatenaID,
                                           m_hatenaPassword ) ? true : false;
                        url2 = _T("");
                    }
                    break;
                }
            }
        }
    }

    if ( b ) {
        // ����
        MessageBox( "�������܂���!        ",
                    "�u�͂ĂȃX�^�[�v�o�^����",
                    MB_OK|MB_ICONINFORMATION );
    }
    else
        MessageBox( "���܁A������ƖZ�����́B"
                    "�܂��A���Ƃł�蒼���Ă�!    ",
                    "�͂ĂȂ����",
                    MB_OK|MB_ICONWARNING );
}


void
CRichEditEx::GetLinkTwitter( CString &url, CString &url2, ENLINK *pLink )
{
    if ( !strcmp( url, "��" ) ) {
        if ( pLink )
            SetFavoriteOnTwitter( url, pLink );
    }
    else if ( !strcmp( url, "��" ) ) {
        if ( pLink )
            SetHatenaStarOnTwitter( url, url2, pLink );
    }
    else {
        int i;
        for ( i = 0; i < m_timeline->m_numOfStats; i++ ) {
            if (!strcmp(m_timeline->m_stat[i].source, url)) {
                url2 = m_timeline->m_stat[i].sourceURL;
                break;
            }
            if ( !strcmp( m_timeline->m_stat[i].id, url ) ) {
                CString username = _T("");
                username = m_timeline->m_stat[i].user.screenName;
                if ( username.GetLength() > 0 ) {
                    url2  = _T("http://twitter.com/");
                    url2 += username;
                    url2 += _T("/statuses/");
                    url2 += url;
                }
                break;
            }
        }
    }
}

void
CRichEditEx::GetLinkJaiku( CString &url, CString &url2 )
{
    int     i;
    long    presenseID = atol( url );

    for ( i = 0; i < m_timeline->m_numOfStats; i++ ) {
        if ( !strcmp( m_timeline->m_stat[i].text, url )       ||
             ((!strncmp( m_timeline->m_stat[i].text,
                         "Comment from ", 13 )       ||
               !strncmp( m_timeline->m_stat[i].text,
                         "http", 4 )                   ) &&
             strstr( m_timeline->m_stat[i].text, url )      )    ) {
            CString *p = (CString *)(m_timeline->m_stat[i].reserved);
            if ( p )
                url2 = *p;
            else {
                url2  = _T( "http://" );
                url2 += m_timeline->m_stat[i].user.screenName;
                url2 += _T( "jaiku.com/presense/" );
                url2 += m_timeline->m_stat[i].id;

                char    *buf = new char[url2.GetLength() + 1];

                strcpy( buf, url2 );
                char    *p = strrchr( buf, '-' );
                if ( p ) {
                    *p = NUL;
                    url2 = buf;
                }

                delete [] buf;
            }
            break;
        }
    }

    if ( (url2.GetLength() == 0) && (presenseID > 0) ) {
        size_t  urlLen = url.GetLength();

        for ( i = 0; i < m_timeline->m_numOfStats; i++ ) {
            if ( !strncmp( m_timeline->m_stat[i].id, url, urlLen ) ) {
                url2  = _T( "http://" );
                url2 += m_timeline->m_stat[i].user.screenName;
                url2 += _T( "jaiku.com/presence/" );
                url2 += m_timeline->m_stat[i].id;

                char    *buf = new char[url2.GetLength() + 1];

                strcpy( buf, url2 );
                char    *p = strrchr( buf, '-' );
                if ( p ) {
                    *p = NUL;
                    url2 = buf;
                }

                delete [] buf;
                break;
            }
        }
    }
}

void
CRichEditEx::GetLinkMogo2( CString &url, CString &url2, ENLINK *pLink )
{
    if ( !strcmp( url, "��" ) ) {
        if ( pLink )
            SetHatenaStarOnMogo2( url, url2, pLink );
    }
    else {
        char    buf[BUFSIZ];

        strcpy( buf, url );
        url2  = _T("http://mogo2.jp/comment/");
        url2 += !strncmp( url, ">>", 2 ) ? &(buf[2]) : buf;
    }
}

void
CRichEditEx::GetLinkTimelog( CString &url, CString &url2, ENLINK *pLink )
{
    if ( !strcmp( url, "��" ) ) {
        if ( pLink ) {
            SetFavoriteOnTimelog( url, pLink );
            return;
        }
    }

    if ( !strcmp( url, "link" ) ||
         strchr( url, '@' )        ) {
        if ( pLink ) {
            CHARRANGE   chrg;
            chrg.cpMin = pLink->chrg.cpMin + strlen("link][ID: ");
            chrg.cpMax = chrg.cpMin + MAX_KEYLENGTH;
            SetSel(chrg);
            url = GetSelText();
            SetSel( -1, -1 );
        }
        if ( url.GetLength() >= 46 ) {
            char    buf[BUFSIZ];

            strcpy( buf, url );

            char    *p = strchr( buf, '@' );
            if ( p )
                *p = NUL;
            url2  = _T("http://timelog.jp/msg/?");
            url2 += buf;
        }
    }
    else {
        url2  = _T("http://timelog.jp/pubtags.asp?tag=");
        url2 += url;
    }
}

void
CRichEditEx::GetLinkHaruFm( CString &url, CString &url2 )
{
    char    buf[BUFSIZ];

    strcpy( buf, url );
    if ( atol( buf ) > 0 ) {
        char    *p = strchr( buf, '-' );
        if ( p )
            *p = NUL;
        url2  = _T("http://haru.fm/post/");
        url2 += buf;
    }
    else {
        CString         tagID = _T("");
        HARUFM_TAG_LIST *lp;
        long            cnt;
        HARUFM_TAGS     *tp;
        int             i;
        int             j;

        for ( i = 0; i < m_timeline->m_numOfStats; i++ ) {
            lp = (HARUFM_TAG_LIST *)
                            (m_timeline->m_stat[i].reserved2);
            if ( !lp )
                continue;

            cnt = lp->numOfTags;
            tp  = lp->tag;

            for ( j = 0; j < cnt; j++ ) {
                if ( !strcmp( tp[j].tag, url ) ) {
                    tagID = tp[j].id;
                    break;
                }
            }
            if ( tagID.GetLength() > 0 )
                break;
        }

        if ( tagID.GetLength() > 0 ) {
            url2  = _T("http://haru.fm/tag/");
            url2 += tagID;
        }
    }
}

void
CRichEditEx::GetLinkWassr( CString &url, CString &url2, ENLINK *pLink )
{
    CString username = _T("");
    int     i;

    if ( !strcmp( url, "��" ) ) {
        if ( pLink ) {
            SetFavoriteOnWassr( url, pLink );
            return;
        }
    }

    for ( i = 0; i < m_timeline->m_numOfStats; i++ ) {
        if ( !strcmp( m_timeline->m_stat[i].id, url ) ) {
            username = m_timeline->m_stat[i].user.id;
            if ( username.GetLength() > 0 ) {
                url2  = _T("http://wassr.jp/user/");
                url2 += username;
                url2 += _T("/statuses/");
                url2 += url;
            }
            break;
        }
    }
}

void
CRichEditEx::GetLinkHatenaHaiku( CString &url, CString &url2, ENLINK *pLink )
{
    if ( !strcmp( url, "��" ) ) {
        if ( pLink )
            SetHatenaStarOnHatenaHaiku( url, url2, pLink );
        return;
    }

    CString username = _T("");
    int     i;
    for ( i = 0; i < m_timeline->m_numOfStats; i++ ) {
        if ( !strcmp( m_timeline->m_stat[i].source, url ) ) {
            url2 = m_timeline->m_stat[i].sourceURL;
            break;
        }
        if ( !strcmp( m_timeline->m_stat[i].id, url ) ) {
            username = m_timeline->m_stat[i].user.id;
            if ( username.GetLength() > 0 ) {
                url2  = _T("http://h.hatena.ne.jp/");
                url2 += username;
                url2 += _T("/");
                url2 += url;
            }
            break;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
// CRichEditEx ���b�Z�[�W �n���h��

#ifdef  _MSC_VER
#pragma warning ( disable: 4100 )
#endif
#if _MSC_VER >= 1400
BOOL
#else
void
#endif
CRichEditEx::OnLink(NMHDR* pNMHDR, LRESULT* pResult)
{
    ENLINK *pLink = (ENLINK *)pNMHDR;

    if ( (pLink->msg == WM_LBUTTONDOWN) ||
         (pLink->msg == WM_SETCURSOR)      ) {
        CString url;

        SetSel(pLink->chrg);
        url = GetSelText();
        SetSel( -1, -1 );
        if ( url.GetLength() > 0 ) {
            if ( !strncmp( url, "http://",    7 ) ||
                 !strncmp( url, "https://",   8 ) ||
                 !strncmp( url, "file:",      5 ) ||
                 !strncmp( url, "mailto:",    7 ) ||
                 !strncmp( url, "ftp:",       4 ) ||
                 !strncmp( url, "gopher:",    7 ) ||
                 !strncmp( url, "nntp:",      5 ) ||
                 !strncmp( url, "prospero:",  9 ) ||
                 !strncmp( url, "telnet:",    7 ) ||
                 !strncmp( url, "news:",      5 ) ||
                 !strncmp( url, "wais:",      5 )    ) {
                int l = url.Find( ' ' );
                if ( l >= 0 )
                    url = url.Left( l );
                m_chirrupDlg->SetPaneText( 0, url );
                if ( pLink->msg == WM_LBUTTONDOWN )
                    DragStart( url );
            }
            else if ( !strncmp( url, "www.", 4 ) ) {
                CString url2 = _T( "http://" );
                url2 += url;
                m_chirrupDlg->SetPaneText( 0, url2 );
                if ( pLink->msg == WM_LBUTTONDOWN )
                    DragStart( url2 );
            }
            else {
                bool    b = false;

                m_chirrupDlg->EnterCriticalSection();
                b = m_active;
                m_chirrupDlg->LeaveCriticalSection();
				if ( b ) {
#if _MSC_VER >= 1400
					return ( TRUE );
#else
                    return;
#endif
				}

                m_chirrupDlg->EnterCriticalSection();
                m_active = true;
                m_chirrupDlg->LeaveCriticalSection();

                CString url2 = _T("");
                switch ( m_serviceType ) {
                case CTwitterTimeline::SVC_TWITTER:
                    GetLinkTwitter( url, url2, pLink );
                    break;

                case CTwitterTimeline::SVC_JAIKU:
                    GetLinkJaiku( url, url2 );
                    break;

                case CTwitterTimeline::SVC_MOGO2:
                    GetLinkMogo2( url, url2, pLink );
                    break;

                case CTwitterTimeline::SVC_TIMELOG:
                    GetLinkTimelog( url, url2, pLink );
                    break;

                case CTwitterTimeline::SVC_HARUFM:
                    GetLinkHaruFm( url, url2 );
                    break;

                case CTwitterTimeline::SVC_WASSR:
                    GetLinkWassr( url, url2, pLink );
                    break;

                case CTwitterTimeline::SVC_HATENAHAIKU:
                    GetLinkHatenaHaiku( url, url2, pLink );
                    break;
                }

                if ( url2.GetLength() > 0 ) {
                    m_chirrupDlg->SetPaneText( 0, url2 );
                    if ( pLink->msg == WM_LBUTTONDOWN )
                        DragStart( url2 );
                }

                m_chirrupDlg->EnterCriticalSection();
                m_active = false;
                m_chirrupDlg->LeaveCriticalSection();
            }
        }
    }

#if _MSC_VER >= 1400
    return ( TRUE );
#endif
}
#ifdef  _MSC_VER
#pragma warning ( default: 4100 )
#endif

void CRichEditEx::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
    long    s, e;

    GetSel( s, e );
    if ( (s >= 0) && (e >= 0) ) {
        CString targetUser = _T("");

        GetTargetUser( targetUser, s );
        if ( targetUser.GetLength() > 0 )
            if ( m_chirrupDlg )
                m_chirrupDlg->SetTargetUserOnMonologue( targetUser );
        return;
    }

	CRichEditCtrl::OnLButtonDblClk(nFlags, point);
}

void CRichEditEx::OnContextMenu(CWnd* pWnd, CPoint point) 
{
    bool    done          = false;
    bool    inContextMenu = false;
    CString text = GetSelText();

    CPoint  cMenuPt;
    GetCursorPos( &cMenuPt );

#define IDC_MENU_COPY               1
#define IDC_MENU_SELECT_ALL         2
#define IDC_MENU_TUMBLR             3
#define IDC_MENU_SEARCH_TWITTER     4
#define IDC_MENU_SEARCH_TWITTER2    5
#define IDC_MENU_SEARCH_TWITTER3    6
#define IDC_MENU_SEARCH_GOOGLE      7
#define IDC_MENU_SEARCH_YAHOO       8
#define IDC_MENU_SEARCH_BUZZTTER    9

    CMenu   menu;
    CString menuText;
    menu.CreatePopupMenu();

    if ( text.GetLength() > 0 )
        menu.AppendMenu( MF_STRING, IDC_MENU_COPY,
                         "�R�s�[ (&C)" );
    menu.AppendMenu( MF_STRING, IDC_MENU_SELECT_ALL,
                     "���ׂđI�� (&A)" );
    if ( text.GetLength() > 0 ) {
        if ( m_chirrupDlg->m_useTumblr )
            menu.AppendMenu( MF_STRING, IDC_MENU_TUMBLR,
                             "tumblr �ɓ��e (&T)" );
        menu.AppendMenu( MF_STRING, IDC_MENU_SEARCH_TWITTER,
                         "Twitter ���� (&S)" );
        menu.AppendMenu( MF_STRING, IDC_MENU_SEARCH_TWITTER2,
                         "Twitter ���� [�V]" );
        menu.AppendMenu( MF_STRING, IDC_MENU_SEARCH_TWITTER3,
                         "Twitter ���� [�{��]" );
        menu.AppendMenu( MF_STRING, IDC_MENU_SEARCH_BUZZTTER,
                         "buzztter �Ō��� (&B)" );
        menu.AppendMenu( MF_STRING, IDC_MENU_SEARCH_GOOGLE,
                         "Google �Ō��� (&G)" );
        menu.AppendMenu( MF_STRING, IDC_MENU_SEARCH_YAHOO,
                         "Yahoo! �Ō��� (&Y)" );
    }

    int iCommand =
        menu.TrackPopupMenu(
            TPM_LEFTALIGN | TPM_BOTTOMALIGN | TPM_RETURNCMD | TPM_LEFTBUTTON,
            cMenuPt.x, cMenuPt.y, this, NULL );
    switch ( iCommand ) {
    case IDC_MENU_COPY:
        m_text = text;
        OnEditCopy();
        done = true;
        break;
    case IDC_MENU_SELECT_ALL:
        SetSel( 0, -1 );
        done = true;
        break;

    case IDC_MENU_TUMBLR:
        inContextMenu = true;
        done = true;
        break;

    case IDC_MENU_SEARCH_TWITTER:
    case IDC_MENU_SEARCH_TWITTER2:
    case IDC_MENU_SEARCH_TWITTER3:
    case IDC_MENU_SEARCH_GOOGLE:
    case IDC_MENU_SEARCH_YAHOO:
    case IDC_MENU_SEARCH_BUZZTTER:
        ExecuteSearch( iCommand, text );
        done = true;
        break;
    }

    menu.DestroyMenu();	

    if ( !done )
    	CRichEditCtrl::OnContextMenu(pWnd, point) ;

    if ( inContextMenu ) {
        long    s, e;

        GetSel( s, e );
        if ( (s >= 0) && (e >= 0) ) {
            CString targetURL     = _T("");
            CString targetContent = text;

            GetTargetURL( targetURL, targetContent, s );
            if ( targetURL.GetLength() > 0 )
                PostTumblr( targetURL, targetContent );
        }
    }
}

void CRichEditEx::OnEditCopy()
{
    size_t  len = m_text.GetLength();
    if ( len == 0 )
        return;

    // �N���b�v�{�[�h�Ƀe�L�X�g���i�[
    HGLOBAL hText;
    char    *pText;

	hText = GlobalAlloc( GMEM_DDESHARE | GMEM_MOVEABLE, len + 1 );
	pText = (char *)GlobalLock( hText );
	lstrcpy( pText, (const char *)m_text );
	GlobalUnlock( hText );

	OpenClipboard();
	EmptyClipboard();
	SetClipboardData( CF_TEXT, hText );
	CloseClipboard();

    m_text = _T("");
}

void CRichEditEx::OnSearchText()
{
    size_t  len = m_text.GetLength();
    if ( (len == 0) && !m_findDialog ) {
        // �L�[���[�h���̓_�C�A���O�N��
        m_findDialog = new CFindReplaceDialog();

        if ( m_findBuf )
            delete [] m_findBuf;
        long    sz = GetTextLength() + 2;
        m_findBuf  = new char [sz];
        memset( m_findBuf, 0x00, sz );

        unsigned long   flag = 0;
        if ( m_findMatchCase )
            flag |= FR_MATCHCASE;
        if ( m_findMatchWholeWord )
            flag |= FR_WHOLEWORD;
        if ( m_findSearchDown )
            flag |= FR_DOWN;

        m_findDialog->Create( TRUE, m_findBuf, NULL, flag, this );

        return;
    }

    // ���݈ʒu�ȍ~�ɏo������u�L�[���[�h�v������
    OnFind( 0, 0 );
}

#ifdef  _MSC_VER
#pragma warning ( disable: 4100 )
#endif
LONG CRichEditEx::OnFind(WPARAM wParam, LPARAM lParam)
{
    if ( m_findDialog ) {
        m_text = m_findDialog->GetFindString();

        m_findMatchCase      = m_findDialog->MatchCase()      ? true : false;
        m_findMatchWholeWord = m_findDialog->MatchWholeWord() ? true : false;
        m_findSearchDown     = m_findDialog->SearchDown()     ? true : false;

        if ( m_findBuf ) {
            delete [] m_findBuf;
            m_findBuf = NULL;
        }

        delete m_findDialog;
        m_findDialog = NULL;
    }

    size_t  len = m_text.GetLength();
    if ( len > 0 ) {
        FINDTEXTEX      t;
        int             loc = 0;
        char            *buf;
        long            s, e;
        unsigned long   flag = 0;

        GetSel( s, e );
        if ( (s > 0) && (e >= s) )
            loc = e;

        buf = new char[m_text.GetLength() + 2];

        strcpy( buf, m_text );
        t.lpstrText  = buf;
        t.chrg.cpMin = loc;
        t.chrg.cpMax = -1;

        if ( m_findMatchCase )
            flag |= FR_MATCHCASE;
        if ( m_findMatchWholeWord )
            flag |= FR_WHOLEWORD;

        if ( m_findSearchDown ) {
            // ���������֌���
            FindText( flag, &t );
        }
        else {
            // ���������֌���
            FINDTEXTEX      t1;
            FINDTEXTEX      t2;

            t2.chrg.cpMin = 0;
            t2.chrg.cpMax = -1;

            t1.chrg.cpMin = 0;
            t1.chrg.cpMax = -1;
            t1.lpstrText  = buf;

            t.chrgText.cpMin = -1;

            bool    done  = false;
            do {
                FindText( flag, &t1 );

                if ( (t1.chrgText.cpMin > t2.chrg.cpMin) &&
                     (t1.chrgText.cpMax < loc)              ) {
                    t = t2 = t1;

                    t.chrg.cpMin  = t2.chrg.cpMin = t1.chrgText.cpMin;
                    t.chrg.cpMax  = t2.chrg.cpMax = t1.chrgText.cpMax;

                    t1.chrg.cpMin = t2.chrg.cpMax + 1;
                    t1.chrg.cpMax = -1;
                }
                else
                    done = true;
            } while ( !done );
        }

        if ( t.chrgText.cpMin >= 0 ) {
            // �������� hide (HideSelection() �̑�1����)�� FALSE �ɂ��Ȃ��ƁA
            // �I�[�g�X�N���[�����Ă���Ȃ�
            HideSelection( FALSE, TRUE );
            SetSel( t.chrgText );
            HideSelection( TRUE, TRUE );
        }

        delete [] buf;
    }

    return ( 0 );
}
#ifdef  _MSC_VER
#pragma warning ( default: 4100 )
#endif

#define CTRL_F  ('F' - '@')
#define VK_F    ('F')
#define VK_f    ('f')

void CRichEditEx::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    switch ( nChar ) {
    case CTRL_F:
        m_text = GetSelText();
        OnSearchText();
        break;
    }

    CRichEditCtrl::OnChar(nChar, nRepCnt, nFlags);
}

void CRichEditEx::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    switch ( nChar ) {
    case VK_F3:
        m_text = GetSelText();
        m_findSearchDown = m_shiftKeyDown ? false : true;
        OnSearchText();
        break;

    case VK_SHIFT:
        m_shiftKeyDown = true;
        break;
    }

    CRichEditCtrl::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CRichEditEx::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    switch ( nChar ) {
    case VK_SHIFT:
        m_shiftKeyDown = false;
        break;
    }

    CRichEditCtrl::OnKeyUp(nChar, nRepCnt, nFlags);
}

void CRichEditEx::OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    switch ( nChar ) {
    case VK_MENU:
        m_altKeyDown = true;
        break;

#if 0
    case VK_F:
    case VK_f:
        m_text = GetSelText();
        OnSearchText();
        break;
#endif
    }

    CRichEditCtrl::OnSysKeyDown(nChar, nRepCnt, nFlags);
}

void CRichEditEx::OnSysKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    switch ( nChar ) {
    case VK_MENU:
        m_altKeyDown = false;
        break;
    }

    CRichEditCtrl::OnSysKeyUp(nChar, nRepCnt, nFlags);
}

/////////////////////////////////////////////////////////////////////////////
// CRichEditEx �ǉ����\�b�h (�Â�)

void
CRichEditEx::ExecuteSearch( int cmdType, const char *text )
{
    char    *url = new char[MAX_URLLENGTH + strlen(text) * 6 + 1];
    char    *p   = any2utf( text );
    char    *q   = encodeURL( p ? p : text );

    switch ( cmdType ) {
    case IDC_MENU_SEARCH_GOOGLE:
        sprintf( url,
                 "http://www.google.co.jp/search?"
                 "hl=ja&"
                 "q=%s&"
                 "lr=",
                 q );
        break;

    case IDC_MENU_SEARCH_YAHOO:
        sprintf( url,
                 "http://search.yahoo.co.jp/search?"
                 "p=%s&"
                 "ei=utf-8",
                 q );
        break;

    case IDC_MENU_SEARCH_BUZZTTER:
        sprintf( url,
                 "http://buzztter.com/ja/k/%s",
                 q );
        break;

    case IDC_MENU_SEARCH_TWITTER2:
        sprintf( url,
                 "http://pcod.no-ip.org/yats/search?"
                 "query=%s",
                 q );
        break;

    case IDC_MENU_SEARCH_TWITTER3:
        sprintf( url,
                 "http://search.twitter.com/search?"
                 "q=%s",
                 q );
        break;

    case IDC_MENU_SEARCH_TWITTER:
    default:
        sprintf( url,
                 "http://twitter.1x1.jp/search/?"
                 "source=&"
                 "keyword=%s&"
                 "lang=&"
                 "text=1",
                 q );
        break;
    }

    ShellExecute( NULL, "open", url, NULL, NULL, SW_SHOWNORMAL );

    delete [] url;
}
