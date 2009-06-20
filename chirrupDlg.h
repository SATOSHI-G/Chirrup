/*
 * chirrupDlg.h  : Twitter �N���C�A���g chirrup
 *      ���C���_�C�A���O �w�b�_�[�t�@�C��
 *          written by H.Tsujimura  4 Apr 2007
 *
 *      Copyright (c) 2007, 2008, 2009 by H.Tsujimura (tsupo@na.rim.or.jp)
 *      All Rights Reserved.
 *
 * $Log: /comm/chirrup/chirrupDlg.h $
 * 
 * 2     09/05/31 20:42 tsupo
 * 1.142��
 * 
 * 111   09/05/29 19:22 Tsujimura543
 * ����A�J�E���g�ŕ��� tumbleblog ���J�݂��Ă���ꍇ�̓��e��
 * tumbleblog ���w�肵�Ă̓��e���\�ɂ���
 * 
 * 1     09/05/14 3:50 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 110   09/04/28 20:52 Tsujimura543
 * �^�C���A�E�g�擾�������K�莞�ԓ��ɏI���Ȃ��ꍇ�̏�����ύX
 * (�X���b�h�����I�������ł͂Ȃ��A�C�x���g�ʒm�������̗p)
 * 
 * 109   09/04/22 21:11 Tsujimura543
 * �u�ݒ�v�_�C�A���O�����Flickr�F�؂̃A�N�Z�X�g�[�N��(frob)���擾�ł���
 * �悤�ɂ���
 * 
 * 108   09/04/16 17:09 Tsujimura543
 * �u�ݒ�v�_�C�A���O�N�����́A�^�C�}���荞�ݔ����ɂ��u�X�V�v����
 * (�^�C�����C���̎擾)�����s���Ȃ��悤�ɂ���
 * 
 * 107   09/04/15 1:17 Tsujimura543
 * Jaiuku �� OAuth �Ή�����
 * 
 * 106   09/03/31 21:27 Tsujimura543
 * Twitter �� OAuth �Ή����� ����5
 * 
 * 105   09/03/30 22:37 Tsujimura543
 * Twitter �� OAuth �Ή����� ����2
 * 
 * 104   09/03/09 21:43 Tsujimura543
 * �^�C�����C���擾�X���b�h�Ď������Ɂu�^�C�����C���擾�X���b�h��
 * �������[�v�������΍�v�����Ă݂�
 * 
 * 103   08/12/22 20:54 Tsujimura543
 * �u���߂����[�v�Ή�
 * 
 * 102   08/08/22 18:42 Tsujimura543
 * �u�͂Ăȃn�C�N�v�Ή�
 * 
 * 101   08/08/01 2:40 Tsujimura543
 * (1) Wassr �ւ̉摜�̓��e�ɑΉ�
 * (2) �u�`�����l���v�Ή�����
 * 
 * 100   08/07/16 4:13 Tsujimura543
 * �u�������e�Ώہv�̐ݒ���u�ݒ�v�_�C�A���O�ł��ݒ�ł���悤�ɂ���
 * 
 * 99    08/07/16 1:20 Tsujimura543
 * �^�X�N�g���C�풓�@�\������
 * 
 * 98    08/07/14 14:59 Tsujimura543
 * Twitter �́uAPI�������擾API�v���Ăԉ񐔁A�^�C�~���O�𒲐���������
 * 
 * 97    08/03/26 22:15 Tsujimura543
 * Firefox ����̉摜�h���b�O�Ή� (��������C�x���g�n���h�����甲����)
 * 
 * 96    08/02/27 20:16 Tsujimura543
 * �u�������[��SNS�x�ǁv�̃A�C�R����ǉ�
 * 
 * 95    08/01/31 18:50 Tsujimura543
 * ���[�U�A�C�R��(�v���t�B�[���A�C�R��)�̍X�V�@�\�� on/off �ł���悤��
 * ���Ă݂�
 * 
 * 94    08/01/28 18:40 Tsujimura543
 * �E�B���h�E�T�C�Y��ۑ��A�����ł���悤�ɂ��Ă݂�
 * 
 * 93    08/01/24 15:29 Tsujimura543
 * Gyazo, Flickr, �͂Ăȃt�H�g���C�t�̊e�A�C�R����ǉ�
 * 
 * 92    08/01/24 14:55 Tsujimura543
 * CUploadImageDialog �̉摜�������e�Ώې�w��@�\�ɑΉ�
 * 
 * 91    08/01/19 0:33 Tsujimura543
 * �͂Ăȃt�H�g���C�t�Ή�����
 * 
 * 90    08/01/17 19:01 Tsujimura543
 * ���C���_�C�A���O���]�����������(�c������)�������ł���悤�ɂ��Ă݂�
 * 
 * 89    08/01/09 22:27 Tsujimura543
 * Flickr �Ή���ƁA�Ƃ肠�����I�� (����m�F����)
 * 
 * 88    08/01/09 17:10 Tsujimura543
 * Flickr �Ή����� ����2
 * 
 * 87    08/01/08 21:07 Tsujimura543
 * flickr �Ή�����
 * 
 * 86    07/12/19 16:34 Tsujimura543
 * Tumblr �� Gyazo �ɃA�b�v���[�h�����t�@�C���� URL ���L�^����@�\��
 * �ǉ�
 * 
 * 85    07/12/19 16:12 Tsujimura543
 * Tumblr �� Gyazo �ɃA�b�v���[�h�����t�@�C���� URL ���L�^����@�\��
 * �ǉ����邽�߂̃v���p�e�B��ǉ�
 * 
 * 84    07/12/15 6:29 Tsujimura543
 * SwitchCapture() ��ǉ�
 * 
 * 83    07/12/15 5:15 Tsujimura543
 * �L���v�`���[�@�\��������
 * 
 * 82    07/12/15 2:54 Tsujimura543
 * �L���v�`���[�@�\�A�������� (�܂��A���s���뒆)
 * 
 * 81    07/12/14 16:44 Tsujimura543
 * DeleteHtmlTags() ��ǉ�
 * 
 * 80    07/12/13 22:26 Tsujimura543
 * �摜�̃A�b�v���[�h���������ύX(�͂Ă�Fotolife�Ή������Abmp�t�@�C����
 * ��)
 * 
 * 79    07/12/13 18:40 Tsujimura543
 * proxy�֘A�̃v���g�^�C�v�錾�� proxy.h �Ƃ��ĕ����Ɨ�������
 * 
 * 78    07/12/13 18:04 Tsujimura543
 * [�b��] WM_HOTKEY �𗘗p���ăz�b�g�L�[(�V���[�g�J�b�g�L�[)��g�ݍ�
 *        ��ł݂�e�X�g
 *   �� �q�E�B���h�E�ɂ������p����Ă��܂����߁A���̂܂܂ł͎g���Ȃ�
 * 
 * 77    07/12/10 22:39 Tsujimura543
 * �X���b�h�ԒʐM�p�\���̂̒�`�� paramForThread.h �Ƃ��ĕ����Ɨ�������
 * 
 * 76    07/12/10 16:39 Tsujimura543
 * Gyazo �ւ̓��e�����֘A�� fix
 * 
 * 75    07/12/06 4:08 Tsujimura543
 * tumblr �ւ̉摜�t�@�C���A�b�v���[�h������ʃX���b�h������
 * 
 * 74    07/12/06 1:59 Tsujimura543
 * tumblr �ւ̉摜�̓��e�ɑΉ�
 * 
 * 73    07/11/26 21:44 Tsujimura543
 * �u�ӂ��ڂ����[�v�� tumblr �̃A�C�R����ǉ�
 * 
 * 72    07/11/26 20:23 Tsujimura543
 * proxy�ݒ�֘A�A�ُ�n����
 * 
 * 71    07/11/26 18:04 Tsujimura543
 * proxy�ݒ�֘A�ڍs��ƁA����
 * 
 * 70    07/11/26 18:03 Tsujimura543
 * OnSettingProxy() �� DoSettingProxy() �Ɉڍs
 * 
 * 69    07/11/26 17:57 Tsujimura543
 * CProxyInfoDialog ��p�~���ACSettingProxy �Ɉڍs
 * 
 * 68    07/11/07 3:39 Tsujimura543
 * ���Ă��锭���� ���p���� Tumblr �֓��e����@�\���쐬
 * 
 * 67    07/09/27 19:49 Tsujimura543
 * ShowFavorites() ��ǉ�
 * 
 * 66    07/09/14 17:52 Tsujimura543
 * �X�e�[�^�X�o�[�Ƀ��b�Z�[�W��\���ł���悤�ɂ���
 * 
 * 65    07/09/12 21:38 Tsujimura543
 * SetAddrOnMonologue() �𓱓��A���t�@�N�^�����O�����{
 * 
 * 64    07/09/06 19:42 Tsujimura543
 * �_�~�[�̃R�s�[�R���X�g���N�^�A������Z�q�� private �Ƃ��ē����B
 * �m��Ȃ������Ƀ������m��(�Ɖ�����Y��)����������\����r���B
 * 
 * 63    07/08/28 17:04 Tsujimura543
 * �\�[�X�R�[�h���̃R�����g�𐮗�
 * 
 * 62    07/08/28 17:02 Tsujimura543
 * (1) DisplayContextMenuForServices() �� DisplayContextMenuForFriends()
 *     ��ǉ����AOnContextMenu() �𐮗�
 * (2) SetStaticEdge() ��ǉ�
 * 
 * 61    07/08/28 0:37 Tsujimura543
 * (1) ReduceExtra() �𓱓�
 * (2) ���������\�[�X����
 * 
 * 60    07/08/25 0:16 Tsujimura543
 * �u�������v�ɑΉ� (�ݒ�֌W)
 * 
 * 59    07/08/13 18:25 Tsujimura543
 * DisplayProfImages() ������Ăяo���A�C�R���`�揈����ʃX���b�h���ł���
 * �悤�ɂ��Ă݂�
 * 
 * 58    07/08/13 12:06 Tsujimura543
 * �uPowered by �T�[�r�X���v�̕\��������悤�ɂ���
 * 
 * 57    07/07/03 18:35 Tsujimura543
 * Haru.fm �̃A�C�R����ݒu
 * 
 * 56    07/06/27 18:13 Tsujimura543
 * haru.fm �ɑΉ�
 * 
 * 55    07/06/25 21:12 Tsujimura543
 * �C���N���[�h�t�@�C���̃C���N���[�h������ύX
 * 
 * 54    07/06/23 0:40 Tsujimura543
 * SwitchTimelineFacilities() �𓱓�
 * 
 * 53    07/06/22 23:06 Tsujimura543
 * UpdateSingle() [�����Ȃ�] ��ǉ�
 * 
 * 52    07/06/22 19:19 Tsujimura543
 * �u�����v���e�������A���Y�T�[�r�X�݂̂�Ώۂ� timeline ���擾����悤
 * �ɂ��Ă݂�
 * 
 * 51    07/06/21 14:43 Tsujimura543
 * OnSetfocusMonologue() �����̏����� RichEditEx.cpp �Ɉړ��B
 * OnSetfocusMonologue() �͍폜�B
 * 
 * 50    07/06/20 15:48 Tsujimura543
 * InitTimelineInfo() ��p�~
 * 
 * 49    07/06/20 14:07 Tsujimura543
 * Timelog �Ή���
 * 
 * 48    07/06/20 5:19 Tsujimura543
 * (1) Twitter �� CTwitterManager ��K�p
 * (2) ���[�U�A�C�R���̉E�N���b�N���j���[�Ɂu�֘AWeb�y�[�W��\���v��ǉ�
 * 
 * 47    07/06/20 1:56 Tsujimura543
 * Jaiku �� CJaikuManager ��K�p
 * 
 * 46    07/06/20 0:31 Tsujimura543
 * Wassr �ɂ� CManager ��K�p
 * 
 * 45    07/06/19 23:12 Tsujimura543
 * (1) CManeger �𓱓����A�Ƃ肠�����u���������v�ɓK�p������m�F�����Ă݂�
 * (2) CService �����ɔ����C�������{
 * 
 * 44    07/06/15 0:07 Tsujimura543
 * timeline �̐؂�ւ����A�K�v�ɉ����āA�u���������v�̃X�N���[����
 * �擾�������Ăяo���悤�ɂ���
 * 
 * 43    07/06/14 21:12 Tsujimura543
 * �u���������v�ɑΉ�
 * 
 * 42    07/06/14 17:55 Tsujimura543
 * Wassr �ɑΉ�
 * 
 * 41    07/06/13 19:18 Tsujimura543
 * Twitter �� Replies �̉{���A���O�o�͂ɑΉ�
 * 
 * 40    07/06/13 1:27 Tsujimura543
 * (1) �_�C�A���O�ɕ\������o�[�W�����ԍ��������\�[�X�t�@�C������
 *     �E���Ă���悤�ɂ���
 * (2) �X�N���[�����̕\���� Twitter �Œ肩��ATwitter/Jaiku�؂�ւ�
 *     �\���ł���悤�ɂ���
 * (3) �ݒ�t�@�C�����܂��Ȃ��Ƃ��̋N���������𐮗��A����
 * 
 * 39    07/06/13 0:12 Tsujimura543
 * (1) TIMELINE_INFO �֘A fix
 * (2) �����ݒ�t�@�C���ǂݏ�����V�������O�t�@�C���Ǘ��d�l�ɑΉ�������
 * 
 * 38    07/06/11 19:58 Tsujimura543
 * Twitter �� Jaiku �ւ̓������e���T�|�[�g
 * 
 * 37    07/06/11 18:39 Tsujimura543
 * Twitter �� user_timeline �̉{�����T�|�[�g
 * 
 * 36    07/06/07 14:12 Tsujimura543
 * �R�����g���C��
 * 
 * 35    07/06/07 14:11 Tsujimura543
 * �ݒ�t�@�C����L���b�V���t�@�C����u���f�B���N�g���̃f�t�H���g�l��
 * �u�J�����g�f�B���N�g���v��������uchirrup�N�����_�̃J�����g�f�B���N
 * �g���v�����ɕύX
 * 
 * 34    07/06/07 1:44 Tsujimura543
 * friends_timeline �ȊO�̃^�C�����C�������O�ɏ����o����悤�ɂ���
 * 
 * 33    07/06/06 22:21 Tsujimura543
 * ���O�t�@�C���̏����o���@�\�T�|�[�g�ɔ����e��C�������{
 * 
 * 32    07/06/06 16:27 Tsujimura543
 * �������e�������ʃX���b�h�����Ă݂�
 * 
 * 31    07/06/05 20:32 Tsujimura543
 * Twitter/Jaiku �� timeline �̎擾�����S�ɕʃX���b�h�����Ă݂�
 * 
 * 30    07/06/05 17:33 Tsujimura543
 * Jaiku �A�C�R����ǉ�
 * 
 * 29    07/06/05 17:06 Tsujimura543
 * RURL �@�\�p�~�A�_�C�A���O�f�U�C���ύX
 * 
 * 28    07/06/05 14:44 Tsujimura543
 * PostMonologue() �������C�A�����Ȃ�Ƃ����ׂ����炷�悤�ɂ��Ă݂�
 * 
 * 27    07/06/04 21:11 Tsujimura543
 * friend �� add �� remove ������ (for Twitter)
 * 
 * 26    07/05/29 12:48 Tsujimura543
 * Jaiku �� friends_timeline �Ή�(�r��)
 * 
 * 25    07/05/29 6:39 Tsujimura543
 * Twitter �̃c���f����Ԕ���@�\(�ȈՔ�)������
 * 
 * 24    07/05/29 5:13 Tsujimura543
 * Jaiku �� user_timeline �̉{���ɑΉ�
 * 
 * 23    07/05/29 3:56 Tsujimura543
 * Jaiku (�� public_timeline �̉{��) �ɑΉ�
 * 
 * 22    07/05/25 20:15 Tsujimura543
 * CTwitterTimeline �N���X�֘A�̋L�q��ʂ̃t�@�C���ɕ����A�Ɨ�������
 * 
 * 21    07/05/25 17:51 Tsujimura543
 * OnSelchangeComboTimelineType() �����ǁA�u���� timeline �̐؂�ւ���
 * �ł���悤�ɂ���
 * 
 * 20    07/05/23 22:25 Tsujimura543
 * friends_timeline �� public_timeline �̕\���ؑ֋@�\��ǉ�
 * 
 * 19    07/05/11 22:40 Tsujimura543
 * �������͒��Ɂu�X�V�v+�u�{������Web�y�[�W���e�v���������ꍇ�ł��A
 * ���͒��̔������e�������Ȃ��悤�ɑΏ�
 * 
 * 18    07/05/11 21:29 Tsujimura543
 * �u���E�U�ŉ{������ URL �� Twitter �ɑ��M����Ƃ��A���� Web �y�[�W��
 * �^�C�g�����擾���đ��M����悤�ɂ���
 * 
 * 17    07/04/28 0:23 Tsujimura543
 * OnSetfocusMonologue() ��ǉ�
 * 
 * 16    07/04/27 22:28 Tsujimura543
 * �v���N�V�֘A�̐ݒ��ێ����郁���o�[�� CChirrupApp �Ɉړ�
 * 
 * 15    07/04/27 19:39 Tsujimura543
 * Twitter API �֘A�̏����� Twitter.cpp �ɏW�񂵂��̂ɔ����C�������{
 * 
 * 14    07/04/26 20:21 Tsujimura543
 * URL ���N���b�J�u���ɂ��Ă݂�
 * 
 * 13    07/04/26 0:22 Tsujimura543
 * �_�C���N�g���b�Z�[�W�{���@�\������
 * 
 * 12    07/04/25 20:39 Tsujimura543
 * ���C���_�C�A���O���c�����Ƀ��T�C�Y�ł���悤�ɂ��Ă݂�
 * 
 * 11    07/04/24 23:49 Tsujimura543
 * �u���E�U�ŉ{������ URL �𑗐M����@�\������
 * 
 * 10    07/04/14 3:01 Tsujimura543
 * proxy�֘A�̏������ďC��
 * 
 * 9     07/04/14 2:05 Tsujimura543
 * �E�N���b�N���j���[��ǉ�
 * 
 * 8     07/04/13 23:19 Tsujimura543
 * friends �摜�\���@�\��t���� (�܂��A�\���̂�)
 * 
 * 7     07/04/09 21:07 Tsujimura543
 * �s���� MAX_NUMOFSTATUS �𒴂���Ƃ���ŗ����Ă��܂��s��ɑΏ�
 * 
 * 6     07/04/07 0:51 Tsujimura543
 * �R�[�h�𐮗�
 * 
 * 5     07/04/07 0:45 Tsujimura543
 * ���^�[���L�[����������ƁAchirrup ���I�����Ă��܂��Ă����̂��A�I������
 * ���悤�ɂ���(���^�[���L�[�̋�ł��͖�������悤�ɂ���)
 * 
 * 4     07/04/06 23:42 Tsujimura543
 * (1) Twitter �ɑ��M���� http ���N�G�X�g�̃w�b�_�� X-Twitter-Client: ����
 *     �t������悤�ɂ��� (�N���C�A���g���XML ��
 *       http://watcher.moe-nifty.com/memo/files/chirrup.xml
 *     �ɐݒu)
 * (2) �v���L�V�T�[�o�����蓮�Őݒ�ł���悤�ɂ���
 * (3) �{�^���������ς��t���Ă݂�
 * 
 * 3     07/04/05 3:03 Tsujimura543
 * �b��I�Ɏg���Ă����}�W�b�N�i���o�[�������Ƃ����l�ɂ���
 * 
 * 2     07/04/05 2:51 Tsujimura543
 * �X�V������ύX�ł���悤�ɂ���
 * 
 * 1     07/04/05 2:06 Tsujimura543
 * �ŏ��̔�
 */

