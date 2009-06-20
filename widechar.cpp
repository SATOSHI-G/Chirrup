/*
 * widechar.cpp : Twitter �N���C�A���g chirrup
 *      ���������΍􃆁[�e�B���e�B�֐��Q
 *          written by H.Tsujimura  12 Dec 2007
 *
 *      Copyright (c) 2007, 2008 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      Some Rights Reserved.
 *
 *      UTF8ToUTF16() ��
 *          UTF8��UTF16�̕ϊ����@
 *              http://hpcgi1.nifty.com/MADIA/Vcbbs/wwwlng.cgi?print+200701/07010007.txt
 *              Blue 2007/01/04(��) 18:52:09
 *      �Ɍf�ڂ���Ă���R�[�h�𗬗p�����Ă��������Ă��܂�
 *
 * $Log: /comm/chirrup/widechar.cpp $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 13    08/12/04 18:19 Tsujimura543
 * �R�[�h�����A���艻��Ƃ����{
 * 
 * 12    08/01/11 20:54 Tsujimura543
 * �R�����g���C��
 * 
 * 11    08/01/11 20:53 Tsujimura543
 * candidate[] �ɓ���Ă��������������1�ǉ�
 * 
 * 10    08/01/07 14:44 Tsujimura543
 * candidate[] �ɓ���Ă��������������1�ǉ�
 * (�ɑ̎��g�p���̕��������΍�)
 * 
 * 9     07/12/26 22:23 Tsujimura543
 * candidate[] �ɓ���Ă��������������1�ǉ�
 * 
 * 8     07/12/26 20:50 Tsujimura543
 * candidate[] �ɓ���Ă��������������1�ǉ�
 * 
 * 7     07/12/20 17:22 Tsujimura543
 * candidate[] �ɓ���Ă�������������ɒǉ�
 * 
 * 6     07/12/19 22:09 Tsujimura543
 * candidate[] �ɓ���Ă��������������1�ǉ�
 * 
 * 5     07/12/19 21:33 Tsujimura543
 * candidate[] �ɓ���Ă���������ǉ�
 * 
 * 4     07/12/19 14:13 Tsujimura543
 * isExistLatin1() �����ǁB����m�F�ς�
 * 
 * 3     07/12/17 21:48 Tsujimura543
 * (1) isExistNonAlnum() �� isExistLatin1() �ɕύX
 * (2) UTF8ToUTF16() ���Ăяo��������ύX
 * 
 * 2     07/12/12 20:37 Tsujimura543
 * isExistNonAlnum() ��ǉ�
 * 
 * 1     07/12/12 19:39 Tsujimura543
 * �ŏ��̔�
 */

#include <afxwin.h>
#include <comdef.h>
#include "widechar.h"
extern "C" {
#include "utility.h"
}

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/chirrup/widechar.cpp 1     09/05/14 3:50 tsupo $";
#endif


BOOL
UTF8ToUTF16( const char*& data, const DWORD len, _bstr_t& text )
{
    BOOL result = FALSE;

    text = L"";

    if ( !data )
        return FALSE;
    if ( !len )
        return TRUE;

    const int wlen = ::MultiByteToWideChar( CP_UTF8, 0, data, len, NULL, 0 );
    if ( !wlen )
        return FALSE;

    WCHAR* buff = new WCHAR[wlen + 1];
    if ( ::MultiByteToWideChar( CP_UTF8, 0, data, len, buff, wlen ) ) {
        result = TRUE;
        buff[wlen] = L'\0';
        text = buff;
    }
    delete[] buff;

    return result;
}

static const char candidate[] =
	"�L�@�H�R�I�[�P�B���F�T���Y�S�A�M�G�C�U�X�K�@�������D�Q�C��";

bool
isExistLatin1( const char *s )
{
    bool                ret = false;
    const unsigned char *p  = (const unsigned char *)s;
    const char          *q;
    size_t              sz  = strlen("�L");

    if ( p ) {
        while ( *p ) {
            if ( *(p + 1) ) {
                for ( q = candidate; *q; q += sz ) {
                    if ( !strncmp( (const char *)p, (const char *)q, sz ) ) {
                        ret = true;
                        break;
                    }
                }

                if ( ret ) {
                    if ( p - 1 >= (const unsigned char *)s ) {
                        if ( *(p - 1) >= 0x80 )
                            ret = false;
                    }
                    if ( *(p + sz) ) {
                        if ( *(p + sz) >= 0x80 )
                            ret = false;
                    }

                    if ( ret )
                        break;  /* Latin-1 �����ł���\�������� */
                }
            }
            p++;
        }
    }

    if ( !ret && s ) {
        bool    kanji = false;

        p = (const unsigned char *)s;
        while ( *p ) {
            if ( !kanji ) {
                if ( iskanji1( *p ) ) {
                    if ( !strncmp( (const char *)p, "�", 2 ) ||
                         !strncmp( (const char *)p, "�", 2 ) ||
                         !strncmp( (const char *)p, "�", 2 )    ) {
                        ret = true; /* UTF-8 �� CP932 �ϊ����s�̉\������ */
                        break;
                    }
                    kanji = true;
                }
            }
            else {
                if ( kanji && !iskanji2( *p ) )
                    break;  /* ���������� */
                kanji = false;
            }

            p++;
        }

        if ( kanji )
            ret = true; /* ���������� */
    }

    return ( ret );
}

CString
RegulateCode(
    const char *orig, // (I) �Ώە����� (UTF-8)
    const char *conv  // (I) �Ώە������ iconv ���g���� CP932 �ɕϊ���������
  )        
{
    // �{���͕����������������Ă�ꍇ�����AUTF8ToUTF16() �ɂ��ϊ����ʂ��g��
    // �΂������A�@�B�I�Ɂu�����������������Ă��邩�ǂ����v�𔻒f����͓̂
    // ���̂ŁA�Ƃ肠�����ALatin-1 ���������݂���\���̂���ꍇ�AUTF-8 �� 
    // CP932 �̕ϊ��Ɏ��s���Ă���ꍇ�Ɋւ��āAUTF8ToUTF16() �ɂ��ϊ����ʂ�
    // �g���悤�ɂ��Ă���

    CString result = conv;

    if ( isExistLatin1( conv ) ) {
        const char  *str = orig;
        _bstr_t     bs;
        if ( UTF8ToUTF16( str, strlen( str ), bs ) ) {
            result = (const char *)bs;
        }
    }

    return ( result );
}
