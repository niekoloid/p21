/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapAnnoBodyC.cpp						�쐬���F2000.04.21

	�P�D�N���X�T�v
		ANNOTATION_OCCURRENCE�n��BODY���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.21	

**/

#include "stdafx.h"
#include <math.h>
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_CurveStyleBaseC.h"
#include "SXFMapF_ColorBaseC.h"
#include "SXFutyFunctionC.h"
#include "SXFMapEntCConvC.h"
//#include "ComSplitStringC.h"
#include "SXFTableManagerC.h"
#include "SXFReadAP202ManagerC.h"
#include "SXFMapE_STYLED_ITEMC.h" 
#include "SXFMapE_TRIMMED_CURVEC.h"
#include "SXFMapE_CARTESIAN_POINTC.h"
#include "SXFMapE_AXIS2_PLACEMENT_2DC.h"
#include "SXFMapE_VECTORC.h"
#include "SXFMapE_DIRECTIONC.h"
#include "SXFMapE_CIRCLEC.h"
#include "SXFMapE_ELLIPSEC.h"
#include "SXFMapE_LINEC.h"
#include "SXFMapE_POLYLINEC.h"
#include "SXFMapE_SPLINEC.h"
#include "SXFMapE_CLOTHOIDC.h"
#include "SXFMapE_TEXT_LITERAL_WITH_EXTENTC.h"
#include "SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC.h"
#include "SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC.h"
#include "SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC.h"
#include "SXFMapE_SYMBOL_TARGETC.h"
#include "SXFMapE_DEFINED_SYMBOLC.h"
#include "SXFMapE_EXTERNALLY_DEFINED_HATCHC.h"
#include "SXFMapE_EXTERNALLY_DEFINED_SYMBOLC.h"
#include "SXFMapE_FILL_AREA_STYLE_COLOURC.h"
#include "SXFMapE_FILL_AREA_STYLE_HATCHINGC.h"
#include "SXFMapE_FILL_AREA_STYLE_TILEC.h"
#include "SXFMapE_ANNOTATION_FILL_AREAC.h"
#include "SXFMapA_CURVE_STYLEC.h"
#include "SXFMapA_SYMBOL_STYLEC.h"
#include "SXFMapA_TEXT_STYLEC.h"
#include "SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC.h"
#include "SXFMapE_CURVE_STYLEC.h"
#include "SXFMapE_SYMBOL_STYLEC.h"
#include "SXFMapE_SYMBOL_COLOURC.h"
#include "SXFMapE_TEXT_STYLEC.h"
#include "SXFMapE_FILL_AREA_STYLEC.h"
#include "SXFF_FeatureTypeE.h"
#include "SXFMapF_ARCC.h"
#include "SXFMapF_CIRCLEC.h"
#include "SXFMapF_ELLIPSEARCC.h"
#include "SXFMapF_ELLIPSEC.h"
#include "SXFMapF_EXSYMBOLC.h"
#include "SXFMapF_LINEC.h"
#include "SXFMapF_POLYLINEC.h"
#include "SXFMapF_SPLINEC.h"
#include "SXFMapF_CLOTHOIDC.h"
#include "SXFMapF_CURVEDIMC.h" 
#include "SXFMapF_ANGULARDIMC.h" 
#include "SXFMapF_ARCC.h" 
#include "SXFMapF_BALLOONC.h" 
#include "SXFMapF_CIRCLEC.h" 
#include "SXFMapF_DIMETERDIMC.h" 
#include "SXFMapF_ELLIPSEARCC.h" 
#include "SXFMapF_ELLIPSEC.h" 
#include "SXFMapF_EXHATCHC.h" 
#include "SXFMapF_EXSYMBOLC.h" 
#include "SXFMapF_FILLCOLOURC.h" 
#include "SXFMapF_FILLHATCHINGC.h" 
#include "SXFMapF_FILLTILESC.h" 
#include "SXFMapF_LABELC.h" 
#include "SXFMapF_LINEC.h" 
#include "SXFMapF_LINERDIMC.h" 
#include "SXFMapF_POINTMARKERC.h" 
#include "SXFMapF_RADIUSDIMC.h" 
#include "SXFMapF_SFIGLOCC.h" 
#include "SXFMapF_SPLINEC.h" 
#include "SXFMapF_CLOTHOIDC.h" 
#include "SXFMapF_TERMSYMBOLC.h" 
#include "SXFMapF_TEXTSTRINGC.h" 
#include "SXFMapT_trimming_preferenceE.h"
#include "SXFMapAnnoBodyC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapAnnoBodyC.cpp						�쐬���F2000.04.21

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		SXFMapAnnoBodyC::SXFMapAnnoBodyC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.21	
**/

SXFMapAnnoBodyC::SXFMapAnnoBodyC( )
{
//
//	<������>
//

//< ANNOTATION_OCCURRENCE�n >/////////////////////////////////////
	m_AnnoKind = 0;
//	NONSTYLE,		//		0:�s��
//	CURVESTYLE,
//	SYMBOLSTYLE,
//	FILLSTYLE,
//	TEXTSTYLE,
//	NULLSTYLE

//< ANNOTATION_CURVE_OCCURRENCE�̎�� >////////////////////////////
	m_CurveKind =0;
//	NONCURVE,			//0:�s��
//	CURVE,				//1:��ʗv�f
//	DIMENSION_CURVE,	//2:���@���i���`�j
//	PROJECTION_CURVE	//3:���@�⏕��

//< ANNOTATION_SYMBOL_OCCURRENCE�̎�� >////////////////////////////
	m_SymbolKind =0;
//	NONSYMBOL,						//0:�s��
//	SYMBOL,							//1:�_�}�[�J�A����`�i�O����`�j�A���̑��V���{��
//	DIM_CURVE_TERMINATOR,			//2:���@�[�_���
//	LEADER_TERMINATOR,				//3:�����o�����A�o���[���[�_���
//	SUBFIGURE_OCCURRENCE			//4:�����}�`�z�u�iSUbfigure�j

	m_InstID = m_AppeID = 0;
	m_InstP  = m_AppeP = m_tilebody =NULL;

//	<SXFTableManagerC�ւ̃|�C���^>
	m_TableManager=NULL;
//	<SXFReadAP202ManagerC�ւ̃|�C���^>
	m_ReadManager=NULL;

//	<���C���R�[�h>
	m_layer = -1;
//	<�t�B�[�`���^�C�v>
	m_Type   = NONFEATURE;
//	<�t�B�[�`���N���X�ւ̃|�C���^>
	m_Class  = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapAnnoBodyC.cpp						�쐬���F2000.04.21

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapAnnoBodyC::SXFMapAnnoBodyC(
					SXFInstanceIDC* IN_InstanceIDManeger,
					SXFTableManagerC* IN_TableManager,
					SXFReadAP202ManagerC* IN_ReadManager)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)


	����  �F	�^						������					���e
				SXFInstanceIDC* 		IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��
				SXFTableManagerC* 		IN_TableManager			ð��يǗ���޼ު��
				SXFReadAP202ManagerC*	IN_ReadManager			Read�Ǘ���޼ު��	

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.21	
**/

