/*
 * tumblr.h : Twitter �N���C�A���g chirrup
 *      tumblr �֘A �w�b�_�[�t�@�C��
 *          written by H.Tsujimura  5 Nov 2007
 *
 *      Copyright (c) 2007, 2008, 2009 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/tumblr.h $
 * 
 * 2     09/05/31 20:42 tsupo
 * 1.142��
 * 
 * 9     09/05/29 19:22 Tsujimura543
 * ����A�J�E���g�ŕ��� tumbleblog ���J�݂��Ă���ꍇ�̓��e��
 * tumbleblog ���w�肵�Ă̓��e���\�ɂ���
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 8     08/02/13 0:10 Tsujimura543
 * tumblr �ւ� Quote ���e���ɃR�����g����������ɓ��e�ł���悤�ɂ���
 * 
 * 7     07/12/13 19:01 Tsujimura543
 * Gyazo�֘A�̃v���g�^�C�v�錾�� gyazo.h �Ƃ��ĕ����Ɨ�������
 * 
 * 6     07/12/10 21:21 Tsujimura543
 * postPhotoWithUrlOnTumblr() ��ǉ�
 * 
 * 5     07/12/10 16:39 Tsujimura543
 * Gyazo �ւ̓��e�����֘A�� fix
 * 
 * 4     07/12/06 19:50 Tsujimura543
 * Gyazo �ɉ摜���A�b�v���[�h����@�\������
 * (������͕ʃt�@�C���Ƃ��ĕ�������)
 * 
 * 3     07/12/06 1:29 Tsujimura543
 * postPhotoOnTumblr() ��ǉ�
 * 
 * 2     07/11/07 3:39 Tsujimura543
 * ���Ă��锭���� ���p���� Tumblr �֓��e����@�\���쐬
 * 
 * 1     07/11/05 23:56 Tsujimura543
 * �ŏ��̔�
 */

#ifndef __TUMBLR_H__
#define __TUMBLR_H__

#ifdef __cplusplus
extern "C" {
#endif

// tumblr �Ɂu�����v�́u���p�v�𓊍e����
BOOL
postTumblr(
    const char *targetURL,  // (I) tumblr �ɓ��e����L���� URL
    const char *quote,      // (I) tumblr �ɓ��e����L���́u���e�v
    const char *title,      // (I) tumblr �ɓ��e����L���́u�薼�v
    const char *comment,    // (I) tumblr �ɓ��e����L���́u�R�����g�v
    const char *username,   // (I) tumblr �� login ����Ƃ��̃��[���A�h���X
    const char *password,   // (I) �p�X���[�h
    const char *group );    // (I) ���e�� tumbleblog ID �܂��̓O���[�v��

// tumblr �Ɂu�摜�v�𓊍e����
BOOL
postPhotoOnTumblr(
    const char *filename,   // (I)   tumblr �ɓ��e����摜�̃t�@�C����
    size_t     filesize,    // (I)   tumblr �ɓ��e����摜�̃t�@�C���T�C�Y
    const char *caption,    // (I)   tumblr �ɓ��e����摜�́u�����v
    const char *username,   // (I)   tumblr �� login ����Ƃ��̃��[���A�h���X
    const char *password,   // (I)   �p�X���[�h
    const char *group,      // (I)   ���e�� tumbleblog ID �܂��̓O���[�v��
    char       *url );      // (O)   �A�b�v���[�h��URL

// tumblr �� url �t���Łu�摜�v�𓊍e����
BOOL
postPhotoWithUrlOnTumblr(
    const char *photoURL,   // (I)   tumblr �ɓ��e����摜��URL
    const char *caption,    // (I)   tumblr �ɓ��e����摜�́u�����v
    const char *username,   // (I)   tumblr �� login ����Ƃ��̃��[���A�h���X
    const char *password,   // (I)   �p�X���[�h
    const char *group,      // (I)   ���e�� tumbleblog ID �܂��̓O���[�v��
    char       *url );      // (O)   �A�b�v���[�h��URL

// tumbleblog �ꗗ���擾����
int
getBlogIDsTumblr(
    const char *userName,       // (I) ���[�U�� (���[���A�h���X)
    const char *password,       // (I) �p�X���[�h
    int        *numberOfBlogs,  // (I) �擾����/�擾���� blog ���̐�
    BLOGINF    *blogInfo );     // (O) �擾���� blog ���

#ifdef __cplusplus
}
#endif

#endif  /* __TUMBLR_H__ */
