/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapGeometryC.cpp						�쐬���F2001.07.21

	�P�D�N���X�T�v
		AP202�G���e�B�e�B����t�B�[�`���ւ̃}�b�s���O���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2001.07.21	���X��(FQS)	

**/
#include "stdafx.h"
#include "SXFTableManagerC.h"
#include "SXFReadAP202ManagerC.h"
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_CurveStyleBaseC.h"
#include "SXFMapF_ColorBaseC.h"
#include "SXFMapAnnoBodyC.h" 
#include "SXFMapCalloutBodyC.h" 
#include "SXFMapCompBodyC.h" 
#include "SXFMapGeometryC.h"
#include "SXFMapE_STYLED_ITEMC.h" 
#include "SXFMapF_LINEC.h" 
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
#include "SXFMapF_LINERDIMC.h" 
#include "SXFMapF_POINTMARKERC.h" 
#include "SXFMapF_POLYLINEC.h" 
#include "SXFMapF_RADIUSDIMC.h"
#include "SXFMapF_SFIGLOCC.h"
#include "SXFMapF_SPLINEC.h"
#include "SXFMapF_CLOTHOIDC.h"
#include "SXFMapF_TERMSYMBOLC.h" 
#include "SXFMapF_TEXTSTRINGC.h"
#include "SXFMapEntAConvC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
	
/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapGeometryC.cpp						�쐬���F2001.07.21

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapGeometryC::SXFMapGeometryC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2001.07.21	���X��(FQS)
**/
SXFMapGeometryC::SXFMapGeometryC()
{
//	<������>
//	<BODY���> ///////////////////////////////////////////////////////
	m_BodyKind=0 ;
	//		0:�s��
	//		1:ANNOTATION_OCCURRENCE
	//		2:DRAUGHTING_CALLOUT
	//		3:COMPOSITE_CURVE_SEGMENT

	//SXFTableManagerC�ւ̃|�C���^
	m_TableManager=NULL;
	m_ComInfoC=NULL;
	m_ReadManager = NULL;
	m_StructData = NULL;
	m_calloutbody = NULL;
	m_annobody = NULL;
	m_compbody =NULL;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapGeometryC.cpp						�쐬���F2001.07.21

	�P�D�@�\�T�v
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapGeometryC::SXFMapGeometryC(
						SXFInstanceIDC* IN_InstanceIDManeger, 
						SXFTableManagerC* IN_TableManager,
						SXFComInfoC* IN_ComInfoC ,
						SXFReadAP202ManagerC* IN_ReadManager)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

	���� �F	�^						������				���e
			SXFInstanceIDC* 		IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��
			SXFTableManagerC* 		IN_TableManager			��`ð��يǗ���޼ު��
			SXFComInfoC* 			IN_ComInfoC				���ʏ��Ǘ���޼ު��
			SXFReadAP202ManagerC* 	IN_ReadManager			Read�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2001.07.21	
**/
//�C���X�^���X�h�c�ւ̃|�C���^��o�^����������
SXFMapGeometryC::SXFMapGeometryC(
		SXFInstanceIDC* IN_InstanceIDManeger, 
		SXFTableManagerC* IN_TableManager,
		SXFComInfoC* IN_ComInfoC ,
		SXFReadAP202ManagerC* IN_ReadManager)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	//	<BODY���> ///////////////////////////////////////////////////////
	m_BodyKind=0 ;
	//		0:�s��
	//		1:ANNOTATION_OCCURRENCE
	//		2:DRAUGHTING_CALLOUT
	//		3:COMPOSITE_CURVE_SEGMENT

	//SXFTableManagerC�ւ̃|�C���^
	m_TableManager=IN_TableManager;
	//SXFComInfoC�ւ̃|�C���^
	m_ComInfoC = IN_ComInfoC;
	m_ReadManager = IN_ReadManager;
	m_StructData = NULL;
	m_calloutbody = NULL;
	m_annobody = NULL;
	m_compbody =NULL;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapGeometryC.cpp						�쐬���F2001.07.21

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapGeometryC::~SXFMapGeometryC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2001.07.21	���X��(FQS)
**/
SXFMapGeometryC::~SXFMapGeometryC()
{

	if(m_calloutbody != NULL)
		delete m_calloutbody;
	if(m_annobody != NULL)
		delete m_annobody;
	if (m_compbody !=NULL ) 
		delete m_compbody;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapGeometryC.cpp						�쐬���F2001.07.21

	�P�D�@�\�T�v
		��ʗv�f�t�B�[�`���\���̂̍쐬

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapGeometryC::SetFeatureParameter(
					int		OUT_type,
					void*	OUT_Class)


	����  �F	�^			������				���e
				int			OUT_type,	//��`�e�[�u�����	
				void*		OUT_Class	//��`�e�[�u���t�B�[�`���N���X�ւ̃|�C���^


	���A�l�F��`�e�[�u�����

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2001.07.21	���X��(FQS)
**/
int	SXFMapGeometryC::	SetFeatureParameter(
					int		&OUT_Type,	//�t�B�[�`�����	
					LPVOID	&OUT_Class)	//�t�B�[�`���N���X�ւ̃|�C���^

{
	//������
	int ircode;
	ircode = 0;
	//�e�ʂ̎�ʔ���Ɛe�ʂɍ��킹��BODY�N���X�쐬
	//	<BODY���> ///////////////////////////////////////////////////////
	m_BodyKind=0 ;
	//		0:�s��
	//		1:ANNOTATION_OCCURRENCE
	//		2:DRAUGHTING_CALLOUT
	//		3:COMPOSITE_CURVE_SEGMENT
		
	//Body�̔���
	//< COMPLEX > 
	if (m_EntityName == DEF_SXF_COMPLEX_INSTANCE ) {

		//< ANNOTATION_OCCURRENCE�n >/////////////////////////////////////
		if (m_EntityData.Find(DEF_ANNOTATION_OCCURRENCE) != -1){
			m_BodyKind = 1;

			// ANNOTATION_OCCURRENCE�n��BODY�N���X�쐬
			if (m_annobody) 
				delete m_annobody;
				m_annobody = new SXFMapAnnoBodyC(m_InstanceIDManager,m_TableManager,m_ReadManager);
				m_annobody->SetRootID(m_RootID);
				ircode = m_annobody->SetParameter();
				if (ircode <0 )return ircode;

					OUT_Type  = m_annobody->m_Type;	//�t�B�[�`���^�C�v	
					OUT_Class = m_annobody->m_Class;	//�t�B�[�`���N���X�ւ̃|�C���^

		}
		//< DRAUGHTING_CALLOUT�n >/////////////////////////////////////
		else if ((m_EntityData.Find(DEF_DRAUGHTING_CALLOUT) != -1)&&
				(m_EntityData.Find(DEF_STRUCTURED_DIMENSION_CALLOUT) == -1)){
				m_BodyKind = 2;

			// DRAUGHTING_CALLOUT�n��BODY�N���X�쐬
			if (m_calloutbody)
				delete m_calloutbody;
				m_calloutbody = new SXFMapCalloutBodyC(m_InstanceIDManager,m_TableManager,m_ReadManager);
				m_calloutbody->SetRootID(m_RootID);
				ircode = m_calloutbody->SetFeatureParameter();
				if (ircode <0 )return ircode;

					OUT_Type  = m_calloutbody->m_Type;	//�t�B�[�`���^�C�v	
					OUT_Class = m_calloutbody->m_Class;	//�t�B�[�`���N���X�ւ̃|�C���^
		}
		else if (m_EntityData.Find(DEF_STRUCTURED_DIMENSION_CALLOUT) != -1){
			return 0;
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
	}
	//< STYLED_ITEM >
	else if ( m_EntityName == DEF_STYLED_ITEM){

		SXFMapE_STYLED_ITEMC styled(m_InstanceIDManager);
		styled.SetRootID(m_RootID);
		styled.SetEntity();
		styled.SetParameter();

		// STYLED_ITEM���Q�Ƃ��Ă���C���X�^���X���`�F�b�N
		SXFMapEntityBaseC body(m_InstanceIDManager);
		body.SetRootID(styled.m_InstID);
		body.SetEntity();

		//< DRAUGHTING_CALLOUT�n >/////////////////////////////////////
		if ((body.m_EntityData.Find(DEF_DRAUGHTING_CALLOUT) != -1)&&
				(body.m_EntityData.Find(DEF_STRUCTURED_DIMENSION_CALLOUT) == -1)){
				m_BodyKind = 2;

			// DRAUGHTING_CALLOUT�n��BODY�N���X�쐬
			if (m_calloutbody)
				delete m_calloutbody;
				m_calloutbody = new SXFMapCalloutBodyC(m_InstanceIDManager,m_TableManager,m_ReadManager);
				m_calloutbody->SetRootID(styled.m_InstID);
				ircode = m_calloutbody->SetFeatureParameter();
				if (ircode <0 )return ircode;

					OUT_Type  = m_calloutbody->m_Type;		//�t�B�[�`���^�C�v	
					OUT_Class = m_calloutbody->m_Class;	//�t�B�[�`���N���X�ւ̃|�C���^
		}
		else if (body.m_EntityData.Find(DEF_STRUCTURED_DIMENSION_CALLOUT) != -1){
			return 0;
		}
		else{
		// SCADEC�̑Ώۂł͂Ȃ�ENTITY�ł�
			SXFErrorMsgC::RecordError(
				SXFEXCEPT,				//err���b�Z�[�W�ԍ�
				body.m_EntityName,		//�G���e�B�e�B��
				2,						//�p�����^�̌�
				styled.m_InstID,		//�p�����^
				body.m_EntityName
				);
			return SXFEXCEPT;

		}

	}
	//////////////////////////////////////////////////////////////////////
	//	COMPOSITE_CURVE_SEGMENT  /////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	else if ( m_EntityName == DEF_COMPOSITE_CURVE_SEGMENT){
		m_BodyKind = 3;

		// ANNOTATION_OCCURRENCE�n��BODY�N���X�쐬
		if (m_compbody)
			delete m_compbody;
			m_compbody = new SXFMapCompBodyC(m_InstanceIDManager,m_TableManager,m_ReadManager);
			m_compbody->SetRootID(m_RootID);
			ircode = m_compbody->SetParameter();
			if (ircode <0 )return ircode;

				OUT_Type  = m_compbody->m_Type;	//�t�B�[�`���^�C�v	
				OUT_Class = m_compbody->m_Class;	//�t�B�[�`���N���X�ւ̃|�C���^

	}
	else if (m_EntityName == DEF_AXIS2_PLACEMENT_2D ||
			m_EntityName == DEF_PLANAR_BOX){
		return 0;
	}

//	ADD(S)	Ver3.0�Ή�	K.Naono	04.01.30
	else if( m_EntityName == DEF_DRAUGHTING_CONTRACT_ASSIGNMENT ) {
		OUT_Type = attribute_feature ;
	}
//	ADD(E)	Ver3.0�Ή�	K.Naono	04.01.30

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

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapGeometryC.cpp						�쐬���F2001.07.21

	�P�D�@�\�T�v
		�t�B�[�`���\���̂ɒl��ݒ�

	�Q�D�C���^�[�t�F�C�X
	int		SXFMapGeometryC::SetStructData(
				int		IN_Type,
				LPVOID	IN_Class);

	����  �F	�^			������				���e
				int			IN_Type,	//�t�B�[�`���^�C�v
				LPVOID		IN_Class	//�t�B�[�`���N���X�ւ̃|�C���^
			
	���A�l�F�t�B�[�`���h�c

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2001.07.21	���X��(FQS)
**/
int SXFMapGeometryC::SetStructData(
				int		IN_Type,
				LPVOID	IN_Class)
{

	m_Type 	= (E_type)IN_Type;
	m_Class	= IN_Class;

/*
	NONFEATURE=0,
	drawing_sheet_feature,
	layer_feature,
	pre_defined_font_feature,
	user_defined_font_feature,
	pre_defined_colour_feature,
	user_defined_colour_feature,
	width_feature,
	text_font_feature,

	point_marker_feature,
	line_feature,
	polyline_feature,
	circle_feature,
	arc_feature,
	ellipse_feature,
	ellipse_arc_feature,
	text_string_feature,
	spline_feature,
	clothoid_feature,

	sfig_locate_feature,
	sfig_org_feature,
	externally_defined_symbol_feature,
	linear_dim_feature,
	curve_dim_feature,
	angular_dim_feature,
	radius_dim_feature,
	diameter_dim_feature,
	label_feature,
	balloon_feature,
	externally_defined_hatch_feature,
	fill_area_style_colour_feature,
	fill_area_style_hatching_feature,
	fill_area_style_tiles_feature,
	composite_curve_org_feature,

	projection_line,
	dimension_line,
	dimension_erminator_symbol
*/
	if(m_Type == drawing_sheet_feature ){//1

		//�\���̃f�[�^�쐬
		Sheet_Struct* sheet = new Sheet_Struct;

		//�\���̃f�[�^�̕ۑ�
		m_StructData = sheet;

		//�t�B�[�`�����x��
		m_Level = 1;

//	ADD(S)	Ver3.0�Ή�	K.Naono	04.01.30
	} else if( m_Type == attribute_feature ) {

		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_ATTRIBUTE);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_ATTRIBUTE);

		//�\���̃f�[�^�쐬
		Attribute_Struct*	attr = new Attribute_Struct ;
		m_TableManager->GetAttributeData(attr) ;

		//�\���̃f�[�^�̕ۑ�
		m_StructData = attr ;

		//�t�B�[�`�����x��
		m_Level = 1 ;

//	ADD(E)	Ver3.0�Ή�	K.Naono	04.01.30

	}else if(m_Type == point_marker_feature ){//2

		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_POINT_MARKER);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_POINT_MARKER);

		//�\���̃f�[�^�쐬
		Point_Marker_Struct* pointmarker = new Point_Marker_Struct;
		((SXFMapF_POINTMARKERC*)m_Class)->GetStructData(pointmarker);
		//�\���̃f�[�^�̕ۑ�
		m_StructData = pointmarker;

		//�t�B�[�`�����x��
		m_Level = 1;

	}else if(m_Type == line_feature ){//3
		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_LINE);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_LINE);
		//�\���̃f�[�^�쐬
		Line_Struct* line = new Line_Struct;
		((SXFMapF_LINEC*)m_Class)->GetStructData(line);
		//�\���̃f�[�^�̕ۑ�
		m_StructData = line;
		//�t�B�[�`�����x��
		m_Level = 1;

	}else if(m_Type == polyline_feature ){//4

		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_POLYLINE);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_POLYLINE);
		//�\���̃f�[�^�쐬
		Polyline_Struct* polyline = new Polyline_Struct;
		((SXFMapF_POLYLINEC*)m_Class)->GetStructData(polyline);
		//�\���̃f�[�^�̕ۑ�
		m_StructData = polyline;
		//�t�B�[�`�����x��
		m_Level = 1;

	}else if(m_Type == circle_feature ){//5

		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_CIRCLE);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_CIRCLE);
		//�\���̃f�[�^�쐬
		Circle_Struct* circle = new Circle_Struct;
		((SXFMapF_CIRCLEC*)m_Class)->GetStructData(circle);
		//�\���̃f�[�^�̕ۑ�
		m_StructData = circle;
		//�t�B�[�`�����x��
		m_Level = 1;

	}else if(m_Type == arc_feature ){//6
		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(m_TypeName,  DEF_ARC);
		strcpy_s(m_TypeName,_countof(m_TypeName),  DEF_ARC);
		//�\���̃f�[�^�쐬
		Arc_Struct* arc = new Arc_Struct;
		((SXFMapF_ARCC*)m_Class)->GetStructData(arc);
		//�\���̃f�[�^�̕ۑ�
		m_StructData = arc;
		//�t�B�[�`�����x��
		m_Level = 1;

	}else if(m_Type == ellipse_feature ){//7
		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_ELLIPSE);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_ELLIPSE);
		//�\���̃f�[�^�쐬
		Ellipse_Struct* ellipse = new Ellipse_Struct;
		((SXFMapF_ELLIPSEC*)m_Class)->GetStructData(ellipse);
		//�\���̃f�[�^�̕ۑ�
		m_StructData = ellipse;
		//�t�B�[�`�����x��
		m_Level = 1;

	}else if(m_Type == ellipse_arc_feature ){//8

		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_ELLIPSE_ARC);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_ELLIPSE_ARC);
		//�\���̃f�[�^�쐬
		Ellipse_Arc_Struct* ellipsearc = new Ellipse_Arc_Struct;
		((SXFMapF_ELLIPSEARCC*)m_Class)->GetStructData(ellipsearc);
		//�\���̃f�[�^�̕ۑ�
		m_StructData = ellipsearc;
		//�t�B�[�`�����x��
		m_Level = 1;

	}else if(m_Type == text_string_feature ){//9

		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_TEXT);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_TEXT);

		//�\���̃f�[�^�쐬
		Text_Struct* textstring = new Text_Struct;
		((SXFMapF_TEXTSTRINGC*)m_Class)->GetStructData(textstring);
		//�\���̃f�[�^�̕ۑ�
		m_StructData = textstring;
		//�t�B�[�`�����x��
		m_Level = 1;

	}else if(m_Type == spline_feature ){//10

		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_SPLINE);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_SPLINE);

		//�\���̃f�[�^�쐬
		Spline_Struct* spline = new Spline_Struct;
		((SXFMapF_SPLINEC*)m_Class)->GetStructData(spline);
		//�\���̃f�[�^�̕ۑ�
		m_StructData = spline;
		//�t�B�[�`�����x��
		m_Level = 2;

	}else if(m_Type == clothoid_feature ){//10

		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_CLOTHOID);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_CLOTHOID);

		//�\���̃f�[�^�쐬
		Clothoid_Struct* clothoid = new Clothoid_Struct;
		((SXFMapF_CLOTHOIDC*)m_Class)->GetStructData(clothoid);
		//�\���̃f�[�^�̕ۑ�
		m_StructData = clothoid;
		//�t�B�[�`�����x��
		m_Level = 2;

	}else if(m_Type == sfig_org_feature ){//11

		//�\���̃f�[�^�쐬
		Sfigorg_Struct* sfigorg = new Sfigorg_Struct;
		//�\���̃f�[�^�̕ۑ�
		m_StructData = sfigorg;
		//�t�B�[�`�����x��
		m_Level = 1;

	}else if(m_Type == sfig_locate_feature ){//12

		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_SFIG_LOCATE);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_SFIG_LOCATE);
		//�\���̃f�[�^�쐬
		Sfigloc_Struct* sfiglocate = new Sfigloc_Struct;
		((SXFMapF_SFIGLOCC*)m_Class)->GetStructData(sfiglocate);
		//�\���̃f�[�^�̕ۑ�
		m_StructData = sfiglocate;
		//�t�B�[�`�����x��
		m_Level = 1;

	}else if(m_Type == externally_defined_symbol_feature ){//13

		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_EXTERNALLY_DEFINED_SYMBOL);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_EXTERNALLY_DEFINED_SYMBOL);
		//�\���̃f�[�^�쐬
		Externally_Defined_Symbol_Struct* exsymbol = new Externally_Defined_Symbol_Struct;
		((SXFMapF_EXSYMBOLC*)m_Class)->GetStructData(exsymbol);
		//�\���̃f�[�^�̕ۑ�
		m_StructData = exsymbol;
		//�t�B�[�`�����x��
		m_Level = 2;

	}else if(m_Type == linear_dim_feature ){//14

		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_LINEAR_DIMENSION);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_LINEAR_DIMENSION);

		//�\���̃f�[�^�쐬
		LinearDim_Struct* lineardim = new LinearDim_Struct;
		((SXFMapF_LINERDIMC*)m_Class)->GetStructData(lineardim);
		//�\���̃f�[�^�̕ۑ�
		m_StructData = lineardim;
		//�t�B�[�`�����x��
		m_Level = 2;

	}else if(m_Type == curve_dim_feature ){//15
		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_CURVE_DIMENSION);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_CURVE_DIMENSION);
		//�\���̃f�[�^�쐬
		CurveDim_Struct* curvedim = new CurveDim_Struct;
		((SXFMapF_CURVEDIMC*)m_Class)->GetStructData(curvedim);
		//�\���̃f�[�^�̕ۑ�
		m_StructData = curvedim;
		//�t�B�[�`�����x��
		m_Level = 2;

	}else if(m_Type == angular_dim_feature ){//15
		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_ANGULAR_DIMENSION);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_ANGULAR_DIMENSION);
		//�\���̃f�[�^�쐬
		AngularDim_Struct* angulardim = new AngularDim_Struct;
		((SXFMapF_ANGULARDIMC*)m_Class)->GetStructData(angulardim);
		//�\���̃f�[�^�̕ۑ�
		m_StructData = angulardim;
		//�t�B�[�`�����x��
		m_Level = 2;

	}else if(m_Type == radius_dim_feature ){//16
		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(m_TypeName,  DEF_RADIUS_DIMENSION);
		strcpy_s(m_TypeName,_countof(m_TypeName),  DEF_RADIUS_DIMENSION);
		//�\���̃f�[�^�쐬
		RadiusDim_Struct* radiusdim = new RadiusDim_Struct;
		((SXFMapF_RADIUSDIMC*)m_Class)->GetStructData(radiusdim);
		//�\���̃f�[�^�̕ۑ�
		m_StructData = radiusdim;
		//�t�B�[�`�����x��
		m_Level = 2;

	}else if(m_Type == diameter_dim_feature ){//17
		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_DIAMETER_DIMENSION);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_DIAMETER_DIMENSION);
		//�\���̃f�[�^�쐬
		DiameterDim_Struct* diameterdim = new DiameterDim_Struct;
		((SXFMapF_DIMETERDIMC*)m_Class)->GetStructData(diameterdim);
		//�\���̃f�[�^�̕ۑ�
		m_StructData = diameterdim;
		//�t�B�[�`�����x��
		m_Level = 2;

	}else if(m_Type == label_feature ){//18
		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_LABEL);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_LABEL);

		//�\���̃f�[�^�쐬
		Label_Struct* label = new Label_Struct;
		((SXFMapF_LABELC*)m_Class)->GetStructData(label);
		//�\���̃f�[�^�̕ۑ�
		m_StructData = label;
		//�t�B�[�`�����x��
		m_Level = 2;

	}else if(m_Type == balloon_feature ){//19
		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(m_TypeName,  DEF_BALLOON);
		strcpy_s(m_TypeName,_countof(m_TypeName),  DEF_BALLOON);

		//�\���̃f�[�^�쐬
		Balloon_Struct* balloon = new Balloon_Struct;
		((SXFMapF_BALLOONC*)m_Class)->GetStructData(balloon);
		//�\���̃f�[�^�̕ۑ�
		m_StructData = balloon;
		//�t�B�[�`�����x��
		m_Level = 2;

	}else if(m_Type == externally_defined_hatch_feature ){//20
		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_EXTERNALLY_DEFINED_HATCH);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_EXTERNALLY_DEFINED_HATCH);

		//�\���̃f�[�^�쐬
		Externally_Defined_Hatch_Struct* externallyhatch = new Externally_Defined_Hatch_Struct;
		((SXFMapF_EXHATCHC*)m_Class)->GetStructData(externallyhatch);
		//�\���̃f�[�^�̕ۑ�
		m_StructData = externallyhatch;
		//�t�B�[�`�����x��
		m_Level = 2;

	}else if(m_Type == fill_area_style_colour_feature ){//21
		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(m_TypeName,  DEF_FILL_AREA_STYLE_COLOUR);
		strcpy_s(m_TypeName,_countof(m_TypeName),  DEF_FILL_AREA_STYLE_COLOUR);

		//�\���̃f�[�^�쐬
		Fill_area_style_colour_Struct* fillcolor = new Fill_area_style_colour_Struct;
		((SXFMapF_FILLCOLOURC*)m_Class)->GetStructData(fillcolor);
		//�\���̃f�[�^�̕ۑ�
		m_StructData = fillcolor;
		//�t�B�[�`�����x��
		m_Level = 2;

	}else if(m_Type == fill_area_style_hatching_feature ){//22
		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_FILL_AREA_STYLE_HATCHING);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_FILL_AREA_STYLE_HATCHING);

		//�\���̃f�[�^�쐬
		Fill_area_style_hatching_Struct* fillstyle = new Fill_area_style_hatching_Struct;
		((SXFMapF_FILLHATCHINGC*)m_Class)->GetStructData(fillstyle);
		//�\���̃f�[�^�̕ۑ�
		m_StructData = fillstyle;
		//�t�B�[�`�����x��
		m_Level = 2;

	}else if(m_Type == fill_area_style_tiles_feature){//23
		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(m_TypeName, DEF_FILL_AREA_STYLE_TILES);
		strcpy_s(m_TypeName,_countof(m_TypeName), DEF_FILL_AREA_STYLE_TILES);

		//�\���̃f�[�^�쐬
		Fill_area_style_tiles_Struct* filltiles = new Fill_area_style_tiles_Struct;
		((SXFMapF_FILLTILESC*)m_Class)->GetStructData(filltiles);
		//�\���̃f�[�^�̕ۑ�
		m_StructData = filltiles;
		//�t�B�[�`�����x��
		m_Level = 2;

	}else if(m_Type == composite_curve_org_feature ){//24

		//�\���̃f�[�^�쐬
		Ccurve_Org_Struct* curveorg = new Ccurve_Org_Struct;

		//�\���̃f�[�^�̕ۑ�
		m_StructData = curveorg;
		//�t�B�[�`�����x��
		m_Level = 2;

	}else{//feature comment name error
		return FALSE;
	}
	return TRUE;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapGeometryC.cpp						�쐬���F2001.07.21

	�P�D�@�\�T�v
		�t�B�[�`���\���̂��擾

	�Q�D�C���^�[�t�F�C�X
	int		SXFMapGeometryC::GetStructData(
				char*&		OUT_Name,
				size_t		NameSize,
				LPVOID		&Out_Struct)

	����  �F	�^			������			���e
				char*&		OUT_Name		�t�B�[�`����
				size_t		NameSize,		�t�B�[�`�����o�b�t�@�T�C�Y
				LPVOID		&OUT_Struct		�t�B�[�`���\����

	���A�l�F�t�B�[�`���h�c

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2001.07.21	���X��(FQS)
	�X�V		2015.04.27	T.Matsushima	JPCERT/CC �w�E �Ǝ㐫�Ή�
**/
int SXFMapGeometryC::GetStructData(
		char*&		OUT_Name,
		size_t		NameSize,		// �o�b�t�@�T�C�Y��n���悤�ɕύX
		LPVOID		&OUT_Struct)
{
//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
//	strcpy(OUT_Name, m_TypeName);
	strcpy_s(OUT_Name, NameSize, m_TypeName);
	OUT_Struct 	= m_StructData;

	return (m_RootID) ;
}
