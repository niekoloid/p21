//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFDataStructC.h					  �쐬���F2001.05.25
//
//	�P�D�N���X�T�v
//		Instance Data��Head Section Data�̍\���̂̒�`
//		
//	�Q�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.05.25	   ���X��		�Ȃ�
//
//------------------------------------------------------------
#ifndef _SXFDATASTRUCTC_H_
#define _SXFDATASTRUCTC_H_

#include <afx.h>

struct HEADSECTION{
	CString FileName;
	int		Level;
	int		Mode;//0:ambilateral(mix)
				 //1:Feature
				 //2:AP202
	CString Author;  
	CString Organization;
	CString Version;
	CString OriginatingSystem;
	int		scadec_flg;				/* SCADEÇ���׸� */
										//-1:SCADEC�ȊO��̧��
										//1:SCADEÇ��
};

#define SXF_IM_NULL			0

#define SXF_IM_COMMENT		1
#define SXF_IM_SECTIONMARK	2
#define SXF_IM_HEADSECTION	3

#define SXF_IM_AP_ENTITY	11
#define SXF_IM_AP_TABLE		12
#define SXF_IM_AP_ASSEMBLY	13
//	ADD(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
#define SXF_IM_AP_INVISIBILITY		14
#define SXF_IM_AP_PRESENTATION_SIZE	15
#define SXF_IM_AP_DRAUGHTING_TITLE	16
//	ADD(E)	�`���[�j���O�Ή�	K.Naono	03.07.03
//	ADD(S)	Ver3.0�Ή�	K.Naono	04.01.30
#define SXF_IM_AP_ATTRIBUTE	17
//	ADD(E)	Ver3.0�Ή�	K.Naono	04.01.30

#define SXF_IM_FT_ENTITY	21
#define SXF_IM_FT_TABLE		22
#define SXF_IM_FT_ASSEMBLY	23


struct INSTANCEDATA{
	int		InstanceMode;//0  NULL,
						 //1  Comment
						 //2  SectionMark
						 //3  HeadSection
						 //11 AP202_Entity
						 //12 AP202_Table
						 //13 AP202_Assembly
						 //21 Feature_Entity
						 //22 Feature_Table
						 //23 Feature_Assembly
	int		InstanceID;
	CString EntityName;
	CString EntityData;
};

#endif

