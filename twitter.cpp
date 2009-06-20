/*
 * twitter.cpp : Twitter �N���C�A���g chirrup
 *      Twitter API �𗘗p���邽�߂̊e�폈���Q
 *          written by H.Tsujimura  4 Apr 2007 / 28 Apr 2007
 *
 *      Copyright (c) 2007, 2008, 2009 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/twitter.cpp $
 * 
 * 2     09/06/18 1:33 tsupo
 * 2.01��
 * 
 * 87    09/06/16 0:51 Tsujimura543
 * �A�N�Z�X�g�[�N���擾���ɕԂ��Ă���X�N���[�����𗘗p����悤�ɂ���
 * 
 * 86    09/06/16 0:01 Tsujimura543
 * Twitter �� status ID �� singed long �ň�����͈͂𒴂��Ă��܂���
 * (2009�N6��13��)���߂̑΍�Ƃ��āACService::GetIdFromJSON() ���Ă�
 * �̂���߂āA�V���� CTwitter::GetIdFromJSON() ��p�ӂ���
 * 
 * 85    09/06/11 18:53 Tsujimura543
 * Twitter �� OAuth �� 1.0 ���� 1.0a �ֈڍs�����̂ɔ����C��
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 84    09/04/28 20:52 Tsujimura543
 * �^�C���A�E�g�擾�������K�莞�ԓ��ɏI���Ȃ��ꍇ�̏�����ύX
 * (�X���b�h�����I�������ł͂Ȃ��A�C�x���g�ʒm�������̗p)
 * 
 * 83    09/04/28 18:24 Tsujimura543
 * ���������[�N�����p�̃R�[�h��ǉ� (�f�o�b�O�r���h�ł̂ݗL��)
 * 
 * 82    09/04/10 17:10 Tsujimura543
 * SetStatFromJSON() ���� trancated �֘A�������C�� (URL �̖����� ... ��
 * �Ȃ��Ă�����̂�{���� URL �ɓW�J���邽�߂̏�����ǉ�)
 * 
 * 81    09/04/09 22:38 Tsujimura543
 * public_timeline �ȊO�̃^�C�����C���擾���Acount=60 ���w�肷��悤�ɂ���
 * (1���API��60���擾����悤�ɂ���)
 * 
 * 80    09/04/09 18:17 Tsujimura543
 * �R�����g�C��
 * 
 * 79    09/04/09 18:16 Tsujimura543
 * OAuth �F�؃G���[���������Ă��邩�ǂ����𔻒肷��̂� http ���X�|���X
 * �R�[�h�� 401 ���ǂ���������悤�ɂ��Ă݂�
 * 
 * 78    09/04/09 17:55 Tsujimura543
 * CheckOAuthResult() �ŕ\������ MessageBox �̕\�����e���C��
 * (title �Ɩ{�����t�ɂȂ��Ă���)
 * 
 * 77    09/04/09 17:50 Tsujimura543
 * OAuth �F�؃G���[���̃��X�|���X�d�l�ύX�ɔ����C�������{
 * 
 * 76    09/04/09 17:18 Tsujimura543
 * SetStatFromJSON() �����t�@�N�^�����O
 * 
 * 75    09/04/09 16:03 Tsujimura543
 * API �Ŏ擾���������� trancated �� true �̂Ƃ��́A���Y�����̃p�[�}�����N
 * �� GET ���āA���S�ȏ�Ԃ̔������擾����悤�ɂ���
 * 
 * 74    09/04/08 20:45 Tsujimura543
 * GetReplies() �ŌĂяo�� API �� replies ���� mentions �Ɉڍs����
 * 
 * 73    09/04/07 15:46 Tsujimura543
 * OAuth �� "Invalid OAuth Request" �����������Ƃ��̏�����ǉ�
 * 
 * 72    09/04/01 22:10 Tsujimura543
 * ���t�@�N�^�����O���{
 * 
 * 71    09/04/01 3:16 Tsujimura543
 * Twitter �� OAuth �Ή��A����
 * 
 * 70    09/03/30 23:58 Tsujimura543
 * Twitter �� OAuth �Ή����� ����4
 * 
 * 69    09/03/30 23:45 Tsujimura543
 * Twitter �� OAuth �Ή����� ����3
 * 
 * 68    09/03/10 22:14 Tsujimura543
 * GetStringFromJSON() �Ƀo�b�t�@�I�[�o�[�����΍�����{
 * 
 * 67    08/12/04 18:19 Tsujimura543
 * �R�[�h�����A���艻��Ƃ����{
 * 
 * 66    08/09/03 19:21 Tsujimura543
 * delete [] response; ����^�C�~���O���C��
 * 
 * 65    08/08/18 18:59 Tsujimura543
 * �����̖`���Ɂu>>���b�Z�[�WID�v�Ə����ŁA�w�肵�����b�Z�[�W�ւ�
 * reply�𓊍e�ł���悤�ɂ���
 * 
 * 64    08/08/11 11:23 Tsujimura543
 * AddFriend, RemoveFriend, SetFavorite, DeleteDirectMessage �� GET
 * ���\�b�h���� POST ���\�b�h�ɕύX (API �̎d�l�ύX�ɋ���)
 * 
 * 63    08/07/16 13:34 Tsujimura543
 * loginTwitter() ���uTwitter ���{��Łv�ɂ��Ή�������
 * 
 * 62    08/07/14 16:54 Tsujimura543
 * Twitter �́uAPI�������擾API�v���Ăԉ񐔁A�^�C�~���O�𒲐���������
 * 
 * 61    08/06/30 20:10 Tsujimura543
 * long GetRateLimitStatus() ��ǉ�
 * 
 * 60    08/06/30 18:49 Tsujimura543
 * GetRateLimitStatus() ��ǉ�
 * 
 * 59    08/04/22 21:20 Tsujimura543
 * CutInReplyTo() ���C��
 * 
 * 58    08/04/15 21:10 Tsujimura543
 * CutInReplyTo() ��ǉ��Ain_reply_to: �̓���q�\���ɑΉ�
 * 
 * 57    07/12/19 18:44 Tsujimura543
 * http �֘A�֐��Ăяo���܂��𐮗�
 * 
 * 56    07/12/19 17:35 Tsujimura543
 * (1) http_postEx() �� _http_postBASIC() �ֈڍs
 * (2) http_getEx(), http_getBASICEx() �� _http_getBASIC() �ֈڍs
 * 
 * 55    07/12/19 16:56 Tsujimura543
 * _http_getBASIC() �̈�����ǉ�
 * 
 * 54    07/12/14 16:27 Tsujimura543
 * (1) http_getBASIC() �� _http_getBASIC() �ɒu��
 * (2) http_postBASIC() �� _http_postBASIC() �ɒu��
 * 
 * 53    07/11/26 20:03 Tsujimura543
 * isNecessaryToCheckProxyInfo() ���g���āA�G���[�������̏���������������
 * 
 * 52    07/09/26 20:18 Tsujimura543
 * �R�����g�𐮗�
 * 
 * 51    07/09/26 20:16 Tsujimura543
 * replaceEntityStrings() �̃���������������_�C���N�g���b�Z�[�W��M����
 * �ɂ�����Ă���
 * 
 * 50    07/09/26 20:13 Tsujimura543
 * �_�C���N�g���b�Z�[�W�ɂ� replaceEntityStrings() ��K�p����悤�ɂ���
 * 
 * 49    07/09/11 15:45 Tsujimura543
 * SetFavorite() �ŃR�[������ API �� URL ��ς��Ă݂�(��A���܂�������)�B
 * (������ API �d�l���� URL ���Ԉ���Ă���?)
 * 
 * 48    07/09/07 19:40 Tsujimura543
 * �\���p�����񐮌`���� replaceEntityStrings() �𓱓��B���̎Q�Ƃ��ߎ�����
 * �ŕ\���\�ȏꍇ�́A�ߎ������ɒu������悤�ɂ���
 * 
 * 47    07/08/31 18:30 Tsujimura543
 * �ufavorites/create API �ɂ�� favorites �̃Z�b�g�v�������I�ɓ���
 * (2007�N8��31��18�����݁A�܂��AAPI �͎�������ĂȂ��̂��APage Not Found
 *  ���Ԃ��Ă��邽�߁AAPI ���s���s���́A�]���� favorites �o�^���������s��
 *  ��悤�ɂ��Ă���)
 * 
 * 46    07/08/25 1:53 Tsujimura543
 * �u�������v�Ή� (���ۂɁ�������)
 * 
 * 45    07/08/25 0:45 Tsujimura543
 * �u�������v�ɑΉ� (�\��)
 * 
 * 44    07/08/17 17:21 Tsujimura543
 * SetFavorite() ��ǉ�
 * 
 * 43    07/08/13 12:05 Tsujimura543
 * �f�o�b�O�p�� ASSERT() [�̂����A�s�v�ɂȂ�������]���폜
 * 
 * 42    07/08/06 17:30 Tsujimura543
 * (1) timeline �� JSON ���̊e�v�f�̏o�������Ɉˑ����Ȃ��悤�ɁAJSON
 *     ���ߏ���������������
 * (2) JSON ���� &quot; ���̕\�����@���ς�����̂ɑΉ�
 * 
 * 41    07/07/23 15:00 Tsujimura543
 * (1) �擾���� timeline �� souce �Ƃ������ڂ��������̂ɑΉ�
 * (2) timeline �� JSON �� createdAt �ł͂Ȃ� user �Ŏn�܂�ꍇ�ɂ��Ή�
 * 
 * 40    07/07/19 21:35 Tsujimura543
 * �^�C���X�^���v�֘A�̏����� VC++ 6 / VC++ 2005 ���ʃR�[�h�ɕύX
 * 
 * 39    07/07/18 10:41 Tsujimura543
 * MakeMessageForLogging() ���Ăԉӏ��������Ă����̂𕜊�������
 * 
 * 38    07/07/17 18:52 Tsujimura543
 * �\�[�X�𐮗�
 * 
 * 37    07/07/17 18:43 Tsujimura543
 * GetTinyURL() ���g���A������ tinyurl �����Ă��瓊�e����悤�ɂ��Ă݂�
 * (URL �� # ���܂܂��ꍇ�ATwitter ���g�� tinyurl �����ł� # �ȍ~��
 *  �����ꂽ�`�� tinyurl ������Ă��܂��A�Ƃ�����肪���邽��)
 * 
 * 36    07/07/10 22:32 Tsujimura543
 * �u�����v�� POST ���̃p�����[�^�� source=API�� ��ǉ����Ă݂�
 * 
 * 35    07/07/05 0:50 Tsujimura543
 * (1) GetStatFromJSON(), GetUserTimeline() �̈�����ύX
 * (2) TWITTER_USER �\���̂̕ύX(orig_userName��ǉ�)�ɔ����C��
 * (3) MakeMessageForScreen() �� MakeMessageForLogging() ��p��
 * 
 * 34    07/07/03 13:46 Tsujimura543
 * Visual Studio 2005 �ł̃r���h���ʂ𔽉f
 * 
 * 33    07/06/26 16:01 Tsujimura543
 * PostUpdate() ���Ŋm�ۂ��� request �̃T�C�Y���C��
 * 
 * 32    07/06/25 23:22 Tsujimura543
 * status ID ��\���A���O�o�͂���悤�ɂ��Ă݂�
 * 
 * 31    07/06/25 21:10 Tsujimura543
 * memcpy() ���g���Ă����Ƃ�����R�s�[�R���X�g���N�^���g���悤�ɏC��
 * 
 * 30    07/06/25 18:24 Tsujimura543
 * �s�v�ȃR�[�h���폜
 * 
 * 29    07/06/25 18:03 Tsujimura543
 * DeleteReserved(), DeleteReserved2() �֘A�A�R�[�h�𐮗�
 * 
 * 28    07/06/21 19:15 Tsujimura543
 * SetUserAgent() �� CService ���̃��\�b�h�Ɉ�{������
 * 
 * 27    07/06/21 13:36 Tsujimura543
 * PostUpdate() ���Ŋm�ۂ��Ă��� request �̃T�C�Y������������ꍇ��
 * ���邱�Ƃ������B�T�C�Y�̌v�Z���C������
 * 
 * 26    07/06/20 19:28 Tsujimura543
 * GetStatusID() �𓱓�
 * 
 * 25    07/06/19 23:09 Tsujimura543
 * CService �𓱓����A�\�[�X�𐮗�����
 * 
 * 24    07/06/19 17:38 Tsujimura543
 * GetTwitterScreenName() �� GetScreenName() �ɕύX
 * 
 * 23    07/06/18 17:25 Tsujimura543
 * ExpandTinyURL() ���C���Atinyurl ���T�[�r�X��~�����邢��
 * 500 �G���[��Ԃ��Ă���ꍇ��retry��������s��ɑΏ�
 * 
 * 22    07/06/14 22:58 Tsujimura543
 * GetStringFromJSON() ���C�� (Wassr�΍�)
 * 
 * 21    07/06/13 21:05 Tsujimura543
 * 1�̔������� tinyurl �������܂܂��ꍇ�ɁA�ŏ��� tinyurl �����W�J
 * �����A�c��͂��̂܂܂ɂȂ�s��ɑΏ�
 * 
 * 20    07/06/13 19:18 Tsujimura543
 * Twitter �� Replies �̉{���A���O�o�͂ɑΉ�
 * 
 * 19    07/06/13 15:55 Tsujimura543
 * �u�_�C���N�g���b�Z�[�W�̍폜�v�ɑΉ�
 * 
 * 18    07/06/13 3:07 Tsujimura543
 * �s�v�ɂȂ����R�[�h���폜
 * 
 * 17    07/06/13 3:02 Tsujimura543
 * tinyurl �W�J������ύX (tinyurl �� preview �@�\�𗘗p����悤��
 * ���Ă݂�)
 * 
 * 16    07/06/11 18:39 Tsujimura543
 * Twitter �� user_timeline �̉{�����T�|�[�g
 * 
 * 15    07/06/07 19:23 Tsujimura543
 * ���t�@�N�^�����O
 * 
 * 14    07/06/07 3:27 Tsujimura543
 * ���O�t�@�C���̃^�C���X�^���v��9���Ԃ�������18���Ԃ����s����C��
 * 
 * 13    07/06/06 23:18 Tsujimura543
 * ���O�ɋL�^��������� UTC ���烍�[�J�����ԂɕύX
 * 
 * 12    07/06/06 21:24 Tsujimura543
 * ���O���t�@�C���ɏ����o���@�\������
 * 
 * 11    07/06/05 20:31 Tsujimura543
 * _http_XXX() �n�֐��̈��� pdlg �� NULL �ł������悤�ɂ��Ă݂�
 * 
 * 10    07/06/04 21:11 Tsujimura543
 * friend �� add �� remove ������ (for Twitter)
 * 
 * 9     07/05/29 5:43 Tsujimura543
 * Jaiku �ւ̓��e���T�|�[�g
 * 
 * 8     07/05/29 3:56 Tsujimura543
 * Jaiku (�� public_timeline �̉{��) �ɑΉ�
 * 
 * 7     07/05/26 0:22 Tsujimura543
 * Twitter �ƒʐM���镔����ʃX���b�h�����Ă݂�
 * 
 * 6     07/05/25 21:06 Tsujimura543
 * tinyurl �W�J�@�\��ǉ�
 * 
 * 5     07/05/23 22:24 Tsujimura543
 * public_timeline �̎擾�ɑΉ�
 * 
 * 4     07/05/11 22:18 Tsujimura543
 * (1) �������d�����ĕ\������Ă��܂����Ƃ�����s��ɑΏ�
 * (2) Twitter �����瑗���Ă��� timeline �ɔ���������ꍇ�ɔ����āA
 *     24���ԕ��]���� timeline ���擾���āA�⊮�ł���悤�ɂ��Ă݂�
 * 
 * 3     07/05/11 21:28 Tsujimura543
 * utf2sjis() �� any2sjis() �ɒu��������
 * 
 * 2     07/04/27 20:53 Tsujimura543
 * GetTwitterScreenName() ��ǉ�
 * 
 * 1     07/04/27 19:36 Tsujimura543
 * �V�K�쐬 (���܂ŕ����̃\�[�X�ɕ��U���Ă��� Twitter API �֘A�������W�听
 * �������̂Ƃ��āACTwitter �N���X��p�ӂ���)
 */

