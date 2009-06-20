/*
 * ChannelWassr.cpp : Wassr �N���C�A���g chirrup
 *      �Q�����̃`�����l���ꗗ�\��(Wassr) �C���v�������e�[�V���� �t�@�C��
 *          written by H.Tsujimura  1 Aug 2008
 *
 *      Copyright (c) 2008 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/ChannelWassr.cpp $
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 1     08/08/02 3:40 Tsujimura543
 * �V�K�쐬 (���̂Ƃ���A�P�Ɉꗗ�\�����邾���̋@�\�����Ȃ�)
 */

#include "chirrup.h"
#include "wassr.h"
#include "ChannelWassr.h"

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/chirrup/ChannelWassr.cpp 1     09/05/14 3:50 tsupo $";
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChannelWassr �_�C�A���O

CChannelWassr::CChannelWassr(CWnd* pParent /*=NULL*/)
	: CDialog(CChannelWassr::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChannelWassr)
	//}}AFX_DATA_INIT

    m_numOfChannels = 0;
    m_numOfColumns  = CHNLLST_NUM_OF_COLUMNS;

    m_columnLabel[0] = _T("�A�C�R��");
    m_columnLabel[1] = _T("�`�����l����");

    m_columnFmt[0] = LVCFMT_LEFT;
    m_columnFmt[1] = LVCFMT_LEFT;

    m_columnWidth[0] = 300;
    m_columnWidth[1] = 300;
}

CChannelWassr::~CChannelWassr()
{
    if ( m_numOfChannels > 0 ) {
        for ( int i = m_numOfChannels - 1; i >= 0; i-- ) {
            IMAGEINFO   img;

            m_imglst.GetImageInfo( i, &img );
            if ( img.hbmImage )
                DeleteObject( img.hbmImage );
            if ( img.hbmMask )
                DeleteObject( img.hbmMask );
            m_imglst.Remove(i);
        }
        m_imglst.DeleteImageList();
    }
}

void CChannelWassr::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChannelWassr)
	DDX_Control(pDX, IDC_LIST, m_listCtr);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CChannelWassr, CDialog)
	//{{AFX_MSG_MAP(CChannelWassr)
	ON_WM_SHOWWINDOW()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChannelWassr ���b�Z�[�W �n���h��

void CChannelWassr::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
	LV_COLUMN lvc;
    int i, j;

	lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_IMAGE | LVCF_SUBITEM;
	for ( i = 0; i < CHNLLST_NUM_OF_COLUMNS; i++ ) {
		lvc.iSubItem = i;
		lvc.pszText  = m_columnLabel[i];
		lvc.cx       = m_columnWidth[i];
		lvc.fmt      = m_columnFmt[i];
		m_listCtr.InsertColumn( i, &lvc );
	}

    LV_ITEM lvi;

    m_listCtr.SetExtendedStyle(
        m_listCtr.GetExtendedStyle() | LVS_EX_SUBITEMIMAGES ); 

    m_imglst.Create( 64, 64, ILC_COLOR8 | ILC_MASK, m_numOfChannels, 2 );

    CImage  image;
    HBITMAP bm;
	for ( i = 0; i < m_numOfChannels; i++ ) {
        bm = image.HttpOpen( m_wassrChannelList[i].image_url );
        if ( bm )
            m_imglst.Add( CBitmap::FromHandle(bm), RGB(0,0,0) );
    }
    m_listCtr.SetImageList( &m_imglst, LVSIL_SMALL );

	for ( i = 0; i < m_numOfChannels; i++ ) {
		lvi.mask      = LVIF_IMAGE | LVIF_TEXT | LVIF_STATE;
		lvi.iItem     = i;
		lvi.iSubItem  = 0;
        lvi.pszText   = _T("");
		lvi.iImage    = i;
		lvi.stateMask = LVIS_STATEIMAGEMASK;
		lvi.state     = INDEXTOSTATEIMAGEMASK(1);

		m_listCtr.InsertItem(&lvi);
        j = 0;

	    // �A�C�R��
        m_listCtr.SetItem( i, j, LVIF_IMAGE | LVIF_TEXT,
                           m_wassrChannelList[i].name_en,
                           i, 0, 0, 0 );
        j++;

        // �`�����l����
        m_listCtr.SetItemText( i, j, m_wassrChannelList[i].title );
        j++;
    }

    m_listCtr.SetExtendedStyle(
        m_listCtr.GetExtendedStyle() |
        LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES |
        LVS_EX_CHECKBOXES | LVCFMT_BITMAP_ON_RIGHT );
}
