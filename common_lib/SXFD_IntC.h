/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_InstC.h						�쐬���F2000.04.12

	�P�D�N���X�T�v
		�����^�v�f��ێ����o�͂���N���X

	�Q�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.12	�{��(FQS)	�Ȃ��B
**/
#ifndef _SXFD_INTC_H_
#define _SXFD_INTC_H_

#include "SXFInstanceC.h"

class SXFPart21FileC;
//
//	INT DEFINITION
//
class SXFD_IntC : public SXFInstanceC {
protected :
	int	m_Data ;
public :
//
//	Default Constructor
//
	SXFD_IntC( ) { }
//
//	Constructor with Data
//
	SXFD_IntC(int) ;
//
//	Destructor
//
	~SXFD_IntC( ) { }
//
//	Data Set
//
	void	SetData( int data ) ;
//
//	Data Get
//
	int	GetData( ) ;
//
//
//
	void WriteP21(SXFPart21FileC *IN_file){}
	void WriteAttr(SXFPart21FileC *IN_file);
} ;

#endif	// _SXFD_INTC_H_