#if !defined(AFX_CHIRRUPDLG_H__5843E218_092A_47EB_AA1F_F176B490916A__INCLUDED_)
#define AFX_CHIRRUPDLG_H__5843E218_092A_47EB_AA1F_F176B490916A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CImage.h"
#include "twitterTimeline.h"
#include "RichEditEx.h"
#include "CManager.h"
#include "CTwitterManager.h"
#include "CJaikuManager.h"
#include "paramForThread.h"
#include "DropTarget.h"

#define TEMPFILE_BASE   _T("chp")

/////////////////////////////////////////////////////////////////////////////
// CChirrupDlg �_�C�A���O

class CChirrupDlg : public CDialog
{
// �\�z
public:
	CChirrupDlg(CWnd* pParent = NULL);	// �W���̃R���X�g���N�^
    ~CChirrupDlg();

    CChirrupDropTarget  m_dropTarget;   //  OLE DnD �̃h���b�v�^�[�Q�b�g

    // for Thread of updating timeline
    CWinThread      *m_updateThread;
    volatile bool   m_updateThread_Fired;
    CTime       m_startTime_updateThread;
    void        ExecuteUpdate( CManager *p );
    void        ExecuteUpdate( CString timelineType );
#       define      ID_THREAD_UPDATE_TWITTER    0xCAFEBABE
#       define      MS_THREAD_UPDATE_TWITTER    (MS_UPDATE_TWITTER / 20)

