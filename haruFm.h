/*
 * haruFm.h  : Haru.fm �N���C�A���g chirrup
 *      Haru.fm API �𗘗p���邽�߂̊e�폈���Q �w�b�_�t�@�C��
 *          written by H.Tsujimura  27 Jun 2007
 *
 *      Copyright (c) 2007 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/haruFm.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 7     07/09/06 19:42 Tsujimura543
 * �_�~�[�̃R�s�[�R���X�g���N�^�A������Z�q�� private �Ƃ��ē����B
 * �m��Ȃ������Ƀ������m��(�Ɖ�����Y��)����������\����r���B
 * 
 * 6     07/07/05 22:30 Tsujimura543
 * Haru.fm �̃R�����g�c���[�̍X�V�ɑΉ�
 * 
 * 5     07/07/05 0:49 Tsujimura543
 * (1) GetStatFromJSON(), GetUserTimeline() �̈�����ύX
 * (2) TWITTER_USER �\���̂̕ύX(orig_userName��ǉ�)�ɔ����C��
 * 
 * 4     07/07/04 18:01 Tsujimura543
 * MakeMessageForScreen() �� MakeMessageForLogging() ��p��
 * 
 * 3     07/07/03 17:45 Tsujimura543
 * �^�O�̕\���ɑΉ�
 * 
 * 2     07/07/03 14:53 Tsujimura543
 * haru.fm �Ή� (����m�F�ς�)
 * 
 * 1     07/06/27 18:13 Tsujimura543
 * �V�K�쐬 (�b���)
 */

#ifndef __HARU_FM_H__
#define __HARU_FM_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CService.h"

// �R�����g
typedef struct haruFmComment    {
    CTime   createdAt;
    char    id[MAX_KEYLENGTH * 2 + 2];
    char    text[MAX_DESCRIPTION_LEN];

    // user
    char    userID[MAX_KEYLENGTH];
    char    userName[MAX_KEYLENGTH];

    // for logging
    char    orig_text[MAX_DESCRIPTION_LEN * 2];
    char    orig_userName[MAX_KEYLENGTH * 2];

    haruFmComment()
    {
        createdAt        = CTime::GetCurrentTime();
        id[0]            = NUL;
        text[0]          = NUL;
        userID[0]        = NUL;
        userName[0]      = NUL;
        orig_text[0]     = NUL;
        orig_userName[0] = NUL;
    }
}   HARUFM_COMMENT;

typedef struct haruFmCommentList    {
    long            preCommentCount;
    long            commentCount;
    HARUFM_COMMENT  *comment;

    haruFmCommentList()
    {
        preCommentCount = -1;
        commentCount    = 0;
        comment         = NULL;
    }
}   HARUFM_COMMENT_LIST;


// �^�O
typedef struct haruFmTags   {
    char    id[MAX_KEYLENGTH + 1];
    char    tag[MAX_KEYLENGTH + 1];
    char    orig_tag[MAX_KEYLENGTH * 2 + 2];

    haruFmTags()
    {
        id[0]       = NUL;
        tag[0]      = NUL;
        orig_tag[0] = NUL;
    }
}   HARUFM_TAGS;

typedef struct haruFmTagList    {
    long        numOfTags;
    HARUFM_TAGS *tag;

    haruFmTagList()
    {
        numOfTags = 0;
        tag       = NULL;
    }
}   HARUFM_TAG_LIST;


class CHaruFm : public CService
{
public:
    CHaruFm();
    ~CHaruFm();

    void    DeleteReserved(TWITTER_STATUS *sp);
    void    DeleteReserved2(TWITTER_STATUS *sp);

    // ���[�UID
    CString m_loginID;

    // �����𓊍e
    bool    PostUpdate( CString monologue, ProceedingDialog *pdlg );

    // friend_timeline ���擾
    CString GetFriendsTimeline( CTwitterTimeline *timeline,
                                ProceedingDialog *pdlg );

    // public_timeline ���擾
    CString GetPublicTimeline( CTwitterTimeline *timeline,
                               ProceedingDialog *pdlg );

    // user_timeline ���擾
    CString GetUserTimeline( CTwitterTimeline *timeline,
                             ProceedingDialog *pdlg );

    // �����̃X�N���[�����̎擾
    CString GetScreenName();

    // ������ ID �̎擾
    CString GetLoginID();

    bool    OverwriteStatFromJSON(
                const char     *p,
                const char     *s,
                TWITTER_STATUS *sp,
                CString        &message );

protected:
    CString GetTimeline( CString          &messages,
                         TWITTER_STATUS   **stat,
                         long             &numOfStats,
                         TIMELINE_TYPE    t,
                         const char       *endPointURL,
                         CTwitterTimeline *timeline,
                         ProceedingDialog *pdlg );
    CString GetStatusID( const char *p,
                         const char *terminator );

    void            SetStatFromJSON(
                            const char     *p,
                            const char     *s,
                            TWITTER_STATUS *sp,
                            CString        &message );
    void            MakeMessageForScreen(
                            CString        &message,
                            TWITTER_STATUS *sp );
    void            MakeMessageForLogging(
                            TWITTER_STATUS *sp );

    TWITTER_USER    GetUserFromJSON( const char *p,
                                     const char *terminator );

    CTime   GetCreatedAtFromJSON( const char *q, const char *terminator );

    TWITTER_USER    GetUserFromXML( const char *p, const char *terminator );

private:
    char    *GetContentFromJSON(
                    const char *q,
                    const char *terminator,
                    char       *origString /* = NULL */
                );

    HARUFM_COMMENT_LIST *GetCommentsFromJSON(
                            const char *p,
                            const char *terminator,
                            long       commentCount,
                            long       preCommentCount
                        );

    HARUFM_TAG_LIST     *GetTagsFromJSON(
                            const char *p,
                            const char *terminator
                        );

private:
    CHaruFm( CHaruFm &obj );
    CHaruFm operator = ( CHaruFm &obj );
};

#endif  /* __HARU_FM_H__ */
