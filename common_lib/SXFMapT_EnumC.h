/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapT_EnumC.h						�쐬���F2000.04.21

	�P�D�@�\�T�v
		�񋓌^���`����

	�Q�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.21	
**/

#ifndef _SXFMAPT_ENUMC_H_
#define	_SXFMAPT_ENUMC_H_

//#include "SXFErrorMsgC.h"

//< ANNOTATION_OCCURRENCE�n >/////////////////////////////////////
//		0:�s�� 1:Curve 2:Symbol 3:Fill 4:Text

typedef enum E_AnnoKindtype{
	NONSTYLE,		//		0:�s��
	CURVESTYLE,
	SYMBOLSTYLE,
	FILLSTYLE,
	TEXTSTYLE,
	NULLSTYLE
}E_AnnoKind;

//< ANNOTATION_CURVE_OCCURRENCE�̎�� >////////////////////////////
typedef enum E_CurveKindtype{
	NONCURVE,			//0:�s��
	CURVE,				//1:��ʗv�f
	DIMENSION_CURVE,	//2:���@���i���`�j
	PROJECTION_CURVE,	//3:���@�⏕��
	LEADER_CURVE		//4:���o���i���`�j
}E_CurveKind;

//< ANNOTATION_SYMBOL_OCCURRENCE�̎�� >////////////////////////////
typedef enum E_SymbolKindtype{
	NONSYMBOL,							//0:�s��
	SYMBOL,								//1:�_�}�[�J�A����`�i�O����`�j�A���̑��V���{��
	DIM_CURVE_TERMINATOR,				//2:���@�[�_���
	LEADER_TERMINATOR,					//3:�����o�����A�o���[���[�_���
	SUBFIGURE_OCCURRENCE		//4:�����}�`�z�u�iSUbfigure�j
}E_SymbolKind;

#endif