#include "chirrup.h"
#include "twitter.h"
#include "twitterTimeline.h"
#include "http.h"
extern "C" {
#include "utility.h"
#include "sha1.h"
}
#include "InputPinDialog.h"

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/chirrup/twitter.cpp 2     09/06/18 1:33 tsupo $";
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#ifdef  _MSC_VER
#define Thread  __declspec( thread )
#else
#define Thread
#endif

CTwitter::CTwitter() : CService()
{
    m_numOfMessages = 0;
    m_dm            = NULL;

    m_numOfStats4   = 0;
    m_stat4         = NULL;

#ifdef  _DEBUG
    m_serviceName   = _T("twitter");
#endif
    m_serviceSymbol = _T("Twitter");
    m_max_remain    = TWITTER_MAX_REMAIN;
    m_remain        = TWITTER_MAX_REMAIN;
}

CTwitter::~CTwitter()
{
    if ( m_stat4 ) {
        delete [] m_stat4;
        m_stat4 = NULL;
    }
}

void CTwitter::DeleteReserved( TWITTER_STATUS *sp )
{
    if ( sp && sp->reserved ) {
    }
}

void CTwitter::DeleteReserved2( TWITTER_STATUS *sp )
{
    if ( sp && sp->reserved2 ) {
    }
}

