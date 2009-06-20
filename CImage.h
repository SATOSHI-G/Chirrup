/*
 * CImage.h  : Twitter �N���C�A���g chirrup
 *      CImage �N���X�̒�`
 *          written by H.Tsujimura  4 Apr 2007
 *
 *      Copyright (c) 2007 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/CImage.h $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 3     07/12/17 18:46 Tsujimura543
 * ConvertImageFile(), SaveBmpFile(), SavePngFile() ��ǉ�
 * 
 * 2     07/09/06 19:42 Tsujimura543
 * �_�~�[�̃R�s�[�R���X�g���N�^�A������Z�q�� private �Ƃ��ē����B
 * �m��Ȃ������Ƀ������m��(�Ɖ�����Y��)����������\����r���B
 * 
 * 1     07/04/13 23:01 Tsujimura543
 * �摜��\������@�\���������邽�߁AWeb �Ō��J����Ă���R�[�h����荞��
 */

#if !defined(AFX_CJIMAGE_H__A07B8677_638F_45CA_8C84_9324D00DA47B__INCLUDED_)
#define AFX_CJIMAGE_H__A07B8677_638F_45CA_8C84_9324D00DA47B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"

class CImage
{
public:
    CImage() {}

    HBITMAP LoadImageFile( CString filename );

    HBITMAP LoadBmpFile( CString filename );
    HBITMAP LoadPngFile( CString filename );
	HBITMAP SimpleOpen( CString filename );
    HBITMAP HttpOpen( CString url, CString filename = _T("") );

    bool    ConvertImageFile( CString srcFilename, CString bmpFilename );
    bool    SaveBmpFile( CString filename, HBITMAP bitmap );
    bool    SavePngFile( CString filename, HBITMAP bitmap );

private:
    HBITMAP LoadPngFileEx( const char *filename );
    CImage( CImage &img );
    CImage  operator = ( CImage &img );
};

#endif // !defined(AFX_CJIMAGE_H__A07B8677_638F_45CA_8C84_9324D00DA47B__INCLUDED_)