    // for Thread of posting monologue
    CWinThread  *m_postThread;
    bool        ExecutePost( CString monologue, CString timelineType );
#       define      ID_THREAD_POST_TWITTER      0xBEC0FFEE
#       define      MS_THREAD_POST_TWITTER      (MS_UPDATE_TWITTER / 20)

    // for Thread of uploading image file
    CWinThread  *m_uploadImageThread;
    bool        ExecuteUploadImage( CString       filename,
                                    size_t        filesize,
                                    CHIRRUP_FTYPE filetype,
                                    CString       caption,
                                    bool          onGyazo,
                                    bool          onFlickr,
                                    bool          onTumblr,
                                    bool          onHatenaFotolife,
                                    bool          onWassr );
    bool        ExecuteUploadImageWithURL( CString url,
                                           CString caption );
#       define      ID_THREAD_UPLAOD_IMAGE      0xBEEFCACE
#       define      MS_THREAD_UPLAOD_IMAGE      (MS_UPDATE_TWITTER / 20)

#       define      ID_WAITED_UPLAOD_IMAGE      0xDEADCAFE
#       define      MS_WAITED_UPLAOD_IMAGE      (MS_UPDATE_TWITTER / 20)

    void    EnterCriticalSection()
    {
        ::EnterCriticalSection( &m_cs_chirrup );
    }

