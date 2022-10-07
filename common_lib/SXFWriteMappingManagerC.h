/**
	All Rights Reserved,(c) JACIC 2001
	SXFWriteMappingManagerC.h								�쐬���F2001.06.14

	�P�D�N���X�T�v
	Write���̃t�B�[�`���I�u�W�F�N�g��Mapping�I�u�W�F�N�g�̊Ǘ����s���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.14			���X��(FQS)			�Ȃ��B
	�X�V			2001.09.18			K.Naono				�n�b�`���O��Q�Ή�

**/

#if !defined(AFX_SXFWRITEMAPPINGMANAGERC_H__A623AA20_11F2_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFWRITEMAPPINGMANAGERC_H__A623AA20_11F2_11D4_A76E_00000EB03267__INCLUDED_

#include "SXFStruct.h"	// ClassView �ɂ���Ēǉ�����܂����B
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"
#include "SXFWriteManagerC.h"

class SXFSfigMappingC;
class SXFSheetMappingC;
class SXFCompCurveMappingC;
class SXFLineMappingC;
class SXFTextStringMappingC;
class SXFPart21FileC;
class SXFTableManagerC;
class SXFPointMarkerMappingC;
class SXFCircleMappingC;
class SXFArcMappingC;
class SXFEllipseMappingC;
class SXFEllipseArcMappingC;
class SXFPolylineMappingC;
class SXFSplineMappingC;
class SXFClothoidMappingC;
class SXFCirlceMappingC;
class SXFLinearDimMappingC;
class SXFCurveDimMappingC;
class SXFAngularDimMappingC;
class SXFDiameterDimMappingC;
class SXFRadiusDimMappingC;
class SXFLabelMappingC;
class SXFBalloonMappingC;
class SXFExSymbolMappingC;
class SXFSfiglocMappingC;
class SXFExHatchMappingC;
class SXFFillColourMappingC;
class SXFFillHatchingMappingC;
class SXFFillTilesMappingC;
class SXFInvisibilityMappingC;
class SXFComInfoC;
class SXFPart21FileWriteC;
class SXFInstanceIDC;
class SXFFeatureC;
class SXFAttrMappingC;

class SXFWriteMappingManagerC  
{
public:
	BOOL SetStructData(char* IN_FeatureType,LPVOID IN_Struct);
	int MappingFeature(
				char*	IN_FeatureType,
				LPVOID	IN_Struct,
				int&	OUT_Id1,
				int&	OUT_Id2,
				double&	INOUT_PointX,
				double&	INOUT_PointY,
				int &INOUT_PointN);
	void ClearData();
	BOOL MappingAssembly(
				CUIntArray*	IN_ChildrenID,
				int&		OUT_AssemblyID1,
				int&		OUT_AssemblyID2,
				int&		OUT_PointID,
				double		IN_PointX,
				double		IN_PointY);
	BOOL SetStructData(int IN_Asem_Type,LPVOID IN_Struct);
	SXFWriteMappingManagerC();
	SXFWriteMappingManagerC(
						SXFPart21FileC*					IN_File,
						SXFTableManagerC*				IN_TableManager,
						int								IN_AssemType,
						CUIntArray*						IN_AssemblyTable,
//	MOD(S)	�n�b�`���O��Q�Ή�	K.Naono		01.09.18
//						CUIntArray*						IN_PointTable,
						CArray<SXF_POINT,SXF_POINT&>*	IN_PointTable,
//	MOD(E)	�n�b�`���O��Q�Ή�	K.Naono		01.09.18
//	MOD(S)	�`���[�j���O�Ή�	K.Naono		03.07.08
//						SXFSFIGORGTABLE*				IN_SfigorgTable,
						CMapStringToPtr*				IN_SfigorgTable,
//	MOD(E)	�`���[�j���O�Ή�	K.Naono		03.07.08
						SXFComInfoC*					IN_ComInfo,
						SXFPart21FileWriteC*			IN_WriteFile,
						SXFInstanceIDC*					IN_InstanceIDManager);
	SXFWriteMappingManagerC(SXFPart21FileC* IN_File);
	virtual ~SXFWriteMappingManagerC();

