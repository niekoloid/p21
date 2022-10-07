/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_TypeC.h						�쐬���F2000.04.12

	�P�D�N���X�T�v
		Type�^�v�f��ێ����o�͂���N���X

	�Q�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.12	�{��(FQS)	�Ȃ��B
**/
#ifndef _SXFD_TYPEC_H_
#define _SXFD_TYPEC_H_

#include "SXFInstanceC.h"
#include <afx.h>

class SXFPart21FileC;
//
//	TYPE DEFINITION
//
class SXFD_TypeC : public SXFInstanceC {
protected :
	CString		m_Data ;
	SXFInstanceC*	m_Next ;
public :
//
//	Default Constructor
//
	SXFD_TypeC( ) { }
//
//	Constructor with Name
//
	SXFD_TypeC( char* ) ;
//
//	Destructor
//
	~SXFD_TypeC( ) { }
//
//	Next Data Set Method
//
	void	SetNext( SXFInstanceC* ) ;
//
//	Data Get
//
	LPCTSTR	GetData( ) ;
//
//
//
	SXFInstanceC* GetNext( ) ;
//
//
//
	void WriteP21(SXFPart21FileC *IN_file);
	void WriteAttr(SXFPart21FileC *IN_file);
} ;

#endif	// _D_TYPE_H_
