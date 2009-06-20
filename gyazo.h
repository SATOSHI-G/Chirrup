/*
 * gyazo.h : Twitter �N���C�A���g chirrup
 *      Gyazo �֘A �w�b�_�[�t�@�C��
 *          written by H.Tsujimura  6 Dec 2007 / 13 Dec 2007
 *
 *      Copyright (c) 2007 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/gyazo.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 1     07/12/13 19:01 Tsujimura543
 * Gyazo�֘A�̃v���g�^�C�v�錾�� tumblr.h ���番���Ɨ�������
 */

#ifndef __GYAZO_H__
#define __GYAZO_H__

// Gyazo �Ɂu�摜�v�𓊍e����
BOOL
postPhotoOnGyazo(
    const char *filename,   // (I)   Gyazo �ɓ��e����摜�̃t�@�C����
    size_t     filesize,    // (I)   Gyazo �ɓ��e����摜�̃t�@�C���T�C�Y
    char       *gyazoID,    // (I/O) Gyazo ID
    char       *url );      // (O)   �A�b�v���[�h��URL

#endif  /* __GYAZO_H__ */