	BOOL MappingInvisibility(CUIntArray* IN_InvisibilityTable);

//	MOD(S)	�`���[�j���O�Ή�	K.Naono		03.07.08
//	SXFSFIGORGTABLE *m_SfigorgTable;
	CMapStringToPtr*	m_SfigorgTable ;
//	MOD(E)	�`���[�j���O�Ή�	K.Naono		03.07.08

private:
	////////////////////////////////
	//�A�Z���u���t�B�[�`���I�u�W�F�N�g
	////////////////////////////////
	SXFFeatureC* m_AsemFeature;
	////////////////////////////////
	//�t�B�[�`���I�u�W�F�N�g
	////////////////////////////////
	SXFFeatureC* m_Feature;

	////////////////////////////////
	//�t�@�C���I�u�W�F�N�g
	////////////////////////////////
	SXFPart21FileC* m_Part21File;
	////////////////////////////////
	//�t�@�C���o�̓I�u�W�F�N�g
	////////////////////////////////
	SXFPart21FileWriteC* m_WriteFile;

	////////////////////////////////
	//���ʏ��Ǘ��I�u�W�F�N�g
	////////////////////////////////
	SXFComInfoC* m_ComInfo;
	////////////////////////////////
	//�C���X�^���XID�I�u�W�F�N�g
	////////////////////////////////
	SXFInstanceIDC* m_InstanceIDManager;
	////////////////////////////////
	//��`�e�[�u���Ǘ��I�u�W�F�N�g
	////////////////////////////////
	SXFTableManagerC* m_TableManager;

	////////////////////////////////
	//�t�B�[�`���^
	////////////////////////////////
	char* m_FeatureType;
	////////////////////////////////
	//�A�Z���u���^
	////////////////////////////////
	int m_AssemType;

	////////////////////////////////
	//�A�Z���u���e�[�u��
	////////////////////////////////
	CUIntArray *m_AssemblyTable;
	////////////////////////////////
	//�n�b�`���O�����̓_�̃e�[�u��
	////////////////////////////////
//	MOD(S)	�n�b�`���O��Q�Ή�	K.Naono		01.09.18
//	CUIntArray *m_PointTable;
	CArray<SXF_POINT,SXF_POINT&>*	m_PointTable ;
//	MOD(E)	�n�b�`���O��Q�Ή�	K.Naono		01.09.18

