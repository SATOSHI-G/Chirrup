/*
 * CJaikuManager.h   : Twitter �N���C�A���g chirrup
 *      CJaikuManager �N���X�̐錾����уC���^�[�t�F�C�X�̒�`
 *          written by H.Tsujimura  20 Jun 2007
 *
 *      Copyright (c) 2007 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/CJaikuManager.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 5     09/04/15 1:17 Tsujimura543
 * Jaiuku �� OAuth �Ή�����
 * 
 * 4     07/09/06 19:42 Tsujimura543
 * �_�~�[�̃R�s�[�R���X�g���N�^�A������Z�q�� private �Ƃ��ē����B
 * �m��Ȃ������Ƀ������m��(�Ɖ�����Y��)����������\����r���B
 * 
 * 3     07/06/20 5:17 Tsujimura543
 * CheckKeys() �Ɉ�����ǉ�
 * 
 * 2     07/06/20 3:16 Tsujimura543
 * �ݒ�t�@�C���̓ǂݏ��������� chirrupDlg ���� CManager ��
 * CJaikuManager �Ɉڂ���
 * 
 * 1     07/06/20 1:53 Tsujimura543
 * �V�K�쐬 (Jaiku ��p CManager)
 */

#ifndef __C_JAIKU_MANAGER_H__
#define __C_JAIKU_MANAGER_H__

#include "CManager.h"

class CJaikuManager : public CManager
{
public:
    CJaikuManager();
    ~CJaikuManager();

    void    SetConfig( CString username,
                       CString password,
                       CString oauthToken,
                       CString oauthTokenSecret,
                       BOOL useOAuth,
                       BOOL useBASIC,
                       BOOL checkMultiPost,
                       TIMELINE_INFO sFriendsTimeline,
                       TIMELINE_INFO sPublicTimeline,
                       TIMELINE_INFO sUserTimeline );
    void    GetConfig( CString &username,
                       CString &password,
                       CString &oauthToken,
                       CString &oauthTokenSecret,
                       BOOL &useOAuth,
                       BOOL &useBASIC,
                       BOOL &checkMultiPost,
                       TIMELINE_INFO &sFriendsTimeline,
                       TIMELINE_INFO &sPublicTimeline,
                       TIMELINE_INFO &sUserTimeline );

    bool    ExecutePost( CString          monologue,
                         CStatic          *sp,
                         ProceedingDialog *pdlg );
    void    GetScreenName();

    void    WriteKeys( FILE          *fp,
                       char          *key,
                       unsigned char **secret,
                       bool          &done );
    bool    CheckKeys( const char          *p,
                       const unsigned char *rsaString,
                       char                *encrypted,
                       bool                &ret );
    bool    EvalKeys( const char          *p,
                      const unsigned char *rsaString,
                      char                *encrypted );

private:
    CJaikuManager( CJaikuManager &obj );
    CJaikuManager   operator = ( CJaikuManager &obj );
};

#endif  /* __C_JAIKU_MANAGER_H__ */
