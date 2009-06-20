/*
 * CService.h   : Twitter �N���C�A���g chirrup
 *      �e�T�[�r�X�� API �𗘗p���邽�߂̊e�폈���Q �w�b�_�t�@�C��
 *          written by H.Tsujimura  4 Apr 2007 / 28 Apr 2007 / 19 Jun 2007
 *
 *      Copyright (c) 2007, 2008 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/CService.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 26    09/03/31 23:29 Tsujimura543
 * Twitter �� OAuth �Ή����� ����7
 * 
 * 25    09/03/30 22:19 Tsujimura543
 * Twitter �� OAuth �Ή�����
 * 
 * 24    09/03/10 22:14 Tsujimura543
 * GetStringFromJSON() �Ƀo�b�t�@�I�[�o�[�����΍�����{
 * 
 * 23    09/03/03 1:30 Tsujimura543
 * �W�J�Ώۂ̒Z�kURL�𑝂₵�Ă݂�
 * 
 * 22    08/02/07 22:36 Tsujimura543
 * copyright �\�����C�� (2008 ��ǉ�)
 * 
 * 21    08/01/11 19:53 Tsujimura543
 * ExpandPheedo() ��ǉ�
 * 
 * 20    07/12/26 21:32 Tsujimura543
 * ���t�@�N�^�����O�����{
 * 
 * 19    07/12/26 20:10 Tsujimura543
 * z.la �ň��k����Ă��� URL �̓W�J������ǉ�
 * 
 * 18    07/12/19 18:41 Tsujimura543
 * http�֘A�̊֐��Q�� http.h �ɕ���
 * 
 * 17    07/12/19 17:17 Tsujimura543
 * _http_postBASIC() �̈�����ǉ�
 * 
 * 16    07/12/19 16:56 Tsujimura543
 * _http_getBASIC() �̈�����ǉ�
 * 
 * 15    07/08/25 0:45 Tsujimura543
 * �u�������v�ɑΉ� (�\��)
 * 
 * 14    07/07/23 14:55 Tsujimura543
 * TWITTER_STATUS �\���̂� source �� sourceURL ��ǉ�
 * 
 * 13    07/07/17 18:41 Tsujimura543
 * GetTinyURL() ��ǉ�
 * 
 * 12    07/07/05 0:46 Tsujimura543
 * (1) GetStatFromJSON(), GetUserTimeline() �̈�����ύX
 * (2) TWITTER_USER �\���̂̕ύX(orig_userName��ǉ�)�ɔ����C��
 * 
 * 11    07/07/03 14:53 Tsujimura543
 * haru.fm �Ή� (����m�F�ς�)
 * 
 * 10    07/06/25 21:09 Tsujimura543
 * twitterStatus �̃R�s�[�R���X�g���N�^��ǉ�
 * 
 * 9     07/06/25 18:21 Tsujimura543
 * DeleteReserved(), DeleteReserved2() �֘A�A�R�[�h�𐮗�
 * 
 * 8     07/06/25 17:40 Tsujimura543
 * DeleteReserved(), DeleteReserved2() ��ǉ�
 * 
 * 7     07/06/22 17:45 Tsujimura543
 * TWITTER_STATUS �� reserved ��ǉ�
 * (���܂̂Ƃ���ATimelog �݂̂Ŏg�p)
 * 
 * 6     07/06/21 19:15 Tsujimura543
 * SetUserAgent() �� CService ���̃��\�b�h�Ɉ�{������
 * 
 * 5     07/06/21 13:33 Tsujimura543
 * status ID �i�[�̈�T�C�Y������ɑ��₷
 * 
 * 4     07/06/20 19:28 Tsujimura543
 * GetStatusID() �𓱓�
 * 
 * 3     07/06/20 15:44 Tsujimura543
 * status ID �̊i�[�̈�T�C�Y�𑝂₵�� [Timelog �Ή��̂���]
 * (Timelog �� ID �͑��T�[�r�X�� ID ��蒷��)
 * 
 * 2     07/06/19 22:50 Tsujimura543
 * ����ɋ��ʉ��\�ȕ����� CService �Ɉڂ���
 * 
 * 1     07/06/19 21:19 Tsujimura543
 * ���܂� CTwitter ���ł���Ă��� API �̌Ăяo���A���s���ʂ̉�͏����̂�
 * ���A Twitter �ȊO�̃T�[�r�X�Ƌ��ʉ��ł��镔���� CService �Ƃ��ēƗ���
 * ����
 */

