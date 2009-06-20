/*
 * proxy.cpp : Twitter �N���C�A���g chirrup
 *      �v���N�V�ݒ�֘A �C���v�������e�[�V���� �t�@�C��
 *          written by H.Tsujimura  26 Nov 2007 / 13 Dec 2007
 *
 *      Copyright (c) 2007 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/proxy.cpp $
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
 * 1     07/12/13 18:52 Tsujimura543
 * proxy�֘A�̊֐��Q�� chirrupDlg.cpp ���番���Ɨ�������
 */

#include "chirrup.h"
#include "chirrupDlg.h"
#include "SettingDialog.h"
#include "proxy.h"

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/chirrup/proxy.cpp 1     09/05/14 3:50 tsupo $";
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// proxy�֘A

#define FILE_CONFIG_PROXY   "./proxy.txt"

void
initProxyInfo()
{
    unlink( FILE_CONFIG_PROXY );
}

bool
checkProxyInfo()
{
    bool    ret = isNecessaryToCheckProxyInfo() ? true : false;

    if ( ret )
        initProxyInfo();

    return ( ret );
}

void DoSettingProxy( CChirrupDlg *p ) 
{
    CChirrupApp *ap = (CChirrupApp *)AfxGetApp();
    setConfirmProxyInfoFunc( (CONF_FUNC)(-1) );
    int r = MessageBox( NULL,
                        "proxy�T�[�o�o�R�ŃC���^�[�l�b�g��"
                        "���p���Ă��܂���?",
                        "�C���^�[�l�b�g���p�`�Ԋm�F",
                        MB_YESNO|MB_ICONQUESTION );

    if ( r == IDYES ) {
        CSettingDialog  dlg;
        dlg.m_settingProxy = true;
		dlg.m_chirrup      = p;

        dlg.DoModal();
        if ( ap->m_isUsedProxy ) {
            FILE    *fp;
            if ( ( fp = fopen( FILE_CONFIG_PROXY, "w" ) ) != NULL ) {
                fprintf( fp, "%s\n", (const char *)ap->m_proxyServer );
                fprintf( fp, "%d\n", ap->m_proxyPort );

                if ( ap->m_proxyUserName.GetLength() > 0 ) {
                    fprintf( fp, "%s\n", (const char *)ap->m_proxyUserName );

                    if ( ap->m_proxyPassword.GetLength() > 0 )
                        fprintf( fp, "%s\n",
                                 (const char *)ap->m_proxyPassword );
                }
                fclose( fp );
            }
        }
        else
            initProxyInfo();
    }
    else
        ap->m_isUsedProxy = false;
}

int confirmProxyInfo( int            *useProxy,
                      char           *proxyServer,
                      unsigned short *proxyPort,
                      char           *proxyUserName,
                      char           *proxyPassword )
{
    int         ret = TRUE;
    CChirrupApp *ap = (CChirrupApp *)AfxGetApp();

    DoSettingProxy( ap->m_chirrpDlg );

    *useProxy = ap->m_isUsedProxy;
    if ( ap->m_proxyServer.GetLength() > 0 )
        strcpy( proxyServer, ap->m_proxyServer );
    else
        *proxyServer = NUL;

    *proxyPort = (unsigned short)(ap->m_proxyPort);

    if ( ap->m_proxyUserName.GetLength() > 0 )
        strcpy( proxyUserName, ap->m_proxyUserName );
    else
        *proxyUserName = NUL;

    if ( ap->m_proxyPassword.GetLength() > 0 )
        strcpy( proxyPassword, ap->m_proxyPassword );
    else
        *proxyPassword = NUL;

    return ( ret );
}