//	<�C���X�^���X�h�c�ւ̃|�C���^��o�^����������>

SXFMapAnnoBodyC::SXFMapAnnoBodyC(
		SXFInstanceIDC* IN_InstanceIDManeger,
		SXFTableManagerC* IN_TableManager,
		SXFReadAP202ManagerC* IN_ReadManager)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
//< ANNOTATION_OCCURRENCE�n >/////////////////////////////////////
	m_AnnoKind = 0;
//	NONSTYLE,		//		0:�s��
//	CURVESTYLE,
//	SYMBOLSTYLE,
//	FILLSTYLE,
//	TEXTSTYLE,
//	NULLSTYLE

//< ANNOTATION_CURVE_OCCURRENCE�̎�� >////////////////////////////
	m_CurveKind =0;
//	NONCURVE,			//0:�s��
//	CURVE,				//1:��ʗv�f
//	DIMENSION_CURVE,	//2:���@���i���`�j
//	PROJECTION_CURVE	//3:���@�⏕��

//< ANNOTATION_SYMBOL_OCCURRENCE�̎�� >////////////////////////////
	m_SymbolKind =0;
//	NONSYMBOL,							//0:�s��
//	SYMBOL,								//1:�_�}�[�J�A����`�i�O����`�j�A���̑��V���{��
//	DIM_CURVE_TERMINATOR,				//2:���@�[�_���
//	LEADER_TERMINATOR,					//3:�����o�����A�o���[���[�_���
//	SUBFIGURE_OCCURRENCE				//4:�����}�`�z�u�iSUbfigure�j

	m_InstID = m_AppeID = 0;
	m_InstP  = m_AppeP = m_tilebody = NULL;

//	<SXFTableManagerC�ւ̃|�C���^>
	m_TableManager=IN_TableManager;
//	<SXFReadAP202ManagerC>
	m_ReadManager= IN_ReadManager;

//	<���C���R�[�h>
	m_layer = -1;
//	<�t�B�[�`���^�C�v>
	m_Type   = NONFEATURE;
