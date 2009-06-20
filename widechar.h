/*
 * widechar.h  : Twitter �N���C�A���g chirrup
 *      ���������΍􃆁[�e�B���e�B�֐��Q �w�b�_�[�t�@�C��
 *          written by H.Tsujimura  12 Dec 2007
 *
 *      Copyright (c) 2007 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/widechar.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 1     07/12/12 19:39 Tsujimura543
 * �ŏ��̔�
 */

#ifndef __WIDE_CHAR_H__
#define __WIDE_CHAR_H__

// UTF-8 �ɂ͑��݂��邪 CP932 �ɂ͑��݂��Ȃ������ɂ��āA
// ����������ԂɂȂ�̂�h�����߂̊֐�

CString
RegulateCode(
    const char *orig, // (I) �Ώە����� (UTF-8)
    const char *conv  // (I) �Ώە������ iconv ���g���� CP932 �ɕϊ���������
  );

#endif  /* __WIDE_CHAR_H__ */
