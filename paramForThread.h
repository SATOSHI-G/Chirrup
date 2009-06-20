/*
 * paramForThread.h  : Twitter �N���C�A���g chirrup
 *      �X���b�h�ԒʐM�p�\���� ��`�t�@�C��
 *          written by H.Tsujimura  5 Jun 2007 / 10 Dec 2007
 *
 *      Copyright (c) 2007 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/paramForThread.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 2     07/12/13 22:26 Tsujimura543
 * �摜�̃A�b�v���[�h���������ύX(�͂Ă�Fotolife�Ή������Abmp�t�@�C����
 * ��)
 * 
 * 1     07/12/10 22:38 Tsujimura543
 * chirrupDlg.h ���番���A�Ɨ�������
 */

#if !defined(__PARAM_FOR_THREAD_H__43C46684_644A_4A51_B317_33C70EBB6EB5__INCLUDED_)
#define __PARAM_FOR_THREAD_H__43C46684_644A_4A51_B317_33C70EBB6EB5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef struct paramForUpdateThread {
    CChirrupDlg *dlg;
    CManager    *manager;
    CString     timelineType;
}   PARAM_UPDATE;

typedef struct paramForPostThread   {
    CChirrupDlg *dlg;
    CString     timelineType;
    CString     monologue;
    bool        ret;
}   PARAM_POST;

typedef struct paramForLoadImage    {
    CChirrupDlg         *dlg;
    CTwitterTimeline    *tp;
    CString             cacheDir;
}   PARAM_LOADIMAGE;



typedef enum {
    FTYPE_UNKNOWN = -1,
    FTYPE_JPG     = 1,
    FTYPE_GIF,
    FTYPE_PNG,
    FTYPE_BMP          } CHIRRUP_FTYPE;

typedef struct paramForUploadImage  {
    CChirrupDlg     *dlg;
    CHIRRUP_FTYPE   filetype;
    CString         filename;
    size_t          filesize;
    CString         url;
    CString         caption;
}   PARAM_UPLOADIMAGE;

#endif // !defined(__PARAM_FOR_THREAD_H__43C46684_644A_4A51_B317_33C70EBB6EB5__INCLUDED_)
