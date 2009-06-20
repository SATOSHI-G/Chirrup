/*
 * jaiku.h   : Jaiku �N���C�A���g chirrup
 *      Jaiku API �𗘗p���邽�߂̊e�폈���Q �w�b�_�t�@�C��
 *          written by H.Tsujimura  28 May 2007
 *
 *      Copyright (c) 2007 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/jaiku.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 23    09/04/16 3:40 Tsujimura543
 * Jaiku �́u����ID�v�A�u�R�����gID�v�̎d�l�ύX�ɔ����C�������{
 * 
 * 22    09/04/16 1:40 Tsujimura543
 * Jaiku �� OAuth �Ή� (�Â�)
 * 
 * 21    09/04/15 1:17 Tsujimura543
 * Jaiuku �� OAuth �Ή�����
 * 
 * 20    07/09/06 19:42 Tsujimura543
 * �_�~�[�̃R�s�[�R���X�g���N�^�A������Z�q�� private �Ƃ��ē����B
 * �m��Ȃ������Ƀ������m��(�Ɖ�����Y��)����������\����r���B
 * 
 * 19    07/07/05 1:25 Tsujimura543
 * (1) GetUserTimeline() �̈�����ύX
 * (2) MakeMessageForScreen() �� MakeMessageForLogging() �����ۂ�
 *     �g���悤�ɂ���
 * 
 * 18    07/07/05 0:50 Tsujimura543
 * (1) GetStatFromJSON(), GetUserTimeline() �̈�����ύX
 * (2) TWITTER_USER �\���̂̕ύX(orig_userName��ǉ�)�ɔ����C��
 * (3) MakeMessageForScreen() �� MakeMessageForLogging() ��p��
 * 
 * 17    07/06/25 18:03 Tsujimura543
 * DeleteReserved(), DeleteReserved2() �֘A�A�R�[�h�𐮗�
 * 
 * 16    07/06/25 17:40 Tsujimura543
 * DeleteReserved(), DeleteReserved2() ��ǉ�
 * 
 * 15    07/06/21 19:15 Tsujimura543
 * SetUserAgent() �� CService ���̃��\�b�h�Ɉ�{������
 * 
 * 14    07/06/21 13:33 Tsujimura543
 * status ID �i�[�̈�T�C�Y������ɑ��₷
 * 
 * 13    07/06/21 1:07 Tsujimura543
 * status ID �i�[�̈�T�C�Y�𑝂₵��
 * 
 * 12    07/06/20 19:28 Tsujimura543
 * GetStatusID() �𓱓�
 * 
 * 11    07/06/20 2:14 Tsujimura543
 * CJaiku �� CTwitter �̔h���N���X���� CService �̔h���N���X�ɕύX
 * (���邽�߂ɏ������z�֐��ɑΉ�����_�~�[�̊֐���ǉ�)
 * 
 * 10    07/06/19 23:05 Tsujimura543
 * CService �����ɔ����C�������{
 * 
 * 9     07/06/18 18:51 Tsujimura543
 * �f�t�H���g�A�C�R���̒�`�� defaultImage.h �Ɉڂ�
 * 
 * 8     07/06/15 23:36 Tsujimura543
 * GetIdFromJSON() ��ǉ�
 * 
 * 7     07/06/07 19:56 Tsujimura543
 * ���t�@�N�^�����O
 * 
 * 6     07/06/06 23:11 Tsujimura543
 * ���O���t�@�C���ɏ����o���@�\������
 * 
 * 5     07/05/29 12:48 Tsujimura543
 * Jaiku �� friends_timeline �Ή�(�r��)
 * 
 * 4     07/05/29 6:50 Tsujimura543
 * C1001 �G���[�΍�
 * 
 * 3     07/05/29 5:13 Tsujimura543
 * Jaiku �� user_timeline �̉{���ɑΉ�
 * 
 * 2     07/05/29 4:34 Tsujimura543
 * Jaiku �� public_timeline �̉{���@�\�A���� (����m�F�ς�)
 * 
 * 1     07/05/29 1:47 Tsujimura543
 * �ŏ��̔� (������)
 */

#ifndef __JAIKU_H__
#define __JAIKU_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CService.h"

typedef struct jaikuUser    {
    char    nick[MAX_KEYLENGTH];
    char    firstName[MAX_NAMELEN];
    char    lastName[MAX_NAMELEN];
    char    avatar[MAX_URLLENGTH];
    char    url[MAX_URLLENGTH];
    HBITMAP bitmap;
}   JAIKU_USER;

typedef struct jaikuPresence    {
    CTime       createdAt;
    char        createdAtRelative[MAX_DATELENGTH];
    char        id[MAX_KEYLENGTH * 2 + 2];
    char        title[MAX_DESCRIPTION_LEN];     // ���e���e�{��
    char        content[MAX_DESCRIPTION_LEN];   // ���e�ꏊ (default �� location �Ɠ����l)
    char        icon[MAX_URLLENGTH];
    char        url[MAX_URLLENGTH];
    long        comments;                       // �t����ꂽ�R�����g��
    char        location[MAX_DESCRIPTION_LEN];  // ���Z�n

    JAIKU_USER  user;

    // for logging
    char        orig_text[MAX_DESCRIPTION_LEN];
}   JAIKU_STATUS;


