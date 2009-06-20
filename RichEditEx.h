/*
 * RichEditEx.h  : Twitter �N���C�A���g chirrup
 *      URL �N���b�J�u���ȃ��b�`�G�f�B�b�g�R���g���[�� �w�b�_�[�t�@�C��
 *          written by H.Tsujimura  26 Apr 2007
 *
 *      Copyright (c) 2007, 2008, 2009 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/RichEditEx.h $
 * 
 * 2     09/05/31 20:42 tsupo
 * 1.142��
 * 
 * 38    09/05/29 19:22 Tsujimura543
 * ����A�J�E���g�ŕ��� tumbleblog ���J�݂��Ă���ꍇ�̓��e��
 * tumbleblog ���w�肵�Ă̓��e���\�ɂ���
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 37    09/03/31 23:29 Tsujimura543
 * Twitter �� OAuth �Ή����� ����7
 * 
 * 36    08/08/22 18:42 Tsujimura543
 * �u�͂Ăȃn�C�N�v�Ή�
 * 
 * 35    08/07/16 15:27 Tsujimura543
 * Timelog �́u�]���v�ɑΉ�����
 * 
 * 34    08/07/08 14:51 Tsujimura543
 * Wassr �́u�C�C�l!�v�ɑΉ�
 * 
 * 33    08/02/07 22:36 Tsujimura543
 * copyright �\�����C�� (2008 ��ǉ�)
 * 
 * 32    08/02/05 22:38 Tsujimura543
 * Alt�L�[�� down/up ���o�������ǉ� (���̂Ƃ���AAlt�L�[�֘A�͖��g�p)
 * 
 * 31    08/02/05 22:29 Tsujimura543
 * F3�L�[�����ŕ������������AShift+F3�ŕ������������ɂȂ�悤�ɂ��Ă݂�
 * 
 * 30    08/02/05 21:33 Tsujimura543
 * F3�L�[�����ł��u�����v�@�\���N���ł���悤�ɂ���
 * 
 * 29    08/02/04 18:13 Tsujimura543
 * �����@�\����
 *   (1) ���������ւ̌������T�|�[�g
 *   (2) �����p�p�����[�^�̈ꎞ�L�����T�|�[�g
 *   (3) �I�[�g�X�N���[���Ή�
 * 
 * 28    08/02/01 23:11 Tsujimura543
 * ctrl+F �ɂ��u�����v�������I�Ɏ���
 * 
 * 27    07/11/08 23:53 Tsujimura543
 * Twitter�����Abuzztter�AGoogle�AYahoo! �Ƃ̘A��(����)�@�\��ǉ�
 * 
 * 26    07/11/07 3:39 Tsujimura543
 * ���Ă��锭���� ���p���� Tumblr �֓��e����@�\���쐬
 * 
 * 25    07/09/27 20:57 Tsujimura543
 * �E�N���b�N�@�\���T�|�[�g(�I�𒆂̕�����̃N���b�v�{�[�h�ւ̃R�s�[�A
 * �\������Ă��镶����̑S�I��)
 * 
 * 24    07/09/27 18:35 Tsujimura543
 * �u���������v�ɑΉ�����
 * 
 * 23    07/09/18 22:29 Tsujimura543
 * �����N�̃h���b�O�� CF_HDROP �ɂ���(�f�X�N�g�b�v���t�H���_�ւ̃h���b�O
 * �ɂ��Ή�����)
 * 
 * 22    07/09/18 18:59 Tsujimura543
 * COleDataSource �ȕϐ����A�N���X���v���p�e�B���烍�[�J���ϐ��ɕύX
 * 
 * 21    07/09/18 16:59 Tsujimura543
 * �����N�̃h���b�O���T�|�[�g (���܂̂Ƃ��� CF_TEXT �Ƃ��đ��o���Ă���)
 * 
 * 20    07/09/12 18:30 Tsujimura543
 * OnLButtonDblClk() �����t�@�N�^�����O
 * 
 * 19    07/09/06 19:42 Tsujimura543
 * �_�~�[�̃R�s�[�R���X�g���N�^�A������Z�q�� private �Ƃ��ē����B
 * �m��Ȃ������Ƀ������m��(�Ɖ�����Y��)����������\����r���B
 * 
 * 18    07/08/25 1:53 Tsujimura543
 * �u�������v�Ή� (���ۂɁ�������)
 * 
 * 17    07/08/17 17:25 Tsujimura543
 * SetLinkTwitter3() ��ǉ�
 * 
 * 16    07/08/16 19:53 Tsujimura543
 * Timelog �́u�����v�� permalink �֔�ׂ�悤�ɂ��� ([link] ���N���b�N)
 * 
 * 15    07/07/23 14:54 Tsujimura543
 * SetLinkTwitter2() ��ǉ�
 * 
 * 14    07/07/03 13:51 Tsujimura543
 * Visual Studio 2005 �ł̃r���h���ʂ𔽉f
 * 
 * 13    07/06/26 19:53 Tsujimura543
 * ���������̃����N�ɑΉ�
 * 
 * 12    07/06/26 15:10 Tsujimura543
 * Jaiku �̃����N�ɑΉ�
 * 
 * 11    07/06/26 0:29 Tsujimura543
 * CRichEditEx �� m_timeline ��ǉ����ATwitter �� status �����N�֔��
 * ���߂̏������ȗ�������
 * 
 * 10    07/06/26 0:11 Tsujimura543
 * �R�����g���C��
 * 
 * 9     07/06/26 0:10 Tsujimura543
 * SetLinkTwitter() ��ǉ����ATwitter �� status �y�[�W�֒��ڔ�ׂ�悤�ɂ���
 * 
 * 8     07/06/25 23:13 Tsujimura543
 * SetLinkTimelog() ��ǉ�
 * 
 * 7     07/06/25 21:12 Tsujimura543
 * SetLink() ��ǉ�
 * 
 * 6     07/06/21 14:48 Tsujimura543
 * m_targetUser ��p�~
 * 
 * 5     07/06/21 14:45 Tsujimura543
 * �u�����v���_�u���N���b�N���������ŁA�u�����v���͗��ɃR�����g�Ԃ��p����
 * ���\���ł���悤�ɂ���
 * 
 * 4     07/06/20 21:08 Tsujimura543
 * SetWhity() ��ǉ�
 * 
 * 3     07/04/28 0:22 Tsujimura543
 * m_targetUser ��ǉ��B�_�u���N���b�N�����s�� Twitter �̃X�N���[������
 * ���݂���Ίi�[����悤�ɂ���
 * 
 * 2     07/04/27 22:26 Tsujimura543
 * SetStrong() ��ǉ�
 * 
 * 1     07/04/26 20:16 Tsujimura543
 * �V�K�쐬
 */

