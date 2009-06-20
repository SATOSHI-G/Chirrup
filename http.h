/*
 * http.h  : Twitter �N���C�A���g chirrup
 *      http�֘A �w�b�_ �t�@�C��
 *          written by H.Tsujimura  19 Jun 2007 / 19 Dec 2007
 *
 *      Copyright (c) 2007 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/http.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 3     08/03/26 22:17 Tsujimura543
 * �r�����������
 * 
 * 2     07/12/19 18:43 Tsujimura543
 * �R�����g���C��
 * 
 * 1     07/12/19 18:42 Tsujimura543
 * http�֘A�̊֐��Q�� CService.h ���番��
 */

#if !defined(__HTTP_H__A07B8677_638F_45CA_8C84_9324D00DA47B__INCLUDED_)
#define __HTTP_H__A07B8677_638F_45CA_8C84_9324D00DA47B__INCLUDED_

#ifdef __cplusplus
void    _http_startUp();
void    _http_shutDown();

char    *
_http_post( const char       *url,
            const char       *request,
            char             *response,
            ProceedingDialog *pdlg );

char    *
_http_get( const char       *url,
           char             *response,
           ProceedingDialog *pdlg );

char    *
_http_postBASIC( const char       *url,
                 const char       *userName,
                 const char       *password,
                 const char       *request,
                 char             *response,
                 char             *cookie,
                 ProceedingDialog *pdlg );

char    *
_http_getBASIC( const char       *url,
                const char       *userName,
                const char       *password,
                char             *response,
                char             *cookie,
                ProceedingDialog *pdlg );
#endif  /* __cplusplus */


#ifdef __cplusplus
extern "C" {
#endif

// �ȉ��̊֐��́AC++ �����łȂ��AC ������Ăяo����邱�Ƃ�z�肵�Ă���

char    *
__http_postBASIC( const char       *url,
                  const char       *userName,
                  const char       *password,
                  const char       *request,
                  char             *response,
                  char             *cookie );

char    *
__http_getBASIC( const char       *url,
                 const char       *userName,
                 const char       *password,
                 char             *response,
                 char             *cookie );

#ifdef __cplusplus
}
#endif

#endif  /* __HTTP_H__A07B8677_638F_45CA_8C84_9324D00DA47B__INCLUDED_ */