/*
 *  Twitter API
 */

// �����𓊍e
bool
CTwitter::PostUpdate( CString monologue, ProceedingDialog *pdlg )
{
    bool        ret = false;
    size_t      sz  = MAX_CONTENT_SIZE;
    size_t      len = monologue.GetLength() * 18;
    char        *request  = new char[7 + 64 + len + 1 + MAX_KEYLENGTH];
    char        *response = new char[sz];
    const char  *url = "http://twitter.com/statuses/update.xml";
    char        rid[MAX_KEYLENGTH];
    char        *p;

    rid[0] = NUL;
    if ( !strncmp( monologue, ">>", 2 ) ) {
        strncpy( rid, ((const char *)monologue) + 2, MAX_KEYLENGTH - 2 );
        rid[MAX_KEYLENGTH - 2] = NUL;
        p = strchr( rid, ' ' );
        if ( p ) {
            *p = NUL;
            monologue = strchr( monologue, ' ' ) + 1;
        }
    }
    p = sjis2utf( monologue );

    if ( request && response ) {
        if ( m_useOAuth ) {
            // OAuth �F��
            char    *request0 = new char[sz];
            char    key[MAX_KEYLENGTH * 2];
            char    base[MAX_CONTENT_SIZE];
            char    param[MAX_CONTENT_SIZE];

            key[0]   = NUL;
            base[0]  = NUL;
            param[0] = NUL;
            if ( rid[0] )
                sprintf( param,
                         "in_reply_to_status_id=%s&",
                         rid );
            MakeOAuthBase( url, "POST", key, base, param );

            sprintf( request0, "%s", p ? p : (const char *)monologue );
            p = GetTinyURL( request0 );
            sprintf( request0,
                     "&"
                     "source=%s&"
                     "status=%s",
                     "Chirrup",
                     encodeURLi( p ? p : monologue, FALSE ) );
            strcat( param, request0 );

            MakeOAuthRequest( url, request0, key, base, param );

            SetUserAgent();
            setUpReceiveBuffer( response, sz );
            _http_postBASIC( request0, NULL, NULL, "", response, NULL, NULL );
            delete [] request0;
        }
        else {
            // BASIC �F��
            sprintf( request, "%s", p ? p : (const char *)monologue );
            p = GetTinyURL( request );
            sprintf( request,
                     "status=%s&"
                     "source=%s",
                     encodeURL( p ? p : monologue ),
                     "Chirrup" );
            if ( rid[0] )
                sprintf( request + strlen(request),
                         "&in_reply_to_status_id=%s",
                         rid );
            SetUserAgent();
            setUpReceiveBuffer( response, sz );
            _http_postBASIC( url, m_username, m_password,
                             request, response, NULL, pdlg );
        }
        if ( *response ) {
            if ( strstr( response, "<created_at>" ) )
                ret = true;
            else if ( m_useOAuth )
                CheckOAuthResult( response );
        }
    }

    if ( response )
        delete [] response;
    if ( request )
        delete [] request;

    return ( ret );
}


CString
CTwitter::GetTimeline(
                CString          &messages,
                TWITTER_STATUS   **stat,
                long             &numOfStats,
                TIMELINE_TYPE    t,
                const char       *endPointURL,
                CTwitterTimeline *timeline,
                ProceedingDialog *pdlg
            )
{
    CChirrupApp *ap = (CChirrupApp *)AfxGetApp();

#ifdef  _DEBUG
    _CrtMemState s1, s2, s3;
    _CrtMemCheckpoint( &s1 );
#endif

    if ( timeline->m_numOfStats > 0 ) {
        if ( !(*stat) ) {
            *stat = new TWITTER_STATUS[MAX_NUMOFSTATUS];
            numOfStats = 0;
        }
        int i;
        for ( i = 0; i < timeline->m_numOfStats; i++ )
            (*stat)[i] = (timeline->m_stat)[i];
        numOfStats = timeline->m_numOfStats;
    }

    if ( m_remain > 0 ) {
        size_t  sz = MAX_CONTENT_SIZE * 16;
        char    *response = new char[sz];
        if ( response ) {
            CString url = endPointURL;
            if ( *stat ) {
                CTime   t;

                t = (*stat)[0].createdAt;
                t -= 24 * 60 * 60;  // 24���ԑO���w�� (Twitter�̃��O�����΍�)
                url += "?since=";
                url += encodeDateTime(t.Format("%a, %d %b %Y %H:%M:%S GMT"));
                    // Tue%2C+27+Mar+2007+22%3A55%3A48+GMT
            }

            SetUserAgent();
            setUpReceiveBuffer( response, sz );
            if ( t != PUBLIC_TIMELINE ) {
                if ( m_useOAuth ) {
                    // OAuth �F��
                    char    *request = new char[sz];
                    char    targetURL[MAX_URLLENGTH];
                    char    since[MAX_URLLENGTH];
                    char    *p = strstr( url, "?since=" );
                    if ( p ) {
                        strncpy( targetURL, url, p - url );
                        targetURL[p - url] = NUL;
                        strcpy( since, p + 7 );

                        p = decodeURL( since );
                        char    *q;
                        do {
                            q = strchr( p, '+' );
                            if ( q )
                                *q = ' ';
                        } while ( q );
                        strcpy( since, p );
                    }
                    else {
                        strcpy( targetURL, url );
                        since[0] = NUL;
                    }

                    char    key[MAX_KEYLENGTH * 2];
                    char    base[MAX_CONTENT_SIZE];
                    char    param[MAX_CONTENT_SIZE];

                    key[0]   = NUL;
                    base[0]  = NUL;
                    param[0] = NUL;
                    strcpy( param, "count=60&" );
                    MakeOAuthBase( targetURL, "GET", key, base, param );

                    if ( since[0] )
                        sprintf( param + strlen(param),
                                 "&"
                                 "since=%s",
                                 encodeURLi( since, FALSE ) );
                    MakeOAuthRequest( targetURL, request, key, base, param );

                    SetUserAgent();
                    setUpReceiveBuffer( response, sz );
                    _http_getBASIC(request, NULL, NULL, response, NULL, NULL);
                    delete [] request;
                }
                else {
                    // BASIC �F��
                    url += strchr( url, '?' ) ? "&" : "?";
                    url += "count=60";  // 200���܂Ŏw��\(�����ǍT���ڂ�)
                    _http_getBASIC( url, m_username, m_password, response,
                                    NULL, pdlg );
                }
            }
            else
                _http_get( url, response, pdlg );
                    // PUBLIC_TIMELINE�͍ő�20���܂ł����擾�ł��Ȃ�
            if ( response[0] ) {
                char    *p  = response;
                bool    ret = true;
                if ( (t != PUBLIC_TIMELINE) && m_useOAuth )
                    ret = CheckOAuthResult( p );
                if ( ret == true ) {
                    if ( strstr( p, "\"in_reply_to\":{\"" ) ) {
#ifdef  _DEBUG
                        FILE    *fp = fopen( "./twitter_orig.json", "w" );
                        if ( fp ) {
                            fputs( p, fp );
                            fclose( fp );
                        }
#endif
                        p = CutInReplyTo( (char *)p );
                    }

                    GetStatFromJSON( response, stat, numOfStats );
                    WriteLog( timeline );
                }

                int i;
                messages = _T("");
                for ( i = 0; i < numOfStats; i++ ) {
                    if ( ap->m_event ) {
                        DWORD   r = WaitForSingleObject( ap->m_event, 0 );
                        if ( r == WAIT_OBJECT_0 ) {
                            // ��ƒ��f
                            ResetEvent( ap->m_event );
#ifdef  _DEBUG
                            MessageBox( NULL,
                                        "��ƒ��f",
                                        "CTwitter::GetTimeline()",
                                        MB_OK|MB_ICONWARNING );
#endif
                            break;
                        }
                    }

                    MakeMessageForScreen( messages, &((*stat)[i]) );
                    if ( messages.GetLength() >= (MAX_CONTENT_SIZE / 2) )
                        break;
                }
            }

            replaceEntityStrings( NULL, CHARSET_UNKNOWN );
            delete [] response;
        }
    }

    timeline->m_numOfStats = numOfStats;
    if ( timeline->m_numOfStats > 0 ) {
        int i;
        for ( i = 0; i < numOfStats; i++ )
            (timeline->m_stat)[i] = (*stat)[i];
    }

#ifdef  _DEBUG
    _CrtMemCheckpoint( &s2 );
if ( _CrtMemDifference( &s3, &s1, &s2 ) )
   _CrtMemDumpStatistics( &s3 );
#endif
    return ( messages );
}

