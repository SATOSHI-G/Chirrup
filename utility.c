/*
 * utility.c : Twitter �N���C�A���g chirrup
 *      �e�탆�[�e�B���e�B�֐��Q
 *          written by H.Tsujimura  4 Apr 2007
 *
 *      Copyright (c) 2007, 2008, 2009 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      Some Rights Reserved.
 *
 * $Log: /comm/chirrup/utility.c $
 * 
 * 2     09/05/31 20:42 tsupo
 * 1.142��
 * 
 * 24    09/05/27 19:35 Tsujimura543
 * setSigInfo() ���폜 (xmlRPC.dll �ֈڊ�)
 * 
 * 23    09/05/27 18:21 Tsujimura543
 * setSigInfo() �̈�����ǉ�
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 22    08/12/01 14:28 Tsujimura543
 * getTitle() ��2008�N11��25���́u�͂Ăȃu�b�N�}�[�N���j���[�A���v��
 * ���킹�čX�V
 * 
 * 21    08/03/26 22:16 Tsujimura543
 * http_get() �� __http_getBASIC() �ֈڍs
 * 
 * 20    08/02/14 22:41 Tsujimura543
 * replaceStringEx() ��ǉ�
 * 
 * 19    08/02/14 20:01 Tsujimura543
 * replaceString() ��ǉ�
 * 
 * 18    08/01/08 21:06 Tsujimura543
 * �R�����g���C��
 * 
 * 17    08/01/08 21:04 Tsujimura543
 * setSigInfo() ��ǉ�
 * 
 * 16    07/07/04 16:56 Tsujimura543
 * getDateTimeFromDateString() ���� _timezone �̒l������������̂�
 * ��߂�
 * 
 * 15    07/06/26 22:34 Tsujimura543
 * �R�����g���C��
 * 
 * 14    07/06/26 22:33 Tsujimura543
 * decodeNumericReference() ���C�� (���������ł́A�V���[�v�G���R�[�h���ʂ�
 * ������ ; ���t���Ȃ��p�^�[��������悤�ŁA; ���Ȃ��Ƃ��Ƀ������Q�ƃG���[
 * �ŗ����Ă��܂����߁A�΍��g�ݍ���)
 * 
 * 13    07/06/22 17:42 Tsujimura543
 * any2sjis() �� stack overflow �΍��ǉ�
 * 
 * 12    07/06/21 18:08 Tsujimura543
 * cutExtra() ��ǉ�
 * 
 * 11    07/06/20 14:05 Tsujimura543
 * getDateTimeFromDateString() �� Twitter �̃^�C���X�^���v�V�`����
 * �Ή�������
 * 
 * 10    07/06/07 3:27 Tsujimura543
 * ���O�t�@�C���̃^�C���X�^���v��9���Ԃ�������18���Ԃ����s����C��
 * 
 * 9     07/05/25 21:14 Tsujimura543
 * any2sjis() ���܂��܂��C��
 * 
 * 8     07/05/23 23:07 Tsujimura543
 * any2sjis() ������ɏC��
 * 
 * 7     07/05/22 22:42 Tsujimura543
 * �����������J�o���������C��
 * 
 * 6     07/05/22 21:03 Tsujimura543
 * Twitter �� API �̕Ԃ��^�C���X�^���v�̃t�H�[�}�b�g���ς�������߁A
 * �^�C���X�^���v�擾���������C
 * 
 * 5     07/05/11 21:27 Tsujimura543
 * normalizeDescription() �� getTitle() ��ǉ�
 * 
 * 4     07/04/27 16:37 Tsujimura543
 * �R�����g���C��
 * 
 * 3     07/04/24 23:48 Tsujimura543
 * CFriendDialog �������[�e�B���e�B�֐���ǉ� (�����͑��ł��g���\��)
 * 
 * 2     07/04/09 21:07 Tsujimura543
 * �N�H�[�e�[�V�����}�[�N���܂܂�锭�����������\������Ȃ��s��ɑΏ�
 * 
 * 1     07/04/05 2:06 Tsujimura543
 * �ŏ��̔�
 */

#include <time.h>
#include "xmlRPC.h"
#include "utility.h"
#include "http.h"

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/chirrup/utility.c 2     09/05/31 20:42 tsupo $";
#endif

#ifdef  _MSC_VER
#define Thread  __declspec( thread )
#else
#define Thread
#endif

