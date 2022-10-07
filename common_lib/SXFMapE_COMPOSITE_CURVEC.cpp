/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_COMPOSITE_CURVEC.cpp								�쐬���F2000.3.29

	�P�D�N���X�T�v
	

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.29			�{��(FQS)			�Ȃ��B

**/
#include "stdafx.h"
//#include <afxtempl.h>
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"

#include "SXFMapE_COMPOSITE_CURVEC.h"
#include "SXFMapE_COMPOSITE_CURVE_SEGMENTC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.cpp								�쐬���F2000.3.29

	�P�D�@�\�T�v
	�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFMapE_COMPOSITE_CURVEC::SXFMapE_COMPOSITE_CURVEC()
	����:	�^				������			���e
			�Ȃ��B

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.29			�{��(FQS)			�Ȃ��B

**/
SXFMapE_COMPOSITE_CURVEC::SXFMapE_COMPOSITE_CURVEC()
{
	m_EntityName = DEF_ANNOTATION_FILL_AREA;

	m_SegmentCount = 0;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.cpp								�쐬���F2000.3.29

	�P�D�@�\�T�v
	�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFMapE_COMPOSITE_CURVEC::SXFMapE_COMPOSITE_CURVEC(
					SXFInstanceIDC* IN_InstanceIDManeger)
	:SXFMapEntityBaseC(IN_InstanceIDManeger)

	����:	�^				������			���e
			SXFInstanceIDC* IN_InstanceIDManeger

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.29			�{��(FQS)			�Ȃ��B

**/
SXFMapE_COMPOSITE_CURVEC::SXFMapE_COMPOSITE_CURVEC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_ANNOTATION_FILL_AREA;
	m_SegmentCount = 0;

}


/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.cpp								�쐬���F2000.3.29

	�P�D�@�\�T�v
	�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFMapE_COMPOSITE_CURVEC::~SXFMapE_COMPOSITE_CURVEC()
	����:	�^				������			���e
			�Ȃ��B

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.29			�{��(FQS)			�Ȃ��B

**/
SXFMapE_COMPOSITE_CURVEC::~SXFMapE_COMPOSITE_CURVEC()
{
	for(int i=0;i<m_SegmentArray_p.GetSize();i++){
		if( m_SegmentArray_p[i] != NULL)
			delete m_SegmentArray_p[i];
	}
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.cpp								�쐬���F2000.3.29

	�P�D�@�\�T�v
	

	�Q�D�C���^�[�t�F�[�X
	int SXFMapE_COMPOSITE_CURVEC::SetParameter( )
	����:	�^				������			���e
			�Ȃ��B

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.29			�{��(FQS)			�Ȃ��B

**/
int SXFMapE_COMPOSITE_CURVEC::SetParameter( )
{

	SXFMapEntAConvC convert(m_EntityArray);

	if ( convert.GetCString(0,m_Name) < 0 ){
		SXFErrorMsgC::RecordError( SXFPARAMS,
								m_EntityName,
								2,
								m_RootID,
								m_EntityName
								);
		return SXFPARAMS;
	}

	if ( convert.GetSetInst(1, m_SegmentCount, m_SegmentArray_Inst) < 0 ){
		SXFErrorMsgC::RecordError( SXFPARAMS,
								m_EntityName,
								2,
								m_RootID,
								m_EntityName
								);
		return SXFPARAMS;
	}

	convert.GetBOOL(2,m_Intersect);	

//	�s�v���� ///////////////////////////////////////////////////////////////

	for(int i=0;i<m_SegmentCount;i++){
		SXFMapE_COMPOSITE_CURVE_SEGMENTC* temp_p = 
			new SXFMapE_COMPOSITE_CURVE_SEGMENTC(m_InstanceIDManager);
		m_SegmentArray_p.Add(temp_p);

		int ircode = temp_p->SetRootID(m_SegmentArray_Inst[i]);
		if ( ircode < 0 )
			return ircode ;
		ircode = temp_p->SetParameter();
		if ( ircode < 0 )
			return ircode ;
	}

	return 0;
}