// friends_timeline ���擾
CString
CTwitter::GetFriendsTimeline(
                CTwitterTimeline *timeline,
                ProceedingDialog *pdlg
            )
{
    GetTimeline( m_messages,
                 &m_stat,
                 m_numOfStats,
                 FRIENDS_TIMELINE,
                 "http://twitter.com/statuses/friends_timeline.json",
                 timeline,
                 pdlg );

    return ( m_messages );
}

// public_timeline ���擾
CString
CTwitter::GetPublicTimeline(
                CTwitterTimeline *timeline,
                ProceedingDialog *pdlg
            )
{
    GetTimeline( m_messages2,
                 &m_stat2,
                 m_numOfStats2,
                 PUBLIC_TIMELINE,
                 "http://twitter.com/statuses/public_timeline.json",
                 timeline,
                 pdlg );

    return ( m_messages2 );
}

// user_timeline ���擾
CString
CTwitter::GetUserTimeline(
                CTwitterTimeline *timeline,
                ProceedingDialog *pdlg
            )
{
    GetTimeline( m_messages3,
                 &m_stat3,
                 m_numOfStats3,
                 USER_TIMELINE,
                 "http://twitter.com/statuses/user_timeline.json",
                 timeline,
                 pdlg );

    return ( m_messages3 );
}

// replies (mentions) ���擾
CString
CTwitter::GetReplies(
                CTwitterTimeline *timeline,
                ProceedingDialog *pdlg
            )
{
    GetTimeline( m_messages4,
                 &m_stat4,
                 m_numOfStats4,
                 REPLIES,
              // "http://twitter.com/statuses/replies.json",
                 "http://twitter.com/statuses/mentions.json",
                 timeline,
                 pdlg );

    return ( m_messages4 );
}


// �_�C���N�g���b�Z�[�W����M
TWITTER_DIRECT_MESSAGE  *
CTwitter::RecvDirectMessages( int &numOfMessages, ProceedingDialog *pdlg )
{
    const char  *url = "http://twitter.com/direct_messages.xml";
    size_t      sz   = MAX_CONTENT_SIZE * MAX_NUM_OF_DIRECTMESSAGES;
    char        *response = new char[sz];

    m_numOfMessages = 0;

    if ( !m_dm || !response ) {
        numOfMessages = m_numOfMessages;
        return ( NULL );
    }

    if ( m_useOAuth ) {
        // OAuth �F��
        char    *request = new char[sz];
        char    key[MAX_KEYLENGTH * 2];
        char    base[MAX_CONTENT_SIZE];
        char    param[MAX_CONTENT_SIZE];

        key[0]   = NUL;
        base[0]  = NUL;
        param[0] = NUL;
        MakeOAuthBase( url, "GET", key, base, param );
        MakeOAuthRequest( url, request, key, base, param );

        SetUserAgent();
        setUpReceiveBuffer( response, sz );
        _http_getBASIC( request, NULL, NULL, response, NULL, NULL );
        delete [] request;
    }
    else {
        // BASIC �F��
        SetUserAgent();
        setUpReceiveBuffer( response, sz );
        _http_getBASIC( url, m_username, m_password, response, NULL, pdlg );
    }
    if ( *response ) {
        if ( strstr( response, "<created_at>" ) ) {
            char    *p, *q, *r, *s;
            CString temp;

         // failure = false;
            p = response;
            while ( *p ) {
                q = strstr( p, "<direct_message>" );
                if ( !q )
                    break;
                p = q + 17;
                r = strstr( p, "</direct_message>" );
                if ( !r )
                    break;

                // id
                temp = GetStringFromXML( p, "id", r );
                strcpy( m_dm[m_numOfMessages].id, temp );

                // text
                temp = GetStringFromXML( p, "text", r );
                strcpy( m_dm[m_numOfMessages].text, temp );
                s = strchr( m_dm[m_numOfMessages].text, '&' );
                if ( s && strchr( s + 1, ';' ) )
                    strcpy( m_dm[m_numOfMessages].text,
                            replaceEntityStrings( m_dm[m_numOfMessages].text,
                                                  CHARSET_SHIFTJIS ) );

                // sender_id
                temp = GetStringFromXML( p, "sender_id", r );
                strcpy( m_dm[m_numOfMessages].sender.id, temp );

                // recipient_id
                temp = GetStringFromXML( p, "recipient_id", r );
                strcpy( m_dm[m_numOfMessages].recipient.id, temp );

                // created_at
                m_dm[m_numOfMessages].createdAt =
                                            GetTimeFromXML( p, "created_at" );

                // sender_screen_name
                temp = GetStringFromXML( p, "sender_screen_name", r );
                strcpy( m_dm[m_numOfMessages].sender.screenName, temp );

                // recipient_screen_name
                temp = GetStringFromXML( p, "recipient_screen_name", r );
                strcpy( m_dm[m_numOfMessages].recipient.screenName, temp );

                // deleted
                m_dm[m_numOfMessages].deleted = false;

                m_numOfMessages++;
                if ( m_numOfMessages >= MAX_NUM_OF_DIRECTMESSAGES )
                    break;
            }
        }
        else if ( m_useOAuth )
            CheckOAuthResult( response );
    }
    replaceEntityStrings( NULL, CHARSET_UNKNOWN );
    delete [] response;

    numOfMessages = m_numOfMessages;

    return ( m_dm );
}


// �_�C���N�g���b�Z�[�W�𑗐M
bool
CTwitter::SendDirectMessage( CString screenName, CString message )
{
    bool    ret = false;
    size_t  sz  = MAX_CONTENT_SIZE;
    size_t  len = strlen( screenName ) + (message.GetLength() * 3 / 2) * 6;
    char    *request  = new char[len + 1];
    char    *response = new char[sz];

    if ( request && response ) {
        const char  *url = "http://twitter.com/direct_messages/new.xml";
        char        *p = sjis2utf( message );

        if ( m_useOAuth ) {
            // OAuth �F��
            char    *request0 = new char[sz];
            char    key[MAX_KEYLENGTH * 2];
            char    base[MAX_CONTENT_SIZE];
            char    param[MAX_CONTENT_SIZE];

            key[0]   = NUL;
            base[0]  = NUL;
            param[0] = NUL;
            MakeOAuthBase( url, "POST", key, base, param );

            sprintf( param + strlen(param),
                     "&"
                     "text=%s&",
                     encodeURLi( p ? p : message, FALSE ) );
            sprintf( param + strlen(param),
                     "user=%s",
                     encodeURLi( screenName, FALSE ) );

            MakeOAuthRequest( url, request0, key, base, param );

            SetUserAgent();
            setUpReceiveBuffer( response, sz );
            _http_postBASIC( request0, NULL, NULL, "", response, NULL, NULL );
            delete [] request0;
        }
        else {
            // BASIC �F��
            sprintf( request,
                     "user=%s&",
                     encodeURL( screenName ) );
            sprintf( request + strlen( request ),
                     "text=%s",
                     encodeURL( p ? p : message ) );
            SetUserAgent();
            setUpReceiveBuffer( response, sz );
            _http_postBASIC( url, m_username, m_password,
                             request, response, NULL, NULL );
        }
        if ( *response ) {
            if ( strstr( response, "<created_at>" ) )
                ret = true;
            else if ( m_useOAuth )
                CheckOAuthResult( response );
        }
    }

    if ( response )
        delete [] response;
    if ( request )
        delete [] request;

    return ( ret );
}


// �_�C���N�g���b�Z�[�W���폜
bool
CTwitter::DeleteDirectMessage( const char *messageID )
{
    bool    ret = false;
    size_t  sz  = MAX_CONTENT_SIZE;
    char    *request  = new char[sz];
    char    *response = new char[sz];
    char    url[MAX_URLLENGTH];

    if ( request && response ) {
        sprintf( request, "id=%s", messageID );
        sprintf( url,
                 "http://twitter.com/direct_messages/destroy/%s.xml",
                 messageID );
        if ( m_useOAuth ) {
            // OAuth �F��
            char    key[MAX_KEYLENGTH * 2];
            char    base[MAX_CONTENT_SIZE];
            char    param[MAX_CONTENT_SIZE];

            key[0]   = NUL;
            base[0]  = NUL;
            param[0] = NUL;
            MakeOAuthBase( url, "POST", key, base, param );
            MakeOAuthRequest( url, request, key, base, param );

            SetUserAgent();
            setUpReceiveBuffer( response, sz );
            _http_postBASIC( request, NULL, NULL, "", response, NULL, NULL );
        }
        else {
            // BASIC �F��
            SetUserAgent();
            setUpReceiveBuffer( response, sz );
            _http_postBASIC( url, m_username, m_password,
                             request, response, NULL, NULL );
        }
        if ( *response ) {
            if ( strstr( response, "<direct_message>" ) )
                ret = true;
            else if ( strstr( response,
                              "No direct message with that ID found." ) )
                MessageBox(
                    NULL,
                    "���̃_�C���N�g���b�Z�[�W�͂��łɍ폜����Ă��܂�  ",
                    "�_�C���N�g���b�Z�[�W�폜�ς�",
                    MB_OK|MB_ICONWARNING );
            else if ( m_useOAuth )
                CheckOAuthResult( response );
        }
    }

    if ( response )
        delete [] response;
    if ( request )
        delete [] request;

    return ( ret );
}


