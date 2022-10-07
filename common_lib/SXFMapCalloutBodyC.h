/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapCalloutBodyC.h						�쐬���F2000.04.21

	�P�D�N���X�T�v
		DRAUGHTING_CALLOUT�n��BODY���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.21	

**/
#ifndef _SXFMapCalloutBodyC_CLASS_
#define _SXFMapCalloutBodyC_CLASS_

#include <afx.h>
#include "SXFMapEntityBaseC.h"
#include "SXFF_FeatureTypeE.h"

class SXFInstanceIDC;
class SXFTableManagerC;
class SXFReadAP202ManagerC;

class SXFMapAnnoBodyC;
class SXFMapF_LINEC;
class SXFMapF_ARCC;
class SXFMapF_POLYLINEC;
class SXFMapF_CIRCLEC;
class SXFMapF_TERMSYMBOLC;
class SXFMapF_TEXTSTRINGC;

class SXFMapCalloutBodyC: public SXFMapEntityBaseC{
public :
//
//	<�f�t�H���g�R���X�g���N�^>
	SXFMapCalloutBodyC( );

//	<�C���X�^���X�h�c�ւ̃|�C���^��o�^����������>
//	SXFMapCalloutBodyC(SXFInstanceIDC* IN_InstanceIDManeger) ;
//	SXFMapCalloutBodyC(SXFInstanceIDC* IN_InstanceIDManeger, SXFTableManagerC* IN_TableManager) ;
	SXFMapCalloutBodyC(
			SXFInstanceIDC* IN_InstanceIDManeger, 
			SXFTableManagerC* IN_TableManager,
			SXFReadAP202ManagerC* IN_ReadManager);

//
//	<�f�X�g���N�^>
	virtual	~SXFMapCalloutBodyC() ;

//
//	<�t�B�[�`���\���̂ւ̒l�̐ݒ�>
//	int	SetFeatureParameter(E_type OUT_Type,	LPVOID	OUT_Class);
	int	SetFeatureParameter( );

//
//	<Body��ʔ���>
	int	CheckBodyKind() ;

//	<���C���R�[�h>
	int 	m_layer;
//	<�t�B�[�`���^�C�v>
	E_type	m_Type;
//	<�t�B�[�`���N���X�ւ̃|�C���^>
	void*	m_Class;

private :

protected :

//< DRAUGHTING_CALLOUT�n >/////////////////////////////////////
	int		m_CalloutKind;
//		0:�s��
//		1:DIMENSION_CURVE_DIRECTED_CALLOUT
//		2:LEADER_DIRECTED_CALLOUT

//< DIMENSION�n >/////////////////////////////////////
	int	m_DimensionKind;
//		0:NONDIMENSION
//		1:LINEAR_DIMENSION
//		2:ANGULAR_DIMENSION
//		3:DIAMETER_DIMENSION
//		4:RADIUS_DIMENSION
//		5:CURVE_DIMENSION

//< LEADER�n >/////////////////////////////////////
	int	m_LavelKind;
//		0:NONLEADER
//		1:LABEL
//		2:BALLOON

//	<�R���e���c�ւ̂h�c>
	CArray<int,int>		m_ContentsID ;
//	<�R���e���c�֐�>
	int		m_ContentsNum;

//	<�R���e���c�ւ̃|�C���^>
	CArray<SXFMapAnnoBodyC*,SXFMapAnnoBodyC*>	m_ContentsP ;

//	<SXFTableManagerC�ւ̃|�C���^>
	SXFTableManagerC* m_TableManager;

//	<SXFReadAP202ManagerC�ւ̃|�C���^>
	SXFReadAP202ManagerC* m_ReadManager;

// DIMENSION LINE �t���O
	int m_dimline;
//DIMENSION ARC �t���O
	int m_dimarc;
// DIMENSION TEXT �t���O
	int m_dimtext;
// PROJECTION LINE1 �t���O
	int m_prjline1;
// PROJECTION LINE2 �t���O
	int m_prjline2;
// LEADER CURVE �t���O
	int m_leader;
// TERM1 �t���O
	int m_term1;
// TERM2 �t���O
	int m_term2;
// CIRCLE �t���O
	int	m_balloon;

// DIMENSION LINE �ւ̃|�C���^
	SXFMapF_LINEC* m_dimlineP;

//DIMENSION ARC �ւ̃|�C���^
	SXFMapF_ARCC* m_dimarcP;

// DIMENSION TEXT �ւ̃|�C���^
	SXFMapF_TEXTSTRINGC* m_dimtextP;

// PROJECTION LINE1 �ւ̃|�C���^
	SXFMapF_LINEC* m_prjline1P;

// PROJECTION LINE2 �ւ̃|�C���^
	SXFMapF_LINEC* m_prjline2P;

// LEADER CURVE�ւ̃|�C���^
	SXFMapF_POLYLINEC* m_leaderP;

// TERM1 �ւ̃|�C���^
	SXFMapF_TERMSYMBOLC* m_term1P;

// TERM2 �ւ̃|�C���^
	SXFMapF_TERMSYMBOLC* m_term2P;

// CIRCLE �ւ̃|�C���^
	SXFMapF_CIRCLEC*	m_balloonP;

} ;
#endif
