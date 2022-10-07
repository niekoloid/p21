#ifndef _ERRORMSGSTRUCT_H_
#define	_ERRORMSGSTRUCT_H_

#include "SXFErrorCode.h"

struct {
	SXFErrorCode		m_Code ;
	char				*m_Text ;
} ErrorMsg[] = {
	//�V�X�e���̃G���[
	{SXFMEMORY, "�������s���ł��B\n"},//-10001
	{SXFDISC, "�f�B�X�N�ɏ������߂܂���B"},//-10002
	{SXFERROR, "�V�X�e�����ŗ\�����ʃG���[���������܂����B"},//-10003
	{SXFFILEDIRECTORY, "�w�肳�ꂽ�t�@�C���܂��̓f�B���N�g����������܂���B<%s>"},//-10004

	{SXFNOTOPENSTEPFILE, "STEP�t�@�C���̃I�[�v���Ɏ��s���܂����B<%s>"},//-10010
	{SXFNOTCLOSESTEPFILE, "STEP�t�@�C���̃N���[�Y�Ɏ��s���܂����B<%s>"},//-10011
	{SXFOPENSTEPFILE, "�w�肳�ꂽSTEP�t�@�C���͊��ɃI�[�v������Ă��܂��B<%s>"},//-10012
	{SXFCLOSESTEPFILE, "�w�肳�ꂽSTEP�t�@�C���͊��ɃN���[�Y����Ă��܂��B<%s>"},//-10013
	{SXFSTEPFILENOTOPEN, "STEP�t�@�C�����I�[�v������Ă��܂���B"},//-10014
	{SXFERRORMODE,"���[�h�̃G���[�ł��B�t�@�C���̃��[�h<%s>  �I�[�v�����Ɏw�肵�����[�h<%s>"},//-10015
	{SXFNOLEVEL,"���x���Ɍ�肪����܂��B���x��<%d>"},//-10016
	{SXFNOMODE,"���[�h�Ɍ�肪����܂��B���[�h<%d>"},//-10017
	{SXFRWFLAG,"�ǂݏ����t���O�͂O�C�P�ȊO�w��ł��܂���B�ǂݏ����t���O<%d>"},//-10018
	{SXFDCWARNING,"�O����`�t�@�C����ǂݍ��݂܂��B"},//-10019
	{SXFEXPANDERROR,"�W�J�֐����Ăяo���܂���B"},//-10020
	{SXFWARNINGLEVEL,"���x��<%d>���w�肳��܂����B"},//-10021
	{SXFWARNINGMODE,"���[�h�Ɍ�肪����܂��B���[�h<%d>  AP202���[�h�Ƃ��ď������܂��B"},//-10022
	{SXFWARNINGDC,"�_�E���R���o�[�g�����͍s���܂���B"},//-10023
	{SXFERRORFILE,"��������v�f������܂���B"},//-10024
	{SXFERRORINS,"�C���X�^���X�f�[�^�Ɍ�肪����܂��B"},//-10025
	{SXFSCADECFILEERR,"SCADEC�ȊO�̃t�@�C���ł��B"},//-10026
	{SXFAP202FILE,"�t�B�[�`���R�����g���[�h�̃t�@�C���ł��B"},//-10027
	{SXFERRENTITY,"�s���ȃG���e�B�e�B���ł��B"},//-10028

	//�A�Z���u���v�f�Ɋւ���G���[
	{SXFNOTSETZNAME, "�}�ʖ����w�肳��Ă��܂���B"},//-20001
	{SXFNOTSETCNAME, "�����}�`�����w�肳��Ă��܂���B�����𒆒f���܂��B"},//-20002
	{SXFNOTSETLNAME, "���C�������w�肳��Ă��܂���B�����𒆒f���܂��B"},//-20003
	{SXFRGBERROR,"RGB�l�Ɉُ킪����܂��B:RGB�l<%d>"},//-20004
	{SXFSEGMENTERROR,"�Z�O�����g�̒l�Ɉُ킪����܂��B:�Z�O�����g<%d>"},//-20005
	{SXFPITCHERROR,"�s�b�`�ɔ͈͊O�̒l��ݒ肵�Ă��܂��B:�s�b�`<%lf>"},//-20006
	{SXFWIDTHERROR,"�����ɔ͈͊O�̒l��ݒ肵�Ă��܂��B:����<%lf>"},//-20007
	{SXFMAXLAYER,"�ő僌�C�����𒴂��܂����B"},//-20008
	{SXFMAXPRECOLOUR,"�ő����`�F���𒴂��܂����B"},//-20009
	{SXFMAXUSERCOLOUR,"�ő僆�[�U��`�F���𒴂��܂����B"},//-20010
	{SXFMAXPRELINETYPE,"�ő����`���퐔�𒴂��܂����B"},//-20011
	{SXFMAXUSERLINETYPE,"�ő僆�[�U��`���퐔�𒴂��܂����B"},//-20012
	{SXFMAXLINEWIDTH,"�ő�������𒴂��܂����B"},//-20013
	{SXFMAXTEXTFONT,"�ő啶���t�H���g���𒴂��܂����B"},//-20014
	{SXFCURVEFLAG,"�\���^��\���t���O�̒l�Ɉُ킪����܂��B<%d>"},//-20015
	{SXFSHEETONE,"�p���͈ꖇ�����ݒ�ł��܂���B"},//-20017
	{SXFSFIGONE,"���x��1�ł́A�����}�͈������`�ł��܂���B"},//-20018
	{SXFSFIGLEVEL,"���x���P�ł́A�����}�`�͕����}������`�ł��܂���B"},//-20019
	{SXFSHEETERROR,"���x���P�ł͗p����ɂ͕����}�����z�u�ł��܂���B"},//-20020
	{SXFCFIGERROR,"���x��1�ł́A�����}��ɂ͍�}�O���[�v����їv�f�����z�u�ł��܂���B"},//-20021
	{SXFNOTASSEMBLY,"�A�Z���u���v�f���J����Ă��܂���B"},//-20022
	{SXFCFIGLOCERROR,"���x��1�ł́A�p����ɂ͈���������}��z�u�ł��܂���B"},//-20023
	{SXFSAMENAME,"���łɓ������̂��e�[�u���ɑ��݂��܂��B:���O<%s>"},//-20024
	{SXFSFIGFLAG,"�����}�`��ʃt���O�̒l�Ɉُ킪����܂��B:�t�B�[�`��ID<%s>  �t���O<%d>  �t�B�[�`����<%s>"},//-20025
	{SXFSHEETSIZE,"�p���T�C�Y��ʂ̒l�Ɉُ킪����܂��B:�p���T�C�Y���<%d>"},//-20026
	{SXFORIENTERROR,"�c/���敪�̒l�Ɉُ킪����܂��B:�c/���敪<%d>"},//-20027
	{SXFSHEETLENGTH,"���R�p���̒�����0�ȉ��ł��B:���R�p����<%d>"},//-20028
	{SXFNOTPRETYPE,"����`����ł͂���܂���B:���햼<%s>"},//-20029
	{SXFNOTPRECOLOUR,"����`�F�ł͂���܂���B:�F��<%s>"},//-20030
	{SXFNOTPREWIDTH,"����`�����ł͂���܂���B:����<%lf>"},//-20031
	{SXFSAMEWIDTH,"���łɓo�^���ꂽ�����ł��B:����<%lf>"},//-20032
	{SXFBASELINEERROR,"�x�[�X���C���䗦�̒l���ُ�ł��B�FAscent<%lf> Decent<%lf>"},//-20033
	{SXFFONTNAMEERROR,"�����t�H���g���̒���0�ł��B"},//-20034
	{SXFSHEETLENGTHWARNING,"���R�p���̒������ݒ肳��Ă��܂��B:���R�p����<%d>"},//-20035
	{SXFNOTFEATURE,"�A�Z���u���v�f��Ƀt�B�[�`���v�f�����݂��܂���B"},//-20036
	{SXFASSEMTYPEERR,"�A�Z���u���^�Ɉُ킪����܂��B:�A�Z���u���^<%d>"},//-20037
	{SXFTABLETYPEERR,"�e�[�u���^�Ɉُ킪����܂��B:�e�[�u���^<%d>"},//-20038
	{SXFSFIGLOCERR,"������`��ɗp���͔z�u�ł��܂���B"},//-20039
	{SXFCURVELOCERR,"�����Ȑ���ɗp���͔z�u�ł��܂���B"},//-20040
	{SXFNOLAYER,"�ǂݏo�����C��������܂���B"},//-20041
	{SXFNOPRECOLOUR,"�ǂݏo������`�F������܂���B"},//-20042
	{SXFNOUSERCOLOUR,"�ǂݏo�����[�U��`�F������܂���B"},//-20043
	{SXFNOPRELINETYPE,"�ǂݏo������`���킪����܂���B"},//-20044
	{SXFNOUSERLINETYPE,"�ǂݏo�����[�U��`���킪����܂���B"},//-20045
	{SXFNOLINEWIDTH,"�ǂݏo������������܂���B"},//-20046
	{SXFNOTEXTFONT,"�ǂݏo�������t�H���g������܂���B"},//-20047
	{SXFNOASSEMBLY,"�ǂݏo���A�Z���u���v�f������܂���B"},//-20048
// ADD(S)	���b�Z�[�W�C��	K.Naono	04.02.09
/*
	{SXFNOTUSEDLAYER,		"�t�@�C���ɂ̓��C���͎g�p����Ă��܂���B"},//-20049,
	{SXFNOTUSEDPRECOLOUR,	"�t�@�C���ɂ͊���`�F�͎g�p����Ă��܂���B"},//-20050,
	{SXFNOTUSEDUSERCOLOUR,	"�t�@�C���ɂ̓��[�U��`�F�͎g�p����Ă��܂���B"},//-20051,
	{SXFNOTUSEDPRELINETYPE,	"�t�@�C���ɂ͊���`����͎g�p����Ă��܂���B"},//-20052,
	{SXFNOTUSEDUSERLINETYPE,"�t�@�C���ɂ̓��[�U��`����͎g�p����Ă��܂���B"},//-20053,
	{SXFNOTUSEDLINEWIDTH,	"�t�@�C���ɂ͐����͎g�p����Ă��܂���B"},//-20054,
	{SXFNOTUSEDTEXTFONT,	"�t�@�C���ɂ͕����t�H���g�͎g�p����Ă��܂���B"},//-20055,
	{SXFNOTUSEDASSEMBLY,	"�t�@�C���ɂ̓A�Z���u���v�f�͎g�p����Ă��܂���B"},//-20056,
*/
// ADD(E)	���b�Z�[�W�C��	K.Naono	04.02.09

	//�t�B�[�`���v�f�Ɋւ���G���[
	{SXFNOTSETSHEET, "�p�����ݒ肳��Ă��܂���B�����𒆒f���܂��B"},//-30001
	{SXFNOTSETCFIG, "�����}�`���ݒ肳��Ă��܂���B�����𒆒f���܂��B:�t�B�[�`��ID<%s>  �����}�`��<%s>  �t�B�[�`����<%s>"},//-30002
 	{SXFEUNSETLAYER,"�ݒ肳��Ă��Ȃ����C���R�[�h���w�肳��܂����B:�t�B�[�`��ID<%s>  ���C���R�[�h<%d>  �t�B�[�`����<%s>"}, //-30003
	{SXFERRORCOLOUR, "�F�R�[�h�̒l�Ɉُ킪����܂��B:�t�B�[�`��ID<%s>  �F�R�[�h<%d> �t�B�[�`����<%s> "},//-30004
	{SXFERRORFONT, "����R�[�h�̒l�Ɉُ킪����܂��B:�t�B�[�`��ID<%s>  ����R�[�h<%d> �t�B�[�`����<%s>"},//-30005
	{SXFERRORWIDTH, "�����R�[�h�̒l�Ɉُ킪����܂��B:�t�B�[�`��ID<%s>  ����<%d> �t�B�[�`����<%s>"},//-30006
	{SXFTEXTFONTERROR,"�����t�H���g�R�[�h�̒l�Ɉُ킪����܂��B:�t�B�[�`��ID<%s>  �����t�H���g�R�[�h<%d>  �t�B�[�`����<%s>"},//-30007
	{SXFLEVELERROR,"���x���P�ł͏����ł��܂���B�t�B�[�`����<%s>"},//-30008
	{SXFLAYERFLAG,"�\���^��\���t���O�̒l�Ɉُ킪����܂��B<%d>"},//-30009
	{SXFPARTERROR,"��}���i�ɂ͕����}�A��}�O���[�v��z�u�ł��܂���B�t�B�[�`����<%s>"},//-30010
	{SXFGROUPERROR,"��}�O���[�v��`�ɕ����}��z�u���Ă��܂��B:�t�B�[�`��ID<%s>  �t�B�[�`����<%s>"},//-30011
	{SXFSFIGERROR,"�����}��`�ɕ����}��z�u���Ă��܂��B:�t�B�[�`��ID<%s>  �t�B�[�`����<%s>"},//-30012
	{SXFGROUPLEVEL1,"��}�O���[�v�ɂ͗v�f�ȊO�z�u�ł��܂���B�t�B�[�`����<%s>"},//-30013
	{SXFNOTCURVE,"�����Ȑ���`�ɂ͔z�u�ł��܂���B�t�B�[�`����<%s>"},//-30014
	{SXFNOTHEADER,"�w�b�_������܂���B�t�@�C����:<%s>"},//-30015
	{SXFFEATURETYPEERR,"�t�B�[�`���^�Ɉُ킪����܂��B:�t�B�[�`���^<%s>"},//-30016
	{SXFNOTATTRIBUTE,"�}�ʕ\�藓�́A�p���܂��́A�����}�ȊO�ɂ͔z�u�ł��܂���B�t�B�[�`����<%s>"},//-30017

	{SXFERRORANGLE, "�p�x�̒l�Ɉُ킪����܂��B :�t�B�[�`��ID<%s>  �x<%lf> �t�B�[�`����<%s>"},//-31001
	{SXFERRORCOORDINATE, "�z�u���W�̒l�Ɉُ킪����܂��B:�t�B�[�`��ID<%s>  X<%lf>  Y<%lf>  �t�B�[�`����<%s>"},//-31002
	{SXFERRORSCALE, "�X�P�[���̒l�Ɉُ킪����܂��B:�t�B�[�`��ID<%s>  �X�P�[��<%lf> �t�B�[�`����<%s>"},//-31003
	{SXFLENGTHZERO, "�����̒������O�ł��B:�t�B�[�`��ID<%s>  �����̒���<%lf>  �t�B�[�`����<%s>"},//-31004
	{SXFRADIUSZERO, "���a�ɔ͈͊O�̒l��ݒ肵�Ă��܂��B:�t�B�[�`��ID<%s>  ���a<%lf> �t�B�[�`����<%s>"},//-31005
	{SXFVERTEXERROR,"���_�����Q�����ł��B:�t�B�[�`��ID<%s>  ���_��<%d>  �t�B�[�`����<%s>"},//-31006
	{SXFTEXTWIDTH,"�����͈͕��ɔ͈͊O�̒l��ݒ肵�Ă��܂��B:�t�B�[�`��ID<%s>  �����͈͕�<%lf>  �t�B�[�`����<%s>"},//-31007
	{SXFTEXTHEIGHT,"�����͈͍��ɔ͈͊O�̒l��ݒ肵�Ă��܂��B:�t�B�[�`��ID<%s>  �����͈͍�<%lf>  �t�B�[�`����<%s>"},//-31008
	{SXFTEXTSPACE,"�����Ԋu�ɔ͈͊O�̒l��ݒ肵�Ă��܂��B:�t�B�[�`��ID<%s>  �����Ԋu<%lf>  �t�B�[�`����<%s>"},//-31009
	{SXFBPNTERROR,"�����z�u��_�̒l�Ɉُ킪����܂��B:�t�B�[�`��ID<%s>  �����z�u��_<%d>  �t�B�[�`����<%s>"},//-31010
	{SXFDIRECTERROR,"���������o�������̒l�Ɉُ킪����܂��B:�t�B�[�`��ID<%s>  ���������o������<%d>  �t�B�[�`����<%s>"},//-31011
	{SXFDIRECTIONERROR,"�����t���O�̒l�Ɉُ킪����܂��B :�t�B�[�`��ID<%s>  �����t���O<%d>  �t�B�[�`����<%s>"},//-31012
	{SXFOPENCLOSEERROR,"�J�敪�̒l�Ɉُ킪����܂��B :�t�B�[�`��ID<%s>  �J�敪<%d>  �t�B�[�`����<%s>"},//-31013
	{SXFMARKERERROR,"�}�[�J�R�[�h�̒l�Ɉُ킪����܂��B :�t�B�[�`��ID<%s>  �}�[�J�R�[�h<%d>  �t�B�[�`����<%s>"},//-31014
	{SXFPRJFLAG,"�⏕���t���O�̒l�Ɉُ킪����܂��B:�t�B�[�`��ID<%s>  �t���O<%d>  �t�B�[�`����<%s>"},//-31016
	{SXFARRCODE,"���R�[�h�̒l�Ɉُ킪����܂��B:�t�B�[�`��ID<%s>  �t���O<%d>  �t�B�[�`����<%s>"},//-31017
	{SXFTEXTFLAG,"���@�l�̗L���t���O�̒l�Ɉُ킪����܂��B:�C���X�^���XID<%s>  �t���O<%d>  �t�B�[�`����<%s>"},//-31018
	{SXFCOLORFLAG,"�F�R�[�h�t���O�̒l�Ɉُ킪����܂��B:�t�B�[�`��ID<%s>  �t���O<%d>  �t�B�[�`����<%s>"},//31019
//
	{SXFERRORVECTOR,"�x�N�g���̑傫�����͈͊O�̒l�ł��B:�t�B�[�`��ID<%s>  �x�N�g���̑傫��<%lf>  �t�B�[�`����<%s>"},//31024
	{SXFERRORNUMBER,"�������̕̈搔��0�����ł��B:�t�B�[�`��ID<%s>  �������̕̈搔<%d>  �t�B�[�`����<%s>"},//31025
	{SXFERRORPATTERN,"�n�b�`���O���̃p�^�[�������͈͊O�̒l�ł��B:�t�B�[�`��ID<%s>  �n�b�`���O���̃p�^�[����<%d>  �t�B�[�`����<%s>"},//31026
	{SXFSAMECOORD,"�׍����Q�_���������W�ł��B:�t�B�[�`��ID<%s>  X<%lf>  Y<%lf>�@�t�B�[�`����<%s>"},//31028
	{SXFSAMEANGLE,"�n�p�ƏI�p���������ł��B:�t�B�[�`��ID<%s>  �n�p<%lf>  �I�p<%lf>  �t�B�[�`����<%s>"},//31029
	{SXFVERTEXERRORSPLINE,"���_�����S�����ł��B:�t�B�[�`��ID<%s>  ���_��<%d>  �t�B�[�`����<%s>"},//-31031
	{SXFSPACING,"�n�b�`���O���̊Ԋu�ɔ͈͊O�̒l��ݒ肵�Ă��܂��B:�t�B�[�`��ID<%s>�@�Ԋu<%lf>  �t�B�[�`����<%s>"},//-31032
	{SXFERROROUTID,"�n�b�`���O�̊O�`����`����Ă��܂���B:�t�B�[�`��ID<%s>  �n�b�`���O�̊O�`<%d>  �t�B�[�`����<%s>"},//-31033
	{SXFERRORINID,"�n�b�`���O�̒���������`����Ă��܂���B:�t�B�[�`��ID<%s>  �n�b�`���O�̒�����<%d>  �t�B�[�`����<%s>"},//-31034
	{SXFSFIGLOCONE, "��̕����}�`��`�ɑ΂��A��ȏ�z�u�ł��܂���B:�t�B�[�`��ID<%s> �����}�`��<%s> �t�B�[�`����<%s>"},//-31035,
	{SXFARRORERROR, "���z�u���W�̒l���ُ�ł��B:�t�B�[�`��ID<%s> ���P���W X<%lf> Y<%lf>�@���Q���W X<%lf> Y<%lf>�@�t�B�[�`����<%s>"},//-31036,
	{SXFHATCHIDERROR,"�n�b�`���O�̊O�`�Ŏw�肵���R�[�h�𒆔����Ɏw�肵�Ă��܂��B:�t�B�[�`��ID<%s>  �������̃R�[�h<%d>  �t�B�[�`����<%s>"},//-31037
	{SXFNOTVERTEXNUMBER,"���_���Ɍ�肪����܂��B:�t�B�[�`��ID<%s>  ���_��<%d>  �t�B�[�`����<%s>"},//-31038
	{SXFNOTINIDNUMBER,"�n�b�`���O�̒������̕̈搔�Ɍ�肪����܂��B:�t�B�[�`��ID<%s>  �������̕̈搔<%d>  �t�B�[�`����<%s>"},//-31039
	{SXFARRINOUTCODE,"�����O�R�[�h�̒l�Ɉُ킪����܂��B:�t�B�[�`��ID<%s>  �����O�R�[�h<%d>  �t�B�[�`����<%s>"},//-31040
	// 2012.07.03
	{SXFNAMELENGTH,"257�o�C�g�ȏ�̕����񂪂���܂����B256�o�C�g�ɐ؂���܂��B:�t�B�[�`��ID<%s>  �t�B�[�`����<%s>"},//-31041
	// 2012.07.03
	{SXFDATEERROR,"���t�ɔ͈͊O�̒l��ݒ肵�Ă��܂��B:�t�B�[�`��ID<%s>  ���t<%d> �t�B�[�`����<%s>"},//-31042

	{SXFCLOTHOIDPARA,"�N���\�C�h�p�����[�^���O�����ł��B:�t�B�[�`��ID<%s>  �p�����[�^<%lf> �t�B�[�`����<%s>"},//-31043
	{SXFCLOTHOIDLEN,"�Ȑ������O�����ł��B:�t�B�[�`��ID<%s>  �Ȑ���<%lf> �t�B�[�`����<%s>"},//-31044

//
// �����ɃG���[���b�Z�[�W��ǉ�
//
/**	
	���[���`�F�b�N�@�\�p�Ɉȉ��̃��b�Z�[�W��ǉ������B
**/
/**	
	�����[���`�F�b�N�@�\�G���[�R�[�h�T�v

		���[���`�F�b�N�@�\�ɂ��G���[�R�[�h�ɂ́A5000�ԑ��
		�p���Ă���B�G���[�̎�ޖ��ɐ�̈ʂ̔ԍ���ς��邱�ƂŁA
		���[���`�F�b�N�@�\�̃G���[�̎�ʂ����ʂł���悤�ɂ����B
		�ȉ��Ɏ�ʂ��������B

		50000�`50999:Part21�̏����i�u(�v���������j�Ɋւ���G���[�������B
		51000�`51999:�p�����[�^�̌^���X�L�[�}�Œ�`����Ă���^��
					  �قȂ鎞�̃G���[�������B
		52000�`52999:DERIVE�AUNIQUE�����Ɋւ���G���[�������B
					  ������4���񋟔łł͑Ή������B
		53000�`53999:�Q�Ɛ�̃C���X�^���X�Ɋւ���G���[�������B
		54000�`54999:�X�L�[�}�ɑ��݂��Ȃ��G���e�B�e�B�Ɋւ���G���[�������B
		55000�`55999:�C���X�^���X�̃p�����[�^�̐��Ɋւ���G���[�������B
		56000�`56999:ENUMERATRION�錾�Ɋւ���G���[�������B
		57000�`57999:��x���Q�Ƃ���Ȃ��C���X�^���X�̃G���[�������B

**/
	{SXFNOINSTCLASS,	"�Q�Ɛ�̃G���e�B�e�B�Ɍ�肪����܂��B:�Q�ƌ��C���X�^���XID<#%d> �G���e�B�e�B��<%s> �Q�Ɛ�C���X�^���XID<#%s>"},//-53001
	{SXFINSTNOTHING,	"�Q�Ɛ�̃C���X�^���XID �����݂��܂���B:�Q�ƌ��C���X�^���XID<#%d> �G���e�B�e�B��<%s> �Q�Ɛ�C���X�^���XID<#%s>"},//-53002
	{SXFCOMPINST1,		"�Q�Ɛ�̕����C���X�^���X����͂ł��܂���B:�C���X�^���XID<#%d> �G���e�B�e�B��<%s> �p�����[�^<%s>"},//-53003
	{SXFCOMPINST2,		"�Q�Ɛ�̕����C���X�^���X�ɕs�K�؂ȃG���e�B�e�B���w�肳��Ă��܂��B:�C���X�^���XID<#%d>  �G���e�B�e�B��<%s>"},//-53004
	{SXFNOENTITY,		"�G���e�B�e�B�����݂��܂���B:�C���X�^���XID<#%d>"},//-53005
	{SXFSYNTAX1,		"(�����݂��܂���B:�C���X�^���XID<#%d> �G���e�B�e�B��<%s>"},//-50001
	{SXFSYNTAX2,		")�����݂��܂���B:�C���X�^���XID<#%d> �G���e�B�e�B��<%s>"},//-50002
	{SXFSYNTAX3,		",�����݂��܂���B:�C���X�^���XID<#%d> �G���e�B�e�B��<%s>"},//-50003
	{SXFSYNTAX4,		",�܂���)�����݂��܂���B:�C���X�^���XID<#%d> �G���e�B�e�B��<%s>"},//-50004
	{SXFTYPEBOOLEAN,	"BOOLEAN�^�łȂ��l���w�肳��Ă��܂��B:�C���X�^���XID<#%d> �G���e�B�e�B��<%s> �p�����[�^<%s>"},//-51001
	{SXFATTRDERIVE,		"DERIVE�錾���Ă��Ȃ����������ɂȂ��Ă��܂��B:�C���X�^���XID<#%d> �G���e�B�e�B��<%s> �p�����[�^<%s>"},//-52001
	{SXFEXCEPT,		"SCADEC�̑Ώۂł͂Ȃ�ENTITY�ł��B:�C���X�^���XID<#%d> �G���e�B�e�B��<%s>"},//-54000
	{SXFNOSCHEMA,		"�s�K�؂�ENTITY�����w�肳��Ă��܂��B:�C���X�^���XID<#%d> �G���e�B�e�B��<%s>"},//-54001
	{SXFNOENUMDEC,		"Enumration�錾�ɂ͑��݂��܂���B:�C���X�^���XID<#%d> �G���e�B�e�B��<%s> �p�����[�^<%s>"},//-56001
	{SXFTYPEENUM,		"Enumration�`���ł͂���܂���B:�C���X�^���XID<#%d> �G���e�B�e�B��<%s> �p�����[�^<%s>"},//-56002
	{SXFTYPEINTEGER,	"INTEGER�^�łȂ��l���w�肳��Ă��܂��B:�C���X�^���XID<#%d> �G���e�B�e�B��<%s> �p�����[�^<%s>"},//-51002
	{SXFTYPELOGICAL,	"LOGICAL�^�łȂ��l���w�肳��Ă��܂��B:�C���X�^���XID<#%d> �G���e�B�e�B��<%s> �p�����[�^<%s>"},//-51003
	{SXFATTROPTIONAL,	"OPTIONALE�錾���Ă��Ȃ�������$�ɂȂ��Ă��܂��B:�C���X�^���XID<#%d> �G���e�B�e�B��<%s> �p�����[�^<%s>"},//-52002
	{SXFTYPEREAL,		"REAL�^�łȂ��l���w�肳��Ă��܂��B�B:�C���X�^���XID<#%d> �G���e�B�e�B��<%s> �p�����[�^<%s>"},//-51004
	{SXFTYPESTRING,		"STRING�^�łȂ��l���w�肳��Ă��܂��B�B:�C���X�^���XID<#%d> �G���e�B�e�B��<%s> �p�����[�^<%s>"},//-51005
	{SXFPARAMS,			"�����̐�������܂���B:�C���X�^���XID<#%d> �G���e�B�e�B��<%s>"},//-55001
	{SXFPARAMM,			"�����̐����������܂��B:�C���X�^���XID<#%d> �G���e�B�e�B��<%s>"},//-55002
	{SXFAGGRPARAMS,		"�W���^�̗v�f��������܂���B:�C���X�^���XID<#%d> �G���e�B�e�B��<%s>"},//-55003
	{SXFAGGRPARAMM,		"�W���^�̗v�f�����������܂��B:�C���X�^���XID<#%d> �G���e�B�e�B��<%s>"},//-55004
	{SXFNODICT,			"�s�K�؂ȕ����ł��B:�C���X�^���XID<#%d> �G���e�B�e�B��<%s> �p�����[�^<%s>"},//-50006
	{SXFNOREF,			"��x���Q�Ƃ���Ȃ��C���X�^���XID�ł��B:�C���X�^���XID<#%d> �G���e�B�e�B��<%s>" }//-57001
};

#endif