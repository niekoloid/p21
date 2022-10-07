//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					�쐬���F2001.06.10
// 
//	�P�D�N���X�T�v
//		��`�e�[�u���f�[�^�l�ƒ�`�e�[�u��Mapping�Ǘ�
//		�I�u�W�F�N�g�̃A�h���X��ێ����A��`�e�[�u��
//		Mapping�Ǘ��I�u�W�F�N�g���Ǘ�����
//
//	�Q�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.10	   ���X��(FQS)
//
//------------------------------------------------------------
#include "stdafx.h"
#include <math.h>
#include "SXFDataStructC.h"
//#include "SXFSplitAP202C.h"
#include "SXFComncApi.h"
#include "SXFMapEntAConvC.h"
#include "SXFPreWidthTableC.h"
#include "SXFTableManagerC.h"
#include "SXFStruct.h"
#include "SXFTableMapManagerC.h"
#include "SXFPart21FileC.h"
#include "SXFErrorMsgC.h"
#include "SXF_EXT.h"
//#include "ComSplitStringC.h"
#include "SXFComncApi.h"
#include "SXFComInfoC.h"
#include "SXFPart21FileWriteC.h"
#include "SXFInstanceIDC.h"
//#include "SXFSplitFeatureC.h"
#include "SXFRGBTableC.h"
#include "SXFPreLineTypeTableC.h"
#include "SXFMapTableC.h"
#include "SXFComndef.h"
#include "SXFEntityDataC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					�쐬���F2001.06.10
//
//	�P�D�@�\�T�v
//		�N���X�\�z
//
//	�Q�D�C���^�[�t�F�[�X
//		void	SXFTableManagerC::SXFTableManagerC()
//	����:	�^								������				���e
//			�Ȃ�					
//
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.10	   ���X��(FQS)
//
//------------------------------------------------------------