//	<�t�B�[�`���N���X�ւ̃|�C���^>
	m_Class  = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapAnnoBodyC.cpp						�쐬���F2000.04.21

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapAnnoBodyC::~SXFMapAnnoBodyC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.21	
**/
SXFMapAnnoBodyC::~SXFMapAnnoBodyC()
{
	if (m_Class!=NULL){
		if ( m_Type == point_marker_feature )
		 delete (SXFMapF_POINTMARKERC*)m_Class;
		if ( m_Type == line_feature )
		 delete (SXFMapF_LINEC*)m_Class;
		if ( m_Type == polyline_feature )
		 delete (SXFMapF_POLYLINEC*)m_Class;
		if ( m_Type == circle_feature )
		 delete (SXFMapF_CIRCLEC*)m_Class;
		if ( m_Type == arc_feature )
		 delete (SXFMapF_ARCC*)m_Class;
		if ( m_Type == ellipse_feature )
		 delete (SXFMapF_ELLIPSEC*)m_Class;
		if ( m_Type == ellipse_arc_feature )
		 delete (SXFMapF_ELLIPSEARCC*)m_Class;
		if ( m_Type == text_string_feature )
		 delete (SXFMapF_TEXTSTRINGC*)m_Class;
		if ( m_Type == spline_feature )
		 delete (SXFMapF_SPLINEC*)m_Class;
		if ( m_Type == clothoid_feature )
		 delete (SXFMapF_CLOTHOIDC*)m_Class;
		if ( m_Type == sfig_locate_feature )
		 delete (SXFMapF_SFIGLOCC*)m_Class;
		if ( m_Type == externally_defined_symbol_feature )
		 delete (SXFMapF_EXSYMBOLC*)m_Class;
		if ( m_Type == dimension_terminator_symbol )
		 delete (SXFMapF_TERMSYMBOLC*)m_Class;		
		if ( m_Type == externally_defined_hatch_feature )
		 delete (SXFMapF_EXHATCHC*)m_Class;
		if ( m_Type == fill_area_style_colour_feature )
		 delete (SXFMapF_FILLCOLOURC*)m_Class;
		if ( m_Type == fill_area_style_hatching_feature )
		 delete (SXFMapF_FILLHATCHINGC*)m_Class;
		if ( m_Type == fill_area_style_tiles_feature )
		 delete (SXFMapF_FILLTILESC*)m_Class;
	}

	if (m_tilebody!=NULL) delete m_tilebody;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapAnnoBodyC.cpp						�쐬���F2000.04.21

	�P�D�@�\�T�v
		�p�����[�^�̐ݒ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapAnnoBodyC::SetParameter()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F��`�e�[�u�����

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.21	
**/
/*
SXFMapAnnoBodyC::	SetParameter(
					E_type	OUT_Type,	//�t�B�[�`�����	
					LPVOID	OUT_Class)	//�t�B�[�`���N���X�ւ̃|�C���^*/

int SXFMapAnnoBodyC::SetParameter()

{
//
//	<������>
//
	int ircode;
	//�e�ʂ̎�ʔ���
	ircode = CheckBodyKind();
	if (ircode <0 ) return ircode;

	////////////////////////////////////////////////////////////////////////////////
	//STYLED_ITEM���猩�����ƃC���X�^���X�ւ̂h�c��Name �����o��
	////////////////////////////////////////////////////////////////////////////////
			// COMPLEX�G���e�B�e�B�̃f�[�^�����o��
			SXFMapEntCConvC convert(m_EntityArray);

			//	STYLED_ITEM �̃p�����^�����o��
			convert.SplitComplex(DEF_STYLED_ITEM);
			CArray<int, int> intarray;
			int OUT_Num;
			convert.GetSetInst(0,OUT_Num,intarray);
			m_AppeID = intarray[0];
			convert.GetInst(1,m_InstID);

			//	REPRESENTATION_ITEM �̃p�����^�����o��
			convert.SplitComplex(DEF_REPRESENTATION_ITEM);
			convert.GetCString(0, m_namepara);

	////////////////////////////////////////////////////////////////////////////////
	//  ������RootID���烌�C���R�[�h���擾����                        //////////////
	////////////////////////////////////////////////////////////////////////////////
		int  OUT_Type = 0; 
		m_layer = m_TableManager->GetTableCode(m_RootID,OUT_Type);
		if ( OUT_Type != 1 ) {
			//err
			m_layer = -1;
		}

	////////////////////////////////////////////////////////////////////////////////
	//  �������ւ̂h�c�̎Q�Ɛ�G���e�B�e�B���擾���AStyles���쐬����B//////////////
	////////////////////////////////////////////////////////////////////////////////

	SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC m_AppeP(m_InstanceIDManager);
	m_AppeP.SetRootID(m_AppeID);
	if ( m_AppeP.SetParameter() < 0 ) {
		// SCADEC�̑Ώۂł͂Ȃ�ENTITY�ł�
		SXFErrorMsgC::RecordError(
			SXFEXCEPT,			//err���b�Z�[�W�ԍ�
			m_EntityName,		//�G���e�B�e�B��
			2,					//�p�����^�̌�
			m_RootID,			//�p�����^
			m_EntityName
			);
		return SXFEXCEPT;
	}

	//styles�̃`�F�b�N
	if ( m_AppeP.m_stylesKind != m_AnnoKind ) {
		//err ANNOTATION_OCCURRENCE �� STYLES�̎�ނ��قȂ�܂��B
	}

	////////////////////////////////////////////////////////////////////////////////
	//  �������ւ̃C���X�^���X���猩�����̏����擾����B      ////////////////////
	//  �C���X�^���X�h�c�̎Q�Ɛ�G���e�B�e�B���擾���A���ʂ���B////////////////////
	////////////////////////////////////////////////////////////////////////////////

	CString InstEntityName;
	InstEntityName = SXFMapInstIDC::GetEntityName(m_InstID);

	// ANNOTATION_CURVE_OCCURRENCE �n�̏��� ///////////////////////////////////////////
	if ( m_AnnoKind == CURVESTYLE ) {

		//  �������̏��擾   ////////////////////////////////////////////////
		SXFMapA_CURVE_STYLEC curvestyle;
		curvestyle.m_colorID =((SXFMapE_CURVE_STYLEC*)(m_AppeP.m_styles_P))->m_colour_Inst;
		curvestyle.m_fontID  =((SXFMapE_CURVE_STYLEC*)(m_AppeP.m_styles_P))->m_font_Inst;
		curvestyle.m_widthID =((SXFMapE_CURVE_STYLEC*)(m_AppeP.m_styles_P))->m_width_Inst;

/*		////////////////////////////////////////////////////////////////////////
			�� SXFTableManagerC::GetTableCode(int IN_ID , int OUT_Type)
			    case 1://layer
			    case 2://predefcolor
			    case 3://userdefcolor
			    case 4://predeffont
			    case 5://userdeffont
			    case 6://width
			    case 7://textfont
		////////////////////////////////////////////////////////////////////////*/
//		OUT_Type = 2or3; 
		curvestyle.m_color = m_TableManager->GetTableCode(curvestyle.m_colorID, OUT_Type);
		if (OUT_Type != 2 && OUT_Type != 3)
			curvestyle.m_color = -1;
//		OUT_Type = 4or5; 
		curvestyle.m_font  = m_TableManager->GetTableCode(curvestyle.m_fontID, OUT_Type);
		if (OUT_Type != 4 && OUT_Type != 5)
			curvestyle.m_font = -1;
//		OUT_Type = 6; 
		curvestyle.m_width = m_TableManager->GetTableCode(curvestyle.m_widthID, OUT_Type);
		if (OUT_Type != 6)
			curvestyle.m_width = -1;

		//  �C���X�^���X���̎擾   //////////////////////////////////////////////

		//TRIMMED_CURVE
		if (InstEntityName == DEF_TRIMMED_CURVE){

			SXFMapE_TRIMMED_CURVEC m_InstP(m_InstanceIDManager);
			m_InstP.SetRootID(m_InstID);
			m_InstP.SetParameter();

			//LINE
			if ( m_InstP.m_basis_curve_Name == DEF_LINE ){

				SXFMapF_LINEC* line;
				line = new SXFMapF_LINEC;

				if ( m_InstP.m_e_rep == cartesian ) {
					line->m_layer	= m_layer;
					line->m_color	= curvestyle.m_color;
					line->m_type  	= curvestyle.m_font;
					line->m_line_width	= curvestyle.m_width;

					line->m_start_x	= m_InstP.m_trim_1_P->m_x;
					line->m_start_y	= m_InstP.m_trim_1_P->m_y;
					line->m_end_x	= m_InstP.m_trim_2_P->m_x;
					line->m_end_y	= m_InstP.m_trim_2_P->m_y;

					// PROJECTION LINE�p�̃f�[�^
					line->Set12flg(m_namepara);
					line->m_org_x	= 	
						((SXFMapE_LINEC*)m_InstP.m_basis_curve_P)->m_pnt_P->m_x; 
					line->m_org_y	= 	
						((SXFMapE_LINEC*)m_InstP.m_basis_curve_P)->m_pnt_P->m_y; 

					m_Type  = line_feature;
					m_Class = line;
				}
				else if ( m_InstP.m_e_rep == parameter ) {

				}

			}
			//ARC
			else if ( m_InstP.m_basis_curve_Name == DEF_CIRCLE ){
				if ( m_InstP.m_e_rep == cartesian ) {
	
				}
				else if ( m_InstP.m_e_rep == parameter ) {

					SXFMapF_ARCC* arc;
					arc = new SXFMapF_ARCC;
					
					arc->m_layer	= m_layer;
					arc->m_color	= curvestyle.m_color;
					arc->m_type  	= curvestyle.m_font;
					arc->m_line_width	= curvestyle.m_width;

					//�~�ʂ̒��S
					arc->m_center_x = ((SXFMapE_CIRCLEC*)m_InstP.m_basis_curve_P)->m_axis2_P->m_pnt_P->m_x;	
					arc->m_center_y = ((SXFMapE_CIRCLEC*)m_InstP.m_basis_curve_P)->m_axis2_P->m_pnt_P->m_y;	
					//�~�ʂ̔��a
					arc->m_radius = ((SXFMapE_CIRCLEC*)m_InstP.m_basis_curve_P)->m_radius;
					//�����t���O�i�O�F�����v���A�P�F���v���j
					if ( m_InstP.m_sense == FALSE     ){
						arc->m_direction = 1;
					}
					else{
						arc->m_direction = 0;
					}
					//�~�ʂ̎n�p�A�I�p
					arc->m_start_angle = m_InstP.m_trim1_para * 180. /acos(-1.) ;
					arc->m_end_angle   = m_InstP.m_trim2_para * 180. /acos(-1.) ;
					m_Type  = arc_feature;
					m_Class = arc;
				}
			}
			//ELLIPSE ARC
			else if ( m_InstP.m_basis_curve_Name == DEF_ELLIPSE ){
				if ( m_InstP.m_e_rep == cartesian ) {

				}
				else if ( m_InstP.m_e_rep == parameter ) {

					SXFMapF_ELLIPSEARCC* ellipsarc;
					ellipsarc = new SXFMapF_ELLIPSEARCC;

					ellipsarc->m_layer	= m_layer;
					ellipsarc->m_color	= curvestyle.m_color;
					ellipsarc->m_type  	= curvestyle.m_font;
					ellipsarc->m_line_width	= curvestyle.m_width;

					//�ȉ~�ʂ̒��S
					ellipsarc->m_center_x = ((SXFMapE_ELLIPSEC*)m_InstP.m_basis_curve_P)->m_axis2_P->m_pnt_P->m_x;	
					ellipsarc->m_center_y = ((SXFMapE_ELLIPSEC*)m_InstP.m_basis_curve_P)->m_axis2_P->m_pnt_P->m_y;	
					//�ȉ~�ʂ̂��������a�A���������a
					ellipsarc->m_radius_x = ((SXFMapE_ELLIPSEC*)m_InstP.m_basis_curve_P)->m_semi_axis_1;
					ellipsarc->m_radius_y = ((SXFMapE_ELLIPSEC*)m_InstP.m_basis_curve_P)->m_semi_axis_2;
					//�����t���O�i�O�F�����v���A�P�F���v���j
					if ( m_InstP.m_sense == FALSE     ){
						ellipsarc->m_direction = 1;
					}
					else{
						ellipsarc->m_direction = 0;
					}
					//�ȉ~�ʂ̉�]�p
					ellipsarc->m_rotation_angle  =	SXFutyFunctionC::calc_angle(
						((SXFMapE_ELLIPSEC*)m_InstP.m_basis_curve_P)->m_axis2_P->m_DIRECTION_P->m_y ,
						((SXFMapE_ELLIPSEC*)m_InstP.m_basis_curve_P)->m_axis2_P->m_DIRECTION_P->m_x   );
				
					//�ȉ~�ʂ̎n�p�A�I�p
					ellipsarc->m_start_angle = m_InstP.m_trim1_para * 180. /acos(-1.) ;
					ellipsarc->m_end_angle   = m_InstP.m_trim2_para * 180. /acos(-1.) ;
					m_Type  = ellipse_arc_feature;
					m_Class = ellipsarc;
				}
			}
			//CLOTHOID
			else if (m_InstP.m_basis_curve_Name == DEF_CLOTHOID){
				SXFMapF_CLOTHOIDC* clothoid;
				clothoid = new SXFMapF_CLOTHOIDC;

				clothoid->m_layer	= m_layer;
				clothoid->m_color	= curvestyle.m_color;
				clothoid->m_type  	= curvestyle.m_font;
				clothoid->m_line_width	= curvestyle.m_width;
				clothoid->base_x = ((SXFMapE_CLOTHOIDC*)m_InstP.m_basis_curve_P)->m_axis2_P->m_pnt_P->m_x;
				clothoid->base_y = ((SXFMapE_CLOTHOIDC*)m_InstP.m_basis_curve_P)->m_axis2_P->m_pnt_P->m_y;
				clothoid->parameter = ((SXFMapE_CLOTHOIDC*)m_InstP.m_basis_curve_P)->m_parameter;
				//�����t���O�i�O�F�����v���A�P�F���v���j
				if (((SXFMapE_CLOTHOIDC*)m_InstP.m_basis_curve_P)->m_direction == _T("1")) {
					clothoid->direction = 1;
				} else {
					clothoid->direction = 0;
				}
				clothoid->angle = SXFutyFunctionC::calc_angle(
						((SXFMapE_CLOTHOIDC*)m_InstP.m_basis_curve_P)->m_axis2_P->m_DIRECTION_P->m_y,
						((SXFMapE_CLOTHOIDC*)m_InstP.m_basis_curve_P)->m_axis2_P->m_DIRECTION_P->m_x);
				clothoid->start_length = m_InstP.m_trim1_para;
				clothoid->end_length = m_InstP.m_trim2_para;
				int	split = m_InstP.m_name.Find(',');
				if (split != -1)
				{
					clothoid->start_length = atof(m_InstP.m_name.Left(split));
					clothoid->end_length = atof(m_InstP.m_name.Mid(split + 1));
				}

				m_Type  = clothoid_feature;
				m_Class = clothoid;
			}

			else {
				//err
			}
		}
		//POLYLINE
		else if (InstEntityName == DEF_POLYLINE){
			SXFMapE_POLYLINEC m_InstP(m_InstanceIDManager);
			m_InstP.SetRootID(m_InstID);
			m_InstP.SetParameter();

			SXFMapF_POLYLINEC* polyline;
			polyline = new SXFMapF_POLYLINEC;

			polyline->m_layer	= m_layer;
			polyline->m_color	= curvestyle.m_color;
			polyline->m_type  	= curvestyle.m_font;
			polyline->m_line_width	= curvestyle.m_width;
			polyline->m_number =m_InstP.m_PointCount;
			for ( int c_pnt=0;c_pnt<m_InstP.m_PointCount;c_pnt++){
				polyline->m_x.Add( m_InstP.m_PointArray_p[c_pnt]->m_x );
				polyline->m_y.Add( m_InstP.m_PointArray_p[c_pnt]->m_y );
			}
			m_Type  = polyline_feature;
			m_Class = polyline;
		}
		//CIRCLE
		else if (InstEntityName == DEF_CIRCLE){
			SXFMapE_CIRCLEC m_InstP(m_InstanceIDManager);
			m_InstP.SetRootID(m_InstID);
			m_InstP.SetParameter();
			
			SXFMapF_CIRCLEC* circle;
			circle = new SXFMapF_CIRCLEC;
			circle->m_layer	= m_layer;
			circle->m_color	= curvestyle.m_color;
			circle->m_type  	= curvestyle.m_font;
			circle->m_line_width	= curvestyle.m_width;
			//�~�̒��S
			circle->m_center_x = m_InstP.m_axis2_P->m_pnt_P->m_x;
			circle->m_center_y = m_InstP.m_axis2_P->m_pnt_P->m_y;
			//�~�̔��a
			circle->m_radius = m_InstP.m_radius;

			m_Type  = circle_feature;
			m_Class = circle;	

		}
		//ELLIPSE
		else if (InstEntityName == DEF_ELLIPSE ){
			SXFMapE_ELLIPSEC m_InstP(m_InstanceIDManager);
			m_InstP.SetRootID(m_InstID);
			m_InstP.SetParameter();

			SXFMapF_ELLIPSEC* ellips;
			ellips = new SXFMapF_ELLIPSEC;
			ellips->m_layer	= m_layer;
			ellips->m_color	= curvestyle.m_color;
			ellips->m_type  	= curvestyle.m_font;
			ellips->m_line_width	= curvestyle.m_width;
			//�ȉ~�ʂ̒��S
			ellips->m_center_x = m_InstP.m_axis2_P->m_pnt_P->m_x;
			ellips->m_center_y = m_InstP.m_axis2_P->m_pnt_P->m_y;
			//�ȉ~�ʂ̂��������a�A���������a
			ellips->m_radius_x = m_InstP.m_semi_axis_1;
			ellips->m_radius_y = m_InstP.m_semi_axis_2;
			//�ȉ~�ʂ̉�]�p
			ellips->m_rotation_angle  =	SXFutyFunctionC::calc_angle(
			m_InstP.m_axis2_P->m_DIRECTION_P->m_y ,
			m_InstP.m_axis2_P->m_DIRECTION_P->m_x   );

			m_Type  = ellipse_feature;
			m_Class = ellips;

		}
		//BEZIER_CURVE
		else if (InstEntityName == DEF_BEZIER_CURVE){
			SXFMapE_SPLINEC m_InstP(m_InstanceIDManager);
			m_InstP.SetRootID(m_InstID);
			m_InstP.SetParameter();

			SXFMapF_SPLINEC* spline;
			spline = new SXFMapF_SPLINEC;

			spline->m_layer	= m_layer;
			spline->m_color	= curvestyle.m_color;
			spline->m_type			= curvestyle.m_font;
			spline->m_line_width	= curvestyle.m_width;

			spline->m_open_close = !(m_InstP.m_ClosedCurveFlg);
			spline->m_number =m_InstP.m_PointCount;
			for ( int c_pnt=0;c_pnt<m_InstP.m_PointCount;c_pnt++){
				spline->m_x.Add( m_InstP.m_PointArray_P[c_pnt]->m_x );
				spline->m_y.Add( m_InstP.m_PointArray_P[c_pnt]->m_y );
			}
			m_Type  = spline_feature;
			m_Class = spline;

		}
		else if (InstEntityName == DEF_AXIS2_PLACEMENT_2D ||
			InstEntityName == DEF_PLANAR_BOX){
		}

	}
	// ANNOTATION_SYMBOL_OCCURRENCE �n�̏��� ///////////////////////////////////////////
	else if ( m_AnnoKind == SYMBOLSTYLE ) {//2:

	//#261 = PRE_DEFINED_TERMINATOR_SYMBOL('dimension origin');
	//#1346 = EXTERNALLY_DEFINED_SYMBOL(IDENTIFIER('asterisk'), #1345);

		if ( InstEntityName == DEF_DEFINED_SYMBOL){

		//  �������̏��擾   ////////////////////////////////////////////////
		SXFMapA_SYMBOL_STYLEC	symbolstyle;
		symbolstyle.m_colorID 
			=((SXFMapE_SYMBOL_STYLEC*)(m_AppeP.m_styles_P))->m_symbol_colour_P->m_colour_Inst;
		//OUT_Type = 2or3; 
		symbolstyle.m_color = m_TableManager->GetTableCode(symbolstyle.m_colorID, OUT_Type);
		if (OUT_Type != 2 && OUT_Type != 3)
			symbolstyle.m_color = -1;

		//  �C���X�^���X���̎擾   //////////////////////////////////////////////

		//DEFINED_SYMBOL
		// 1:PRE_DEFINED_POINT_MARKER
		// 2:PRE_DEFINED_TERMINATOR_SYMBOL
		// 3:EXTERNALLY_DEFINED_SYMBOL

			SXFMapE_DEFINED_SYMBOLC m_InstP(m_InstanceIDManager);
			m_InstP.SetRootID(m_InstID);
			m_InstP.SetParameter();

			//PRE_DEFINED_POINT_MARKER
			if ( m_InstP.m_DefsymKind == 1 ){
				SXFMapF_POINTMARKERC* point;
				point = new SXFMapF_POINTMARKERC;

				point->m_layer	 = m_layer;
				point->m_color	 = symbolstyle.m_color;
				point->m_start_x = m_InstP.m_Target_p->m_Placement_p->m_pnt_P->m_x;
				point->m_start_y = m_InstP.m_Target_p->m_Placement_p->m_pnt_P->m_y;
				point->m_marker_code = 
					((SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC*)(m_InstP.m_Definition_p))->m_code;
				point->m_rotate_angle = SXFutyFunctionC::calc_angle(
					m_InstP.m_Target_p->m_Placement_p->m_DIRECTION_P->m_y,
					m_InstP.m_Target_p->m_Placement_p->m_DIRECTION_P->m_x);
				point->m_scale = m_InstP.m_Target_p->m_Scale_x;
				m_Type  = point_marker_feature;
				m_Class = point;
			}
			// 2:PRE_DEFINED_TERMINATOR_SYMBOL
			else if ( m_InstP.m_DefsymKind == 2 ){

				SXFMapF_TERMSYMBOLC* term;
				term = new SXFMapF_TERMSYMBOLC;

				term->m_layer	= m_layer;
				term->m_color	= symbolstyle.m_color;
				term->m_start_x	= m_InstP.m_Target_p->m_Placement_p->m_pnt_P->m_x;
				term->m_start_y = m_InstP.m_Target_p->m_Placement_p->m_pnt_P->m_y;
				term->m_arr_code = 
					((SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC*)(m_InstP.m_Definition_p))->m_code;
				term->m_scale = m_InstP.m_Target_p->m_Scale_x;
				term->Set12flg(m_namepara);

				//���̃x�N�g��
				term->m_vecter_x =
					m_InstP.m_Target_p->m_Placement_p->m_DIRECTION_P->m_x;
				term->m_vecter_y =
					m_InstP.m_Target_p->m_Placement_p->m_DIRECTION_P->m_y;
				m_Type  = dimension_terminator_symbol;
				m_Class = term;
			}
			// 3:EXTERNALLY_DEFINED_SYMBOL
			else if ( m_InstP.m_DefsymKind == 3 ){

				SXFMapF_EXSYMBOLC* extsymbol;
				extsymbol = new SXFMapF_EXSYMBOLC;

				extsymbol->m_layer	= m_layer;
				 extsymbol->m_color_flag = 0;
				if ( m_AppeP.m_stylesKind == SYMBOLSTYLE ) extsymbol->m_color_flag = 1;
					extsymbol->m_color	= symbolstyle.m_color;
					extsymbol->m_name   = 
						((SXFMapE_EXTERNALLY_DEFINED_SYMBOLC*)(m_InstP.m_Definition_p))->m_Name;
					extsymbol->m_start_x = m_InstP.m_Target_p->m_Placement_p->m_pnt_P->m_x;
					extsymbol->m_start_y = m_InstP.m_Target_p->m_Placement_p->m_pnt_P->m_y;
					extsymbol->m_rotate_angle = SXFutyFunctionC::calc_angle(
					m_InstP.m_Target_p->m_Placement_p->m_DIRECTION_P->m_y,
					m_InstP.m_Target_p->m_Placement_p->m_DIRECTION_P->m_x);
					extsymbol->m_scale = m_InstP.m_Target_p->m_Scale_x; 
					extsymbol->m_scale_y = m_InstP.m_Target_p->m_Scale_y; 

					m_Type  = externally_defined_symbol_feature;
					m_Class = extsymbol;
				}

		}

		//COMPLEX		sfig_locate_feature,
		else if ( InstEntityName == DEF_SXF_COMPLEX_INSTANCE){
			int TargetID, SourceID;
			CStringArray* IN_ComplexArray;
			CStringArray OUT_ComplexArray;
			GetMyArray(m_InstID,OUT_ComplexArray);
			IN_ComplexArray = &OUT_ComplexArray;

			//�v�f�̃`�F�b�N
			if (m_EntityData.Find(DEF_REPRESENTATION_ITEM) == -1){
				//err
			}
			if (m_EntityData.Find(DEF_GEOMETRIC_REPRESENTATION_ITEM) == -1){
				//err
			}
			if (m_EntityData.Find(DEF_MAPPED_ITEM) == -1){
				//err
			}
			if (m_EntityData.Find(DEF_ANNOTATION_SYMBOL) == -1){
				//err
			}
			/*
			#965 = (
			  ANNOTATION_SYMBOL()
			  GEOMETRIC_REPRESENTATION_ITEM()
			  MAPPED_ITEM(#400, #964)
			  REPRESENTATION_ITEM('annotation_symbol1')
			*/
			/*	
			 ENTITY mapped_item
				SUBTYPE OF (representation_item);
				  mapping_source : representation_map;
				  mapping_target : representation_item;
				WHERE
				  wr1: acyclic_mapped_representation(using_representations(SELF),[SELF]);
			 END_ENTITY; -- mapped_item
		*/

			// COMPLEX�G���e�B�e�B�̃f�[�^�����o��
			SXFMapEntCConvC convert(IN_ComplexArray);

			//	MAPPED_ITEM �̃p�����^�����o��
			convert.SplitComplex(DEF_MAPPED_ITEM);
			convert.GetInst(0,SourceID);
			convert.GetInst(1,TargetID);

			SXFMapE_SYMBOL_TARGETC TargetP(m_InstanceIDManager);
			TargetP.SetRootID(TargetID);
			TargetP.SetParameter();

			SXFMapF_SFIGLOCC* sfigloc;
			sfigloc = new SXFMapF_SFIGLOCC();

			int OUT_Flag;
			sfigloc->m_layer =  m_layer;
			CString tmp_name;
		    m_ReadManager->GetSymbolInfo( SourceID, OUT_Flag, tmp_name );
			sfigloc->m_name  =  tmp_name;
			sfigloc->m_start_x = TargetP.m_Placement_p->m_pnt_P->m_x;
			sfigloc->m_start_y = TargetP.m_Placement_p->m_pnt_P->m_y;
			sfigloc->m_angle   = SXFutyFunctionC::calc_angle(
				TargetP.m_Placement_p->m_DIRECTION_P->m_y ,
				TargetP.m_Placement_p->m_DIRECTION_P->m_x );
			sfigloc->m_ratio_x = TargetP.m_Scale_x;
			sfigloc->m_ratio_y = TargetP.m_Scale_y;
						
			m_Type  = sfig_locate_feature;
			m_Class = sfigloc;

		}
	}
	// ANNOTATION_FILL_AREA_OCCURRENCE �n�̏��� ///////////////////////////////////////////
	else if ( m_AnnoKind == FILLSTYLE ) {//3:

		//  �C���X�^���X���̎擾   //////////////////////////////////////////////
		//#1201 = ANNOTATION_FILL_AREA('annotation_fill_area2', (#1121, #1181));

		SXFMapE_ANNOTATION_FILL_AREAC m_InstP(m_InstanceIDManager);
		m_InstP.SetRootID(m_InstID);
		m_InstP.SetParameter();

		//  �r�s�x�k�d�r�ւ̃|�C���^�擾   //////////////////////////////////////////////
		SXFMapE_FILL_AREA_STYLEC* FillStyleP;
		FillStyleP = ((SXFMapE_FILL_AREA_STYLEC*)(m_AppeP.m_styles_P));
		
		////////////////////////////////////////////////////////////////
		// �� �O�`�A���a�̂�ID�擾     
		////////////////////////////////////////////////////////////////
		int tmp_out_id,tmp_number;
		CArray<int,int> tmparray_in_id;

		tmp_out_id = m_ReadManager->GetAssemblyCode(m_InstP.m_Boundary_Inst[0]);
		tmp_number = m_InstP.m_BoundaryCont-1;
		for (int in_id=1; in_id<m_InstP.m_BoundaryCont;in_id++){
			tmparray_in_id.Add(m_ReadManager->GetAssemblyCode(m_InstP.m_Boundary_Inst[in_id]) );
		}

		////////////////////////////////////////////////////////////////
		// �� AREAFILL�̏��擾    
		////////////////////////////////////////////////////////////////

		int ii = 0; // ���x���Q�܂ł́A�قȂ�����ނ�FILL�̂����˂��킹�͂���
		//	<�n�b�`���O�O����`>		////////////////////////////////////////////////
		if ( FillStyleP->m_FillStyle_Name[ii] == DEF_EXTERNALLY_DEFINED_HATCH_STYLE){

			SXFMapE_EXTERNALLY_DEFINED_HATCHC* e_exthatch;
			e_exthatch = 
				(SXFMapE_EXTERNALLY_DEFINED_HATCHC*)(FillStyleP->m_FillStyleArray_p[ii]);

			SXFMapF_EXHATCHC* exthatch;
			exthatch = new SXFMapF_EXHATCHC;

			exthatch->m_layer	 = m_layer;
			exthatch->m_name     = e_exthatch->m_Name;

			////////////////////////////////////////////////////////////////
			// �� �O�`�A���a��ID     
			////////////////////////////////////////////////////////////////
			exthatch->m_out_id = tmp_out_id;
			exthatch->m_number = tmp_number;
			exthatch->m_in_id.Copy(tmparray_in_id);

			m_Type  = externally_defined_hatch_feature;
			m_Class = exthatch;		
		
		}
		//	<�n�b�`���O�h��>			////////////////////////////////////////////////
		else if (  FillStyleP->m_FillStyle_Name[ii] == DEF_FILL_AREA_STYLE_COLOUR){

			SXFMapE_FILL_AREA_STYLE_COLOURC* e_fillcolor;
			e_fillcolor =
				(SXFMapE_FILL_AREA_STYLE_COLOURC*)(FillStyleP->m_FillStyleArray_p[ii]);

			SXFMapF_FILLCOLOURC* fillcolor = new SXFMapF_FILLCOLOURC;

			fillcolor->m_layer	 = m_layer;
			fillcolor->m_color	 = m_TableManager->GetTableCode(e_fillcolor->m_FillColour_Inst, OUT_Type);
			if (OUT_Type != 2 && OUT_Type != 3)
				fillcolor->m_color = -1;

			////////////////////////////////////////////////////////////////
			// �� �O�`�A���a��ID
			////////////////////////////////////////////////////////////////
			fillcolor->m_out_id = tmp_out_id;
			fillcolor->m_number = tmp_number;
			fillcolor->m_in_id.Copy(tmparray_in_id);

			m_Type  = fill_area_style_colour_feature;
			m_Class = fillcolor;

		}
		//	<�n�b�`���O���[�U��`>		////////////////////////////////////////////////
		else if (  FillStyleP->m_FillStyle_Name[ii]  == DEF_FILL_AREA_STYLE_HATCHING){

			SXFMapE_FILL_AREA_STYLE_HATCHINGC* e_fillhatch;
			e_fillhatch = 
				(SXFMapE_FILL_AREA_STYLE_HATCHINGC*)(FillStyleP->m_FillStyleArray_p[ii]);

			SXFMapF_FILLHATCHINGC* fillhatch = new SXFMapF_FILLHATCHINGC;

			fillhatch->m_layer	 = m_layer;
			fillhatch->m_hatch_number = FillStyleP->m_FillStyle_Count;
			if ( fillhatch->m_hatch_number >4 ) fillhatch->m_hatch_number=4;

			for (int j=0; j<fillhatch->m_hatch_number;j++){
				e_fillhatch = 
				(SXFMapE_FILL_AREA_STYLE_HATCHINGC*)(FillStyleP->m_FillStyleArray_p[j]);
				fillhatch->m_hatch_color[j] = 
					m_TableManager->GetTableCode(e_fillhatch->m_HatchLineAppeatance_p->m_colour_Inst, OUT_Type);
				if (OUT_Type != 2 && OUT_Type != 3)
					fillhatch->m_hatch_color[j] = -1;
				fillhatch->m_hatch_type[j] =
					m_TableManager->GetTableCode(e_fillhatch->m_HatchLineAppeatance_p->m_font_Inst, OUT_Type);
				if (OUT_Type != 4 && OUT_Type != 5)
					fillhatch->m_hatch_type[j] = -1;
				fillhatch->m_hatch_line_width[j] =
					m_TableManager->GetTableCode(e_fillhatch->m_HatchLineAppeatance_p->m_width_Inst, OUT_Type);
				if (OUT_Type != 6)
					fillhatch->m_hatch_line_width[j] = -1;
				fillhatch->m_hatch_start_x[j] = e_fillhatch->m_PatternStart_p->m_x;
				fillhatch->m_hatch_start_y[j] = e_fillhatch->m_PatternStart_p->m_y;
				fillhatch->m_hatch_angle[j]   = (e_fillhatch->m_HatchLineAngle) * 180. /acos(-1.) ;
				double tmp_maguni, tmp_x, tmp_y, vec_ang;
				tmp_x = e_fillhatch->m_StartOfNextHatchLine_p->m_Factor_p->m_DIRECTION_P->m_x;
				tmp_y =	e_fillhatch->m_StartOfNextHatchLine_p->m_Factor_p->m_DIRECTION_P->m_y;
				tmp_maguni = e_fillhatch->m_StartOfNextHatchLine_p->m_Factor_p->m_magni;
				vec_ang = atan2(tmp_y, tmp_x);
				fillhatch->m_hatch_spacing[j] = tmp_maguni * sin(vec_ang-((fillhatch->m_hatch_angle[j])*acos(-1.)/180.) );
			}

			////////////////////////////////////////////////////////////////
			// �� �O�`�A���a��ID
			////////////////////////////////////////////////////////////////
			fillhatch->m_out_id = tmp_out_id;
			fillhatch->m_number = tmp_number;
			fillhatch->m_in_id.Copy(tmparray_in_id);

			m_Type  = fill_area_style_hatching_feature;
			m_Class = fillhatch;

		}
		//	<�n�b�`���O�p�^�[��>		////////////////////////////////////////////////
		else if (  FillStyleP->m_FillStyle_Name[ii] == DEF_FILL_AREA_STYLE_TILES){
			// E_FILL_AREA_STYLE_TILEC �ւ̃|�C���^�Z�[�u
			SXFMapE_FILL_AREA_STYLE_TILEC* e_filltile;
			e_filltile = 
				((SXFMapE_FILL_AREA_STYLE_TILEC*)(FillStyleP->m_FillStyleArray_p[ii]));

			SXFMapF_FILLTILESC* filltile = new SXFMapF_FILLTILESC;

			//	Tile��BODY�쐬
			m_tilebody = new SXFMapAnnoBodyC(m_InstanceIDManager,m_TableManager,m_ReadManager);
			ircode = m_tilebody->SetRootID( e_filltile->m_TileArray_p[0]->m_Symbol_Inst );
			if ( ircode < 0 )
				return ircode ;
			ircode = m_tilebody->SetParameter();
			if ( ircode < 0 )
				return ircode ;

			filltile->m_layer	    = m_layer;
			filltile->m_name		= ((SXFMapF_EXSYMBOLC*)m_tilebody->m_Class)->m_name;
			filltile->m_hatch_color = ((SXFMapF_EXSYMBOLC*)m_tilebody->m_Class)->m_color;
			filltile->m_hatch_pattern_x = ((SXFMapF_EXSYMBOLC*)m_tilebody->m_Class)->m_start_x;
			filltile->m_hatch_pattern_y = ((SXFMapF_EXSYMBOLC*)m_tilebody->m_Class)->m_start_y;

			filltile->m_hatch_pattern_vector1 = e_filltile->m_TilingPattern_p->m_FirstFactor_p->m_magni;
			filltile->m_hatch_pattern_vector1_angle = SXFutyFunctionC::calc_angle(
				e_filltile->m_TilingPattern_p->m_FirstFactor_p->m_DIRECTION_P->m_y ,
				e_filltile->m_TilingPattern_p->m_FirstFactor_p->m_DIRECTION_P->m_x );
			filltile->m_hatch_pattern_vector2 = e_filltile->m_TilingPattern_p->m_SecondFactor_p->m_magni;
			filltile->m_hatch_pattern_vector2_angle = SXFutyFunctionC::calc_angle(
				e_filltile->m_TilingPattern_p->m_SecondFactor_p->m_DIRECTION_P->m_y ,
				e_filltile->m_TilingPattern_p->m_SecondFactor_p->m_DIRECTION_P->m_x );

			filltile->m_hatch_pattern_scale_x = ((SXFMapF_EXSYMBOLC*)m_tilebody->m_Class)->m_scale; 
			filltile->m_hatch_pattern_scale_y = ((SXFMapF_EXSYMBOLC*)m_tilebody->m_Class)->m_scale_y;
			filltile->m_hatch_pattern_angle   = ((SXFMapF_EXSYMBOLC*)m_tilebody->m_Class)->m_rotate_angle;

			////////////////////////////////////////////////////////////////
			// �� �O�`�A���a��ID
			////////////////////////////////////////////////////////////////
			filltile->m_out_id = tmp_out_id;
			filltile->m_number = tmp_number;
			filltile->m_in_id.Copy(tmparray_in_id);

			m_Type  = fill_area_style_tiles_feature;
			m_Class = filltile;
		}
		else{
			// SCADEC�̑Ώۂł͂Ȃ�ENTITY�ł�
			SXFErrorMsgC::RecordError(
				SXFEXCEPT,			//err���b�Z�[�W�ԍ�
				InstEntityName,		//�G���e�B�e�B��
				2,					//�p�����^�̌�
				m_InstID,			//�p�����^
				InstEntityName
				);
			return SXFEXCEPT;
		}
	}
	// ANNOTATION_TEXT_OCCURRENCE �n�̏��� ///////////////////////////////////////////
	else if ( m_AnnoKind == TEXTSTYLE ) {//4:

		//  �������̏��擾   ////////////////////////////////////////////////		
		SXFMapA_TEXT_STYLEC	textstyle;
		textstyle.m_colorID 
			=(((SXFMapE_TEXT_STYLEC*)(m_AppeP.m_styles_P))->m_text_appe_P)->m_Color_Inst;
		//OUT_Type = 2or3; 
		textstyle.m_color = m_TableManager->GetTableCode(textstyle.m_colorID, OUT_Type);
		if (OUT_Type != 2 && OUT_Type != 3)
			textstyle.m_color = -1;

		//  �C���X�^���X���̎擾   //////////////////////////////////////////////	
		
		//TEXT_LITERAL_WITH_EXTENT
		if ( InstEntityName == DEF_TEXT_LITERAL_WITH_EXTENT){

			SXFMapE_TEXT_LITERAL_WITH_EXTENTC m_InstP(m_InstanceIDManager);
			m_InstP.SetRootID(m_InstID);
			ircode = m_InstP.SetParameter();
			if (ircode <0 ) return ircode;

			SXFMapF_TEXTSTRINGC* text;
			text = new SXFMapF_TEXTSTRINGC;
			
			text->m_layer	= m_layer;
			text->m_color	= textstyle.m_color;
			text->m_font	= m_TableManager->GetTableCode(m_InstP.m_Font_Inst, OUT_Type);
			if (OUT_Type != 7)
				text->m_font = -1;
			text->m_str		= m_InstP.m_Literal;

			text->m_height  = m_InstP.m_PlanarExtent_p->m_Size_y;
			text->m_width	= m_InstP.m_PlanarExtent_p->m_Size_x;
			text->m_spc		= ((SXFMapE_TEXT_STYLEC*)(m_AppeP.m_styles_P))->m_spacing;
			text->m_angle	= SXFutyFunctionC::calc_angle(m_InstP.m_Placement_p->m_DIRECTION_P->m_y,m_InstP.m_Placement_p->m_DIRECTION_P->m_x) ;
			text->m_slant	= ((SXFMapE_TEXT_STYLEC*)(m_AppeP.m_styles_P))->m_slant_angle  * 180. /acos(-1.) ;

			text->SetBasePoint(m_InstP.m_Name,m_InstP.m_Alignment);
			text->SetDirect(m_InstP.m_Path);
			double OUT_Ascent,OUT_Decent;
			m_TableManager->GetTextFontProperty(text->m_font, OUT_Ascent, OUT_Decent );
			text->SetXYPoint(m_InstP.m_Placement_p->m_pnt_P->m_x,
							m_InstP.m_Placement_p->m_pnt_P->m_y,
							OUT_Ascent, OUT_Decent );

			m_Type  = text_string_feature;
			m_Class = text;

		}
		else{
		// SCADEC�̑Ώۂł͂Ȃ�ENTITY�ł�
			SXFErrorMsgC::RecordError(
				SXFEXCEPT,			//err���b�Z�[�W�ԍ�
				InstEntityName,		//�G���e�B�e�B��
				2,					//�p�����^�̌�
				m_InstID,			//�p�����^
				InstEntityName
				);
			return SXFEXCEPT;
		}

	}

	return 0;
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapAnnoBodyC.cpp						�쐬���F2000.04.21

	�P�D�@�\�T�v
		Body�̎�ʔ���

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapAnnoBodyC::CheckBodyKind()
					

	����  �F	�^			������				���e
		�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.21	
**/

int	SXFMapAnnoBodyC::CheckBodyKind()
{

//< ANNOTATION_OCCURRENCE�n >/////////////////////////////////////
	m_AnnoKind = 0;
//	NONSTYLE,		//0:�s��
//	CURVESTYLE,		//1:
//	SYMBOLSTYLE,	//2:
//	FILLSTYLE,		//3:
//	TEXTSTYLE,		//4:
//	NULLSTYLE		//5:

//< ANNOTATION_CURVE_OCCURRENCE�̎�� >////////////////////////////
	m_CurveKind =0;
//	NONCURVE,			//0:�s��
//	CURVE,				//1:��ʗv�f
//	DIMENSION_CURVE,	//2:���@���i���`�j
//	PROJECTION_CURVE	//3:���@�⏕��
//	LEADER_CURVE		//3:���o�����i���`�j

//< ANNOTATION_SYMBOL_OCCURRENCE�̎�� >////////////////////////////
	m_SymbolKind =0;
//	NONSYMBOL,							//0:�s��
//	SYMBOL,								//1:�_�}�[�J�A����`�i�O����`�j�A���̑��V���{��
//	DIM_CURVE_TERMINATOR,				//2:���@�[�_���
//	LEADER_TERMINATOR,					//3:�����o�����A�o���[���[�_���
//	SUBFIGURE_OCCURRENCE		//4:�����}�`�z�u�iSUbfigure�j

	//< ANNOTATION_OCCURRENCE�n >/////////////////////////////////////
	//�v�f�̃`�F�b�N
	if (m_EntityData.Find(DEF_REPRESENTATION_ITEM) == -1){
		//err
	}
	if (m_EntityData.Find(DEF_GEOMETRIC_REPRESENTATION_ITEM) == -1){
		//err
	}
	if (m_EntityData.Find(DEF_DRAUGHTING_ANNOTATION_OCCURRENCE) == -1){
		//err
	}
	if (m_EntityData.Find(DEF_STYLED_ITEM) == -1){
		//err
	}

	//<ANNOTATION�̔���>
	//�J�[�u�iCURVE�j
	if (m_EntityData.Find(DEF_ANNOTATION_CURVE_OCCURRENCE) != -1){
		m_AnnoKind = CURVESTYLE;

		// ���@���i���`�j////////////////////////////////////////////////////////
		if (m_EntityData.Find(DEF_DIMENSION_CURVE) != -1){
			m_CurveKind =DIMENSION_CURVE;

		}
		// ���@�⏕�� ////////////////////////////////////////////////////////
		else if (m_EntityData.Find(DEF_PROJECTION_CURVE) != -1){
			m_CurveKind =PROJECTION_CURVE;

		}
		// ���o����	 ////////////////////////////////////////////////////////
		else if (m_EntityData.Find(DEF_LEADER_CURVE) != -1){
			m_CurveKind =LEADER_CURVE;

		}
		// ��ʗv�f��Curve ////////////////////////////////////////////////////////
		else{
			m_CurveKind = CURVE;
		}
	}

	//�V���{��
	else if (m_EntityData.Find(DEF_ANNOTATION_SYMBOL_OCCURRENCE) != -1){
		m_AnnoKind = SYMBOLSTYLE;

		// ���  /////////////////////////////////////////////////////////////
		if (m_EntityData.Find(DEF_TERMINATOR_SYMBOL) != -1){

			// ���@�[�_���
			if (m_EntityData.Find(DEF_DIMENSION_CURVE_TERMINATOR) != -1){
				m_SymbolKind =DIM_CURVE_TERMINATOR;

			}
			// �����o�����A�o���[���[�_���
			else if (m_EntityData.Find(DEF_LEADER_TERMINATOR) != -1){
				m_SymbolKind =LEADER_TERMINATOR;

			}
		}
		// �����}�z�u
		else if (m_EntityData.Find(DEF_ANNOTATION_SUBFIGURE_OCCURRENCE) != -1){
			m_SymbolKind =SUBFIGURE_OCCURRENCE;

		}// �_�}�[�J�A����`�i�O����`�j�A���̑��V���{��///////////////////
		else{
			m_SymbolKind =SYMBOL;

		}
	}
	//�����v�f
	else if (m_EntityData.Find(DEF_ANNOTATION_TEXT_OCCURRENCE) != -1){
		m_AnnoKind = TEXTSTYLE;
	}
	//�n�b�`���O
	else if (m_EntityData.Find(DEF_ANNOTATION_FILL_AREA_OCCURRENCE) != -1){
		m_AnnoKind = FILLSTYLE;
	}

	else{
	// SCADEC�̑Ώۂł͂Ȃ�ENTITY�ł�
		SXFErrorMsgC::RecordError(
			SXFEXCEPT,			//err���b�Z�[�W�ԍ�
			m_EntityName,		//�G���e�B�e�B��
			2,					//�p�����^�̌�
			m_RootID,			//�p�����^
			m_EntityName
			);
		return SXFEXCEPT;
	}
	return 0;
}