// �w�胆�[�U�̍ŐV�̔������擾
TWITTER_USER
CTwitter::ShowUser( const char *userID )
{
    TWITTER_USER    user;
    size_t          sz  = MAX_CONTENT_SIZE;
    char            *response = new char[sz];
    char            url[MAX_URLLENGTH];
 // bool            ret = false;

    if ( response ) {
        sprintf( url,
                 "http://twitter.com/users/show/%s.xml",
                 userID );
        if ( m_useOAuth ) {
            // OAuth �F��
            char    *request = new char[sz];
            char    key[MAX_KEYLENGTH * 2];
            char    base[MAX_CONTENT_SIZE];
            char    param[MAX_CONTENT_SIZE];

            key[0]   = NUL;
            base[0]  = NUL;
            param[0] = NUL;
            MakeOAuthBase( url, "GET", key, base, param );
            MakeOAuthRequest( url, request, key, base, param );

            SetUserAgent();
            setUpReceiveBuffer( response, sz );
            _http_getBASIC( request, NULL, NULL, response, NULL, NULL );
            delete [] request;
        }
        else {
            // BASIC �F��
            SetUserAgent();
            setUpReceiveBuffer( response, sz );
            _http_getBASIC( url, m_username, m_password, response, NULL, NULL );
        }
        if ( *response ) {
            char    *p = strstr( response, "<profile_image_url>" );
            if ( p ) {
             // ret  = true;
                user = GetUserFromXML(response, response + strlen(response));
            }
            else if ( m_useOAuth )
                CheckOAuthResult( response );
        }

        delete [] response;
    }

    return ( user );
}

// �w�胆�[�U�� friend �ɂ���
bool CTwitter::AddFriend( const char *userID )
{
    size_t  sz  = MAX_CONTENT_SIZE;
    char    *request  = new char[sz];
    char    *response = new char[sz];
    char    url[MAX_URLLENGTH];
    bool    ret = false;

    if ( request && response ) {
        sprintf( request, "id=%s", userID );
        sprintf( url,
                 "http://twitter.com/friendships/create/%s.xml",
                 userID );
        if ( m_useOAuth ) {
            // OAuth �F��
            char    key[MAX_KEYLENGTH * 2];
            char    base[MAX_CONTENT_SIZE];
            char    param[MAX_CONTENT_SIZE];

            key[0]   = NUL;
            base[0]  = NUL;
            param[0] = NUL;
            MakeOAuthBase( url, "POST", key, base, param );
            MakeOAuthRequest( url, request, key, base, param );

            SetUserAgent();
            setUpReceiveBuffer( response, sz );
            _http_postBASIC( request, NULL, NULL, "", response, NULL, NULL );
        }
        else {
            // BASIC �F��
            SetUserAgent();
            setUpReceiveBuffer( response, sz );
            _http_postBASIC( url, m_username, m_password,
                             request, response, NULL, NULL );
        }
        if ( *response ) {
            char    *p = strstr( response, "<profile_image_url>" );
            if ( p )
                ret  = true;
            else if ( m_useOAuth )
                CheckOAuthResult( response );
        }
    }

    if ( response )
        delete [] response;
    if ( request )
        delete [] request;

    return ( ret );
}

// �w�胆�[�U�� friend ����O��
bool CTwitter::RemoveFriend( const char *userID )
{
    size_t  sz  = MAX_CONTENT_SIZE;
    char    *request  = new char[sz];
    char    *response = new char[sz];
    char    url[MAX_URLLENGTH];
    bool    ret = false;

    if ( response ) {
        sprintf( request, "id=%s", userID );
        sprintf( url,
                 "http://twitter.com/friendships/destroy/%s.xml",
                 userID );
        if ( m_useOAuth ) {
            // OAuth �F��
            char    key[MAX_KEYLENGTH * 2];
            char    base[MAX_CONTENT_SIZE];
            char    param[MAX_CONTENT_SIZE];

            key[0]   = NUL;
            base[0]  = NUL;
            param[0] = NUL;
            MakeOAuthBase( url, "POST", key, base, param );
            MakeOAuthRequest( url, request, key, base, param );

            SetUserAgent();
            setUpReceiveBuffer( response, sz );
            _http_postBASIC( request, NULL, NULL, "", response, NULL, NULL );
        }
        else {
            // BASIC �F��
            SetUserAgent();
            setUpReceiveBuffer( response, sz );
            _http_postBASIC( url, m_username, m_password,
                             request, response, NULL, NULL );
        }
        if ( *response ) {
            char    *p = strstr( response, "<profile_image_url>" );
            if ( p )
                ret  = true;
            else if ( m_useOAuth )
                CheckOAuthResult( response );
        }
    }

    if ( response )
        delete [] response;
    if ( request )
        delete [] request;

    return ( ret );
}

// �w�� status �� favorites �ɂ���
bool CTwitter::SetFavorite( const char *statusID )
{
    size_t  sz  = MAX_CONTENT_SIZE;
    char    *request  = new char[sz];
    char    *response = new char[sz];
    char    url[MAX_URLLENGTH];
    bool    ret = false;

    if ( request && response ) {
        // favorites/create API �ɂ�� favorites �̃Z�b�g
        if ( m_useOAuth ) {
            // OAuth �F��
            sprintf( url,
                     "http://twitter.com/favorites/create/%s.json",
                     statusID );

            char    key[MAX_KEYLENGTH * 2];
            char    base[MAX_CONTENT_SIZE];
            char    param[MAX_CONTENT_SIZE];

            key[0]   = NUL;
            base[0]  = NUL;
            param[0] = NUL;
            MakeOAuthBase( url, "POST", key, base, param );
            MakeOAuthRequest( url, request, key, base, param );

            SetUserAgent();
            setUpReceiveBuffer( response, sz );
            _http_postBASIC( request, NULL, NULL, "", response, NULL, NULL );
        }
        else {
            // BASIC �F��
            SetUserAgent();
            setUpReceiveBuffer( response, sz );
            sprintf( request, "id=%s", statusID );
            sprintf( url,
                     "http://twitter.com/favorites/create/%s.json",
                     statusID );
            _http_postBASIC( url, m_username, m_password,
                             request, response, NULL, NULL );
        }
        if ( *response ) {
            if ( strstr( response, "created_at" ) )
                ret = true;
            else if ( m_useOAuth )
                CheckOAuthResult( response );
        }
    }

    if ( response )
        delete [] response;
    if ( request )
        delete [] request;

    return ( ret );
}

// �����̃X�N���[�����̎擾
CString CTwitter::GetScreenName()
{
    TWITTER_USER    user;
    CString         screenName = _T("");
    size_t          sz  = MAX_CONTENT_SIZE;
    char            *response = new char[sz];
    char            url[MAX_URLLENGTH];
    char            *targetURL =
                        "http://twitter.com/statuses/user_timeline.xml";

    if ( response ) {
        if ( m_useOAuth ) {
            // OAuth �F��
            char    *request = new char[sz];
            char    key[MAX_KEYLENGTH * 2];
            char    base[MAX_CONTENT_SIZE];
            char    param[MAX_CONTENT_SIZE];

            key[0]   = NUL;
            base[0]  = NUL;
            param[0] = NUL;

            sprintf( param,
                     "count=%d&",
                     1 );
            MakeOAuthBase( targetURL, "GET", key, base, param );
            MakeOAuthRequest( targetURL, request, key, base, param );

            SetUserAgent();
            setUpReceiveBuffer( response, sz );
            _http_getBASIC( request, NULL, NULL, response, NULL, NULL );
            delete [] request;
        }
        else {
            // BASIC �F��
            sprintf( url,
                     "%s?"
                     "count=%d",
                     targetURL, 1 );
            SetUserAgent();
            setUpReceiveBuffer( response, sz );
            _http_getBASIC(url, m_username, m_password, response, NULL, NULL);
        }
        if ( *response ) {
            char    *p = strstr( response, "<screen_name>" );
            if ( p ) {
             // ret  = true;
                user = GetUserFromXML(response, response + strlen(response));
                screenName = user.screenName;
            }
            else if ( m_useOAuth )
                CheckOAuthResult( response );
        }

        if ( (screenName.GetLength() == 0)  &&
             !isNecessaryToCheckProxyInfo()    ) {
            char    cookie[MAX_COOKIE_LEN];
            char    sname[MAX_KEYLENGTH];

            cookie[0] = NUL;
            sname[0]  = NUL;
            loginTwitter( m_username, m_password, cookie, sname );
            screenName = sname;
        }

        delete [] response;
    }

    return ( screenName );
}