#ifndef __C_SERVICE_H__
#define __C_SERVICE_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxwin.h>         // MFC �̃R�A����ѕW���R���|�[�l���g
#include "resource.h"		// ���C�� �V���{��
#include "ProceedingDialog.h"
#include "defaultImage.h"
extern "C" {
#include "xmlRPC.h"
#include "encryptRSA.h"
}

#define MAX_NUMOFSTATUS     128 /* �b��l */
#define MAX_NUMOFFRIENDS    20  /* �_�C�A���O�ŉ��i�ɕ\������ friends �̐� */
#define ID_UPDATE_TWITTER   0xDEADBEAF
#define MS_UPDATE_TWITTER   (60 * 1000) // �f�t�H���g�̍X�V����
#define MAX_NUM_OF_DIRECTMESSAGES   20

typedef struct twitterUser  {
    char    id[MAX_KEYLENGTH];
    char    name[MAX_KEYLENGTH];
    char    screenName[MAX_KEYLENGTH];
    char    location[MAX_LOGICALLINELEN];
    char    description[MAX_DESCRIPTION_LEN];
    char    profileImageURL[MAX_URLLENGTH];
    char    url[MAX_URLLENGTH];
    char    lastStatus[MAX_DESCRIPTION_LEN];
    HBITMAP bitmap;

    // for logging
    char    orig_userName[MAX_KEYLENGTH * 2];

    twitterUser()
    {
        id[0]              = NUL;
        name[0]            = NUL;
        screenName[0]      = NUL;
        location[0]        = NUL;
        description[0]     = NUL;
        profileImageURL[0] = NUL;
        url[0]             = NUL;
        lastStatus[0]      = NUL;
        bitmap             = NULL;
        orig_userName[0]   = NUL;
    }
}   TWITTER_USER;

typedef struct twitterStatus    {
    CTime   createdAt;
    char    id[MAX_KEYLENGTH * 2 + 2];
    char    text[MAX_DESCRIPTION_LEN];
    char    source[MAX_KEYLENGTH];     /* {@@} */
    char    sourceURL[MAX_URLLENGTH];  /* {@@} */

    TWITTER_USER    user;

    // for logging
    char    orig_text[MAX_DESCRIPTION_LEN * 2];

    // �e�T�[�r�X�̓Ǝ��g���Ή��p
    void    *reserved;
    void    *reserved2;

    twitterStatus()
    {
        createdAt    = CTime::GetCurrentTime();
        id[0]        = NUL;
        text[0]      = NUL;
        orig_text[0] = NUL;
        source[0]    = NUL;
        sourceURL[0] = NUL;

        memset( &user, 0x00, sizeof ( TWITTER_USER ) );
        reserved  = NULL;
        reserved2 = NULL;
    }

    twitterStatus operator= ( twitterStatus t )
    {
        createdAt = t.createdAt;
        strcpy( id, t.id );
        strcpy( text, t.text );
        strcpy( source, t.source );
        strcpy( sourceURL, t.sourceURL );

        user = t.user;

        strcpy( orig_text, t.orig_text );

        reserved  = t.reserved;
        reserved2 = t.reserved2;

        return ( *this );
    }
}   TWITTER_STATUS;

typedef struct twitterLogging   {
    time_t  createdAt;
    int     createdAt_yyyy;
    int     createdAt_mm;
    int     createdAt_dd;
    int     createdAt_HH;
    int     createdAt_MM;
    int     createdAt_SS;

    char    orig_text[MAX_DESCRIPTION_LEN * 2];
    char    orig_userName[MAX_KEYLENGTH * 2];
}   TWITTER_LOG;

typedef struct  twitterDirectMessage    {
    CTime   createdAt;
    char    id[MAX_KEYLENGTH * 2 + 2];
    char    text[MAX_DESCRIPTION_LEN];

    TWITTER_USER    sender;
    TWITTER_USER    recipient;

    bool    deleted;
}   TWITTER_DIRECT_MESSAGE;

class CTwitterTimeline;

class CService
{
public:
    CService();
    ~CService();

    typedef enum timelineType   {
        FRIENDS_TIMELINE = 1,
        PUBLIC_TIMELINE,
        USER_TIMELINE,
        REPLIES
    }   TIMELINE_TYPE;

    bool    m_useOAuth;
    CString m_username;     // ID �܂��� ���[���A�h���X
    CString m_password;     // �p�X���[�h �܂��� API �L�[
    CString m_oauthToken;       // OAuth �A�N�Z�X�g�[�N��
    CString m_oauthTokenSecret; // OAuth �����p�閧��
    CString m_screenName;   // �X�N���[���� (�܂��� ���[�U��)
#ifdef  _DEBUG
    CString m_serviceName;
#endif
    CString m_serviceSymbol;

