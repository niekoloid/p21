/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapAssemblyC.h						�쐬���F2000.04.21

	�P�D�N���X�T�v
		ASSEMBLY�v�f��BODY���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.21	

**/
#ifndef _SXFMapAssemblyC_CLASS_
#define _SXFMapAssemblyC_CLASS_

#include <afx.h>
#include "SXFMapEntityBaseC.h"
#include "SXFF_FeatureTypeE.h"


class SXFInstanceIDC;
class SXFTableManagerC;
class SXFComInfoC;

class SXFMapAssemblyC: public SXFMapEntityBaseC{
public :
//
//	<�f�t�H���g�R���X�g���N�^>
	SXFMapAssemblyC( ) ;

//	<�C���X�^���X�h�c�ւ̃|�C���^��o�^����������>
//	SXFMapAssemblyC(SXFInstanceIDC* IN_InstanceIDManeger) ;
//	SXFMapAssemblyC(SXFInstanceIDC* IN_InstanceIDManeger, 
//		SXFTableManagerC* IN_TableManager) ;
	SXFMapAssemblyC(
		SXFInstanceIDC* IN_InstanceIDManeger,
		SXFTableManagerC* IN_TableManager,
		SXFComInfoC* IN_ComInfoC ) ;

	//
//	<�f�X�g���N�^>
	virtual	~SXFMapAssemblyC() ;

//
//	<�t�B�[�`���N���X�ւ̒l�̐ݒ�>
//	int		SetFeatureParameter(int OUT_Type,	LPVOID	OUT_Class);
	int		SetFeatureParameter(int& OUT_Type,	LPVOID&	OUT_Class);

//
//	<�t�B�[�`���\���̂ւ̒l�̐ݒ�>
//	BOOL	SetStructData(E_type IN_Type,	LPVOID	IN_Class);
	BOOL	SetStructData(int IN_Type,	LPVOID	IN_Class);

//
//	<�t�B�[�`���\����(OUT_Struct)�ւ̃|�C���^�ԋp>
//	int		GetStructData(CString& OUT_TypeName, LPVOID OUT_Struct );
//	int		GetStructData( char*& OUT_Name, LPVOID OUT_Struct );
//	int		GetStructData( LPVOID OUT_Struct );
	int		GetStructData( LPVOID& OUT_Struct );

//
//	<��`�e�[�u���v�f�̃��[�gEntity�ւ̃|�C���^�̎擾>
//	void*	GetBodyP();

private :

protected :
//	<BODY���> ///////////////////////////////////////////////////////
	int		m_AsmKind;
//		0:�s��
//		1:DRAWING_SHEET_REVISION_USAGE
//		2:DRAUGHTING_CALLOUT
//		3:COMPOSITE_CURVE

//	<SXFTableManagerC�ւ̃|�C���^>
	SXFTableManagerC* m_TableManager;

//	<SXFComInfoC�ւ̃|�C���^>
	SXFComInfoC* m_ComInfoC;

//	<�A�Z���u���v�f�̃G���e�B�e�B�ւ̃|�C���^>
	void*	m_AssmP ;

//	<�t�B�[�`���^�C�v>
	E_type	m_Type;

//	<�t�B�[�`���N���X�ւ̃|�C���^>
	void*	m_Class;

//	<�t�B�[�`����>
//	CString	m_TypeName;
	char m_TypeName[30];

//	<�t�B�[�`���\���̂ւ̃|�C���^>
	void*	m_StructData;

//	<�A�Z���u���v�f��������A�v�f�Q�ւ̃C���X�^���X�h�c>
	CUIntArray m_Elements;

} ;
#endif