    void    LeaveCriticalSection()
    {
        ::LeaveCriticalSection( &m_cs_chirrup );
    }

    void    SetTwitter( CString username,
                        CString password,
                        CString oauthToken,
                        CString oauthTokenSecret,
                        BOOL useOAuth,
                        BOOL useBASIC,
                        BOOL checkMultiPost,
                        TIMELINE_INFO sFriendsTimeline,
                        TIMELINE_INFO sPublicTimeline,
                        TIMELINE_INFO sUserTimeline,
                        TIMELINE_INFO sReplies );
    void    GetTwitter( CString &username,
                        CString &password,
                        CString &oauthToken,
                        CString &oauthTokenSecret,
                        BOOL &useOAuth,
                        BOOL &useBASIC,
                        BOOL &checkMultiPost,
                        TIMELINE_INFO &sFriendsTimeline,
                        TIMELINE_INFO &sPublicTimeline,
                        TIMELINE_INFO &sUserTimeline,
                        TIMELINE_INFO &sReplies );

    void    SetJaiku( CString username,
                      CString personalKey,
                      CString oauthToken,
                      CString oauthTokenSecret,
                      BOOL useOAuth,
                      BOOL useBASIC,
                      BOOL checkMultiPost,
                      TIMELINE_INFO sFriendsTimeline,
                      TIMELINE_INFO sPublicTimeline,
                      TIMELINE_INFO sUserTimeline );
    void    GetJaiku( CString &username,
                      CString &personalKey,
                      CString &oauthToken,
                      CString &oauthTokenSecret,
                      BOOL &useOAuth,
                      BOOL &useBASIC,
                      BOOL &checkMultiPost,
                      TIMELINE_INFO &sFriendsTimeline,
                      TIMELINE_INFO &sPublicTimeline,
                      TIMELINE_INFO &sUserTimeline );