/* Unicode(UCS-2BE) (%uXXXX) �� UTF-8 (xxyyzz) �ϊ� */
char    *
convUnicode( unsigned long code )
{
    unsigned short      a, b, c, d;
    Thread  static char codeStr[6];

    if ( code < 0x0080 ) {
        a = (unsigned short)code;
        codeStr[0] = (char)(a & 0xFF);
        codeStr[1] = NUL;
    }
    else if ( code < 0x0800 ) {
        a = (unsigned short)(((code & 0x07C0) >> 6) | 0xC0);
        b = (unsigned short)(( code & 0x003F)       | 0x80);
        codeStr[0] = (char)(a & 0xFF);
        codeStr[1] = (char)(b & 0xFF);
        codeStr[2] = NUL;
    }
    else if ( code < 0x010000 ) {
        a = (unsigned short)(((code & 0xF000) >> 12) | 0xE0);
        b = (unsigned short)(((code & 0x0FC0) >>  6) | 0x80);
        c = (unsigned short)(( code & 0x003F)        | 0x80);
        codeStr[0] = (char)(a & 0xFF);
        codeStr[1] = (char)(b & 0xFF);
        codeStr[2] = (char)(c & 0xFF);
        codeStr[3] = NUL;
    }
    else {
        a = (unsigned short)(((code & 0x001C0000) >> 18) | 0xF0);
        b = (unsigned short)(((code & 0x0003F000) >> 12) | 0x80);
        c = (unsigned short)(((code & 0x00000FC0) >>  6) | 0x80);
        d = (unsigned short)(( code & 0x0000003F)        | 0x80);
        codeStr[0] = (char)(a & 0xFF);
        codeStr[1] = (char)(b & 0xFF);
        codeStr[2] = (char)(c & 0xFF);
        codeStr[3] = (char)(d & 0xFF);
        codeStr[4] = NUL;
    }

    return ( codeStr );
}


char    *
decodeContents( char *contents )
{
    unsigned char   *p = (unsigned char *)contents;
    unsigned char   *q;
    char            *r;

    while ( p && *p ) {
        if ( *p != '\\' ) {
            p++;
            continue;
        }

        p++;
        switch ( *p ) {
     // case '"':
        case '/':
            strcpy( (char *)p - 1, (char *)p );
            break;

        case 'r':
            strcpy( (char *)p - 1, (char *)p );
            *(p - 1) = '\r';
            break;

        case 'n':
            strcpy( (char *)p - 1, (char *)p );
            *(p - 1) = '\n';
            break;

        case 'u':   /* UCS-2 */
            {
                char            *term;
                unsigned long   hex;
                char            tmp[8];

                p++;
                tmp[0] = *p++;
                tmp[1] = *p++;
                tmp[2] = *p++;
                tmp[3] = *p++;
                tmp[4] = NUL;
                hex = strtol( tmp, &term, 16 );
                term = (char *)p;
                q = (unsigned char *)convUnicode( hex );
                p -= 6;
                while ( *q )
                    *p++ = *q++;
                strcpy( (char *)p, term );
            }
            break;

        default:
            p++;
            break;
        }
    }

    while ( ( r = strstr( contents, "&amp;" ) ) != NULL )
        strcpy( r + 1, r + 5 );

    return ( contents );
}

char    *
decodeNumericReference( char *src )
{
    char    *p    = src;
    char    *q;
    char    *temp = (char *)malloc( strlen( src ) + 1 );

    if ( temp ) {
        unsigned long   l;

        temp[0] = NUL;
        while ( *p ) {
            if ( (*p == '&') && (*(p + 1) == '#') ) {
                l = atol( p + 2 );
                strcat( temp, convUnicode( l ) );
                q = strchr( p + 2, ';' );
                if ( !q )
                    strcat( src, ";" );
                p = strchr( p + 2, ';' ) + 1;
            }
            else {
                l = temp[0] ? strlen( temp ) : 0;
                temp[l]     = *p;
                temp[l + 1] = NUL;
                p++;
            }
        }
        strcpy( src, temp );

        free( temp );
    }

    return ( src );
}


