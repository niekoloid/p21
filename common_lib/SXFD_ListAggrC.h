/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_ListAggrC.cpp						�쐬���F2000.04.12

	�P�D�N���X�T�v
		�W���̌^�̗v�f��ێ����o�͂���N���X

	�Q�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.12	�{��(FQS)	�Ȃ��B
**/
#ifndef _SXFD_LISTAGGRC_H_
#define _SXFD_LISTAGGRC_H_

#include "SXFInstanceC.h"

#include <afx.h>

class SXFPart21FileC;

//
//	AGGR TYPE DEFINITION
//
class SXFD_ListAggrC : public SXFInstanceC {
protected :
	CObList		m_Data ;
public :
//
//	Default Constructor
//
	SXFD_ListAggrC() { }
//
//	Destructor
//
	~SXFD_ListAggrC( ) ;
//
//	Data Set Method
//
	void	AddElem( CObject* ) ;
//
//
//
	void	RemoveTail() ;

//
//
//
	void Remove();
//
//
//
	CObList& GetData();
//
//
//
	void WriteP21(SXFPart21FileC *IN_file) ;
//
//	
//	
	void WriteAttr(SXFPart21FileC *IN_file);

	BOOL Is_Empty();
} ;

#endif	// _D_AGGR_H_
