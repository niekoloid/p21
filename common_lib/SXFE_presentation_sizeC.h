/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_presentation_sizeC.h								ì¬úF2000.4.18

	PDNXTv
	presentation_sizeÌGeBeBf[^Ç

	QDð
	ðÔ		út¯				SÒ				Tv
	ì¬			2000.4.18			{(FQS)			ÈµB

**/
#ifndef _E_PRESENTATION_SIZE_H_
#define _E_PRESENTATION_SIZE_H_

#include "SXFD_InstC.h"

class SXFPart21FileC;
//
//
//
class SXFE_presentation_sizeC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_presentation_sizeC(SXFD_InstC*,SXFD_InstC*);
	void WriteP21(SXFPart21FileC *IN_file);
} ;

#endif	// _E_PRESENTATION_SIZE_H_