    void    SetWassr( CString username,
                      CString password,
                      BOOL checkMultiPost,
                      BOOL useWassrForUpload,
                      BOOL writeLogfileForUpload,
                      CString logFilenameForUpload,
                      TIMELINE_INFO sFriendsTimeline,
                      TIMELINE_INFO sPublicTimeline,
                      TIMELINE_INFO sUserTimeline );
    void    GetWassr( CString &username,
                      CString &password,
                      BOOL &checkMultiPost,
                      BOOL &useWassrForUpload,
                      BOOL &writeLogfileForUpload,
                      CString &logFilenameForUpload,
                      TIMELINE_INFO &sFriendsTimeline,
                      TIMELINE_INFO &sPublicTimeline,
                      TIMELINE_INFO &sUserTimeline );

    void    SetMogo2( CString username,
                      CString password,
                      BOOL checkMultiPost,
                      TIMELINE_INFO sFriendsTimeline,
                      TIMELINE_INFO sPublicTimeline,
                      TIMELINE_INFO sUserTimeline );
    void    GetMogo2( CString &username,
                      CString &password,
                      BOOL &checkMultiPost,
                      TIMELINE_INFO &sFriendsTimeline,
                      TIMELINE_INFO &sPublicTimeline,
                      TIMELINE_INFO &sUserTimeline );

    void    SetTimelog( CString username,
                        CString password,
                        BOOL checkMultiPost,
                        TIMELINE_INFO sFriendsTimeline,
                        TIMELINE_INFO sPublicTimeline,
                        TIMELINE_INFO sUserTimeline );
    void    GetTimelog( CString &username,
                        CString &password,
                        BOOL &checkMultiPost,
                        TIMELINE_INFO &sFriendsTimeline,
                        TIMELINE_INFO &sPublicTimeline,
                        TIMELINE_INFO &sUserTimeline );

    void    SetHaruFm( CString username,
                       CString password,
                       BOOL checkMultiPost,
                       TIMELINE_INFO sFriendsTimeline,
                       TIMELINE_INFO sPublicTimeline,
                       TIMELINE_INFO sUserTimeline );
    void    GetHaruFm( CString &username,
                       CString &password,
                       BOOL &checkMultiPost,
                       TIMELINE_INFO &sFriendsTimeline,
                       TIMELINE_INFO &sPublicTimeline,
                       TIMELINE_INFO &sUserTimeline );

    void    SetHatenaHaiku( CString username,
                            CString password,
                            BOOL checkMultiPost,
                            TIMELINE_INFO sFriendsTimeline,
                            TIMELINE_INFO sPublicTimeline,
                            TIMELINE_INFO sUserTimeline );
    void    GetHatenaHaiku( CString &username,
                            CString &password,
                            BOOL &checkMultiPost,
                            TIMELINE_INFO &sFriendsTimeline,
                            TIMELINE_INFO &sPublicTimeline,
                            TIMELINE_INFO &sUserTimeline );

    void    SetHatena( CString username,
                       CString password,
                       BOOL    useTwitStar,
                       BOOL    useHatenaFotolife,
                       BOOL    writeLogFile,
                       CString logFilename );
    void    GetHatena( CString &username,
                       CString &password,
                       BOOL    &useTwitStar,
                       BOOL    &useHatenaFotolife,
                       BOOL    &writeLogFile,
                       CString &logFilename );

    void    SetTumblr( CString username,
                       CString password,
                       CString group,
                       CString blogName,
                       BOOL    useTumblr,
                       BOOL    useTumblr2,
                       BOOL    writeLogFile,
                       CString logFilename );
    void    GetTumblr( CString &username,
                       CString &password,
                       CString &group,
                       CString &blogName,
                       BOOL    &useTumblr,
                       BOOL    &useTumblr2,
                       BOOL    &writeLogFile,
                       CString &logFilename );