// API�����󋵂̎擾
CString
CTwitter::GetRateLimitStatus()
{
    CString limitStatus = _T("");
    long    remain = m_remain;
    long    rate   = m_max_remain;

    GetRateLimitStatus( rate, remain );

    if ( rate > 0 ) {
        char    buf[64];
        memset( buf, 0x00, 64 );

        limitStatus  = _T("API����: ");
        limitStatus += ltoa( rate, buf, 10 );
        limitStatus += _T("��/�� -- �c��: ");
        limitStatus += ltoa( remain, buf, 10 );
        limitStatus += _T("��");

        m_remain = remain;
    }

    return ( limitStatus );
}

long
CTwitter::GetRateLimitStatus( long &rate, long &remain )
{
    size_t      sz  = MAX_CONTENT_SIZE;
    char        *response = new char[sz];
    const char  *targetURL =
                    "http://twitter.com/account/rate_limit_status.xml";

    if ( response ) {
        if ( m_useOAuth ) {
            // OAuth �F��
            char    *request = new char[sz];
            char    key[MAX_KEYLENGTH * 2];
            char    base[MAX_CONTENT_SIZE];
            char    param[MAX_CONTENT_SIZE];

            key[0]   = NUL;
            base[0]  = NUL;
            param[0] = NUL;
            MakeOAuthBase( targetURL, "GET", key, base, param );
            MakeOAuthRequest( targetURL, request, key, base, param );

            SetUserAgent();
            setUpReceiveBuffer( response, sz );
            _http_getBASIC( request, NULL, NULL, response, NULL, NULL );
            delete [] request;
        }
        else {
            // BASIC �F��
            SetUserAgent();
            setUpReceiveBuffer( response, sz );
            _http_getBASIC( "http://twitter.com/account/rate_limit_status.xml",
                            m_username, m_password, response, NULL, NULL );
        }
        if ( *response ) {
            char    *p = strstr( response, "<hourly-limit" );
            if ( p ) {
                char    *q = p + 12;

                p = strchr( q, '>' );
                if ( p++ ) {
                    if ( (*p >= '1') && (*p <= '9') )
                        rate = atol( p );
                    else
                        rate = 0;
                }
            }

            p = strstr( response, "<remaining-hits" );
            if ( p ) {
                char    *q = p + 15;

                p = strchr( q, '>' );
                if ( p++ ) {
                    if ( (*p == '-') || ((*p >= '1') && (*p <= '9')) )
                        remain = atol( p );
                    else
                        remain = 0;
                }
            }

            if ( m_useOAuth )
                CheckOAuthResult( response );
        }
        else {
            rate   = 0;
            remain = 0;
        }

        delete [] response;
    }

    return ( remain );
}


bool
CTwitter::loginTwitter(
                const char *username,
                const char *password,
                char       *cookie,
                char       *screenName
            )
{
    bool    ret = false;
    size_t  sz  = MAX_CONTENT_SIZE;
    char    request[BUFSIZ];
    char    *response = new char[sz];

    if ( response ) {
        sprintf( request,
                 "username_or_email=%s&"
                 "password=%s&"
                 "remember_me=1",
                 username, password );
        SetUserAgent();
        setUpReceiveBuffer( response, sz );
        _http_postBASIC( "https://twitter.com/sessions",
                         NULL, NULL,
                         request, response, cookie, NULL );
        if ( *response ) {
            char    *p = strstr(response, "Welcome back, <strong><a href=\"");
            char    *q;

            if ( p ) {
                ret = true;

                p += 31;
                if ( !strncmp( p, "http://twitter.com/", 19 ) )
                    p += 19;
                else if ( *p == '/' )
                    p++;
                q = strchr( p, '"' );
                if ( q ) {
                    strncpy( screenName, p, q - p );
                    screenName[q - p] = NUL;
                }
            }
            else {
                // ���{���
                p = strstr( response, sjis2utf(">�v���t�B�[��</a>") );
                if ( p ) {
                    while ( p >= response ) {
                        if ( *p != '<' ) {
                            p--;
                            continue;
                        }
                        if (!strncmp(p,"<a href=\"http://twitter.com/",28)) {
                            ret = true;
                            p += 28;
                            q = strchr( p, '"' );
                            if ( q ) {
                                strncpy( screenName, p, q - p );
                                screenName[q - p] = NUL;
                            }
                            break;
                        }
                    }
                }
            }
        }

        delete [] response;
    }

    return ( ret );
}

/*
 *  ���[�e�B���e�B���\�b�h�Q 
 */

void CTwitter::SetStatFromJSON(
                        const char     *q,
                        const char     *s,
                        TWITTER_STATUS *sp,
                        CString        &message
                    )
{
    bool    first     = false;
    bool    trancated = false;

    if ( !strncmp( q, "\"user\"", 6 ) ) {
        const char  *r;

        sp->user = GetUserFromJSON( q, s );
        first = true;
        r = strstr( q, "}," );
        if ( r && (r < s) )
            q = r + 2;
    }

    sp->createdAt = GetCreatedAtFromJSON(q, s);
    trancated = GetTruncated( q, s );
    strcpy( sp->source, GetSource( q, s, sp->sourceURL ) );
    strcpy( sp->id,     GetStatusID(q, s) );
    strcpy( sp->text,   GetTextFromJSON( q, s, sp->orig_text ) );

    if ( strchr( sp->text, '&' ) ) {
        strcpy( sp->text, decodeString( sp->text ) );

        char    *p = strchr( sp->text, '&' );
        if ( p && strchr( p + 1, ';' ) )
            strcpy( sp->text,
                    replaceEntityStrings( sp->text, CHARSET_SHIFTJIS ) );
    }
    if ( strchr( sp->orig_text, '&' ) ) {
        strcpy( sp->orig_text, decodeString( sp->orig_text ) );

        char    *p = strchr( sp->orig_text, '&' );
        if ( p && strchr( p + 1, ';' ) )
            strcpy( sp->orig_text,
                    replaceEntityStrings( sp->orig_text, CHARSET_UTF8 ) );
    }

    if ( !first )
        sp->user = GetUserFromJSON( q, s );

    if ( trancated ) {
        // GET sp->id
        CString statusURL = _T("http://twitter.com/");
        statusURL += sp->user.screenName;
        statusURL += _T("/statuses/");
        statusURL += sp->id;

        size_t  sz   = MAX_CONTENT_SIZE * MAX_NUM_OF_DIRECTMESSAGES;
        char    *response = new char[sz];
#if 0
        if ( m_useOAuth ) {
            // OAuth �F��
            char    *request = new char[sz];
            char    key[MAX_KEYLENGTH * 2];
            char    base[MAX_CONTENT_SIZE];
            char    param[MAX_CONTENT_SIZE];

            key[0]   = NUL;
            base[0]  = NUL;
            param[0] = NUL;
            MakeOAuthBase( statusURL, "GET", key, base, param );
            MakeOAuthRequest( statusURL, request, key, base, param );

            SetUserAgent();
            setUpReceiveBuffer( response, sz );
            _http_getBASIC( request, NULL, NULL, response, NULL, NULL );
                // �� �u����� API �͂Ȃ��v�Ƃ����Ӗ��̃G���[�ɂȂ�
            delete [] request;
        }

        if ( !m_useOAuth ||
             (strstr( response, "Invalid" ) && m_password.GetLength() > 0) ) {
            // BASIC �F��
            SetUserAgent();
            setUpReceiveBuffer( response, sz );
            _http_getBASIC( statusURL, m_username, m_password, response,
                            NULL, NULL );
        }
#else
        if ( (m_username.GetLength() > 0) &&
             (m_password.GetLength() > 0)    ) {
            SetUserAgent();
            setUpReceiveBuffer( response, sz );
            _http_getBASIC( statusURL, m_username, m_password, response,
                            NULL, NULL );
        }
#endif
        if ( *response ) {
            char    *p = strstr( response,
                                 "<span class=\"status-body\">"
                                 "<span class=\"entry-content\">" );
            if ( p ) {
                p += 54;

                char  *q = strstr( p, "</span>" );
                if ( q ) {
                    char    temp[MAX_DESCRIPTION_LEN * 2];
                    strncpy( temp, p, q - p );
                    temp[q - p] = NUL;

                    if ( strchr( temp, '<' ) ) {
                        char    *r, *s, *t;
                        bool    done = true;

                        // <a href="http://example.com/">http://exa...</a> ��
                        // �悤�ɖ����� ... �ɂ���Ă��܂��Ă��� URL ��{����
                        // URL �ɓW�J���邽�߂̏���
                        //   �������A<a href="/example">@example</a> �̂悤��
                        //   ���� URL �͓W�J�ΏۂƂ͂��Ȃ�
                        p = temp;
                        do {
                            done = true;
                            q = strstr( p, "<a " );
                            if ( q ) {
                                r = q + 3;
                                s = strstr( r, "href=\"http" );
                                if ( s ) {
                                    r = s + 6; // 6 = strlen("href=\"");
                                    s = strchr( r, '"' );
                                    if ( s ) {
                                        t = strstr( s + 1, "</a>" );
                                        if ( t ) {
                                            t += 4;
                                            strncpy( q, r, s - r );
                                            strcpy( q + (s - r), t );

                                            p = q + (s - r);
                                            done = false;
                                        }
                                    }
                                }
                                else {
                                    s = strstr( r, "</a>" );
                                    if ( s ) {
                                        p = s + 4;
                                        done = false;
                                    }
                                }
                            }
                        } while ( !done && !(*p) );

                        /* html �^�O�̏��� */
                        p = temp;
                        while ( ( q = strchr( p, '<' ) ) != NULL ) {
                            if ( (r = strchr(q + 1, '>')) != NULL )
                                strcpy( q, r + 1 );
                            else {
                                *q = NUL;
                                break;
                            }
                        }
                    }

                    strcpy( sp->orig_text,
                            replaceEntityStrings( temp, CHARSET_UTF8 ) );
                    strcpy( temp, ExpandTinyURL( sp->orig_text ) );
                    strcpy( sp->text, any2sjis( temp ) );
                }
            }
        }

        delete [] response;
    }

    MakeMessageForScreen( message, sp );
    strcpy( sp->user.lastStatus, sp->text );
    MakeMessageForLogging( sp );
}

