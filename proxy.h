/*
 * proxy.h : Twitter �N���C�A���g chirrup
 *      �v���N�V�ݒ�֘A �w�b�_�[ �t�@�C��
 *          written by H.Tsujimura  26 Nov 2007 / 13 Dec 2007
 *
 *      Copyright (c) 2007 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/proxy.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 3     07/12/20 16:36 Tsujimura543
 * �����ݒ�t�@�C�����܂����݂��Ȃ���ԂŋN�������Ƃ���proxy�ݒ菈����2��
 * �����Ă��܂��s����C��
 * 
 * 2     07/12/13 19:00 Tsujimura543
 * �R�����g���C��
 * 
 * 1     07/12/13 18:51 Tsujimura543
 * proxy�֘A�̃v���g�^�C�v�錾�� chirrupDlg.h ���番���Ɨ�������
 */

#ifndef __PROXY_H__
#define __PROXY_H__

// proxy�ݒ�_�C�A���O���g�����ݒ�ύX
void    DoSettingProxy( CChirrupDlg *p );

// proxy�ݒ����V�K�ݒ肠�邢�͐ݒ�ύX����K�v�������(xmlRPC.dll ��
// �� http �ʐM�֘A�֐��Q����)���f���ꂽ�Ƃ��ɌĂяo�����(�Ăяo���Ă���
// ������)�֐�
int     confirmProxyInfo( int            *useProxy,
                          char           *proxyServer,
                          unsigned short *proxyPort,
                          char           *proxyUserName,
                          char           *proxyPassword );

#endif  /* __PROXY_H__ */