#if !defined(AFX_RICHEDITEX_H__43C46684_644A_4A51_B317_33C70EBB6EB5__INCLUDED_)
#define AFX_RICHEDITEX_H__43C46684_644A_4A51_B317_33C70EBB6EB5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxole.h>

/////////////////////////////////////////////////////////////////////////////
// CRichEditEx �E�B���h�E

class CRichEditEx : public CRichEditCtrl
{
// �R���X�g���N�V����
public:
	CRichEditEx();

// �A�g���r���[�g
public:
    CChirrupDlg                 *m_chirrupDlg;
    CTwitterTimeline            *m_timeline;
    CTwitterTimeline::SVC_TYPE  m_serviceType;

    CString                     m_username;
    CString                     m_password;
    CString                     m_hatenaID;
    CString                     m_hatenaPassword;
    CString                     m_tumblrID;
    CString                     m_tumblrPassword;
    CString                     m_tumblrGroup;

    CString                     m_twitterOauthToken;
    CString                     m_twitterOauthTokenSecret;
    bool                        m_twitterUseOAuth;

// �I�y���[�V����
public:
    void    SetAutoUrlDetect();
    void    SetStrong( CString target );    // �w�蕶����������\��
    void    SetWhity();                     // ���b�Z�[�WID�����𔖐F�\��
    void    SetLink();                      // �e�탊���N�𖄂ߍ���

// �I�[�o�[���C�h
	//{{AFX_VIRTUAL(CRichEditEx)
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
public:
	virtual ~CRichEditEx();

private:
    void    SetLinkTimelog();   // tag �Ƀ����N�𖄂ߍ���
    void    SetLinkTimelog2();  // link �Ƀ����N�𖄂ߍ���
    void    SetLinkTwitter();   // status ID �Ƀ����N�𖄂ߍ���
    void    SetLinkTwitter2();  // source �Ƀ����N�𖄂ߍ���
    void    SetLinkTwitter3();  // �� / �� �Ƀ����N�𖄂ߍ���
    void    SetLinkJaiku();     // title �Ƀ����N�𖄂ߍ���
    void    SetLinkMogo2();     // >>messageID �Ƀ����N�𖄂ߍ���
    void    SetLinkStar( bool useStar ); // �� �������� �� �Ƀ����N�𖄂ߍ���
    void    SetLinkStar2();     // �� �Ƀ����N�𖄂ߍ��� (for Timelog)

