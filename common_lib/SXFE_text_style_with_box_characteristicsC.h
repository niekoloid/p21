/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_text_style_with_box_characteristicsC.h								�쐬���F2000.4.18

	�P�D�N���X�T�v
	text_style_with_box_characteristics�̃G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
#ifndef _E_TEXT_STYLE_WITH_BOX_CHARACTERISTICS_H_
#define _E_TEXT_STYLE_WITH_BOX_CHARACTERISTICS_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
class SXFD_TypeC;
class SXFD_RealC;
class SXFD_AggrC;
class SXFPart21FileC;
//
//
//
class SXFE_text_style_with_box_characteristicsC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_text_style_with_box_characteristicsC(SXFD_StrC*,SXFD_InstC*,SXFD_AggrC*,SXFD_TypeC*);
//
//
//
	void WriteP21(SXFPart21FileC *IN_file);
} ;

#endif	// _E_TEXT_STYLE_WITH_BOX_CHARACTERISTICS_H_
