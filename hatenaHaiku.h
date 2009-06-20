/*
 * hatenaHaiku.h  : �͂Ăȃn�C�N �N���C�A���g chirrup
 *      �͂Ăȃn�C�N API �𗘗p���邽�߂̊e�폈���Q �w�b�_�t�@�C��
 *          written by H.Tsujimura  22 Aug 2008
 *
 *      Copyright (c) 2008 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/hatenaHaiku.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 4     08/09/02 18:38 Tsujimura543
 * ����̏C���ɔ����^�C�����C���\���֘A�̓���m�F�A�I���
 * 
 * 3     08/09/02 18:28 Tsujimura543
 * �擾����(JSON)�� whitespace ���g���Đ��`���ꂽ���̂ɕύX���ꂽ
 * �֌W�Ń^�C�����C�����o�����܂������Ȃ��Ȃ��Ă��܂������߁A
 * CutWhiteSpaces() ��ǉ����邱�ƂőΏ�����
 * 
 * 2     08/08/22 19:55 Tsujimura543
 * ����m�F�I��
 * 
 * 1     08/08/22 18:42 Tsujimura543
 * �V�K�쐬
 */

#ifndef __HATENA_HAIKU_H__
#define __HATENA_HAIKU_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CService.h"

class CHatenaHaiku : public CService
{
public:
    CHatenaHaiku();
    ~CHatenaHaiku();

    void    DeleteReserved(TWITTER_STATUS *sp);
    void    DeleteReserved2(TWITTER_STATUS *sp);

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
    CString GetIdFromJSON( const char *p,
                           const char *terminator );

    char    *GetSource( const char *q, const char *s, char *sourceURL );
    char    *CutWhiteSpaces( char *p );

private:
    CHatenaHaiku( CHatenaHaiku &obj );
    CHatenaHaiku  operator = ( CHatenaHaiku &obj );
};

#endif  /* __HATENA_HAIKU_H__ */