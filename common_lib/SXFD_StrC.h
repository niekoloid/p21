/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_StrC.h						�쐬���F2000.04.12

	�P�D�N���X�T�v
		�����^�v�f��ێ����o�͂���N���X

	�Q�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.12	�{��(FQS)	�Ȃ��B
**/
#ifndef _SXFD_STRC_H_
#define _SXFD_STRC_H_

#include "SXFInstanceC.h"
#include <afx.h>

class SXFPart21FileC;
//
//	STRING DEFINITION
//
class SXFD_StrC : public SXFInstanceC {
protected :
	CString		m_Data ;
public :
//
//	Default Constructor
//
	SXFD_StrC( ) { }
//
//	Constructor with Data
//
	SXFD_StrC(char*) ;
//
//	Destructor
//
	~SXFD_StrC( ) { }
//
//	Data Set
//
	void	SetData( char* ) ;
//
//	Data Get
//
	LPCTSTR	GetData( ) ;
//
//
//
	void WriteP21(SXFPart21FileC *IN_file){}
	void WriteAttr(SXFPart21FileC *IN_file);
} ;

#endif	// _D_STRING_H_
