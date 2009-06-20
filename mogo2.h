/*
 * mogo2.h  : �������� �N���C�A���g chirrup
 *      �������� API �𗘗p���邽�߂̊e�폈���Q �w�b�_�t�@�C��
 *          written by H.Tsujimura  14 Jun 2007
 *
 *      Copyright (c) 2007 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/mogo2.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 12    07/09/06 19:42 Tsujimura543
 * �_�~�[�̃R�s�[�R���X�g���N�^�A������Z�q�� private �Ƃ��ē����B
 * �m��Ȃ������Ƀ������m��(�Ɖ�����Y��)����������\����r���B
 * 
 * 11    07/07/05 0:50 Tsujimura543
 * (1) GetStatFromJSON(), GetUserTimeline() �̈�����ύX
 * (2) TWITTER_USER �\���̂̕ύX(orig_userName��ǉ�)�ɔ����C��
 * (3) MakeMessageForScreen() �� MakeMessageForLogging() ��p��
 * 
 * 10    07/06/25 18:03 Tsujimura543
 * DeleteReserved(), DeleteReserved2() �֘A�A�R�[�h�𐮗�
 * 
 * 9     07/06/25 17:40 Tsujimura543
 * DeleteReserved(), DeleteReserved2() ��ǉ�
 * 
 * 8     07/06/21 19:15 Tsujimura543
 * SetUserAgent() �� CService ���̃��\�b�h�Ɉ�{������
 * 
 * 7     07/06/20 19:28 Tsujimura543
 * GetStatusID() �𓱓�
 * 
 * 6     07/06/19 23:01 Tsujimura543
 * CService �𓱓����A�\�[�X�R�[�h�𐮗�����
 * 
 * 5     07/06/19 17:39 Tsujimura543
 * GetMogo2ScreenName() �� GetScreenName() �ɕύX
 * 
 * 4     07/06/18 18:51 Tsujimura543
 * �f�t�H���g�A�C�R���̒�`�� defaultImage.h �Ɉڂ�
 * 
 * 3     07/06/15 23:53 Tsujimura543
 * MOGO2_DEFAULT_IMAGE �̒�`��ύX
 * 
 * 2     07/06/15 19:15 Tsujimura543
 * friends_timeline �΍�A�ǉ�
 * 
 * 1     07/06/14 23:00 Tsujimura543
 * �V�K�쐬 (����m�F�ς�)
 */

#ifndef __MOGO2_H__
#define __MOGO2_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CService.h"

class CMogo2 : public CService
{
public:
    CMogo2();
    ~CMogo2();

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

private:
    CMogo2( CMogo2 &obj );
    CMogo2  operator = ( CMogo2 &obj );
};

#endif  /* __MOGO2_H__ */