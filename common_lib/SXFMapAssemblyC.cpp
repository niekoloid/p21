/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapAssemblyC.cpp						�쐬���F2001.06.21

	�P�D�N���X�T�v
		AP202�G���e�B�e�B����t�B�[�`���ւ̃}�b�s���O���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2001.06.21	

**/
#include "stdafx.h"
#include "SXFTableManagerC.h"
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFMapF_CurveStyleBaseC.h"
#include "SXFF_FeatureTypeE.h"
#include "SXFMapE_DRAWING_SHEET_REVISION_USAGEC.h" 
#include "SXFMapE_SYMBOL_REPRESENTATION_MAPC.h" 
#include "SXFMapE_COMPOSITE_CURVEC.h" 
#include "SXFMapE_DRAUGHTING_SUBFIGURE_REPRESENTATIONC.h" 
#include "SXFMapE_PLANAR_BOXC.h"
#include "SXFMapE_STYLED_ITEMC.h"
#include "SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC.h"
#include "SXFMapE_CURVE_STYLEC.h"
#include "SXFMapF_SHEETC.h" 
#include "SXFMapF_SFIGORGC.h" 
#include "SXFMapF_COMPOSITEC.h" 
#include "SXFMapAssemblyC.h"
#include "SXFMapEntAConvC.h"
#include "SXFMapEntCConvC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
	
/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapAssemblyC.cpp						�쐬���F2001.06.21

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapAssemblyC::SXFMapAssemblyC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2001.06.21	
**/
SXFMapAssemblyC::SXFMapAssemblyC()
{
//
//	<������>
//
//	<BODY���> ///////////////////////////////////////////////////////
	m_AsmKind=0 ;
//		0:�s��
//		1:DRAWING_SHEET_REVISION_USAGE
//		2:DRAUGHTING_CALLOUT
//		3:COMPOSITE_CURVE

//	<SXFTableManagerC�ւ̃|�C���^>
	m_TableManager=NULL;
	m_ComInfoC=NULL;

//	<�A�Z���u���v�f�̃G���e�B�e�B�ւ̃|�C���^>
	m_AssmP = NULL ;
//	<�t�B�[�`���^�C�v>
	m_Type  = NONFEATURE;
//	<�t�B�[�`���N���X�ւ̃|�C���^>
	m_Class = NULL;
//	<�t�B�[�`����>
//  char m_TypeName[30];
//	<�t�B�[�`���\���̂ւ̃|�C���^>
	m_StructData = NULL;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapAssemblyC.cpp						�쐬���F2001.06.21

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapAssemblyC::SXFMapAssemblyC(
					SXFInstanceIDC* IN_InstanceIDManeger, 
					SXFTableManagerC* IN_TableManager,
					SXFComInfoC* IN_ComInfoC )
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

	�����F	�^					������					���e
			SXFInstanceIDC* 	IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��
			SXFTableManagerC* 	IN_TableManager			��`ð��يǗ���޼ު��
			SXFComInfoC*		IN_ComInfoC				���ʏ��Ǘ���޼ު��		

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2001.06.21	
**/
//	<�C���X�^���X�h�c�ւ̃|�C���^��o�^����������>
SXFMapAssemblyC::SXFMapAssemblyC(
		SXFInstanceIDC* IN_InstanceIDManeger, 
		SXFTableManagerC* IN_TableManager,
		SXFComInfoC* IN_ComInfoC )
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
//	<BODY���> ///////////////////////////////////////////////////////
	m_AsmKind=0 ;
//		0:�s��
//		1:DRAWING_SHEET_REVISION_USAGE
//		2:DRAUGHTING_CALLOUT
//		3:COMPOSITE_CURVE

//	<SXFTableManagerC�ւ̃|�C���^>
	m_TableManager=IN_TableManager;
//	<SXFComInfoC�ւ̃|�C���^>
	m_ComInfoC = IN_ComInfoC;

//	<�A�Z���u���v�f�̃G���e�B�e�B�ւ̃|�C���^>
	m_AssmP = NULL ;
//	<�t�B�[�`���^�C�v>
	m_Type = NONFEATURE;
//	<�t�B�[�`���N���X�ւ̃|�C���^>
	m_Class = NULL;
//	<�t�B�[�`����>
//  char m_TypeName[30];
//	<�t�B�[�`���\���̂ւ̃|�C���^>
	m_StructData = NULL;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapAssemblyC.cpp						�쐬���F2001.06.21

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapAssemblyC::~SXFMapAssemblyC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2001.06.21	
**/
SXFMapAssemblyC::~SXFMapAssemblyC()
{
	if (m_Class !=NULL ){
		if (m_Type == drawing_sheet_feature)
			delete (SXFMapF_SHEETC*)m_Class;
		if (m_Type == sfig_org_feature)
			delete (SXFMapF_SFIGORGC*)m_Class;
		if (m_Type == composite_curve_org_feature)
			delete (SXFMapF_COMPOSITEC*)m_Class;
	}
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapAssemblyC.cpp						�쐬���F2001.06.21

	�P�D�@�\�T�v
		��ʗv�f�t�B�[�`���\���̂̍쐬

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapAssemblyC::SetFeatureParameter(
					int		OUT_type,
					void*	OUT_Class)


	����  �F	�^			������				���e
				int		OUT_type,	//�A�Z���u�����
									1:�p��
									2:�����}�`
									3:�����Ȑ�
				void*	OUT_Class)	//�t�B�[�`���N���X�ւ̃|�C���^


	���A�l�F��`�e�[�u�����

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2001.06.21	
**/
int	SXFMapAssemblyC::	SetFeatureParameter(
					int		&OUT_Type,	//�A�Z���u�����	
					LPVOID	&OUT_Class)	//�t�B�[�`���N���X�ւ̃|�C���^

{
//
//	<������>
//
//	DEL(S)	�`���[�j���O�Ή�	K.Naono	03.07.10
/*
	CStringArray type,orient;
	//�p���T�C�Y���
	CString a0("A0");
	CString a1("A1");
	CString a2("A2");
	CString a3("A3");
	CString a4("A4");
	type.Add((LPCTSTR)a0);
	type.Add((LPCTSTR)a1);
	type.Add((LPCTSTR)a2);
	type.Add((LPCTSTR)a3);
	type.Add((LPCTSTR)a4);
	//�c/���敪
	CString a10(DEF_vertical);
	CString a11(DEF_horizontal);
	orient.Add((LPCTSTR)a10);
	orient.Add((LPCTSTR)a11);
	CString BodyData, BodyName;
*/
//	DEL(E)	�`���[�j���O�Ή�	K.Naono	03.07.10
	//�e�ʂ̎�ʔ���Ɛe�ʂɍ��킹��BODY�N���X�쐬

//	<BODY���> ///////////////////////////////////////////////////////
	m_AsmKind=0 ;
//		0:�s��
//		1:DRAWING_SHEET_REVISION_USAGE
//		2:DRAUGHTING_CALLOUT
//		3:COMPOSITE_CURVE

// #1400 = DRAWING_SHEET_REVISION_USAGE(#1412, #1402, '01');
// #1040 = SYMBOL_REPRESENTATION_MAP(#1046, #1047);
// #1121 = COMPOSITE_CURVE('composite_curve3', (#1100), .F.);

//	<Body�̔���>

//	�p�� ///////////////////////////////////////////////////////// 
	if (m_EntityName == DEF_DRAWING_SHEET_REVISION_USAGE) {
//	ADD(S)	�`���[�j���O�Ή�	K.Naono	03.07.10
		CStringArray	type, orient;
		type.Add(DEF_A0) ;
		type.Add(DEF_A1) ;
		type.Add(DEF_A2) ;
		type.Add(DEF_A3) ;
		type.Add(DEF_A4) ;
		//�c/���敪
		orient.Add(DEF_vertical) ;
		orient.Add(DEF_horizontal) ;
//	ADD(E)	�`���[�j���O�Ή�	K.Naono	03.07.10

	/** drawing_sheet **/
/*		#1409 = CARTESIAN_POINT('cartesian_point168', (0., 0.));
		#1410 = AXIS2_PLACEMENT_2D('axis2_placement_2d54', #1409, $);
		#1411 = PLANAR_BOX('planar_box1', 594., 840., #1410);
		#1412 = DRAWING_SHEET_REVISION('A1_vertical', (#1060, #1080, #1120, #1180, #1200, #1220, #1260, #1280, #1320, #1340, #1380, #1411), #1408, 'revision_identifier01');
		#1400 = DRAWING_SHEET_REVISION_USAGE(#1412, #1402, '01');
		#1413 = PRESENTATION_SIZE(#1412, #1411);*/

		m_AsmKind = 1;

		SXFMapE_DRAWING_SHEET_REVISION_USAGEC m_AssmP(m_InstanceIDManager);
		m_AssmP.SetRootID(m_RootID);
		m_AssmP.SetParameter();

		SXFMapF_SHEETC* sheet;
		sheet = new SXFMapF_SHEETC;
		m_TableManager->GetSheetTitle(m_AssmP.m_InSet_Inst,sheet->m_name);

//	ADD(S)	Ver3.0�Ή�	K.Naono	04.01.30
		//	DRAUGHTING_DRAWING_REVISION�̃C���X�^���XID��o�^
		m_TableManager->SetDraughtingDrawingRevID(m_AssmP.m_InSet_Inst) ;
//	ADD(E)	Ver3.0�Ή�	K.Naono	04.01.30

		// �c���t���O ,�p���T�C�Y �̐ݒ� ////////////////////////////
		sheet->m_int_x	= 0;
		sheet->m_int_y	= 0;

		sheet->m_type = -1;
//		for(int i=0;i<=4;i++){
		for(int i = 0;i < type.GetSize(); i++) {
			if(m_AssmP.m_Area_p->m_Name.Find(type[i]) != -1) {
				sheet->m_type	= i ;
				sheet->m_int_x	= 0 ;
				sheet->m_int_y	= 0 ;
				break;
			}
			if ( m_AssmP.m_Area_p->m_Name.Find(DEF_FREE) != -1) {
				sheet->m_type	= 9 ;
				break;
			}
		}
		sheet->m_orient = -1;
		if (sheet->m_type != 9) {
//			for(int i=0;i<=1;i++){
			for(int i = 0; i < orient.GetSize(); i++) {
				if( m_AssmP.m_Area_p->m_Name.Find(orient[i]) != -1) {
					sheet->m_orient = i ;
					break;
				}
			}
		}
		
		int PlanarBoxID = m_TableManager->GetPlanarBoxID(m_AssmP.m_Area_Inst);
		CStringArray tmparray;
		
		SXFMapE_PLANAR_BOXC planar(m_InstanceIDManager);
		planar.SetRootID(PlanarBoxID);
		planar.SetEntity();
		planar.SetParameter();

		switch(sheet->m_type){
		case 0:
			sheet->m_int_x = DEF_A0_SIZE_X ;
			sheet->m_int_y = DEF_A0_SIZE_Y ;
			break;
		case 1:
			sheet->m_int_x = DEF_A1_SIZE_X ;
			sheet->m_int_y = DEF_A1_SIZE_Y ;
			break;
		case 2:
			sheet->m_int_x = DEF_A2_SIZE_X ;
			sheet->m_int_y = DEF_A2_SIZE_Y ;
			break;
		case 3:
			sheet->m_int_x = DEF_A3_SIZE_X ;
			sheet->m_int_y = DEF_A3_SIZE_Y ;
			break;
		case 4:
			sheet->m_int_x = DEF_A4_SIZE_X ;
			sheet->m_int_y = DEF_A4_SIZE_Y ;
			break;
		case 9:
			sheet->m_int_x = (int)planar.m_Size_x ;
			sheet->m_int_y = (int)planar.m_Size_y ;
			break;
		default:
			break;
		}
		
		// �p���T�C�Y��ʂ��O�`�S�Ȃ�΁A
		//PLANAR_BOX����Ǎ��񂾒l���p���T�C�Y�ƈقȂ�΃G���[���o�͂���B
		//�A���O��OK
		if ( sheet->m_type >= 0 && sheet->m_type <= 4) {
			if (sheet->m_orient == 1 ){
				if ( (int)planar.m_Size_x != sheet->m_int_x && (int)planar.m_Size_x != 0 ) {
					SXFErrorMsgC::RecordError(
						SXFSHEETLENGTHWARNING,		//err���b�Z�[�W�ԍ�
						m_EntityName,				//�G���e�B�e�B��
						1,							//�p�����^�̌�
						(int)planar.m_Size_x		//�p�����^
						);
				}
				if ( (int)planar.m_Size_y != sheet->m_int_y && (int)planar.m_Size_y != 0 ) {
					SXFErrorMsgC::RecordError(
						SXFSHEETLENGTHWARNING,		//err���b�Z�[�W�ԍ�
						m_EntityName,				//�G���e�B�e�B��
						1,							//�p�����^�̌�
						(int)planar.m_Size_y		//�p�����^
						);
				}
			}
			else{
				if ( (int)planar.m_Size_y != sheet->m_int_x && (int)planar.m_Size_y != 0 ) {
					SXFErrorMsgC::RecordError(
						SXFSHEETLENGTHWARNING,		//err���b�Z�[�W�ԍ�
						m_EntityName,				//�G���e�B�e�B��
						1,							//�p�����^�̌�
						(int)planar.m_Size_y		//�p�����^
						);
				}
				if ( (int)planar.m_Size_x != sheet->m_int_y && (int)planar.m_Size_x != 0 ) {
					SXFErrorMsgC::RecordError(
						SXFSHEETLENGTHWARNING,		//err���b�Z�[�W�ԍ�
						m_EntityName,				//�G���e�B�e�B��
						1,							//�p�����^�̌�
						(int)planar.m_Size_x		//�p�����^
						);
				}
			}
		}
		
		// �p���̕�����v�f�Q�ւ̃C���X�^���X�h�c
		m_Type  = drawing_sheet_feature;
		m_Class = sheet;
	}
	//	�����}�` ///////////////////////////////////////////////////// 
	else if ( m_EntityName == DEF_SYMBOL_REPRESENTATION_MAP ){

		m_AsmKind = 2;

		SXFMapE_SYMBOL_REPRESENTATION_MAPC m_AssmP(m_InstanceIDManager);
		m_AssmP.SetRootID(m_RootID);
		m_AssmP.SetParameter();

		SXFMapF_SFIGORGC* sfigorg;
		sfigorg = new SXFMapF_SFIGORGC;

		/*sfigorg->m_flag,sfigorg->m_name �̐ݒ�*/
		sfigorg->SetSubName(m_AssmP.m_subfig_rep_P->m_Name);

		m_Type  = sfig_org_feature;
		m_Class = sfigorg;

	}
	//	�����Ȑ�  ///////////////////////////////////////////////////// 
	else if ( m_EntityName == DEF_COMPOSITE_CURVE){
		int CurveID = 0;
		m_AsmKind = 3;

		SXFMapE_COMPOSITE_CURVEC m_AssmP(m_InstanceIDManager);
		m_AssmP.SetRootID(m_RootID);
		m_AssmP.SetParameter();

		SXFMapF_COMPOSITEC* composite;
		composite = new SXFMapF_COMPOSITEC;

		////////////////////////////////////////////////////////////////////////////////
		//  ��������ID�擾   ////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.10
//		CArray<int,int>* IDarray;
		CList<int,int>* IDarray;
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.10
		CString IN_InstanceName;
		int AppeID;

		// STYLED_ITEM�̂h�c�擾
		IN_InstanceName = DEF_SXF_COMPLEX_INSTANCE;
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.10
/*
		if ( GetIDArray(IN_InstanceName) == NULL ) {
			return -10000;
		}
		else{
			IDarray = GetIDArray(IN_InstanceName); 
		}
		for (int i=0;i<(IDarray->GetSize());i++){
*/
		IDarray = GetIDArray(IN_InstanceName) ;
		if( IDarray == NULL ) {
			return -10000 ;
		}
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.10
		for(POSITION pos = IDarray->GetHeadPosition(); pos; ) {
			// SXF_COMPLEX_INSTANCE��STYLED_ITEM�̂h�c�擾
			// STYLED_ITEM���Q�Ƃ��Ă���C���X�^���X���`�F�b�N
			SXFMapEntityBaseC body(m_InstanceIDManager);
//			body.SetRootID((*IDarray)[i]);
			body.SetRootID(IDarray->GetNext(pos));
			body.SetEntity();
			
			if ( (body.m_EntityData).Find( DEF_STYLED_ITEM ) != -1 ){

				// COMPLEX�G���e�B�e�B�̃f�[�^�����o��
				SXFMapEntCConvC convert(body.m_EntityArray);
				//	STYLED_ITEM �̃p�����^�����o��
				convert.SplitComplex(DEF_STYLED_ITEM);
				CArray<int, int> intarray;
				int tmpInstID,OUT_Num;
				convert.GetSetInst(0,OUT_Num,intarray);
				convert.GetInst(1,tmpInstID);
				//	STYLED_ITEM�̂��C���X�^���X�ւ̂h�c��
				//	����COMPOSITE_CURVE_SEGMENT�̂���
				//	m_parent_curve_Inst �Ɠ������H�̃`�F�b�N
				if (tmpInstID == m_RootID ){
					AppeID = intarray[0];
					CurveID = body.GetRootID();
					break;
				}
			}
		}

		if (AppeID == 0){
			// STYLED_ITEM�̂h�c�擾
			IN_InstanceName = DEF_STYLED_ITEM;
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.10
/*
			if ( GetIDArray(IN_InstanceName) == NULL ) {
				return -10000;
			}
			else{
				IDarray = GetIDArray(IN_InstanceName);
			}
			for (i=0;i<IDarray->GetSize();i++){
*/
			IDarray = GetIDArray(IN_InstanceName) ;
			if( IDarray == NULL ) {
				return -10000 ;
			}
			for(pos = IDarray->GetHeadPosition(); pos; ) {
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.10
				// STYLED_ITEM�̂��C���X�^���X�h�c�擾
				SXFMapE_STYLED_ITEMC styled(m_InstanceIDManager);
//				styled.SetRootID((*IDarray)[i]);
				styled.SetRootID(IDarray->GetNext(pos));
				styled.SetEntity();
				styled.SetParameter();
				//	STYLED_ITEM�̂��C���X�^���X�ւ̂h�c��
				//	����COMPOSITE_CURVE_SEGMENT�̂���
				//	m_parent_curve_Inst �Ɠ������H�̃`�F�b�N
				if (styled.m_InstID == m_RootID ){
					AppeID = styled.m_AppeID;
					CurveID = styled.GetRootID();
					break;
				}
			}
		}

		////////////////////////////////////////////////////////////////////////////////
		//  �������ւ̂h�c�̎Q�Ɛ�G���e�B�e�B���擾���AStyles���쐬����B//////////////
		////////////////////////////////////////////////////////////////////////////////
		SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC AppeP(m_InstanceIDManager);
		AppeP.SetRootID(AppeID);
		if ( AppeP.SetParameter() < 0 ) {
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
		int colorID,fontID,widthID;
		colorID =((SXFMapE_CURVE_STYLEC*)(AppeP.m_styles_P))->m_colour_Inst;
		fontID  =((SXFMapE_CURVE_STYLEC*)(AppeP.m_styles_P))->m_font_Inst;
		widthID =((SXFMapE_CURVE_STYLEC*)(AppeP.m_styles_P))->m_width_Inst;
		int OUT_Type;
	//	OUT_Type = 2or3; 
		composite->m_color = m_TableManager->GetTableCode(colorID, OUT_Type);
		if (OUT_Type != 2 && OUT_Type != 3)
			composite->m_color = -1;
	//	OUT_Type = 4or5; 
		composite->m_type  = m_TableManager->GetTableCode(fontID, OUT_Type);
		if (OUT_Type != 4 && OUT_Type != 5)
			composite->m_type = -1;
	//	OUT_Type = 6; 
		composite->m_line_width = m_TableManager->GetTableCode(widthID, OUT_Type);
		if (OUT_Type != 6)
			composite->m_line_width = -1;
		//  �\���E��\���t���O�̐ݒ� /////////////////////////////////////////
		if (m_TableManager->GetInvisibilityFlag(CurveID))
			composite->m_flag = 0;
		else
			composite->m_flag = 1;
		m_Type  = composite_curve_org_feature;
		m_Class = composite;

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

	OUT_Type  = m_Type;		//�A�Z���u�����	
	OUT_Class = m_Class;	//�t�B�[�`���N���X�ւ̃|�C���^
	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapAssemblyC.cpp						�쐬���F2001.06.21

	�P�D�@�\�T�v
		�t�B�[�`���\���̂ɒl��ݒ�

	�Q�D�C���^�[�t�F�C�X
	int		SXFMapAssemblyC::SetStructData(
				E_type	IN_Type,
				LPVOID	IN_Class);

	����  �F	�^			������				���e
				E_type	IN_Type,	//�t�B�[�`���^�C�v
				LPVOID	IN_Class	//�t�B�[�`���N���X�ւ̃|�C���^
			
	���A�l�F�t�B�[�`���h�c

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2001.06.21	
**/
int SXFMapAssemblyC::SetStructData(
				int		IN_Type,
				LPVOID	IN_Class)

{
	m_Type 	= (E_type)IN_Type;
	m_Class	= IN_Class;
	if(m_Type == drawing_sheet_feature ){//1

		//�\�����ް��쐬
		Sheet_Struct* sheet = new Sheet_Struct;
		((SXFMapF_SHEETC*)m_Class)->GetStructData(sheet);
		//�\�����ް��̕ۑ�
		m_StructData = sheet;

	}else if(m_Type == sfig_org_feature){//11

		//�\�����ް��̍쐬
		Sfigorg_Struct* sfigorg = new Sfigorg_Struct;
		((SXFMapF_SFIGORGC*)m_Class)->GetStructData(sfigorg);
		//�\�����ް��̕ۑ�
		m_StructData = sfigorg;

	}else if(m_Type == composite_curve_org_feature ){//24

		//�\�����ް��̍쐬
		Ccurve_Org_Struct* curveorg = new Ccurve_Org_Struct;
		((SXFMapF_COMPOSITEC*)m_Class)->GetStructData(curveorg);
		//�\�����ް��̕ۑ�
		m_StructData = curveorg;

	}else{//feature comment name error
		return FALSE;
	}
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapAssemblyC.cpp						�쐬���F2001.06.21

	�P�D�@�\�T�v
		�t�B�[�`���\���̂��擾����

	�Q�D�C���^�[�t�F�C�X
	int		SXFMapAssemblyC::GetStructData(
				char*&	OUT_TypeName,
				void*		Out_Struct)

	����  �F	�^			������				���e
			char*			OUT_TypeName	�\���̂�Type Name
			LPVOID			OUT_Struct		�t�B�[�`���\����
			
	���A�l�F�t�B�[�`���h�c

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2001.06.21	
**/
int SXFMapAssemblyC::GetStructData(
		LPVOID&		OUT_Struct)
{
	OUT_Struct 	= m_StructData;
	return (m_RootID) ;
}
