// SXFChildFeatureC.h: SXFChildFeatureC �N���X�̃C���^�[�t�F�C�X
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SXFCHILDFEATUREC_H__790053E1_2A42_11D4_A3A9_009027565E9B__INCLUDED_)
#define AFX_SXFCHILDFEATUREC_H__790053E1_2A42_11D4_A3A9_009027565E9B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include <afxtempl.h>
//#include "SXFDNFeatureChildC.h"

/*typedef struct SfigLocateInfo{
	double m_Locate_x;
	double m_Locate_y;
	double m_Angle;
	double m_Ratio_x;
	double m_Ratio_y;
}SXFSFIGLOCATEINFO;

typedef CArray<SXFSFIGLOCATEINFO,SXFSFIGLOCATEINFO&> SXFSFIGLOCATETABLE;*/
typedef struct SfigLocateInfo{
	double m_Locate_x;
	double m_Locate_y;
	double m_Angle;
	double m_Ratio_x;
	double m_Ratio_y;
}SXFSFIGLOCATEINFO;

typedef CArray<SXFSFIGLOCATEINFO,const SXFSFIGLOCATEINFO&> SXFSFIGLOCATETABLE;

class SXFChildFeatureC  
{
public:
	SXFChildFeatureC& operator=(const SXFChildFeatureC& IN_ChildFeature);
	SXFChildFeatureC(const SXFChildFeatureC& IN_ChildFeature);

	SXFChildFeatureC();
	virtual ~SXFChildFeatureC();

	//�t�B�[�`���\����
	LPVOID ChildStruct;
	//�t�B�[�`����
	char FeatureType[64];
	//�t�B�[�`���̃��x��
	int Level;
	//�z�u���
	SXFSFIGLOCATETABLE SfigLocateTable;
	//�C���X�^���XID
	int InstanceID;

	//�����Ȑ��̔�\���t���O
	//�v�f���n�b�`���O�̂Ƃ��̂ݎg�p
	int CurveFlag;
	//�����Ȑ��̐F�A����A����
	//�v�f���n�b�`���O�̊O�`�A�������̂Ƃ��̂ݎg�p
	int CurveColor;
	int CurveType;
	int CurveWidth;
	//�n�b�`�̗v�f(�n�b�`�A�O�`�A������)�ł��邱�Ƃ̃t���O
	int HatchElemFlg;

	int HatchLayer;

	//�O�`�A��������ID
	int HatchID;//ID_222_000725_ins
};

#endif // !defined(AFX_SXFCHILDFEATUREC_H__790053E1_2A42_11D4_A3A9_009027565E9B__INCLUDED_)
