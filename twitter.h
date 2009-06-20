/*
 * twitter.h   : Twitter �N���C�A���g chirrup
 *      Twitter API �𗘗p���邽�߂̊e�폈���Q �w�b�_�t�@�C��
 *          written by H.Tsujimura  4 Apr 2007 / 28 Apr 2007
 *
 *      Copyright (c) 2007, 2008, 2009 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/twitter.h $
 * 
 * 2     09/06/18 1:33 tsupo
 * 2.01��
 * 
 * 36    09/06/16 0:51 Tsujimura543
 * �A�N�Z�X�g�[�N���擾���ɕԂ��Ă���X�N���[�����𗘗p����悤�ɂ���
 * 
 * 35    09/06/16 0:01 Tsujimura543
 * Twitter �� status ID �� singed long �ň�����͈͂𒴂��Ă��܂���
 * (2009�N6��13��)���߂̑΍�Ƃ��āACService::GetIdFromJSON() ���Ă�
 * �̂���߂āA�V���� CTwitter::GetIdFromJSON() ��p�ӂ���
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 34    09/04/09 16:03 Tsujimura543
 * API �Ŏ擾���������� trancated �� true �̂Ƃ��́A���Y�����̃p�[�}�����N
 * �� GET ���āA���S�ȏ�Ԃ̔������擾����悤�ɂ���
 * 
 * 33    09/04/07 15:46 Tsujimura543
 * OAuth �� "Invalid OAuth Request" �����������Ƃ��̏�����ǉ�
 * 
 * 32    09/04/01 3:16 Tsujimura543
 * Twitter �� OAuth �Ή��A����
 * 
 * 31    09/03/30 23:45 Tsujimura543
 * Twitter �� OAuth �Ή����� ����3
 * 
 * 30    08/07/14 16:54 Tsujimura543
 * Twitter �́uAPI�������擾API�v���Ăԉ񐔁A�^�C�~���O�𒲐���������
 * 
 * 29    08/06/30 20:10 Tsujimura543
 * long GetRateLimitStatus() ��ǉ�
 * 
 * 28    08/06/30 18:49 Tsujimura543
 * GetRateLimitStatus() ��ǉ�
 * 
 * 27    08/04/15 21:10 Tsujimura543
 * CutInReplyTo() ��ǉ��Ain_reply_to: �̓���q�\���ɑΉ�
 * 
 * 26    07/09/06 19:42 Tsujimura543
 * �_�~�[�̃R�s�[�R���X�g���N�^�A������Z�q�� private �Ƃ��ē����B
 * �m��Ȃ������Ƀ������m��(�Ɖ�����Y��)����������\����r���B
 * 
 * 25    07/08/17 17:21 Tsujimura543
 * SetFavorite() ��ǉ�
 * 
 * 24    07/07/23 14:54 Tsujimura543
 * GetSource() ��ǉ�
 * 
 * 23    07/07/05 0:50 Tsujimura543
 * (1) GetStatFromJSON(), GetUserTimeline() �̈�����ύX
 * (2) TWITTER_USER �\���̂̕ύX(orig_userName��ǉ�)�ɔ����C��
 * (3) MakeMessageForScreen() �� MakeMessageForLogging() ��p��
 * 
 * 22    07/06/25 18:03 Tsujimura543
 * DeleteReserved(), DeleteReserved2() �֘A�A�R�[�h�𐮗�
 * 
 * 21    07/06/25 17:40 Tsujimura543
 * DeleteReserved(), DeleteReserved2() ��ǉ�
 * 
 * 20    07/06/21 19:15 Tsujimura543
 * SetUserAgent() �� CService ���̃��\�b�h�Ɉ�{������
 * 
 * 19    07/06/20 19:28 Tsujimura543
 * GetStatusID() �𓱓�
 * 
 * 18    07/06/19 23:09 Tsujimura543
 * CService �𓱓����A�\�[�X�𐮗�����
 * 
 * 17    07/06/19 17:38 Tsujimura543
 * GetTwitterScreenName() �� GetScreenName() �ɕύX
 * 
 * 16    07/06/18 22:35 Tsujimura543
 * ���[�U���̍ő勖�e����32�o�C�g����64�o�C�g�֕ύX
 * 
 * 15    07/06/18 18:51 Tsujimura543
 * �f�t�H���g�A�C�R���̒�`�� defaultImage.h �Ɉڂ�
 * 
 * 14    07/06/14 18:25 Tsujimura543
 * _http_getBASIC() �� _http_postBASIC() �̃v���g�^�C�v�錾��
 * twitter.h �Ɉړ�
 * 
 * 13    07/06/14 17:56 Tsujimura543
 * Wassr �ɑΉ�
 * 
 * 12    07/06/13 15:55 Tsujimura543
 * �u�_�C���N�g���b�Z�[�W�̍폜�v�ɑΉ�
 * 
 * 11    07/06/13 0:12 Tsujimura543
 * (1) TIMELINE_INFO �֘A fix
 * (2) �����ݒ�t�@�C���ǂݏ�����V�������O�t�@�C���Ǘ��d�l�ɑΉ�������
 * 
 * 10    07/06/11 18:39 Tsujimura543
 * Twitter �� user_timeline �̉{�����T�|�[�g
 * 
 * 9     07/06/07 19:23 Tsujimura543
 * ���t�@�N�^�����O
 * 
 * 8     07/06/06 21:24 Tsujimura543
 * ���O���t�@�C���ɏ����o���@�\������
 * 
 * 7     07/06/04 21:11 Tsujimura543
 * friend �� add �� remove ������ (for Twitter)
 * 
 * 6     07/06/04 14:51 Tsujimura543
 * _http_get() �� _http_post() �̃v���g�^�C�v�錾�� twitter.h �Ɉړ�
 * 
 * 5     07/05/29 3:56 Tsujimura543
 * Jaiku (�� public_timeline �̉{��) �ɑΉ�
 * 
 * 4     07/05/26 0:22 Tsujimura543
 * Twitter �ƒʐM���镔����ʃX���b�h�����Ă݂�
 * 
 * 3     07/05/23 22:24 Tsujimura543
 * public_timeline �̎擾�ɑΉ�
 * 
 * 2     07/04/27 20:53 Tsujimura543
 * GetTwitterScreenName() ��ǉ�
 * 
 * 1     07/04/27 19:36 Tsujimura543
 * �V�K�쐬 (���܂ŕ����̃\�[�X�ɕ��U���Ă��� Twitter API �֘A�������W�听
 * �������̂Ƃ��āACTwitter �N���X��p�ӂ���)
 */