	////////////////////////////////
	//�p���\����
	////////////////////////////////
	Sheet_Struct m_Sheet_Str;
	////////////////////////////////
	//�_�}�[�J�\����
	////////////////////////////////
	Point_Marker_Struct m_Point_Marker_Str;
	////////////////////////////////
	//�����\����
	////////////////////////////////
	Line_Struct m_Line_Str;
	////////////////////////////////
	//�ܐ��\����
	////////////////////////////////
	Polyline_Struct m_Polyline_Str;
	////////////////////////////////
	//�~�\����
	////////////////////////////////
	Circle_Struct m_Circle_Str;
	////////////////////////////////
	//�~�ʍ\����
	////////////////////////////////
	Arc_Struct m_Arc_Str;
	////////////////////////////////
	//�ȉ~�\����
	////////////////////////////////
	Ellipse_Struct m_Ellipse_Str;
	////////////////////////////////
	//�ȉ~�ʍ\����
	////////////////////////////////
	Ellipse_Arc_Struct m_Ellipse_Arc_Str;
	////////////////////////////////
	//�����v�f�\����
	////////////////////////////////
	Text_Struct m_Text_String_Str;
	////////////////////////////////
	//�X�v���C���\����
	////////////////////////////////
	Spline_Struct m_Spline_Str;
	////////////////////////////////
	//�N���\�C�h�\����
	////////////////////////////////
	Clothoid_Struct m_Clothoid_Str;
	////////////////////////////////
	//�����}�`��`�\����
	////////////////////////////////
	Sfigorg_Struct m_Sfigorg_Str;
	////////////////////////////////
	//�����}�`�z�u�\����
	////////////////////////////////
	Sfigloc_Struct m_Sfigloc_Str;
	////////////////////////////////
	//����`�V���{���\����
	////////////////////////////////
	Externally_Defined_Symbol_Struct m_ExSymbol_Str;
	////////////////////////////////
	//�������@�\����
	////////////////////////////////
	LinearDim_Struct m_LinearDim_Str;
	////////////////////////////////
	//�ʒ����@�\����
	////////////////////////////////
	CurveDim_Struct m_CurveDim_Str;
	////////////////////////////////
	//�p�x���@�\����
	////////////////////////////////
	AngularDim_Struct m_AngularDim_Str;
	////////////////////////////////
	//���a���@�\����
	////////////////////////////////
	RadiusDim_Struct m_RadiusDim_Str;
	////////////////////////////////
	//���a���@�\����
	////////////////////////////////
	DiameterDim_Struct m_DiameterDim_Str;
	////////////////////////////////
	//�����o�����\����
	////////////////////////////////
	Label_Struct m_Label_Str;
	////////////////////////////////
	//�o���[���\����
	////////////////////////////////
	Balloon_Struct m_Balloon_Str;
	////////////////////////////////
	//�n�b�`���O�i�O����`�j�\����
	////////////////////////////////
	Externally_Defined_Hatch_Struct m_ExHatch_Str;
	////////////////////////////////
	//�n�b�`���O�i�h��)�\����
	////////////////////////////////
	Fill_area_style_colour_Struct m_FillColour_Str;
	////////////////////////////////
	//�n�b�`���O�i���[�U��`�j�\����
	////////////////////////////////
	Fill_area_style_hatching_Struct m_FillHatching_Str;
	////////////////////////////////
	//�n�b�`���O(�p�^�[��)�\����
	////////////////////////////////
	Fill_area_style_tiles_Struct m_FillTiles_Str;
	////////////////////////////////
	//�����Ȑ��\����
	////////////////////////////////
	Ccurve_Org_Struct m_CompCurve_Str;

	////////////////////////////////
	//�p��Mapping�I�u�W�F�N�g
	////////////////////////////////
	SXFSheetMappingC* m_SheetMapping;

//	ADD(S)	Ver3.0�Ή�	K.Naono	04.01.30
	//	�}�ʕ\�藓Mapping�I�u�W�F�N�g
	SXFAttrMappingC* m_AttrMapping ;
//	ADD(E)	Ver3.0�Ή�	K.Naono	04.01.30

