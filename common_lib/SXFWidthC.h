//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWidthC.h                           �쐬���F2000.04.16
//
//	�P�D�N���X�T�v
//		�����̍\���́A�R�[�h�A�C���X�^���X�h�c�Ȃǂ�ێ�����N���X
//
//	�Q�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2000.04.16     ��
//
//------------------------------------------------------------
#ifndef _SXFWIDTHC_H_
#define _SXFWIDTHC_H_

class SXFTableMapManagerC;

class SXFWidthC  
{
public:
	SXFWidthC(	);
	virtual ~SXFWidthC();
	int InquireCode(double IN_Width, double IN_Eps);

public:
	int m_Code;
	int m_ID;

	double m_Width;

	SXFTableMapManagerC* m_MappingManager;

};

#endif
