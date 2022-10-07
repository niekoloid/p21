/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapCalloutBodyC.cpp						�쐬���F2000.04.21

	�P�D�N���X�T�v
		DRAUGHTING_CALLOUT�n��BODY���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.21	

**/

#include "stdafx.h"
#include "SXFTableManagerC.h"
#include "SXFReadAP202ManagerC.h"
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_CurveStyleBaseC.h"
#include "SXFMapF_ColorBaseC.h"
#include "SXFMapEntCConvC.h"
#include "SXFF_FeatureTypeE.h"
#include "SXFMapF_LINEC.h" 
#include "SXFMapAnnoBodyC.h"
#include "SXFMapF_CURVEDIMC.h" 
#include "SXFMapF_ANGULARDIMC.h" 
#include "SXFMapF_ARCC.h" 
#include "SXFMapF_BALLOONC.h" 
#include "SXFMapF_CIRCLEC.h" 
#include "SXFMapF_DIMETERDIMC.h" 
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
#include "SXFMapCalloutBodyC.h"	
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapCalloutBodyC.cpp						�쐬���F2000.04.21

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapCalloutBodyC::SXFMapCalloutBodyC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.21	
**/
SXFMapCalloutBodyC::SXFMapCalloutBodyC( )
{
//
//	<������>
//
//< DRAUGHTING_CALLOUT�n >/////////////////////////////////////
	m_CalloutKind =0;
//		0:�s��
//		1:DIMENSION_CURVE_DIRECTED_CALLOUT
//		2:LEADER_DIRECTED_CALLOUT
//

//< DIMENSION�n >/////////////////////////////////////
	m_DimensionKind =0;
//		0:NONDIMENSION
//		1:LINEAR_DIMENSION
//		2:ANGULAR_DIMENSION
//		3:DIAMETER_DIMENSION
//		4:RADIUS_DIMENSION
//		5:CURVE_DIMENSION

//< LEADER�n >/////////////////////////////////////
	m_LavelKind =0;
//		0:NONLEADER
//		1:LABEL
//		2:BALLOON
//

	m_ContentsNum = 0;
//	<�R���e���c�ւ̂h�c>
	m_ContentsID.RemoveAll() ;
//	<�R���e���c�ւ̃|�C���^>
	m_ContentsP.RemoveAll();

//	<SXFTableManagerC�ւ̃|�C���^>
	m_TableManager=NULL;
//	<SXFReadAP202ManagerC�ւ̃|�C���^>
	m_ReadManager=NULL;

//	<���C���R�[�h>
	m_layer=0;
//	<�t�B�[�`���^�C�v>
	m_Type=NONFEATURE;
//	<�t�B�[�`���N���X�ւ̃|�C���^>
	m_Class=NULL;

// DIMENSION LINE �t���O
	 m_dimline=0;
//DIMENSION ARC �t���O
	 m_dimarc=0;
// DIMENSION TEXT �t���O
	 m_dimtext=0;
// PROJECTION LINE1 �t���O
	 m_prjline1=0;
// PROJECTION LINE2 �t���O
	 m_prjline2=0;
// LEADER CURVE �t���O
	 m_leader=0;
// TERM1 �t���O
	 m_term1=0;
// TERM2 �t���O
	 m_term2=0;
// CIRCLE �t���O
	 m_balloon =0;

// DIMENSION LINE �ւ̃|�C���^
	m_dimlineP=NULL;

// DIMENSION ARC�ւ̃|�C���^
	m_dimarcP=NULL;

// DIMENSION TEXT �ւ̃|�C���^
	m_dimtextP=NULL;

// PROJECTION LINE1 �ւ̃|�C���^
	m_prjline1P=NULL;

// PROJECTION LINE2 �ւ̃|�C���^
	m_prjline2P=NULL;

// LEADER CURVE�ւ̃|�C���^
	m_leader=NULL;

// TERM1 �ւ̃|�C���^
	m_term1P=NULL;

// TERM2 �ւ̃|�C���^
	m_term2P=NULL;

// CIRCLE �ւ̃|�C���^
	m_balloonP=NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapCalloutBodyC.cpp						�쐬���F2000.04.21

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapCalloutBodyC::SXFMapCalloutBodyC(
					SXFInstanceIDC* IN_InstanceIDManeger,
					SXFTableManagerC* IN_TableManager,
					SXFReadAP202ManagerC* IN_ReadManager)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	�����F	�^						������					���e
			SXFInstanceIDC* 		IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��
			SXFTableManagerC* 		IN_TableManager			��`ð��يǗ���޼ު��
			SXFReadAP202ManagerC* 	IN_ReadManager			Read�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.21	
**/

//	<�C���X�^���X�h�c�ւ̃|�C���^��o�^����������>
		
SXFMapCalloutBodyC::SXFMapCalloutBodyC(
		SXFInstanceIDC* IN_InstanceIDManeger,
		SXFTableManagerC* IN_TableManager,
		SXFReadAP202ManagerC* IN_ReadManager)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	
//< DRAUGHTING_CALLOUT�n >/////////////////////////////////////
	m_CalloutKind =0;
//		0:�s��
//		1:DIMENSION_CURVE_DIRECTED_CALLOUT
//		2:LEADER_DIRECTED_CALLOUT
//

//< DIMENSION�n >/////////////////////////////////////
	m_DimensionKind =0;
//		0:NONDIMENSION
//		1:LINEAR_DIMENSION
//		2:ANGULAR_DIMENSION
//		3:DIAMETER_DIMENSION
//		4:RADIUS_DIMENSION
//		5:CURVE_DIMENSION

//< LEADER�n >/////////////////////////////////////
	m_LavelKind =0;
//		0:NONLEADER
//		1:LABEL
//		2:BALLOON
//
//	<�R���e���c�ւ̂h�c>
	m_ContentsID.RemoveAll() ;
//	<�R���e���c�ւ̃|�C���^>
	m_ContentsP.RemoveAll();

//	<���C���R�[�h>
	m_layer=0;
//	<�t�B�[�`���^�C�v>
	m_Type=NONFEATURE;
//	<�t�B�[�`���N���X�ւ̃|�C���^>
	m_Class=NULL;

// DIMENSION LINE �t���O
	 m_dimline=0;
//DIMENSION ARC �t���O
	 m_dimarc=0;
// DIMENSION TEXT �t���O
	 m_dimtext=0;
// PROJECTION LINE1 �t���O
	 m_prjline1=0;
// PROJECTION LINE2 �t���O
	 m_prjline2=0;
// LEADER CURVE �t���O
	 m_leader=0;
// TERM1 �t���O
	 m_term1=0;
// TERM2 �t���O
	 m_term2=0;
// CIRCLE �t���O
	 m_balloon =0;

// DIMENSION LINE �ւ̃|�C���^
	m_dimlineP=NULL;

// DIMENSION ARC�ւ̃|�C���^
	m_dimarcP=NULL;

// DIMENSION TEXT �ւ̃|�C���^
	m_dimtextP=NULL;

// PROJECTION LINE1 �ւ̃|�C���^
	m_prjline1P=NULL;

// PROJECTION LINE2 �ւ̃|�C���^
	m_prjline2P=NULL;

// LEADER CURVE�ւ̃|�C���^
	m_leader=NULL;

// TERM1 �ւ̃|�C���^
	m_term1P=NULL;

// TERM2 �ւ̃|�C���^
	m_term2P=NULL;  

// CIRCLE �ւ̃|�C���^
	m_balloonP=NULL;
	
//	<SXFTableManagerC�ւ̃|�C���^>
    m_TableManager = IN_TableManager;
//	<SXFReadAP202ManagerC>
	m_ReadManager= IN_ReadManager;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapCalloutBodyC.cpp						�쐬���F2000.04.21

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapCalloutBodyC::~SXFMapCalloutBodyC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.21	
**/
SXFMapCalloutBodyC::~SXFMapCalloutBodyC()
{

	if (m_Class!=NULL){
		if ( m_Type == linear_dim_feature )
		 delete (SXFMapF_LINERDIMC*)m_Class;
		if ( m_Type == curve_dim_feature )
		 delete (SXFMapF_CURVEDIMC*)m_Class;
		if ( m_Type == angular_dim_feature )
		 delete (SXFMapF_ANGULARDIMC*)m_Class;
		if ( m_Type == radius_dim_feature )
		 delete (SXFMapF_RADIUSDIMC*)m_Class;
		if ( m_Type == diameter_dim_feature )
		 delete (SXFMapF_DIMETERDIMC*)m_Class;
		if ( m_Type == label_feature )
		 delete (SXFMapF_LABELC*)m_Class;
		if ( m_Type == balloon_feature )
		 delete (SXFMapF_BALLOONC*)m_Class;
	}

	for(int i=0;i<m_ContentsP.GetSize();i++){
		if( m_ContentsP[i] != NULL)
			delete m_ContentsP[i];
	}
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapCalloutBodyC.cpp						�쐬���F2000.04.21

	�P�D�@�\�T�v
		DRAUGHTING_CALLOUT�n�t�B�[�`���p�����^�ݒ�

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapCalloutBodyC::	SetFeatureParameter()


	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F��`�e�[�u�����

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.21	
**/
int	SXFMapCalloutBodyC::	SetFeatureParameter()
{
//
//	<������>
//
	int ircode =0;

	// DIMENSION LINE �t���O
	 m_dimline=0;
	//DIMENSION ARC �t���O
	 m_dimarc=0;
	// DIMENSION TEXT �t���O
	 m_dimtext=0;
	// PROJECTION LINE1 �t���O
	 m_prjline1=0;
	// PROJECTION LINE2 �t���O
	 m_prjline2=0;
	// LEADER CURVE �t���O
	 m_leader=0;
	// TERM1 �t���O
	 m_term1=0;
	// TERM2 �t���O
	 m_term2=0;
	// CIRCLE �t���O
	 m_balloon =0;

	//�e�ʂ̎�ʔ���Ɛe�ʂɍ��킹��BODY�N���X�쐬
	ircode = CheckBodyKind();
	if ( ircode <0 )return ircode;

	////////////////////////////////////////////////////////////////////////////////
	// �R���e���c�̂h�c�����o��
	////////////////////////////////////////////////////////////////////////////////

//  DRAUGHTING_CALLOUT((#1968, #1974, #1983, #1993))

	// COMPLEX�G���e�B�e�B�̃f�[�^�����o��
	SXFMapEntCConvC convert(m_EntityArray);

	//	STYLED_ITEM �̃p�����^�����o��
	convert.SplitComplex(DEF_DRAUGHTING_CALLOUT);
	convert.GetSetInst(0,m_ContentsNum,m_ContentsID);			

	////////////////////////////////////////////////////////////////////////////////
	// �R���e���c���̐}�`�C���X�^���X�iSXFMapAnnoBodyC�j���쐬����
	////////////////////////////////////////////////////////////////////////////////

	// ANNOTATION_OCCURRENCE�n��BODY�N���X�쐬

	for ( int i=0; i<m_ContentsNum;i++){

		SXFMapAnnoBodyC* annobody =
			new SXFMapAnnoBodyC(m_InstanceIDManager,m_TableManager,m_ReadManager);
		m_ContentsP.Add(annobody);
		ircode = annobody->SetRootID(m_ContentsID[i]);
		if ( ircode < 0 )
			return ircode ;
		ircode = annobody->SetParameter();
		if ( ircode < 0 )
			return ircode ;

		//DIMENSION_CURVE
		if(annobody->m_Type == line_feature){
			//	DIMENSION_CURVE,	//2:���@���i���`�j
			if (annobody->m_CurveKind ==2 ){
				m_dimline  = 1;
				m_dimlineP = ((SXFMapF_LINEC*)(annobody->m_Class));
			}
			//	PROJECTION_CURVE	//3:���@�⏕��
			else if (annobody->m_CurveKind ==3 ){
				if ( ((SXFMapF_LINEC*)(annobody->m_Class))->m_flag ==1 ){
					m_prjline1  =1;
					m_prjline1P = ((SXFMapF_LINEC*)(annobody->m_Class));
				}
				else if ( ((SXFMapF_LINEC*)(annobody->m_Class))->m_flag ==2) {
					m_prjline2  =1;
					m_prjline2P = ((SXFMapF_LINEC*)(annobody->m_Class) );
				}
				else{
					m_prjline1  =1;
					m_prjline1P = ((SXFMapF_LINEC*)(annobody->m_Class));
					
				}
			}
			else{
				//err
			}
		}
		//DIMENSION ARC
		else if(annobody->m_Type == arc_feature ){
			m_dimarc  = 1;
			m_dimarcP = ((SXFMapF_ARCC*)(annobody->m_Class ));

		}
		//LIEADER_CURVE
		else if(annobody->m_Type == polyline_feature){
			m_leader  = 1;
			m_leaderP = ((SXFMapF_POLYLINEC*)(annobody->m_Class));

		}
		//DIMTEXT
		else if(annobody->m_Type == text_string_feature){
			m_dimtext  =1;
			m_dimtextP = ((SXFMapF_TEXTSTRINGC*)(annobody->m_Class));

		}
		//ARRAW
		else if(annobody->m_Type == dimension_terminator_symbol){
			//���a���@�͖����
			//	4:RADIUS_DIMENSION///////////////////////////////////////
			if (m_DimensionKind == 4){
				if ( ((SXFMapF_TERMSYMBOLC*)(annobody->m_Class))->m_flag ==2 ){
					((SXFMapF_TERMSYMBOLC*)(annobody->m_Class))->m_flag = 1;
				}
			}
			if ( ((SXFMapF_TERMSYMBOLC*)(annobody->m_Class))->m_flag ==1 ){
				m_term1  = 1;
				m_term1P = ((SXFMapF_TERMSYMBOLC*)(annobody->m_Class));
			}
			else if ( ((SXFMapF_TERMSYMBOLC*)(annobody->m_Class))->m_flag ==2 ){
				m_term2  = 1;
				m_term2P = ((SXFMapF_TERMSYMBOLC*)(annobody->m_Class));
			}
			else{
				m_term1  = 1;
				m_term1P = ((SXFMapF_TERMSYMBOLC*)(annobody->m_Class));
			}
		}
		//CIRCLE
		else if(annobody->m_Type == circle_feature){
			m_balloon  =1;
			m_balloonP = ((SXFMapF_CIRCLEC*)(annobody->m_Class));

		}
	}

	////////////////////////////////////////////////////////////////////////////////
	// �R���e���c�����@�v�f�̃`�F�b�N
	////////////////////////////////////////////////////////////////////////////////
	// DIMENSION LINE �܂��́ADIMENSION ARC �͂��邩�H
	if ( m_dimline==0 && m_dimarc==0 && m_leader == 0 ) {
		//DRAUGHTING_CALLOUT �̍\���f�[�^�Ɉُ킪����܂��B
		return -10000;	
	}

	//	1:DIMENSION_CURVE_DIRECTED_CALLOUT�n///////////////////////////////////////
	if ( m_CalloutKind == 1 ){

		//	1:LINEAR_DIMENSION�n///////////////////////////////////////
		if (m_DimensionKind == 1){
			if ( m_ContentsNum > 6 ){
				//err
			}
		}
		//	2:ANGULAR_DIMENSION�n///////////////////////////////////////
		else if (m_DimensionKind == 2){

		}
		//	3:DIAMETER_DIMENSION�n///////////////////////////////////////
		else if (m_DimensionKind == 3){

		}
		//	4:RADIUS_DIMENSION�n///////////////////////////////////////
		else if (m_DimensionKind == 4){

		}
		//	5:CURVE_DIMENSION�n///////////////////////////////////////
		else if (m_DimensionKind == 5){

		}
	
	}
	//	2:LEADER_DIRECTED_CALLOUT�n////////////////////////////////////////////////
	else if ( m_CalloutKind == 2 ){
		if ( m_balloon == 1 ){
			m_DimensionKind = 2;
		}
		else{
			m_DimensionKind = 1;
		}
		//	1:LABEL �n///////////////////////////////////////
		if (m_DimensionKind == 1){

		}
		//	2:BALLOON �n///////////////////////////////////////
		else if (m_DimensionKind == 2){

		}

	}

	////////////////////////////////////////////////////////////////////////////////
	// �R���e���c�̗v�f����K�v�ȏ������o���B
	////////////////////////////////////////////////////////////////////////////////

	//	1:DIMENSION_CURVE_DIRECTED_CALLOUT�n///////////////////////////////////////
	if ( m_CalloutKind == 1 ){

		//	1:LINEAR_DIMENSION�n///////////////////////////////////////
		if (m_DimensionKind == 1){
			SXFMapF_LINERDIMC* linedim;
			linedim = new SXFMapF_LINERDIMC;

			linedim->m_layer = ((SXFMapF_LINEC*)m_dimlineP)->m_layer ;			//���C���R�[�h
			linedim->m_color = ((SXFMapF_LINEC*)m_dimlineP)->m_color ;			//�F�R�[�h
			linedim->m_type  = ((SXFMapF_LINEC*)m_dimlineP)->m_type ;			//����R�[�h
			linedim->m_line_width = ((SXFMapF_LINEC*)m_dimlineP)->m_line_width ;	//�����R�[�h
			
			linedim->m_sun_x1 = ((SXFMapF_LINEC*)m_dimlineP)->m_start_x ;	
			linedim->m_sun_y1 = ((SXFMapF_LINEC*)m_dimlineP)->m_start_y ;
			linedim->m_sun_x2 = ((SXFMapF_LINEC*)m_dimlineP)->m_end_x ;
			linedim->m_sun_y2 = ((SXFMapF_LINEC*)m_dimlineP)->m_end_y ;
			if ( m_prjline1 == 0 ) {   
				linedim->m_flg2 =0 ;
			}
			else {
				linedim->m_flg2 =1 ;
				linedim->m_ho1_x0 = ((SXFMapF_LINEC*)m_prjline1P)->m_org_x ;	
				linedim->m_ho1_y0 = ((SXFMapF_LINEC*)m_prjline1P)->m_org_y;
				linedim->m_ho1_x1 = ((SXFMapF_LINEC*)m_prjline1P)->m_start_x ;
				linedim->m_ho1_y1 = ((SXFMapF_LINEC*)m_prjline1P)->m_start_y ;
				linedim->m_ho1_x2 = ((SXFMapF_LINEC*)m_prjline1P)->m_end_x ;
				linedim->m_ho1_y2 = ((SXFMapF_LINEC*)m_prjline1P)->m_end_y ;
			}
			if ( m_prjline2 == 0 ) {   
				linedim->m_flg3 =0;
			}
			else{
				linedim->m_flg3 =1;
				linedim->m_ho2_x0 = ((SXFMapF_LINEC*)m_prjline2P)->m_org_x ;
				linedim->m_ho2_y0 = ((SXFMapF_LINEC*)m_prjline2P)->m_org_y ;
				linedim->m_ho2_x1 = ((SXFMapF_LINEC*)m_prjline2P)->m_start_x ;
				linedim->m_ho2_y1 = ((SXFMapF_LINEC*)m_prjline2P)->m_start_y ;
				linedim->m_ho2_x2 = ((SXFMapF_LINEC*)m_prjline2P)->m_end_x ;
				linedim->m_ho2_y2 = ((SXFMapF_LINEC*)m_prjline2P)->m_end_y ;
			}
			
			double tmvec_x1,tmvec_y1,tmvec_x2,tmvec_y2;
			tmvec_x1 =tmvec_y1 =tmvec_x2 = tmvec_y2 =0.;
			if ( m_term1 == 0 ) { 
				linedim->m_arr1_code2 = 0;
			}
			else{
				linedim->m_arr1_code2= 1 ;
				linedim->m_arr1_code1 = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_arr_code ;
				linedim->m_arr1_x = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_start_x ;
				linedim->m_arr1_y = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_start_y ;
				linedim->m_arr1_r = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_scale ;
				tmvec_x1 = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_vecter_x;
				tmvec_y1 = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_vecter_y;
			}

			if ( m_term2 == 0 ) { 
				linedim->m_arr2_code2 = 0;
			}
			else{
				linedim->m_arr2_code2=1 ;
				linedim->m_arr2_code1 = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_arr_code ;
				linedim->m_arr2_x = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_start_x ;
				linedim->m_arr2_y = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_start_y ;
				linedim->m_arr2_r = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_scale ;
				tmvec_x2 = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_vecter_x;
				tmvec_y2 = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_vecter_y;
			}

			linedim->SetArrFlag(
				m_term1, m_term2,
				linedim->m_sun_x1, linedim->m_sun_y1,	//���@���̎n�_
				linedim->m_sun_x2, linedim->m_sun_y2,	//���@���̏I�_
				tmvec_x1,	tmvec_y1,					//���P�̃x�N�g��XY
				tmvec_x2,	tmvec_y2					//���Q�̃x�N�g��XY
			);

			if ( m_dimtext != 0 ) { 
				if ( ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_str.IsEmpty() ){
					linedim->m_flg4 = 0;
				}
				else{
					linedim->m_flg4 = 1;
				}

				linedim->m_font = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_font ;

 				linedim->m_str = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_str ;   

				linedim->m_text_x = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_text_x ;
				linedim->m_text_y = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_text_y ;
				linedim->m_height = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_height ;
				linedim->m_width  = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_width ;
				linedim->m_spc    = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_spc ;
				linedim->m_angle  = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_angle ;
				linedim->m_slant  = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_slant ;
				linedim->m_b_pnt  = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_b_pnt ;
				linedim->m_direct = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_direct ;
			}
			m_Type  = linear_dim_feature;
			m_Class = linedim;
		}
		//	5:CURVE_DIMENSION�n///////////////////////////////////////
		else if (m_DimensionKind == 5){
			SXFMapF_CURVEDIMC* curvedim;
			curvedim = new SXFMapF_CURVEDIMC;

			curvedim->m_layer = ((SXFMapF_ARCC*)m_dimarcP)->m_layer ;			//���C���R�[�h
			curvedim->m_color = ((SXFMapF_ARCC*)m_dimarcP)->m_color ;			//�F�R�[�h
			curvedim->m_type  = ((SXFMapF_ARCC*)m_dimarcP)->m_type ;			//����R�[�h
			curvedim->m_line_width = ((SXFMapF_ARCC*)m_dimarcP)->m_line_width ;	//�����R�[�h

			curvedim->m_sun_x = ((SXFMapF_ARCC*)m_dimarcP)->m_center_x ;
			curvedim->m_sun_y = ((SXFMapF_ARCC*)m_dimarcP)->m_center_y ;                 
			curvedim->m_sun_radius = ((SXFMapF_ARCC*)m_dimarcP)->m_radius ;
			curvedim->m_sun_angle0 = ((SXFMapF_ARCC*)m_dimarcP)->m_start_angle ;
			curvedim->m_sun_angle1 = ((SXFMapF_ARCC*)m_dimarcP)->m_end_angle ;

			if ( m_prjline1 == 0 ) {
	    		curvedim->m_flg2=0 ;
			}
			else{
				curvedim->m_flg2=1 ;
				curvedim->m_ho1_x0 = ((SXFMapF_LINEC*)m_prjline1P)->m_org_x ;
				curvedim->m_ho1_y0 = ((SXFMapF_LINEC*)m_prjline1P)->m_org_y ;
				curvedim->m_ho1_x1 = ((SXFMapF_LINEC*)m_prjline1P)->m_start_x ;
				curvedim->m_ho1_y1 = ((SXFMapF_LINEC*)m_prjline1P)->m_start_y ;
				curvedim->m_ho1_x2 = ((SXFMapF_LINEC*)m_prjline1P)->m_end_x ;
				curvedim->m_ho1_y2 = ((SXFMapF_LINEC*)m_prjline1P)->m_end_y ;
			}

			if ( m_prjline2 == 0 ) {
				curvedim->m_flg3=0 ;
			}
			else{
				curvedim->m_flg3=1 ;
				curvedim->m_ho2_x0 = ((SXFMapF_LINEC*)m_prjline2P)->m_org_x ;
				curvedim->m_ho2_y0 = ((SXFMapF_LINEC*)m_prjline2P)->m_org_y ;
				curvedim->m_ho2_x1 = ((SXFMapF_LINEC*)m_prjline2P)->m_start_x ;
				curvedim->m_ho2_y1 = ((SXFMapF_LINEC*)m_prjline2P)->m_start_y ;
				curvedim->m_ho2_x2 = ((SXFMapF_LINEC*)m_prjline2P)->m_end_x ;
				curvedim->m_ho2_y2 = ((SXFMapF_LINEC*)m_prjline2P)->m_end_y ;
			}
			double tmvec_x1,tmvec_y1,tmvec_x2,tmvec_y2;
			tmvec_x1 =tmvec_y1 =tmvec_x2 = tmvec_y2 =0.;

			if ( m_term1 == 0 ) { 
				curvedim->m_arr1_code2 =0 ;
			}
			else{
				curvedim->m_arr1_code2 =1 ;
				curvedim->m_arr1_code1 = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_arr_code ;
				curvedim->m_arr1_x = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_start_x ;
				curvedim->m_arr1_y = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_start_y ;
				curvedim->m_arr1_r = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_scale ;
				tmvec_x1 = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_vecter_x;
				tmvec_y1 = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_vecter_y;
			}

			if ( m_term2 == 0 ) { 
				curvedim->m_arr2_code2 =0;
			}
			else{
				curvedim->m_arr2_code1 = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_arr_code ;
				curvedim->m_arr2_x = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_start_x ;
				curvedim->m_arr2_y = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_start_y ;
				curvedim->m_arr2_r = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_scale ;
				tmvec_x2 = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_vecter_x;
				tmvec_y2 = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_vecter_y;
			}
			curvedim->SetArrFlag(
				m_term1, m_term2,
				curvedim->m_sun_x, curvedim->m_sun_y,	//���@���̌��_�i���S�j
				curvedim->m_arr1_x,	//���P�z�u�_X
				curvedim->m_arr1_y,	//���P�z�u�_Y
				curvedim->m_arr2_x,	//���Q�z�u�_X
				curvedim->m_arr2_y,	//���Q�z�u�_Y				
				tmvec_x1,	tmvec_y1,					//���P�̃x�N�g��XY
				tmvec_x2,	tmvec_y2					//���Q�̃x�N�g��XY
			);

			if ( m_dimtext != 0 ) { 
				if ( ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_str.IsEmpty()){
					curvedim->m_flg4 = 0;
				}
				else{
					curvedim->m_flg4 = 1;
				}
				curvedim->m_font = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_font ;

				curvedim->m_str = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_str ;

				curvedim->m_text_x = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_text_x ;
				curvedim->m_text_y = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_text_y ;
				curvedim->m_height = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_height ;
				curvedim->m_width = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_width ;
				curvedim->m_spc = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_spc ;
				curvedim->m_angle = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_angle ;
				curvedim->m_slant = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_slant ;
				curvedim->m_b_pnt = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_b_pnt ;
				curvedim->m_direct = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_direct ;
			}

			m_Type  = curve_dim_feature;
			m_Class = curvedim;

		}
		//	2:ANGULAR_DIMENSION�n///////////////////////////////////////
		else if (m_DimensionKind == 2){
			SXFMapF_ANGULARDIMC* angledim;
			angledim = new SXFMapF_ANGULARDIMC;

			angledim->m_layer = ((SXFMapF_ARCC*)m_dimarcP)->m_layer ;			//���C���R�[�h
			angledim->m_color = ((SXFMapF_ARCC*)m_dimarcP)->m_color ;			//�F�R�[�h
			angledim->m_type  = ((SXFMapF_ARCC*)m_dimarcP)->m_type ;			//����R�[�h
			angledim->m_line_width = ((SXFMapF_ARCC*)m_dimarcP)->m_line_width ;	//�����R�[�h

			angledim->m_sun_x = ((SXFMapF_ARCC*)m_dimarcP)->m_center_x ;
			angledim->m_sun_y = ((SXFMapF_ARCC*)m_dimarcP)->m_center_y ;                 
			angledim->m_sun_radius = ((SXFMapF_ARCC*)m_dimarcP)->m_radius ;
			angledim->m_sun_angle0 = ((SXFMapF_ARCC*)m_dimarcP)->m_start_angle ;
			angledim->m_sun_angle1 = ((SXFMapF_ARCC*)m_dimarcP)->m_end_angle ;

			if ( m_prjline1 == 0 ) {
	    		angledim->m_flg2=0 ;
			}
			else{
				angledim->m_flg2=1 ;
				angledim->m_ho1_x0 = ((SXFMapF_LINEC*)m_prjline1P)->m_org_x ;
				angledim->m_ho1_y0 = ((SXFMapF_LINEC*)m_prjline1P)->m_org_y ;
				angledim->m_ho1_x1 = ((SXFMapF_LINEC*)m_prjline1P)->m_start_x ;
				angledim->m_ho1_y1 = ((SXFMapF_LINEC*)m_prjline1P)->m_start_y ;
				angledim->m_ho1_x2 = ((SXFMapF_LINEC*)m_prjline1P)->m_end_x ;
				angledim->m_ho1_y2 = ((SXFMapF_LINEC*)m_prjline1P)->m_end_y ;
			}

			if ( m_prjline2 == 0 ) {
				angledim->m_flg3=0 ;
			}
			else{
				angledim->m_flg3=1 ;
				angledim->m_ho2_x0 = ((SXFMapF_LINEC*)m_prjline2P)->m_org_x ;
				angledim->m_ho2_y0 = ((SXFMapF_LINEC*)m_prjline2P)->m_org_y ;
				angledim->m_ho2_x1 = ((SXFMapF_LINEC*)m_prjline2P)->m_start_x ;
				angledim->m_ho2_y1 = ((SXFMapF_LINEC*)m_prjline2P)->m_start_y ;
				angledim->m_ho2_x2 = ((SXFMapF_LINEC*)m_prjline2P)->m_end_x ;
				angledim->m_ho2_y2 = ((SXFMapF_LINEC*)m_prjline2P)->m_end_y ;
			}
			double tmvec_x1,tmvec_y1,tmvec_x2,tmvec_y2;
			tmvec_x1 =tmvec_y1 =tmvec_x2 = tmvec_y2 =0.;

			if ( m_term1 == 0 ) { 
				angledim->m_arr1_code2 =0 ;
			}
			else{
				angledim->m_arr1_code2 =1 ;
				angledim->m_arr1_code1 = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_arr_code ;
				angledim->m_arr1_x = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_start_x ;
				angledim->m_arr1_y = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_start_y ;
				angledim->m_arr1_r = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_scale ;
				tmvec_x1 = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_vecter_x;
				tmvec_y1 = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_vecter_y;
			}

			if ( m_term2 == 0 ) { 
				angledim->m_arr2_code2 =0;
			}
			else{
				angledim->m_arr2_code1 = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_arr_code ;
				angledim->m_arr2_x = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_start_x ;
				angledim->m_arr2_y = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_start_y ;
				angledim->m_arr2_r = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_scale ;
				tmvec_x2 = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_vecter_x;
				tmvec_y2 = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_vecter_y;
			}
			angledim->SetArrFlag(
				m_term1, m_term2,
				angledim->m_sun_x, angledim->m_sun_y,	//���@���̌��_�i���S�j
				angledim->m_arr1_x,	//���P�z�u�_X
				angledim->m_arr1_y,	//���P�z�u�_Y
				angledim->m_arr2_x,	//���Q�z�u�_X
				angledim->m_arr2_y,	//���Q�z�u�_Y				
				tmvec_x1,	tmvec_y1,					//���P�̃x�N�g��XY
				tmvec_x2,	tmvec_y2					//���Q�̃x�N�g��XY
			);

			if ( m_dimtext != 0 ) { 
				if ( ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_str.IsEmpty()){
					angledim->m_flg4 = 0;
				}
				else{
					angledim->m_flg4 = 1;
				}
				angledim->m_font = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_font ;

				angledim->m_str = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_str ;

				angledim->m_text_x = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_text_x ;
				angledim->m_text_y = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_text_y ;
				angledim->m_height = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_height ;
				angledim->m_width = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_width ;
				angledim->m_spc = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_spc ;
				angledim->m_angle = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_angle ;
				angledim->m_slant = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_slant ;
				angledim->m_b_pnt = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_b_pnt ;
				angledim->m_direct = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_direct ;
			}

			m_Type  = angular_dim_feature;
			m_Class = angledim;

		}
		//	3:DIAMETER_DIMENSION�n///////////////////////////////////////
		else if (m_DimensionKind == 3){

			SXFMapF_DIMETERDIMC* dimeterdim;
			dimeterdim = new SXFMapF_DIMETERDIMC;	

			dimeterdim->m_layer = ((SXFMapF_LINEC*)m_dimlineP)->m_layer ;		//���C���R�[�h
			dimeterdim->m_color = ((SXFMapF_LINEC*)m_dimlineP)->m_color ;		//�F�R�[�h
			dimeterdim->m_type = ((SXFMapF_LINEC*)m_dimlineP)->m_type ;			//����R�[�h
			dimeterdim->m_line_width = ((SXFMapF_LINEC*)m_dimlineP)->m_line_width ;	//�����R�[�h

			dimeterdim->m_sun_x1 = ((SXFMapF_LINEC*)m_dimlineP)->m_start_x ;
			dimeterdim->m_sun_y1 = ((SXFMapF_LINEC*)m_dimlineP)->m_start_y ;
			dimeterdim->m_sun_x2 = ((SXFMapF_LINEC*)m_dimlineP)->m_end_x ;
			dimeterdim->m_sun_y2 = ((SXFMapF_LINEC*)m_dimlineP)->m_end_y ;

			double tmvec_x1,tmvec_y1,tmvec_x2,tmvec_y2;
			tmvec_x1 =tmvec_y1 =tmvec_x2 = tmvec_y2 =0.;
			if ( m_term1 == 0 ) { 
				dimeterdim->m_arr1_code2=0 ;
			}
			else{
				dimeterdim->m_arr1_code2=1 ;
				dimeterdim->m_arr1_code1 = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_arr_code ;
				dimeterdim->m_arr1_x = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_start_x ;
				dimeterdim->m_arr1_y = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_start_y ;
				dimeterdim->m_arr1_r = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_scale ;
				tmvec_x1 = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_vecter_x;
				tmvec_y1 = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_vecter_y;
			}
			if ( m_term2 == 0 ) { 
				dimeterdim->m_arr2_code2 = 0 ;
			}
			else{
				dimeterdim->m_arr2_code2 = 1 ;
				dimeterdim->m_arr2_code1 = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_arr_code ;
				dimeterdim->m_arr2_x = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_start_x ;
				dimeterdim->m_arr2_y = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_start_y ;
				dimeterdim->m_arr2_r = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_scale ;
				tmvec_x2 = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_vecter_x;
				tmvec_y2 = ((SXFMapF_TERMSYMBOLC*)m_term2P)->m_vecter_y;
			}
			
			dimeterdim->SetArrFlag(
				m_term1, m_term2,
				dimeterdim->m_sun_x1, dimeterdim->m_sun_y1,	//���@���̎n�_
				dimeterdim->m_sun_x2, dimeterdim->m_sun_y2,	//���@���̏I�_
				tmvec_x1,	tmvec_y1,					//���P�̃x�N�g��XY
				tmvec_x2,	tmvec_y2					//���Q�̃x�N�g��XY
			);

			if ( m_dimtext != 0 ) { 
				if ( ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_str.IsEmpty()){
					dimeterdim->m_flg = 0;
				}
				else{
					dimeterdim->m_flg = 1;
				}
				dimeterdim->m_font = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_font ;

				dimeterdim->m_str = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_str ;

				dimeterdim->m_text_x = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_text_x ;
				dimeterdim->m_text_y = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_text_y ;
				dimeterdim->m_height = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_height ;
				dimeterdim->m_width = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_width ;
				dimeterdim->m_spc = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_spc ;
				dimeterdim->m_angle = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_angle ;
				dimeterdim->m_slant = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_slant ;
				dimeterdim->m_b_pnt = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_b_pnt ;
				dimeterdim->m_direct = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_direct ;
			}
			m_Type  = diameter_dim_feature;
			m_Class = dimeterdim;
		}
		//	4:RADIUS_DIMENSION�n///////////////////////////////////////
		else if (m_DimensionKind == 4){
			SXFMapF_RADIUSDIMC* radiusdim;
			radiusdim = new SXFMapF_RADIUSDIMC;

			radiusdim->m_layer = ((SXFMapF_LINEC*)m_dimlineP)->m_layer ;		//���C���R�[�h
			radiusdim->m_color = ((SXFMapF_LINEC*)m_dimlineP)->m_color ;		//�F�R�[�h
			radiusdim->m_type = ((SXFMapF_LINEC*)m_dimlineP)->m_type ;			//����R�[�h
			radiusdim->m_line_width = ((SXFMapF_LINEC*)m_dimlineP)->m_line_width ;	//�����R�[�h

			radiusdim->m_sun_x1 = ((SXFMapF_LINEC*)m_dimlineP)->m_start_x ;
			radiusdim->m_sun_y1 = ((SXFMapF_LINEC*)m_dimlineP)->m_start_y ;
			radiusdim->m_sun_x2 = ((SXFMapF_LINEC*)m_dimlineP)->m_end_x ;
			radiusdim->m_sun_y2 = ((SXFMapF_LINEC*)m_dimlineP)->m_end_y ;

			double tmvec_x,tmvec_y;
			tmvec_x =tmvec_y =0.;
			if ( m_term1 == 0 ) { 
				radiusdim->m_arr_code2 = 0 ;
			}
			else{
				radiusdim->m_arr_code2 = 1 ;
				radiusdim->m_arr_code1 = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_arr_code ;
				radiusdim->m_arr_x = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_start_x ;
				radiusdim->m_arr_y = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_start_y ;
				radiusdim->m_arr_r = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_scale ;
				tmvec_x = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_vecter_x;
				tmvec_y = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_vecter_y;
			}

			radiusdim->SetArrFlag(
				m_term1, 	//���̗L�薳���t���O
				radiusdim->m_sun_x1, radiusdim->m_sun_y1,	//���@���̎n�_
				radiusdim->m_sun_x2, radiusdim->m_sun_y2,	//���@���̏I�_
				tmvec_x,	tmvec_y								//���P�̃x�N�g��XY
			);

			if ( m_dimtext != 0 ) { 
				if ( ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_str.IsEmpty()){
					radiusdim->m_flg = 0;
				}
				else{
					radiusdim->m_flg = 1;
				}
				radiusdim->m_font = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_font ;

				radiusdim->m_str = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_str ;

				radiusdim->m_text_x = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_text_x ;
				radiusdim->m_text_y = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_text_y ;
				radiusdim->m_height = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_height ;
				radiusdim->m_width = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_width ;
				radiusdim->m_spc = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_spc ;
				radiusdim->m_angle = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_angle ;
				radiusdim->m_slant = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_slant ;
				radiusdim->m_b_pnt = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_b_pnt ;
				radiusdim->m_direct = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_direct ;
			}
			m_Type  = radius_dim_feature;
			m_Class = radiusdim;
		}
	}
	//	2:LEADER_DIRECTED_CALLOUT�n////////////////////////////////////////////////
	else if ( m_CalloutKind == 2 ){
		
		//	1:LABEL �n///////////////////////////////////////
		if (m_DimensionKind == 1){
			SXFMapF_LABELC* label;
			label = new SXFMapF_LABELC;

			label->m_layer = ((SXFMapF_POLYLINEC*)m_leaderP)->m_layer ;		//���C���R�[�h
			label->m_color = ((SXFMapF_POLYLINEC*)m_leaderP)->m_color ;		//�F�R�[�h
			label->m_type = ((SXFMapF_POLYLINEC*)m_leaderP)->m_type ;			//����R�[�h
			label->m_line_width = ((SXFMapF_POLYLINEC*)m_leaderP)->m_line_width ;	//�����R�[�h

    		label->m_vertex_number = ((SXFMapF_POLYLINEC*)m_leaderP)->m_number ;
			label->m_vertex_x.Copy( ((SXFMapF_POLYLINEC*)m_leaderP)->m_x );
			label->m_vertex_y.Copy( ((SXFMapF_POLYLINEC*)m_leaderP)->m_y );

			if ( m_term1 == 1 ) { 
				//	�܂���̓���ւ�������
				label->SetVertex(
				((SXFMapF_TERMSYMBOLC*)m_term1P)->m_start_x,
				((SXFMapF_TERMSYMBOLC*)m_term1P)->m_start_y,
				((SXFMapF_POLYLINEC*)m_leaderP)->m_number,
				((SXFMapF_POLYLINEC*)m_leaderP)->m_x,
				((SXFMapF_POLYLINEC*)m_leaderP)->m_y	);

				label->m_arr_code = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_arr_code ;
				label->m_arr_r = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_scale ;
			}
			if ( m_dimtext != 0 ) { 
				if ( ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_str.IsEmpty()) {
					label->m_flg = 0;
				}
				else{
					label->m_flg = 1;
				}
				label->m_font = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_font ;
				label->m_str = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_str ;
	    		label->m_text_x = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_text_x ;
				label->m_text_y = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_text_y ;
				label->m_height = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_height ;
				label->m_width = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_width ;
				label->m_spc = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_spc ;
				label->m_angle = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_angle ;
				label->m_slant = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_slant ;
				label->m_b_pnt = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_b_pnt ;
				label->m_direct = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_direct ;
			}

			m_Type  = label_feature;
			m_Class = label;

		}
		//	2:BALLOON �n///////////////////////////////////////
		else if (m_DimensionKind == 2){
			SXFMapF_BALLOONC* balloon;
			balloon = new SXFMapF_BALLOONC;

			balloon->m_layer = ((SXFMapF_POLYLINEC*)m_leaderP)->m_layer ;		//���C���R�[�h
			balloon->m_color = ((SXFMapF_POLYLINEC*)m_leaderP)->m_color ;		//�F�R�[�h
			balloon->m_type = ((SXFMapF_POLYLINEC*)m_leaderP)->m_type ;		//����R�[�h
			balloon->m_line_width = ((SXFMapF_POLYLINEC*)m_leaderP)->m_line_width ;	//�����R�[�h

			balloon->m_vertex_number = ((SXFMapF_POLYLINEC*)m_leaderP)->m_number ;

			balloon->m_vertex_x.Copy( ((SXFMapF_POLYLINEC*)m_leaderP)->m_x );
			balloon->m_vertex_y.Copy( ((SXFMapF_POLYLINEC*)m_leaderP)->m_y );

			balloon->m_center_x = ((SXFMapF_CIRCLEC*)m_balloonP)->m_center_x ;
			balloon->m_center_y = ((SXFMapF_CIRCLEC*)m_balloonP)->m_center_y ;
			balloon->m_radius = ((SXFMapF_CIRCLEC*)m_balloonP)->m_radius ;

			if ( m_term1 == 1 ) { 
				//	�܂���̓���ւ�������
				balloon->SetVertex(
				((SXFMapF_TERMSYMBOLC*)m_term1P)->m_start_x,
				((SXFMapF_TERMSYMBOLC*)m_term1P)->m_start_y,
				((SXFMapF_POLYLINEC*)m_leaderP)->m_number,
				((SXFMapF_POLYLINEC*)m_leaderP)->m_x,
				((SXFMapF_POLYLINEC*)m_leaderP)->m_y	);
				balloon->m_arr_code = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_arr_code ;
				balloon->m_arr_r = ((SXFMapF_TERMSYMBOLC*)m_term1P)->m_scale ;
			}

			if ( m_dimtext != 0 ) { 
				if ( ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_str.IsEmpty() ){
					balloon->m_flg = 0;
				}
				else{
					balloon->m_flg = 1;
				}

				balloon->m_font = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_font ;
				balloon->m_str = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_str ;
	    		balloon->m_text_x = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_text_x ;
				balloon->m_text_y = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_text_y ;
				balloon->m_height = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_height ;
				balloon->m_width = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_width ;
				balloon->m_spc = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_spc ;
				balloon->m_angle = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_angle ;
				balloon->m_slant = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_slant ;
				balloon->m_b_pnt = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_b_pnt ;
				balloon->m_direct = ((SXFMapF_TEXTSTRINGC*)m_dimtextP)->m_direct ;
			}
			m_Type  = balloon_feature;
			m_Class = balloon;
		}
	}

	return 0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapCalloutBodyC.cpp						�쐬���F2000.04.21

	�P�D�@�\�T�v
		Body�̎�ʔ���

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapCalloutBodyC::CheckBodyKind()
					

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.21	
**/

int SXFMapCalloutBodyC::CheckBodyKind()
{

//< DRAUGHTING_CALLOUT�n >/////////////////////////////////////
	m_CalloutKind =0;
//		0:�s��
//		1:DIMENSION_CURVE_DIRECTED_CALLOUT
//		2:LEADER_DIRECTED_CALLOUT
//

//< DIMENSION�n >/////////////////////////////////////
	m_DimensionKind =0;
//		0:NONDIMENSION
//		1:LINEAR_DIMENSION
//		2:ANGULAR_DIMENSION
//		3:DIAMETER_DIMENSION
//		4:RADIUS_DIMENSION
//		5:CURVE_DIMENSION

//< LEADER�n >/////////////////////////////////////
	m_LavelKind =0;
//		0:NONLEADER
//		1:LABEL
//		2:BALLOON


//	<�e�ʂ̔���>


	//�v�f�̃`�F�b�N
	if (m_EntityData.Find(DEF_REPRESENTATION_ITEM) == -1){
		//err
	}
	if (m_EntityData.Find(DEF_GEOMETRIC_REPRESENTATION_ITEM) == -1){
		//err
	}
	if (m_EntityData.Find(DEF_DRAUGHTING_ELEMENTS) == -1){
		//err
	}

	//<DRAUGHTING_CALLOUT�̔���>
	//<���@���n>
	if (m_EntityData.Find(DEF_DIMENSION_CURVE_DIRECTED_CALLOUT) != -1){
		m_CalloutKind = 1;

		// �������@ ////////////////////////////////////////////////////////
		if (m_EntityData.Find(DEF_LINEAR_DIMENSION) != -1){
			m_DimensionKind =1;
		}
		// �ʒ����@ ////////////////////////////////////////////////////////
		else if (m_EntityData.Find(DEF_CURVE_DIMENSION) != -1){
			m_DimensionKind =5;
		}
		// �p�x���@ ////////////////////////////////////////////////////////
		else if (m_EntityData.Find(DEF_ANGULAR_DIMENSION) != -1){
			m_DimensionKind =2;
		}
		// ���a���@ ////////////////////////////////////////////////////////
		else if (m_EntityData.Find(DEF_DIAMETER_DIMENSION) != -1){
			m_DimensionKind =3;
		}
		// ���a���@ ////////////////////////////////////////////////////////
		else if (m_EntityData.Find(DEF_RADIUS_DIMENSION) != -1){
			m_DimensionKind =4;
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
	
	//<���o���n>
	else if (m_EntityData.Find(DEF_LEADER_DIRECTED_CALLOUT) != -1){
		m_CalloutKind = 2;
		
	}
	else {
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
