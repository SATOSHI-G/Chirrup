/*
 * BrowserWindow.cpp : Twitter �N���C�A���g chirrup
 * $Log: /comm/chirrup/BrowserWindow.cpp $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 6     07/05/11 21:29 Tsujimura543
 * �u���E�U�ŉ{������ URL �� Twitter �ɑ��M����Ƃ��A���� Web �y�[�W��
 * �^�C�g�����擾���đ��M����悤�ɂ���
 * 
 * 5     07/04/25 15:20 Tsujimura543
 * �擾���� url �� https �Ŏn�܂�ꍇ�͋󕶎����Ԃ��悤�Ɏd�l��ύX
 * 
 * 4     07/04/25 11:54 Tsujimura543
 * (1) GetUrlByDDE() �̃o�O�C�� (���t�@�N�^�����O���̃~�X�ŃG���o�O���Ă���)
 * (2) GetUrlByDDE() ���̕s�v�Ȋ֐��Ăяo�����폜
 * 
 * 3     07/04/24 23:44 Tsujimura543
 * �C���f���g�C���A�s�v�ɂȂ����R�����g�̍폜
 * 
 * 2     07/04/24 23:42 Tsujimura543
 * ���t�@�N�^�����O
 * 
 * 1     07/04/24 23:38 Tsujimura543
 * GetUrlInBrowsing() �����Ғʂ蓮�삷�邱�Ƃ��m�F
 *
 * �ȉ��� URL �Ō��J����Ă���\�[�X�R�[�h�̂����A
 *      GetUrlByDDE()
 *      DdeCallback()
 * ��2�֐��𗬗p�����Ă��������Ă��܂�(�����ŏ����������Ă܂�)�B
 *
 *     http://www.hirax.net/misc/browser_window/BrowserWindow.h
 *     http://www.hirax.net/misc/browser_window/BrowserWindow.cpp
 */

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/chirrup/BrowserWindow.cpp 1     09/05/14 3:50 tsupo $";
#endif

#include "chirrup.h"
#include <ddeml.h>
extern "C" {
#include "utility.h"
}

//------------jun hirabayashi jun@hirax.net 2006/05/03------------------
#ifdef  _MSC_VER
#pragma warning ( disable: 4100 )
#endif
HDDEDATA CALLBACK DdeCallback(
                    UINT     uType,
                    UINT     uFmt,
                    HCONV    hconv,
                    HSZ      hsz1,
                    HSZ      hsz2,
                    HDDEDATA hdata,
                    DWORD    dwData1,
                    DWORD    dwData2 )
{
    HDDEDATA ret = NULL;

    switch ( uType ) {
    case XTYP_ADVDATA:
        ret = (HDDEDATA)DDE_FACK;
        break;
    }

    return ( ret );
}
#ifdef  _MSC_VER
#pragma warning ( default: 4100 )
#endif


//------�őO��Window�̏��X�V   --------------------
#define IE_STRING   " - Microsoft Internet Explorer"
#define IE7_STRING  " - Windows Internet Explorer"
#define SLEIPNIR    "Sleipnir - "
#define SLEIPNIR2   " - Sleipnir"
#define FIREFOX     " - Mozilla Firefox"
#define MOZILLA     " - Mozilla"
#define OPERA       " - Opera"
#define FLOCK       " - Flock"
#define NETSCAPE8   " - Netscape Browser"
#define NETSCAPE    " - Netscape"

//------DDE�o�R�Ŏ擾------------------------------------
bool GetUrlByDDE( CString browser, CString &URL )
{
    bool    ret    = false;
    DWORD   idInst = 0;
    UINT    result = DdeInitialize( &idInst, DdeCallback,
                                    APPCMD_CLIENTONLY, 0L );

    URL = _T("");
    if ( result == DMLERR_NO_ERROR ) {
        LPSTR   lpszApplication = browser.GetBuffer(0);
        LPSTR   lpszTopic       = "WWW_GetWindowInfo";
        HSZ     hszApplication  = DdeCreateStringHandle(
                                        idInst, lpszApplication, CP_WINANSI );
        HSZ     hszTopic        = DdeCreateStringHandle(
                                        idInst, lpszTopic, CP_WINANSI );
        HSZ     hszItem         = DdeCreateStringHandle(
                                        idInst, "-1", CP_WINANSI );

        if ( hszApplication && hszTopic && hszItem ) {
            HCONV hConv = DdeConnect(idInst, hszApplication, hszTopic, NULL);

            if ( hConv ) {
                HDDEDATA    hData   = DdeClientTransaction(
                                          NULL, 0, hConv, hszItem,
                                          CF_TEXT, XTYP_REQUEST, 1000, NULL );
                if ( hData ) {
                    char    *pStart = (char *)DdeAccessData( hData, NULL );

                    if ( pStart ) {
                        while ( *pStart++ != '"' )
                            ;
                        if ( *pStart ) {
                            char    *pEnd = pStart;
                            while ( *pEnd != '"' )
                                pEnd++;

                            *pEnd = NUL;
                            URL   = pStart;
                            ret   = true;
                        }
                    }
                }

                DdeDisconnect( hConv );
            }
        }

        if ( hszItem )
            DdeFreeStringHandle( idInst, hszItem );
        if ( hszTopic )
            DdeFreeStringHandle( idInst, hszTopic );
        if ( hszApplication )
            DdeFreeStringHandle( idInst, hszApplication );
        DdeUninitialize( idInst );
    }

    return ( ret );
}


