/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_curve_style_fontC.h								�쐬���F2000.4.18

	�P�D�N���X�T�v
	curve_style_font�̃G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
#ifndef _E_CURVE_STYLE_FONT_H_
#define _E_CURVE_STYLE_FONT_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
class SXFD_AggrC;
class SXFD_ListAggrC;
//
//
//
class SXFE_curve_style_fontC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_curve_style_fontC(SXFD_StrC*,SXFD_AggrC*);
	SXFE_curve_style_fontC(SXFD_StrC*,SXFD_ListAggrC*);
} ;

#endif	// _E_CURVE_STYLE_FONT_H_