class CJaiku : public CService
{
public:
    CJaiku();
    ~CJaiku();

    void    DeleteReserved(TWITTER_STATUS *sp);
    void    DeleteReserved2(TWITTER_STATUS *sp);

    CString m_apiKey;   // Jaiku personal_key

    // �����𓊍e
    bool    PostUpdate( CString monologue, ProceedingDialog *pdlg )
    {
        return ( PostPresence( monologue, pdlg ) );
    }
    bool    PostPresence( CString monologue, ProceedingDialog *pdlg );

    // friend_timeline (Overview����) ���擾
    CString GetFriendsTimeline( CTwitterTimeline *timeline,
                                ProceedingDialog *pdlg );

    // public_timeline ���擾
    CString GetPublicTimeline( CTwitterTimeline *timeline,
                               ProceedingDialog *pdlg );

    // user_timeline ���擾
    CString GetUserTimeline( CTwitterTimeline *timeline,
                             ProceedingDialog *pdlg );

    // �w�胆�[�U�̍ŐV�̔������擾
    JAIKU_USER      ShowUser( const char *userID );

    // �����̃X�N���[�����̎擾
    CString         GetScreenName();

    // OAuth �A�N�Z�X�g�[�N���̎擾
    bool    GetAccessToken( const char *consumerKey,
                            const char *consumerSecret,
                            CString    &oauthToken,
                            CString    &oauthTokenSecret );

private:
    void    Jaiku2Twitter( TWITTER_STATUS &ts, JAIKU_STATUS js );
    void    Jaiku2Twitter( TWITTER_USER &tu, JAIKU_USER ju );

    void    Twitter2Jaiku( JAIKU_STATUS *js, TWITTER_STATUS *ts,
                           long numOfStats );
    void    Twitter2Jaiku( JAIKU_USER *ju, TWITTER_USER *tu );

    JAIKU_USER      GetUserFromJSON( const char *p,
                                     const char *terminator );
    char            *GetTitleFromJSON( const char *q,
                                       const char *terminator,
                                       char       *origString /* = NULL */ );
#ifdef  JAIKU_LEGACY_TIMELINE
    int             GetIdFromJSON( const char *q,
                                   const char *terminator,
                                    int        &presence );
#else
    char            *GetIdFromJSON( const char *q,
                                    const char *terminator,
                                    char       *presence );
#endif

    CString         GetJaikuPresenceFromJSON(
                            const char    *p,
                            TIMELINE_TYPE t = FRIENDS_TIMELINE
                        );

    void            SetJaikuPresenceFromJSON(
                            const char   *q,
                            const char   *s,
                            JAIKU_STATUS *sp,
                            CString      &message );
    void            MakeMessageForScreen(
                            CString        &message,
                            TWITTER_STATUS *sp );
    void            MakeMessageForLogging(
                            TWITTER_STATUS *sp );

    CString         GetTimeline(
                            CString          &messages,
                            JAIKU_STATUS     **stat,
                            long             &numOfStats,
                            TIMELINE_TYPE    timelineType,
                            const char       *endPointURL,
                            CTwitterTimeline *timeline,
                            ProceedingDialog *pdlg );

protected:
    JAIKU_STATUS    *m_stat;    // friends_timeline
    JAIKU_STATUS    *m_stat2;   // public_timeline
    JAIKU_STATUS    *m_stat3;   // user_timeline

    CString GetTimeline( CString          &messages,
                         TWITTER_STATUS   **stat,
                         long             &numOfStats,
                         TIMELINE_TYPE    t,
                         const char       *endPointURL,
                         CTwitterTimeline *timeline,
                         ProceedingDialog *pdlg );
    CString GetStatusID( const char *p,
                         const char *terminator );
    void    SetStatFromJSON( const char     *p,
                             const char     *s,
                             TWITTER_STATUS *sp,
                             CString        &message );
    char    *CutWhiteSpaces( char *p );

private:
    // OAuth ���N�G�X�g�g�[�N���̎擾
    bool    GetRequestToken( const char *consumerKey,
                             const char *consumerSecret,
                             CString    &oauthToken,
                             CString    &oauthTokenSecret );

    bool    GetToken( const char *response,
                      CString    &oauthToken,
                      CString    &oauthTokenSecret );

    void    MakeOAuthBase( const char *url,
                           const char *method,
                           char       *key,
                           char       *base,
                           char       *param );
    void    MakeOAuthRequest( const char *url,
                              const char *method,
                              char       *request,
                              char       *key,
                              char       *base,
                              char       *param );

    bool    CheckOAuthResult( const char *response );

private:
    CJaiku( CJaiku &obj );
    CJaiku  operator = ( CJaiku &obj );
};


#endif  /* __TWITTER_H__ */