CString GetUrlInBrowsing( CString &pageTitle )
{
#define MAX_TITLE_LEN   1024

    char    title[MAX_TITLE_LEN + 2];
 // char    temp[MAX_TITLE_LEN + 2];
    char    *p;
    CString browser = _T("");
    CString URL     = _T("");

    HWND    h = GetTopWindow( NULL );
    while ( h ) {
        title[0] = NUL;
     // temp[0]  = NUL;
        GetWindowText( h, title, MAX_TITLE_LEN );

        if ( title[0] ) {
            // �����̃u���E�U�𓯎��ɊJ���Ă���ꍇ��
            // �ŏ��ɔ��������u���E�U�𒲍��Ώۂɂ���
            if ( (( p = strstr( title, IE_STRING ) ) != NULL) ||
                 (( p = strstr( title, IE7_STRING )) != NULL)    ) {
                browser = "IEXPLORE";
             // strncpy( temp, title, p - title );
             // temp[p - title] = NUL;
                break;
            }
            if ( ( p = strstr( title, SLEIPNIR ) ) != NULL ) {
                browser = "Sleipnir";
             // strcpy( temp, p + strlen(SLEIPNIR) );
                break;
            }
            if ( ( p = strstr( title, SLEIPNIR2 ) ) != NULL ) {
                browser = "Sleipnir2";
             // strncpy( temp, title, p - title );
             // temp[p - title] = NUL;
                break;
            }
            if ( ( p = strstr( title, FIREFOX ) ) != NULL ) {
                browser = "Firefox";
             // strncpy( temp, title, p - title );
             // temp[p - title] = NUL;
                break;
            }
            if ( ( p = strstr( title, MOZILLA ) ) != NULL ) {
                browser = "Mozilla";
             // strncpy( temp, title, p - title );
             // temp[p - title] = NUL;
                break;
            }
            if ( ( p = strstr( title, OPERA ) ) != NULL ) {
                browser = "Opera";
             // strncpy( temp, title, p - title );
             // temp[p - title] = NUL;
                break;
            }
         // if ( ( p = strstr( title, FLOCK ) ) != NULL ) {
         //     browser = "FLOCK"; // "Flock"; // "flock";
         //     strncpy( temp, title, p - title );
         //     temp[p - title] = NUL;
         //     break;  // Flock �� GetUrlByDDE() �ł� URL �擾�͂ł��Ȃ�
         // }
            if ( (( p = strstr( title, NETSCAPE8) ) != NULL) || 
                 (( p = strstr( title, NETSCAPE ) ) != NULL)    ) {
                browser = "NETSCAPE";
             // strncpy( temp, title, p - title );
             // temp[p - title] = NUL;
                break;
            }
        }

        h = GetNextWindow( h, GW_HWNDNEXT );
    }

    if ( browser.GetLength() > 0 ) {
     // if ( temp[0] )          // �u���E�U�𕡐��N�����Ă���Ƃ��́A�����ŋ�
     //     pageTitle = temp;   // �߂� title �� GetUrlByDDE() �ŋ��߂� URL ��
                                // �Ή����� title ����v����Ƃ͌���Ȃ�
        GetUrlByDDE( browser, URL );
        if ( !strncmp( URL, "https", 5 ) )
            URL = _T("");   // https �Ŏn�܂�ꍇ�͎̂Ă�
        else
            pageTitle = getTitle( URL );
    }

    return ( URL );
}
