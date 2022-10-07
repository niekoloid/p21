/**
	All Rights Reserved,(c)JACIC 2001
	SXFComInfoC.cpp						�쐬���F2001.05.17

	�P�D�N���X�T�v
		���ʏ��i���x���E���[�h�j��ێ�����N���X

	�Q�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.05.17	�ЎR(FQS)	�Ȃ��B
**/

#include "stdafx.h"
#include <string.h>
#include "SXFComInfoC.h"
#include "SXFErrorMsgC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFComInfoC.cpp						�쐬���F2001.05.17

	�P�D�@�\�T�v
		�R���X�g���N�^
		
	�Q�D�C���^�[�t�F�C�X
		void	SXFComInfoC::SXFComInfoC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.05.17	�ЎR(FQS)	�Ȃ��B
**/
SXFComInfoC::SXFComInfoC()
{
//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
//	strcpy(m_file_name, "");
	strcpy_s(m_file_name,_countof(m_file_name), "");
	m_rw_flg = 0;
	m_tolerance = 0.0;
	m_tolerance2 = 0.0;	
	m_devide = 0.0;	
	m_level = 0;
	m_mode = 0;	
//	MOD(S)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
//	strcpy(m_author, "");	
//	strcpy(m_organization,"");
//	strcpy(m_trans_name,"");
//	strcpy(m_version, "");
	strcpy_s(m_author,_countof(m_author), "");	
	strcpy_s(m_organization,_countof(m_organization),"");
	strcpy_s(m_trans_name,_countof(m_trans_name),"");
	strcpy_s(m_version,_countof(m_version), "");
//	MOD(E)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
	m_IN_level = 0;
	m_exfile = 0;

}
/**
	All Rights Reserved,(c)JACIC 2001
	SXFComInfoC.cpp						�쐬���F2001.05.17

	�P�D�@�\�T�v
		�f�X�g���N�^
		
	�Q�D�C���^�[�t�F�C�X
		void	SXFComInfoC::~SXFComInfoC ()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.05.17	�ЎR(FQS)	�Ȃ��B
**/
SXFComInfoC::~SXFComInfoC ()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFComInfoC.cpp						�쐬���F2001.05.17

	�P�D�@�\�T�v
		���ʏ���ێ�
		
	�Q�D�C���^�[�t�F�C�X
		void	Set_Write_Come(char IN_fname[257], 
							   int IN_flg,
							   double IN_tolerance, 
							   double IN_tolerance2, 
							   double IN_devide, 
							   int IN_level, 
							   int IN_mode, 
							   char IN_author[257],
							   char IN_organization[257], 
							   char IN_trans_name[257])
		
	�����F	�^		������				���e
			int		IN_flg					�Ǐ����t���O
			double	IN_tolerance			���e�덷
			double	IN_tolerance2			�p�x���e�덷
			double	IN_devide				���e�덷(�X�v���C�������p)
			int		IN_level				���x��
			int		IN_mode					���[�h
			char	IN_author[257]			�t�@�C���쐬��
			char	IN_organization[257]	�쐬�ҏ���
			char	IN_trans_name[257]		�g�����X���[�^��
	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.05.17	�ЎR(FQS)	�Ȃ��B
**/
void SXFComInfoC::Set_Write_Come(char IN_fname[257], int IN_flg, double IN_tolerance, double IN_tolerance2, double IN_devide, int IN_level, int IN_mode, char IN_author[257], char IN_organization[257], char IN_trans_name[257])
{
//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
//	strcpy(m_file_name, IN_fname);
	strcpy_s(m_file_name,_countof(m_file_name), IN_fname);
	m_rw_flg = IN_flg ;
	m_tolerance = IN_tolerance ;
	m_tolerance2 = IN_tolerance2 ;
	m_devide = IN_devide ;
	m_level = IN_level ;
	m_mode = IN_mode ;
//	MOD(S)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
//	strcpy(m_author, IN_author);
//	strcpy(m_organization, IN_organization);
//	strcpy(m_trans_name, IN_trans_name);
	strcpy_s(m_author,_countof(m_author), IN_author);
	strcpy_s(m_organization,_countof(m_organization), IN_organization);
	strcpy_s(m_trans_name,_countof(m_trans_name), IN_trans_name);
//	MOD(E)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFComInfoC.cpp						�쐬���F2001.05.17

	�P�D�@�\�T�v
		���ʏ���ێ�
		
	�Q�D�C���^�[�t�F�C�X
		void	Set_Read_Come(char IN_fname[257], 
							  int IN_flg, 
							  double IN_tolerance, 
							  double IN_tolerance2, 
							  double IN_devide, 
							  int IN_level, 
							  int IN_mode)
		
	�����F	�^		������				���e

				char	IN_fname[257]		�t�@�C����
				int		IN_flg				�Ǐ����t���O
				double	IN_tolerance		���e�덷
				double	IN_tolerance2		�p�x�p���e�덷
				double	IN_devide			���e�덷(�X�v���C�������p)
				int		IN_level			���x��
				int		IN_mode				���[�h

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.05.17	�ЎR(FQS)	�Ȃ��B
**/
void SXFComInfoC::Set_Read_Come(char IN_fname[257], int IN_flg, double IN_tolerance, double IN_tolerance2, double IN_devide, int IN_level, int IN_mode)
{
//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
//	strcpy(m_file_name, IN_fname);
	strcpy_s(m_file_name,_countof(m_file_name), IN_fname);
	m_rw_flg = IN_flg ;
	m_tolerance = IN_tolerance ;
	m_tolerance2 = IN_tolerance2 ;
	m_devide = IN_devide ;
	m_level = IN_level ;
	m_mode = IN_mode ;
	m_IN_level = IN_level;
	m_exfile = 0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFComInfoC.cpp						�쐬���F2001.05.17

	�P�D�@�\�T�v
		�t���O�̕ԋp
		
	�Q�D�C���^�[�t�F�C�X
		void	SXFComInfoC::Get_Flg(int &OUT_flg)
		
	�����F	�^		������				���e
			int		&OUT_flg	�ǂݏ����t���O

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.05.17	�ЎR(FQS)	�Ȃ��B
**/
void SXFComInfoC::Get_Flg(int &OUT_flg)
{
	OUT_flg = m_rw_flg ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFComInfoC.cpp						�쐬���F2001.05.17

	�P�D�@�\�T�v
		�g�������X���̎擾
		
	�Q�D�C���^�[�t�F�C�X
		void	 SXFComInfoC::Get_Tolerance(double &OUT_tolerance, 
											double &OUT_tolerance2)
		
	����	�F	�^			������				���e
				double&		OUT_tolerance		���e�덷
				double&		OUT_tolerance2		�p�x�p���e�덷
		

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.05.17	�ЎR(FQS)	�Ȃ��B
**/
void SXFComInfoC::Get_Tolerance(double &OUT_tolerance, double &OUT_tolerance2)
{
	OUT_tolerance = m_tolerance ;
	OUT_tolerance2 = m_tolerance2 ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFComInfoC.cpp						�쐬���F2001.06.24

	�P�D�@�\�T�v
		�Ǐ����t���O�̎擾
		
	�Q�D�C���^�[�t�F�C�X
		void	 SXFComInfoC::Get_RWFlag(int &OUT_RWFlag)
		
	����	�F	�^			������				���e
				int&		OUT_RWFlag			�Ǐ����t���O		

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.24	���X��(FQS)	�Ȃ��B
**/
void SXFComInfoC::Get_RWFlag(int &OUT_RWFlag)
{
	OUT_RWFlag = m_rw_flg;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFComInfoC.cpp						�쐬���F2001.06.24

	�P�D�@�\�T�v
		Part21�t�@�C���̏��ƌĂяo�������r�`�F�b�N���A�s������ʒm����
		(���[�j���O����)
		
	�Q�D�C���^�[�t�F�C�X
		int	 SXFComInfoC::SetFileInfo(HEADSECTION IN_Head) 
		
	����	�F	�^				������		���e
				HEADSECTION		IN_Head		̧�ق�ͯ�ޏ��

	���A�l�F
		����I��	�F0
		�ُ�I��	�F�G���[�R�[�h

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.24	���X��(FQS)	�Ȃ��B
**/
int SXFComInfoC::SetFileInfo(HEADSECTION IN_Head)
{
	/** Level **/
	m_FileLevel = IN_Head.Level;
	/** Mode **/
	m_FileMode = IN_Head.Mode;
	/* SCADEC�ȊO��̧�� */
	if (IN_Head.scadec_flg == -1){
//	MOD(S)	���b�Z�[�W�C��	K.Naono	04.03.05
//		SXFErrorMsgC::RecordError(SXFSCADECFILEERR,"",0);
		SXFErrorMsgC::RecordError2(SXFSCADECFILEERR,"",0);
//	MOD(E)	���b�Z�[�W�C��	K.Naono	04.03.05
		/* �t�B�[�`���R�����g�A���x���Q�Ƃ��ď������� */
		m_mode = 2;
		m_level = 2;
	}
	else{
		/* FileLevel�P�̂Ƃ� */
		if (m_FileLevel == 1)
			m_level = 2;
		/* FileLevel2�̂Ƃ� */
		else if (m_FileLevel == 2){
			if (m_level == 1){
				//�_�E���R���o�[�g�͍s���܂���B
//	MOD(S)	���b�Z�[�W�C��	K.Naono	04.03.05
//				SXFErrorMsgC::RecordError(SXFWARNINGDC,"",0);
				SXFErrorMsgC::RecordError2(SXFWARNINGDC,"",0);
//	MOD(E)	���b�Z�[�W�C��	K.Naono	04.03.05
				m_level = 2;
			}
			else
				m_level = 2;
		}
		//error
		else{
			SXFErrorMsgC::RecordError(SXFNOLEVEL,"",1,m_FileLevel);
			return SXFNOLEVEL;
		}
		/* ���[�h */
		switch(m_FileMode){
			case 0:
			case 2:
				break;
			case 1:
				/* �t�B�[�`���R�����g��̧�� */
//	MOD(S)	���b�Z�[�W�C��	K.Naono	04.03.05
//				SXFErrorMsgC::RecordError(SXFAP202FILE,"",0);
				SXFErrorMsgC::RecordError2(SXFAP202FILE,"",0);
//	MOD(E)	���b�Z�[�W�C��	K.Naono	04.03.05
				/* AP202���[�h�Ƃ��ď������� */
				m_mode = 2;
				break;
			default:
				/* ���[�h���O�C�P�C�Q�ȊO */
				SXFErrorMsgC::RecordError(SXFNOMODE,"",1,m_FileMode);
				return SXFNOMODE;
		}
	}
	return 0;
}