time_t
getDateTimeFromDateString(
        const char *date,   /* (I) �������(������) */
        int        *yyyy,   /* (O) �N               */
        int        *mm,     /* (O) ��               */
        int        *dd,     /* (O) ��               */
        int        *HH,     /* (O) ��               */
        int        *MM,     /* (O) ��               */
        int        *SS      /* (O) �b               */
    )
{
    const char  *p = date;
    const char  *q;
    time_t      t = 0;
    struct tm   tm;
    int         i;
    int         dHH = 0, dMM = 0, d = 0;
    BOOL        found = FALSE;
    BOOL        json  = FALSE;
    static char monStr[12][4] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };

    *yyyy = 0;
    *mm   = 0;
    *dd   = 0;
    *HH   = 0;
    *MM   = 0;
    *SS   = 0;

    /* �܂��A�u�N�����v���������� */
    for ( i = 0; i < 12; i++ ) {
        q = strstr( p, monStr[i] );
        if ( q                                 &&
             (*(q - 1) == ' ')                 &&
             (*(q + strlen(monStr[i])) == ' ')    ) {
            found = TRUE;
            break;
        }
    }
    if ( found ) {
        /* RFC 822 �`���̓��t�̏ꍇ              */
        /*   ��) Tue, 20 May 2003 08:56:02 GMT   */
        /*       20 May 2003 08:56:02 GMT        */
        /*       Tue, 20 May 2003 17:56:02 JST   */
        /*       Tue, 20 May 2003 17:56:02 +0900 */
        /*       Tue, 20 May 2003 17:56:02+0900  */
        /*       Wed, 06 Dec 2006 14:54:02 +0900 */
        /*       Wed, 6 Dec 2006 14:54:02 +0900  */
        /* JSON �Ŏg���Ă�����t�̃t�H�[�}�b�g�͔����ɈႤ */
        /*   ��) Wed Apr 04 12:31:49 +0000 2007            */
        /*                                                 */
        /* + 2007�N6��20���� Twitter �̃^�C���X�^���v��    */
        /*   �t�H�[�}�b�g���ȉ��̂悤�Ȃ��̂ɕύX���ꂽ    */
        /*       Wed 20 Jun 04:44:12 +0000 2007            */
        while ( *p && ((*p < '0') || (*p > '9')) )
            p++;
        if ( (*p >= '0') && (*p <= '9') ) {
            *dd = *p - '0';
            p++;
            if ( (*p >= '0') && (*p <= '9') ) {
                *dd = *dd * 10 + (*p - '0');
                p++;
            }
        }

        while ( *p && ((*p == ' ') || (*p == '\t')) )
            p++;

        if ( (*p >= 'A') && (*p <= 'Z') ) {
            json = FALSE;
            while ( *p && ((*p < 'A') || (*p > 'Z')) )
                p++;
        }
        else if ( (*p >= '0') && (*p <= '9') )
            json = TRUE;

        *mm = i + 1;

        if ( !json ) {
            while ( *p && ((*p < '0') || (*p > '9')) )
                p++;
            if ( (*p >= '0') && (*p <= '9') ) {
                if ( *(p + 2) != ':' ) {
                    *yyyy = *p - '0';
                    p++;
                    if ( (*p >= '0') && (*p <= '9') ) {
                        *yyyy = *yyyy * 10 + (*p - '0');
                        p++;
                    }
                    if ( (*p >= '0') && (*p <= '9') ) {
                        *yyyy = *yyyy * 10 + (*p - '0');
                        p++;
                    }
                    if ( (*p >= '0') && (*p <= '9') ) {
                        *yyyy = *yyyy * 10 + (*p - '0');
                        p++;
                    }
                }
                else
                    json = TRUE;
            }

            if ( !json ) {
                while ( *p && ((*p < '0') || (*p > '9')) )
                    p++;
            }
        }
    }
    else {
        q = strstr( p, "/200" );        // 2006 �` 2009
        if ( !q )
            q = strstr( p, "/201" );    // 2010 �` 2019
        if ( q ) {
            // 05/22/2007 23:59:59 �`��

            while ( *p && ((*p < '0') || (*p > '9')) )
                p++;
            if ( (*p >= '0') && (*p <= '9') ) {
                *mm = *p - '0';
                p++;
                if ( (*p >= '0') && (*p <= '9') ) {
                    *mm = *mm * 10 + (*p - '0');
                    p++;
                }
            }

            while ( *p && ((*p < '0') || (*p > '9')) )
                p++;
            if ( (*p >= '0') && (*p <= '9') ) {
                *dd = *p - '0';
                p++;
                if ( (*p >= '0') && (*p <= '9') ) {
                    *dd = *dd * 10 + (*p - '0');
                    p++;
                }
            }

            while ( *p && ((*p < '0') || (*p > '9')) )
                p++;
            if ( (*p >= '0') && (*p <= '9') ) {
                *yyyy = *p - '0';
                p++;
                if ( (*p >= '0') && (*p <= '9') ) {
                    *yyyy = *yyyy * 10 + (*p - '0');
                    p++;
                }
                if ( (*p >= '0') && (*p <= '9') ) {
                    *yyyy = *yyyy * 10 + (*p - '0');
                    p++;
                }
                if ( (*p >= '0') && (*p <= '9') ) {
                    *yyyy = *yyyy * 10 + (*p - '0');
                    p++;
                }
            }
        }
        else {
     // q = strchr( p, 'T' );
     // if ( q &&
     //      (*(q - 1) >= '0') && (*(q - 1) <= '9') &&
     //      (*(q + 1) >= '0') && (*(q + 1) <= '9')    ) {
            /* ISO8601 �`���̓��t�̏ꍇ      */
            /* ��) 2003-12-03T23:59:59+09:00 */
            /*     2003-12-03T23:59:59Z      */
            while ( *p && ((*p < '0') || (*p > '9')) )
                p++;
            if ( (*p >= '0') && (*p <= '9') ) {
                *yyyy = *p - '0';
                p++;
                if ( (*p >= '0') && (*p <= '9') ) {
                    *yyyy = *yyyy * 10 + (*p - '0');
                    p++;
                }
                if ( (*p >= '0') && (*p <= '9') ) {
                    *yyyy = *yyyy * 10 + (*p - '0');
                    p++;
                }
                if ( (*p >= '0') && (*p <= '9') ) {
                    *yyyy = *yyyy * 10 + (*p - '0');
                    p++;
                }
            }

            while ( *p && ((*p < '0') || (*p > '9')) )
                p++;
            if ( (*p >= '0') && (*p <= '9') ) {
                *mm = *p - '0';
                p++;
                if ( (*p >= '0') && (*p <= '9') ) {
                    *mm = *mm * 10 + (*p - '0');
                    p++;
                }
            }

            while ( *p && ((*p < '0') || (*p > '9')) )
                p++;
            if ( (*p >= '0') && (*p <= '9') ) {
                *dd = *p - '0';
                p++;
                if ( (*p >= '0') && (*p <= '9') ) {
                    *dd = *dd * 10 + (*p - '0');
                    p++;
                }
            }
        }
    //  else {
    //      /* ����ȊO�̌`���̏ꍇ */
    //  }
    }

    /* ���ɁA�u�����b�v���������� */
    while ( *p && ((*p < '0') || (*p > '9')) )
        p++;
    if ( (*p >= '0') && (*p <= '9') ) {
        *HH = *p - '0';
        p++;
        if ( (*p >= '0') && (*p <= '9') ) {
            *HH = *HH * 10 + (*p - '0');
            p++;
        }
    }

    while ( *p && ((*p < '0') || (*p > '9')) )
        p++;
    if ( (*p >= '0') && (*p <= '9') ) {
        *MM = *p - '0';
        p++;
        if ( (*p >= '0') && (*p <= '9') ) {
            *MM = *MM * 10 + (*p - '0');
            p++;
        }
    }

    while ( *p                         &&
            ((*p < '0') || (*p > '9')) &&
            (*p != '-')                &&
            (*p != '+')                &&
            ((*p < 'A') || (*p > 'Z'))    )
        p++;
    if ( (*p >= '0') && (*p <= '9') ) {
        *SS = *p - '0';
        p++;
        if ( (*p >= '0') && (*p <= '9') ) {
            *SS = *SS * 10 + (*p - '0');
            p++;
        }
    }

    while ( *p ) {
        /* �uUTC �Ƃ̎����v���������� */
        if ( (*p == 'Z')             ||
             !strncmp( p, "GMT", 3 ) ||
             !strncmp( p, "UTC", 3 )    ) {
            d   = 1;
            dHH = 0;
            dMM = 0;
            break;  // UTC(�Ȃ̂ŁA���ɏ�������K�v�͂Ȃ�)
        }
        else if ( (*p == '-') || (*p == '+') ) {
            /* +09:00 �� +0900 ��2�p�^�[��(':'�̗L��)���� */
            d = (*p == '-') ? -1 : 1;
            while ( *p && ((*p < '0') || (*p > '9')) )
                p++;
            if ( (*p >= '0') && (*p <= '9') ) {
                dHH = *p - '0';
                p++;
                if ( (*p >= '0') && (*p <= '9') ) {
                    dHH = dHH * 10 + (*p - '0');
                    p++;
                }
            }

            while ( *p && ((*p < '0') || (*p > '9')) )
                p++;
            if ( (*p >= '0') && (*p <= '9') ) {
                dMM = *p - '0';
                p++;
                if ( (*p >= '0') && (*p <= '9') ) {
                    dMM = dMM * 10 + (*p - '0');
                    p++;
                }
            }
            break;
        }
        else if ( ((*p == ' ') || (*p == '\t')) )
            ;
        else {
            // ���[�J������(���̃v���O�����𓮂����Ă���PC�̃^�C���]�[�����̗p)
            //  -- �{���́A�T�[�o�ݒu�ꏊ�̃��[�J�����Ԃ��̗p����K�v������
#ifdef  WIN32
            if ( _timezone != 0 ) {
                long    tDiff = _timezone;
                d = (tDiff > 0 ) ? 1 : -1;
                if ( d == -1 )
                    tDiff *= d;
                dHH = (tDiff / 60) / 60;
                dMM = (tDiff / 60) % 60;
            }
#else
            /* JST �� GMT (�Ƃ肠�����A���{�ȊO�ł��̃v���O�������g���l�� */
            /*             ���Ƃ͖Y���) [�b��]                           */
            d   = 1;
            dHH = 9;
            dMM = 0;
#endif
        }
        p++;
    }

    if ( json ) {
        while ( *p && ((*p < '0') || (*p > '9')) )
            p++;
        if ( (*p >= '0') && (*p <= '9') ) {
            *yyyy = *p - '0';
            p++;
            if ( (*p >= '0') && (*p <= '9') ) {
                *yyyy = *yyyy * 10 + (*p - '0');
                p++;
            }
            if ( (*p >= '0') && (*p <= '9') ) {
                *yyyy = *yyyy * 10 + (*p - '0');
                p++;
            }
            if ( (*p >= '0') && (*p <= '9') ) {
                *yyyy = *yyyy * 10 + (*p - '0');
                p++;
            }
        }
    }

    if ( *yyyy > 2000 ) {    
        struct tm   *m;

        tm.tm_year = *yyyy - 1900;
        tm.tm_mon  = *mm   - 1;
        tm.tm_mday = *dd;
        tm.tm_hour = *HH;
        tm.tm_min  = *MM;
        tm.tm_sec  = *SS;

        t = timelocal( &tm );
        if ( d != 0 )
            t -= (dHH * 60 + dMM) * 60 * d; // UTC
#ifdef  USE_UTC
        m = gmtime( &t );       // UTC �̂܂ܕێ�
#else
        if ( (d == 0) && (dHH == 0) && (dMM == 0) )
            m = gmtime( &t );
        else
            m = localtime( &t );    // ���[�J�����Ԃɕϊ����ĕێ�
#endif
        *yyyy = m->tm_year + 1900;
        *mm   = m->tm_mon  + 1;
        *dd   = m->tm_mday;
        *HH   = m->tm_hour;
        *MM   = m->tm_min;
        *SS   = m->tm_sec;
    }

    return ( t );
}


