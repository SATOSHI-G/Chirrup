/*
 * CManager.h   : Twitter �N���C�A���g chirrup
 *      CManager �N���X�̐錾����уC���^�[�t�F�C�X�̒�`
 *          written by H.Tsujimura  19 Jun 2007
 *
 *      Copyright (c) 2007 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/CManager.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 12    09/05/12 17:16 Tsujimura543
 * �u�X���b�h�N�������v���e�^�C�����C���擾�������Ăяo���^�C�~���O��
 * �㏑������悤�ɕύX (�T�[�r�X���� �� �^�C�����C������ �ɕύX)
 * 
 * 11    09/04/16 16:11 Tsujimura543
 * �V�K�C���X�g�[������ OAuth �F�ؐݒ肵�����ƁA�X�N���[�����̎擾�Ɏ��s
 * ���铙�AOAuth �Ή����ɍ�肱��ł��܂����o�O���C��
 * 
 * 10    09/03/31 21:27 Tsujimura543
 * Twitter �� OAuth �Ή����� ����5
 * 
 * 9     09/03/30 22:19 Tsujimura543
 * Twitter �� OAuth �Ή�����
 * 
 * 8     08/07/16 4:13 Tsujimura543
 * �u�������e�Ώہv�̐ݒ���u�ݒ�v�_�C�A���O�ł��ݒ�ł���悤�ɂ���
 * 
 * 7     07/09/06 19:42 Tsujimura543
 * �_�~�[�̃R�s�[�R���X�g���N�^�A������Z�q�� private �Ƃ��ē����B
 * �m��Ȃ������Ƀ������m��(�Ɖ�����Y��)����������\����r���B
 * 
 * 6     07/08/28 1:56 Tsujimura543
 * �������e�Ώۂɂ���T�[�r�X��I���ł���悤�ɂ���
 * 
 * 5     07/08/25 0:45 Tsujimura543
 * �u�������v�ɑΉ� (�\��)
 * 
 * 4     07/06/20 15:46 Tsujimura543
 * InitTimelineInfo() ��p�~
 * 
 * 3     07/06/20 5:16 Tsujimura543
 * CheckKeys() �Ɉ�����ǉ�
 * 
 * 2     07/06/20 3:16 Tsujimura543
 * �ݒ�t�@�C���̓ǂݏ��������� chirrupDlg ���� CManager ��
 * CJaikuManager �Ɉڂ���
 * 
 * 1     07/06/19 21:16 Tsujimura543
 * ���܂� CChirrupDlg ���ł���Ă����e�T�[�r�X���Ǘ��A���䂷�鏈����
 * ���o�� CManager �Ƃ��ēƗ�������
 */

#ifndef __C_MANAGER_H__
#define __C_MANAGER_H__

#include "twitterTimeline.h"

class CManager  {
public:
    CManager();
    CManager( CTwitterTimeline::SVC_TYPE serviceType );

    ~CManager();

    CString             m_serviceName;
    CString             m_serviceSymbol;
    CString             m_screenName;
    CString             m_username;
    CString             m_password;
    CString             m_oauthToken;
    CString             m_oauthTokenSecret;
    bool                m_useOAuth;
    bool                m_useBASIC;
    bool                m_simultaneousPost;

    TIMELINE_INFO       m_sFriendsTimeline;
    TIMELINE_INFO       m_sPublicTimeline;
    TIMELINE_INFO       m_sUserTimeline;

    CTwitterTimeline    m_friendsTimeline;
    CTwitterTimeline    m_publicTimeline;
    CTwitterTimeline    m_userTimeline;

    CService            *m_service;

    void    SetConfig( CString username,
                       CString password,
                       BOOL checkMultiPost,
                       TIMELINE_INFO sFriendsTimeline,
                       TIMELINE_INFO sPublicTimeline,
                       TIMELINE_INFO sUserTimeline );
    void    GetConfig( CString &username,
                       CString &password,
                       BOOL &checkMultiPost,
                       TIMELINE_INFO &sFriendsTimeline,
                       TIMELINE_INFO &sPublicTimeline,
                       TIMELINE_INFO &sUserTimeline );

    void    ExecuteUpdate( CStatic          *sp,
                           bool             useTwitStar,
                           CChirrupDlg      *cdlg,
                           ProceedingDialog *pdlg );
    bool    ExecutePost( CString          monologue,
                         CStatic          *sp,
                         ProceedingDialog *pdlg );
    void    GetScreenName();
    void    SetUpUserInfo();

    void    SetLogFileSpec();

    void    WriteKeys( FILE          *fp,
                       char          *key,
                       unsigned char **secret,
                       bool          &done );
    void    WriteKeys( FILE                *fp,
                       const TIMELINE_INFO *t,
                       const char          *timelineType );

    bool    CheckKeys( const char          *p,
                       const unsigned char *rsaString,
                       char                *encrypted,
                       bool                &ret );
    bool    EvalKeys( const char          *p,
                      const unsigned char *rsaString,
                      char                *encrypted );
    bool    EvalKeys( TIMELINE_INFO *t,
                      const char    *timelineType,
                      const char    *p );

    CTwitterTimeline    *GetFriendsTimeline()
    {
        return ( &m_friendsTimeline );
    }

    CTwitterTimeline    *GetPublicTimeline()
    {
        return ( &m_publicTimeline );
    }

    CTwitterTimeline    *GetUserTimeline()
    {
        return ( &m_userTimeline );
    }

private:
    CManager( CManager &obj );
    CManager    operator = ( CManager &obj );
};

#endif  /* __C_MANAGER_H__ */
