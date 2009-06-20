/*
 * CTwitterManager.h : Twitter �N���C�A���g chirrup
 *      CTwitterManager �N���X�̐錾����уC���^�[�t�F�C�X�̒�`
 *          written by H.Tsujimura  20 Jun 2007
 *
 *      Copyright (c) 2007 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/CTwitterManager.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 8     09/05/12 17:16 Tsujimura543
 * �u�X���b�h�N�������v���e�^�C�����C���擾�������Ăяo���^�C�~���O��
 * �㏑������悤�ɕύX (�T�[�r�X���� �� �^�C�����C������ �ɕύX)
 * 
 * 7     09/03/31 21:27 Tsujimura543
 * Twitter �� OAuth �Ή����� ����5
 * 
 * 6     09/03/30 22:37 Tsujimura543
 * Twitter �� OAuth �Ή����� ����2
 * 
 * 5     08/07/16 4:13 Tsujimura543
 * �u�������e�Ώہv�̐ݒ���u�ݒ�v�_�C�A���O�ł��ݒ�ł���悤�ɂ���
 * 
 * 4     07/09/06 19:42 Tsujimura543
 * �_�~�[�̃R�s�[�R���X�g���N�^�A������Z�q�� private �Ƃ��ē����B
 * �m��Ȃ������Ƀ������m��(�Ɖ�����Y��)����������\����r���B
 * 
 * 3     07/08/25 0:45 Tsujimura543
 * �u�������v�ɑΉ� (�\��)
 * 
 * 2     07/08/06 17:31 Tsujimura543
 * Twitter �� API ���s�񐔐����ɒ�G����̂�h���d�g�݂𓱓�
 * 
 * 1     07/06/20 5:17 Tsujimura543
 * �V�K�쐬 (Twitter ��p CManager)
 */

#ifndef __C_TWITTER_MANAGER_H__
#define __C_TWITTER_MANAGER_H__

#include "CManager.h"

class CTwitterManager : public CManager
{
public:
    CTwitterManager();
    ~CTwitterManager();

    TIMELINE_INFO       m_sReplies;
    CTwitterTimeline    m_replies;
    bool                m_twitterHealthy;
    time_t              m_lastUpdated;

    void    SetConfig( CString username,
                       CString password,
                       CString oauthToken,
                       CString oauthTokenSecret,
                       BOOL useOAuth,
                       BOOL useBASIC,
                       BOOL checkMultiPost,
                       TIMELINE_INFO sFriendsTimeline,
                       TIMELINE_INFO sPublicTimeline,
                       TIMELINE_INFO sUserTimeline,
                       TIMELINE_INFO sReplies );
    void    GetConfig( CString &username,
                       CString &password,
                       CString &oauthToken,
                       CString &oauthTokenSecret,
                       BOOL &useOAuth,
                       BOOL &useBASIC,
                       BOOL &checkMultiPost,
                       TIMELINE_INFO &sFriendsTimeline,
                       TIMELINE_INFO &sPublicTimeline,
                       TIMELINE_INFO &sUserTimeline,
                       TIMELINE_INFO &sReplies );

    void    ExecuteUpdate( CStatic          *sp,
                           bool             useTwitStar,
                           CChirrupDlg      *cdlg,
                           ProceedingDialog *pdlg );
    void    SetLogFileSpec();

    void    WriteKeys( FILE          *fp,
                       char          *key,
                       unsigned char **secret,
                       bool          &done );
    bool    EvalKeys( const char          *p,
                      const unsigned char *rsaString,
                      char                *encrypted );

    CTwitterTimeline    *GetReplies()
    {
        return ( &m_replies );
    }

private:
    CTwitterManager( CTwitterManager &obj );
    CTwitterManager operator = ( CTwitterManager &obj );
};

#endif  /* __C_TWITTER_MANAGER_H__ */
