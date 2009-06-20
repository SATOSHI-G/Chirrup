/*
 * wassr.h   : Wassr �N���C�A���g chirrup
 *      Wassr API �𗘗p���邽�߂̊e�폈���Q �w�b�_�t�@�C��
 *          written by H.Tsujimura  14 Jun 2007
 *
 *      Copyright (c) 2007 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/wassr.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 18    08/11/21 15:35 Tsujimura543
 * PostPhotoViaAPI() ��ǉ�
 * 
 * 17    08/08/02 2:23 Tsujimura543
 * GetChannelList() ��ǉ�
 * 
 * 16    08/08/01 4:35 Tsujimura543
 * �摜�̓��e���u�`�����l���v�Ή�����
 * 
 * 15    08/08/01 2:39 Tsujimura543
 * Wassr �ւ̉摜�̓��e�ɑΉ�
 * 
 * 14    08/07/08 14:51 Tsujimura543
 * Wassr �́u�C�C�l!�v�ɑΉ�
 * 
 * 13    07/09/06 19:42 Tsujimura543
 * �_�~�[�̃R�s�[�R���X�g���N�^�A������Z�q�� private �Ƃ��ē����B
 * �m��Ȃ������Ƀ������m��(�Ɖ�����Y��)����������\����r���B
 * 
 * 12    07/07/05 0:50 Tsujimura543
 * (1) GetStatFromJSON(), GetUserTimeline() �̈�����ύX
 * (2) TWITTER_USER �\���̂̕ύX(orig_userName��ǉ�)�ɔ����C��
 * (3) MakeMessageForScreen() �� MakeMessageForLogging() ��p��
 * 
 * 11    07/06/25 18:03 Tsujimura543
 * DeleteReserved(), DeleteReserved2() �֘A�A�R�[�h�𐮗�
 * 
 * 10    07/06/25 17:40 Tsujimura543
 * DeleteReserved(), DeleteReserved2() ��ǉ�
 * 
 * 9     07/06/21 19:15 Tsujimura543
 * SetUserAgent() �� CService ���̃��\�b�h�Ɉ�{������
 * 
 * 8     07/06/20 19:28 Tsujimura543
 * GetStatusID() �𓱓�
 * 
 * 7     07/06/19 23:01 Tsujimura543
 * CService �𓱓����A�\�[�X�R�[�h�𐮗�����
 * 
 * 6     07/06/18 18:51 Tsujimura543
 * �f�t�H���g�A�C�R���̒�`�� defaultImage.h �Ɉڂ�
 * 
 * 5     07/06/15 17:37 Tsujimura543
 * Wassr ���L�̕�������(�G�������������Ǝv����)�΍��ǉ�
 * 
 * 4     07/06/14 21:11 Tsujimura543
 * ���O�o�͎��́u�X�N���[�����v�� UTF-8 �ɂȂ��Ă��Ȃ������s����C��
 * 
 * 3     07/06/14 19:17 Tsujimura543
 * �\�[�X�𐮗�
 * 
 * 2     07/06/14 19:06 Tsujimura543
 * friends_timeline �� user_timeline ���������āATwitter �݊���
 * friends_timeline �𐶐����鏈����ǉ�
 * 
 * 1     07/06/14 17:55 Tsujimura543
 * �V�K�쐬 (�b���)
 */

#ifndef __WASSR_H__
#define __WASSR_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CService.h"

typedef struct WassrChennelList {
    char  image_url[MAX_URLLENGTH]; // �`�����l���A�C�R����URL
    char  title[MAX_CATNAMELENGTH]; // �`�����l����
    char  name_en[MAX_NAMELEN];     // �`�����l��ID (�p�ꖼ)
}   WASSR_CHANNEL_LIST;

class CWassr : public CService
{
public:
    CWassr();
    ~CWassr();

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

    // �w�胆�[�U�� friend �ɂ���
    bool    AddFriend( const char *userID );