char    *
encodeDateTime( const char *str )
{
    static char timeStr[80];
    const char  *p = str;
    char        *q;

    q = timeStr;
    while ( *p ) {
        if ( *p == ',' ) {
            *q++ = '%';
            *q++ = '2';
            *q   = 'C';
        }
        else if ( *p == ':' ) {
            *q++ = '%';
            *q++ = '3';
            *q   = 'A';
        }
        else if ( *p == ' ' )
            *q = '+';
        else
            *q = *p;
        p++;
        q++;
    }
    *q = NUL;

    return ( timeStr );
}


char    *
getLastStatus( const char *screenName, char *lastStatus )
{
    char    url[MAX_URLLENGTH];
    char    *p, *q;
    char    *response;
    size_t  sz = MAX_DESCRIPTION_LEN;

    sprintf( url,
             "http://api.twittervision.com/user/current_status/%s.xml",
              screenName );

    response = (char *)malloc( sz );
    if ( response ) {
        setUpReceiveBuffer( response, sz );
     // http_get( url, response );
        __http_getBASIC( url, NULL, NULL, response, NULL );
        if ( *response ) {
            p = strstr( response, "<last-status>" );
            if ( p ) {
                p += 13;
                q = strstr( p, "<text>" );
                if ( q ) {
                    p = q + 6;
                    q = strstr( p, "</text>" );
                    if ( q ) {
                        strncpy( lastStatus, p, q - p );
                        lastStatus[q - p] = NUL;

                        decodeNumericReference( lastStatus );
                        p = any2sjis( lastStatus );
                        if ( p )
                            strcpy( lastStatus, p );
                    }
                }
            }
        }

        free( response );
    }

    return ( lastStatus );
}

