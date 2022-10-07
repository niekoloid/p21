/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapGeometryC.h						�쐬���F2000.04.21

	�P�D�N���X�T�v
		AP202�G���e�B�e�B����t�B�[�`���ւ̃}�b�s���O���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����			�T�v
		�쐬		2000.04.21	
		�X�V		2015.04.27	T.Matsushima	JPCERT/CC �w�E �Ǝ㐫�Ή�

**/
#ifndef _SXFMapGeometryC_CLASS_
#define _SXFMapGeometryC_CLASS_

#include <afx.h>
#include "SXFMapEntityBaseC.h"
#include "SXFF_FeatureTypeE.h"


class SXFMapAnnoBodyC;
class SXFMapCalloutBodyC;
class SXFMapCompBodyC;
class SXFInstanceIDC;
class SXFTableManagerC;
class SXFComInfoC;

class SXFMapGeometryC: public SXFMapEntityBaseC{
public :
//
//	<�f�t�H���g�R���X�g���N�^>
	SXFMapGeometryC( ) ;

//	<�C���X�^���X�h�c�ւ̃|�C���^��o�^����������>
//	SXFMapGeometryC(SXFInstanceIDC* IN_InstanceIDManeger) ;
//	SXFMapGeometryC(SXFInstanceIDC* IN_InstanceIDManeger, 
//		SXFTableManagerC* IN_TableManager) ;
	SXFMapGeometryC(
		SXFInstanceIDC* IN_InstanceIDManeger,
		SXFTableManagerC* IN_TableManager,
		SXFComInfoC* IN_ComInfoC,
		SXFReadAP202ManagerC* IN_ReadManager);

	//
//	<�f�X�g���N�^>
	virtual	~SXFMapGeometryC() ;

//
//	<�t�B�[�`���N���X�ւ̒l�̐ݒ�>
	int		SetFeatureParameter(int& OUT_Type,	LPVOID&	OUT_Class);

//
//	<�t�B�[�`���\���̂ւ̒l�̐ݒ�>
//	BOOL	SetStructData(E_type IN_Type,	LPVOID	IN_Class);
//	BOOL	SetStructData(int& IN_Type,	LPVOID&	IN_Class);
	BOOL	SetStructData(int  IN_Type,	LPVOID	IN_Class);

//
//	<�t�B�[�`���\���̂ւ̃|�C���^�ԋp>
//	int		GetStructData(CString& OUT_TypeName, LPVOID OUT_Struct );
//	int		GetStructData( char*& OUT_Name, LPVOID& OUT_Struct );					JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
	int		GetStructData( char*& OUT_Name, size_t NameSize, LPVOID& OUT_Struct );	// �o�b�t�@�T�C�Y��n���悤�ɕύX

	//�_�E���R���o�[�g�p
	int GetStructDataLevel( char*& OUT_Name, LPVOID& OUT_Struct,int& OUT_Level );

//
//	<��`�e�[�u���v�f�̃��[�gEntity�ւ̃|�C���^�̎擾>
//	void*	GetBodyP();


private :

protected :
//	<BODY���> ///////////////////////////////////////////////////////
	int		m_BodyKind;
//		0:�s��
//		1:ANNOTATION_OCCURRENCE
//		2:DRAUGHTING_CALLOUT
//		3:COMPOSITE_CURVE_SEGMENT

//	<SXFTableManagerC�ւ̃|�C���^>
	SXFTableManagerC* m_TableManager;
	
//	<SXFComInfoC�ւ̃|�C���^>
	SXFComInfoC* m_ComInfoC;

//	<�t�B�[�`���^�C�v>
	E_type	m_Type;

//	<�t�B�[�`���N���X�ւ̃|�C���^>
	void*	m_Class;

//	<�t�B�[�`����>
//	CString	m_TypeName;
    char m_TypeName[30];

//	<�t�B�[�`���\���̂ւ̃|�C���^>
	void*	m_StructData;

	SXFReadAP202ManagerC* m_ReadManager;

	//�_�E���R���o�[�g���Ɏg�p
	//�t�B�[�`���̃��x��
	int m_Level;

	SXFMapCalloutBodyC* m_calloutbody;
	SXFMapAnnoBodyC* m_annobody;
	SXFMapCompBodyC* m_compbody;
} ;
#endif
