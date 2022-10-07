/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillTiles_checkC.cpp								�쐬���F2000.4.3

	�P�D�N���X�T�v
	�n�b�`���O�i�p�^�[���j�t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/

#if !defined(AFX_SXFFILLTILES_CHECKC_H__1E81D282_0A46_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFFILLTILES_CHECKC_H__1E81D282_0A46_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"
#include "SXFTableCheckC.h"
#include "SXFComFunctionC.h"

class SXFTableManagerC;
class SXFWriteManagerC;
class SXFReadAP202ManagerC;
class SXFComInfoC;

class SXFFillTiles_checkC  :public SXFTableCheckC, SXFComFunctionC
{
public:
	int ReadAP202_Check(Fill_area_style_tiles_Struct *IN_filltiles_str);
	int str_rule_check(Fill_area_style_tiles_Struct* IN_filltiles_str);
	int attr_rule_check(Fill_area_style_tiles_Struct* IN_filltiles_str);
	int Feature_rule_check(Fill_area_style_tiles_Struct* IN_filltiles_str,
							SXFTableManagerC* IN_TableManager,
							SXFReadAP202ManagerC* IN_ReadAP202Manager,
							SXFWriteManagerC* IN_WriteManager,
							CString IN_InstanceID,
							SXFComInfoC* IN_Info);
	SXFFillTiles_checkC();
	virtual ~SXFFillTiles_checkC();
	
	SXFReadAP202ManagerC* m_ReadAP202Manager;
	SXFWriteManagerC* m_WriteManager;
};

#endif // !defined(AFX_SXFFILLTILES_CHECKC_H__1E81D282_0A46_11D4_A76E_00000EB03267__INCLUDED_)
