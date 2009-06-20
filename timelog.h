/*
 * timelog.h : Timelog �N���C�A���g chirrup
 *      Timelog API �𗘗p���邽�߂̊e�폈���Q �w�b�_�t�@�C��
 *          written by H.Tsujimura  20 Jun 2007
 *
 *      Copyright (c) 2007, 2008 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/timelog.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 14    08/07/16 15:27 Tsujimura543
 * Timelog �́u�]���v�ɑΉ�����
 * 
 * 13    08/02/08 23:15 Tsujimura543
 * �R�s�[���C�g�\�����X�V
 * 
 * 12    08/02/08 23:14 Tsujimura543
 * tag �̍ő啶���񒷂��C�� (����tag�o�����ɗ̈�j�󂪔����A�����Ă���)
 * 
 * 11    07/09/06 19:42 Tsujimura543
 * �_�~�[�̃R�s�[�R���X�g���N�^�A������Z�q�� private �Ƃ��ē����B
 * �m��Ȃ������Ƀ������m��(�Ɖ�����Y��)����������\����r���B
 * 
 * 10    07/07/19 21:23 Tsujimura543
 * �^�O�������Ɨ����Ă��܂��s��ɑΏ����邽�߁A�^�O�i�[�p��
 * �̈�𑝂₵�Ă݂�
 * 
 * 9     07/07/05 0:50 Tsujimura543
 * (1) GetStatFromJSON(), GetUserTimeline() �̈�����ύX
 * (2) TWITTER_USER �\���̂̕ύX(orig_userName��ǉ�)�ɔ����C��
 * (3) MakeMessageForScreen() �� MakeMessageForLogging() ��p��
 * 
 * 8     07/06/25 18:47 Tsujimura543
 * tag ��\������悤�ɂ��Ă݂�
 * 
 * 7     07/06/25 18:09 Tsujimura543
 * DeleteReserved(), DeleteReserved2() ��ǉ�
 * 
 * 6     07/06/22 18:00 Tsujimura543
 * �u�����v�{�������Ɂu> �R�����g�惆�[�U���v��t������悤�ɂ���
 * 
 * 5     07/06/21 22:05 Tsujimura543
 * �_�C���N�g���b�Z�[�W�̑���M���������� (�폜�͖�����)
 * 
 * 4     07/06/21 19:15 Tsujimura543
 * SetUserAgent() �� CService ���̃��\�b�h�Ɉ�{������
 * 
 * 3     07/06/20 19:28 Tsujimura543
 * GetStatusID() �𓱓�
 * 
 * 2     07/06/20 17:05 Tsujimura543
 * timeline �̎擾�� status �̓��e�Ɋւ��āA���삷�邱�Ƃ��m�F
 * 
 * 1     07/06/20 14:06 Tsujimura543
 * �V�K�쐬 (�b���)
 */

#ifndef __TIMELOG_H__
#define __TIMELOG_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CService.h"

// �^�O
typedef struct timelogTags   {
    char    tag[MAX_LOGICALLINELEN * 2 + 1];
    char    orig_tag[MAX_LOGICALLINELEN * 4 + 2];

    timelogTags()
    {
        tag[0]      = NUL;
        orig_tag[0] = NUL;
    }
}   TIMELOG_TAGS;


class CTimelog : public CService
{
public:
    CTimelog();
    ~CTimelog();

    void    DeleteReserved(TWITTER_STATUS *sp);
    void    DeleteReserved2(TWITTER_STATUS *sp);

    // �_�C���N�g���b�Z�[�W (�ŐV�� MAX_NUM_OF_DIRECTMESSAGES ��)
    TWITTER_DIRECT_MESSAGE  *m_dm;
    int                     m_numOfMessages;

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

    // �_�C���N�g���b�Z�[�W����M
    TWITTER_DIRECT_MESSAGE  *RecvDirectMessages( int &numOfMessages,
                                                 ProceedingDialog *pdlg );

    // �_�C���N�g���b�Z�[�W�𑗐M
    bool    SendDirectMessage( CString userID, CString message );

    // �_�C���N�g���b�Z�[�W���폜
    bool    DeleteDirectMessage( const char *messageID );

    // �w�� status �� favorites �ɂ��� (�u�]���v������)
    bool    SetFavorite( const char *statusID );

    // �����̃X�N���[�����̎擾
    CString GetScreenName();

    CString GetIdFromJSON( const char *p,
                           const char *terminator );

protected:
    // timeline ���擾
    CString GetTimeline(
                    CString          &messages,
                    TWITTER_STATUS   **stat,
                    long             &numOfStats,
                    TIMELINE_TYPE    t,
                    const char       *endPointURL,
                    CTwitterTimeline *timeline,
                    ProceedingDialog *pdlg );
    CString GetStatusID( const char *p, const char *terminator );

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

    CTime           GetCreatedAtFromJSON(
                                      const char *p,
                                      const char *terminator );
    TWITTER_USER    GetUserFromJSON(  const char *p,
                                      const char *terminator );
    TWITTER_USER    *GetRecipientUserFromJSON(
                                      const char *p,
                                      const char *terminator );
    TIMELOG_TAGS    *GetTagsFromJSON( const char *p,
                                      const char *terminator );

    char            *GetUserLoginIdFromJSON(
                                      const char *p,
                                      const char *terminator );

    char            *GetTextFromJSON( const char *p,
                                      const char *terminator,
                                      char       *origString /* = NULL */ );

private:
    CTimelog( CTimelog &obj );
    CTimelog    operator = ( CTimelog &obj );
};

#endif  /* __TIMELOG_H__ */