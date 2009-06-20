/*
 * flickr.h : Twitter �N���C�A���g chirrup
 *      Flickr �֘A �w�b�_�[�t�@�C��
 *          written by H.Tsujimura  9 Jan 2008
 *
 *      Copyright (c) 2008 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/flickr.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 4     09/04/22 21:11 Tsujimura543
 * �u�ݒ�v�_�C�A���O�����Flickr�F�؂̃A�N�Z�X�g�[�N��(frob)���擾�ł���
 * �悤�ɂ���
 * 
 * 3     08/01/09 22:26 Tsujimura543
 * flickrNSID �� flickrUserName �ɕύX
 * 
 * 2     08/01/09 21:58 Tsujimura543
 * ���� flickrNSID ��ǉ�
 * 
 * 1     08/01/09 19:23 Tsujimura543
 * �V�K�쐬
 */

#ifndef __FLICKR_H__
#define __FLICKR_H__

// Flickr �Ɂu�摜�v�𓊍e����
BOOL
postPhotoOnFlickr(
    const char *filename,       // (I)   Flickr �ɓ��e����摜�̃t�@�C����
    size_t     filesize,        // (I)   Flickr �ɓ��e����摜�̃t�@�C���T�C�Y
    const char *title,          // (I)   Flickr �ɓ��e����摜�́u�薼�v
    const char *caption,        // (I)   Flickr �ɓ��e����摜�́u�����v
    const char *flickrKey,      // (I)   Flickr API�L�[
    const char *flickrSecret,   // (I)   signature�������ɕt�����镶����
    char       *flickrToken,    // (I/O) Flickr �g�[�N��
    char       *flickrUserName, // (I/O) Flickr ���[�U��
    char       *url );          // (O)   �A�b�v���[�h��URL

// �A�N�Z�X�g�[�N���̎擾
BOOL
GetAccessTokenOnFlickr(
    const char *flickrKey,      // (I)   Flickr API�L�[
    const char *flickrSecret,   // (I)   signature�������ɕt�����镶����
    char       *flickrToken,    // (I/O) Flickr �g�[�N��
    char       *flickrUserName, // (I/O) Flickr ���[�U��
    char       *flickrNSID );   // (I/O) Flickr NSID

#endif  /* __FLICKR_H__ */