SXFTableManagerC::SXFTableManagerC()
{
	m_LayerFirstFlag = TRUE;
	m_CurrentType=0;
	m_CurrentNumber=0;
	for(int i=0;i<10;i++)
		m_PreDefWidthFlagTable[i]=0;
	userdefwidthcode=11;		/* հ�ޒ�`�������ނ�11�` */

	// TableCode��HASH�p�ɒǉ��F
	m_TableCodeElemMapInitialized = FALSE;

//	ADD(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
	m_AP202IDTable.SetSize(0, 100) ;
//	ADD(E)	�`���[�j���O�Ή�	K.Naono	03.07.03

//	ADD(S)	Ver3.0�Ή�	K.Naono	04.01.30
	m_Attribute_Str = NULL ;
	m_id_draug_drw_rev = -1 ;
//	ADD(E)	Ver3.0�Ή�	K.Naono	04.01.30
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					�쐬���F2001.06.10
//
//	�P�D�@�\�T�v
//		�N���X�\�z
//
//	�Q�D�C���^�[�t�F�[�X
//	void SXFTableManagerC::SXFTableManagerC(SXFComInfoC* IN_CommonInfo)
//		
//	���� �F	�^				������			���e
//			SXFComInfoC*	IN_CommonInfo	���ʏ���޼ު��
//
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.10	   ���X��(FQS)
//
//------------------------------------------------------------
SXFTableManagerC::SXFTableManagerC(SXFComInfoC* IN_CommonInfo)
{
	m_ComInfo = IN_CommonInfo;
	m_LayerFirstFlag = TRUE;
	m_CurrentType=0;
	m_CurrentNumber=0;
	for(int i=0;i<10;i++)
		m_PreDefWidthFlagTable[i]=0;
	userdefwidthcode=11;

	// TableCode��HASH�p�ɒǉ��F
	m_TableCodeElemMapInitialized = FALSE;

//	ADD(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
	m_AP202IDTable.SetSize(0, 100) ;
//	ADD(E)	�`���[�j���O�Ή�	K.Naono	03.07.03

//	ADD(S)	Ver3.0�Ή�	K.Naono	04.01.30
	m_Attribute_Str = NULL ;
	m_id_draug_drw_rev = -1 ;
//	ADD(E)	Ver3.0�Ή�	K.Naono	04.01.30
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					�쐬���F2001.06.10
//
//	�P�D�@�\�T�v
//		�N���X�\�z
//
//	�Q�D�C���^�[�t�F�[�X
//	void SXFTableManagerC::SXFTableManagerC(SXFPart21FileC* IN_File)
//
//		
//	���� �F	�^					  ������				���e
//			SXFPart21FileC*		  IN_File			�t�@�C����
//
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.10	   ���X��(FQS)
//
//------------------------------------------------------------
SXFTableManagerC::SXFTableManagerC(SXFPart21FileC* IN_File)
{
	m_LayerFirstFlag = TRUE;
	m_File = IN_File;
	m_CurrentType=0;
	m_CurrentNumber=0;
	for(int i=0;i<10;i++)
		m_PreDefWidthFlagTable[i]=0;
	userdefwidthcode=11;		/* հ�ޒ�`�������ނ�11�` */

	// TableCode��HASH�p�ɒǉ��F
	m_TableCodeElemMapInitialized = FALSE;

//	ADD(S)	Ver3.0�Ή�	K.Naono	04.01.30
	m_Attribute_Str = NULL ;
	m_id_draug_drw_rev = -1 ;
//	ADD(E)	Ver3.0�Ή�	K.Naono	04.01.30
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					�쐬���F2001.06.10
//
//	�P�D�@�\�T�v
//		�N���X�\�z
//
//	�Q�D�C���^�[�t�F�[�X
//	void SXFTableManagerC::SXFTableManagerC(
//								SXFPart21FileC* IN_File,	
//								SXFComInfoC* IN_CommonInfo,
//								SXFPart21FileWriteC* IN_WriteFile,
//								SXFInstanceIDC* IN_InstanceIDManager)
//
//		
//	���� �F	�^					  ������				���e
//			SXFPart21FileC* 	  IN_File				̧�ٵ�޼ު�Ă̱��ڽ
//			SXFComInfoC*		  IN_CommonInfo			���ʏ���޼ު�Ă̱��ڽ
//			SXFPart21FileWriteC*  IN_WriteFile			̧�ُo�͵�޼ު�Ă̱��ڽ
//			SXFInstanceIDC*		  IN_InstanceIDManager	�ݽ�ݽID��޼ު�Ă̱��ڽ
//
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.10	   ���X��(FQS)
//
//------------------------------------------------------------
SXFTableManagerC::SXFTableManagerC(SXFPart21FileC* IN_File,
					SXFComInfoC* IN_CommonInfo,
					SXFPart21FileWriteC* IN_WriteFile,
					SXFInstanceIDC* IN_InstanceIDManager)
{
	m_File = IN_File;
	m_WriteFile= IN_WriteFile;
	m_ComInfo=IN_CommonInfo;
	m_InstanceIDManager=IN_InstanceIDManager;
	m_LayerFirstFlag = TRUE;
	m_CurrentType=0;
	m_CurrentNumber=0;
	for(int i=0;i<10;i++)
		m_PreDefWidthFlagTable[i]=0;
	userdefwidthcode=11;		/* հ�ޒ�`�������ނ�11�` */

	// TableCode��HASH�p�ɒǉ��F
	m_TableCodeElemMapInitialized = FALSE;

//	ADD(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
	m_AP202IDTable.SetSize(0, 100) ;
//	ADD(E)	�`���[�j���O�Ή�	K.Naono	03.07.03

//	ADD(S)	Ver3.0�Ή�	K.Naono	04.01.30
	m_Attribute_Str = NULL ;
	m_id_draug_drw_rev = -1 ;
//	ADD(E)	Ver3.0�Ή�	K.Naono	04.01.30
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					�쐬���F2001.06.10
//
//	�P�D�@�\�T�v
//		�N���X�\�z
//
//	�Q�D�C���^�[�t�F�[�X
//SXFTableManagerC::SXFTableManagerC(SXFComInfoC* IN_CommonInfo
//									SXFInstanceIDC* IN_InstanceIDManager)
//
//		
//	���� �F	�^					  ������				���e
//			SXFComInfoC*		  IN_CommonInfo			���ʏ���޼ު�Ă̱��ڽ
//			SXFInstanceIDC*		  IN_InstanceIDManager	�ݽ�ݽID��޼ު�Ă̱��ڽ
//
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.10	   ���X��(FQS)
//
//------------------------------------------------------------
SXFTableManagerC::SXFTableManagerC(SXFComInfoC* IN_CommonInfo,SXFInstanceIDC* IN_InstanceIDManager){
	m_File = NULL;
	m_WriteFile= NULL;
	m_ComInfo=IN_CommonInfo;
	m_InstanceIDManager=IN_InstanceIDManager;
	m_LayerFirstFlag = TRUE;
	m_CurrentType=0;
	m_CurrentNumber=0;
	for(int i=0;i<10;i++)
		m_PreDefWidthFlagTable[i]=0;
	userdefwidthcode=11;		/* հ�ޒ�`�������ނ�11�` */

	// TableCode��HASH�p�ɒǉ��F
	m_TableCodeElemMapInitialized = FALSE;

//	ADD(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
	m_AP202IDTable.SetSize(0, 100) ;
//	ADD(E)	�`���[�j���O�Ή�	K.Naono	03.07.03

//	ADD(S)	Ver3.0�Ή�	K.Naono	04.01.30
	m_Attribute_Str = NULL ;
	m_id_draug_drw_rev = -1 ;
//	ADD(E)	Ver3.0�Ή�	K.Naono	04.01.30
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					�쐬���F2001.06.10
//
//	�P�D�@�\�T�v
//		�N���X����
//
//	�Q�D�C���^�[�t�F�[�X
//	void	SXFTableManagerC::~SXFTableManagerC()
//	����:	�^						������				���e
//			�Ȃ�					
//
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.10	   ���X��(FQS)
//
//------------------------------------------------------------

SXFTableManagerC::~SXFTableManagerC()
{

	//delete mapping class in layer table
	for(int i=0;i<m_LayerTable.GetSize();i++){
		if(m_LayerTable[i].m_MappingManager!=NULL)
			delete m_LayerTable[i].m_MappingManager;
	}

	//delete mapping class in predefcolor table
	for( i=0;i<16;i++){
		if(m_PreDefColorTable[i].m_MappingManager!=NULL)
			delete m_PreDefColorTable[i].m_MappingManager;
	}

	//delete mapping class in userdefcolor table
	for( i=0;i<m_UserDefColorTable.GetSize();i++){
		if(m_UserDefColorTable[i].m_MappingManager!=NULL)
			delete m_UserDefColorTable[i].m_MappingManager;
	}

	//delete mapping class in predeffont table
	for( i=0;i<16;i++){
		if(m_PreDefFontTable[i].m_MappingManager!=NULL)
			delete m_PreDefFontTable[i].m_MappingManager;
	}

	//delete mapping class in userdeffont table
	for( i=0;i<m_UserDefFontTable.GetSize();i++){
		if(m_UserDefFontTable[i].m_MappingManager!=NULL)
			delete m_UserDefFontTable[i].m_MappingManager;
	}

	//delete mapping class in width table
	for(i=0;i<16;i++){
		if(m_WidthTable[i].m_MappingManager!=NULL)
			delete m_WidthTable[i].m_MappingManager;
	}

	//delete mapping class in textfont table
	for(i=0;i<m_TextFontTable.GetSize();i++){
		if(m_TextFontTable[i].m_MappingManager!=NULL)
			delete m_TextFontTable[i].m_MappingManager;
	}

	for(i=0;i<m_PresentationSizeTable.GetSize();i++){
		if(m_PresentationSizeTable[i]!=NULL)
			delete m_PresentationSizeTable[i];
	}

	for(i=0;i<m_SheetTitleTable.GetSize();i++){
		if(m_SheetTitleTable[i]!=NULL)
			delete m_SheetTitleTable[i];
	}

//	ADD(S)	Ver3.0�Ή�	K.Naono	04.01.30
	if( m_Attribute_Str != NULL )
		delete m_Attribute_Str ;

	for(i = 0; i < m_AttributeTable.GetSize(); i++) {
		delete m_AttributeTable[i] ;
	}
	m_AttributeTable.RemoveAll() ;

	m_id_draug_drw_rev = -1 ;
//	ADD(E)	Ver3.0�Ή�	K.Naono	04.01.30
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					�쐬���F2001.06.10
//
//	�P�D�@�\�T�v
//		Table �v�f�̍\���̂�o�^����
//		
//	�Q�D�C���^�[�t�F�[�X
//		int RegisterStructTable( int IN_Type, LPVOID IN_Struct)
//
//		����: �^			  ������				���e
//			  int			  IN_Type			   �\���̂�Type
//			  LPVOID		  IN_Struct			   �\���̂̃A�h���X
//													
//		
//		���A�l	
//			  ���펞�F Table �v�f��Code
//			  �ُ펞�F -1
//
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.10	   ���X��(FQS)
//
//------------------------------------------------------------
int SXFTableManagerC::RegisterStructTable( int IN_Type, LPVOID IN_Struct)
{
	int return_code;
	SXFTableMapManagerC* mappingmanager; 
	SXFLayerC layer;
	SXFPreDefColorC predefcolor;
	SXFUserDefColorC userdefcolor;
	SXFPreDefFontC predeffont;
	SXFUserDefFontC userdeffont;
	SXFWidthC width;
	double inwidth;
	int resaultcode;
	SXFTextFontC textfont;
	int i = 0;
	INT_PTR layersize;
	INT_PTR usercolorsize;
	INT_PTR userfontsize;
	INT_PTR textfontsize;
	double eps1,eps2;
	CString tmp_font_name;
	CString decent_tmp;
	CString ascent_tmp;
	double ascent = 1.0;
	double decent = 0.0;
	int find1,find2;

	switch(IN_Type)
	{
	/** ���C�� **/
	case 1:
		if (m_LayerFirstFlag){
			//�����}�`�z�u�p�̃��C���O���쐬
			layer.m_Code = 0;
			layer.m_Name = "$$SXF_dummy_layer_for_subfigure";
			layer.m_LfFlag = 1;
			mappingmanager = new SXFTableMapManagerC(m_File,m_ComInfo,m_WriteFile,m_InstanceIDManager);
			layer.m_MappingManager = mappingmanager;
			m_LayerTable.Add(layer);
			m_LayerFirstFlag = FALSE;
		}
		/* ڲ�ð��ٻ��� */
		layersize = m_LayerTable.GetSize();
		/* �ő�ڲԐ��𒴂����Ƃ� */
		if (layersize > MAXLAYER){// max layer code = 1024 
			SXFErrorMsgC::RecordError(SXFMAXLAYER,DEF_LAYER,0);
			return SXFMAXLAYER;
		}
		/* ڲԺ��� */
		layer.m_Code = (int)layersize;
		/* ڲԖ� */
		layer.m_Name = ((Layer_Struct*)IN_Struct)->name;
		/* �\���^��\���׸� */
		layer.m_LfFlag = ((Layer_Struct*)IN_Struct)->lflag;
		/* ��`ð��ٗv�fMapping�Ǘ���޼ު�Đ��� */
		mappingmanager = new SXFTableMapManagerC(m_File,m_ComInfo,m_WriteFile,m_InstanceIDManager);
		/* ���A�l(ڲԺ���) */
		return_code = layer.m_Code;
		/* ��`ð��ٗv�fMapping�Ǘ���޼ު�ľ�� */
		layer.m_MappingManager = mappingmanager;
		/* ڲ�ð��قɒǉ� */
		m_LayerTable.Add(layer);
		break;
	/** ����`�F **/
	case 2://predefcolor 16
		//����`�łȂ����O�̓G���[
		if (!predefcolor.SetName(((Predefined_Colour_Struct*)IN_Struct)->name)){
			SXFErrorMsgC::RecordError(SXFNOTPRECOLOUR,DEF_PREDEFINED_COLOUR,1,((Predefined_Colour_Struct*)IN_Struct)->name);
			return SXFNOTPRECOLOUR;
		}
		/* ��`ð��ٗv�fMapping�Ǘ���޼ު�Đ��� */
		mappingmanager = new SXFTableMapManagerC(m_File,m_ComInfo,m_WriteFile,m_InstanceIDManager);
		/* ����`�F�\���̾�� */
		if (mappingmanager->SetStructPrecolor(IN_Type,IN_Struct,predefcolor)){
			predefcolor.m_MappingManager=mappingmanager;
			/* ����`�F�ݽ�ݽ�o�� */
			return_code = predefcolor.m_Code;
			mappingmanager->WriteInstance(IN_Type);
			predefcolor.m_ID = mappingmanager->GetInstanceID(IN_Type);
			m_PreDefColorTable[predefcolor.m_Code-1] = predefcolor;
		}
		else
			/* �o�͎��s */
			return_code = -1;
		break;
	/** ���[�U��`�F **/
	case 3:
		/* հ�ޒ�`�Fð��ٻ��� */
		usercolorsize = m_UserDefColorTable.GetSize();
		///ERROR
		//���[�U��`��240�F������`�ł��Ȃ��B
		if (usercolorsize >= MAXUSERCOLOUR){
			SXFErrorMsgC::RecordError(SXFMAXUSERCOLOUR,DEF_USERDEFINED_COLOUR,0);
			return SXFMAXUSERCOLOUR;
		}
		else{
			/* ��`ð��ٗv�fMapping�Ǘ���޼ު�� */
			mappingmanager = new SXFTableMapManagerC(m_File,m_ComInfo,m_WriteFile,m_InstanceIDManager);
			/* �F���� */
			userdefcolor.m_Code = (int)(usercolorsize+17);//17------
			userdefcolor.R =((Userdefined_Colour_Struct*)IN_Struct)->red;
			userdefcolor.G =((Userdefined_Colour_Struct*)IN_Struct)->green;
			userdefcolor.B =((Userdefined_Colour_Struct*)IN_Struct)->blue;
			/* հ�ޒ�`�F�\���̾�� */
			if (mappingmanager->SetStructData(IN_Type,IN_Struct)){
				usercolorsize = m_UserDefColorTable.GetSize();
				userdefcolor.m_MappingManager=mappingmanager;
				/* հ�ޒ�`�F�ݽ�ݽ�o�� */
				return_code = userdefcolor.m_Code;
				mappingmanager->WriteInstance(IN_Type);
				userdefcolor.m_ID = mappingmanager->GetInstanceID(IN_Type);
				m_UserDefColorTable.Add(userdefcolor);
			}
			else
				/* �o�͎��s */
				return_code = -1;
		}
		break;
	/** ����`���� **/
	case 4://predeffont
		//����`�łȂ����O�̓G���[
		if (!predeffont.SetName(((Predefined_Linetype_Struct*)IN_Struct)->name)){
			SXFErrorMsgC::RecordError(SXFNOTPRETYPE,DEF_PREDEFINED_LINETYPE,1,((Predefined_Linetype_Struct*)IN_Struct)->name);
			return SXFNOTPRETYPE;
		}
		/* ��`ð��ٗv�fMapping�Ǘ���޼ު�Đ��� */
		mappingmanager = new SXFTableMapManagerC(m_File,m_ComInfo,m_WriteFile,m_InstanceIDManager);
		/* ����`����\���̾�� */
		if (mappingmanager->SetStructData(IN_Type,IN_Struct)){
			predeffont.m_MappingManager=mappingmanager;
			/* ����`����ݽ�ݽ�o�� */
			return_code = predeffont.m_Code;
			mappingmanager->WriteInstance(IN_Type);
			predeffont.m_ID = mappingmanager->GetInstanceID(IN_Type);
			/* ����`����ð��ْǉ� */
			m_PreDefFontTable[predeffont.m_Code-1] = predeffont;
		}
		else
			/* �o�͎��s */
			return_code = -1;
		break;
	/** ���[�U��`���� **/
	case 5:
		/* հ�ޒ�`����ð��ٻ��� */
		userfontsize = m_UserDefFontTable.GetSize();
		///ERROR
		//���[�U��`�����32������`�ł��Ȃ��B
		if (userfontsize >= MAXUSERLINETYPE){
			SXFErrorMsgC::RecordError(SXFMAXUSERLINETYPE,DEF_USERDEFINED_LINETYPE,0);
			return SXFMAXUSERLINETYPE;
		}
		else{
			/* ������ */
			userdeffont.m_Code = (int) m_UserDefFontTable.GetSize()+17;//17---
			/* ���햼 */
			userdeffont.m_Name = ((Userdefined_Linetype_Struct*)IN_Struct)->name;
			/* �����Đ� */
			userdeffont.m_Segment=((Userdefined_Linetype_Struct*)IN_Struct)->segment;
			/* �߯� */
			for(i=0;i<userdeffont.m_Segment;i++)
				userdeffont.m_Pitch.Add( ((Userdefined_Linetype_Struct*)IN_Struct)->pitch[i] );
			/* ��`ð��ٗv�fMapping�Ǘ���޼ު�Đ��� */
			mappingmanager = new SXFTableMapManagerC(m_File,m_ComInfo,m_WriteFile,m_InstanceIDManager);
			/* հ�ޒ�`����\���̾�� */
			if (mappingmanager->SetStructData(IN_Type,IN_Struct)){
				/* ��`ð��ٗv�fMapping�Ǘ���޼ު�ľ�� */
				userdeffont.m_MappingManager=mappingmanager;
				/* հ�ޒ�`����ݽ�ݽ�o�� */
				return_code = userdeffont.m_Code;
				mappingmanager->WriteInstance(IN_Type);
				/* �ݽ�ݽID */
				userdeffont.m_ID = mappingmanager->GetInstanceID(IN_Type);
				/* հ�ޒ�`����ð��ْǉ� */
				m_UserDefFontTable.Add(userdeffont);
			}
			else
				/* �o�͎��s */
				return_code = -1;
		}
		break;
	/** ���� **/
	case 6:
		/* ���� */
		inwidth = ((Line_Width_Struct*)IN_Struct)->width;
		/* ���e�덷�擾 */
		m_ComInfo->Get_Tolerance(eps1,eps2);
		/* ��������������ނ����߂� */
		resaultcode = width.InquireCode(inwidth,eps1);
		/* �����ɑΉ�����������ނ�����(����`) */
		if(resaultcode != 0){
			/* ����ð��ٓ��ɂ��� */
			if(m_PreDefWidthFlagTable[resaultcode-1] == 1){
				SXFErrorMsgC::RecordError(SXFSAMEWIDTH,DEF_LINE_WIDTH,1,inwidth);
				return TRUE;//FALSE�͕Ԃ��Ȃ�
			}

			/* �������� */
			width.m_Code = resaultcode;
			SXFPreWidthTableC prewidthtable;
			double prewidth = 0.0;
			/* �������ނ���������擾 */
			prewidthtable.GetPreWidth(resaultcode, prewidth); 
			width.m_Width = prewidth;
			/* ��`�ς��׸ނ�ON */
			m_PreDefWidthFlagTable[resaultcode-1]=1;
		}
		//�����ɑΉ�����R�[�h���O�̂Ƃ��͊���`�ł͂Ȃ��B
		else{
			//�������P�U�ȏ�o�^����Ă����
			//����ȏ�o�^�ł��Ȃ��̂ŁA�G���[
			if (userdefwidthcode > MAXLINEWIDTH){//widthcode 1---16
				SXFErrorMsgC::RecordError(SXFMAXLINEWIDTH,DEF_LINE_WIDTH,0);
				return SXFMAXLINEWIDTH;
			}
			else{
				/* �������� */
				width.m_Code = userdefwidthcode;
				userdefwidthcode++;
			}
			/* ���� */
			width.m_Width=inwidth;
		}
		/* ��`ð��ٗv�fMapping�Ǘ���޼ު�Đ��� */
		mappingmanager = new SXFTableMapManagerC(m_File,m_ComInfo,m_WriteFile,m_InstanceIDManager);
		/* �����\���̾�� */
		if (mappingmanager->SetStructData(IN_Type,IN_Struct)){
			width.m_MappingManager=mappingmanager;
			/* ���A�l(��������) */
			return_code = width.m_Code;
			/* �����ݽ�ݽ�o�� */
			mappingmanager->WriteInstance(IN_Type);
			/* ��`ð��ٗv�fMapping�Ǘ���޼ު�ľ�� */
			width.m_ID = mappingmanager->GetInstanceID(IN_Type);
			m_WidthTable[width.m_Code-1] = width;
		}
		else
			/* �o�͎��s */
			return_code = -1;
		break;
	/** �����t�H���g **/
	case 7://textfont
		//ERROR
		//�����t�H���g�͂P�O�Q�S�����o�^�ł��Ȃ�
		textfontsize = m_TextFontTable.GetSize();
		if (textfontsize >= MAXTEXTFONT){//textfont 1--1024
			SXFErrorMsgC::RecordError(SXFMAXTEXTFONT,DEF_TEXT_FONT,0);
			return SXFMAXTEXTFONT;
		}
		else{
			/* ����̫�Ė� */
			textfont.m_Name = ((Text_Font_Struct*)IN_Struct)->name;//
			if ((find1 = textfont.m_Name.ReverseFind('-')) != -1){
				tmp_font_name = textfont.m_Name.Left(find1);
				decent_tmp = textfont.m_Name.Mid(find1+1);
				if ((find2 = tmp_font_name.ReverseFind('-')) != -1){
					ascent_tmp = tmp_font_name.Mid(find2+1);
					ascent = atof(ascent_tmp);
					decent = atof(decent_tmp);
				}
			}
			textfont.m_Ascent = ascent;
			textfont.m_Decent = decent;
			/* ����̫�ĺ��� */
			textfont.m_Code = (int)m_TextFontTable.GetSize()+1;
			/* ��`ð��ٗv�fMapping�Ǘ���޼ު�Đ��� */
			mappingmanager = new SXFTableMapManagerC(m_File,m_ComInfo,m_WriteFile,m_InstanceIDManager);
			/* ����̫�č\���̾�� */
			if (mappingmanager->SetStructData(IN_Type,IN_Struct)){
				/* ��`ð��ٗv�fMapping�Ǘ���޼ު�ľ�� */
				textfont.m_MappingManager=mappingmanager;
				/* ����̫�ĺ��� */
				return_code = textfont.m_Code;
				/* ����̫�Ĳݽ�ݽ�o�� */
				mappingmanager->WriteInstance(IN_Type);
				textfont.m_ID = mappingmanager->GetInstanceID(IN_Type);
				/* ����̫��ð��قɒǉ� */
				m_TextFontTable.Add(textfont);
			}
			else
				return_code = -1;
		}
		break;
	default:
		return_code = -1;
		break;
	}

	return return_code;
}
//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					�쐬���F2001.06.10
//
//	�P�D�@�\�T�v
//		�w�肵��Table�v�f��Code�ƑΉ������Instance ID���擾����
//		
//	�Q�D�C���^�[�t�F�[�X
//		int GetID(int IN_Type, int IN_Code)
//
//		����: �^			  ������				���e
//			  int			  IN_Type			   Table�v�f��Type
//			  int			  IN_Code			   Table�v�f��Code
//													
//		
//		���A�l	
//			  ���펞�F Table �v�f��Instance ID
//			  �ُ펞�F -1
//
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.10	   ���X��(FQS)
//
//------------------------------------------------------------
int SXFTableManagerC::GetID(int IN_Type, int IN_Code)
{
	if(IN_Code<1)  //code must >=1
		return -1;

	int getid=-1;
	int RW_Flag = -1;
	/* �Ǐ����׸ގ擾 */
	m_ComInfo->Get_RWFlag(RW_Flag);

	switch (IN_Type)
	{
	case 1://layer
		if(IN_Code>=m_LayerTable.GetSize())
			return -1;//layer code not register
		getid = m_LayerTable[IN_Code].m_LfFlag;//�e�[�u���ɓo�^����Ă��Ȃ���Ώ����l-�P
		break;
	case 2://predefcolor
		if(IN_Code>16)
			return -1;//predefcolor must <= 16
		getid = m_PreDefColorTable[IN_Code-1].m_ID;
		break;
	case 3://userdefcolor
		if(IN_Code<17 || IN_Code>=m_UserDefColorTable.GetSize()+17)
			return -1;//userdefcolor code must 17---256
		//or user def color not register
		getid=m_UserDefColorTable[IN_Code-17].m_ID;
		break;
	case 4://predeffont
		if(IN_Code>16)
			return -1;//predeffont code must <=16
		getid = m_PreDefFontTable[IN_Code-1].m_ID;
		break;
	case 5://userdeffont
		if(IN_Code<17 || IN_Code>=m_UserDefFontTable.GetSize()+17)
			return -1;//user def font code 17---32
		//or user def font not register
		getid = m_UserDefFontTable[IN_Code-17].m_ID;
		break;
	case 6://width
		if(IN_Code>16)
			return -1;//width code 1--16
		getid=m_WidthTable[IN_Code-1].m_ID;
		break;
	case 7://textfont
		if(IN_Code>m_TextFontTable.GetSize())
			return -1;//text font must 1--1024
		//text font not register
		getid=m_TextFontTable[IN_Code-1].m_ID;
		break;
	default:
		break;
	}
	return getid;//-1:error, ID:OK
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					�쐬���F2001.06.10
//
//	�P�D�@�\�T�v
//		�w�肵��Table�v�f��Instance ID�ƑΉ������Code���擾����
//		
//	�Q�D�C���^�[�t�F�[�X
//		int GetCode(int IN_Type, int IN_ID)
//
//		����: �^			  ������				���e
//			  int			  IN_Type			   Table�v�f��Type
//			  int			  IN_ID				   Table�v�f��Instance ID
//													
//		
//		���A�l	
//			  ���펞�F Table �v�f�� Code
//			  �ُ펞�F -1
//
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.10	   ���X��(FQS)
//
//------------------------------------------------------------

int SXFTableManagerC::GetCode(int IN_Type, int IN_ID)
{
	int getcode=-1;
	int i = 0;
	switch (IN_Type)
	{
	case 1://layer
		for(i=0;i<m_LayerTable.GetSize();i++){
			if(m_LayerTable[i].m_ID == IN_ID){
				getcode=i;
				return getcode;
			}
		}
		break;//layer ID not register
	case 2://predefcolor
		for(i=0;i<16;i++){
			if(m_PreDefColorTable[i].m_ID == IN_ID){
				getcode = i+1;
				return getcode;
			}
		}
		break;//predefcolot ID not register
	case 3://userdefcolor
		for(i=0;i<m_UserDefColorTable.GetSize();i++){ //0---(256-16)
			if(m_UserDefColorTable[i].m_ID == IN_ID){
				getcode = i+16+1;
				return getcode;
			}
		}
		break;//userdefcolor ID not register
	case 4://predeffont
		for(i=0;i<16;i++){
			if(m_PreDefFontTable[i].m_ID == IN_ID){
				getcode = i+1;
				return getcode;
			}
		}
		break;//predeffont not register
	case 5://userdeffont
		for(i=0;i<m_UserDefFontTable.GetSize();i++){//0----(32-16)
			if(m_UserDefFontTable[i].m_ID == IN_ID){
				getcode = i+16+1;
				return getcode;
			}
		}
		break;//userdeffont not register
	case 6://width
		for(i=0;i<16;i++){
			if(m_WidthTable[i].m_ID == IN_ID){
				getcode = i+1;
				return getcode;
			}
		}
		break;
	case 7://textfont
		for(i=0;i<m_TextFontTable.GetSize();i++){
			if(m_TextFontTable[i].m_ID == IN_ID){
				getcode = i+1;
				return getcode;
			}
		}
		break;
	default:
		break;
	}

	return getcode;//-1:error,Code:OK

}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					�쐬���F2001.06.10
//
//	�P�D�@�\�T�v
//		�w�肵��Layer�v�f��ElementTable��Element�v�f��o�^����
//		
//	�Q�D�C���^�[�t�F�[�X
//		BOOL SetLayerElement(int IN_LayerCode, int IN_ElementID)
//
//		����: �^			  ������				���e
//			  int			  IN_LayerCode		   Layer�v�f��Code
//			  int			  IN_ElementID		   Layer�v�f��Element�v�f��
//												   Instance ID
//													
//		
//		���A�l	
//			  ���펞�F TRUE
//			  �ُ펞�F FALSE
//		
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.10	   ���X��(FQS)
//
//------------------------------------------------------------

BOOL SXFTableManagerC::SetLayerElement(int IN_LayerCode, int IN_ElementID)
{
	if(IN_LayerCode>m_LayerTable.GetSize()-1){
		//error layercode is not register
		return FALSE;
	}

	m_LayerTable[IN_LayerCode].m_Element.Add(IN_ElementID);

	return TRUE;
}
//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					�쐬���F2001.06.10
//
//	�P�D�@�\�T�v
//		�S����Layer�v�f��Sheet ID��o�^����
//		
//	�Q�D�C���^�[�t�F�[�X
//		BOOL SetLayerSheetID( int IN_SheetID)
//
//		����: �^			  ������				���e
//			  int			  IN_SheetID		   Sheet�v�f
//												   Instance ID
//													
//		
//		���A�l	
//			  ���펞�F TRUE
//			  �ُ펞�F FALSE
//		
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.10	   ���X��(FQS)
//
//------------------------------------------------------------

BOOL SXFTableManagerC::SetLayerSheetID( int IN_SheetID)
{

	for(int i=0;i<m_LayerTable.GetSize();i++){
		m_LayerTable[i].m_SheetID = IN_SheetID;
	}
	return TRUE;
}
//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					�쐬���F2001.06.10
//
//	�P�D�@�\�T�v
//		�w�肵����Text Font�̑������擾����
//		
//	�Q�D�C���^�[�t�F�[�X
//		BOOL GetTextFontProperty(int IN_Code, 
//								 double& OUT_Ascent,
//								 double& OUT_Decent)
//
//		����: �^			  ������				���e
//			  int			  IN_Code			   Text Font�v�f��
//												   Code
//			  double&		  OUT_Ascent		   Ascent����
//			  double&		  OUT_Decent		   Decent����
//													
//		
//		���A�l	
//			  ���펞�F TRUE
//			  �ُ펞�F FALSE
//		
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.10	   ���X��(FQS)
//
//------------------------------------------------------------

BOOL SXFTableManagerC::GetTextFontProperty(int IN_Code, 
											double& OUT_Ascent,
											double& OUT_Decent)
{
	if(IN_Code<1)  //code must >=1
		return FALSE;
	if(IN_Code>m_TextFontTable.GetSize()){
		//error, textfont code is not register
		return FALSE;
	}

	OUT_Ascent = m_TextFontTable[IN_Code-1].m_Ascent;
	OUT_Decent = m_TextFontTable[IN_Code-1].m_Decent;

	return TRUE;

}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					�쐬���F2001.06.10
//
//	�P�D�@�\�T�v
//		�w�肵��Layer Name����`����Ă��邩�`�F�b�N
//		
//	�Q�D�C���^�[�t�F�[�X
//		BOOL CheckSameLayer( LPCTSTR IN_Name)
//
//		����: �^			  ������				���e
//			  LPCTSTR		 IN_Name			   Layer Name						 
//		
//		���A�l	
//			  ���펞�F TRUE
//			  �ُ펞�F FALSE
//		
//
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.10	   ���X��(FQS)
//
//------------------------------------------------------------

BOOL SXFTableManagerC::CheckSameLayer( LPCTSTR IN_Name)
{
	for(int i=0;i<m_LayerTable.GetSize();i++){
		if(IN_Name == m_LayerTable[i].m_Name)
			return FALSE;
	}

	return TRUE;
}
//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					�쐬���F2001.06.10
//
//	�P�D�@�\�T�v
//		�w�肵��PreDefColor Name����`����Ă��邩�`�F�b�N
//		
//	�Q�D�C���^�[�t�F�[�X
//		BOOL CheckSamePreDefColor( LPCTSTR IN_Name)
//
//		����: �^			  ������				���e
//			  LPCTSTR		 IN_Name			   PreDefColor Name						   
//		
//		���A�l	
//			  ���펞�F TRUE
//			  �ُ펞�F FALSE
//		
//	�Q�D�C���^�[�t�F�[�X
//
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.10	   ���X��(FQS)
//
//------------------------------------------------------------
BOOL SXFTableManagerC::CheckSamePreDefColor( LPCTSTR IN_Name)
{
	for(int i=0;i<16;i++){
		if(IN_Name == m_PreDefColorTable[i].m_Name)
			return FALSE;
	}

	return TRUE;
}
//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					�쐬���F2001.06.10
//
//	�P�D�@�\�T�v
//		�w�肵��PreDefFont Name����`����Ă��邩�`�F�b�N
//		
//	�Q�D�C���^�[�t�F�[�X
//		BOOL CheckSamePreDefFont( LPCTSTR IN_Name)
//
//		����: �^			  ������				���e
//			  LPCTSTR		 IN_Name			   PreDefFont Name						  
//		
//		���A�l	
//			  ���펞�F TRUE
//			  �ُ펞�F FALSE
//		
//
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.10	   ���X��(FQS)
//
//------------------------------------------------------------
BOOL SXFTableManagerC::CheckSamePreDefFont( LPCTSTR IN_Name)
{
	for(int i=0;i<16;i++){
		if(IN_Name == m_PreDefFontTable[i].m_Name)
			return FALSE;
	}
	return TRUE;
}
//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					�쐬���F2001.06.10
//
//	�P�D�@�\�T�v
//		�w�肵��PreDefFont Name����`����Ă��邩�`�F�b�N
//		
//	�Q�D�C���^�[�t�F�[�X
//		BOOL CheckSameUserDefFont( LPCTSTR IN_Name)
//
//		����: �^			  ������				���e
//			  LPCTSTR		 IN_Name			   UserDefFont Name						   
//		
//		���A�l	
//			  ���펞�F TRUE
//			  �ُ펞�F FALSE
//		
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.10	   ���X��(FQS)
//
//------------------------------------------------------------
BOOL SXFTableManagerC::CheckSameUserDefFont( LPCTSTR IN_Name)
{
	for(int i=0;i<m_UserDefFontTable.GetSize();i++){
		if(IN_Name == m_UserDefFontTable[i].m_Name)
			return FALSE;
	}

	return TRUE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					�쐬���F2001.06.10
//
//	�P�D�@�\�T�v
//		�w�肵��Width�l����`����Ă��邩�`�F�b�N
//		
//	�Q�D�C���^�[�t�F�[�X
//		BOOL CheckSameWidth( double IN_Width)
//
//		����: �^			  ������				���e
//			  double		 IN_Width			   Width�l						  
//		
//		���A�l	
//			  ���펞�F TRUE
//			  �ُ펞�F FALSE
//
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.10	   ���X��(FQS)
//
//------------------------------------------------------------
BOOL SXFTableManagerC::CheckSameWidth( double IN_Width)
{
	double eps,angle_eps;
	m_ComInfo->Get_Tolerance(eps,angle_eps);

	SXFPreWidthTableC prewidthtable;

	int code = prewidthtable.GetCode(IN_Width,eps);

	if(m_PreDefWidthFlagTable[code-1] == 1){
		return FALSE;
	}

	return TRUE;
}
//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					�쐬���F2001.06.10
//
//	�P�D�@�\�T�v
//		�w�肵��TextFont����`����Ă��邩�`�F�b�N
//		
//	�Q�D�C���^�[�t�F�[�X
//		BOOL CheckSameTextFont( LPCTSTR IN_Name)
//
//		����: �^			  ������				���e
//			  LPCTSTR		 IN_Name				TextFont Name						 
//		
//		���A�l	
//			  ���펞�F TRUE
//			  �ُ펞�F FALSE
//		
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.10	   ���X��(FQS)
//
//------------------------------------------------------------

BOOL SXFTableManagerC::CheckSameTextFont( LPCTSTR IN_Name)
{
	for(int i=0;i<m_TextFontTable.GetSize();i++){
		if(IN_Name == m_TextFontTable[i].m_Name)
			return FALSE;
	}

	return TRUE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					�쐬���F2001.06.10
//
//	�P�D�@�\�T�v
//		�o�^����Layer�v�f��Mapping����
//		
//	�Q�D�C���^�[�t�F�[�X
//		BOOL  LayerMapping()
//
//		����: �^			  ������				���e
//				�Ȃ�
//		
//		���A�l	
//			  ���펞�F TRUE
//			  �ُ펞�F FALSE
//		
//		
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.10	   ���X��(FQS)
//
//------------------------------------------------------------
BOOL  SXFTableManagerC::LayerMapping()
{
	for(int i=0;i<m_LayerTable.GetSize();i++){
		if (m_LayerTable[i].m_MappingManager->SetStructLayer(&m_LayerTable[i])){
			m_LayerTable[i].m_MappingManager->WriteInstance(1);
			if (m_LayerTable[i].m_LfFlag == 0){
				m_LayerTable[i].m_ID = m_LayerTable[i].m_MappingManager->GetInstanceID(1);
				m_InvisibilityLayerTable.Add(m_LayerTable[i].m_ID);
			}
		}
	}
	return TRUE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					�쐬���F2001.06.10
//
//	�P�D�@�\�T�v
//		�o�^����Invisibility�v�f��Mapping����
//		
//	�Q�D�C���^�[�t�F�[�X
//		BOOL MappingInvisibility()
//
//		����: �^			  ������				���e
//				�Ȃ�
//
//		���A�l	
//			  ���펞�F TRUE
//			  �ُ펞�F FALSE
//		
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.10	   ���X��(FQS)
//
//------------------------------------------------------------
BOOL SXFTableManagerC::MappingInvisibility()
{

	if (m_InvisibilityLayerTable.GetSize() > 0){
		SXFTableMapManagerC* mappingmanager = new SXFTableMapManagerC(m_File,
													m_ComInfo,m_WriteFile,
													m_InstanceIDManager); 
		if( !mappingmanager->MappingInvisibility(&m_InvisibilityLayerTable)) {
			delete mappingmanager;
			return FALSE;
		}
		delete mappingmanager;
		return TRUE;
	}
	else
		return FALSE;

}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					�쐬���F2001.06.10
//
//	�P�D�@�\�T�v
//		�Ǘ�Table����o�^����Table�v�f������o�͂���
//
//	�Q�D�C���^�[�t�F�[�X
//		int GetTableElement(int IN_Type,
//							LPVOID& OUT_Struct,
//							int& OUT_EndFlg)
//
//		����: �^			  ������				���e
//			  int			 IN_Type			   Table�v�f��Type
//			  LPVOID&		 OUT_Struct			   Table�v�f�̍\����
//												   �̃A�h���X
//			  int&			 OUT_EndFlg			   �Ō�̗v�f��Flag
//													1:�Ō�̗v�f
//													0:����
//
//		���A�l	
//			  ���펞�F Table�v�f��Code
//			  �ُ펞�F -1
//
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.10	   ���X��(FQS)
//
//------------------------------------------------------------
int SXFTableManagerC::GetTableElement(int IN_Type, LPVOID OUT_Struct, int* OUT_EndFlg)
{
	*OUT_EndFlg = 1;
	SXFTableMapManagerC* mappingmanager;
	int i = 0;
	CUIntArray predefcolor;
	CUIntArray predeffont;
	CUIntArray width;
	int return_code = -1;
	INT_PTR table_size;

	/* ð��ٌ^���ُ� */
	if (IN_Type < 1 || 7 < IN_Type){
		SXFErrorMsgC::RecordError(SXFTABLETYPEERR,"",1,IN_Type);
		return SXFTABLETYPEERR;
	}
	/* ð��ٲ��ޯ����0 */
	if(m_CurrentNumber == 0 ){
		m_CurrentType = IN_Type;
	}
	else{
		if(m_CurrentType != IN_Type){
			m_CurrentNumber = 0;
			m_CurrentType = IN_Type;
		}
	}

	switch (m_CurrentType)
	{
		/* ڲ� */
		case 1://layer
			if(m_CurrentNumber == 0)
				m_CurrentNumber = 1;

			/* ڲ�ð��ق̻��� */
			table_size = m_LayerTable.GetSize();
			/* ���ނ�0�̂Ƃ� */
			if (table_size == 0){
				/* �ǂݏo�����C��������܂��� */
//	MOD(S)	���b�Z�[�W�C��	K.Naono	04.03.05
//				SXFErrorMsgC::RecordError(SXFNOLAYER,DEF_LAYER,0);
				SXFErrorMsgC::RecordError2(SXFNOLAYER,DEF_LAYER,0);
				return SXFNOLAYER;
//	MOD(E)	���b�Z�[�W�C��	K.Naono	04.03.05
			}
			/* ڲ�ð��ٲ��ޯ����ð��ق̍Ō� */
			if(m_CurrentNumber == table_size - 1)
				*OUT_EndFlg = 1;	/* EndFlg��ON */
			else if(m_CurrentNumber > table_size - 1) {
				*OUT_EndFlg = 1;	/* EndFlg��ON */
				/* �ǂݏo�����C��������܂��� */
				SXFErrorMsgC::RecordError(SXFNOLAYER,DEF_LAYER,0);
				return SXFNOLAYER;
			}
			else
				*OUT_EndFlg = 0;	/* EndFlg��OFF */
			/* ڲԍ\���� */
			*(Layer_Struct*)OUT_Struct = *(Layer_Struct*)(m_LayerTable[m_CurrentNumber].m_MappingManager->GetStructData(  ));
			/* ���A�l(ڲԺ���) */
			return_code = m_LayerTable[m_CurrentNumber].m_Code;
			/* ð��ٲ��ޯ�����{�P */
			m_CurrentNumber++;
			break;
 		/* ����`�F */
		case 2://predefcolor
			for(i=0; i<MAXPRECOLOUR; i++){
				/* ��`ð��ٗv�fMapping�Ǘ���޼ު�ľ�� */
				mappingmanager = m_PreDefColorTable[i].m_MappingManager;
				if(mappingmanager != NULL)
					/* ����`�Fð��قɒǉ� */
					predefcolor.Add(i);
			}
			/* ����`�Fð��ٻ��� */
			table_size = predefcolor.GetSize();
			/* ð��ٻ��ނ�0 */
			if (table_size == 0){
				/* �ǂݏo������`�F������܂��� */
//	MOD(S)	���b�Z�[�W�C��	K.Naono	04.03.05
//				SXFErrorMsgC::RecordError(SXFNOPRECOLOUR,DEF_PREDEFINED_COLOUR,0);
				SXFErrorMsgC::RecordError2(SXFNOPRECOLOUR,DEF_PREDEFINED_COLOUR,0);
				return SXFNOPRECOLOUR;
//	MOD(E)	���b�Z�[�W�C��	K.Naono	04.03.05
			}
			/* ð��ٲ��ޯ�����Ō� */
			if(m_CurrentNumber == table_size-1)
				*OUT_EndFlg = 1;	/* EndFlg��ON */
			else if(m_CurrentNumber > table_size-1) {
				*OUT_EndFlg = 1;	/* EndFlg��ON */
				/* �ǂݏo������`�F������܂��� */
				SXFErrorMsgC::RecordError(SXFNOPRECOLOUR,DEF_PREDEFINED_COLOUR,0);
				return SXFNOPRECOLOUR;
			}
			else
				*OUT_EndFlg = 0;	/* EndFlg��OFF */
			/* ����`�F�\���� */
			*(Predefined_Colour_Struct*)OUT_Struct = *(Predefined_Colour_Struct*)(m_PreDefColorTable[predefcolor[m_CurrentNumber]].m_MappingManager->GetStructData(  ));
			/* ���A�l(�F����) */
			return_code = m_PreDefColorTable[predefcolor[m_CurrentNumber]].m_Code;
			/* ð��ٲ��ޯ�����{�P */
			m_CurrentNumber++;
			break;
		/* հ�ޒ�`�F */
		case 3://userdefcolor
			/* հ�ޒ�`�Fð��ٻ��� */
			table_size = m_UserDefColorTable.GetSize();
			/* ð��ٻ��ނ�0 */
			if (table_size == 0){
				/* �ǂݏo��հ�ޒ�`�F������܂��� */
//	MOD(S)	���b�Z�[�W�C��	K.Naono	04.03.05
//				SXFErrorMsgC::RecordError(SXFNOUSERCOLOUR,DEF_USERDEFINED_COLOUR,0);
				SXFErrorMsgC::RecordError2(SXFNOUSERCOLOUR,DEF_USERDEFINED_COLOUR,0);
				return SXFNOUSERCOLOUR;
//	MOD(E)	���b�Z�[�W�C��	K.Naono	04.03.05
			}
			/* ð��ٲ��ޯ�����Ō� */
			if(m_CurrentNumber == table_size-1)
				*OUT_EndFlg = 1;	/* EndFlg��ON */
			else if(m_CurrentNumber > table_size-1) {
				*OUT_EndFlg = 1;	/* EndFlg��ON */
				/* �ǂݏo��հ�ޒ�`�F������܂��� */
				SXFErrorMsgC::RecordError(SXFNOUSERCOLOUR,DEF_USERDEFINED_COLOUR,0);
				return SXFNOUSERCOLOUR;
			}
			else
				*OUT_EndFlg = 0;	/* EndFlg��OFF */
			/* հ�ޒ�`�F�\���� */
			*(Userdefined_Colour_Struct*)OUT_Struct = *(Userdefined_Colour_Struct*)(m_UserDefColorTable[m_CurrentNumber].m_MappingManager->GetStructData(  ));
			/* ���A�l(�F����) */
			return_code = m_UserDefColorTable[m_CurrentNumber].m_Code;
			/* ð��ٲ��ޯ�����{�P */
			m_CurrentNumber++;
			break;
		/* ����`���� */
		case 4://predeffont
			for(i=0; i<MAXPRELINETYPE; i++){
				/* ��`ð��ٗv�fMapping�Ǘ���޼ު�Đ��� */
				mappingmanager = m_PreDefFontTable[i].m_MappingManager;
				if(mappingmanager != NULL)
					/* ����`����ð��قɒǉ� */
					predeffont.Add(i);
			}
			/* ����`����ð��ٻ��� */
			table_size = predeffont.GetSize();
			/* ð��ٻ��ނ�0 */
			if (table_size == 0){
				/* �ǂݏo������`���킪����܂��� */
//	MOD(S)	���b�Z�[�W�C��	K.Naono	04.03.05
//				SXFErrorMsgC::RecordError(SXFNOPRELINETYPE,DEF_PREDEFINED_LINETYPE,0);
				SXFErrorMsgC::RecordError2(SXFNOPRELINETYPE,DEF_PREDEFINED_LINETYPE,0);
				return SXFNOPRELINETYPE;
//	MOD(E)	���b�Z�[�W�C��	K.Naono	04.03.05
			}
			/* ð��ٲ��ޯ����ð��ق̍Ō� */
			if(m_CurrentNumber == table_size-1)
				*OUT_EndFlg = 1;	/* EndFlg��ON */
			else if(m_CurrentNumber > table_size-1) {
				*OUT_EndFlg = 1;	/* EndFlg��ON */
				/* �ǂݏo������`���킪����܂��� */
				SXFErrorMsgC::RecordError(SXFNOPRELINETYPE,DEF_PREDEFINED_LINETYPE,0);
				return SXFNOPRELINETYPE;
			}
			else
				*OUT_EndFlg = 0;	/* EndFlg��OFF */
			/* ����`����\���� */
			*(Predefined_Linetype_Struct*)OUT_Struct = *(Predefined_Linetype_Struct*)(m_PreDefFontTable[predeffont[m_CurrentNumber]].m_MappingManager->GetStructData(  ));
			/* ���A�l(������) */
			return_code = m_PreDefFontTable[predeffont[m_CurrentNumber]].m_Code;
			/* ð��ٲ��ޯ�����{�P */
			m_CurrentNumber++;
			break;
		/* հ�ޒ�`���� */
		case 5://userdeffont
			/* հ�ޒ�`����ð��ٻ��� */
			table_size = m_UserDefFontTable.GetSize();
			/* ð��ٻ��ނ�0 */
			if (table_size == 0){
				/* �ǂݏo��հ�ޒ�`���킪����܂��� */
//	MOD(S)	���b�Z�[�W�C��	K.Naono	04.03.05
//				SXFErrorMsgC::RecordError(SXFNOUSERLINETYPE,DEF_USERDEFINED_LINETYPE,0);
				SXFErrorMsgC::RecordError2(SXFNOUSERLINETYPE,DEF_USERDEFINED_LINETYPE,0);
				return SXFNOUSERLINETYPE;
//	MOD(E)	���b�Z�[�W�C��	K.Naono	04.03.05
			}
			/* ð��ٲ��ޯ����ð��ق̍Ō� */
			if(m_CurrentNumber == table_size-1)
				*OUT_EndFlg = 1;		/* EndFlg ��ON */
			else if(m_CurrentNumber > table_size-1) {
				*OUT_EndFlg = 1;		/* EndFlg ��ON */
				/* �ǂݏo��հ�ޒ�`���킪����܂��� */
				SXFErrorMsgC::RecordError(SXFNOUSERLINETYPE,DEF_USERDEFINED_LINETYPE,0);
				return SXFNOUSERLINETYPE;
			}
			else
				*OUT_EndFlg = 0;		/* EndFlg ��OFF */
			/* հ�ޒ�`����\���� */
			*(Userdefined_Linetype_Struct*)OUT_Struct = *(Userdefined_Linetype_Struct*)(m_UserDefFontTable[m_CurrentNumber].m_MappingManager->GetStructData(  ));
			/* ���A�l(������) */
			return_code = m_UserDefFontTable[m_CurrentNumber].m_Code;
			/* ð��ٲ��ޯ�����{�P */
			m_CurrentNumber++;
			break;
		/* ���� */
		case 6://width
			for(i=0; i<MAXLINEWIDTH; i++){
				/* ��`ð��ٗv�fMapping�Ǘ���޼ު�ľ�� */
				mappingmanager = m_WidthTable[i].m_MappingManager;
				if(mappingmanager != NULL)
					/* ����ð��قɒǉ� */
					width.Add(i);
			}
			/* ����ð��ٻ��� */
			table_size = width.GetSize();
			/* ð��ٻ��ނ�0 */
			if (table_size == 0){
				/* �ǂݏo������������܂��� */
//	MOD(S)	���b�Z�[�W�C��	K.Naono	04.03.05
//				SXFErrorMsgC::RecordError(SXFNOLINEWIDTH,DEF_LINE_WIDTH,0);
				SXFErrorMsgC::RecordError2(SXFNOLINEWIDTH,DEF_LINE_WIDTH,0);
				return SXFNOLINEWIDTH;
//	MOD(E)	���b�Z�[�W�C��	K.Naono	04.03.05
			}
			/* ð��ٲ��ޯ����ð��ق̍Ō� */		   
			if(m_CurrentNumber == table_size-1)
				*OUT_EndFlg = 1;	/* EndFlg��ON */
			else if(m_CurrentNumber > table_size-1) {
				*OUT_EndFlg = 1;	/* EndFlg��ON */
				/* �ǂݏo������������܂��� */
				SXFErrorMsgC::RecordError(SXFNOLINEWIDTH,DEF_LINE_WIDTH,0);
				return SXFNOLINEWIDTH;
			}
			else
				*OUT_EndFlg = 0;	/* EndFlg��OFF */
			/* �����\���� */
			*(Line_Width_Struct*)OUT_Struct = *(Line_Width_Struct*)(m_WidthTable[width[m_CurrentNumber]].m_MappingManager->GetStructData(  ));
			/* ���A�l(��������) */
			return_code = m_WidthTable[width[m_CurrentNumber]].m_Code;
			/* ð��ٲ��ޯ�����{�P */
			m_CurrentNumber++;
			break;
		/* ����̫�� */
		case 7://textfont
			/* ����̫��ð��ٻ��� */
			table_size = m_TextFontTable.GetSize();
			/* ð��ٻ��ނ�0 */
			if (table_size == 0){
				/* �ǂݏo������̫�Ă�����܂��� */
//	MOD(S)	���b�Z�[�W�C��	K.Naono	04.03.05
//				SXFErrorMsgC::RecordError(SXFNOTEXTFONT,DEF_TEXT_FONT,0);
				SXFErrorMsgC::RecordError2(SXFNOTEXTFONT,DEF_TEXT_FONT,0);
				return SXFNOTEXTFONT;
//	MOD(E)	���b�Z�[�W�C��	K.Naono	04.03.05
			}
			/* ð��ٲ��ޯ����ð��ق̍Ō� */
			if(m_CurrentNumber == table_size-1)
				*OUT_EndFlg = 1;		/* EndFlg ��ON */
			else if(m_CurrentNumber > table_size-1) {
				*OUT_EndFlg = 1;		/* EndFlg ��ON */
				/* �ǂݏo������̫�Ă�����܂��� */
				SXFErrorMsgC::RecordError(SXFNOTEXTFONT,DEF_TEXT_FONT,0);
				return SXFNOTEXTFONT;
			}
			else
				*OUT_EndFlg = 0;		/* EndFlg ��OFF */
			/* ����̫�č\���� */
			*(Text_Font_Struct*)OUT_Struct = *(Text_Font_Struct*)(m_TextFontTable[m_CurrentNumber].m_MappingManager->GetStructData(  ));
			/* ���A�l(����̫�ĺ���) */
			return_code = m_TextFontTable[m_CurrentNumber].m_Code;
			/* ð��ٲ��ޯ�����{�P */
			m_CurrentNumber++;
			break;
		default:
			return -1;
			break;
	}
	return return_code;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					�쐬���F2001.06.10
//
//	�P�D�@�\�T�v
//		AP202 Table Instance��ID��o�^����
//
//	�Q�D�C���^�[�t�F�[�X
//		BOOL RegisterAP202IDTable(int IN_ID)
//
//		����: �^			  ������				���e
//			  int			 IN_ID				   InstanceID
//		
//		���A�l	
//			  ���펞�FTRUE
//			  �ُ펞�FFALSE
//
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.10	   ���X��(FQS)
//
//------------------------------------------------------------
BOOL SXFTableManagerC::RegisterAP202IDTable(int IN_ID)
{
	m_AP202IDTable.Add(IN_ID);
	return TRUE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					�쐬���F2001.06.10
//
//	�P�D�@�\�T�v
//		AP202 Table ��Mapping���s��
//
//	�Q�D�C���^�[�t�F�[�X
//		BOOL SXFTableManagerC::MappingAP202Table()
//
//		����: �^			  ������				���e
// 					�Ȃ�
//		
//		���A�l	
//			  ���펞�FTRUE
//			  �ُ펞�FFALSE
//
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.10	   ���X��(FQS)
//
//------------------------------------------------------------
BOOL SXFTableManagerC::MappingAP202Table()
{
	for(int i=0;i<m_AP202IDTable.GetSize();i++)
	{
		/* ��`ð��ٗv�fMapping�Ǘ���޼ު�Đ��� */
		SXFTableMapManagerC* mappingmanager = new SXFTableMapManagerC( this, m_InstanceIDManager,m_ComInfo); 

		if( !mappingmanager->SetAP202ID(m_AP202IDTable[i]) ){
			delete mappingmanager;
			continue;
		}

		int tabletype=0;
		/*�\���̎擾*/
		LPVOID tablestruct = mappingmanager->GetStruct( tabletype );
		if(tablestruct == NULL ){
			delete mappingmanager;
			continue;
		}

		//AP202 �e�[�u���̓o�^
		if( RegisterAP202Table( m_AP202IDTable[i],
								tabletype,
								tablestruct,
								mappingmanager) < 0) {
			delete mappingmanager;
			continue;
		}
	}

	return TRUE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					�쐬���F2001.06.10
//
//	�P�D�@�\�T�v
//		AP202 Table �̓o�^
//
//	�Q�D�C���^�[�t�F�[�X
//	int SXFTableManagerC::RegisterAP202Table( int IN_ID,
//											int IN_Type,
//											LPVOID IN_Struct,
//											SXFTableMapManagerC* IN_MappingManager)
//											
//		����: �^			  ������				���e
//			int IN_ID							�e�[�u���v�f��ID
//			int IN_Type							�e�[�u���v�f��type
//			LPVOID IN_Struct					�\����
//			SXFTableMapManagerC* IN_MappingManager
//
//		���A�l	
//			  ���펞�FTRUE
//			  �ُ펞�FFALSE
//
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.10	   ���X��(FQS)
//
//------------------------------------------------------------
int SXFTableManagerC::RegisterAP202Table( int IN_ID,
										  int IN_Type,
										  LPVOID IN_Struct,
										  SXFTableMapManagerC* IN_MappingManager)
{

	SXFLayerC layer;
	SXFPreDefColorC predefcolor;
	SXFPreDefFontC predeffont;
	SXFUserDefColorC userdefcolor;
	SXFUserDefFontC userdeffont;
	SXFWidthC width;
	SXFTextFontC textfont;
	INT_PTR textfontsize;
	INT_PTR layercode;
	INT_PTR usercolorsize;
	INT_PTR userfontsize;
	int i;
	double inwidth;
	double eps1;
	double eps2;
	int resaultcode;
	int find1;
	int find2;
	double ascent = 1.0;
	double decent = 0.0;

	switch(IN_Type)
	{
	/* ڲ� */
	case 1://layer

		if(m_LayerTable.GetSize() == 0 ){
			SXFLayerC blanklayer;
			blanklayer.m_Name =DEF_BLANK;
			blanklayer.m_Code = 0;
			m_LayerTable.Add(blanklayer);
		}
		/* ڲԖ� */
		layer.m_Name = ((Layer_Struct*)IN_Struct)->name;
		/* �\���E��\���t���O*/
		layer.m_LfFlag = ((Layer_Struct*)IN_Struct)->lflag;
		/*	ڲ�ID*/
		layer.m_ID=IN_ID;

		if(layer.m_Name == "$$SXF_dummy_layer_for_subfigure"){
			layercode = 0;
		}else{
			layercode = m_LayerTable.GetSize();
		}

		if (layercode>MAXLAYER){
			SXFErrorMsgC::RecordError(SXFMAXLAYER,DEF_LAYER,0);
			return SXFMAXLAYER;
		}
		layer.m_Code = (int)layercode;
		/* ��`ð��ٗv�fMapping�Ǘ���޼ު�ľ�� */
		layer.m_MappingManager = IN_MappingManager;
		layer.m_Element.Copy(IN_MappingManager->m_MapTable->m_LayerElements);
		if(layer.m_Code == 0){
			if(m_LayerTable[0].m_Name != DEF_BLANK)
				return FALSE; 
			m_LayerTable.SetAt(0,layer);
		}else{
			/* ڲ�ð��قɒǉ� */
			m_LayerTable.Add(layer);
		}
		break;

	/** ����`�F **/
	case 2://predefcolor 16
		/* ����`�F�ȊO�̖��O�̂Ƃ� */
		if(!predefcolor.SetName(((Predefined_Colour_Struct*)IN_Struct)->name)){
			SXFErrorMsgC::RecordError(SXFNOTPRECOLOUR,DEF_PREDEFINED_COLOUR,1,((Predefined_Colour_Struct*)IN_Struct)->name);
			return SXFNOTPRECOLOUR;
		}
		/* �F��������ð��ٓ��ɂ���Ƃ� */
		if (!CheckSamePreDefColor(predefcolor.m_Name)) {
			SXFErrorMsgC::RecordError(SXFSAMENAME,DEF_PREDEFINED_COLOUR,1,predefcolor.m_Name);
			return SXFSAMENAME;
		}
		/* �ݽ�ݽID��� */
		predefcolor.m_ID = IN_ID;
		/* ��`ð��ٗv�fMapping�Ǘ���޼ު�Ă�� */
		predefcolor.m_MappingManager = IN_MappingManager;
		/* ����`�Fð��قɒǉ� */
		m_PreDefColorTable[predefcolor.m_Code-1] = predefcolor;
		break;

	/** ���[�U��`�F **/
	case 3://userdefcolor
		usercolorsize = m_UserDefColorTable.GetSize();
		///ERROR
		/** �ő�F���𒴂����Ƃ��G���[���� **/
		if (usercolorsize >= MAXUSERCOLOUR){
			SXFErrorMsgC::RecordError(SXFMAXUSERCOLOUR,DEF_USERDEFINED_COLOUR,0);
			return SXFMAXUSERCOLOUR;
		}
		userdefcolor.m_Code = (int)(usercolorsize+16+1);//17------
		userdefcolor.R =((Userdefined_Colour_Struct*)IN_Struct)->red;
		userdefcolor.G =((Userdefined_Colour_Struct*)IN_Struct)->green;
		userdefcolor.B =((Userdefined_Colour_Struct*)IN_Struct)->blue;
		userdefcolor.m_ID = IN_ID;
		/* ��`ð��ٗv�fMapping�Ǘ���޼ު�ľ�� */
		userdefcolor.m_MappingManager = IN_MappingManager;
		/* հ�ޒ�`�Fð��قɒǉ� */
		m_UserDefColorTable.Add(userdefcolor);
		break;

	/** ����`���� **/
	case 4://predeffont
		/* ����`���햼�łȂ� */
		if (!predeffont.SetName(((Predefined_Linetype_Struct*)IN_Struct)->name)){
			SXFErrorMsgC::RecordError(SXFNOTPRETYPE,DEF_PREDEFINED_LINETYPE,1,((Predefined_Linetype_Struct*)IN_Struct)->name);
			return SXFNOTPRETYPE;
		}
		/* ����`���햼������ð��ٓ��ɂ��� */
		if (!CheckSamePreDefFont(predeffont.m_Name)) {
			SXFErrorMsgC::RecordError(SXFSAMENAME,DEF_PREDEFINED_LINETYPE,1,predeffont.m_Name);
			return SXFSAMENAME;
		}
		/* �ݽ�ݽID��� */
		predeffont.m_ID = IN_ID;
		/* ��`ð��ٗv�fMapping�Ǘ���޼ު�ľ�� */
		predeffont.m_MappingManager = IN_MappingManager;
		/* ����`����ð��قɒǉ� */
		m_PreDefFontTable[predeffont.m_Code-1] = predeffont;
		break;

	/** ���[�U��`���� **/
	case 5://userdeffont
		userfontsize = m_UserDefFontTable.GetSize();
		///ERROR
		//���[�U��`�����32������`�ł��Ȃ��B
		if (userfontsize >= MAXUSERLINETYPE){
			SXFErrorMsgC::RecordError(SXFMAXUSERLINETYPE,DEF_USERDEFINED_LINETYPE,0);
			return SXFMAXUSERLINETYPE;
		}
		userdeffont.m_Code = (int)(userfontsize+16+1);//17---
		userdeffont.m_Name = ((Userdefined_Linetype_Struct*)IN_Struct)->name;
		userdeffont.m_Segment=((Userdefined_Linetype_Struct*)IN_Struct)->segment;
		for(i=0;i<userdeffont.m_Segment;i++)
			userdeffont.m_Pitch.Add( ((Userdefined_Linetype_Struct*)IN_Struct)->pitch[i] );
		/* �ݽ�ݽID */
		userdeffont.m_ID = IN_ID;
		/* ��`ð��ٗv�fMapping�Ǘ���޼ު�ľ�� */
		userdeffont.m_MappingManager = IN_MappingManager;
		/* հ�ޒ�`����ð��ْǉ� */
		m_UserDefFontTable.Add(userdeffont);
		break;

	/** ���� **/
	case 6://width
		/* ���� */
		inwidth = ((Line_Width_Struct*)IN_Struct)->width;
		/* �������ُ� */
		if( inwidth <= 0 ){
			SXFErrorMsgC::RecordError(SXFERRORWIDTH,DEF_LINE_WIDTH,1,inwidth);
			return -1;
		}

		eps1 = 0.0;
		eps2 = 0.0;
		/* ���e�덷�擾 */
		m_ComInfo->Get_Tolerance(eps1,eps2);
		/* ��������������ނ����߂� */
		resaultcode = width.InquireCode(inwidth,eps1);
		/* �����ɑΉ�����������ނ�����(����`) */
		if(resaultcode != 0){
			/* ����ð��ٓ��ɂ��� */
			if(m_PreDefWidthFlagTable[resaultcode-1] == 1){
				SXFErrorMsgC::RecordError(SXFSAMEWIDTH,DEF_LINE_WIDTH,1,inwidth);
				return SXFSAMEWIDTH;
			}
			/* �������� */
			width.m_Code = resaultcode;
			SXFPreWidthTableC prewidthtable;
			double prewidth = 0.0;
			/* �������ނ���������擾 */
			prewidthtable.GetPreWidth(resaultcode, prewidth); 
			/* ���� */
			width.m_Width = prewidth;
			/* ����ð��قɒǉ� */
			m_PreDefWidthFlagTable[resaultcode-1]=1;

		}
		//�����ɑΉ�����R�[�h���O�̂Ƃ��͊���`�ł͂Ȃ��B
		else{
			/* ����ð��ٓ��ɂ��� */
			for (int i = 11; i < userdefwidthcode; i++) {
				if (m_WidthTable[i-1] .m_Width == inwidth) {
					SXFErrorMsgC::RecordError(SXFSAMEWIDTH,DEF_LINE_WIDTH,1,inwidth);
					return SXFSAMEWIDTH;
				}
			}
			//�������P�U�ȏ�o�^����Ă����
			//����ȏ�o�^�ł��Ȃ��̂ŁA�G���[
			if (userdefwidthcode > MAXLINEWIDTH){//widthcode 1---16
				SXFErrorMsgC::RecordError(SXFMAXLINEWIDTH,DEF_LINE_WIDTH,0);
				return SXFMAXLINEWIDTH;
			}
			else{
				/* �������� */
				width.m_Code = userdefwidthcode;
				userdefwidthcode++;
			}
			/* ���� */
			width.m_Width=inwidth;
		}
		/* ��`ð��ٗv�fMapping�Ǘ���޼ު�ľ�� */
		width.m_MappingManager=IN_MappingManager;
		/* �ݽ�ݽID */
		width.m_ID = IN_ID;
		/* ����ð��قɒǉ� */	
		m_WidthTable[width.m_Code-1] = width;
		break;

	/** �����t�H���g **/
	case 7://textfont
		//ERROR
		//�����t�H���g�͂P�O�Q�S�����o�^�ł��Ȃ�
		textfontsize = m_TextFontTable.GetSize();
		if (textfontsize >= MAXTEXTFONT){//textfont 1--1024
			SXFErrorMsgC::RecordError(SXFMAXTEXTFONT,DEF_TEXT_FONT,0);
			return SXFMAXTEXTFONT;
		}
		/* ����̫�Ė� */
		textfont.m_Name = ((Text_Font_Struct*)IN_Struct)->name;
		/* ����ð��ٓ��ɂ��� */
		if (!CheckSameTextFont(textfont.m_Name)) {
			SXFErrorMsgC::RecordError(SXFSAMENAME,DEF_TEXT_FONT,1,textfont.m_Name);
			return SXFSAMENAME;
		}

		ascent = 1.0;
		decent = 0.0;

		if ((find1 = textfont.m_Name.ReverseFind('-')) != -1){
			CString tmp_font_name = textfont.m_Name.Left(find1);
			CString decent_tmp = textfont.m_Name.Mid(find1+1);
			if ((find2 = tmp_font_name.ReverseFind('-')) != -1){
				CString ascent_tmp = tmp_font_name.Mid(find2+1);
				ascent = atof(ascent_tmp);
				decent = atof(decent_tmp);
			}
		}
		textfont.m_Ascent = ascent;
		textfont.m_Decent = decent;
		/* ����̫�ĺ��� */
		textfont.m_Code = (int) m_TextFontTable.GetSize()+1;
		/* �ݽ�ݽID */
		textfont.m_ID = IN_ID;
		/* ��`ð��ٗv�fMapping�Ǘ���޼ު�ľ�� */
		textfont.m_MappingManager = IN_MappingManager;
		/* ����̫��ð��قɒǉ� */
		m_TextFontTable.Add(textfont);
		break;

	default:
		// struct type error
		return -1;
		break;
	}

	return 1;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					�쐬���F2001.06.10
//
//	�P�D�@�\�T�v
//		�w�肵��Table�v�f��Instance ID�ƑΉ������Code���擾����
//		(READ AP202)
//		 Layer�̎��́ALayer Element ID�ƑΉ������Layer Code��Ԃ�
//
//	�Q�D�C���^�[�t�F�[�X
//		int GetTableCode( int IN_ID , int& OUT_Type)
//
//		����: �^			  ������				���e
//			  int			  IN_ID				   Table�v�f��Instance ID
//													
//		
//		���A�l	
//			  ���펞�F Table �v�f�� Code
//			  �ُ펞�F -1
//
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.10	   ���X��(FQS)
//
//------------------------------------------------------------
int SXFTableManagerC::GetTableCode( int IN_ID, int& OUT_Type)
{
	int i = 0;
	int j = 0;

	if (m_TableCodeElemMapInitialized == FALSE) {
		// ����������Ă��Ȃ��ꍇ�͏���������
		m_TableCodeElemMapInitialized = TRUE;
		m_TableCodeElemMap.InitHashTable( 109 );
		for(i=0;i<m_LayerTable.GetSize();i++){
			for(j=0;j<m_LayerTable[i].m_Element.GetSize();j++){
				SXFTableCodeElem	e;
				e.id = m_LayerTable[i].m_Element[j];
				e.getcode = i;
				e.codetype = 1;//layer
				m_TableCodeElemMap.SetAt(e.id, e);
			}
		}
		for(i=0;i<16;i++){
				SXFTableCodeElem	e;
				e.id = m_PreDefColorTable[i].m_ID;
				e.getcode = i+1;
				e.codetype = 2;//predefcolor
				m_TableCodeElemMap.SetAt(e.id, e);
		}
		for(i=0;i<m_UserDefColorTable.GetSize();i++){ //0---(256-16)
				SXFTableCodeElem	e;
				e.id = m_UserDefColorTable[i].m_ID;
				e.getcode = i+16+1;
				e.codetype = 3;//userdefcolor
				m_TableCodeElemMap.SetAt(e.id, e);
		}
		for(i=0;i<16;i++){
				SXFTableCodeElem	e;
				e.id = m_PreDefFontTable[i].m_ID;
				e.getcode = i+1;
				e.codetype = 4;//predeffont
				m_TableCodeElemMap.SetAt(e.id, e);
		}
		for(i=0;i<m_UserDefFontTable.GetSize();i++){//0----(32-16)
				SXFTableCodeElem	e;
				e.id = m_UserDefFontTable[i].m_ID;
				e.getcode = i+16+1;
				e.codetype = 5;//userdeffont
				m_TableCodeElemMap.SetAt(e.id, e);
		}
		for(i=0;i<16;i++){
				SXFTableCodeElem	e;
				e.id = m_WidthTable[i].m_ID;
				e.getcode = i+1;
				e.codetype = 6;//width
				m_TableCodeElemMap.SetAt(e.id, e);
		}
		for(i=0;i<m_TextFontTable.GetSize();i++){
				SXFTableCodeElem	e;
				e.id = m_TextFontTable[i].m_ID;
				e.getcode = i+1;
				e.codetype = 7;//textfont
				m_TableCodeElemMap.SetAt(e.id, e);
		}

	}
	SXFTableCodeElem	e;
	if (m_TableCodeElemMap.Lookup(IN_ID,e)) {
		OUT_Type = e.codetype;
		return e.getcode;
	}
	else {
		return -1;
	}
}
//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					�쐬���F2001.06.10
//
//	�P�D�@�\�T�v
//		�\���E��\���t���O�̓o�^
//
//	�Q�D�C���^�[�t�F�[�X
//		void	SXFTableManagerC::RegisterInvisibility
//		
//	����	�F	�^		�@�@�@�@������				���e
//		�@�@�@�@INSTANCEDATA	*IN_Instance	
//
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.10	   ���X��(FQS)
//
//------------------------------------------------------------

BOOL SXFTableManagerC::RegisterInvisibility(INSTANCEDATA *IN_Instance)
{

	CUIntArray	idarray;
	if( SXFListToIntID( IN_Instance->EntityData,idarray ) == FALSE)
		return FALSE;

	m_InvisibilityLayerTable.Append( idarray );

	return TRUE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					�쐬���F2001.06.10
//
//	�P�D�@�\�T�v
//		�\���E��\���t���O�̎擾
//
//	�Q�D�C���^�[�t�F�[�X
//		void	SXFTableManagerC::GetInvisibilityFlag()
//		
//	����	�F	�^		������				���e
//		int		IN_ID	���C��Instance ID	
//
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.10	   ���X��(FQS)
//
//------------------------------------------------------------
BOOL SXFTableManagerC::GetInvisibilityFlag(int IN_ID)
{
	for(int i=0;i<m_InvisibilityLayerTable.GetSize();i++){
		if((UINT)IN_ID == m_InvisibilityLayerTable[i])
			return TRUE;
	}

	return FALSE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp				�쐬���F2001.06.24
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
BOOL SXFTableManagerC::SXFListToIntID(CString& IN_List, CUIntArray& OUT_IDArray)
{

	if(IN_List[0] != '(' || IN_List.Right(1) != ')' )
		return FALSE;

	IN_List.TrimLeft('(');
	IN_List.TrimRight(')');

	if (IN_List.IsEmpty()) {
		return TRUE;
	}
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
/*
	ComSplitStringC split(IN_List);
	CStringArray* array;
	array = split.Split(',');

	for(int i=0;i<array->GetSize();i++){
		(*array)[i].TrimLeft();
		(*array)[i].TrimRight();
		if ((*array)[i].IsEmpty()) {
			return FALSE;
		}
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
		array[i].TrimRight() ;
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
//	SXFTableManagerC.cpp					�쐬���F2001.06.10
//
//	�P�D�@�\�T�v
//		PresentationSize�̓o�^
//
//	�Q�D�C���^�[�t�F�[�X
//		void	SXFTableManagerC::RegisterPresentationSize()
//		
//	����	�F	�^		������				���e
//			INSTANCEDATA  IN_Instance  �ݽ�ݽ�ް���޼ު�Ă̱��ڽ
//
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.10	   ���X��(FQS)
//
//------------------------------------------------------------
BOOL SXFTableManagerC::RegisterPresentationSize(INSTANCEDATA *IN_Instance)
{
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
/*
	CStringArray* array;

	SXFSplitAP202C splitap202( 2,IN_Instance->EntityData );
	
	array = splitap202.Split();

	if(array==NULL)
		return FALSE;

	if(array->GetSize() !=2 )
		return FALSE;

	SXFMapEntAConvC convent(array);
*/
	CStringArray	array ;
	if( GFn_SplitSEntityAttr(IN_Instance->EntityData, array) != 2 )
		return FALSE ;

	SXFMapEntAConvC convent(&array) ;
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.03

	int sheetid;
	int planarboxid;

	if( convent.GetInst(0,sheetid) < 0 )
		return FALSE;

	if( convent.GetInst(1,planarboxid) < 0 )
		return FALSE;
	/*PresentationSize�Ǘ���޼ު�Đ���*/
	SXFPresentationSizeC* presentationsize = 
		new SXFPresentationSizeC();
	/*�p��ID�Z�b�g*/
	presentationsize->sheetid = sheetid;
	/*planarbox ID�Z�b�g*/
	presentationsize->planarboxid = planarboxid;
	/*PresentationSizeð��قɒǉ�*/
	m_PresentationSizeTable.Add(presentationsize);

	return TRUE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					�쐬���F2001.06.10
//
//	�P�D�@�\�T�v
//		Sheet Title��o�^����
//		
//	�Q�D�C���^�[�t�F�[�X
//		BOOL RegisterSheetTitle( INSTANCEDATA *IN_Instance )
//
//		����: �^			  ������			���e
//			  INSTANCEDATA*   IN_Instance		Instance��
//												�\���̂̃A�h���X 
//		
//		���A�l	
//			  ���펞�FTRUE
//			  �ُ펞�FFALSE
//
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.10	   ���X��(FQS)
//
//------------------------------------------------------------
BOOL SXFTableManagerC::RegisterSheetTitle(INSTANCEDATA *IN_Instance)
{
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
/*
	CStringArray* array;

	SXFSplitAP202C splitap202( 2,IN_Instance->EntityData );

	array = splitap202.Split();

	if(array==NULL)
		return FALSE;

	if(array->GetSize() !=3 )
		return FALSE;

	SXFMapEntAConvC convent(array);
*/
	CStringArray	array ;
	if( GFn_SplitSEntityAttr(IN_Instance->EntityData, array) != 3 )
		return FALSE ;

	SXFMapEntAConvC convent(&array) ;
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.03

	CArray<int,int> sheetidarray;
	int count;
	if( convent.GetSetInst(0,count,sheetidarray) < 0 )
		return FALSE;

	CString sheettitle;
	if ( convent.GetCString(2,sheettitle) < 0 )
		return FALSE;
	/*DranghtingTitle�Ǘ���޼ު�Đ���*/
	SXFDranghtingTitleC* dranghtingtitle =
		new SXFDranghtingTitleC();
	for(int i=0;i<sheetidarray.GetSize();i++){
		dranghtingtitle->sheetidlist.Add(sheetidarray[i]);
	}
	/*�p�����پ��*/
	dranghtingtitle->sheettitle = sheettitle;
	/*�p������ð��قɒǉ�*/
	m_SheetTitleTable.Add(dranghtingtitle);

//	ADD(S)	Ver3.0�Ή�	K.Naono	04.01.30
	RegisterAttribute(IN_Instance) ;
//	ADD(E)	Ver3.0�Ή�	K.Naono	04.01.30

	return TRUE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					�쐬���F2001.06.10
//
//	�P�D�@�\�T�v
//		PlanarBox ID�̎擾
//		
//	�Q�D�C���^�[�t�F�[�X
//		BOOL GetPlanarBoxID(int IN_SheetID)
//
//		����: �^			  ������			���e
//			int			IN_SheetID		�p��ID
//		
//		���A�l	
//			  ���펞�Fplanarboxid
//
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.10	   ���X��(FQS)
//
//------------------------------------------------------------
int SXFTableManagerC::GetPlanarBoxID(int IN_SheetID)
{
	int planarboxid = -1;

	for(int i=0;i<m_PresentationSizeTable.GetSize();i++){
		if(m_PresentationSizeTable[i]->sheetid == IN_SheetID ){
			planarboxid = m_PresentationSizeTable[i]->planarboxid;
			break;
		}
	}

	return planarboxid;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					�쐬���F2001.06.10
//
//	�P�D�@�\�T�v
//		�p���^�C�g���̎擾
//		
//	�Q�D�C���^�[�t�F�[�X
//	  BOOL SXFTableManagerC::GetSheetTitle(int IN_SheetID, CString& INOUT_SheetTitle)
//
//		����: �^			  ������			���e
//		int			 IN_SheetID			�p��ID
//		CString		 INOUT_SheetTitle	�p���^�C�g��   
//
//		���A�l	
//			  ���펞�FTRUE
//			  �ُ펞�FFALSE
//
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.10	   ���X��(FQS)
//
//------------------------------------------------------------
BOOL SXFTableManagerC::GetSheetTitle(int IN_SheetID, CString& INOUT_SheetTitle)
{
	BOOL find = FALSE;
	for(int i=0;i<m_SheetTitleTable.GetSize();i++){
		for(int j=0;j<m_SheetTitleTable[i]->sheetidlist.GetSize();j++){
			if(m_SheetTitleTable[i]->sheetidlist[j] == IN_SheetID){
				INOUT_SheetTitle = (m_SheetTitleTable[i]->sheettitle);
				find = TRUE;
				break;
			}
		}
		if(find)
			break;
	}
	return find;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp                    �쐬���F2001.06.10
//
//	�P�D�@�\�T�v
//		�}�ʕ\�藓�̏���ݒ肷��(WRITE��)
//
//	�Q�D�C���^�[�t�F�[�X
//		BOOL SXFTableManagerC::SetAttributeStruct(
//										LPVOID	IN_Struct)
//
//		����:	�^				������			���e
//			LPVOID		IN_Struct		�}�ʕ\�藓�\����
//
//		���A�l	
//			���펞�FTRUE
//			�ُ펞�FFALSE
//
//	�R�D����
//		����ԍ�	���t��			�S����		�T�v
//		�쐬		2004.01.30		K.Naono		Ver3.0�Ή�
//
//------------------------------------------------------------
BOOL SXFTableManagerC::SetAttributeStruct(
								LPVOID	IN_Struct)
{
	if( IN_Struct == NULL ) {
		return FALSE ;
	}

	//	���ɐ}�ʕ\�藓��񂪑��݂���΁A�o�^���Ȃ�
	if( m_Attribute_Str != NULL ) {
		return TRUE ;
	}
	m_Attribute_Str = new Attribute_Struct ;
//	MOD(S)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
//	strcpy(m_Attribute_Str->p_name,		((Attribute_Struct*)IN_Struct)->p_name) ;
//	strcpy(m_Attribute_Str->c_name,		((Attribute_Struct*)IN_Struct)->c_name) ;
//	strcpy(m_Attribute_Str->c_type,		((Attribute_Struct*)IN_Struct)->c_type) ;
//	strcpy(m_Attribute_Str->d_title,	((Attribute_Struct*)IN_Struct)->d_title) ;
//	strcpy(m_Attribute_Str->d_number,	((Attribute_Struct*)IN_Struct)->d_number) ;
//	strcpy(m_Attribute_Str->d_type,		((Attribute_Struct*)IN_Struct)->d_type) ;
//	strcpy(m_Attribute_Str->d_scale,	((Attribute_Struct*)IN_Struct)->d_scale) ;
	strcpy_s(m_Attribute_Str->p_name,	_countof(m_Attribute_Str->p_name),		((Attribute_Struct*)IN_Struct)->p_name) ;
	strcpy_s(m_Attribute_Str->c_name,	_countof(m_Attribute_Str->c_name),		((Attribute_Struct*)IN_Struct)->c_name) ;
	strcpy_s(m_Attribute_Str->c_type,	_countof(m_Attribute_Str->c_type),		((Attribute_Struct*)IN_Struct)->c_type) ;
	strcpy_s(m_Attribute_Str->d_title,	_countof(m_Attribute_Str->d_title),		((Attribute_Struct*)IN_Struct)->d_title) ;
	strcpy_s(m_Attribute_Str->d_number,	_countof(m_Attribute_Str->d_number),	((Attribute_Struct*)IN_Struct)->d_number) ;
	strcpy_s(m_Attribute_Str->d_type,	_countof(m_Attribute_Str->d_type),		((Attribute_Struct*)IN_Struct)->d_type) ;
	strcpy_s(m_Attribute_Str->d_scale,	_countof(m_Attribute_Str->d_scale),		((Attribute_Struct*)IN_Struct)->d_scale) ;
//	MOD(E)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
	m_Attribute_Str->d_year	= 			((Attribute_Struct*)IN_Struct)->d_year ;
	m_Attribute_Str->d_month= 			((Attribute_Struct*)IN_Struct)->d_month ;
	m_Attribute_Str->d_day	= 			((Attribute_Struct*)IN_Struct)->d_day ;
//	MOD(S)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
//	strcpy(m_Attribute_Str->c_contractor,	((Attribute_Struct*)IN_Struct)->c_contractor) ;
//	strcpy(m_Attribute_Str->c_owner,		((Attribute_Struct*)IN_Struct)->c_owner) ;
	strcpy_s(m_Attribute_Str->c_contractor,	_countof(m_Attribute_Str->c_contractor),	((Attribute_Struct*)IN_Struct)->c_contractor) ;
	strcpy_s(m_Attribute_Str->c_owner,		_countof(m_Attribute_Str->c_owner),			((Attribute_Struct*)IN_Struct)->c_owner) ;
//	MOD(E)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
	return TRUE ;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp                    �쐬���F2001.06.10
//
//	�P�D�@�\�T�v
//		�}�ʕ\�藓�̏���ԋp����(WRITE��)
//
//	�Q�D�C���^�[�t�F�[�X
//		Attribute_Struct* SXFTableManagerC::GetAttributeStruct()
//
//		����:	�^				������			���e
//			�Ȃ�
//
//		���A�l	
//			���펞�F�}�ʕ\�藓���
//			�ُ펞�FNULL
//
//	�R�D����
//		����ԍ�	���t��			�S����		�T�v
//		�쐬		2004.01.30		K.Naono		Ver3.0�Ή�
//
//------------------------------------------------------------
Attribute_Struct* SXFTableManagerC::GetAttributeStruct()
{
	return m_Attribute_Str ;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp                    �쐬���F2001.06.10
//
//	�P�D�@�\�T�v
//		�}�ʕ\�藓�̏���ԋp����(READ��)
//
//	�Q�D�C���^�[�t�F�[�X
//		void SXFTableManagerC::GetAttributeData(
//										Attribute_Struct*	OUT_Attr)
//
//		����:	�^				������			���e
//			Attribute_Struct*	OUT_Attr		�}�ʕ\�藓���̊i�[�̈�
//
//		���A�l	
//			�Ȃ�
//
//	�R�D����
//		����ԍ�	���t��			�S����		�T�v
//		�쐬		2004.01.30		K.Naono		Ver3.0�Ή�
//
//------------------------------------------------------------
void SXFTableManagerC::GetAttributeData(
								Attribute_Struct*	OUT_Attr)
{
	if( OUT_Attr == NULL ) {
		return ;
	}

	//	������
	ZeroMemory(OUT_Attr->p_name,		sizeof(OUT_Attr->p_name)) ;
	ZeroMemory(OUT_Attr->c_name,		sizeof(OUT_Attr->c_name)) ;
	ZeroMemory(OUT_Attr->c_type,		sizeof(OUT_Attr->c_type)) ;
	ZeroMemory(OUT_Attr->d_title,		sizeof(OUT_Attr->d_title)) ;
	ZeroMemory(OUT_Attr->d_number,		sizeof(OUT_Attr->d_number)) ;
	ZeroMemory(OUT_Attr->d_type,		sizeof(OUT_Attr->d_type)) ;
	ZeroMemory(OUT_Attr->d_scale,		sizeof(OUT_Attr->d_scale)) ;
	ZeroMemory(OUT_Attr->c_contractor,	sizeof(OUT_Attr->c_contractor)) ;
	ZeroMemory(OUT_Attr->c_owner,		sizeof(OUT_Attr->c_owner)) ;
	OUT_Attr->d_year = OUT_Attr->d_month = OUT_Attr->d_day = 0 ;

	if( m_id_draug_drw_rev == -1 ) {
		return ;
	}

	//	�}�ʕ\�藓���̎擾
	ATTRIBUTEINFO*	attr_info = GetAttributeInfo(m_id_draug_drw_rev) ;
	if( attr_info == NULL ) {
		return ;
	}

	//	�}�ʕ\�藓�����R�s�[
//	MOD(S)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
//	strcpy(OUT_Attr->p_name,	attr_info->attr_body.p_name) ;
//	strcpy(OUT_Attr->c_name,	attr_info->attr_body.c_name) ;
//	strcpy(OUT_Attr->c_type,	attr_info->attr_body.c_type) ;
//	strcpy(OUT_Attr->d_title,	attr_info->attr_body.d_title) ;
//	strcpy(OUT_Attr->d_number,	attr_info->attr_body.d_number) ;
//	strcpy(OUT_Attr->d_type,	attr_info->attr_body.d_type) ;
//	strcpy(OUT_Attr->d_scale,	attr_info->attr_body.d_scale) ;
	strcpy_s(OUT_Attr->p_name,	_countof(OUT_Attr->p_name),		attr_info->attr_body.p_name) ;
	strcpy_s(OUT_Attr->c_name,	_countof(OUT_Attr->c_name),		attr_info->attr_body.c_name) ;
	strcpy_s(OUT_Attr->c_type,	_countof(OUT_Attr->c_type),		attr_info->attr_body.c_type) ;
	strcpy_s(OUT_Attr->d_title,	_countof(OUT_Attr->d_title),	attr_info->attr_body.d_title) ;
	strcpy_s(OUT_Attr->d_number,_countof(OUT_Attr->d_number),	attr_info->attr_body.d_number) ;
	strcpy_s(OUT_Attr->d_type,	_countof(OUT_Attr->d_type),		attr_info->attr_body.d_type) ;
	strcpy_s(OUT_Attr->d_scale,	_countof(OUT_Attr->d_scale),	attr_info->attr_body.d_scale) ;
//	MOD(E)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
	OUT_Attr->d_year	= 		attr_info->attr_body.d_year ;
	OUT_Attr->d_month	= 		attr_info->attr_body.d_month ;
	OUT_Attr->d_day		= 		attr_info->attr_body.d_day ;
//	MOD(S)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
//	strcpy(OUT_Attr->c_contractor,	attr_info->attr_body.c_contractor) ;
//	strcpy(OUT_Attr->c_owner,		attr_info->attr_body.c_owner) ;
	strcpy_s(OUT_Attr->c_contractor,_countof(OUT_Attr->c_contractor),	attr_info->attr_body.c_contractor) ;
	strcpy_s(OUT_Attr->c_owner,		_countof(OUT_Attr->c_owner),		attr_info->attr_body.c_owner) ;
//	MOD(E)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp                    �쐬���F2001.06.10
//
//	�P�D�@�\�T�v
//		�C���X�^���X�f�[�^���A�}�ʕ\�藓�̏����擾����(READ��)
//
//	�Q�D�C���^�[�t�F�[�X
//		BOOL SXFTableManagerC::RegisterAttribute(
//										INSTANCEDATA*	IN_Instance)
//
//		����:	�^				������			���e
//			INSTANCEDATA*		IN_Instance		�ݽ�ݽ�ް���޼ު�Ă̱��ڽ
//
//		���A�l	
//			���펞�FTRUE
//			�ُ펞�FFALSE
//
//	�R�D����
//		����ԍ�	���t��			�S����		�T�v
//		�쐬		2004.01.30		K.Naono		Ver3.0�Ή�
//
//------------------------------------------------------------
BOOL SXFTableManagerC::RegisterAttribute(
								INSTANCEDATA*	IN_Instance)
{
	if( m_InstanceIDManager == NULL ) {
		return FALSE ;
	}

	char	szInstanceId[256] ;

	//	#5170=DRAWING_DEFINITION('\X2\56F39762756A53F7\X0\4','\X2\56F397627A2E5225\X0\4');
	//	#5180=DRAUGHTING_DRAWING_REVISION('01',#5170,'\X2\5C3A5EA6\X0\4');
	//	#5190=DRAUGHTING_TITLE((#5180),'JAPANESE','\X2\56F39762540D\X0\4');
	if( IN_Instance->EntityName == DEF_DRAUGHTING_TITLE ) {

		CStringArray	array1 ;
		if( GFn_SplitSEntityAttr(IN_Instance->EntityData, array1) != 3 )
			return FALSE ;

		SXFMapEntAConvC	convent1(&array1) ;
		CString	d_title ;
		if( convent1.GetCString(2, d_title) < 0 )
			return FALSE ;

		CArray<int,int>	idarray ;
		int	count = 0 ;
		if( convent1.GetSetInst(0, count,idarray) < 0 )
			return FALSE;

		SXFEntityDataC*	draw_rev_ent = NULL ;
		for(int i = 0; i < idarray.GetSize(); i++) {
			draw_rev_ent = m_InstanceIDManager->GetEntityDataPtr(idarray[i]) ;
			if( draw_rev_ent != NULL ) {
				ATTRIBUTEINFO*	attr_info = new ATTRIBUTEINFO ;
				attr_info->id_draug_drw_rev = idarray[i] ;
				//	�}�ʖ��̎擾
				if( lstrlen(d_title) <= 256 ) {
					lstrcpy(attr_info->attr_body.d_title, (LPCTSTR)d_title) ;
				} else {
					//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
					//sprintf(szInstanceId, "#%d", IN_Instance->InstanceID) ;
					sprintf_s(szInstanceId,_countof(szInstanceId), "#%d", IN_Instance->InstanceID) ;
					SXFErrorMsgC::RecordError(SXFNAMELENGTH,
												DEF_DRAUGHTING_TITLE,
												2,
												szInstanceId,
												DEF_DRAUGHTING_TITLE) ;
					// �擪����256�o�C�g�؂���
					lstrcpyn(attr_info->attr_body.d_title, (LPCTSTR)d_title, 256) ;
				}
				CString	draw_rev_data ;
				if( !draw_rev_ent->GetEntityData(draw_rev_data) ) {
					return FALSE ;
				}

				CStringArray	array2 ;
				if( GFn_SplitSEntityAttr(draw_rev_data, array2) != 3 )
					return FALSE ;

				SXFMapEntAConvC	convent2(&array2) ;
				CString	scale ;
				if( convent2.GetCString(2, scale) < 0 )
					return FALSE ;
				//	�ړx�̎擾
				if( lstrlen(scale) <= 256 ) {
					lstrcpy(attr_info->attr_body.d_scale, (LPCTSTR)scale) ;
				} else {
					//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
					//sprintf(szInstanceId, "#%d", idarray[i]) ;
					sprintf_s(szInstanceId,_countof(szInstanceId), "#%d", idarray[i]) ;
					SXFErrorMsgC::RecordError(SXFNAMELENGTH,
												DEF_DRAUGHTING_DRAWING_REVISION,
												2,
												szInstanceId,
												DEF_DRAUGHTING_DRAWING_REVISION) ;
					// �擪����256�o�C�g�؂���
					lstrcpyn(attr_info->attr_body.d_scale, (LPCTSTR)scale, 256) ;
				}

				int	def_id = 0 ;
				if( convent2.GetInst(1, def_id) < 0 )
					return FALSE ;
				SXFEntityDataC*	def_ent = m_InstanceIDManager->GetEntityDataPtr(def_id) ;
				if( def_ent == NULL )
					return FALSE ;

				CString	def_data ;
				if( !def_ent->GetEntityData(def_data) ) {
					return FALSE ;
				}

				CStringArray	array3 ;
				if( GFn_SplitSEntityAttr(def_data, array3) != 2 )
					return FALSE ;

				SXFMapEntAConvC	convent3(&array3) ;
				CString	d_number, d_type ;
				//	�}�ʔԍ��̎擾
				if( convent3.GetCString(0, d_number) < 0 )
					return FALSE ;
				if( lstrlen(d_number) <= 256 ) {
					lstrcpy(attr_info->attr_body.d_number, (LPCTSTR)d_number) ;
				} else {
					// �擪����256�o�C�g�؂���
					lstrcpyn(attr_info->attr_body.d_number, (LPCTSTR)d_number, 256) ;
				}
				//	�}�ʎ�ʂ̎擾
				if( convent3.GetCString(1, d_type) < 0 )
					return FALSE ;
				if( lstrlen(d_type) <= 256 ) {
					lstrcpy(attr_info->attr_body.d_type, (LPCTSTR)d_type) ;
				} else {
					//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
					//sprintf(szInstanceId, "#%d", def_id) ;
					sprintf_s(szInstanceId,_countof(szInstanceId), "#%d", def_id) ;
					SXFErrorMsgC::RecordError(SXFNAMELENGTH,
												DEF_DRAWING_DEFINITION,
												2,
												szInstanceId,
												DEF_DRAWING_DEFINITION) ;
					// �擪����256�o�C�g�؂���
					lstrcpyn(attr_info->attr_body.d_type, (LPCTSTR)d_type, 256) ;
				}

				m_AttributeTable.Add(attr_info) ;
			}
		}
		return TRUE ;
	}

	//	#5300=CONTRACT_TYPE('\X2\59517D04533A5206\X0\4');
	//	#5310=CONTRACT('\X2\5DE54E8B540D\X0\4','\X2\4E8B696D540D\X0\4',#5300);
	//	#5320=DRAUGHTING_CONTRACT_ASSIGNMENT(#5310,(#5180));
	if( IN_Instance->EntityName == DEF_DRAUGHTING_CONTRACT_ASSIGNMENT ) {

		CStringArray	array1 ;
		if( GFn_SplitSEntityAttr(IN_Instance->EntityData, array1) != 2 )
			return FALSE ;

		SXFMapEntAConvC	convent1(&array1) ;
		int	con_id = 0 ;
		if( convent1.GetInst(0, con_id) < 0 )
			return FALSE ;

		CArray<int,int>	idarray ;
		int	count = 0 ;
		if( convent1.GetSetInst(1, count, idarray) < 0 )
			return FALSE;

		SXFEntityDataC*	con_ent = m_InstanceIDManager->GetEntityDataPtr(con_id) ;
		if( con_ent == NULL )
			return FALSE ;

		CString	con_data ;
		if( !con_ent->GetEntityData(con_data) ) {
			return FALSE ;
		}

		CStringArray	array2 ;
		if( GFn_SplitSEntityAttr(con_data, array2) != 3 )
			return FALSE ;

		SXFMapEntAConvC	convent2(&array2) ;
		CString	c_name, p_name ;
		if( convent2.GetCString(0, c_name) < 0 )
			return FALSE ;
		if( convent2.GetCString(1, p_name) < 0 )
			return FALSE ;

		int	con_type_id = 0 ;
		if( convent2.GetInst(2, con_type_id) < 0 )
			return FALSE ;

		SXFEntityDataC*	con_type_ent = m_InstanceIDManager->GetEntityDataPtr(con_type_id) ;
		if( con_type_ent == NULL )
			return FALSE ;

		CString	con_type_data ;
		if( !con_type_ent->GetEntityData(con_type_data) ) {
			return FALSE ;
		}

		CStringArray	array3 ;
		if( GFn_SplitSEntityAttr(con_type_data, array3) != 1 )
			return FALSE ;

		SXFMapEntAConvC	convent3(&array3) ;
		CString	c_type ;
		if( convent3.GetCString(0, c_type) < 0 )
			return FALSE ;

		for(int i = 0; i < idarray.GetSize(); i++) {
			ATTRIBUTEINFO*	attr_info = GetAttributeInfo(idarray[i]) ;
			if( attr_info != NULL ) {
				//	DRAUGHTING_CONTRACT_ASSIGNMENT�̃C���X�^���XID�ݒ�
				attr_info->id_draug_con_ass = IN_Instance->InstanceID ;
				//	�H�����̎擾
				if( lstrlen(c_name) <= 256 ) {
					lstrcpy(attr_info->attr_body.c_name, (LPCTSTR)c_name) ;
				} else {
					//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
					//sprintf(szInstanceId, "#%d", con_id) ;
					sprintf_s(szInstanceId,_countof(szInstanceId), "#%d", con_id) ;
					SXFErrorMsgC::RecordError(SXFNAMELENGTH,
												DEF_CONTRACT,
												2,
												szInstanceId,
												DEF_CONTRACT) ;
					// �擪����256�o�C�g�؂���
					lstrcpyn(attr_info->attr_body.c_name, (LPCTSTR)c_name, 256) ;
				}
				//	���Ɩ��̎擾
				if( lstrlen(p_name) <= 256 ) {
					lstrcpy(attr_info->attr_body.p_name, (LPCTSTR)p_name) ;
				} else {
					//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
					//sprintf(szInstanceId, "#%d", con_id) ;
					sprintf_s(szInstanceId,_countof(szInstanceId), "#%d", con_id) ;
					SXFErrorMsgC::RecordError(SXFNAMELENGTH,
												DEF_CONTRACT,
												2,
												szInstanceId,
												DEF_CONTRACT) ;
					// �擪����256�o�C�g�؂���
					lstrcpyn(attr_info->attr_body.p_name, (LPCTSTR)p_name, 256) ;
				}
				//	�_��敪�̎擾
				if( lstrlen(c_type) <= 256 ) {
					lstrcpy(attr_info->attr_body.c_type, (LPCTSTR)c_type) ;
				} else {
					//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
					//sprintf(szInstanceId, "#%d", con_type_id) ;
					sprintf_s(szInstanceId,_countof(szInstanceId), "#%d", con_type_id) ;
					SXFErrorMsgC::RecordError(SXFNAMELENGTH,
												DEF_CONTRACT_TYPE,
												2,
												szInstanceId,
												DEF_CONTRACT_TYPE) ;
					// �擪����256�o�C�g�؂���
					lstrcpyn(attr_info->attr_body.c_type, (LPCTSTR)c_type, 256) ;
				}
			}
		}

	//	#5340=APPROVAL_STATUS(' ');
	//	#5350=APPROVAL(#5340,' ');
	//	#5330=CALENDAR_DATE(2002,4,12);
	//	#5360=APPROVAL_DATE_TIME(#5330,#5350);
	} else if( IN_Instance->EntityName == DEF_APPROVAL_DATE_TIME ) {

		CStringArray	array1 ;
		if( GFn_SplitSEntityAttr(IN_Instance->EntityData, array1) != 2 )
			return FALSE ;

		SXFMapEntAConvC	convent1(&array1) ;
		int	cal_id = 0, app_id = 0 ;
		if( convent1.GetInst(0, cal_id) < 0 )
			return FALSE ;
		if( convent1.GetInst(1, app_id) < 0 )
			return FALSE ;

		APPDATETIMEINFO	app_info ;
		app_info.id_cal_date = cal_id ;
		app_info.id_approval = app_id ;
		m_AppTimeTable.Add(app_info) ;

	//	#5370=DRAUGHTING_APPROVAL_ASSIGNMENT(#5350,(#5180));
	} else if( IN_Instance->EntityName == "DRAUGHTING_APPROVAL_ASSIGNMENT" ) {

		CStringArray	array1 ;
		if( GFn_SplitSEntityAttr(IN_Instance->EntityData, array1) != 2 )
			return FALSE ;

		SXFMapEntAConvC	convent1(&array1) ;
		int	app_id = 0 ;
		if( convent1.GetInst(0, app_id) < 0 )
			return FALSE ;

		int	cal_id = -1 ;
		for(int i = 0; i < m_AppTimeTable.GetSize(); i++) {
			if( app_id == m_AppTimeTable[i].id_approval ) {
				cal_id = m_AppTimeTable[i].id_cal_date ;
				break ;
			}
		}
		if( cal_id == -1 ) {
			return FALSE ;
		}

		CArray<int,int>	idarray ;
		int	count = 0 ;
		if( convent1.GetSetInst(1, count, idarray) < 0 )
			return FALSE ;

		SXFEntityDataC*	cal_ent = m_InstanceIDManager->GetEntityDataPtr(cal_id) ;
		if( cal_ent == NULL )
			return FALSE ;

		CString	cal_data ;
		if( !cal_ent->GetEntityData(cal_data) ) {
			return FALSE ;
		}

		CStringArray	array2 ;
		if( GFn_SplitSEntityAttr(cal_data, array2) != 3 )
			return FALSE ;

		SXFMapEntAConvC	convent2(&array2) ;
		int	year, day, month ;
		if( convent2.GetInt(0, year) < 0 )
			return FALSE ;
		if( convent2.GetInt(1, day) < 0 )
			return FALSE ;
		if( convent2.GetInt(2, month) < 0 )
			return FALSE ;

		for(i = 0; i < idarray.GetSize(); i++) {
			ATTRIBUTEINFO*	attr_info = GetAttributeInfo(idarray[i]) ;
			if( attr_info != NULL ) {
				//	�}�ʍ쐬�N(����)�̎擾
				attr_info->attr_body.d_year	= 	year ;
				//	�}�ʍ쐬��(����)�̎擾
				attr_info->attr_body.d_day	= 	day ;
				//	�}�ʍ쐬��(����)�̎擾
				attr_info->attr_body.d_month= 	month ;
			}
		}

	//	#5390=ORGANIZATION_ROLE('creator');
	//	#5380=ORGANIZATION($,'\X2\8A2D8A084F1A793E540D\X0\4',' ');
	//	#5400=DRAUGHTING_ORGANIZATION_ASSIGNMENT(#5380,#5390,(#5180));
	} else if( IN_Instance->EntityName == DEF_DRAUGHTING_ORGANIZATION_ASSIGNMENT ) {

		CStringArray	array1 ;
		if( GFn_SplitSEntityAttr(IN_Instance->EntityData, array1) != 3 )
			return FALSE ;

		SXFMapEntAConvC	convent1(&array1) ;
		int	org_id = 0, rol_id = 0 ;
		if( convent1.GetInst(0, org_id) < 0 )
			return FALSE ;
		if( convent1.GetInst(1, rol_id) < 0 )
			return FALSE ;
		CArray<int,int>	idarray ;
		int	count = 0 ;
		if( convent1.GetSetInst(2, count, idarray) < 0 )
			return FALSE ;

		SXFEntityDataC*	org_ent = m_InstanceIDManager->GetEntityDataPtr(org_id) ;
		if( org_ent == NULL )
			return FALSE ;

		CString	org_data ;
		if( !org_ent->GetEntityData(org_data) ) {
			return FALSE ;
		}

		CStringArray	array2 ;
		int	nCnt = GFn_SplitSEntityAttr(org_data, array2) ;
		if( nCnt > 3 || nCnt < 2 ) {
			return FALSE ;
		}
		SXFMapEntAConvC	convent2(&array2) ;

		SXFEntityDataC*	rol_ent = m_InstanceIDManager->GetEntityDataPtr(rol_id) ;
		if( rol_ent == NULL )
			return FALSE ;

		CString	rol_data ;
		if( !rol_ent->GetEntityData(rol_data) ) {
			return FALSE ;
		}

		CStringArray	array3 ;
		if( GFn_SplitSEntityAttr(rol_data, array3) != 1 )
			return FALSE ;

		SXFMapEntAConvC	convent3(&array3) ;
		CString	rol_name ;
		if( convent3.GetCString(0, rol_name) < 0 )
			return FALSE ;

		CString	name ;
		if( array2.GetSize() == 2 ) {
			if( convent2.GetCString(0, name) < 0 )
				return FALSE ;
		} else {
			if( convent2.GetCString(1, name) < 0 )
				return FALSE ;
		}

		for(int i = 0; i < idarray.GetSize(); i++) {
			ATTRIBUTEINFO*	attr_info = GetAttributeInfo(idarray[i]) ;
			if( attr_info != NULL ) {
				if( !rol_name.CompareNoCase("creator") ) {
					//	�󒍉�Ж��̎擾
					if( lstrlen(name) <= 256 ) {
						lstrcpy(attr_info->attr_body.c_contractor, (LPCTSTR)name) ;
					} else {
						//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
						//sprintf(szInstanceId, "#%d", org_id) ;
						sprintf_s(szInstanceId,_countof(szInstanceId), "#%d", org_id) ;
						SXFErrorMsgC::RecordError(SXFNAMELENGTH,
													DEF_ORGANIZATION,
													2,
													szInstanceId,
													DEF_ORGANIZATION) ;
						// �擪����256�o�C�g�؂���
						lstrcpyn(attr_info->attr_body.c_contractor, (LPCTSTR)name, 256) ;
					}
				} else if( !rol_name.CompareNoCase("owner") ) {
					//	�������ƎҖ��̎擾
					if( lstrlen(name) <= 256 ) {
						lstrcpy(attr_info->attr_body.c_owner, (LPCTSTR)name) ;
					} else {
						//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
						//sprintf(szInstanceId, "#%d", org_id) ;
						sprintf_s(szInstanceId,_countof(szInstanceId), "#%d", org_id) ;
						SXFErrorMsgC::RecordError(SXFNAMELENGTH,
													DEF_ORGANIZATION,
													2,
													szInstanceId,
													DEF_ORGANIZATION) ;
						// �擪����256�o�C�g�؂���
						lstrcpyn(attr_info->attr_body.c_owner, (LPCTSTR)name, 256) ;
					}
				}
			}
		}
	}

	return TRUE ;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp                    �쐬���F2001.06.10
//
//	�P�D�@�\�T�v
//		DRAUGHTING_CONTRACT_ASSIGNMENT�̃C���X�^���XID��ԋp����
//
//	�Q�D�C���^�[�t�F�[�X
//		int SXFTableManagerC::GetAttributeID()
//
//		����:	�^				������			���e
//			�Ȃ�
//
//		���A�l	
//			���펞�F�C���X�^���XID
//			�ُ펞�F-1
//
//	�R�D����
//		����ԍ�	���t��			�S����		�T�v
//		�쐬		2004.01.30		K.Naono		Ver3.0�Ή�
//
//------------------------------------------------------------
int SXFTableManagerC::GetAttributeID()
{
	if( m_id_draug_drw_rev == -1 ) {
		return -1 ;
	}

	//	�J�����g��DRAUGHTING_DRAWING_REVISION�ɑΉ�����
	//	DRAUGHTING_CONTRACT_ASSIGNMENT�̃C���X�^���XID����������
	for(int i = 0; i < m_AttributeTable.GetSize(); i++) {
		if( m_AttributeTable[i]->id_draug_drw_rev == m_id_draug_drw_rev ) {
			return m_AttributeTable[i]->id_draug_con_ass ;
		}
	}

	return -1 ;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp                    �쐬���F2001.06.10
//
//	�P�D�@�\�T�v
//		�w�肵��DRAUGHTING_DRAWING_REVISION�̐}�ʕ\�藓����
//		�ԋp����
//
//	�Q�D�C���^�[�t�F�[�X
//		ATTRIBUTEINFO* SXFTableManagerC::GetAttributeInfo(int inID)
//
//		����:	�^				������			���e
//				int				inID		�C���X�^���XID
//
//		���A�l	
//			���펞�F�}�ʕ\�藓���
//			�ُ펞�FNULL
//
//	�R�D����
//		����ԍ�	���t��			�S����		�T�v
//		�쐬		2004.01.30		K.Naono		Ver3.0�Ή�
//
//------------------------------------------------------------
ATTRIBUTEINFO* SXFTableManagerC::GetAttributeInfo(int inID) {

	//	DRAUGHTING_DRAWING_REVISION�ɑΉ�����}�ʕ\�藓��������
	for(int i = 0; i < m_AttributeTable.GetSize(); i++) {
		if( m_AttributeTable[i]->id_draug_drw_rev == inID ) {
			return m_AttributeTable[i] ;
		}
	}
	return NULL ;
}
