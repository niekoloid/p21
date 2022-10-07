/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapAnnoBodyC.h						�쐬���F2000.04.21

	�P�D�N���X�T�v
		ANNOTATION_OCCURRENCE�n��BODY���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.21	

**/
#ifndef _SXFMapAnnoBodyC_CLASS_
#define _SXFMapAnnoBodyC_CLASS_

#include <afx.h>
#include "SXFMapEntityBaseC.h"
#include "SXFF_FeatureTypeE.h"

class SXFInstanceIDC;
class SXFTableManagerC;
class SXFReadAP202ManagerC;

class SXFMapAnnoBodyC: public SXFMapEntityBaseC{
public:
//
//	<�f�t�H���g�R���X�g���N�^>
	SXFMapAnnoBodyC( );

//	<�C���X�^���X�h�c�ւ̃|�C���^��o�^����������>
//	SXFMapAnnoBodyC(SXFInstanceIDC* IN_InstanceIDManeger);
//	SXFMapAnnoBodyC(SXFInstanceIDC* IN_InstanceIDManeger, SXFTableManagerC* IN_TableManager);
	SXFMapAnnoBodyC(SXFInstanceIDC* IN_InstanceIDManeger, 
					SXFTableManagerC* IN_TableManager,
					SXFReadAP202ManagerC* IN_ReadManager);

//
//	<�f�X�g���N�^>
	virtual	~SXFMapAnnoBodyC( );

//
//	<�t�B�[�`���\���̂ւ̒l�̐ݒ�>
//	int	SetParameter(E_type OUT_Type,	LPVOID	OUT_Class);
	int	SetParameter();

	//	<Body��ʔ���>
	int	CheckBodyKind() ;

//	<���C���R�[�h>
	int 	m_layer;

//	<�t�B�[�`���^�C�v>
	E_type	m_Type;
//	<�t�B�[�`���N���X�ւ̃|�C���^>
	void*	m_Class;
		
//< ANNOTATION_OCCURRENCE�n >/////////////////////////////////////
	int	m_AnnoKind;
//	E_AnnoKindtype	m_AnnoKind;
//	NONSTYLE,		//0:�s��
//	CURVESTYLE,		//1:
//	SYMBOLSTYLE,	//2:
//	FILLSTYLE,		//3:
//	TEXTSTYLE,		//4:
//	NULLSTYLE		//5:

//< ANNOTATION_CURVE_OCCURRENCE�̎�� >////////////////////////////
	int	m_CurveKind;
//	E_CurveKindtype m_CurveKind;
//	NONCURVE,			//0:�s��
//	CURVE,				//1:��ʗv�f
//	DIMENSION_CURVE,	//2:���@���i���`�j
//	PROJECTION_CURVE	//3:���@�⏕��
//	LEADER_CURVE		//4:���o�����i���`�j


//< ANNOTATION_SYMBOL_OCCURRENCE�̎�� >////////////////////////////
	int	m_SymbolKind;
//	E_SymbolKindtype m_SymbolKind;
//	NONSYMBOL,							//0:�s��
//	SYMBOL,							//1:�_�}�[�J�A����`�i�O����`�j�A���̑��V���{��
//	DIM_CURVE_TERMINATOR,			//2:���@�[�_���
//	LEADER_TERMINATOR,				//3:�����o�����A�o���[���[�_���
//	SUBFIGURE_OCCURRENCE			//4:�����}�`�z�u�iSUbfigure�j

//	<�e�ʂ�name�p�����^>
	CString m_namepara;

private :

protected :


//	<�}�`�C���X�^���X���ւ̂h�c>
	int		m_InstID ;
//	<�}�`�������ւ̂h�c>
	int		m_AppeID ;

//	<�}�`�C���X�^���X���ւ̃|�C���^>
	void*	m_InstP ;
//	<�}�`�������ւ̃|�C���^>
	void*	m_AppeP ;

//	<SXFTableManagerC�ւ̃|�C���^>
	SXFTableManagerC* m_TableManager;

//	<SXFReadAP202ManagerC�ւ̃|�C���^>
	SXFReadAP202ManagerC* m_ReadManager;

//	<SXFMapAnnoBodyC�ւ̃|�C���^>
	SXFMapAnnoBodyC* m_tilebody;

};

#endif