    // �w�胆�[�U�� friend ����O��
    bool    RemoveFriend( const char *userID );

    // �w�� status �� favorites �ɂ��� (�u�C�C�l!�v������)
    bool    SetFavorite( const char *statusID );

    // �����̃X�N���[�����̎擾
    CString GetScreenName();

    // �摜�𓊍e
    BOOL
    PostPhoto(
        const char  *filename, // (I) ���e����摜�̃t�@�C����
        size_t      filesize,  // (I) ���e����摜�̃t�@�C���T�C�Y
        const char  *caption,  // (I) ���e����摜�Ƃ�������ɓ��e����u�����v
        char        *url );    // (O) �A�b�v���[�h��URL

    BOOL
    PostPhotoViaAPI(
        const char  *filename, // (I) ���e����摜�̃t�@�C����
        size_t      filesize,  // (I) ���e����摜�̃t�@�C���T�C�Y
        const char  *caption,  // (I) ���e����摜�Ƃ�������ɓ��e����u�����v
        char        *url );    // (O) �A�b�v���[�h��URL

    // �Q�����̃`�����l���̈ꗗ�̎擾
    WASSR_CHANNEL_LIST  *GetChannelList( int &numOfChannels );

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

    CTime           GetCreatedAtFromJSON( const char *p,
                                          const char *terminator );
    CString         GetIdFromJSON( const char *p,
                                   const char *terminator );
    CString         GetHtmlFromJSON( const char *p,
                                     const char *terminator );
    TWITTER_USER    GetUserFromJSON( const char *p,
                                     const char *terminator,
                                     const char *userName );

    long            GetEpochFromJSON( const char *p,
                                      const char *terminator );
    char            *GetUserLoginIdFromJSON(
                                      const char *p,
                                      const char *terminator );

    char            *Regulize( char *text, const char *origText );

private:
    bool    loginWassr( const char *username,
                        const char *password,
                        char       *cookie,
                        char       *key,
                        const char *channel,
                        char       *channel_rid );

    BOOL    readImageData( const char *filename,
                           size_t filesize,
                           FILEINF *fInfo );
    size_t  makeRequestForPhoto(
                        char          *request,
                        char          *contentType,
                        const char    *key,
                        const char    *caption,
                        const char    *channel_rid,
                        const FILEINF *fInfo );

    char    *getPhotoURL( const char *response,
                          const char *channel,
                          char       *url );

    BOOL
    PostPhoto(
        const char *filename,// (I)   ���e����摜�̃t�@�C����
        size_t     filesize, // (I)   ���e����摜�̃t�@�C���T�C�Y
        const char *caption, // (I)   ���e����摜�Ƃ�������ɓ��e����u�����v
        char       *url,     // (O)   �A�b�v���[�h��URL
        char       *cookie,  // (I/O) �N�b�L�[
        const char *key,            // (I) CSRF�΍�L�[
        const char *channel,        // (I) �`�����l����
        const char *channel_rid );  // (I) �`�����l��ID


    size_t  makeRequestForPhotoViaAPI(
                        char          *request,
                        char          *contentType,
                        const char    *key,
                        const char    *caption,
                        const char    *channel_rid,
                        const FILEINF *fInfo );

    BOOL
    PostPhotoViaAPI(
        const char *filename,  // (I) ���e����摜�̃t�@�C����
        size_t     filesize,   // (I) ���e����摜�̃t�@�C���T�C�Y
        const char *caption,   // (I) ���e����摜�Ƃ�������ɓ��e����u�����v
        const char *rid,       // (I) ���񓊍e����u�����v�̕ԐM�Ώہu����ID�v
        char       *url,       // (O) �A�b�v���[�h��URL
        const char *channel ); // (I) �`�����l����

private:
    CWassr( CWassr &obj );
    CWassr  operator = ( CWassr &obj );
};

#endif  /* __WASSR_H__ */