char    *addCarriageReturn( char *str, int loc )
{
    char    *p = str;
    char    *temp;
    int     len = strlen( str );

    temp = (char *)malloc( len + (len / loc) * 2 + 2 );
    if ( temp ) {
        char    *q    = temp;
        int     cnt   = 0;
        BOOL    kanji = FALSE;

        while ( *p ) {
            if ( !kanji ) {
                if ( cnt >= loc ) {
                    *q++ = '\r';
                    *q++ = '\n';
                    cnt = 0;
                }

                if ( iskanji1( (unsigned char)(*p) ) ) {
                    kanji = TRUE;
                }

                *q++ = *p++;
            }
            else {
                kanji = FALSE;

                *q++ = *p++;
                if ( cnt >= loc ) {
                    *q++ = '\r';
                    *q++ = '\n';
                    cnt = 0;
                }
            }

            cnt++;
        }

        *q = NUL;
        strcpy( str, temp );
        free( temp );
    }

    return ( str );
}

char    *
any2sjis( const char *p )
{
    char                *q, *r, *s;
    Thread  static long depth = 0;;

    depth++;
    if ( depth >= 20 ) {
        // stack overflow �ŗ�����̂�}������
        depth--;
        return ( "???" );
    }

    q = utf2sjis( p );
    if ( !q ) {
        // p �� charset �� UTF-8 �ł͂Ȃ�
        if ( strstr( p, "\033$@" ) || strstr( p, "\033$B" ) )
            q = jis2sjis( p );
        else {
            q = euc2sjis( p );
            if ( !q ) {
                r = (char *)p;
                while ( (*r == ' ')  || (*r == '\t') ||
                        (*r == '\r') || (*r == '\n')    )
                    r++;
                s = strchr( r, ' ' );
                if ( !s )
                    s = strchr( r, '\t' );
                if ( !s )
                    s = strchr( r, '\r' );
                if ( !s )
                    s = strchr( r, '\n' );
                if ( !s )
                    q = utf2sjisEx( (char *)p );
                else {
                    size_t  sz1 = (s - r);
                    size_t  sz2 = strlen( s );
                    char    *temp1 = (char *)malloc( sz1 * 16 );
                    char    *temp2 = (char *)malloc( sz2 * 16 );
                    if ( temp1 ) {
                        char    *pp;

                        strncpy( temp1, r, sz1 );
                        temp1[sz1] = NUL;
                        pp = any2sjis( temp1 );
                        if ( !pp )
                            pp = "...";
                        else {
                            char    *temp11 = (char *)malloc(strlen(pp) + 1);
                            if ( temp11 ) {
                                strcpy( temp11, pp );
                                free( temp1 );
                                pp = temp1 = temp11;
                            }
                            else
                                pp = "...";
                        }

                        if ( temp2 ) {
                            char    *qq;

                            strcpy( temp2, s );
                            qq = any2sjis( temp2 );
                            if ( !qq )
                                qq = "...";

                            strcpy( (char *)p, pp  );
                            strcat( (char *)p, " " );
                            strcat( (char *)p, qq  );

                            free( temp2 );
                        }
                        else
                            strcpy( (char *)p, pp  );
                        free( temp1 );
                    }
                    q = (char *)p;
                }
            }
        }
    }
    depth--;

    return ( q );
}


