/*
 * utility.h  : Twitter �N���C�A���g chirrup
 *      �e�탆�[�e�B���e�B�֐��Q �w�b�_�[�t�@�C��
 *          written by H.Tsujimura  4 Apr 2007
 *
 *      Copyright (c) 2007, 2008, 2009 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/utility.h $
 * 
 * 2     09/05/31 20:42 tsupo
 * 1.142��
 * 
 * 12    09/05/27 19:35 Tsujimura543
 * setSigInfo() ���폜 (xmlRPC.dll �ֈڊ�)
 * 
 * 11    09/05/27 18:21 Tsujimura543
 * setSigInfo() �̈�����ǉ�
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 10    08/02/14 22:41 Tsujimura543
 * replaceStringEx() ��ǉ�
 * 
 * 9     08/02/14 20:01 Tsujimura543
 * replaceString() ��ǉ�
 * 
 * 8     08/01/08 21:06 Tsujimura543
 * �R�����g���C��
 * 
 * 7     08/01/08 21:04 Tsujimura543
 * setSigInfo() ��ǉ�
 * 
 * 6     07/11/08 23:52 Tsujimura543
 * any2utf() �̃v���g�^�C�v�錾��ǉ�
 * 
 * 5     07/06/21 18:08 Tsujimura543
 * cutExtra() ��ǉ�
 * 
 * 4     07/05/11 21:27 Tsujimura543
 * normalizeDescription() �� getTitle() ��ǉ�
 * 
 * 3     07/04/27 16:37 Tsujimura543
 * �R�����g���C��
 * 
 * 2     07/04/24 23:48 Tsujimura543
 * CFriendDialog �������[�e�B���e�B�֐���ǉ� (�����͑��ł��g���\��)
 * 
 * 1     07/04/05 2:06 Tsujimura543
 * �ŏ��̔�
 */

#ifndef __UTILITY_H__
#define __UTILITY_H__

char    *
convUnicode( unsigned long code );

char    *
decodeContents( char *contents );

char    *
decodeNumericReference( char *src );

char    *
any2sjis( const char *p );

char    *
cutExtra( char *s );

time_t
getDateTimeFromDateString(
        const char *date,   /* (I) �������(������) */
        int        *yyyy,   /* (O) �N               */
        int        *mm,     /* (O) ��               */
        int        *dd,     /* (O) ��               */
        int        *HH,     /* (O) ��               */
        int        *MM,     /* (O) ��               */
        int        *SS      /* (O) �b               */
    );

time_t
timelocal( struct tm *tm );

char    *
encodeDateTime( const char *str );

char    *
getLastStatus( const char *screenName, char *lastStatus );

char    *
addCarriageReturn( char *str, int loc );

char *
normalizeDescription( char *description, size_t length );

char    *
getTitle(const char *url );

char    *
any2utf( const char *p );

BOOL
replaceString( char *target, const char *src, const char *dst );

BOOL
replaceStringEx( char *target );

#ifndef	iskanji1
#define	iskanji1(s)	((((s)>=0x81) && ((s)<=0x9f)) || \
			 (((s)>=0xe0) && ((s)<=0xfc)))
#endif
#ifndef	iskanji2
#define	iskanji2(s)	((((s)>=0x40) && ((s)<=0x7e)) || \
			 (((s)>=0x80) && ((s)<=0xfc)))
#endif

#endif  /* __UTILITY_H__ */