    void    SetGyazo( BOOL    useGyazo,
                      BOOL    writeLogFile,
                      CString logFilename );
    void    GetGyazo( BOOL    &useGyazo,
                      BOOL    &writeLogFile,
                      CString &logFilename );

    void    SetFlickr( BOOL    useFlickr,
                       BOOL    writeLogFile,
                       CString logFilename,
                       CString flickrToken,
                       CString flickrUserName );
    void    GetFlickr( BOOL    &useFlickr,
                       BOOL    &writeLogFile,
                       CString &logFilename,
                       CString &flickrToken,
                       CString &flickrUserName );

    void    SetProxy( BOOL    useProxy,
                      CString proxyServerName,
                      UINT    proxyPortNumber,
                      CString proxyUserName,
                      CString proxyPassword );
    void    GetProxy( BOOL    &useProxy,
                      CString &proxyServerName,
                      UINT    &proxyPortNumber,
                      CString &proxyUserName,
                      CString &proxyPassword );

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CChirrupDlg)
	enum { IDD = IDD_CHIRRUP_DIALOG };
	CComboBox	m_timelineTypeList;
	CRichEditEx	m_messageCtrl;
	CString	m_monologue;
	CString	m_periodStr;
	BOOL	m_checkBrowsing;
	CString	m_timelineType;
	BOOL	m_postMulti;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CChirrupDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �̃T�|�[�g
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
public:
    bool    m_useTumblr;    // tumblr ���g�����ǂ���

    void    SetTargetUserOnMonologue( CString targetUser );
    BOOL    SetPaneText(int nIndex, LPCTSTR lpszNewText, BOOL bUpdate = TRUE);

    void    UploadImage( PARAM_UPLOADIMAGE *param );
    void    UploadImage( const char *filename );
    void    PostImage( const char *url );
    CHIRRUP_FTYPE   GetImageSize( const char *filename,
                                  int& height, int& width );

    // ��ʃL���v�`��
    bool    m_useHatenaFotolife;// �͂Ă�FOTOLIFE���g�����ۂ�
    bool    m_useTumblr2;       // tumblr �ւ̉摜�A�b�v���[�h�@�\���g�����ۂ�
    bool    m_useGyazo;         // Gyazo �ւ̉摜�A�b�v���[�h�@�\���g�����ۂ�
    bool    m_useFlickr;        // Flickr �ւ̉摜�A�b�v���[�h�@�\���g�����ۂ�
    bool    m_useWassrForUpload;// Wassr �ւ̉摜�A�b�v���[�h�@�\���g�����ۂ�

    bool    m_inCapturing;
    void    OnEndCapture();

#define ADJUST_HEIGHT   4
#define ADJUST_WIDTH    8
#define FORTH_REDRAW    (UINT)(0xFFFF)

protected:
    CTwitterManager *m_twitter;
    CJaikuManager   *m_jaiku;
    CManager        *m_wassr;
    CManager        *m_mogo2;
    CManager        *m_timelog;
    CManager        *m_haruFm;
    CManager        *m_hatenaHaiku;

    // ����
	HICON       m_hIcon;
    HCURSOR     m_hCursor;
    CStatusBar  m_status;

    CString     m_settingDir;
    CString     m_cacheDir;
    CString     m_configFilename;

    int         m_period;   // �X�V����
    bool        m_needToSave;
    bool        m_useImetter;   // �u���߂����[�v�摜���œ��e���邩�ۂ�

    CString     m_urlBrowsing;  // �u���E�U�ŉ{������ URL
    CString     m_pageTitle;    // �u���E�U�ŉ{�����̃y�[�W�� title
    int         m_count;

    CRect       m_rectBottom;
    CRect       m_rectFriend020;
    CRect       m_rectFriend010;
    CRect       m_rectCheckBrowsing;
    CRect       m_rectMonologue;
    CRect       m_rectPostMonologue;
    CRect       m_rectDirectMessage;
    CRect       m_rectUpdate;
    CRect       m_rectMessageCtrl;
    bool        m_initialized;
    bool        m_twitterHealthy;

    // ������ (+ ��������) / �͂Ă�FOTOLIFE
    bool        m_useTwitStar;      // �������@�\���g�����ǂ���
    CString     m_hatenaID;         // �͂Ă�ID
    CString     m_hatenaPassword;   // �p�X���[�h
    bool        m_hatenaFotolifeWriteLogFile;   // ���O���c�����ۂ�
    CString     m_hatenaFotolifeLogFilename;    // ���O�t�@�C����

    // tumblr
    CString     m_tumblrID;           // ���[���A�h���X
    CString     m_tumblrPassword;     // �p�X���[�h
    CString     m_tumblrName;         // ���e�Ώ�tumbleblog �܂��̓O���[�v��
    CString     m_tumblrGroup;        // ���e�Ώ�tumbleblog ID�܂��̓O���[�v��
    bool        m_tumblrWriteLogFile; // ���O���c�����ۂ�
    CString     m_tumblrLogFilename;  // ���O�t�@�C����

    // Gyazo
    char        m_gyazoID[MAX_DATELENGTH];  // Gyazo ID (�e���|����)
    bool        m_gyazoWriteLogFile;        // ���O���c�����ۂ�
    CString     m_gyazoLogFilename;         // ���O�t�@�C����

    // Flickr
    char        m_flickrToken[MAX_CATIDLENGTH];     // flickr �g�[�N��
    char        m_flickrUserName[MAX_CATIDLENGTH];  // flickr ���[�U��
    bool        m_flickrWriteLogFile;               // ���O���c�����ۂ�
    CString     m_flickrLogFilename;                // ���O�t�@�C����

    // Wassr (�摜)
    bool        m_wassrWriteLogFileForUpload;   // ���O���c�����ۂ�
    CString     m_wassrLogFilenameForUpload;    // ���O�t�@�C����

    // ��ʃL���v�`��
    HWND        m_hWndForCapture;
    HINSTANCE   m_hInstForCapture;

#define CACHE_DIRECTORY     "cache/"
#define SETTING_DIRECTORY   "setting/"
#define SETTING_FILENAME    "chirrup.inf"
    void    LoadSetting();
    void    SaveSetting();

    bool    GetStringValue(
                const char *inputString,
                const char *targetName,
                char       *stringValue );

    void    WriteKeys(
                FILE          *fp,      // (I/O) �����o����
                char          *key,     // (I/O) ���J��
                unsigned char **secret, // (I/O) �����ɕK�v�ȏ��(�閧��)
                bool          &done );  // (O)   �Í����������s�ς݂��ۂ�

    bool    CheckKeys(
                const char          *p,
                const unsigned char *rsaString,
                bool                &ret );

    bool    EvalKeys(
                const char          *p,
                const unsigned char *rsaString );

    bool    CheckEncodedPassword();
    void    GetProxyInfo( bool           &p_isUsedProxy,
                          CString        &p_proxyServer,
                          unsigned short &p_proxyPort,
                          CString        &p_proxyUserName,
                          CString        &p_proxyPassword );

    bool            IsInner( int id, WORD wX, WORD wY );

    CWinThread      *DisplayProfImages( CTwitterTimeline *tp );
    void            DisplayTimeline();

    void            PostMessageToFriend( int idx );
    char            *GetSceenNameOfFriend( int idx );
    void            ShowFriendProfile( int idx );
    void            ShowWebPage( int idx );
    void            SendDirectMessageToFriend( int idx );
    void            AddFriend( int idx );
    void            RemoveFriend( int idx );
    void            ShowFavorites( int idx );

    bool            PostMonologue( PARAM_POST *param );

    void            UpdateSingle( CManager *manager );
    void            UpdateSingle();

	// ���b�Z�[�W�}�b�v�֐�
	//{{AFX_MSG(CChirrupDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnPostMonologue();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnUpdate();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnKillfocusPeriod();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
    afx_msg void OnDisplayToolTip(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnTwitter();
	afx_msg void OnHatenagroup();
	afx_msg void OnHatenabookmark();
	afx_msg void OnDelicous();
	afx_msg void OnGooglegroups();
	afx_msg void OnTwitterwiki();
	afx_msg void OnTwitterChirrup();
	afx_msg void OnMixi();
	afx_msg void OnMagnolia();
	afx_msg void OnDigg();
	afx_msg void OnLivedoorclip();
	afx_msg void OnLivedoor();
	afx_msg void OnGoogle();
	afx_msg void OnYahoo();
	afx_msg void OnBloglines();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnFriend001();
	afx_msg void OnFriend002();
	afx_msg void OnFriend003();
	afx_msg void OnFriend004();
	afx_msg void OnFriend005();
	afx_msg void OnFriend006();
	afx_msg void OnFriend007();
	afx_msg void OnFriend008();
	afx_msg void OnFriend009();
	afx_msg void OnFriend010();
	afx_msg void OnFriend011();
	afx_msg void OnFriend012();
	afx_msg void OnFriend013();
	afx_msg void OnFriend014();
	afx_msg void OnFriend015();
	afx_msg void OnFriend016();
	afx_msg void OnFriend017();
	afx_msg void OnFriend018();
	afx_msg void OnFriend019();
	afx_msg void OnFriend020();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnTwitterSearch();
	afx_msg void OnCheckBrowsing();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI);
	afx_msg void OnRecvDirectmessage();
	afx_msg void OnSelchangeComboTimelineType();
	afx_msg void OnSettingAccount();
	afx_msg void OnJaiku();
	afx_msg void OnCheckMultipost();
	afx_msg void OnMogo2();
	afx_msg void OnWassr();
	afx_msg void OnTimelog();
	afx_msg void OnHarufm();
	afx_msg void OnExecuting();
	afx_msg void OnHatenastar();
	afx_msg void OnFavotter();
	afx_msg void OnTumblr();
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg void OnEditPaste();
	afx_msg void OnStartCapture();
	afx_msg void OnGyazo();
	afx_msg void OnHatenaFotolife();
	afx_msg void OnFlickr();
	afx_msg void OnTwitterSNS();
	afx_msg void OnDestroy();
	afx_msg void OnHatenaHaiku();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
    CRITICAL_SECTION    m_cs_chirrup; // �X���b�h�Ԃł̔r������p
    PARAM_UPDATE        m_param;      // for Thread of updating timeline
    PARAM_POST          m_postTweet;  // for Thread of posting monologue
    PARAM_POST          m_postBrowse; // for Thread of posting 'browsing info'
    PARAM_LOADIMAGE     m_paramLoadImage;   // for Thread of 'loading images'
    PARAM_UPLOADIMAGE   m_paramUploadImage; // for Thread of 'upload image'
    CWinThread          *m_loadImageThread;
    volatile bool       m_inSetting;
    bool                m_showServiceName;
    CString             m_serviceName;
    CFont               m_cFont1;
    CFont               m_cFont2;

    char                m_waitedFilename[MAX_PATH];

    unsigned long       m_nType;
    long                m_cx;
    long                m_cy;
    long                m_cxInitial;
    long                m_cyInitial;

    bool                m_updateUserIcon;

    CTwitterTimeline    *GetCurrentTimeline()
    {
        CTwitterTimeline    *tp =
            !m_timelineType.Compare( "Jaiku: Public" )
                                        ? &(m_jaiku->m_publicTimeline)
                                        :
            !m_timelineType.Compare( "Jaiku: User" )
                                        ? &(m_jaiku->m_userTimeline)
                                        :
            !m_timelineType.Compare( "Jaiku: Friends" )
                                        ? &(m_jaiku->m_friendsTimeline)
                                        :
            !m_timelineType.Compare( "Wassr: Public" )
                                        ? &(m_wassr->m_publicTimeline)
                                        :
            !m_timelineType.Compare( "Wassr: User" )
                                        ? &(m_wassr->m_userTimeline)
                                        :
            !m_timelineType.Compare( "Wassr: Friends" )
                                        ? &(m_wassr->m_friendsTimeline)
                                        :
            !m_timelineType.Compare( "��������: Public" )
                                        ? &(m_mogo2->m_publicTimeline)
                                        :
            !m_timelineType.Compare( "��������: User" )
                                        ? &(m_mogo2->m_userTimeline)
                                        :
            !m_timelineType.Compare( "��������: Friends" )
                                        ? &(m_mogo2->m_friendsTimeline)
                                        :
            !m_timelineType.Compare( "Timelog: Public" )
                                        ? &(m_timelog->m_publicTimeline)
                                        :
            !m_timelineType.Compare( "Timelog: User" )
                                        ? &(m_timelog->m_userTimeline)
                                        :
            !m_timelineType.Compare( "Timelog: Friends" )
                                        ? &(m_timelog->m_friendsTimeline)
                                        :
            !m_timelineType.Compare( "Haru.fm: Public" )
                                        ? &(m_haruFm->m_publicTimeline)
                                        :
            !m_timelineType.Compare( "Haru.fm: User" )
                                        ? &(m_haruFm->m_userTimeline)
                                        :
            !m_timelineType.Compare( "Haru.fm: Friends" )
                                        ? &(m_haruFm->m_friendsTimeline)
                                        :
            !m_timelineType.Compare( "�͂Ăȃn�C�N: Public" )
                                        ? &(m_hatenaHaiku->m_publicTimeline)
                                        :
            !m_timelineType.Compare( "�͂Ăȃn�C�N: User" )
                                        ? &(m_hatenaHaiku->m_userTimeline)
                                        :
            !m_timelineType.Compare( "�͂Ăȃn�C�N: Friends" )
                                        ? &(m_hatenaHaiku->m_friendsTimeline)
                                        :
            !m_timelineType.Compare( "Twitter: Replies" )
                                        ? &(m_twitter->m_replies)
                                        :
            !m_timelineType.Compare( "Twitter: User" )
                                        ? &(m_twitter->m_userTimeline)
                                        :
            !m_timelineType.Compare( "Twitter: Public" )
                                        ? &(m_twitter->m_publicTimeline)
                                        : &(m_twitter->m_friendsTimeline);

        return ( tp );
    }

    CString GetCurrentScreenName()
    {
        CString s =
            !strncmp( m_timelineType, "Jaiku: ", 7 )
                                        ? m_jaiku->m_screenName
                                        :
            !strncmp( m_timelineType, "Wassr: ", 7 )
                                        ? m_wassr->m_screenName
                                        :
            !strncmp( m_timelineType, "��������: ", 10 )
                                        ? m_mogo2->m_screenName
                                        :
            !strncmp( m_timelineType, "Timelog: ", 9 )
                                        ? m_timelog->m_screenName
                                        :
            !strncmp( m_timelineType, "Haru.fm: ", 9 )
                                        ? m_haruFm->m_screenName
                                        :
            !strncmp( m_timelineType, "�͂Ăȃn�C�N: ", 9 )
                                        ? m_hatenaHaiku->m_screenName
                                        : m_twitter->m_screenName;

        return ( s );
    }

    void    SwitchMultiPost();
    void    SwitchTimelineList();
    void    SwitchTimelineFacilities();
    void    SwitchTitle();
    void    SwitchCapture();
    void    SwitchImetter();

    void    ShowServiceName( bool mode );
    void    ReduceExtra();

    bool    DisplayContextMenuForServices( WORD wX, WORD wY );
    bool    DisplayContextMenuForFriends( WORD wX, WORD wY );
    bool    DisplayContextMenuForImetter( WORD wX, WORD wY );
    bool    ExtraContextMenu( WORD wX, WORD wY );
    void    SetStaticEdge( int idx, bool status );
    void    SetAddrOnMonologue( CString targetUser, CEdit *cp );

private:
    CChirrupDlg( CChirrupDlg &dlg );
    CChirrupDlg operator = ( CChirrupDlg &dlg );

    void    DeleteHtmlTags( CString &targetString )
    {
        size_t  sz = targetString.GetLength();
        if ( strchr( targetString, '<' ) ) {
            /* html �^�O�̏��� */
            char    *temp = new char[sz + 1];

            if ( temp ) {
                strcpy( temp, targetString );

                char        *p = temp;
                char        *q;
                const char  *r;
                while ( ( q = strchr( p, '<' ) ) != NULL ) {
                    if ( (r = strchr(q + 1, '>')) != NULL )
                        strcpy( q, r + 1 );
                    else {
                        *q = NUL;
                        break;
                    }
                }

                targetString = temp;
                delete [] temp;
            }
        }
    }

    void    WriteUploadLog( const char *filename,
                            const char *url,
                            const char *caption );
    bool    SetSigInfo( CString &sKey,    CString &sSecret,
                        const char *sig1, const char *sig2 );

    void    GetImageViaImetter( CString &monologue, ProceedingDialog *pdlg );

    // �^�X�N�g���C�A�C�R���֘A
    NOTIFYICONDATA  m_stNotifyIcon;
#define WM_APP_TASKTRY  (WM_APP + 0x0BED)  
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_CHIRRUPDLG_H__5843E218_092A_47EB_AA1F_F176B490916A__INCLUDED_)