#define MAX_DESCRIPTION_LENGTH  160

char *
normalizeDescription( char *description, size_t length )
{
    size_t  max_len1 = MAX_DESCRIPTION_LENGTH;
    size_t  max_len2 = (max_len1 / 3) * 2;

    if ( length > 0 ) {
        max_len1 = (length * 3 / 2);
        max_len2 = length;
    }

    if ( strlen( description ) > max_len2 ) {
        char    *s = description;
        int     kanjiFlag = 0;
        size_t  i = 0;

        while ( *s ) {
            if ( ++i > max_len2 )
                break;
            if ( kanjiFlag == 0 ) {
                if ( iskanji1( *s ) )
                    kanjiFlag = 1;
            }
            else
                kanjiFlag = ((kanjiFlag + 1) % 3);
            *s++;
        }
        switch ( kanjiFlag ) {
        case 0:
            *s = NUL;
            break;
        case 1:
            *(s - 1) = NUL;
            break;
        case 2:
            *(s - 2) = NUL;
            break;
        }

        strcat( description, "..." );
    }

    return ( description );
}


#define BUFFER_SIZE_FOR_GETTITLE    2048

char    *
encodeURLforHatena( const char *url )
{
    Thread  static char url2[BUFFER_SIZE_FOR_GETTITLE];
    char                *p;
    char                *q;

    strcpy( url2, url );
    while ( (p = strchr( url2, '#' )) != NULL ) {
        q = &url2[strlen(url2)];
        while ( q >= p + 1 ) {
            *(q + 2) = *q;
            q--;
        }
        *p++ = '%';
        *p++ = '2';
        *p   = '3';
    }

    return ( url2 );
}