CString CTwitter::GetIdFromJSON( const char *p, const char *terminator )
{
    // Twitter �� status ID �� singed long �ň�����͈͂𒴂��Ă��܂���
    // (2009�N6��13��)���߂̑΍�Ƃ��āACService::GetIdFromJSON() ���Ă�
    // �̂���߂āA�V���� CTwitter::GetIdFromJSON() ��p�ӂ���
    char    statusID[MAX_KEYLENGTH * 2 + 2];
    CString id;

    // "id"
    statusID[0] = NUL;
    char    *q = strchr( p, ':' );
    if ( q && (q < terminator) ) {
        q++;

        char    *r = strchr( q, ',' );
        if ( r && (r < terminator) ) {
            strncpy( statusID, q, r - q );
            statusID[r - q] = NUL;
        }
    }

    id = statusID;

    return ( id );
}

CString CTwitter::GetStatusID(
                        const char *p,
                        const char *terminator
                    )
{
    const char  *q  = p;
    const char  *r1 = strstr( q, "\"user\"" );
    const char  *r2 = strstr( q, "\"id\"" );

    if ( r1 && r2 && (r1 < terminator) && (r2 < terminator) ) {
        if ( r2 > r1 ) {
            r1 = strstr( r2 + 4 , "\"id\"" );
            if ( r1 && (r1 < terminator) )
                q = r1;
        }
    }

    CString s = GetIdFromJSON( q, terminator );
    return ( s );
}

char    *
CTwitter::GetSource(
                const char *q,
                const char *s,
                char       *sourceURL
            )
{
    Thread static char  temp[BUFSIZ * 2];
    GetStringFromJSON( temp, BUFSIZ * 2, "\"source\"", q, s );

    char    *p = strstr( temp, "<a href=\"" );
    if ( p ) {
        char    *q;

        p += 9;
        q = strchr( p, '"' );
        if ( q ) {
            strncpy( sourceURL, p, q - p );
            sourceURL[q - p] = NUL;

            p = strchr( q + 1, '>' );
            if ( p ) {
                p++;
                q = strstr( p, "</a>" );
                if ( q ) {
                    *q = NUL;
                    strcpy( temp, p );
                }
            }
        }
        else
            sourceURL[0] = NUL;
    }
    else
        sourceURL[0] = NUL;

    return ( temp );
}

bool
CTwitter::GetTruncated(
                const char *q,
                const char *s
            )
{
    bool    ret = false;
    Thread static char  temp[BUFSIZ * 2];
    GetStringFromJSON( temp, BUFSIZ * 2, "\"truncated\"", q, s );

    char    *p = strstr( temp, "true" );
    if ( p )
        ret = true;
    else {
        p = strstr( temp, "false" );
        if ( p )
            ret = false;
    }

    return ( ret );
}

void
CTwitter::MakeMessageForScreen(
            CString        &message,
            TWITTER_STATUS *sp )
{
    message += sp->user.screenName;
    message += _T(": ");
    message += EscapeQuote(sp->text);

    message += _T(" ��");
    if ( m_useTwitStar )
        message += _T(" / ��");
    message += _T("[ID: ");
    message += sp->id;
    message += _T("]");

    if ( sp->source[0] ) {
        message += _T(" (from ");
        if ( sp->sourceURL[0] )
            message += _T("*");
        message += sp->source;
        if ( sp->sourceURL[0] )
            message += _T("*");
        message += _T(")");
    }

    message += _T("\r\n");
}

void
CTwitter::MakeMessageForLogging( TWITTER_STATUS *sp )
{
    if ( !m_log )
        m_log = new TWITTER_LOG[MAX_NUMOFSTATUS + 1];

    if ( m_log && (m_numOfLogs < MAX_NUMOFSTATUS) ) {
        sprintf( m_log[m_numOfLogs].orig_text,
                 "%s [ID: %s]",
                 sp->orig_text, sp->id );
        if ( sp->source[0] ) {
            sprintf( m_log[m_numOfLogs].orig_text +
                        strlen(m_log[m_numOfLogs].orig_text),
                     " (from %s)",
                     sp->source );
        }

        strcpy( m_log[m_numOfLogs].orig_userName, sp->user.orig_userName );

        m_log[m_numOfLogs].createdAt = sp->createdAt.GetTime();

        struct tm   ttmm;
     // struct tm   *tm = sp->createdAt.GetGmtTm( &ttmm );
        struct tm   *tm = sp->createdAt.GetLocalTm( &ttmm );

        m_log[m_numOfLogs].createdAt_yyyy = tm->tm_year + 1900;
        m_log[m_numOfLogs].createdAt_mm   = tm->tm_mon + 1;
        m_log[m_numOfLogs].createdAt_dd   = tm->tm_mday;
        m_log[m_numOfLogs].createdAt_HH   = tm->tm_hour;
        m_log[m_numOfLogs].createdAt_MM   = tm->tm_min;
        m_log[m_numOfLogs].createdAt_SS   = tm->tm_sec;
        m_numOfLogs++;
    }
}


char    *
CTwitter::CutInReplyTo( char *s )
{
    const char  *inReplyTo = "\"in_reply_to\":{";
    int         len = strlen( inReplyTo );
    int         cnt = 0;
    char        *t, *u;

    do {
        t = strstr( s, inReplyTo );
        if ( !t )
            break;

        u   = t + len;
        cnt = 1;

        bool quote = false;
        while ( *u ) {
            if ( quote ) {
                if ( *u == '\\' )
                    u++;
                else if ( *u == '"' )
                    quote = false;
                u++;
                continue;
            }

            if ( *u == '\\' )
                u++;
            else if ( *u == '"' )
                quote = true;
            else if ( *u == '{' )
                cnt++;
            else if ( *u == '}' ) {
                cnt--;
                if ( cnt == 0 ) {
                    u++;
                    if ( *u == ',' )
                        u++;
                    break;
                }
            }

            u++;
        }

        strcpy( t, u );
    } while ( t );

    return ( s );
}

bool
CTwitter::GetToken(
        const char *response,
        CString    &oauthToken,
        CString    &oauthTokenSecret
    )
{
    CString screenName = _T("");
    return ( GetToken( response, oauthToken, oauthTokenSecret, screenName ) );
}

bool
CTwitter::GetToken(
        const char *response,
        CString    &oauthToken,
        CString    &oauthTokenSecret,
        CString    &screenName
    )
{
    bool    ret = false;

    if ( response && *response ) {
        char    oauth_token[BUFSIZ];
        char    oauth_token_secret[BUFSIZ];
        char    screen_name[BUFSIZ];

        char    *p = strstr( response, "oauth_token=" );
        if ( p ) {
            p += 12;

            char    *q = strchr( p, '&' );
            if ( q ) {
                strncpy( oauth_token, p, q - p );
                oauth_token[q - p] = NUL;
            }
            else {
                strcpy( oauth_token, p );
            }

            oauthToken = oauth_token;
        }

        p = strstr( response, "oauth_token_secret=" );
        if ( p ) {
            p += 19;

            char    *q = strchr( p, '&' );
            if ( q ) {
                strncpy( oauth_token_secret, p, q - p );
                oauth_token_secret[q - p] = NUL;
            }
            else {
                strcpy( oauth_token_secret, p );
            }

            oauthTokenSecret = oauth_token_secret;
        }

        p = strstr( response, "screen_name=" );
        if ( p ) {
            p += 12;

            char    *q = strchr( p, '&' );
            if ( q ) {
                strncpy( screen_name, p, q - p );
                screen_name[q - p] = NUL;
            }
            else {
                strcpy( screen_name, p );
            }

            screenName = screen_name;
        }

        if ( (oauthToken.GetLength()       > 0) &&
             (oauthTokenSecret.GetLength() > 0)    )
            ret = true;
    }

    return ( ret );
}