    void    GetTargetUser( CString &targetUser, long startPos );
    bool    DragStart( CString &url );

    void    GetLinkTwitter( CString &url, CString &url2, ENLINK *pLink );
    void    GetLinkJaiku( CString &url, CString &url2 );
    void    GetLinkMogo2( CString &url, CString &url2, ENLINK *pLink );
    void    GetLinkTimelog( CString &url, CString &url2, ENLINK *pLink );
    void    GetLinkHaruFm( CString &url, CString &url2 );
    void    GetLinkWassr( CString &url, CString &url2, ENLINK *pLink );
    void    GetLinkHatenaHaiku( CString &url, CString &url2, ENLINK *pLink );

    void    SetFavoriteOnTwitter( CString &url, ENLINK *pLink );
    void    SetFavoriteOnWassr( CString &url, ENLINK *pLink );
    void    SetFavoriteOnTimelog( CString &url, ENLINK *pLink );
    void    SetHatenaStarOnTwitter( CString &url, CString &url2, ENLINK *pLink );
    void    SetHatenaStarOnMogo2( CString &url, CString &url2, ENLINK *pLink );
    void    SetHatenaStarOnHatenaHaiku( CString &url, CString &url2, ENLINK *pLink );

	// ���b�Z�[�W�}�b�v�֐�
protected:
	//{{AFX_MSG(CRichEditEx)
#if _MSC_VER >= 1400
	afx_msg BOOL OnLink(NMHDR* pNMHDR, LRESULT* pResult);
#else
	afx_msg void OnLink(NMHDR* pNMHDR, LRESULT* pResult);
#endif
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnEditCopy();
    afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void OnSysKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg LONG OnFind(WPARAM wParam, LPARAM lParam);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

private:
    bool                m_active;
    CString             m_text;

    // �����֘A
    CFindReplaceDialog  *m_findDialog;
    bool                m_findMatchCase;        // �啶���E�������̋�ʂ̗L��
    bool                m_findMatchWholeWord;   // ���S��v��������v��
    bool                m_findSearchDown;       // ��������������������
    char                *m_findBuf;

    bool                m_shiftKeyDown;
    bool                m_altKeyDown;

    void    GetTargetURL(
                CString &targetURL,
                CString &targetContent,
                long    startPos
            );
    void    PostTumblr( CString targetURL, CString targetContent );
    void    ExecuteSearch( int cmdType, const char *text );

    void    OnSearchText();

    CRichEditEx( CRichEditEx &obj );
    CRichEditEx operator = ( CRichEditEx &obj );
};

class   CChirrupDropSource : public COleDropSource
{   // m_bDragStarted �̒l���Q�Ƃ����������̖ړI�ō�����N���X
public:
    BOOL    isDragStarted() { return ( m_bDragStarted ); }
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_RICHEDITEX_H__43C46684_644A_4A51_B317_33C70EBB6EB5__INCLUDED_)