char    *
getTitle(const char *url )
{
    Thread  static char title[BUFFER_SIZE_FOR_GETTITLE];
    char                title2[BUFFER_SIZE_FOR_GETTITLE];
    char                url2[BUFFER_SIZE_FOR_GETTITLE];
    char                *response;
    char                *p, *q;
    BOOL                useHatenaBookmark = FALSE;
    size_t              sz;

    title[0]  = NUL;
    title2[0] = NUL;

    sz = MAX_CONTENT_SIZE;
    response = (char *)malloc( sz );
    if ( !response )
        return ( title );

    sprintf( url2, "http://b.hatena.ne.jp/entry/%s",
             encodeURLforHatena( url ) );

    setUpReceiveBuffer( response, sz );
 // http_get( url2, response );
    __http_getBASIC( url2, NULL, NULL, response, NULL );
    if ( response && response[0] ) {
        if ( !strstr( response,
                      sjis2utf( "���u�b�N�}�[�N�G���g���[") ) ) {
            p = strstr( response, "<title>" );
            if ( p ) {
                char    *q = strstr( p, " - " );
                if ( q ) {
                    p = q + 3;
                    q = strstr( p, "</" );
                    if ( q ) {
                        strncpy( title2, p, q - p );
                        title2[q - p] = NUL;
                    }
                }
                
                p = title2;
                while ( ( q = strstr( p, "&lt;" ) ) != NULL ) {
                    *q = '<';
                    strcpy( q + 1, q + 4 );
                }
                while ( ( q = strstr( p, "&gt;" ) ) != NULL ) {
                    *q = '>';
                    strcpy( q + 1, q + 4 );
                }
                while ( ( q = strstr( p, "&quot;" ) ) != NULL ) {
                    *q = '"';
                    strcpy( q + 1, q + 6 );
                }
                while ( ( q = strstr( p, "&amp;" ) ) != NULL )
                    strcpy( q + 1, q + 5 );
                while ( ( q = strstr( p, "&#" ) ) != NULL ) {
                    char    *r;
                    long    l;

                    q += 2;
                    r = strchr( q, ';' );
                    if ( !r ) {
                        r = strstr( q, "&#" );
                        if ( !r )
                            break;
                        p = r;
                        continue;
                    }

                    l = atol( q );
                    if ( (l >= ' ') && (l < 0x80) ) {
                        q -= 2;
                        *q = (char)l;
                        strcpy( q + 1, r + 1 );
                        p = q + 1;
                    }
                    else
                        p = r + 1;
                }

                if (!strcmp(title2, sjis2utf("���݃����e�i���X���ł��B") ) ||
                    !strcmp(title2, sjis2utf("Service Not Available")    )   )
                    title2[0] = NUL;
            }

            if ( title2[0] )
                useHatenaBookmark = TRUE;
        }
    }

    setUpReceiveBuffer( response, sz );
 // http_get( url, response );
    __http_getBASIC( url, NULL, NULL, response, NULL );

    if ( response && response[0] ) {
        p = strstr( response, "<title>" );
        if ( !p )
            p = strstr( response, "<title " );
        if ( !p )
            p = strstr( response, "<TITLE>" );
        if ( !p )
            p = strstr( response, "<TITLE " );
        if ( !p )
            p = strstr( response, "<h1>" );
        if ( !p )
            p = strstr( response, "<h1 " );
        if ( !p )
            p = strstr( response, "<H1>" );
        if ( !p )
            p = strstr( response, "<H1 " );
        if ( p ) {
            p++;
            p = strchr( p, '>' );
            p++;
            q = strstr( p + 1, "</" );
            if ( q ) {
                strncpy( title, p, q - p );
                title[q - p] = NUL;

                while ( ( ( p = strchr( title, '\r' ) ) != NULL ) ||
                        ( ( p = strchr( title, '\n' ) ) != NULL )    )
                    strcpy( p, p + 1 );
            }
        }

        if ( title2[0] != NUL )
            strcpy( title, title2 );

        /* asahi.com �΍� #1 */
        while ( ( p = strstr( title, "&#160;" ) ) != NULL ) {
            *p++ = ' ';
            strcpy( p, p + 5 );
        }

        /* asahi.com �΍� #2 */
        if ( ( p = strstr( title, "\xEF\xBF\xBD-\xEF\xBF\xBD" ) ) != NULL ) {
            strcpy( p, " - " );
            strcpy( p + 3, p + 7 );
        }
    }

    if ( !(title[0]) && title2[0] )
        strcpy( title, title2 );

    if ( strstr( response, "charset=UTF-8" ) ||
         strstr( response, "charset=utf-8" ) ||
         useHatenaBookmark                      )
        p = utf2sjisEx( title );
    else if ( strstr( response, "charset=Shift_JIS" ) ||
              strstr( response, "charset=shift_jis" )    )
        p = title;
    else
        p = utf2sjis( title );
    if ( p ) {
        strcpy( title, p );
        if ( strstr( p, "\033$@" ) || strstr( p, "\033$B" ) ) {
            q = jis2sjis( title );
            if ( q )
                strcpy( title, q );
        }
    }
    else {
        q = NULL;
        if ( strstr( response, "charset=iso-8859-1" ) ||
             strstr( response, "charset=ISO-8859-1" )    ) {
            for ( p = title; *p; p++ ) {
                if ( (unsigned char)(*p & 0xFF) >= 0xA0 ) {
                    q = iso8859_1toUtf8( title );
                    if ( q )
                        p = decodeURL( q ); // utf8 �� us-ascii �ϊ������˂�
                    break;
                }
            }
        }

        if ( !q )
            p = euc2sjis( title );
        if ( p )
            strcpy( title, p );
    }
    free( response );

    p = title;
    while ( *p ) {
        if ( (*p == '\t') || (*p == '\r') || (*p == '\n' ) )
            *p = ' ';
        p++;
    }

    p = title;
    while ( *p ) {
        while ( (*p == ' ') && (*(p + 1) == ' ') )
            strcpy( p, p + 1);
        p++;
    }

    p = title;
    while ( *p == ' ' )
        strcpy( p, p + 1);

    if ( *p ) {
        p = &(title[strlen(title) - 1]);
        while ( *p == ' ' )
            *p-- = NUL;
    }
    while ( ( p = strstr( title, "&raquo;" ) ) != NULL ) {
        strncpy( p, "��", 2 );
        strcpy( p + 2, p + 7 );
    }
    while ( ( p = strstr( title, "&laquo;" ) ) != NULL ) {
        strncpy( p, "��", 2 );
        strcpy( p + 2, p + 7 );
    }

    return ( title );
}

