/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntCConvC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		Complex�^EntityArrayData���^�ϊ�����

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#ifndef _SXFMapEntCConvC_CLASS_
#define _SXFMapEntCConvC_CLASS_

//#include <afx.h>
//#include <afxtempl.h>

//#include "SXFSplitAP202C.h"
#include "SXFMapEntAConvC.h"

class SXFMapEntCConvC : public SXFMapEntAConvC{
public :
//
//	<�f�t�H���g�R���X�g���N�^>
	SXFMapEntCConvC( ) ;

//	<�R���X�g���N�^>
	SXFMapEntCConvC(CStringArray* IN_ComplexArray ) ;
//	SXFMapEntCConvC(CStringArray&) ;

//	<�f�X�g���N�^>
//
	virtual	~SXFMapEntCConvC() ;

//�G���e�B�e�B���ƃG���e�B�e�B�f�[�^�̓o�^
	int	SetCompelexArray(CStringArray* IN_ComplexArray);

//
//	<Complex�^Entity�̎w�肳�ꂽ�G���e�B�e�B�̃f�[�_�𕪊�����>
//	CStringArray*		ConvCStringArray(CString&);
	BOOL	SplitComplex(CString& IN_EntityName);
	BOOL	SplitComplex(char* IN_EntityName);
/*
	SXFMapEntDConvC(CString*) ;
	SXFMapEntDConvC(CString&) ;
	SXFMapEntDConvC(char*) ;
*/

private :


protected :

//
//	<�G���e�B�e�B��>
	CString		m_EntityName;
//
//	<ComplexEntity�̑S�f�[�^>
	CStringArray*	m_ComplexArray;

//	<SXFMapEntAConvC�ւ̃|�C���^>
//	SXFMapEntAConvC*  m_convertP; 

	CStringArray m_EntityArrayTempEntC;

} ;

#endif

////////////////////////////
