/*
 * CImage.cpp : Twitter �N���C�A���g chirrup
 *      CImage �N���X�̒�`
 *          written by H.Tsujimura  23 Feb 2007 / 5 Apr 2007
 *
 * $Log: /comm/chirrup/CImage.cpp $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 9     08/07/08 14:41 Tsujimura543
 * �L���b�V���̗L�����Ԃ𔻒肷��̂Ɏg���t�@�C���̃^�C���X�^���v��
 * st_ctime ���� st_mtime �ɕύX
 * 
 * 8     08/01/07 15:19 Tsujimura543
 * HttpOpen() �����t�@�N�^�����O
 * 
 * 7     07/12/17 18:46 Tsujimura543
 * ConvertImageFile(), SaveBmpFile(), SavePngFile() ��ǉ�
 * 
 * 6     07/12/14 16:07 Tsujimura543
 * http_get() �� _http_get() �ɒu��
 * 
 * 5     07/06/07 20:17 Tsujimura543
 * malloc/free �� new/delete �ɒu��������
 * 
 * 4     07/05/25 18:19 Tsujimura543
 * �L���b�V���̗L�����Ԃ�1���Ԃɂ��Ă݂��B�O��̎擾����1���Ԉȏ�o��
 * �����t�@�C���͎擾������(�T�[�o���d�����Ŏ擾���s�����ꍇ�́A������
 * ���A���܂ł̃t�@�C�����g��)
 * 
 * 3     07/05/22 22:41 Tsujimura543
 * proxy �֘A�̐ݒ�擾�E�ύX����������\���̂��鏈���� CImage
 * �̒��ł͎g��Ȃ��悤�ɂ���
 * 
 * 2     07/04/13 23:27 Tsujimura543
 * CImage::HttpOpen() ���C���A�L���b�V���ɉ摜�t�@�C�������݂���΁A
 * Web�A�N�Z�X�����ɁA�L���b�V�����g���悤�ɂ���
 * 
 * 1     07/04/13 23:01 Tsujimura543
 * �摜��\������@�\���������邽�߁AWeb �Ō��J����Ă���R�[�h����荞��
 */

/*
 * �ŏ��́A
 *    http://www.dinop.com/vc/read_jpeg_idg.html
 * ���Q�l�ɁAlibjpeg �𗘗p���� jpg �摜���r�b�g�}�b�v�ɕϊ����鏈����
 * �������悤�Ƃ��Ă������A����
 *    http://hp.vector.co.jp/authors/VA007941/program/no2124.html
 * ������ OleLoadPictureFile() ���g�����ƂŁAjpg �ȊO�� gif �ɂ��Ή���
 * ���邱�Ƃ������Blibjpeg ���g���̂͂�߂āAOleLoadPictureFile() ���g
 * �����Ƃɂ����B
 *
 * ����ɁApng �Ɋւ��Ă� OleLoadPictureFile() �ł͑Ή��ł��Ȃ��̂ŁA
 * libpng (+ zlib) ���g�����Ƃɂ����Blibpng ���g���ɂ������āA
 *    http://cetus.sakura.ne.jp/softlab/software/b2psrc.html
 * �� png2bmp �̃\�[�X�R�[�h
 *    png2bmp/bmphed.h
 *    png2bmp/common.h
 *    png2bmp/common.c
 *    png2bmp/png2bmp.c
 * ���قƂ�ǂ��̂܂ܗ��p�����Ă��������Ă��� (png2bmp() ��ǉ�����ȂǁA
 * �����A�����ł������Ă���)
 */

#include <afx.h>
#include "CImage.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <afxctl.h>
#include <sys/stat.h>
#include "ProceedingDialog.h"

extern "C" {
#include "xmlRPC.h"
int png2bmp( const char *inpfile, const char *outfile );
}

char    *
_http_get( const char       *url,
           char             *response,
           ProceedingDialog *pdlg );

BOOL
saveBmp( const char *filename, HBITMAP hBitmap );

BOOL
savePNG( const char *fileName, HBITMAP hBitmap );


#ifndef	lint
static char	*rcs_id =
"$Header: /comm/chirrup/CImage.cpp 1     09/05/14 3:50 tsupo $";
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

HBITMAP CImage::LoadImageFile( CString csFileName )
{
    HBITMAP hBmp = LoadBmpFile( csFileName );

    if ( !hBmp )
        hBmp = LoadPngFile( csFileName );

    return ( hBmp );
}

HBITMAP CImage::LoadBmpFile( CString csFileName )
{
    // �l�^��: http://hp.vector.co.jp/authors/VA007941/program/no2124.html
    // bmp, jpg, gif �ɂ͑Ή����Ă��邪 png �� tif �ɂ͑Ή����Ă��Ȃ�
    // �� png �� CImage::LoadPngFile() �ɂđΉ��Btif �͍���͑Ή����Ȃ�
    //    ���Ƃɂ���
	LPDISPATCH	    pDispatch;
	COleVariant	    oleFileName(csFileName);	
	OLE_HANDLE	    holeHandle;
	short		    type;
	CPictureHolder	PictureHolder;
    HBITMAP         hBmp = NULL;

	// �摜�t�@�C�������[�h
	if ( OleLoadPictureFile( oleFileName, &pDispatch ) >= 0 ) {		
		PictureHolder.SetPictureDispatch( (LPPICTUREDISP)pDispatch );	
		if ( PictureHolder.m_pPict != NULL ) {
			PictureHolder.m_pPict->get_Type( &type );
			if ((type == PICTYPE_BITMAP)                                &&
                (PictureHolder.m_pPict->get_Handle( &holeHandle ) >= 0)   ) {
                hBmp = (HBITMAP)holeHandle;
			}
		}
	}

	return ( hBmp );
}

