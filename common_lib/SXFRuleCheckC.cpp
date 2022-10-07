/**
	All Rights Reserved,(c) JACIC 2001
	SXFRuleCheckC.cpp								�쐬���F2001.06.19

	�P�D�N���X�T�v
	�t�B�[�`���̃��[���`�F�b�N���s��

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.19			���X��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFRuleCheckC.h"
#include "SXFStruct.h"
#include "SXFErrorMsgC.h"
#include "SXFTableManagerC.h"
#include "SXFWriteManagerC.h"
#include "SXFComInfoC.h"
#include "SXFReadAP202ManagerC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFRuleCheckC.cpp								�쐬���F2001.06.19

	�P�D�N���X�T�v

	�Q�D�C���^�[�t�F�[�X
	void	SXFRuleCheckC::SXFRuleCheckC()
	����:	�^				������			���e
			�Ȃ��B

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.19			���X��(FQS)			�Ȃ��B

**/
SXFRuleCheckC::SXFRuleCheckC()
{
	m_ReadAP202Manager = NULL;
	m_WriteManager = NULL;
	m_TableManager = NULL;
	m_ComInfo = NULL;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFRuleCheckC.cpp								�쐬���F2001.06.19

	�P�D�N���X�T�v

	�Q�D�C���^�[�t�F�[�X
	void	SXFRuleCheckC::~SXFRuleCheckC()
	����:	�^				������			���e
			�Ȃ��B

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.19			���X��(FQS)			�Ȃ��B

**/
SXFRuleCheckC::~SXFRuleCheckC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFRuleCheckC.cpp								�쐬���F2001.06.19

	�P�D�N���X�T�v

	�Q�D�C���^�[�t�F�[�X
	int	TableRuleCheck(int IN_Type, LPVOID IN_Struct)
	����:	�^				������			���e
			int				IN_Type
			LPVOID 			IN_Struct

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.19			���X��(FQS)			�Ȃ��B

**/
int SXFRuleCheckC::TableRuleCheck(int IN_Type, LPVOID IN_Struct)
{
	int error_code = 0;
	int RWFlag = -1;
	m_ComInfo->Get_RWFlag(RWFlag);

	switch(IN_Type){
	//���C��
	case 1:
		error_code = m_Layer_check.Feature_rule_check((Layer_Struct*)IN_Struct,m_TableManager,m_ComInfo);
		break;
	//����`�F
	case 2:
		error_code = m_PreColour_check.Feature_rule_check((Predefined_Colour_Struct*)IN_Struct,m_TableManager,m_ComInfo);
		break;
	//���[�U��`�F
	case 3:
		//WRITE
		if (RWFlag == 1)
			error_code = m_Usercolor_check.Feature_rule_check((Userdefined_Colour_Struct*)IN_Struct);
		break;
	//����`����
	case 4:
		error_code = m_PreType_check.Feature_rule_check((Predefined_Linetype_Struct*)IN_Struct,m_TableManager,m_ComInfo);
		break;
	case 5:
		//WRITE
		if (RWFlag == 1){
			error_code = m_Usertype_check.Feature_rule_check((Userdefined_Linetype_Struct*)IN_Struct,m_TableManager,m_ComInfo);
		}
		break;
	//����
	case 6:
		error_code = m_Width_check.Feature_rule_check((Line_Width_Struct*)IN_Struct,m_TableManager,m_ComInfo);
		break;
	//�����t�H���g
	case 7:
		error_code = m_TextFont_check.Feature_rule_checkC((Text_Font_Struct*)IN_Struct,m_TableManager,m_ComInfo);
		break;
	default:
		SXFErrorMsgC::RecordError(SXFTABLETYPEERR,"",1,IN_Type);
		return SXFTABLETYPEERR;
	}
	return error_code;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFRuleCheckC.cpp								�쐬���F2001.06.19

	�P�D�N���X�T�v

	�Q�D�C���^�[�t�F�[�X
	int	AssemblyRuleCheck(int IN_Type, LPVOID IN_Struct)
	����:	�^				������			���e
			int 			IN_Type
			LPVOID 			IN_Struct

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.19			���X��(FQS)			�Ȃ��B

**/
int SXFRuleCheckC::AssemblyRuleCheck(int IN_Type, LPVOID IN_Struct)
{
	int error_code = 0;
	int RWFlag = -1;
	m_ComInfo->Get_RWFlag(RWFlag);

	switch(IN_Type){
	case 1:
		//WRITE
		if (RWFlag == 1){
			error_code = m_Sheet_check.Feature_rule_check((Sheet_Struct*)IN_Struct);
		}
		m_SfigFlag = -1;
		break;
	case 2:
		m_SfigFlag = ((Sfigorg_Struct*)IN_Struct)->flag;
		//WRITE
		if (RWFlag == 1){
			//�������O�ł��łɒ�`����Ă���
			if (!m_WriteManager->CheckSameSfig(((Sfigorg_Struct*)IN_Struct)->name)){
				SXFErrorMsgC::RecordError(SXFSAMENAME,DEF_SFIG_ORG,1,((Sfigorg_Struct*)IN_Struct)->name);
				return SXFSAMENAME;
			}
			error_code = m_Sfigorg_check.Feature_rule_check((Sfigorg_Struct*)IN_Struct,m_InstanceID);
		}
		break;
	case 3:
		m_SfigFlag = -1;
		error_code = m_Ccurveorg_check.Feature_rule_check((Ccurve_Org_Struct*)IN_Struct,m_TableManager,m_InstanceID);
		break;
	default:
		SXFErrorMsgC::RecordError(SXFASSEMTYPEERR,"",1,IN_Type);
		return SXFASSEMTYPEERR;
	}
	return error_code;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFRuleCheckC.cpp								�쐬���F2001.06.19

	�P�D�N���X�T�v

	�Q�D�C���^�[�t�F�[�X
	int	FeatureRuleCheck(int IN_AssemType,char *IN_Type, LPVOID IN_Struct)
	����:	�^				������			���e
			int 			IN_AssemType
			char 			*IN_Type
			LPVOID 			IN_Struct

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.19			���X��(FQS)			�Ȃ��B

**/
int SXFRuleCheckC::FeatureRuleCheck(int IN_AssemType,char *IN_Type, LPVOID IN_Struct)
{
	int error_code = 0;
	int rw_flg = -1;
	m_ComInfo->Get_RWFlag(rw_flg);
	//Assembly not open
	if (IN_AssemType == -1){
		SXFErrorMsgC::RecordError(SXFNOTASSEMBLY,IN_Type,0);
		return SXFNOTASSEMBLY;
	}
	/** �_�}�[�J **/
	if (strcmp(IN_Type,DEF_POINT_MARKER) == 0){
		/** �����Ȑ���ɔz�u�ł��Ȃ� **/
		if (IN_AssemType == 3){
			SXFErrorMsgC::RecordError(SXFNOTCURVE,IN_Type,1,IN_Type);
			return SXFNOTCURVE;
		}
		error_code = m_Point_Marker_check.Feature_rule_check(
													(Point_Marker_Struct*)IN_Struct,
													m_TableManager,
													m_InstanceID);
	}

//	ADD(S)	Ver3.0�Ή�	K.Naono	04.01.30
	/** �}�ʕ\�藓 **/
	else if (strcmp(IN_Type,DEF_ATTRIBUTE) == 0){
		/** �����Ȑ���ɔz�u�ł��Ȃ� **/
		if (IN_AssemType == 3){
			SXFErrorMsgC::RecordError(SXFNOTCURVE,IN_Type,1,IN_Type);
			return SXFNOTCURVE;
		}
		error_code = m_Attribute_check.Feature_rule_check(
										(Attribute_Struct*)IN_Struct,
										m_TableManager,
										m_InstanceID) ;
		if( IN_AssemType != 2 ) {
			return error_code ;
		}

		/** �p���܂��́A�����}�ȊO�ɂ͔z�u�ł��Ȃ� **/
		if( m_SfigFlag != 1 && m_SfigFlag != 2) {
			TRACE0("�p���܂��́A�����}�ȊO�ɂ͔z�u�ł��܂���...\n") ;
			SXFErrorMsgC::RecordError(SXFNOTATTRIBUTE,IN_Type,1,IN_Type) ;
			return SXFNOTATTRIBUTE ;
		}
	}
//	ADD(E)	Ver3.0�Ή�	K.Naono	04.01.30

	/** ���� **/
	else if (strcmp(IN_Type,DEF_LINE) == 0){
		/** �����Ȑ���ɔz�u�ł��Ȃ� **/
		if (IN_AssemType == 3){
			SXFErrorMsgC::RecordError(SXFNOTCURVE,IN_Type,1,IN_Type);
			return SXFNOTCURVE;
		}
		error_code = m_Line_check.Feature_rule_check((Line_Struct*)IN_Struct,
													m_TableManager,
													m_InstanceID,
													m_ComInfo);
	}
	/** �����v�f **/
	else if (strcmp(IN_Type,DEF_TEXT) == 0){
		/** �����Ȑ���ɔz�u�ł��Ȃ� **/
		if (IN_AssemType == 3){
			SXFErrorMsgC::RecordError(SXFNOTCURVE,IN_Type,1,IN_Type);
			return SXFNOTCURVE;
		}
		error_code = m_Text_String_check.Feature_rule_check(
												(Text_Struct*)IN_Struct,
												m_TableManager,
												m_InstanceID);
	}
	/** �~�� **/
	else if (strcmp(IN_Type,DEF_ARC) == 0){
		error_code = m_Arc_check.Feature_rule_check((Arc_Struct*)IN_Struct,
														m_TableManager,
														IN_AssemType,
														m_InstanceID,
														m_ComInfo);
	}
	/** �~ **/
	else if (strcmp(IN_Type,DEF_CIRCLE) == 0){
		/** �����Ȑ���ɔz�u�ł��Ȃ� **/
		if (IN_AssemType == 3){
			SXFErrorMsgC::RecordError(SXFNOTCURVE,IN_Type,1,IN_Type);
			return SXFNOTCURVE;
		}
		error_code = m_Circle_check.Feature_rule_check((Circle_Struct*)IN_Struct,
															m_TableManager,
															m_InstanceID);
	}
	/** �ȉ~ **/
	else if (strcmp(IN_Type,DEF_ELLIPSE) == 0){
		/** �����Ȑ���ɔz�u�ł��Ȃ� **/
		if (IN_AssemType == 3){
			SXFErrorMsgC::RecordError(SXFNOTCURVE,IN_Type,1,IN_Type);
			return SXFNOTCURVE;
		}
		error_code = m_Ellipse_check.Feature_rule_check(
												(Ellipse_Struct*)IN_Struct,
												m_TableManager,
												m_InstanceID);
	}
	/** �ȉ~�� **/
	else if (strcmp(IN_Type,DEF_ELLIPSE_ARC) == 0){
		error_code = m_Ellipse_Arc_check.Feature_rule_check(
												(Ellipse_Arc_Struct*)IN_Struct,
												m_TableManager,
												IN_AssemType,
												m_InstanceID,
												m_ComInfo);
	}
	/** �ܐ� **/
	else if (strcmp(IN_Type,DEF_POLYLINE) == 0){
		error_code = m_Polyline_check.Feature_rule_check(
												(Polyline_Struct*)IN_Struct,
												m_TableManager,
												IN_AssemType,
												m_InstanceID,
												m_ComInfo);
	}
	/** �X�v���C�� **/
	else if (strcmp(IN_Type,DEF_SPLINE) == 0){
		error_code = m_Spline_check.Feature_rule_check((Spline_Struct*)IN_Struct,
															m_TableManager,
															IN_AssemType,
															m_InstanceID);
	}
	/** �N���\�C�h **/
	else if (strcmp(IN_Type,DEF_CLOTHOID) == 0){
		error_code = m_Clothoid_check.Feature_rule_check((Clothoid_Struct*)IN_Struct,
															m_TableManager,
															IN_AssemType,
															m_InstanceID,
															m_ComInfo);
	}
	/** �������@ **/
	else if (strcmp(IN_Type,DEF_LINEAR_DIMENSION) == 0){
		/** �����Ȑ���ɔz�u�ł��Ȃ� **/
		if (IN_AssemType == 3){
			SXFErrorMsgC::RecordError(SXFNOTCURVE,IN_Type,1,IN_Type);
			return SXFNOTCURVE;
		}
		error_code = m_LinearDim_check.Feature_rule_check(
												(LinearDim_Struct*)IN_Struct,
												m_TableManager,
												m_InstanceID,
												m_ComInfo);
	}
	/** �ʒ����@ **/
	else if (strcmp(IN_Type,DEF_CURVE_DIMENSION) == 0){
		/** �����Ȑ���ɔz�u�ł��Ȃ� **/
		if (IN_AssemType == 3){
			SXFErrorMsgC::RecordError(SXFNOTCURVE,IN_Type,1,IN_Type);
			return SXFNOTCURVE;
		}
		error_code = m_CurveDim_check.Feature_rule_check(
												(CurveDim_Struct*)IN_Struct,
												m_TableManager,
												m_InstanceID,
												m_ComInfo);
	}
	/** �p�x���@ **/
	else if (strcmp(IN_Type,DEF_ANGULAR_DIMENSION) == 0){
		/** �����Ȑ���ɔz�u�ł��Ȃ� **/
		if (IN_AssemType == 3){
			SXFErrorMsgC::RecordError(SXFNOTCURVE,IN_Type,1,IN_Type);
			return SXFNOTCURVE;
		}
		error_code = m_AngularDim_check.Feature_rule_check(
												(AngularDim_Struct*)IN_Struct,
												m_TableManager,
												m_InstanceID,
												m_ComInfo);
	}
	/** ���a���@ **/
	else if (strcmp(IN_Type,DEF_RADIUS_DIMENSION) == 0){
		/** �����Ȑ���ɔz�u�ł��Ȃ� **/
		if (IN_AssemType == 3){
			SXFErrorMsgC::RecordError(SXFNOTCURVE,IN_Type,1,IN_Type);
			return SXFNOTCURVE;
		}
		error_code = m_RadiusDim_check.Feature_rule_check(
												(RadiusDim_Struct*)IN_Struct,
												m_TableManager,
												m_InstanceID,
												m_ComInfo);
	}
	/** ���a���@ **/
	else if (strcmp(IN_Type,DEF_DIAMETER_DIMENSION) == 0){
		/** �����Ȑ���ɔz�u�ł��Ȃ� **/
		if (IN_AssemType == 3){
			SXFErrorMsgC::RecordError(SXFNOTCURVE,IN_Type,1,IN_Type);
			return SXFNOTCURVE;
		}
		error_code = m_DiameterDim_check.Feature_rule_check(
												(DiameterDim_Struct*)IN_Struct,
												m_TableManager,
												m_InstanceID,
												m_ComInfo);
	}
	/** ���o���� **/
	else if (strcmp(IN_Type,DEF_LABEL) == 0){
		/** �����Ȑ���ɔz�u�ł��Ȃ� **/
		if (IN_AssemType == 3){
			SXFErrorMsgC::RecordError(SXFNOTCURVE,IN_Type,1,IN_Type);
			return SXFNOTCURVE;
		}
		error_code = m_Label_check.Feature_rule_check(
												(Label_Struct*)IN_Struct,
												m_TableManager,
												m_InstanceID,
												m_ComInfo);
	}
	/** �o���[�� **/
	else if (strcmp(IN_Type,DEF_BALLOON) == 0){
		/** �����Ȑ���ɔz�u�ł��Ȃ� **/
		if (IN_AssemType == 3){
			SXFErrorMsgC::RecordError(SXFNOTCURVE,IN_Type,1,IN_Type);
			return SXFNOTCURVE;
		}
		error_code = m_Balloon_check.Feature_rule_check(
												(Balloon_Struct*)IN_Struct,
												m_TableManager,
												m_InstanceID,
												m_ComInfo);
	}
	/** ����`�V���{�� **/
	else if (strcmp(IN_Type,DEF_EXTERNALLY_DEFINED_SYMBOL) == 0){
		/** �����Ȑ���ɔz�u�ł��Ȃ� **/
		if (IN_AssemType == 3){
			SXFErrorMsgC::RecordError(SXFNOTCURVE,IN_Type,1,IN_Type);
			return SXFNOTCURVE;
		}
		error_code = m_ExSymbol_check.Feature_rule_check(
								(Externally_Defined_Symbol_Struct*)IN_Struct,
								m_TableManager,
								m_InstanceID);
	}
	/** �����}�`�z�u **/
	else if (strcmp(IN_Type,DEF_SFIG_LOCATE) == 0){
		int SfigLocType,LocFlg;
		//�����Ȑ��ɂ͔z�u�ł��Ȃ��B
		if (IN_AssemType == 3){
			SXFErrorMsgC::RecordError(SXFNOTCURVE,IN_Type,1,IN_Type);
			return SXFNOTCURVE;
		}
		//WRITE
		if (rw_flg == 1){
			/** �����}�`��ʁA�z�u�t���O�擾 **/
			if (!m_WriteManager->GetSfigFlg(((Sfigloc_Struct*)IN_Struct)->name,
											&SfigLocType,&LocFlg)){
				/** ��`����Ă��Ȃ� **/
				SXFErrorMsgC::RecordError(SXFNOTSETCFIG,
											IN_Type,
											3,
											"-",
											((Sfigloc_Struct*)IN_Struct)->name,
											IN_Type);
				return SXFNOTSETCFIG;
			}
			/** �����}�z�u **/
			if (SfigLocType == 1 || SfigLocType == 2){
				/** ���ɔz�u�ς�(�����z�u�s��) **/
				if (LocFlg == 1){
					SXFErrorMsgC::RecordError(SXFSFIGLOCONE,
											IN_Type,
											3,
											m_InstanceID,
											((Sfigloc_Struct*)IN_Struct)->name,
											IN_Type);
					return SXFSFIGLOCONE;
				}
				/** �����}��ɕ����}�͔z�u�ł��Ȃ� **/
				if (m_SfigFlag == 1 || m_SfigFlag == 2){
					SXFErrorMsgC::RecordError(SXFSFIGERROR,
												IN_Type,
												2,
												"-",
												IN_Type);
					return SXFSFIGERROR;
				}
				/** ��}�O���[�v��ɕ����}�͔z�u�ł��Ȃ� */
				else if (m_SfigFlag == 3){
					SXFErrorMsgC::RecordError(SXFGROUPERROR,
												IN_Type,
												2,
												"-",
												IN_Type);
					return SXFSFIGERROR;
				}
				/** ��}���i�ɂ͕����}��z�u�ł��Ȃ� **/
				else if (m_SfigFlag == 4){
					SXFErrorMsgC::RecordError(SXFPARTERROR,
												IN_Type,
												1,
												IN_Type);
					return SXFPARTERROR;
				}
			}
			/** �O���[�v�z�u **/
			else if (SfigLocType == 3){
				/** ���ɔz�u�ς�(�����z�u�s��) **/
				if (LocFlg == 1){
					SXFErrorMsgC::RecordError(SXFSFIGLOCONE,
											IN_Type,
											3,
											m_InstanceID,
											((Sfigloc_Struct*)IN_Struct)->name,
											IN_Type);
					return SXFSFIGLOCONE;
				}
				/** ��}���i��ɂ̓O���[�v��z�u�ł��Ȃ� **/
				if (m_SfigFlag == 4){
					SXFErrorMsgC::RecordError(SXFPARTERROR,IN_Type,1,IN_Type);
					return SXFPARTERROR;
				}
			}
			error_code = m_Sfigloc_check.Feature_rule_check(
											(Sfigloc_Struct*)IN_Struct,
											m_TableManager,
											m_InstanceID);
			if (!error_code)
				/** �z�u�t���OON **/
				m_WriteManager->SetLocFlg(((Sfigloc_Struct*)IN_Struct)->name);
		}
		//Read
		else if (rw_flg == 0){
			//�����}�`���ݒ肳��Ă��Ȃ��i�e�[�u���ɂȂ��j
			if (!m_ReadAP202Manager->GetSfigFlg(((Sfigloc_Struct*)IN_Struct)->name,
													&SfigLocType,
													&LocFlg)){
				SXFErrorMsgC::RecordError(SXFNOTSETCFIG,
											IN_Type,
											3,
											"-",
											((Sfigloc_Struct*)IN_Struct)->name,
											IN_Type);
				return SXFNOTSETCFIG;
			}
			/** �����}�z�u **/
			if (SfigLocType == 1 || SfigLocType == 2){
				/** ���ɔz�u�ς�(�����z�u�s��) **/
				if (LocFlg == 1){
					SXFErrorMsgC::RecordError(SXFSFIGLOCONE,
												IN_Type,
												3,
												m_InstanceID,
												((Sfigloc_Struct*)IN_Struct)->name,
												IN_Type);
					return SXFSFIGLOCONE;
				}
				/** �����}��ɕ����}�͔z�u�ł��Ȃ� **/
				if (m_SfigFlag == 1 || m_SfigFlag == 2){
					SXFErrorMsgC::RecordError(SXFSFIGERROR,
												IN_Type,
												2,
												"-",
												IN_Type);
					return SXFSFIGERROR;
				}
				/** ��}�O���[�v��ɕ����}�͔z�u�ł��Ȃ� */
				else if (m_SfigFlag == 3){
					SXFErrorMsgC::RecordError(SXFGROUPERROR,
												IN_Type,
												2,
												"-",
												IN_Type);
					return SXFSFIGERROR;
				}
				/** ��}���i��ɂ͕����}��z�u�ł��Ȃ� **/
				else if (m_SfigFlag == 4){
					SXFErrorMsgC::RecordError(SXFPARTERROR,
												IN_Type,
												1,
												IN_Type);
					return SXFPARTERROR;
				}
			}
			/** ��}�O���[�v�z�u **/
			else if (SfigLocType == 3){
				/** ���ɔz�u�ς�(�����z�u�s��) **/
				if (LocFlg == 1){
					SXFErrorMsgC::RecordError(SXFSFIGLOCONE,
												IN_Type,
												3,
												m_InstanceID,
												((Sfigloc_Struct*)IN_Struct)->name,
												IN_Type);
					return SXFSFIGLOCONE;
				}
				/** ��}���i��ɂ̓O���[�v��z�u�ł��Ȃ� **/
				if (m_SfigFlag == 4){
					SXFErrorMsgC::RecordError(SXFPARTERROR,
												IN_Type,
												1,
												IN_Type);
					return SXFPARTERROR;
				}
			}
			error_code = m_Sfigloc_check.Feature_rule_check(
											(Sfigloc_Struct*)IN_Struct,
											m_TableManager,
											m_InstanceID);
			if (!error_code)
				/** �z�u�t���OON **/
				m_ReadAP202Manager->SetLocFlg(((Sfigloc_Struct*)IN_Struct)->name);
		}
	}
	/** �O����`�n�b�` **/
	else if (strcmp(IN_Type,DEF_EXTERNALLY_DEFINED_HATCH) == 0){
		/** �����Ȑ���ɔz�u�ł��Ȃ� **/
		if (IN_AssemType == 3){
			SXFErrorMsgC::RecordError(SXFNOTCURVE,IN_Type,1,IN_Type);
			return SXFNOTCURVE;
		}
		error_code = m_Exhatch_check.Feature_rule_check(
								(Externally_Defined_Hatch_Struct*)IN_Struct,
								m_TableManager,
								m_ReadAP202Manager,
								m_WriteManager,
								m_InstanceID,
								m_ComInfo);
	}
	/** �n�b�`���O(�h��) **/
	else if (strcmp(IN_Type,DEF_FILL_AREA_STYLE_COLOUR) == 0){
		/** �����Ȑ���ɔz�u�ł��Ȃ� **/
		if (IN_AssemType == 3){
			SXFErrorMsgC::RecordError(SXFNOTCURVE,IN_Type,1,IN_Type);
			return SXFNOTCURVE;
		}
		error_code = m_FillColour_check.Feature_rule_check(
										(Fill_area_style_colour_Struct*)IN_Struct,
										m_TableManager,
										m_ReadAP202Manager,
										m_WriteManager,
										m_InstanceID,
										m_ComInfo);
	}
	/** �n�b�`���O(���[�U��`) **/
	else if (strcmp(IN_Type,DEF_FILL_AREA_STYLE_HATCHING) == 0){
		/** �����Ȑ���ɔz�u�ł��Ȃ� **/
		if (IN_AssemType == 3){
			SXFErrorMsgC::RecordError(SXFNOTCURVE,IN_Type,1,IN_Type);
			return SXFNOTCURVE;
		}
		error_code = m_FillHatching_check.Feature_rule_check(
										(Fill_area_style_hatching_Struct*)IN_Struct,
										m_TableManager,
										m_ReadAP202Manager,
										m_WriteManager,
										m_InstanceID,
										m_ComInfo);
	}
	/** �n�b�`���O(�p�^�[��) **/
	else if (strcmp(IN_Type,DEF_FILL_AREA_STYLE_TILES) == 0){
		/** �����Ȑ���ɔz�u�ł��Ȃ� **/
		if (IN_AssemType == 3){
			SXFErrorMsgC::RecordError(SXFNOTCURVE,IN_Type,1,IN_Type);
			return SXFNOTCURVE;
		}
		error_code = m_FillTiles_check.Feature_rule_check(
										(Fill_area_style_tiles_Struct*)IN_Struct,
										m_TableManager,
										m_ReadAP202Manager,
										m_WriteManager,
										m_InstanceID,
										m_ComInfo);
	}
	else{
		SXFErrorMsgC::RecordError(SXFFEATURETYPEERR,"",1,IN_Type);
		return SXFFEATURETYPEERR;
	}
	return error_code;
}
