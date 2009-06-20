/*
 * hatenaFotolife.h : Twitter �N���C�A���g chirrup
 *      �͂Ăȃt�H�g���C�t �֘A �w�b�_�[�t�@�C��
 *          written by H.Tsujimura  19 Jan 2008
 *
 *      Copyright (c) 2008 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/hatenaFotolife.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 2     08/01/23 17:39 Tsujimura543
 * ���� + ����m�F�A����
 * 
 * 1     08/01/19 0:30 Tsujimura543
 * �ŏ��̔�
 */

#ifndef __HATENA_FOTOLIFE_H__
#define __HATENA_FOTOLIFE_H__

#define HATENA_F_ENDPOINT_URL "http://f.hatena.ne.jp/atom"

typedef enum {
    MITYPE_UNKNOWN = -1,
    MITYPE_JPG     = 1,
    MITYPE_GIF,
    MITYPE_PNG,
    MITYPE_BMP
}   MIMAGE_TYPE;

/* WSSE �̐��� */
char    *makeWSSE( const char *username, const char *password, char *buffer,
                   int blogKind );


// �͂Ăȃt�H�g���C�t �Ɂu�摜�v�𓊍e����
BOOL
postPhotoOnHatenaFotolife(
    const char  *filename,       // (I) ���e����摜�̃t�@�C����
    size_t      filesize,        // (I) ���e����摜�̃t�@�C���T�C�Y
    MIMAGE_TYPE filetype,        // (I) ���e����摜�̃t�@�C�����
    const char  *title,          // (I) ���e����摜�́u�薼�v
    const char  *hatenaID,       // (I) �͂Ă� ID
    const char  *hatenaPassword, // (I) �͂Ă� �p�X���[�h
    char        *url );          // (O) �A�b�v���[�h��URL

#endif  /* __HATENA_FOTOLIFE_H__ */
