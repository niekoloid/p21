/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_leader_directed_calloutC.h								�쐬���F2000.4.18

	�P�D�N���X�T�v
	leader_directed_callout�̃G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
#ifndef _E_LEADER_DIRECTED_CALLOUT_H_
#define _E_LEADER_DIRECTED_CALLOUT_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
class SXFD_AggrC;
class SXFPart21FileC;
//
//
//
class SXFE_leader_directed_calloutC : public SXFD_InstC {
public :
//
//	Constructor
//
	SXFE_leader_directed_calloutC(SXFD_StrC*,SXFD_AggrC*);
//
//
//
	void WriteP21(SXFPart21FileC *IN_file);
} ;

#endif	// _E_LEADER_DIRECTED_CALLOUT_H_