    // ��n��
    virtual void    DeleteReserved( TWITTER_STATUS *sp )  = 0;
    virtual void    DeleteReserved2( TWITTER_STATUS *sp ) = 0;

    // User-Agent ��ݒ�
    void    SetUserAgent();

    // �����𓊍e
    virtual bool    PostUpdate( CString          monologue,
                                ProceedingDialog *pdlg ) = 0;

    // friends_timeline ���擾
    virtual CString GetFriendsTimeline(
                                CTwitterTimeline *timeline,
                                ProceedingDialog *pdlg ) = 0;
    CString GetFriendsTimeline( const char       *endPointURL,
                                CTwitterTimeline *timeline,
                                ProceedingDialog *pdlg );

    // public_timeline ���擾
    virtual CString GetPublicTimeline(
                                CTwitterTimeline *timeline,
                                ProceedingDialog *pdlg ) = 0;
    CString GetPublicTimeline(  const char       *endPointURL,
                                CTwitterTimeline *timeline,
                                ProceedingDialog *pdlg );

    // user_timeline ���擾
    virtual CString GetUserTimeline(
                                CTwitterTimeline *timeline,
                                ProceedingDialog *pdlg ) = 0;
    CString GetUserTimeline(    const char       *endPointURL,
                                CTwitterTimeline *timeline,
                                ProceedingDialog *pdlg );

    // �����̃X�N���[�����̎擾
    virtual CString GetScreenName() = 0;

    // for logging
    void            WriteLog( CTwitterTimeline *timeline );
    long            m_numOfLogs;
    TWITTER_LOG     *m_log;

    // for ������
    bool            m_useTwitStar;

protected:
    // timeline ���擾
    virtual CString GetTimeline( CString          &messages,
                                 TWITTER_STATUS   **sp,
                                 long             &numOfStats,
                                 TIMELINE_TYPE    t,
                                 const char       *endPointURL,
                                 CTwitterTimeline *timeline,
                                 ProceedingDialog *pdlg )  = 0;
    virtual CString GetStatusID( const char *p,
                                 const char *terminator ) = 0;

    CString         GetStatFromJSON(
                            const char     *p,
                            TWITTER_STATUS **sp,
                            long           &numOfStats );
    virtual void    SetStatFromJSON(
                            const char     *p,
                            const char     *s,
                            TWITTER_STATUS *sp,
                            CString        &message ) = 0;
    virtual void    MakeMessageForScreen(
                            CString        &message,
                            TWITTER_STATUS *sp ) = 0;
    virtual void    MakeMessageForLogging(
                            TWITTER_STATUS *sp ) = 0;

    CString         EscapeQuote( const char *p );
    char            *ExpandTinyURL( char *str );
    char            *ExpandZla( char *str );
    char            *ExpandPheedo( char *str );
    char            *ExpandURL( char *str );
    char            *ExtractURL( char       *str,
                                 size_t     offset,
                                 const char *response,
                                 const char *delimiter ); 

    char            *GetTinyURL( const char *targetURL,
                                 char       *request,
                                 char       *response,
                                 size_t     sz );
    char            *GetTinyURL( char *str );

    char            *GetStringFromJSON( char       *result,
                                        size_t     result_len,
                                        const char *name,
                                        const char *p,
                                        const char *terminator,
                                        bool       raw = false,
                                        char       *origString = NULL );
    int             GetIntegerFromJSON( const char *name,
                                        const char *p,
                                        const char *terminator );
    CTime           GetCreatedAtFromJSON( const char *p,
                                          const char *terminator );
    char            *GetIdFromJSON( const char *p,
                                    const char *terminator );
    char            *GetTextFromJSON( const char *p,
                                      const char *terminator,
                                      char       *origString = NULL );
    TWITTER_USER    GetUserFromJSON( const char *p,
                                     const char *terminator );

    CTime           GetTimeFromXML( const char *p, const char *name );
    TWITTER_USER    GetUserFromXML( const char *p, const char *terminator );
    CString         GetStringFromXML( const char *p,
                                      const char *name,
                                      const char *terminator );
    CString         GetStringFromXML( const char *p,
                                      const char *name,
                                      const char *param,
                                      const char *terminator );

    // �ŋ߂̔����̃��X�g (�ő� MAX_NUMOFSTATUS ��)
	CString	        m_messages;     // friends_timeline
    long            m_numOfStats;
    TWITTER_STATUS  *m_stat;

	CString	        m_messages2;    // public_timeline
    long            m_numOfStats2;
    TWITTER_STATUS  *m_stat2;

	CString	        m_messages3;    // user_timeline
    long            m_numOfStats3;
    TWITTER_STATUS  *m_stat3;
};

#endif  /* __C_SERVICE_H__ */