#ifndef __TWITTER_H__
#define __TWITTER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxwin.h>         // MFC �̃R�A����ѕW���R���|�[�l���g
#include "resource.h"		// ���C�� �V���{��
#include "ProceedingDialog.h"
#include "defaultImage.h"
#include "CService.h"

class CTwitter : public CService
{
public:
    CTwitter();
    ~CTwitter();

    void    DeleteReserved(TWITTER_STATUS *sp);
    void    DeleteReserved2(TWITTER_STATUS *sp);

    // �_�C���N�g���b�Z�[�W (�ŐV�� MAX_NUM_OF_DIRECTMESSAGES ��)
    TWITTER_DIRECT_MESSAGE  *m_dm;
    int                     m_numOfMessages;

    // �����𓊍e
    bool    PostUpdate( CString monologue, ProceedingDialog *pdlg );

    // friends_timeline ���擾
    CString GetFriendsTimeline( CTwitterTimeline *timeline,
                                ProceedingDialog *pdlg );

    // public_timeline ���擾
    CString GetPublicTimeline( CTwitterTimeline *timeline,
                               ProceedingDialog *pdlg );

    // user_timeline ���擾
    CString GetUserTimeline( CTwitterTimeline *timeline,
                             ProceedingDialog *pdlg );

    // replies ���擾
    CString GetReplies( CTwitterTimeline *timeline,
                        ProceedingDialog *pdlg );

