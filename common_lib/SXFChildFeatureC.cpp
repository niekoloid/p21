// SXFChildFeatureC.cpp: SXFChildFeatureC �N���X�̃C���v�������e�[�V����
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SXFChildFeatureC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//////////////////////////////////////////////////////////////////////
// �\�z/����
//////////////////////////////////////////////////////////////////////

SXFChildFeatureC::SXFChildFeatureC()
{
	//�t�B�[�`���\����
	ChildStruct = NULL;
	//�t�B�[�`����
//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
//	strcpy(FeatureType,"");
	strcpy_s(FeatureType,_countof(FeatureType),"");
	//�t�B�[�`���̃��x��
	Level = -1;
	//�C���X�^���XID
	InstanceID = -1;
	//�����Ȑ��̔�\���t���O
	CurveFlag = -1;
	//�����Ȑ��̐F�A����A����
	CurveColor = 0;
	CurveType = 0;
	CurveWidth = 0;
	//�n�b�`�̗v�f(�n�b�`�A�O�`�A������)�ł��邱�Ƃ̃t���O
	HatchElemFlg = -1; 
	HatchLayer = -1;
	HatchID = -1;//ID_222_000725_ins
}

SXFChildFeatureC::~SXFChildFeatureC()
{

}

SXFChildFeatureC& SXFChildFeatureC::operator=(const SXFChildFeatureC& IN_ChildFeature){
	//�t�B�[�`���\����
	ChildStruct = IN_ChildFeature.ChildStruct;
	//�t�B�[�`����
//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
//	strcpy(FeatureType,IN_ChildFeature.FeatureType);
	strcpy_s(FeatureType,_countof(FeatureType),IN_ChildFeature.FeatureType);
	//�t�B�[�`���̃��x��
	Level = IN_ChildFeature.Level;
	//�z�u���
	for (int i = 0; i < IN_ChildFeature.SfigLocateTable.GetSize(); i++)
		SfigLocateTable.Add(IN_ChildFeature.SfigLocateTable.GetAt(i));
	//�C���X�^���XID
	InstanceID = IN_ChildFeature.InstanceID;
	//�����Ȑ��̔�\���t���O
	CurveFlag = IN_ChildFeature.CurveFlag;
	//�����Ȑ��̐F�A����A����
	CurveColor = IN_ChildFeature.CurveColor;
	CurveType = IN_ChildFeature.CurveType;
	CurveWidth = IN_ChildFeature.CurveWidth;
	//�n�b�`�̗v�f(�n�b�`�A�O�`�A������)�ł��邱�Ƃ̃t���O
	HatchElemFlg = IN_ChildFeature.HatchElemFlg; 
	HatchLayer = IN_ChildFeature.HatchLayer; 
	HatchID = IN_ChildFeature.HatchID;//ID_222_000725_ins

	return *this;
}

SXFChildFeatureC::SXFChildFeatureC(const SXFChildFeatureC& IN_ChildFeature){
	//�t�B�[�`���\����
	ChildStruct = IN_ChildFeature.ChildStruct;
	//�t�B�[�`����
//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
//	strcpy(FeatureType,IN_ChildFeature.FeatureType);
	strcpy_s(FeatureType,_countof(FeatureType),IN_ChildFeature.FeatureType);
	//�t�B�[�`���̃��x��
	Level = IN_ChildFeature.Level;
	//�z�u���
	for (int i = 0; i < IN_ChildFeature.SfigLocateTable.GetSize(); i++)
		SfigLocateTable.Add(IN_ChildFeature.SfigLocateTable.GetAt(i));
	//�C���X�^���XID
	InstanceID = IN_ChildFeature.InstanceID;
	//�����Ȑ��̔�\���t���O
	CurveFlag = IN_ChildFeature.CurveFlag;
	//�����Ȑ��̐F�A����A����
	CurveColor = IN_ChildFeature.CurveColor;
	CurveType = IN_ChildFeature.CurveType;
	CurveWidth = IN_ChildFeature.CurveWidth;
	//�n�b�`�̗v�f(�n�b�`�A�O�`�A������)�ł��邱�Ƃ̃t���O
	HatchElemFlg = IN_ChildFeature.HatchElemFlg; 
	HatchLayer = IN_ChildFeature.HatchLayer; 
	HatchID = IN_ChildFeature.HatchID;//ID_222_000725_ins
}
