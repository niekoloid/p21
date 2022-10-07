/**
	All Rights Reserved,(c) JACIC 2001
	�t�@�C����				�쐬���F2000.04.21
	SXFExtraSchema.cpp

	�P�D�N���X�T�v
	�����t�@�C������e�G���e�B�e�B�̃f�[�^�\���𐶐�����

	�Q�D����
	����ԍ�		���t��		�S����		�T�v
	�쐬		2000.04.21	�@�@�]�{	�@�@�Ȃ��B

**/
#include "stdafx.h"
#include "SXFCKSchemaC.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#define	ENTITY(entname)	\
	class entname : public SXFCKEntityC	{	\
	public:	\
		entname(SXFCKSchemaC *IN_schema) : SXFCKEntityC(IN_schema) {
#define	END_ENTITY	}};
#define	NAME(name)	m_name = name;
#define	ATTRIBUTE(name,type)	m_attrs.AddTail(new SXFCKAttrLink(name, type, 0));
#define	OPTIONAL_ATTRIBUTE(name,type)	m_attrs.AddTail(new SXFCKAttrLink(name, type, SXFCKAttrLink::FLAG_OPTIONAL));
#define	UNIQUE_ATTRIBUTE(name,type)	m_attrs.AddTail(new SXFCKAttrLink(name, type, SXFCKAttrLink::FLAG_UNIQUE));
#define	DERIVED_ATTRIBUTE(name,type)	m_attrs.AddTail(new SXFCKAttrLink(name, type, SXFCKAttrLink::FLAG_DERIVE));
#define	SUBTYPE_OF(super)		m_supers.AddTail(new SXFCKAttrLink("", super, 0));

#define	TYPEDEF(clas,name,alias)	\
	class clas : public SXFCKTypeDefSingleC {	\
	public:	clas(SXFCKSchemaC *IN_schema) : SXFCKTypeDefSingleC(IN_schema) {	\
			m_name = name;	\
			m_definedtype.m_typename = alias;	\
	}};

#define	SELECT(selname)	\
	class selname : public SXFCKSelectC	{	\
	public:	\
		selname(SXFCKSchemaC *IN_schema) : SXFCKSelectC(IN_schema) {
#define	SELECTITEM(type)	m_select.AddTail(new SXFCKAttrLink(type, type, 0));
#define	END_SELECT	}};

#define	ENUMERATION(enumname)	\
	class enumname : public SXFCKEnumerationC	{	\
	public:	\
		enumname(SXFCKSchemaC *IN_schema) : SXFCKEnumerationC(IN_schema) {
#define	ENUMITEM(type)	m_enum.AddTail(new SXFCKAttrLink(type, type, 0));
#define	END_ENUMERATION	}};


#define	ADDATTRTYPE(cls)	AddAttr(new cls(this));

#define	REGISTER_TYPE	void SXFCKSchemaC::SetupExtraType(){

#define	END_REGISTER_TYPE	}


/////////////////////////////////////////////////////
// ������hldai���f���o������`��ǂ�
#include "SXFExtraSchema.h"
/////////////////////////////////////////////////////