	////////////////////////////////
	//�_�}�[�JMapping�I�u�W�F�N�g
	////////////////////////////////
	SXFPointMarkerMappingC* m_PointMarkerMapping;
	////////////////////////////////
	//����Mapping�I�u�W�F�N�g
	////////////////////////////////
	SXFLineMappingC* m_LineMapping;
	////////////////////////////////
	//�ܐ�Mapping�I�u�W�F�N�g
	////////////////////////////////
	SXFPolylineMappingC* m_PolylineMapping;
	////////////////////////////////
	//�~Mapping�I�u�W�F�N�g
	////////////////////////////////
	SXFCircleMappingC* m_CircleMapping;
	////////////////////////////////
	//�~��Mapping�I�u�W�F�N�g
	////////////////////////////////
	SXFArcMappingC* m_ArcMapping;
	////////////////////////////////
	//�ȉ~Mapping�I�u�W�F�N�g
	////////////////////////////////
	SXFEllipseMappingC* m_EllipseMapping;
	////////////////////////////////
	//�ȉ~��Mapping�I�u�W�F�N�g
	////////////////////////////////
	SXFEllipseArcMappingC* m_EllipseArcMapping;
	////////////////////////////////
	//�����v�fMapping�̃I�u�W�F�N�g
	////////////////////////////////
	SXFTextStringMappingC* m_TextStringMapping;
	////////////////////////////////
	//�X�v���C��Mapping�I�u�W�F�N�g
	////////////////////////////////
	SXFSplineMappingC* m_SplineMapping;
	////////////////////////////////
	//�N���\�C�hMapping�I�u�W�F�N�g
	////////////////////////////////
	SXFClothoidMappingC* m_ClothoidMapping;
	////////////////////////////////
	//�����}�`��`Mapping�I�u�W�F�N�g
	////////////////////////////////
	SXFSfigMappingC* m_SfigMapping;
	////////////////////////////////
	//�����}�`�z�uMapping�̃I�u�W�F�N�g
	////////////////////////////////
	SXFSfiglocMappingC* m_SfiglocMapping;
	////////////////////////////////
	//����`�V���{��Mapping�̃I�u�W�F�N�g
	////////////////////////////////
	SXFExSymbolMappingC* m_ExSymbolMapping;
	////////////////////////////////
	//�������@Mapping�̃I�u�W�F�N�g
	////////////////////////////////
	SXFLinearDimMappingC* m_LinearDimMapping;
	////////////////////////////////
	//�ʒ����@Mapping�̃I�u�W�F�N�g
	////////////////////////////////
	SXFCurveDimMappingC* m_CurveDimMapping;
	////////////////////////////////
	//�p�x���@Mapping�̃I�u�W�F�N�g
	////////////////////////////////
	SXFAngularDimMappingC* m_AngularDimMapping;
	////////////////////////////////
	//���a���@Mapping�̃I�u�W�F�N�g
	////////////////////////////////
	SXFRadiusDimMappingC* m_RadiusDimMapping;
	////////////////////////////////
	//���a���@Mapping�I�u�W�F�N�g
	////////////////////////////////
	SXFDiameterDimMappingC* m_DiameterDimMapping;
	////////////////////////////////
	//�n�b�`���O(�p�^�[���jMapping�̃I�u�W�F�N�g
	////////////////////////////////
	SXFFillTilesMappingC* m_FillTilesMapping;
	////////////////////////////////
	//�n�b�`���O�i���[�U��`�jMapping�̃I�u�W�F�N�g
	////////////////////////////////
	SXFFillHatchingMappingC* m_FillHatchingMapping;
	////////////////////////////////
	//�n�b�`���O�i�h��jMapping�̃I�u�W�F�N�g
	////////////////////////////////
	SXFFillColourMappingC* m_FillColourMapping;
	////////////////////////////////
	//�n�b�`���O(�O����`�jMapping�̃I�u�W�F�N�g
	////////////////////////////////
	SXFExHatchMappingC* m_ExHatchMapping;
	////////////////////////////////
	//�o���[��Mapping�̃I�u�W�F�N�g
	////////////////////////////////
	SXFBalloonMappingC* m_BalloonMapping;
	////////////////////////////////
	//�����o����Mapping�̃I�u�W�F�N�g
	////////////////////////////////
	SXFLabelMappingC* m_LabelMapping;
	////////////////////////////////
	//�����Ȑ�Mapping�I�u�W�F�N�g
	////////////////////////////////
	SXFCompCurveMappingC* m_CompCurveMapping;

	////////////////////////////////
	//INVISIBILITY_Mapping�I�u�W�F�N�g
	////////////////////////////////
	SXFInvisibilityMappingC* m_InvisibilityMapping;

};

#endif // !defined(AFX_SXFWRITEMAPPINGMANAGERC_H__A623AA20_11F2_11D4_A76E_00000EB03267__INCLUDED_)
