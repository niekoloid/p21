//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFReadAP202ManagerC.cpp				�쐬���F2001.06.24
//
//	�P�D�N���X�T�v
//		�`�o202���͂̎��A�Z���u���Ԃ̎Q�Ɗ֌W
//		���Ǘ�����I�u�W�F�N�g
//
//	�Q�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.24	   ���X��(FQS)
//
//------------------------------------------------------------

#include "stdafx.h"
#include "SXFStruct.h"
#include "SXFMapEntAConvC.h"
#include "SXFReadAP202ManagerC.h"
#include "SXFReadAP202MapManagerC.h"
#include "SXFEntityDataC.h"
#include "SXFInstanceIDC.h"
//#include "ComSplitStringC.h"
#include "SXFComncApi.h"
#include "SXFErrorMsgC.h"
#include "SXFInstanceIDC.h"
#include "SXFTableManagerC.h"
#include "SXFComInfoC.h"
#include "SXF_EXT.h"
#include "SXFManageC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFReadAP202ManagerC.cpp				�쐬���F2001.06.24
//
//	�P�D�@�\�T�v
//		�N���X�\�z
//
//	�Q�D�C���^�[�t�F�[�X
//	����:	�^								������				���e
//			�Ȃ�					
//
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.24	   ���X��(FQS)
//
//------------------------------------------------------------
SXFReadAP202ManagerC::SXFReadAP202ManagerC()
{
	//initialization
	m_SheetID = 0;
	m_CurrentAssemblyType = 0;	//1:sheet
								//2:symbol
								//3:curve
	m_CurrentAssemblyNumber = 0;
	m_currentassemblyID = 0;
	m_CurrentChildArraySize = 0;
	m_CurrentChildNumber = 0;
//	DEL(S)	�`���[�j���O�Ή�	K.Naono	03.07.04
//	m_SheetStruct = NULL;
//	DEL(E)	�`���[�j���O�Ή�	K.Naono	03.07.04
	m_CurveAssemblyList = NULL;
	m_code = 1;			/* �A�Z���u���R�[�h */
	m_currentchild_Struct =NULL;
	m_currentchild_ID = 0;	

//	ADD(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
	m_mapSymId.InitHashTable(2999) ;
	m_SymbolInfoTable.InitHashTable(2999) ;
//	ADD(E)	�`���[�j���O�Ή�	K.Naono	03.07.03
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFReadAP202ManagerC.cpp				�쐬���F2001.06.24
//
//	�P�D�@�\�T�v
//		�N���X����
//
//	�Q�D�C���^�[�t�F�[�X
//	SXFReadAP202ManagerC::~SXFReadAP202ManagerC()
//
//	����:	�^								������				���e
//			�Ȃ�					
//
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.24	   ���X��(FQS)
//
//------------------------------------------------------------
SXFReadAP202ManagerC::~SXFReadAP202ManagerC()
{
	if(m_CurveAssemblyList != NULL){
		POSITION pos = m_CurveAssemblyList->GetHeadPosition();
		while(pos!=NULL){
			SXFASSEMBLYDATA *pAssembly = m_CurveAssemblyList->GetAt(pos);
			if(pAssembly!=NULL){
				delete pAssembly;
			}
			m_CurveAssemblyList->GetNext(pos);
		}
		delete	m_CurveAssemblyList;
	}

	if (m_currentchild_Struct)
		if (strcmp(m_currentchild_TypeName,DEF_POLYLINE) == 0)
			delete (Polyline_Struct*)m_currentchild_Struct;
		else if (strcmp(m_currentchild_TypeName,DEF_SPLINE) == 0)
			delete (Spline_Struct*)m_currentchild_Struct;
		else if (strcmp(m_currentchild_TypeName,DEF_CLOTHOID) == 0)
			delete (Clothoid_Struct*)m_currentchild_Struct;
		else if (strcmp(m_currentchild_TypeName,DEF_LABEL) == 0)
			delete (Label_Struct*)m_currentchild_Struct;
		else if (strcmp(m_currentchild_TypeName,DEF_BALLOON) == 0)
			delete (Balloon_Struct*)m_currentchild_Struct;
		else if (strcmp(m_currentchild_TypeName,DEF_FILL_AREA_STYLE_HATCHING) == 0)
			delete (Fill_area_style_hatching_Struct*)m_currentchild_Struct;
		else if (strcmp(m_currentchild_TypeName,DEF_EXTERNALLY_DEFINED_HATCH) == 0)
			delete (Externally_Defined_Hatch_Struct*)m_currentchild_Struct;
		else if (strcmp(m_currentchild_TypeName,DEF_FILL_AREA_STYLE_COLOUR) == 0)
			delete (Fill_area_style_colour_Struct*)m_currentchild_Struct;
		else if (strcmp(m_currentchild_TypeName,DEF_FILL_AREA_STYLE_TILES) == 0)
			delete (Fill_area_style_tiles_Struct*)m_currentchild_Struct;
		else 
			delete m_currentchild_Struct;
		m_currentchild_Struct = NULL;

//	ADD(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
	CString			strKey ;
	SXFSYMBOLINFO*	pSymValue ;
	for( POSITION pos = m_SymbolInfoTable.GetStartPosition(); pos; ) {
		m_SymbolInfoTable.GetNextAssoc(pos, strKey, (void*&)pSymValue) ;
		delete pSymValue ;
	}
//	ADD(E)	�`���[�j���O�Ή�	K.Naono	03.07.03
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFReadAP202ManagerC.cpp				�쐬���F2001.06.24
//
//	�P�D�@�\�T�v
//		�v�f�Ǘ�Table�����̗v�f���o�͂���
//		
//	�Q�D�C���^�[�t�F�[�X
//		BOOL GetNextFeature(char* OUT_TypeName,
//							size_t TypeNameSize,me,
//							LPVOID& OUT_Struct,
//							int* OUT_EndFlg)
//
//		����: �^			  ������				���e
//			  char*			  OUT_TypeName		   �\���̂�Type Name
//			  size_t		  TypeNameSize		   Type Name�o�b�t�@�T�C�Y
//			  LPVOID&		  OUT_Struct		   �\���̂̃A�h���X
//			  int*			  OUT_EndFlg		   �Ō�̗v�f��Flag
//													1: �Ō�̗v�f
//													0: ����
//		
//		���A�l	
//			  ���펞�FTRUE
//			  �ُ펞�FFALSE
//
//
//	�R�D����
//		����ԍ�	���t��		   �S����			�T�v
//		�쐬		2001.06.24	   ���X��(FQS)
//		�X�V		2015.04.27		T.Matsushima	JPCERT/CC �w�E �Ǝ㐫�Ή�
//
//------------------------------------------------------------
//int SXFReadAP202ManagerC::GetNextFeature(char* OUT_TypeName, LPVOID& OUT_Struct, int* OUT_EndFlg )
int SXFReadAP202ManagerC::GetNextFeature(char* OUT_TypeName,size_t TypeNameSize, LPVOID& OUT_Struct, int* OUT_EndFlg )
{
	OUT_Struct=NULL;
	*OUT_EndFlg = 0;
	int OUT_ID=0;

//	if(m_CurrentChildArraySize > m_CurrentChildArray.GetSize()-1){
	if(m_CurrentChildArraySize > m_CurrentChildArray.GetSize()){
		*OUT_EndFlg = 1;
		/** �A�Z���u����ɗv�f�����݂��Ȃ� **/
		SXFErrorMsgC::RecordError(SXFNOTFEATURE,"",0);
		return SXFNOTFEATURE;
	}

	//�A�Z���u����̂Q�Ԗڈȍ~�̗v�f�̏ꍇ
	if(m_CurrentChildArraySize > 0){
		if(m_currentchild_Struct==NULL){
			*OUT_EndFlg = 1;
			/** �A�Z���u����ɗv�f�����݂��Ȃ� **/
			SXFErrorMsgC::RecordError(SXFNOTFEATURE,"",0);
			return SXFNOTFEATURE;
		}
		//���̗v�f�̍\���̂�ԋp����B
		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(OUT_TypeName,m_currentchild_TypeName);
		strcpy_s(OUT_TypeName,TypeNameSize,m_currentchild_TypeName);
		OUT_Struct=m_currentchild_Struct;
		OUT_ID = m_currentchild_ID;
		//�v�f�̗̈���N���A����
		m_currentchild_Struct =NULL;
	}

	//�A�Z���u����̗v�f���\���̂��擾�ł���܂Ń}�b�s���O����
	//�ŏ��̗v�f�́A�ŏ��̗v�f�Ƃ��̎��̗v�f���}�b�s���O
	//�Q�Ԗڈȍ~�̗v�f�́A���̗v�f���}�b�s���O
	//�捡�̗v�f��*OUT_EndFlg�i�p���t���O�j��ݒ肷�邽�߁A
	//���̗v�f�ȍ~���A�S�ă}�b�s���O�ł��Ȃ������ꍇ���l���B

	while(m_CurrentChildArraySize < m_CurrentChildArray.GetSize()){

		//�A�Z���u����̗v�f�̃C���X�^���X�h�c�𓾂�
		m_currentchild_ID = 0;
		m_currentchild_ID = m_CurrentChildArray[m_CurrentChildArraySize];

		SXFReadAP202MapManagerC* currentmapmanager =new SXFReadAP202MapManagerC(
														m_InstanceIDManager,
														m_TableManager,
														m_ComInfo,
														this);
		if(currentmapmanager == NULL){
			/* �����G���[���������܂��� */
			SXFErrorMsgC::RecordError(SXFERROR,"",0);
			return SXFERROR;
		}

		if( currentmapmanager->SetInstanceID(m_currentchild_ID) == FALSE){
			if(currentmapmanager!=NULL)
				delete currentmapmanager;
			/** �A�Z���u����ɗv�f�����݂��Ȃ� **/
			SXFErrorMsgC::RecordError(SXFNOTFEATURE,"",0);
			return SXFNOTFEATURE;
		}

		//�A�Z���u����̗v�f�̃t�B�[�`���\���̂𓾂�
		if (m_currentchild_Struct != NULL ){
			gl_Man->Delete_feature(m_currentchild_TypeName,m_currentchild_Struct);
			m_currentchild_Struct = NULL;
		}

		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//m_currentchild_Struct = currentmapmanager->GetStructData(m_currentchild_TypeName);
		m_currentchild_Struct = currentmapmanager->GetStructData(m_currentchild_TypeName,_countof(m_currentchild_TypeName));
		if(currentmapmanager!=NULL)
			delete currentmapmanager;

		m_CurrentChildArraySize++;

		//�t�B�[�`���\���̂��擾�ł��Ă���ꍇ
		if(m_currentchild_Struct!=NULL){
			//�ŏ��̗v�f�̏ꍇ
			if(OUT_Struct==NULL){
				//���̗v�f�̍\���̂�ԋp����B
				//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
				//strcpy(OUT_TypeName,m_currentchild_TypeName);
				strcpy_s(OUT_TypeName,TypeNameSize,m_currentchild_TypeName);
				OUT_Struct=m_currentchild_Struct;
				OUT_ID = m_currentchild_ID;
				//�v�f�̗̈���N���A����i���̗v�f���ǂ߂�悤�j
				m_currentchild_Struct =NULL;
			}
			//���̗v�f������ꍇ
			else
				break;
		}
	}

	if(OUT_Struct==NULL){
		*OUT_EndFlg = 1;
		/** �A�Z���u����ɗv�f�����݂��Ȃ� **/
		SXFErrorMsgC::RecordError(SXFNOTFEATURE,"",0);
		return SXFNOTFEATURE;
	}

	//���̗v�f���Ȃ��ꍇ
	if(m_currentchild_Struct==NULL){
		*OUT_EndFlg = 1;
		//�A�Z���u����̗v�f�̗̈���N���A����
//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
//		strcpy(m_currentchild_TypeName,"");
		strcpy_s(m_currentchild_TypeName,_countof(m_currentchild_TypeName),"");
		m_currentchild_ID = 0;
	}
	//���̗v�f������ꍇ
	else{
		*OUT_EndFlg = 0;
	}

	m_CurrentChildNumber++;

	return OUT_ID;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFReadAP202ManagerC.cpp				�쐬���F2001.06.24
//
//	�P�D�@�\�T�v
//		Assembly�v�f�Ǘ�Table������Assembly�v�f���o�͂���
//		
//	�Q�D�C���^�[�t�F�[�X 
//		BOOL GetNextAssembly(int IN_Type,
//							 LPVOID& OUT_Struct,
//							 int* OUT_EndFlg)
//
//		����: �^			  ������				���e
//			  int			  IN_Type			   Assembly�\���̂�Type
//													1:sheet
//													2:symbol
//													3:curve
//			  LPVOID&		  OUT_Struct		   Assembly�\���̂̃A�h���X
//			  int*			  OUT_EndFlg		   �Ō��Assembly�v�f��Flag
//													1: �Ō��Assembly�v�f
//													0: ����
//		
//		���A�l	
//			  ���펞�FTRUE
//			  �ُ펞�FFALSE
//
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.24	   ���X��(FQS)
//
//------------------------------------------------------------
int SXFReadAP202ManagerC::GetNextAssembly(int IN_Type, LPVOID& OUT_Struct, int* OUT_EndFlg, int& OUT_InstanceID)
{
	OUT_Struct=NULL;

	OUT_InstanceID = -1;

	/* �����،^���ُ� */
	if (IN_Type != 1 && IN_Type != 2 && IN_Type != 3){
		SXFErrorMsgC::RecordError(SXFASSEMTYPEERR,"",1,IN_Type);
		return SXFASSEMTYPEERR;
	}

	/** �P�O�������Ȑ��̂Ƃ� **/
	if( m_CurrentAssemblyType == 3){
		if (m_CurrentChildNumber == 0) {
			// �����Ȑ��̃G���[�t���O�Ή�����
			if (m_CurveAssemblyList != NULL) {
				if( m_CurrentAssemblyNumber <= m_CurveIDArray.GetSize() ) {
				//	int beforeassemblyID = m_CurveIDArray[m_CurrentAssemblyNumber-1] ;
					SXFASSEMBLYDATA *pAssembly = NULL ;
					POSITION pos = m_CurveAssemblyList->GetHeadPosition() ;
					while( pos ) {
						pAssembly = m_CurveAssemblyList->GetAt(pos) ;
						if( pAssembly->ID == m_currentassemblyID ) {
							pAssembly->error = 1 ;
							break ;
						}
						m_CurveAssemblyList->GetNext(pos) ;
					}
				}
			}
		}
	}
	/* �V�Kð��ق̓ǂݏo���w�� */
	if(m_CurrentAssemblyType != IN_Type){
		m_CurrentAssemblyType = 0;
		m_CurrentAssemblyNumber = 0;
	}

	/** �p�� **/
	if(IN_Type == 1){
		m_currentassemblyID = m_SheetID;
		*OUT_EndFlg = 1;
	/** �����}�` **/
	}else if(IN_Type == 2){
		if(m_CurrentAssemblyNumber == m_SymbolIDArray.GetSize()-1){
			*OUT_EndFlg = 1;
		}else if(m_CurrentAssemblyNumber > m_SymbolIDArray.GetSize()-1 ){
			m_currentassemblyID = 0;
			*OUT_EndFlg = 1;
// MOD(S)	���b�Z�[�W�C��	K.Naono	04.03.05
			if( m_SymbolIDArray.GetSize() == 0 ) {
				SXFErrorMsgC::RecordError2(SXFNOASSEMBLY,"SFIGORG",0);
				return SXFNOASSEMBLY;
			}
// MOD(E)	���b�Z�[�W�C��	K.Naono	04.03.05
			/* �ǂݏo���A�Z���u���v�f������܂���B*/
			SXFErrorMsgC::RecordError(SXFNOASSEMBLY,"SFIGORG",0);
			return SXFNOASSEMBLY;
		}else{
			*OUT_EndFlg =0;
		}

		m_currentassemblyID = m_SymbolIDArray[m_CurrentAssemblyNumber];
	/** �����Ȑ� **/		   
	}else if(IN_Type == 3){
		if(m_CurrentAssemblyNumber == m_CurveIDArray.GetSize()-1){
			*OUT_EndFlg = 1;
		}else if(m_CurrentAssemblyNumber > m_CurveIDArray.GetSize()-1 ){
			m_currentassemblyID = 0;
			*OUT_EndFlg = 1;
// MOD(S)	���b�Z�[�W�C��	K.Naono	04.03.05
			if( m_CurveIDArray.GetSize() == 0 ) {
				SXFErrorMsgC::RecordError2(SXFNOASSEMBLY,"CCURVE_ORG",0);
				return SXFNOASSEMBLY;
			}
// MOD(E)	���b�Z�[�W�C��	K.Naono	04.03.05
			/* �ǂݏo���A�Z���u���v�f������܂���B*/
			SXFErrorMsgC::RecordError(SXFNOASSEMBLY,"CCURVE_ORG",0);
			return SXFNOASSEMBLY;
		}else{
			*OUT_EndFlg =0;
		}

		m_currentassemblyID = m_CurveIDArray[m_CurrentAssemblyNumber];
	}else{
		/* �����،^���ُ� */
		SXFErrorMsgC::RecordError(SXFASSEMTYPEERR,"",1,IN_Type);
		return SXFASSEMTYPEERR;
	}

	/** �ŏ��̃A�Z���u���v�f�̂Ƃ� **/
	if( m_CurrentAssemblyType == 0){
		/** �p�� **/
		if(IN_Type == 1){//sheet
			/* ���݂̱����،^���Z�b�g */
			m_CurrentAssemblyType = 1;
		/** �����}�` **/
		}else if(IN_Type == 2){//symbol
			/* ���݂̱����،^���Z�b�g */
			m_CurrentAssemblyType = 2;
			m_CurrentChildArraySize = 0;
			m_CurrentChildNumber = 0;
		/** �����Ȑ� **/ 
		}else if(IN_Type == 3){//curve
			/* ���݂̱����،^���Z�b�g */
			m_CurrentAssemblyType = 3;
			m_CurrentChildArraySize = 0;
			m_CurrentChildNumber = 0;
		}else{
			return -1;//type error
		}
	}else{
		if(IN_Type != m_CurrentAssemblyType){
			return -1;//error
		}
	}

	OUT_InstanceID = m_currentassemblyID;
	/*AP202Mapping�Ǘ���޼ު�Đ���*/
	SXFReadAP202MapManagerC* currentmapmanager =new SXFReadAP202MapManagerC(
											m_InstanceIDManager,
											m_TableManager,
											m_ComInfo,
											this);
	/*�����زݽ�ݽID�̾��*/
	if( currentmapmanager->SetAssemblyInstanceID(m_currentassemblyID) == FALSE){
		if(currentmapmanager!=NULL)
			delete currentmapmanager;
		m_CurrentAssemblyNumber++;
		/* �ǂݏo���A�Z���u���v�f������܂���B*/
		SXFErrorMsgC::RecordError(SXFNOASSEMBLY,"",0);
		return SXFNOASSEMBLY;
	}

	if(m_CurrentAssemblyType == 1){
		OUT_Struct = currentmapmanager->GetAssemblyStructData();
//	DEL(S)	�`���[�j���O�Ή�	K.Naono	03.07.04
//		 m_SheetStruct = (Sheet_Struct*)OUT_Struct;
//	DEL(E)	�`���[�j���O�Ή�	K.Naono	03.07.04
	/* �����}�` */	 
	}else if(m_CurrentAssemblyType == 2){
		OUT_Struct = currentmapmanager->GetAssemblyStructData();
//	DEL(S)	�`���[�j���O�Ή�	K.Naono	03.07.04
//		m_SfigStructArray.Add((Sfigorg_Struct*)OUT_Struct);
//	DEL(E)	�`���[�j���O�Ή�	K.Naono	03.07.04
	/* �����Ȑ� */
	}else if(m_CurrentAssemblyType == 3){
		 OUT_Struct = currentmapmanager->GetAssemblyStructData();
//	DEL(S)	�`���[�j���O�Ή�	K.Naono	03.07.04
//		 m_CurveStructArray.Add((Ccurve_Org_Struct*)OUT_Struct);
//	DEL(E)	�`���[�j���O�Ή�	K.Naono	03.07.04
	}else{
		/* �����،^���ُ� */
		SXFErrorMsgC::RecordError(SXFASSEMTYPEERR,"",1,IN_Type);
		return SXFASSEMTYPEERR;
	}

	if(OUT_Struct == NULL){
		if(currentmapmanager!=NULL)
			delete currentmapmanager;
		m_CurrentAssemblyNumber++;
		return -1;
	}

	m_CurrentChildArraySize = 0;
	m_CurrentChildNumber = 0;

//	ADD(S)	�`���[�j���O�Ή�	K.Naono	03.07.04
	m_CurrentChildArray.RemoveAll() ;
//	ADD(E)	�`���[�j���O�Ή�	K.Naono	03.07.04

	if (GetAllChild(m_currentassemblyID, m_CurrentChildArray)== FALSE){
		if(currentmapmanager!=NULL)
			delete currentmapmanager;
		m_CurrentAssemblyNumber++;
		return -1;
	}

	m_CurrentAssemblyNumber++;

	if(currentmapmanager!=NULL)
		delete currentmapmanager;

	int assemblycode =	GetAssemblyCode( m_currentassemblyID );

	return assemblycode;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFReadAP202ManagerC.cpp				�쐬���F2001.06.24
//
//	�P�D�@�\�T�v
//		�v�f�Ǘ�Table�Ɉ��AP202 Assembly Instance��o�^����
//		
//	�Q�D�C���^�[�t�F�[�X
//		BOOL RegisterAPAssembly(INSTANCEDATA *IN_Instance)
//
//		����: �^			  ������				���e
//			  INSTANCEDATA*  IN_Instance		   AP202 Assembly
//												   Instance�\���̂̃A�h���X
//		
//		���A�l	
//			  ���펞�FTRUE
//			  �ُ펞�FFALSE
//		
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.24	   ���X��(FQS)
//
//------------------------------------------------------------
BOOL SXFReadAP202ManagerC::RegisterAPAssembly(INSTANCEDATA *IN_Instance)
{
	if(IN_Instance->EntityName == DEF_DRAWING_SHEET_REVISION_USAGE){
		/*�p�����Ȃ�*/
		if(m_SheetID!= 0){
			SXFErrorMsgC::RecordError(SXFSHEETONE,"",0);
			return FALSE;
		}
		/*�p��ID*/
		m_SheetID = IN_Instance->InstanceID;
	/** �����Ȑ���` **/
	}else if(IN_Instance->EntityName == DEF_COMPOSITE_CURVE){
		m_CurveIDArray.Add(IN_Instance->InstanceID);
		if(m_CurveAssemblyList == NULL){
			m_CurveAssemblyList = new SXFAPASSEMBLYLIST;
		}
		/* �����Ȑ��e�[�u���ɒǉ� */
		SXFASSEMBLYDATA *pAssembly = new SXFASSEMBLYDATA();
		pAssembly->ID = IN_Instance->InstanceID;
		m_code++;	/* �����غ��ށFCURVE�̍ŏ��͂Q�ł����A�V�[�g�����CURVE������ */
		pAssembly->AssemblyCode = m_code;
		m_CurveAssemblyList->AddTail(pAssembly);

	}else if(IN_Instance->EntityName == DEF_SYMBOL_REPRESENTATION_MAP){
		m_SymbolIDTempArray.Add(IN_Instance->InstanceID);
//	ADD(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
		m_mapSymId.SetAt((WORD)IN_Instance->InstanceID, NULL) ;
//	ADD(E)	�`���[�j���O�Ή�	K.Naono	03.07.03
	}else{
		return FALSE;
	}

	return TRUE;

}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFReadAP202ManagerC.cpp				�쐬���F2001.06.24
//
//	�P�D�@�\�T�v
//		�v�f�Ǘ�Table�̒��ɓo�^������Symbol Assembly�𐮂���
//		(Symbol Assembly�̐e�q�֌W��z�񂷂�j
//		
//	�Q�D�C���^�[�t�F�[�X
//		BOOL ArrangeChild(int ExternalFlg )
//
//		����: �^			  ������				���e
//		 	  int			  ExternalFlg			Instance�\���̂̃A�h���X
//		
//		���A�l	
//			  ���펞�FTRUE
//			  �ُ펞�FFALSE
//
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.24	   ���X��(FQS)
//
//------------------------------------------------------------
BOOL SXFReadAP202ManagerC::ArrangeChild(int ExternalFlg )//ExternalFlag 0:StepFileRead 1:ExternalFileRead
{
//	ADD(S)	�`���[�j���O�Ή�	K.Naono	03.07.04
	if( m_SymbolIDTempArray.GetSize() == 0 ) {
		return TRUE ;
	}
//	ADD(E)	�`���[�j���O�Ή�	K.Naono	03.07.04

	//���e�[�u���̍쐬
	for( int i = 0;i<m_SymbolIDTempArray.GetSize();i++){
		SXFSYMBOLINFO*	info = new SXFSYMBOLINFO ;
		info->id = m_SymbolIDTempArray[i];

		/*AP202Mapping�Ǘ���޼ު�Đ���*/
		SXFReadAP202MapManagerC* mapmanager = 
			new SXFReadAP202MapManagerC( m_InstanceIDManager,
										m_TableManager,
										m_ComInfo, this);

		if( mapmanager->SetAssemblyInstanceID(info->id) == FALSE){
			if(mapmanager!=NULL)
				delete mapmanager;
			return FALSE;//set id or mapping data error
		}

		Sfigorg_Struct* structdata = (Sfigorg_Struct*)(mapmanager->GetAssemblyStructData());
		if(structdata == NULL){
			if(mapmanager!=NULL)
				delete mapmanager;
			return FALSE;//set id or mapping data error
		}
		if(mapmanager!=NULL)
			delete mapmanager;

		info->typeflag = structdata->flag;
		info->name = structdata->name;
		delete structdata;

		//ð��قɂ��łɑ��݂��邩�̃`�F�b�N
		BOOL samefind=FALSE;
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.08
/*
		for(int j=0;j<m_SymbolInfoTable.GetSize();j++){
			if( info.name == m_SymbolInfoTable[j].name){
				samefind = TRUE;
				break;
			}
		}
*/
		SXFSYMBOLINFO*	pValue ;
		if( m_SymbolInfoTable.Lookup(info->name, (void*&)pValue) ) {
			samefind = TRUE ;
		}
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.08
		/*���łɓo�^����Ă���ꍇ*/
		if(samefind == TRUE){
//	ADD(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
			m_mapSymId.RemoveKey((WORD)m_SymbolIDTempArray[i]) ;
//	ADD(E)	�`���[�j���O�Ή�	K.Naono	03.07.03
			m_SymbolIDTempArray.RemoveAt(i);		
			SXFErrorMsgC::RecordError(SXFSAMENAME, //SXFSAMENAME = -20024,
										DEF_SFIG_ORG,
										1,
										info->name);
		}else{
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.08
//			m_SymbolInfoTable.Add(info);
			m_SymbolInfoTable.SetAt(info->name, info) ;
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.08
		}
	}

	///////////////////////////////////////
	//�O����`�t�@�C����Read���̓V�[�g�Ȃ��ł�OK
	///////////////////////////////////////
	if (ExternalFlg == 1){
		m_SymbolIDArray.Copy(m_SymbolIDTempArray);
	}
	else{
		if(m_SheetID == 0) {
			SXFErrorMsgC::RecordError(SXFNOTSETSHEET,DEF_SHEET,0);
			return FALSE;
		}

//	ADD(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
/*
		CUIntArray symbolarray;
		if( GetSymbolChild(m_SheetID, symbolarray) == FALSE)
			return FALSE;

		while(symbolarray.GetSize()!=0){
			for(int i =0;i<symbolarray.GetSize();i++){
				m_SymbolArrangeIDArray.Add(symbolarray[i]);
			}

			CUIntArray tempsymbolarray;
			CUIntArray allchildarray;
			for(i =0;i<symbolarray.GetSize();i++){
				tempsymbolarray.RemoveAll();
				if( GetSymbolChild(symbolarray[i], tempsymbolarray) == FALSE)
					return FALSE;
				for(int j=0;j<tempsymbolarray.GetSize();j++){
					allchildarray.Add(tempsymbolarray[j]);
				}
			}

			symbolarray.RemoveAll();
			for(i=0;i<allchildarray.GetSize();i++){
				symbolarray.Add(allchildarray[i]);
			}

		}

		int count = m_SymbolArrangeIDArray.GetSize();
		for(int j =0;j<count;j++){
			BOOL findsame =FALSE;
			for(int k =0;k<m_SymbolIDArray.GetSize();k++){
				if( m_SymbolArrangeIDArray[count-j-1]  == m_SymbolIDArray[k]){
					findsame = TRUE;
					break;
				}
			}
			if(findsame == FALSE)
				m_SymbolIDArray.Add( m_SymbolArrangeIDArray[count-j-1]);
		}
*/
		if( !builtRelationship(m_SheetID) ) {
			return FALSE ;
		}
//	ADD(E)	�`���[�j���O�Ή�	K.Naono	03.07.03
	}

	return TRUE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2003
//	SXFReadAP202ManagerC.cpp				�쐬���F2003.07.07
//
//	�P�D�@�\�T�v
//		�v�f�Ǘ�Table�̒��ɓo�^������Symbol Assembly�𐮂���
//			(Symbol Assembly�̐e�q�֌W��z�񂷂�j
//
//	�Q�D�C���^�[�t�F�[�X
//		BOOL TEST(int ExternalFlg)
//
//		����: �^			������				���e
//			int				ExternalFlg			Instance�\���̂̃A�h���X
//
//		���A�l	
//			���펞�FTRUE
//			�ُ펞�FFALSE
//
//	�R�D����
//		����ԍ�	���t��		�S����			�T�v
//		�쐬		2003.07.07	K.Naono
//
//------------------------------------------------------------
BOOL SXFReadAP202ManagerC::builtRelationship(
						int		inID) {
	CUIntArray	symbolarray ;
	CUIntArray	allchildarray ;
	INT_PTR			nSize ;

	if( !GetSymbolChild(m_SheetID, symbolarray) )
		return FALSE ;

	while(TRUE) {
		m_SymbolArrangeIDArray.Append(symbolarray) ;

		allchildarray.RemoveAll() ;
		nSize = symbolarray.GetSize() ;
		for(int i = 0; i < nSize; i++) {
			if( !GetSymbolChild(symbolarray[i], allchildarray) )
				return FALSE ;
		}

		if( allchildarray.GetSize() == 0 ) {
			break ;
		}

		symbolarray.RemoveAll();
		symbolarray.Append(allchildarray) ;
	}

	INT_PTR	i, j ;
	nSize = m_SymbolArrangeIDArray.GetSize() ;
	for(i = nSize - 1; i >= 0; i--) {
		for(j = 0; j < m_SymbolIDArray.GetSize(); j++) {
			if( m_SymbolArrangeIDArray[i] == m_SymbolIDArray[j] ) {
				break ;
			}
		}
		if( j == m_SymbolIDArray.GetSize() ) {
			m_SymbolIDArray.Add(m_SymbolArrangeIDArray[i]) ;
		}
	}

	return TRUE ;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFReadAP202ManagerC.cpp				�쐬���F2001.06.24
//
//	�P�D�@�\�T�v
//		�w�肵��Assembly��Symbol Assembly�q�ǂ���T��
//		(Symbol Assembly�̐e�q�֌W��z�񂷂�ׁj
//		
//	�Q�D�C���^�[�t�F�[�X
//		BOOL GetSymbolChild(int IN_ID,
//							CUIntArray& OUT_ChildArray)
//
//		����: �^			  ������				���e
//			  int			  IN_ID				   �w�肵��Assembly
//												   ��Instance ID
//			  CUIntArray&	  OUT_ChildArray	   �T����Symbol Assembly
//												   �q��������Instance ID
//												   Array
//		
//		���A�l	
//			  ���펞�FTRUE
//			  �ُ펞�FFALSE
//		
//
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.24	   ���X��(FQS)
//
//------------------------------------------------------------

BOOL SXFReadAP202ManagerC::GetSymbolChild(int IN_ID, CUIntArray& OUT_ChildArray)
{
	CUIntArray allchild;
	CUIntArray symbolchild;

	if( GetAllChild(IN_ID,allchild) == FALSE )
		return FALSE;

//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
/*
	for(int i = 0;i<allchild.GetSize();i++){
		int symbolID = 0;
		if( (symbolID = FindSymbolID(allchild[i])) != 0){
			symbolchild.Add(symbolID);
		}
	}

	for( i=0;i<symbolchild.GetSize();i++){
		for(int j=0;j<m_SymbolIDTempArray.GetSize();j++){
			BOOL findflg = FALSE;
			if( symbolchild[i] == m_SymbolIDTempArray[j] ){ 
				OUT_ChildArray.Add(symbolchild[i]);
				findflg=TRUE;
				break;
			}
			if (findflg=FALSE)
				return FALSE;
		}
	}
*/
	int		i, symbolID = 0;
	INT_PTR		nall = allchild.GetSize() ;
	void*	rValue = NULL ;
//	int	nsym = m_SymbolIDTempArray.GetSize() ;
	for(i = 0; i < nall; i++) {
		symbolID = FindSymbolID(allchild[i]) ;
		if( symbolID == 0 ) continue ;

//		for(j = 0; j < nsym; j++) {
//			if( symbolID == (int)m_SymbolIDTempArray[j] ) {
//				OUT_ChildArray.Add(symbolID) ;
//				break ;
//			}
//		}
//		if( j == nsym ) {
//			return FALSE ;
//		}
		if( m_mapSymId.Lookup((WORD)symbolID, rValue) ) {
			OUT_ChildArray.Add(symbolID) ;
		} else {
			return FALSE ;
		}
	}
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.03

	return TRUE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFReadAP202ManagerC.cpp				�쐬���F2001.06.24
//
//	�P�D�@�\�T�v
//		�w�肵���q�ǂ���Symbol Assembly���܂ނ��ǂ����̔��肷��
//		(Symbol Assembly�̐e�q�֌W��z�񂷂�ׁj
//		
//	�Q�D�C���^�[�t�F�[�X
//		int FindSymbolID( int IN_ID )
//
//		����: �^			  ������				���e
//			  int			  IN_ID				   �w�肵���q�ǂ�
//												   ��Instance ID
//		
//		���A�l
//			  ���펞�F
//					   Symbol Assembly��Instance ID�FSymbol Assembly���܂�
//												  0�FSymbol Assembly���Ȃ�
//			  �ُ펞�F
//		
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.24	   ���X��(FQS)
//
//------------------------------------------------------------
int SXFReadAP202ManagerC::FindSymbolID( int IN_ID )
{

	SXFEntityDataC* entitydataptr = NULL;
	entitydataptr=m_InstanceIDManager->GetEntityDataPtr(IN_ID);
	if(entitydataptr == NULL)
		return 0;

	if(entitydataptr->m_EntityName != DEF_SXF_COMPLEX_INSTANCE)
		return 0;

	CStringArray dataarray;

	if( entitydataptr->GetEntityDataArray(dataarray) == FALSE)
		return 0;

	if(dataarray.GetSize() != 7)
		return 0;

	dataarray[1].Remove('(');
	dataarray[1].Remove(')');
	dataarray[1].TrimLeft( );
	dataarray[1].TrimRight( );
	if(dataarray[1] != DEF_ANNOTATION_SUBFIGURE_OCCURRENCE)
		return 0;

	if(dataarray[6].Left(11) != DEF_STYLED_ITEM)
		return 0;

	int place = dataarray[6].ReverseFind('#');
	if(place<0)
		return 0;
	dataarray[6].Delete(0,place+1);
	dataarray[6].Remove(')');
	dataarray[6].TrimLeft( );
	dataarray[6].TrimRight( );

	int dataid = atoi(dataarray[6]);
	dataarray.RemoveAll();

	entitydataptr = NULL;
	entitydataptr=m_InstanceIDManager->GetEntityDataPtr(dataid);
	if(entitydataptr == NULL)
		return 0;

	if(entitydataptr->m_EntityName != DEF_SXF_COMPLEX_INSTANCE)
		return 0;

	if( entitydataptr->GetEntityDataArray(dataarray) == FALSE)
		return 0;
	
	if(dataarray.GetSize() != 4)
		return 0;

	if(dataarray[2].Left(11) != DEF_MAPPED_ITEM)
		return 0;

	int place1 = dataarray[2].Find('#'); 
	if(place1<0)
		return 0;
	int place2 = dataarray[2].Find(','); 
	if(place2<0)
		return 0;
	int charcount=place2-place1-1;
	if( charcount<1)
		return 0;

	dataid = 0;
	dataid = atoi(dataarray[2].Mid(place1+1,charcount));

	entitydataptr = NULL;
	entitydataptr=m_InstanceIDManager->GetEntityDataPtr(dataid);
	if(entitydataptr == NULL)
		return 0;

	if(entitydataptr->m_EntityName != DEF_SYMBOL_REPRESENTATION_MAP)
		return 0;

	return dataid;

}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFReadAP202ManagerC.cpp				�쐬���F2001.06.24
//
//	�P�D�@�\�T�v
//		�w�肵��Assembly�̑S���̎q�ǂ���T��
//		(Symbol Assembly�̐e�q�֌W��z�񂷂�ׁj
//		
//	�Q�D�C���^�[�t�F�[�X
//		BOOL GetAllChild(int IN_ID, CUIntArray& OUT_ChildArray)
//
//		����: �^			  ������				���e
//			  int			  IN_ID				   �w�肵��Assembly
//												   ��Instance ID
//			  CUIntArray&	  OUT_ChildArray	   �T�����q��������
//												   Instance ID Array
//		
//		���A�l	
//			  ���펞�FTRUE
//			  �ُ펞�FFALSE
//		
//
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.24	   ���X��(FQS)
//
//------------------------------------------------------------
BOOL SXFReadAP202ManagerC::GetAllChild(int IN_ID, CUIntArray& OUT_ChildArray)
{

	OUT_ChildArray.RemoveAll();
	int subfigureid = -1;
	SXFEntityDataC* entitydataptr = NULL;
	entitydataptr=m_InstanceIDManager->GetEntityDataPtr(IN_ID);
	if(entitydataptr == NULL)
		return FALSE;

	if(entitydataptr->m_EntityName == DEF_DRAWING_SHEET_REVISION_USAGE){

		CStringArray dataarray_temp;
		if( entitydataptr->GetEntityDataArray(dataarray_temp) == FALSE)
			return FALSE;

		int sheetid = 0;
		SXFMapEntAConvC convent(&dataarray_temp);

		if( convent.GetInst(0,sheetid) < 0 )
			return FALSE;
		if(sheetid<=0)
			return FALSE;

		entitydataptr=m_InstanceIDManager->GetEntityDataPtr(sheetid);
		if(entitydataptr == NULL)
			return FALSE;
		if(entitydataptr->m_EntityName != DEF_DRAWING_SHEET_REVISION)
			return FALSE;

		CStringArray dataarray;
		if( entitydataptr->GetEntityDataArray(dataarray) == FALSE)
			return FALSE;

		CUIntArray	idarray;
		if( SXFListToIntID( dataarray[1],idarray ) == FALSE)
			return FALSE;

//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
/*
		for(int i =0;i<idarray.GetSize();i++){
			OUT_ChildArray.Add(idarray[i]);
		}
*/
		OUT_ChildArray.Append(idarray) ;
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.03

//	ADD(S)	Ver3.0�Ή�	K.Naono	04.01.30
		// DRAUGHTING_CONTRACT_ASSIGNMENT�̃C���X�^���XID���擾
		int	attr_id = m_TableManager->GetAttributeID() ;
		if( attr_id != -1 ) {
            OUT_ChildArray.Add(attr_id) ;
		}
//	ADD(E)	Ver3.0�Ή�	K.Naono	04.01.30

	}else if( entitydataptr->m_EntityName ==DEF_DRAUGHTING_SUBFIGURE_REPRESENTATION ){

		CStringArray dataarray;
		if( entitydataptr->GetEntityDataArray(dataarray) == FALSE)
			return FALSE;

		CUIntArray	idarray;
		if( SXFListToIntID( dataarray[1],idarray ) == FALSE)
			return FALSE;

//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
/*
		for(int i =0;i<idarray.GetSize();i++){
			OUT_ChildArray.Add(idarray[i]);
		}
*/
		OUT_ChildArray.Append(idarray) ;
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.03

	}else if(entitydataptr->m_EntityName ==DEF_SYMBOL_REPRESENTATION_MAP){

		CStringArray dataarray;
		if( entitydataptr->GetEntityDataArray(dataarray) == FALSE)
			return FALSE;

		if( dataarray.GetSize()!= 2)
			return FALSE;
		if(dataarray[1][0]!='#')
			return FALSE;
		dataarray[1].TrimLeft('#');

		subfigureid = atoi(dataarray[1]);

		SXFEntityDataC* subfiguredataptr = NULL;
		subfiguredataptr = m_InstanceIDManager->GetEntityDataPtr(subfigureid);
		if(subfiguredataptr == NULL)
			return FALSE;

		if(subfiguredataptr->m_EntityName != DEF_DRAUGHTING_SUBFIGURE_REPRESENTATION)
			return FALSE;

		dataarray.RemoveAll();

		if( subfiguredataptr->GetEntityDataArray(dataarray) == FALSE)
			return FALSE;

		CUIntArray	idarray;
		if( SXFListToIntID( dataarray[1],idarray ) == FALSE)
			return FALSE;

//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
/*
		for(int i =0;i<idarray.GetSize();i++){
			OUT_ChildArray.Add(idarray[i]);
		}
*/
		OUT_ChildArray.Append(idarray) ;
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.03

	}else if(entitydataptr->m_EntityName ==DEF_COMPOSITE_CURVE){

		CStringArray dataarray;
		if( entitydataptr->GetEntityDataArray(dataarray) == FALSE)
			return FALSE;

		CUIntArray	idarray;
		if( SXFListToIntID( dataarray[1],idarray ) == FALSE)
			return FALSE;

//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
/*
		for(int i =0;i<idarray.GetSize();i++){
			OUT_ChildArray.Add(idarray[i]);
		}
*/
		OUT_ChildArray.Append(idarray) ;
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.03

	}else{
		return FALSE;
	}

	return TRUE;
}
//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFReadAP202ManagerC.cpp				�쐬���F2001.06.24
//
//	�P�D�@�\�T�v
//		Instance ID List ���� Int Array�ɕϊ�����
//		Char String:"(ID1,ID2,ID3,...IDn)" 
//				   ====>
//		IntArray:[ID1,ID2,ID3,...IDn]
//		
//	�Q�D�C���^�[�t�F�[�X
//		BOOL SXFListToIntID(CString& IN_List, CUIntArray& OUT_IDArray)
//
//		����: �^			  ������				���e
//			  CString&		 IN_List			   Instance ID List
//												   char string�^
//			  CUIntArray&	 OUT_IDArrayint		   Instance ID Array
//												   IntArray�^
//		
//		���A�l	
//			  ���펞�FTRUE
//			  �ُ펞�FFALSE
//
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.24	   ���X��(FQS)
//
//------------------------------------------------------------
BOOL SXFReadAP202ManagerC::SXFListToIntID(CString& IN_List, CUIntArray& OUT_IDArray)
{
	IN_List.TrimLeft();
	if(IN_List[0] != '(' || IN_List.Right(1) != ')' )
		return FALSE;

	IN_List.TrimLeft('(');
	IN_List.TrimRight(')');

//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
/*
	ComSplitStringC split(IN_List);
	CStringArray* array;
	array = split.Split(',');

	for(int i=0;i<array->GetSize();i++){
		(*array)[i].TrimLeft();
		if((*array)[i][0] != '#')
			return FALSE;
		(*array)[i].TrimLeft('#');
		OUT_IDArray.Add( atoi( (*array)[i] ) );
	}
*/
	CStringArray	array ;
	int	nCount = GFn_SplitString(IN_List, ',' , array) ;
	for(int i = 0; i < nCount; i++) {
		array[i].TrimLeft() ;
		if(array[i][0] != '#')
			return FALSE ;
		array[i].TrimLeft('#') ;
		OUT_IDArray.Add(atoi(array[i])) ;
	}
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.03

	return TRUE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFReadAP202ManagerC.cpp				�쐬���F2001.06.24
//
//	�P�D�@�\�T�v
//		�N���X�\�z
//
//	�Q�D�C���^�[�t�F�[�X
//	void	SXFReadAP202ManagerC(SXFInstanceIDC* IN_InstanceIDManager,
//								 SXFTableManagerC* IN_TableManager,
//								 SXFComInfoC* IN_ComInfo)
//	����:	�^								������				���e
//			SXFInstanceIDC*  				IN_InstanceIDManager	�ݽ�ݽID�Ǘ���޼ު��
//			SXFTableManagerC* 				IN_TableManager			��`ð��يǗ���޼ު��
//			SXFComInfoC* 					IN_ComInfo				���ʏ��Ǘ���޼ު��
//
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.24	   ���X��(FQS)
//
//------------------------------------------------------------
SXFReadAP202ManagerC::SXFReadAP202ManagerC(
							SXFInstanceIDC* IN_InstanceIDManager,
							SXFTableManagerC* IN_TableManager,
							SXFComInfoC* IN_ComInfo)
{

	//initialization
	m_SheetID = 0;
	m_CurrentAssemblyType = 0;	//1:sheet
								//2:symbol
								//3:curve
	m_CurrentAssemblyNumber = 0;
	m_currentassemblyID = 0;
	m_CurrentChildArraySize = 0;
	m_CurrentChildNumber = 0;
	m_InstanceIDManager = IN_InstanceIDManager;
	m_TableManager = IN_TableManager;
	m_ComInfo = IN_ComInfo;
//	DEL(S)	�`���[�j���O�Ή�	K.Naono	03.07.04
//	m_SheetStruct = NULL;
//	DEL(E)	�`���[�j���O�Ή�	K.Naono	03.07.04
	m_CurveAssemblyList = NULL;
	m_code = 1;			/* �A�Z���u���R�[�h */
	m_currentchild_Struct =NULL;
	m_currentchild_ID = 0;

//	ADD(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
	m_mapSymId.InitHashTable(2999) ;
	m_SymbolInfoTable.InitHashTable(2999) ;
//	ADD(E)	�`���[�j���O�Ή�	K.Naono	03.07.03
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWriteManagerC.cpp					�쐬���F2001.06.18
//
//	�P�D�@�\�T�v
//		Assembly ID�̎擾
//
//	�Q�D�C���^�[�t�F�[�X
//		int GetAssemblyID(int IN_AssemblyCode)
//
//		����: �^			  ������				���e
//			  int			  IN_AssemblyCode			   Assembly Code
//
//		���A�l	
//			  ���펞�FAssembly ID
//			  �ُ펞�F-1
//		
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.18	  ���X��(FQS)
//
//------------------------------------------------------------
int SXFReadAP202ManagerC::GetAssemblyID(int IN_AssemblyCode)
{
	int id = -1;

	if(IN_AssemblyCode == 1){
		id = m_SheetID;

	} else if(	(IN_AssemblyCode-1) > 0 && 
				(IN_AssemblyCode-1) <= m_CurveIDArray.GetSize()) {
		id = m_CurveIDArray[IN_AssemblyCode-1-1];

	} else if(	(IN_AssemblyCode - 1 - m_CurveIDArray.GetSize()) > 0 &&
				(IN_AssemblyCode - 1 - m_CurveIDArray.GetSize()) <= m_SymbolIDTempArray.GetSize() ) {
		id = m_SymbolIDTempArray[IN_AssemblyCode - 1 - m_CurveIDArray.GetSize() -1];

	} else {
		id = -1;
	}

	return id;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWriteManagerC.cpp					�쐬���F2001.06.18
//
//	�P�D�@�\�T�v
//		Assembly Code�̎擾
//
//	�Q�D�C���^�[�t�F�[�X
//		int GetAssemblyCode(int IN_AssemblyID)
//
//		����: �^			  ������				���e
//			  int			  IN_AssemblyID				 Assembly ID
//
//		���A�l	
//			  ���펞�FAssembly Code
//			  �ُ펞�F-1
//		
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.18	  ���X��(FQS)
//
//------------------------------------------------------------
int SXFReadAP202ManagerC::GetAssemblyCode(int IN_AssemblyID)
{
	INT_PTR code = -1;
	if(IN_AssemblyID == m_SheetID){
		code = 1;
		return (int)code;
	}

//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.01
//	for(int i=0;i<m_CurveIDArray.GetSize();i++){
	INT_PTR	nSize = m_CurveIDArray.GetSize() ;
	for(int i = 0; i < nSize; i++) {
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.01
		if(m_CurveIDArray[i] == (UINT)IN_AssemblyID){
			code = i + 1 + 1;
			return (int)code;
		}
	}
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.01
//	for(i=0;i<m_SymbolIDTempArray.GetSize();i++){
	nSize = m_SymbolIDTempArray.GetSize() ;
	for(i = 0; i < nSize; i++) {
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.01
		if(m_SymbolIDTempArray[i] == (UINT)IN_AssemblyID){
			code = i + 1 + 1 + m_CurveIDArray.GetSize();
			return (int)code;
		}
	}
	return (int)code;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWriteManagerC.cpp					�쐬���F2001.06.18
//
//	�P�D�@�\�T�v
//		Symbol�̏��擾
//
//	�Q�D�C���^�[�t�F�[�X
//		int GetSymbolInfo(int IN_SymbolID, int& OUT_Flag, CString& OUT_Name)
//
//		����: �^			  ������				���e
//		int				IN_SymbolID		Symbol ID		
//		int				OUT_Flag		Sysmbol���i�t���O�j
//		CString			OUT_Name		Sysmbol���i���O�j
//
//		���A�l	
//			  ���펞�FAssembly Code
//			  �ُ펞�F-1
//		
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.18	  ���X��(FQS)
//
//------------------------------------------------------------
BOOL SXFReadAP202ManagerC::GetSymbolInfo(int IN_SymbolID, int& OUT_Flag, CString& OUT_Name)
{
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.08
/*
	for(int i=0;i<m_SymbolInfoTable.GetSize();i++){
		if(IN_SymbolID == m_SymbolInfoTable[i].id){
			OUT_Flag = m_SymbolInfoTable[i].typeflag;
			OUT_Name = m_SymbolInfoTable[i].name;
			return TRUE;
		}
	}
*/
	CString			strKey ;
	SXFSYMBOLINFO*	pValue ;
	for(POSITION pos = m_SymbolInfoTable.GetStartPosition(); pos; ) {
		m_SymbolInfoTable.GetNextAssoc(pos, strKey, (void*&)pValue) ;
		if( IN_SymbolID == pValue->id ) {
			OUT_Flag = pValue->typeflag ;
			OUT_Name = pValue->name ;
			return TRUE ;
		}
	}
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.08

	return FALSE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFReadAP202ManagerC.cpp					�쐬���F2001.06.18
//
//	�P�D�@�\�T�v
//		Symbol Code�̃`�F�b�N
//
//	�Q�D�C���^�[�t�F�[�X
//		int SymbolCodeCheck( int IN_Code )
//
//		����: �^			  ������				���e
//		int			IN_Code			Symbol Code		
//
//		���A�l	
//			  ���펞�FAssembly Code
//			  �ُ펞�F-1
//		
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.18	  ���X��(FQS)
//
//------------------------------------------------------------
BOOL SXFReadAP202ManagerC::SymbolCodeCheck( int IN_Code )
{
	if(IN_Code >= 1 + 1 &&
		IN_Code <= 1 + m_CurveIDArray.GetSize() ) {
		// ��������TRUE�ɂ���̂ł͂Ȃ��Aerror�ł��邩�ǂ��������ׂ�
		if (m_CurveAssemblyList == NULL)
			return TRUE;
		for(POSITION pos = m_CurveAssemblyList->GetHeadPosition();
					pos != NULL;m_CurveAssemblyList->GetNext(pos)){
			if (m_CurveAssemblyList->GetAt(pos)->AssemblyCode == IN_Code) {
				if (m_CurveAssemblyList->GetAt(pos)->error != 0) {
					// Error�ł�����
					return FALSE;
				}
			}
		}
		return TRUE;
	}
	else
		return FALSE;

	return FALSE;
}

//	DEL(S)	�`���[�j���O�Ή�	K.Naono	03.07.08
/*
//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFReadAP202ManagerC.cpp					�쐬���F2001.06.18
//
//	�P�D�@�\�T�v
//		����Sfig Assembly�o�^���邱�Ƃ����邩�ǂ�����Check
//
//	�Q�D�C���^�[�t�F�[�X
//		BOOL CheckSameSfig( LPCTSTR IN_Name)
//
//		����: �^			  ������				���e
//			  LPCTSTR		  IN_Name			   Sfig Name
//
//		���A�l	
//			  ���펞�FTRUE
//			  �ُ펞�FFALSE
//		
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.18	  ���X��(FQS)
//
//------------------------------------------------------------
BOOL SXFReadAP202ManagerC::SfigNameCheck(LPCTSTR IN_Name)
{
	//Name check
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.08
//
//	for(int i=0;i<m_SymbolInfoTable.GetSize();i++){
//		if (m_SymbolInfoTable[i].name == IN_Name){
//			return TRUE;
//		}
//	}
//
	SXFSYMBOLINFO*	pValue ;
	if( m_SymbolInfoTable.Lookup(IN_Name, (void*&)pValue) ) {
		return TRUE ;
	}
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.08
	return FALSE;
}
*/
//	DEL(E)	�`���[�j���O�Ή�	K.Naono	03.07.08

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFReadAP202ManagerC.cpp					�쐬���F2001.06.18
//
//	�P�D�@�\�T�v
//		Symbol ID�̎擾
//
//	�Q�D�C���^�[�t�F�[�X
//		int GetSymbolID(LPCTSTR IN_Name,int& OUT_SymbolID, int& OUT_Flag)
//
//		����: �^			  ������				���e
//				LPCTSTR		 IN_Name				Symbol��		  
//				int			 OUT_SymbolID			Symbol ID
//				int			 OUT_Flag				Symbol �t���O
//
//		���A�l	
//			  ���펞�FTRUE
//			  �ُ펞�FFALSE
//		
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.18	  ���X��(FQS)
//
//------------------------------------------------------------
BOOL SXFReadAP202ManagerC::GetSymbolID(LPCTSTR IN_Name,int& OUT_SymbolID, int& OUT_Flag)
{
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.08
/*
	for(int i=0;i<m_SymbolInfoTable.GetSize();i++){
		if(m_SymbolInfoTable[i].name == CString(IN_Name)){
			OUT_Flag = m_SymbolInfoTable[i].typeflag;
			OUT_SymbolID = m_SymbolInfoTable[i].id;
			return TRUE;
		}
	}
*/
	SXFSYMBOLINFO*	pValue ;
	if( m_SymbolInfoTable.Lookup(IN_Name, (void*&)pValue) ) {
		OUT_Flag	= pValue->typeflag ;
		OUT_SymbolID= pValue->id ;
		return TRUE ;
	}
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.08

	return FALSE ;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFReadAP202ManagerC.cpp			   �쐬���F2001.2.23
//
//	�P�D�@�\�T�v
//		�����}�`���ɑΉ����镡���}�`��ʂ̎擾
//
//	�Q�D�C���^�[�t�F�[�X
//		BOOL GetSfigFlg( LPCTSTR IN_Name,
//						int* OUT_SfigFlg,
//						int* OUT_LocFlg)
//
//		����: �^			  ������			���e
//			  LPCTSTR		  IN_Name			Sfig Name
//
//		���A�l	
//			  ���펞�FTRUE		�����}�`���ɑΉ������ʂ���
//			  �ُ펞�FFALSE		�����}�`���ɑΉ������ʂȂ�
//
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.2.23	   ���X��(FQS)
//
//------------------------------------------------------------
BOOL SXFReadAP202ManagerC::GetSfigFlg( LPCTSTR IN_Name,
											int* OUT_SfigFlg,
											int* OUT_LocFlg)
{
	*OUT_SfigFlg = -1;
	*OUT_LocFlg = -1;
	//Name check 
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.08
/*
	for(int i=0;i<m_SymbolInfoTable.GetSize();i++){
		if (m_SymbolInfoTable[i].name == IN_Name){
			// �����}�`���
			*OUT_SfigFlg = m_SymbolInfoTable[i].typeflag;
			// �����}�`�z�u�׸�
			*OUT_LocFlg = m_SymbolInfoTable[i].locateflag;
			return TRUE;
		}
	}
*/
	SXFSYMBOLINFO*	pValue ;
	if( m_SymbolInfoTable.Lookup(IN_Name, (void*&)pValue) ) {
		// �����}�`���
		*OUT_SfigFlg= pValue->typeflag ;
		// �����}�`�z�u�׸�
		*OUT_LocFlg	= pValue->locateflag ;
		return TRUE ;
	}
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.08
	return FALSE;
}
//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFReadAP202ManagerC.cpp			   �쐬���F2001.2.23
//
//	�P�D�@�\�T�v
//		�����}�`���ɑΉ����镡���}�`��ʂ̐ݒ�
//
//	�Q�D�C���^�[�t�F�[�X
//		BOOL SetLocFlg( LPCTSTR IN_Name)
//
//		����: �^			  ������			���e
//			  LPCTSTR		  IN_Name			Sfig Name
//
//		���A�l	
//			  ���펞�FTRUE		�����}�`���ɑΉ������ʂ���
//			  �ُ펞�FFALSE		�����}�`���ɑΉ������ʂȂ�
//
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.2.23	   ���X��(FQS)
//
//------------------------------------------------------------
BOOL SXFReadAP202ManagerC::SetLocFlg(LPCTSTR IN_Name)
{
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.08
/*
	for(int i=0;i<m_SymbolInfoTable.GetSize();i++){
		if (m_SymbolInfoTable[i].name == IN_Name){
			// �����}�`�z�u�׸ނ�ON
			m_SymbolInfoTable[i].locateflag = 1;
			return TRUE;
		}
	}
*/
	SXFSYMBOLINFO*	pValue ;
	if( m_SymbolInfoTable.Lookup(IN_Name, (void*&)pValue) ) {
		// �����}�`�z�u�׸ނ�ON
		pValue->locateflag = 1 ;
		return TRUE ;
	}
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.08
	return FALSE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFReadAP202ManagerC.cpp			   �쐬���F2001.2.23
//
//	�P�D�@�\�T�v
//		�n�b�`���O�̊O�`�E������ID����`����Ă��邩�`�F�b�N����
//
//	�Q�D�C���^�[�t�F�[�X
//		BOOL CheckHatchID( int IN_ID)
//
//		����: �^	������		���e
//			  int	IN_ID		ʯ�ݸނ̊O�`��������ID
//								(�����Ȑ��̱����غ���)
//
//		���A�l	
//			  ���펞�FTRUE		ʯ�ݸނ̊O�`����`����Ă���
//			  �ُ펞�FFALSE		ʯ�ݸނ̊O�`����`����Ă��Ȃ�
//		
//	�R�D����
//		����ԍ�	���t��		   �S����		�T�v
//		�쐬		2001.2.23	   ���X��(FQS)
//
//------------------------------------------------------------
BOOL SXFReadAP202ManagerC::CheckHatchID( int IN_ID){
	if (m_CurveAssemblyList == NULL)
		return FALSE;
	for(POSITION pos = m_CurveAssemblyList->GetHeadPosition();
				pos != NULL;m_CurveAssemblyList->GetNext(pos)){
		if (m_CurveAssemblyList->GetAt(pos)->AssemblyCode == IN_ID) {
			// ��������TRUE�ɂ���̂ł͂Ȃ��Aerror�ł��邩�ǂ��������ׂ�
			if (m_CurveAssemblyList->GetAt(pos)->error == 0) {
				return TRUE;
			}
			else {
				return FALSE;
			}
		}
	}
	return FALSE;
}