    // �_�C���N�g���b�Z�[�W����M
    TWITTER_DIRECT_MESSAGE  *RecvDirectMessages( int &numOfMessages,
                                                 ProceedingDialog *pdlg );

    // �_�C���N�g���b�Z�[�W�𑗐M
    bool    SendDirectMessage( CString screenName, CString message );

    // �_�C���N�g���b�Z�[�W���폜
    bool    DeleteDirectMessage( const char *messageID );

    // �w�胆�[�U�̍ŐV�̔������擾
    TWITTER_USER    ShowUser( const char *userID );

    // �w�胆�[�U�� friend �ɂ���
    bool    AddFriend( const char *userID );

    // �w�胆�[�U�� friend ����O��
    bool    RemoveFriend( const char *userID );

    // �w�� status �� favorites �ɂ���
    bool    SetFavorite( const char *statusID );

    // �����̃X�N���[�����̎擾
    CString GetScreenName();

    // API�����󋵂̎擾
    CString GetRateLimitStatus();
    long    GetRateLimitStatus( long &rate, long &remain );

    // OAuth �A�N�Z�X�g�[�N���̎擾
    bool    GetAccessToken( const char *consumerKey,
                            const char *consumerSecret,
                            CString    &oauthToken,
                            CString    &oauthTokenSecret,
                            CString    &screenName );

protected:
    CString GetTimeline(
                    CString          &messages,
                    TWITTER_STATUS   **stat,
                    long             &numOfStats,
                    TIMELINE_TYPE    t,
                    const char       *endPointURL,
                    CTwitterTimeline *timeline,
                    ProceedingDialog *pdlg );
    CString GetIdFromJSON(
                    const char *p,
                    const char *terminator );
    CString GetStatusID(
                    const char *p,
                    const char *terminator );
    char    *GetSource( const char *q,
                        const char *s,
                        char       *sourceURL );
    bool    GetTruncated( const char *q,
                          const char *s );

    void    SetStatFromJSON(
                    const char     *q,
                    const char     *s,
                    TWITTER_STATUS *sp,
                    CString        &message );
    void    MakeMessageForScreen(
                    CString        &message,
                    TWITTER_STATUS *sp );
    void    MakeMessageForLogging(
                    TWITTER_STATUS *sp );

    char    *CutInReplyTo( char *s );

private:
    bool    loginTwitter( const char *username,
                          const char *password,
                          char       *cookie,
                          char       *screenName );

    // OAuth ���N�G�X�g�g�[�N���̎擾
    bool    GetRequestToken( const char *consumerKey,
                             const char *consumerSecret,
                             CString    &oauthToken,
                             CString    &oauthTokenSecret );

    bool    GetToken( const char *response,
                      CString    &oauthToken,
                      CString    &oauthTokenSecret );
    bool    GetToken( const char *response,
                      CString    &oauthToken,
                      CString    &oauthTokenSecret,
                      CString    &screenName );

    void    MakeOAuthBase( const char *url,
                           const char *method,
                           char       *key,
                           char       *base,
                           char       *param );
    void    MakeOAuthRequest( const char *url,
                              char       *request,
                              char       *key,
                              char       *base,
                              char       *param );

    bool    CheckOAuthResult( const char *response );

    CString	        m_messages4;    // replies
    long            m_numOfStats4;
    TWITTER_STATUS  *m_stat4;
    long            m_max_remain;
    long            m_remain;
#define TWITTER_MAX_REMAIN  70

private:
    CTwitter( CTwitter &obj );
    CTwitter    operator = ( CTwitter &obj );
};


#endif  /* __TWITTER_H__ */