char    *
cutExtra( char *s )
{
    char    *p = &(s[strlen(s) - 1]);
    while ( (p >= s) &&
            ((*p == ' ') || (*p == '\t') || (*p == '\n') || (*p == '\r')) )
        *p-- = NUL;

    return ( s );
}

/* �w�蕶�����ʂ̎w�蕶����ɒu������ */
BOOL
replaceString( char *target, const char *src, const char *dst )
{
    char    *p = target;
    char    *q;
    BOOL    ret = FALSE;
    int     len = strlen( dst );

    while ( ( q = strstr( p, src ) ) != NULL ) {
        char    *temp;
        int     l = strlen( src );

        temp = (char *)malloc( strlen( p ) - l + strlen( dst ) + 1 );
        if ( temp ) {
            strncpy( temp, p, q - p );
            strcpy( &(temp[q - p]), dst );
            strcat( temp, q + l );

            strcpy( p, temp );
            free( temp );
            ret = TRUE;

            p = q + len;
        }
        else
            break;
    }

    return ( ret );
}

BOOL
replaceStringEx( char *target )
{
    const char  *src = "<";
    const char  *dst = "&lt;";
    char        *p = target;
    char        *q;
    BOOL        ret = FALSE;
    int         len = strlen( dst );

    while ( ( q = strstr( p, src ) ) != NULL ) {
        if ( ((*(q + 1) >= 'a') && (*(q + 1) <= 'z')) ||
             ((*(q + 1) >= 'A') && (*(q + 1) <= 'Z')) ||
             (*(q + 1) == '/')                           ) {
            p = q + 1;
            continue;
        }
        else {
            char    *temp;
            int     l = strlen( src );

            temp = (char *)malloc( strlen( p ) - l + strlen( dst ) + 1 );
            if ( temp ) {
                strncpy( temp, p, q - p );
                strcpy( &(temp[q - p]), dst );
                strcat( temp, q + l );

                strcpy( p, temp );
                free( temp );
                ret = TRUE;

                p = q + len;
            }
            else
                break;
        }
    }

    return ( ret );
}