bool
CTwitter::GetRequestToken(
        const char *consumerKey,
        const char *consumerSecret,
        CString    &oauthToken,
        CString    &oauthTokenSecret
    )
{
    bool    ret = false;

    time_t  t  = time( NULL );
    size_t  sz = MAX_CONTENT_SIZE * 16;
    char    base[MAX_CONTENT_SIZE];
    char    param[MAX_CONTENT_SIZE];
    char    nonce[MAX_KEYLENGTH];
    char    key[MAX_KEYLENGTH * 2];

    char    *request  = new char[sz];
    char    *response = new char[sz];

    CString targetURL = _T("");
    targetURL.LoadString(IDS_URL_TWITTER_REQUEST_TOKEN);

    strcpy( nonce, getNonce(NULL) );

    sprintf( key, "%s&", encodeURLi( consumerSecret, FALSE ) );

    sprintf( base,
             "GET&"
             "%s&",
             encodeURLi( targetURL, FALSE ) );
    sprintf( param,
             "oauth_consumer_key=%s&"
             "oauth_nonce=%s&"
             "oauth_signature_method=HMAC-SHA1&"
             "oauth_timestamp=%ld&"
             "oauth_version=1.0",
             consumerKey,
             nonce,
             t );

    MakeOAuthRequest( targetURL, request, key, base, param );

    SetUserAgent();
    setUpReceiveBuffer( response, sz );
    _http_getBASIC( request, NULL, NULL, response, NULL, NULL );
    ret = GetToken( response, oauthToken, oauthTokenSecret );

    delete [] response;
    delete [] request;

    return ( ret );
}

bool
CTwitter::GetAccessToken(
        const char *consumerKey,
        const char *consumerSecret,
        CString    &oauthToken,
        CString    &oauthTokenSecret,
        CString    &screenName
    )
{
    bool    ret = false;

    if ( !consumerKey    || !(*consumerKey)    ||
         !consumerSecret || !(*consumerSecret)    )
        return ( ret );

    // request token �擾
    CString _oauthToken       = _T("");
    CString _oauthTokenSecret = _T("");
    if ( !GetRequestToken( consumerKey, consumerSecret,
                           _oauthToken, _oauthTokenSecret ) )
        return ( ret );        

    // �u���E�U�N�� -- ���[�U�ɃA�N�Z�X�������߂�
    CString targetURL = _T("");
    targetURL.LoadString(IDS_URL_TWITTER_AUTHORIZE);

    char    url[MAX_URLLENGTH];
    sprintf( url, "%s?oauth_token=%s", targetURL, _oauthToken );
    ShellExecute( NULL, "open", url, NULL, NULL, SW_SHOWNORMAL );

    // ���[�U�̋��҂�
#ifdef  BEFORE_20090610
    // OAuth 1.0
    int r = MessageBox( NULL,
            "Chirrup �� Twitter �ɃA�N�Z�X���鋖��^���Ă��������B\r\n"
            "����^���I�������AOK �{�^���������Ă��������B\r\n"
            "����^�������Ȃ��ꍇ�� �L�����Z�� �{�^���������Ă��������B  ",
            "Twitter �ւ̃A�N�Z�X����", MB_OKCANCEL|MB_ICONINFORMATION );
    if ( r != IDOK ) {
        MessageBox( NULL,
                    "Twitter �ւ̃A�N�Z�X�𒆎~���܂��B  ",
                    "�A�N�Z�X���~", MB_OK|MB_ICONWARNING );
        return ( ret );
    }
#else   /* !BEFORE_20090610 */
    // OAuth 1.0a
    InputPinDialog  dlg;

    int r = dlg.DoModal();
    if ( (r != IDOK) || (dlg.m_pin.GetLength() < 6) )
        return ( ret );
#endif  /* !BEFORE_20090610 */

    // access token �擾
    time_t  t  = time( NULL );
    size_t  sz = MAX_CONTENT_SIZE * 16;
    char    base[MAX_CONTENT_SIZE];
    char    param[MAX_CONTENT_SIZE];
    char    nonce[MAX_KEYLENGTH];
    char    key[MAX_KEYLENGTH * 2];

    char    *request  = new char[sz];
    char    *response = new char[sz];

    targetURL = _T("");
    targetURL.LoadString(IDS_URL_TWITTER_ACCESS_TOKEN);

    strcpy( nonce, getNonce(NULL) );

    sprintf( key,
             "%s&",
             encodeURLi( consumerSecret, FALSE ) );
    sprintf( key + strlen(key),
             "%s",
             encodeURLi( _oauthTokenSecret, FALSE ) );

    sprintf( base,
             "GET&"
             "%s&",
             encodeURLi( targetURL, FALSE ) );

#ifdef  BEFORE_20090610
    // OAuth 1.0
    sprintf( param,
             "oauth_consumer_key=%s&"
             "oauth_nonce=%s&"
             "oauth_signature_method=HMAC-SHA1&"
             "oauth_timestamp=%ld&"
             "oauth_token=%s&"
             "oauth_version=1.0",
             consumerKey,
             nonce,
             t,
             _oauthToken );
#else   /* !BEFORE_20090610 */
    // OAuth 1.0a
    sprintf( param,
             "oauth_consumer_key=%s&"
             "oauth_nonce=%s&"
             "oauth_signature_method=HMAC-SHA1&"
             "oauth_timestamp=%ld&"
             "oauth_token=%s&"
             "oauth_verifier=%s&"
             "oauth_version=1.0",
             consumerKey,
             nonce,
             t,
             _oauthToken,
             (const char *)dlg.m_pin );
#endif  /* !BEFORE_20090610 */

    MakeOAuthRequest( targetURL, request, key, base, param );

    SetUserAgent();
    setUpReceiveBuffer( response, sz );
    _http_getBASIC( request, NULL, NULL, response, NULL, NULL );
    ret = GetToken( response, oauthToken, oauthTokenSecret, screenName );

    if ( ret ) {
        m_oauthToken       = oauthToken;
        m_oauthTokenSecret = oauthTokenSecret;
    }

    delete [] response;
    delete [] request;

    return ( ret );
}


void
CTwitter::MakeOAuthBase(
        const char *url,
        const char *method,
        char       *key,
        char       *base,
        char       *param
    )
{
    CChirrupApp *ap = (CChirrupApp *)AfxGetApp();
    time_t      t   = time( NULL );
    char        nonce[MAX_KEYLENGTH];

    strcpy( nonce, getNonce(NULL) );

    sprintf( key,
             "%s&",
             encodeURLi( ap->m_tcSecret, FALSE ) );
    sprintf( key + strlen(key),
             "%s",
             encodeURLi( m_oauthTokenSecret, FALSE ) );

    sprintf( base,
             "%s&"
             "%s&",
             method,
             encodeURLi( url, FALSE ) );

    sprintf( param[0] ? param + strlen(param) : param,
             "oauth_consumer_key=%s&"
             "oauth_nonce=%s&"
             "oauth_signature_method=HMAC-SHA1&"
             "oauth_timestamp=%ld&"
             "oauth_token=%s&"
             "oauth_version=1.0",
             ap->m_tcKey,
             nonce,
             t,
             m_oauthToken );
}


void
CTwitter::MakeOAuthRequest(
        const char *url,
        char       *request,
        char       *key,
        char       *base,
        char       *param
    )
{
    char    digest[SHA1HashSize * 4];

    sprintf( base + strlen(base),
             "%s",
             encodeURLi(param, FALSE) );

    memset( digest, 0x00, SHA1HashSize );
    hmac_sha1( (unsigned char *)base, strlen(base),
               (unsigned char *)key, strlen(key),
               digest );
    strcpy( digest, base64( (unsigned char *)digest, SHA1HashSize ) );

    sprintf( request,
             "%s?"
             "%s&"
             "oauth_signature=%s",
             url,
             param,
             encodeURLi( digest, TRUE ) );
}


bool
CTwitter::CheckOAuthResult( const char *response )
{
    bool    ret = true;
    unsigned short responseCode = getStatusCode();

    if ( (responseCode == 401) ||
         strstr( response, "Invalid OAuth Request" ) ||
         strstr( response, "Failed to validate oauth signature or token" ) ) {
        MessageBox( NULL,
                    "OAuth �F�؂Ɏ��s���܂����B\r\n"
                    "���̃G���[���p�ɂɏo��悤�ł���΁A"
                    "�A�N�Z�X�g�[�N�����擾�������Ă��������B  ",
                    "OAuth �F�؃G���[",
                    MB_OK|MB_ICONERROR );
        ret = false;
    }

    return ( ret );
}
