/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_EnumC.h						�쐬���F2000.04.12

	�P�D�N���X�T�v
		�񋓌^�̗v�f��ێ����o�͂���N���X

	�Q�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.12	�{��(FQS)	�Ȃ��B
**/
#ifndef _SXFD_ENUMC_H_
#define _SXFD_ENUMC_H_

#include "SXFInstanceC.h"

class SXFPart21FileC;
//
//	ENUMETATION DEFINITION
//
class SXFD_EnumC : public SXFInstanceC {
protected :
	CString		m_Data ;
public :
//
//	Default Constructor
//
	SXFD_EnumC( ) { }
//
//	Constructor with Data
//
	SXFD_EnumC(char*) ;
//
//	Destructor
//
	~SXFD_EnumC( ) { }
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

#endif	// _D_ENUM_H_