HBITMAP CImage::LoadPngFile( CString filename )
{
    /* png �͈ȉ��̏����őΉ� */
    // libjpeg �̓G���[����������� abort() �����Ⴄ�̂ŁA���炩���߁A
    // ���̃t�@�C���� png �t�@�C�����ǂ����`�F�b�N���Ă���Ăяo���悤
    // �ɂ��Ă��� (�擪��8�o�C�g�� PNG �Ƌ��R�����t�@�C�������݂����
    // �\���͂��邯�ǁA���̏ꍇ�� abort() �����Ⴂ�܂�)
    HBITMAP hBmp  = NULL;
    bool    isPNG = false;
    FILE    *fp   = fopen( filename, "rb" );

    // ���Y�t�@�C���̃t�H�[�}�b�g�� PNG ���ǂ����`�F�b�N���APNG ��������
    // libpng �𗘗p���ăr�b�g�}�b�v�𐶐�
    if ( fp ) {
        unsigned char   buf[BUFSIZ];
        fread( buf, 1, BUFSIZ, fp );
        fclose( fp );

        if ( (buf[0] == 0x89) &&
             (buf[1] == 'P')  &&
             (buf[2] == 'N')  &&
             (buf[3] == 'G')  &&
             (buf[4] == 0x0D) &&
             (buf[5] == 0x0A) &&
             (buf[6] == 0x1A) &&
             (buf[7] == 0x0A)    )
            isPNG = true;
    }

    if ( isPNG ) {
        char    tempFileName[BUFSIZ];
        char    *p;

        strcpy( tempFileName, filename );
        p = strrchr( tempFileName, '.' );
        strcpy( p + 1, "bmp" );
        png2bmp( filename, tempFileName );
        hBmp = LoadBmpFile( tempFileName );
    }

	return ( hBmp );
}


bool    CImage::ConvertImageFile( CString srcFilename, CString bmpFilename )
{
    bool    ret = false;

    // GIF, JPEG, PNG �`���̃t�@�C���� BMP �`���̃t�@�C���ɕϊ�����
    HBITMAP bitmap = LoadImageFile( srcFilename );
    if ( bitmap )
        ret = SaveBmpFile( bmpFilename, bitmap );

    return ( ret );
}

bool    CImage::SaveBmpFile( CString filename, HBITMAP bitmap )
{
    bool    ret = false;
    BOOL    res = saveBmp( filename, bitmap );

    ret = res ? true : false;

    return ( ret );
}

bool    CImage::SavePngFile( CString filename, HBITMAP bitmap )
{
    bool    ret = false;
    BOOL    res = savePNG( filename, bitmap );

    ret = res ? true : false;

    return ( ret );
}


HBITMAP CImage::SimpleOpen( CString filename )
{
    // �w�肳�ꂽ�t�@�C�����̉摜�t�@�C����ǂ݁A�r�b�g�}�b�v�𐶐�����
    return LoadImageFile( filename );
}

HBITMAP CImage::HttpOpen( CString url, CString filename /* = _T("") */ )
{
    bool    cached = false;

    // ���ł� filename �Ŏw�肳�ꂽ�摜�t�@�C�������݂���΁A���̃t�@�C��
    // ��\������ (Web�A�N�Z�X�͂��Ȃ�)
    if ( filename.GetLength() > 0 ) {
        struct stat s;
        if ( !stat( filename, &s ) ) {
            time_t  t = time( NULL );
            if ( t - s.st_mtime < 60 * 60 )
                return ( LoadImageFile( filename ) );

            cached = true;  // �V�����A�C�R���̎擾�Ɏ��s�����ꍇ�́A����
                            // �����A�L���b�V���ς݃A�C�R����K�p����
        }
    }

    // �w�肳�ꂽ URL �̉摜�t�@�C����ǂ݁A�r�b�g�}�b�v�𐶐�����
    char    *response;
    size_t  sz  = 65536 * 256;
    HBITMAP ret = NULL;

    response = new char[sz];
    if ( !response )
        return ret;

    setUpReceiveBuffer( response, sz );
    _http_get( url, response, NULL );
    if ( *response ) {
        size_t  sz = getBinSize();
        if ( sz > 0 ) {
            CString fileName = "tmp.img";
            if ( filename.GetLength() > 0 )
                fileName = filename;

            FILE    *fp = fopen( fileName, "wb" );
            if ( fp ) {
                fwrite( response, sz, 1, fp );
                fclose( fp );

                ret = LoadImageFile( fileName );
                if ( filename.GetLength() == 0 )
                    unlink( fileName );
            }
        }
    }
    else if ( cached )
        ret = LoadImageFile( filename );

    delete [] response;
    encodeURL( NULL );

    return ret;
}
