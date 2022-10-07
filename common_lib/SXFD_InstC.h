/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_InstC.h						�쐬���F2000.04.12

	�P�D�N���X�T�v
		�C���X�^���X��ێ����o�͂���N���X

	�Q�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.12	�{��(FQS)	�Ȃ��B
**/
#ifndef _SXFD_INSTC_H_
#define _SXFD_INSTC_H_
#include "SXFInstanceC.h"
#include <afx.h>

class SXFPart21FileC;
//
//	APP INSTANCE DEFINITION
//
class SXFD_InstC : public SXFInstanceC{
protected :
	int			m_Flg;
	int			m_InstanceID ;
	CString  	m_Entity ;
	CObList		m_Data ;
public :
//
//	Default Constructor
//
	SXFD_InstC( ) ;
//
//	Constructor
//
	SXFD_InstC(int) ;
//
//	Destructor
//
	~SXFD_InstC( ) ;
//
//	Entity Definition
//
	void	SetEntity( CString ) ;
//
//	Instance Attribute Data Definition
//
	void	AddAttr( CObject * ) ;
//
//
//
	CObList&	GetAttr(  ) ;
//
//
//
//	void		SetInsID();
//
//
//
	int		GetInsID();
//
//
//
    void	WriteP21(SXFPart21FileC *IN_file) ;
//
//
//
	void    WriteAttr(SXFPart21FileC *IN_file);
} ;

#endif	// _D_INST_H_
