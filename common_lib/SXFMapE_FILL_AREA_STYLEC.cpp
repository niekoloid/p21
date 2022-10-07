/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_FILL_AREA_STYLEC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		FILL_AREA_STYLE���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include <afxtempl.h>
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapE_EXTERNALLY_DEFINED_HATCHC.h"
#include "SXFMapE_FILL_AREA_STYLE_COLOURC.h"
#include "SXFMapE_FILL_AREA_STYLE_HATCHINGC.h"
#include "SXFMapE_FILL_AREA_STYLE_TILEC.h"
#include "SXFMapE_FILL_AREA_STYLEC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_FILL_AREA_STYLEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_FILL_AREA_STYLEC::SXFMapE_FILL_AREA_STYLEC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_FILL_AREA_STYLEC::SXFMapE_FILL_AREA_STYLEC()
{
	m_EntityName = DEF_FILL_AREA_STYLE;

	m_FillStyle_Count = 0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_FILL_AREA_STYLEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�C���X�^���X�h�c�ւ̃|�C���^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_FILL_AREA_STYLEC::SXFMapE_FILL_AREA_STYLEC(
						SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	���� �F	�^				������				���e
			SXFInstanceIDC* IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_FILL_AREA_STYLEC::SXFMapE_FILL_AREA_STYLEC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_FILL_AREA_STYLE;

	m_FillStyle_Count = 0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_FILL_AREA_STYLEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_FILL_AREA_STYLEC::~SXFMapE_FILL_AREA_STYLEC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_FILL_AREA_STYLEC::~SXFMapE_FILL_AREA_STYLEC()
{

	for(int i=0;i<m_FillStyleArray_p.GetSize();i++){
		if(m_FillStyleArray_p[i]!=NULL){
			if( m_FillStyle_Name[i]==DEF_EXTERNALLY_DEFINED_HATCH_STYLE)
				 delete (SXFMapE_EXTERNALLY_DEFINED_HATCHC*)m_FillStyleArray_p[i];

			if( m_FillStyle_Name[i]==DEF_FILL_AREA_STYLE_COLOUR)
				 delete (SXFMapE_FILL_AREA_STYLE_COLOURC*)m_FillStyleArray_p[i];

			if( m_FillStyle_Name[i]==DEF_FILL_AREA_STYLE_HATCHING)
				 delete (SXFMapE_FILL_AREA_STYLE_HATCHINGC*)m_FillStyleArray_p[i];

			if( m_FillStyle_Name[i]==DEF_FILL_AREA_STYLE_TILES)
				 delete (SXFMapE_FILL_AREA_STYLE_TILEC*)m_FillStyleArray_p[i];
		}
	}

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_FILL_AREA_STYLEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�̃p�����^�ݒ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_FILL_AREA_STYLEC::SetParameter()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int SXFMapE_FILL_AREA_STYLEC::SetParameter( )
{
	int ircode;

	SXFMapEntAConvC convent(m_EntityArray);

	//�����G���[
	if ( convent.GetCString(0,m_Name) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//�����G���[
	if ( convent.GetSetInst(1,m_FillStyle_Count,m_FillStyleArray_Inst ) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	for(int i=m_FillStyle_Count-1;i>=0;i--){

		CString InstEntityName;
		//Fill_Style���擾���A���ʂ���B
		InstEntityName = SXFMapInstIDC::GetEntityName(m_FillStyleArray_Inst[i]);

		//EXTERNALLY_DEFINED_HATCH_STYLE
		if (InstEntityName ==DEF_EXTERNALLY_DEFINED_HATCH_STYLE){
			m_FillStyle_Name.Add( DEF_EXTERNALLY_DEFINED_HATCH_STYLE );

			SXFMapE_EXTERNALLY_DEFINED_HATCHC* tempptr = 
				new SXFMapE_EXTERNALLY_DEFINED_HATCHC(m_InstanceIDManager );
			m_FillStyleArray_p.Add((SXFMapE_EXTERNALLY_DEFINED_HATCHC*)tempptr);

			ircode = tempptr->SetRootID(m_FillStyleArray_Inst[i]);
			if ( ircode < 0 )
				return ircode ;
			ircode = tempptr->SetParameter();
			if ( ircode < 0 )
				return ircode ;
		}
		//FILL_AREA_STYLE_COLOUR
		else if (InstEntityName ==DEF_FILL_AREA_STYLE_COLOUR){
			m_FillStyle_Name.Add( DEF_FILL_AREA_STYLE_COLOUR );

			SXFMapE_FILL_AREA_STYLE_COLOURC* tempptr = 
				new SXFMapE_FILL_AREA_STYLE_COLOURC(m_InstanceIDManager );
			m_FillStyleArray_p.Add((SXFMapE_FILL_AREA_STYLE_COLOURC*)tempptr);

			ircode = tempptr->SetRootID(m_FillStyleArray_Inst[i]);
			if ( ircode < 0 )
				return ircode ;
			ircode = tempptr->SetParameter();
			if ( ircode < 0 )
				return ircode ;
		}
    	// FILL_AREA_STYLE_HATCHING
		else if (InstEntityName ==DEF_FILL_AREA_STYLE_HATCHING){
			m_FillStyle_Name.Add ( DEF_FILL_AREA_STYLE_HATCHING );
			SXFMapE_FILL_AREA_STYLE_HATCHINGC* tempptr = 
				new SXFMapE_FILL_AREA_STYLE_HATCHINGC(m_InstanceIDManager );
			m_FillStyleArray_p.Add((SXFMapE_FILL_AREA_STYLE_HATCHINGC*)tempptr);

			ircode = tempptr->SetRootID(m_FillStyleArray_Inst[i]);
			if ( ircode < 0 )
				return ircode ;
			ircode = tempptr->SetParameter();
			if ( ircode < 0 )
				return ircode ;
		}
		// FILL_AREA_STYLE_TILES
		else if (InstEntityName ==DEF_FILL_AREA_STYLE_TILES){
			m_FillStyle_Name.Add (DEF_FILL_AREA_STYLE_TILES );
			SXFMapE_FILL_AREA_STYLE_TILEC* tempptr = 
				new SXFMapE_FILL_AREA_STYLE_TILEC(m_InstanceIDManager );
			m_FillStyleArray_p.Add((SXFMapE_FILL_AREA_STYLE_TILEC*)tempptr);

			ircode = tempptr->SetRootID(m_FillStyleArray_Inst[i]);
			if ( ircode < 0 )
				return ircode ;
			ircode = tempptr->SetParameter();
			if ( ircode < 0 )
				return ircode ;
		}
		else {
			//err
		}
	}

	return 0;
}
