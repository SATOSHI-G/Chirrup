/*
 * twitterTimeline.h : Twitter �N���C�A���g chirrup
 *      timeline �֘A�e�폈���Q �w�b�_�t�@�C��
 *          written by H.Tsujimura  4 Apr 2007 / 25 May 2007
 *
 *      Copyright (c) 2007, 2008, 2009 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/twitterTimeline.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 12    09/03/31 23:29 Tsujimura543
 * Twitter �� OAuth �Ή����� ����7
 * 
 * 11    08/08/22 18:42 Tsujimura543
 * �u�͂Ăȃn�C�N�v�Ή�
 * 
 * 10    08/07/31 18:19 Tsujimura543
 * �u�`�����l���v�ɑΉ�
 * 
 * 9     07/09/06 19:42 Tsujimura543
 * �_�~�[�̃R�s�[�R���X�g���N�^�A������Z�q�� private �Ƃ��ē����B
 * �m��Ȃ������Ƀ������m��(�Ɖ�����Y��)����������\����r���B
 * 
 * 8     07/07/05 16:08 Tsujimura543
 * GetServiceName() ��ǉ�
 * 
 * 7     07/06/21 22:40 Tsujimura543
 * LoadUserIcon() ��ύX�A���[�U�A�C�R���� URL ���s���ȏꍇ�ATwitter
 * �� ShowUser API ���g���ăA�C�R���� URL ���擾����悤�ɂ���
 * 
 * 6     07/06/20 15:47 Tsujimura543
 * timelineSetting �\���̂̃R���X�g���N�^��ǉ�
 * 
 * 5     07/06/18 18:52 Tsujimura543
 * LoadUserIcon() �𓱓����A���[�U�A�C�R���̕\����������{������
 * 
 * 4     07/06/13 0:12 Tsujimura543
 * (1) TIMELINE_INFO �֘A fix
 * (2) �����ݒ�t�@�C���ǂݏ�����V�������O�t�@�C���Ǘ��d�l�ɑΉ�������
 * 
 * 3     07/06/12 19:49 Tsujimura543
 * ���O�t�@�C�����̖����ɓ��t�𖄂ߍ��ނ��Ƃ��ł���悤�ɂ���
 * 
 * 2     07/06/06 19:05 Tsujimura543
 * ���O���t�@�C���ɏ����o���@�\������
 * 
 * 1     07/05/25 20:15 Tsujimura543
 * �V�K�쐬 (chirrupDlg.h ���番���A�Ɨ�)
 */

#ifndef __TWITTER_TIMELINE_H__
#define __TWITTER_TIMELINE_H__


class CChirrupDlg;

typedef struct timelineSetting  {
    CString logFileName;
    bool    checkTimeline;
    bool    checkLogFile;
    bool    checkChannel;

    timelineSetting()
    {
        logFileName   = _T("");
        checkTimeline = false;
        checkLogFile  = false;
        checkChannel  = false;
    }
}   TIMELINE_INFO;


class CTwitterTimeline {
public:
    CTwitterTimeline();
    ~CTwitterTimeline();

    typedef enum serviceType   {
        SVC_TWITTER = 1,
        SVC_JAIKU,
        SVC_WASSR,
        SVC_MOGO2,
        SVC_TIMELOG,
        SVC_HARUFM,
        SVC_HATENAHAIKU
    }   SVC_TYPE;
    SVC_TYPE        m_serviceType;

    // �ݒ�
    bool            m_checkTimeline;    // �{���ΏۂƂ��邩�ۂ�
    bool            m_checkChannel;     // �Q�����̃`�����l�����{���ΏۂƂ��邩�ۂ�
    bool            m_checkLogFile;     // basename �ɓ��t��t�����邩�ۂ�
    CString         m_logFileBaseName;  // ���O�t�@�C�� basename
    CString         m_logFileExtention; // ���O�t�@�C�� �g���q

    // user
    long            m_numOfUsers;
    TWITTER_USER    *m_users;

    // status
    long            m_numOfStats;
    TWITTER_STATUS  *m_stat;
	CString	        m_messages;

    // logging
    bool            m_logging;
    char            m_logFileName[MAX_PATH];
    FILE            *m_logFp;

    bool            InitTimeline();
    void            MoveTimeline();
    void            LoadTimeline( CChirrupDlg *cp, CString cacheDir );

    void            SetLogFileSpec( TIMELINE_INFO s );
    CString         GetServiceName();

    void            StartLogging();
    void            FinishLogging();
    void            WriteLog( const char *str );

private:
    CTwitterTimeline( CTwitterTimeline &obj );
    CTwitterTimeline    operator = ( CTwitterTimeline &obj );
};

bool
LoadUserIcon( CStatic                    *sp,
              TWITTER_USER               *u,
              CTwitterTimeline::SVC_TYPE &type,
              const char                 *cacheDir,
              CString                    username = _T(""),
              CString                    password = _T(""),
              bool                       useOAuth = false,
              CString                    oauthToken       = _T(""),
              CString                    oauthTokenSecret = _T("") );

#endif  /* __TWITTER_TIMELINE_H__ */