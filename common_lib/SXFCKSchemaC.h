/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			�쐬���F2000.04.23

	�P�D�@�\�T�v
		Part21�C���X�^���X�̃`�F�b�N���s��

	�Q�D����
	����ԍ�	���t��		�S����		�T�v
	�쐬		2000.04.23	�@�@���{(FQS)	�Ȃ��B

**/
#if !defined(SXFCKSchemaC_INCLUDED_)
#define SXFCKSchemaC_INCLUDED_

#include "SXFDataStructC.h"
#include "SXFEntityDataC.h"
#include "SXFInstanceIDC.h"
#include "SXFPart21FileC.h"
#include "SXFPart21FileReadC.h"

#include "SXFTokenC.h"

#include "SXFErrorCode.h"
#include "SXFErrorMsgC.h"

class SXFCKAttrTypeC ;
class SXFCKEntityC;
struct SXFCKAttrLink ;
class SXFCheckContext;


struct SXFCKValue {
	enum VTYPE {
		VT_UNDEFINED = 0,
		VT_INTEGER,
		VT_REAL,
		VT_STRING,
		VT_BOOLEAN,
		VT_LOGICAL,
		VT_AGGR,
		VT_INSTANCE,
	} m_type;
	union {
		int	ival;
		double	rval;
		CString	*sval;
		char	bval;
		char	lval;
	} u;
	SXFCKValue() {
		m_type = VT_UNDEFINED;
	}
	~SXFCKValue() {
		Clear();
	}
	void Clear() {
		if (m_type == VT_STRING) {
			delete u.sval;
		}
		m_type = VT_UNDEFINED;
	}
	void SetString(LPCTSTR sval) {
		Clear();
		m_type = VT_STRING;
		u.sval = new CString(sval);
	}
	void SetInteger(int ival) {
		Clear();
		m_type = VT_INTEGER;
		u.ival = ival;
	}
	void SetReal(double rval) {
		Clear();
		m_type = VT_REAL;
		u.rval = rval;
	}
	void SetBoolean(int bval) {
		Clear();
		m_type = VT_BOOLEAN;
		u.bval = bval;
	}
	void SetLogical(int lval) {
		Clear();
		m_type = VT_LOGICAL;
		u.lval = lval;
	}
	void SetAggr() {
		Clear();
		m_type = VT_AGGR;
		u.ival = 0;
	}
	void SetInstance(int ival) {
		Clear();
		m_type = VT_INSTANCE;
		u.ival = ival;
	}
};
//////////////////////////////////////////////////////////////////////
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			�쐬���F2000.04.23

	�P�D�@�\�T�v
		�G���[�o�́A�C���X�^���XID����

	�Q�D����
	����ԍ�	���t��		�S����		�T�v
	�쐬		2000.04.23	�@�@���{(FQS)	�Ȃ��B

**/
class SXFMainContextC
{
public:
//------------------------------------------------------------------------------
//	�Q�Ɗ֌W�e�[�u��
//------------------------------------------------------------------------------
	CMap<int,int&,int,int&>	m_refmap;

//------------------------------------------------------------------------------
//	�C���X�^���XID����
//------------------------------------------------------------------------------
	void RefInstance(int IN_instanceID) {
		int	count;
		if (m_refmap.Lookup(IN_instanceID, count)) {
			count++;
		}
		else {
			count = 1;
			m_refmap.SetAt(IN_instanceID, count);
		}
	}
	int RefCount(int IN_instanceID) {
		int	count = 0;
		if (m_refmap.Lookup(IN_instanceID, count)) {
		}
		return count;
	}
//------------------------------------------------------------------------------
//	�G���[�o��
//------------------------------------------------------------------------------
	virtual void OnError(int IN_instanceID, 
						 LPCTSTR IN_entityname, 
						 SXFErrorCode IN_error_code, 
						 LPCTSTR IN_param_string) 
	{
		if (IN_error_code == 2)
		{
			SXFErrorMsgC::RecordError(IN_error_code, 
								  IN_entityname, 
								  2, 
								  IN_instanceID, 
								  IN_entityname
								  );
		}
		else{
			SXFErrorMsgC::RecordError(IN_error_code, 
								  IN_entityname, 
								  3, 
								  IN_instanceID, 
								  IN_entityname,
								  IN_param_string
								  );
		}
	}
};

//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			�쐬���F2000.04.23

	�P�D�@�\�T�v
		Part21�C���X�^���X���`�F�b�N����

	�Q�D����
	����ԍ�	���t��		�S����		�T�v
	�쐬		2000.04.23	�@�@���{(FQS)	�Ȃ��B

**/
class SXFCKSchemaC {
public:
//-----------------------------------------------------------------------------
//	�f�t�H���g�R���X�g���N�^
//-----------------------------------------------------------------------------
	SXFCKSchemaC();

//-----------------------------------------------------------------------------
//	�f�t�H���g�f�X�g���N�^
//-----------------------------------------------------------------------------
	~SXFCKSchemaC();

//-----------------------------------------------------------------------------
//	��{�f�[�^�^�̑�������
//-----------------------------------------------------------------------------
	void SetupBasicType();

//-----------------------------------------------------------------------------
//	��{�f�[�^�^�ȊO�̑�������
//-----------------------------------------------------------------------------
	void SetupExtraType();

//-----------------------------------------------------------------------------
//	�����ǉ�
//-----------------------------------------------------------------------------
	void AddAttr(SXFCKAttrTypeC *IN_Attr);

//-----------------------------------------------------------------------------
//	���������N
//-----------------------------------------------------------------------------
	BOOL LinkAttr(SXFCKAttrLink *IN_AttrLink);
	CMapStringToPtr	m_attrmap;

//-----------------------------------------------------------------------------
//	�����^�擾
//-----------------------------------------------------------------------------
	SXFCKAttrTypeC *GetAttr(LPCTSTR IN_name);

//-----------------------------------------------------------------------------
//	�C���X�^���XID��ێ�
//-----------------------------------------------------------------------------
	void SetIDManager(SXFInstanceIDC *IN_manager) {
		m_manager = IN_manager;
	}

//-----------------------------------------------------------------------------
//	�`�F�b�N
//-----------------------------------------------------------------------------
	BOOL Check(SXFMainContextC *IN_mc, SXFEntityDataC *IN_entity);

//-----------------------------------------------------------------------------
//	�����C���X�^���X�ȊO�̃`�F�b�N
//-----------------------------------------------------------------------------
	BOOL CheckSingleInstance(SXFEntityDataC *IN_entity, 
							 SXFCheckContext *IN_context);

//-----------------------------------------------------------------------------
//	�����C���X�^���X�̃`�F�b�N
//-----------------------------------------------------------------------------
	BOOL CheckComplexInstance(SXFEntityDataC *IN_entity, 
							  SXFCheckContext *IN_context, 
							  CArray<SXFCKEntityC*,SXFCKEntityC*> *IN_ents);

//-----------------------------------------------------------------------------
//	�C���X�^���XID
//-----------------------------------------------------------------------------
	SXFInstanceIDC	*m_manager;
};
//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			�쐬���F2000.04.23

	�P�D�@�\�T�v
		�`�F�b�N���ׂ��l��ێ�����B

	�Q�D����
	����ԍ�	���t��		�S����		�T�v
	�쐬		2000.04.23	�@�@���{(FQS)	�Ȃ��B

**/
class SXFCheckContext : public SXFTokenC {
public:
	SXFCheckContext(SXFMainContextC *IN_mc) : SXFTokenC()
	{
		m_MainContext = IN_mc;
	}
	SXFMainContextC	*m_MainContext;

//-----------------------------------------------------------------------------
//	������^�̔���
//-----------------------------------------------------------------------------
	BOOL IsString() {
		return m_Type == T_STRING;
	}

//-----------------------------------------------------------------------------
//	�����^�̔���
//-----------------------------------------------------------------------------
	BOOL IsReal() {
		return m_Type == T_REAL;
	}

//-----------------------------------------------------------------------------
//	�����^�̔���
//-----------------------------------------------------------------------------
	BOOL IsInteger() {
		return m_Type == T_INTEGER;
	}

//-----------------------------------------------------------------------------
//	�C���X�^���XID���̔���
//-----------------------------------------------------------------------------
	BOOL IsID() {
		return m_Type == T_ID;
	}

//-----------------------------------------------------------------------------
//	�G���[�o��
//-----------------------------------------------------------------------------
	void SXFCheckContext::Output(SXFErrorCode error_code, 
								 int param_num, 
								 LPCTSTR param_string);

//-----------------------------------------------------------------------------
//	�C���X�^���X�̏���ێ�
//-----------------------------------------------------------------------------
	void SetInstanceInfo(int instanceID, LPCTSTR entityname) {
		m_instanceID = instanceID;
		m_entityname = entityname;
	}

//-----------------------------------------------------------------------------
//	�C���X�^���XID
//-----------------------------------------------------------------------------
	int			m_instanceID;

//-----------------------------------------------------------------------------
//	�G���[�R�[�h
//-----------------------------------------------------------------------------
	SXFErrorCode m_error_code;

//-----------------------------------------------------------------------------
//	�G���[�o�͂ɕK�v�ȃp�����[�^��
//-----------------------------------------------------------------------------
	int m_param_num;

//-----------------------------------------------------------------------------
//	�G���e�B�e�B���A�C���X�^���XID�ȊO�̃p�����[�^
//-----------------------------------------------------------------------------
	CString m_param_string;

//-----------------------------------------------------------------------------
//	�G���e�B�e�B��
//-----------------------------------------------------------------------------
	CString		m_entityname;

//-----------------------------------------------------------------------------
//	�G���[�p������
//-----------------------------------------------------------------------------
	CString		m_errortext;
};

//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			�쐬���F2000.04.23

	�P�D�@�\�T�v
		�����̌^��ێ��B

	�Q�D����
	����ԍ�	���t��		�S����		�T�v
	�쐬		2000.04.23	�@�@���{(FQS)	�Ȃ��B

**/
class SXFCKAttrTypeC {
public:
//-----------------------------------------------------------------------------
//	�R���X�g���N�^
//-----------------------------------------------------------------------------
	SXFCKAttrTypeC(SXFCKSchemaC *IN_schema) {
		m_schema = IN_schema;
	}

//-----------------------------------------------------------------------------
//	�f�X�g���N�^
//-----------------------------------------------------------------------------
	virtual ~SXFCKAttrTypeC() {
	}

//-----------------------------------------------------------------------------
//	���O�擾
//-----------------------------------------------------------------------------
	CString GetName() {
		return m_name;
	}

//-----------------------------------------------------------------------------
//	������
//-----------------------------------------------------------------------------
	virtual BOOL Initialize() {
		return TRUE;
	}

//-----------------------------------------------------------------------------
//	�`�F�b�N
//-----------------------------------------------------------------------------
	virtual BOOL Check(SXFEntityDataC *IN_entity, 
					   SXFCheckContext *IN_context, 
					   SXFCKValue *val) 
	{
		IN_context->Output(SXFNODICT, 2, "");
		return FALSE;
	};
protected:

//-----------------------------------------------------------------------------
//	���O
//-----------------------------------------------------------------------------
	CString	m_name;
	SXFCKSchemaC	*m_schema;
};

struct SXFCKAttrLink {
	CString			m_attrname;
	CString			m_typename;
	SXFCKAttrTypeC	*m_attr;
	BOOL			m_deletable;
	enum FLAGS {
		FLAG_OPTIONAL = 0x0001,
		FLAG_UNIQUE = 0x0002,
		FLAG_DERIVE = 0x0004,
	};
	DWORD			m_flags;
	SXFCKAttrLink() {
		m_attr = NULL;
		m_deletable = FALSE;
		m_flags = 0;
	}
	SXFCKAttrLink(LPCTSTR attrname, LPCTSTR typenam, DWORD flags) {
		m_attrname = attrname;
		m_typename = typenam;
		m_attr = NULL;
		m_deletable = FALSE;
		m_flags = flags;
	}
	~SXFCKAttrLink() {
		if (m_deletable) {
			delete m_attr;
		}
	}
};

struct SXFCKDeriveAttrLink: public SXFCKAttrLink {
	SXFCKDeriveAttrLink(LPCTSTR supertype, LPCTSTR attrname) :
		SXFCKAttrLink(attrname, "", 0) {
		m_supertype = supertype;
	}
	CString		m_supertype;// DERIVE���鑮�������N���X�B�J�����g�Ȃ�Empty()
};

//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			�쐬���F2000.04.23

	�P�D�@�\�T�v
		��{�f�[�^�^���`�F�b�N�B

	�Q�D����
	����ԍ�	���t��		�S����		�T�v
	�쐬		2000.04.23	�@�@���{(FQS)	�Ȃ��B

**/
class SXFCKBasicTypeC : public SXFCKAttrTypeC {
public:
//-----------------------------------------------------------------------------
//	�R���X�g���N�^
//-----------------------------------------------------------------------------
	SXFCKBasicTypeC(SXFCKSchemaC *IN_schema) : SXFCKAttrTypeC(IN_schema) {
	}
protected:
};

//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			�쐬���F2000.04.23

	�P�D�@�\�T�v
		�����^���`�F�b�N�B

	�Q�D����
	����ԍ�	���t��		�S����		�T�v
	�쐬		2000.04.23	�@�@���{(FQS)	�Ȃ��B

**/
class SXFCKIntegerC : public SXFCKBasicTypeC {
public:
//-----------------------------------------------------------------------------
//	�R���X�g���N�^
//-----------------------------------------------------------------------------
	SXFCKIntegerC(SXFCKSchemaC *IN_schema) : SXFCKBasicTypeC(IN_schema) {
		m_name = "INTEGER";
	}

//-----------------------------------------------------------------------------
//	�`�F�b�N
//-----------------------------------------------------------------------------
	virtual BOOL Check(SXFEntityDataC *IN_entity, 
					   SXFCheckContext *IN_context, 
					   SXFCKValue *val);
protected:
};

//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			�쐬���F2000.04.23

	�P�D�@�\�T�v
		�����^���`�F�b�N�B

	�Q�D����
	����ԍ�	���t��		�S����		�T�v
	�쐬		2000.04.23	�@�@���{(FQS)	�Ȃ��B

**/
class SXFCKRealC : public SXFCKBasicTypeC {
public:
//-----------------------------------------------------------------------------
//	�R���X�g���N�^
//-----------------------------------------------------------------------------
	SXFCKRealC(SXFCKSchemaC *IN_schema) : SXFCKBasicTypeC(IN_schema) {
		m_name = "REAL";
	}

//-----------------------------------------------------------------------------
//	�`�F�b�N
//-----------------------------------------------------------------------------
	virtual BOOL Check(SXFEntityDataC *IN_entity, 
					   SXFCheckContext *IN_context, 
					   SXFCKValue *val);
protected:
};

//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			�쐬���F2000.04.23

	�P�D�@�\�T�v
		BOOL�^���`�F�b�N�B

	�Q�D����
	����ԍ�	���t��		�S����		�T�v
	�쐬		2000.04.23	�@�@���{(FQS)	�Ȃ��B

**/
class SXFCBooleanC : public SXFCKBasicTypeC {
public:
//-----------------------------------------------------------------------------
//	�R���X�g���N�^
//-----------------------------------------------------------------------------
	SXFCBooleanC(SXFCKSchemaC *IN_schema) : SXFCKBasicTypeC(IN_schema) {
		m_name = "BOOLEAN";
	}

//-----------------------------------------------------------------------------
//	�`�F�b�N
//-----------------------------------------------------------------------------
	virtual BOOL Check(SXFEntityDataC *IN_entity, 
					   SXFCheckContext *IN_context, 
					   SXFCKValue *val);
protected:
};

//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			�쐬���F2000.04.23

	�P�D�@�\�T�v
		LOGICAL�^���`�F�b�N�B

	�Q�D����
	����ԍ�	���t��		�S����		�T�v
	�쐬		2000.04.23	�@�@���{(FQS)	�Ȃ��B

**/
class SXFCLogicalC : public SXFCKBasicTypeC {
public:
//-----------------------------------------------------------------------------
//	�R���X�g���N�^
//-----------------------------------------------------------------------------
	SXFCLogicalC(SXFCKSchemaC *IN_schema) : SXFCKBasicTypeC(IN_schema) {
		m_name = "LOGICAL";
	}

//-----------------------------------------------------------------------------
//	�`�F�b�N
//-----------------------------------------------------------------------------
	virtual BOOL Check(SXFEntityDataC *IN_entity, 
					   SXFCheckContext *IN_context, 
					   SXFCKValue *val);
protected:
};

//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			�쐬���F2000.04.23

	�P�D�@�\�T�v
		������^���`�F�b�N�B

	�Q�D����
	����ԍ�	���t��		�S����		�T�v
	�쐬		2000.04.23	�@�@���{(FQS)	�Ȃ��B

**/
class SXFCStringC : public SXFCKBasicTypeC {
public:
//-----------------------------------------------------------------------------
//	�R���X�g���N�^
//-----------------------------------------------------------------------------
	SXFCStringC(SXFCKSchemaC *IN_schema) : SXFCKBasicTypeC(IN_schema) {
		m_name = "STRING";
	}

//-----------------------------------------------------------------------------
//	�`�F�b�N
//-----------------------------------------------------------------------------
	virtual BOOL Check(SXFEntityDataC *IN_entity, 
					   SXFCheckContext *IN_context, 
					   SXFCKValue *val);
protected:
};

//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			�쐬���F2000.04.23

	�P�D�@�\�T�v
		�W���̌^���`�F�b�N�B

	�Q�D����
	����ԍ�	���t��		�S����		�T�v
	�쐬		2000.04.23	�@�@���{(FQS)	�Ȃ��B

**/
class SXFCAggrC : public SXFCKBasicTypeC {
public:
//-----------------------------------------------------------------------------
//	�R���X�g���N�^
//-----------------------------------------------------------------------------
	SXFCAggrC(SXFCKSchemaC *IN_schema) : SXFCKBasicTypeC(IN_schema) {
	}
	int		m_lower;// ����
	int		m_upper;// ���

//-----------------------------------------------------------------------------
//	�v�f
//-----------------------------------------------------------------------------
	SXFCKAttrLink	m_element;

//-----------------------------------------------------------------------------
//	�`�F�b�N
//-----------------------------------------------------------------------------
	virtual BOOL Check(SXFEntityDataC *IN_entity, 
					   SXFCheckContext *IN_context, 
					   SXFCKValue *val);
};

//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			�쐬���F2000.04.23

	�P�D�@�\�T�v
		SET�^���`�F�b�N�B

	�Q�D����
	����ԍ�	���t��		�S����		�T�v
	�쐬		2000.04.23	�@�@���{(FQS)	�Ȃ��B

**/
class SXFCSetC : public SXFCAggrC {
public:
//-----------------------------------------------------------------------------
//	�R���X�g���N�^
//-----------------------------------------------------------------------------
	SXFCSetC(SXFCKSchemaC *IN_schema) : SXFCAggrC(IN_schema) {
		m_name = "SET";
	}
protected:
};

//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			�쐬���F2000.04.23

	�P�D�@�\�T�v
		BAG�^���`�F�b�N�B

	�Q�D����
	����ԍ�	���t��		�S����		�T�v
	�쐬		2000.04.23	�@�@���{(FQS)	�Ȃ��B

**/
class SXFCBagC : public SXFCAggrC {
public:
//-----------------------------------------------------------------------------
//	�R���X�g���N�^
//-----------------------------------------------------------------------------
	SXFCBagC(SXFCKSchemaC *IN_schema) : SXFCAggrC(IN_schema) {
		m_name = "BAG";
	}
protected:
};

//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			�쐬���F2000.04.23

	�P�D�@�\�T�v
		ARRAY�^���`�F�b�N�B

	�Q�D����
	����ԍ�	���t��		�S����		�T�v
	�쐬		2000.04.23	�@�@���{(FQS)	�Ȃ��B

**/
class SXFCArrayC : public SXFCAggrC {
public:
//-----------------------------------------------------------------------------
//	�R���X�g���N�^
//-----------------------------------------------------------------------------
	SXFCArrayC(SXFCKSchemaC *IN_schema) : SXFCAggrC(IN_schema) {
		m_name = "ARRAY";
	}
protected:
};

//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			�쐬���F2000.04.23

	�P�D�@�\�T�v
		LIST�^���`�F�b�N�B

	�Q�D����
	����ԍ�	���t��		�S����		�T�v
	�쐬		2000.04.23	�@�@���{(FQS)	�Ȃ��B

**/
class SXFCListC : public SXFCAggrC {
public:
//-----------------------------------------------------------------------------
//	�R���X�g���N�^
//------------------------------------------------------------------------------
	SXFCListC(SXFCKSchemaC *IN_schema) : SXFCAggrC(IN_schema) {
		m_name = "LIST";
	}
protected:
};

//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			�쐬���F2000.04.23

	�P�D�@�\�T�v
		Part21�C���X�^���X���`�F�b�N�B

	�Q�D����
	����ԍ�	���t��		�S����		�T�v
	�쐬		2000.04.23	�@�@���{(FQS)	�Ȃ��B

**/
class SXFCKEntityC : public SXFCKAttrTypeC {
public:
//-----------------------------------------------------------------------------
//	�R���X�g���N�^
//-----------------------------------------------------------------------------
	SXFCKEntityC(SXFCKSchemaC *IN_schema) : SXFCKAttrTypeC(IN_schema) {
		/*	==>	Added by S.Kakizawa(KLS) on 2006/01/11	*/
		m_notArgs = TRUE;
		/*	<==	Added by S.Kakizawa(KLS) on 2006/01/11	*/
	}

//-----------------------------------------------------------------------------
//	�f�X�g���N�^
//-----------------------------------------------------------------------------
	virtual ~SXFCKEntityC();

//-----------------------------------------------------------------------------
//	������
//-----------------------------------------------------------------------------
	virtual BOOL Initialize();

//-----------------------------------------------------------------------------
//	�`�F�b�N
//-----------------------------------------------------------------------------
	virtual BOOL Check(SXFEntityDataC *IN_entity, 
					   SXFCheckContext *IN_context, 
					   SXFCKValue *val);

//-----------------------------------------------------------------------------
//	�G���e�B�e�B���`�F�b�N����
//-----------------------------------------------------------------------------
	BOOL CheckEntity(SXFEntityDataC *IN_entity, 
					 SXFCheckContext *IN_context, 
					 BOOL bComplex, SXFCKValue *val);

//-----------------------------------------------------------------------------
//	�T�u�^�C�v����
//-----------------------------------------------------------------------------
	BOOL IsSubclassOf(SXFCKEntityC *IN_ent);
protected:
//-----------------------------------------------------------------------------
//	�}�[�W�����������擾
//-----------------------------------------------------------------------------
	void GetMargedArgs(CArray<SXFCKAttrLink*,SXFCKAttrLink*> &IO_args);

//-----------------------------------------------------------------------------
//	�X�[�p�[�^�C�v
//-----------------------------------------------------------------------------
	CList<SXFCKAttrLink*,SXFCKAttrLink*>	m_supers;

//-----------------------------------------------------------------------------
//	����
//-----------------------------------------------------------------------------
	CList<SXFCKAttrLink*,SXFCKAttrLink*>	m_attrs;

//-----------------------------------------------------------------------------
//	DERIVE����
//-----------------------------------------------------------------------------
	CList<SXFCKDeriveAttrLink*,SXFCKDeriveAttrLink*>	m_deriveattrs;

	/*	==>	Added by S.Kakizawa(KLS) on 2006/01/11	*/
	//------------------------------------------------------------------------------------------------
	//	Attribute Name:
	//		m_args
	//	Exposition:
	//		Array of the Argument.
	//	Protective:
	//		protected
	//	Type:
	//		CArray<SXFCKAttrLink*,SXFCKAttrLink*>: Array of the Pointer to the Argument.
	//	History:
	//		Created by S.Kakizawa(KLS) on 2006/01/11.
	//	Notes:
	//		All Rights Reserved,(c) JACIC 2006
	//------------------------------------------------------------------------------------------------
	CArray<SXFCKAttrLink*,SXFCKAttrLink*>	m_args;

	//------------------------------------------------------------------------------------------------
	//	Attribute Name:
	//		m_notArgs
	//	Exposition:
	//		Flag for Set Argument.
	//	Protective:
	//		protected
	//	Type:
	//		BOOL : If this is 'TRUE', m_args has not yet Set.
	//	History:
	//		Created by S.Kakizawa(KLS) on 2006/01/11.
	//	Notes:
	//		All Rights Reserved,(c) JACIC 2006
	//------------------------------------------------------------------------------------------------
	BOOL									m_notArgs;
	/*	<==	Added by S.Kakizawa(KLS) on 2006/01/11	*/
};

//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			�쐬���F2000.04.23

	�P�D�@�\�T�v
		�^��`

	�Q�D����
	����ԍ�	���t��		�S����		�T�v
	�쐬		2000.04.23	�@�@���{(FQS)	�Ȃ��B

**/
class SXFCKTypeDefC : public SXFCKAttrTypeC {
public:
//-----------------------------------------------------------------------------
//	�R���X�g���N�^
//-----------------------------------------------------------------------------
	SXFCKTypeDefC(SXFCKSchemaC *IN_schema) : SXFCKAttrTypeC(IN_schema) {
	}
protected:
};

//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			�쐬���F2000.04.23

	�P�D�@�\�T�v
		�P���f�[�^�^��`

	�Q�D����
	����ԍ�	���t��		�S����		�T�v
	�쐬		2000.04.23	�@�@���{(FQS)	�Ȃ��B

**/
class SXFCKTypeDefSingleC : public SXFCKTypeDefC {
public:
//-----------------------------------------------------------------------------
//	�R���X�g���N�^
//-----------------------------------------------------------------------------
	SXFCKTypeDefSingleC(SXFCKSchemaC *IN_schema) : SXFCKTypeDefC(IN_schema) {
	}

//-----------------------------------------------------------------------------
//	�f�X�g���N�^
//-----------------------------------------------------------------------------
	virtual ~SXFCKTypeDefSingleC() {
	}

//-----------------------------------------------------------------------------
//	������
//-----------------------------------------------------------------------------
	virtual BOOL Initialize() {
		return m_schema->LinkAttr(&m_definedtype);
	}

//-----------------------------------------------------------------------------
//	�`�F�b�N
//-----------------------------------------------------------------------------
	virtual BOOL Check(SXFEntityDataC *IN_entity, 
					   SXFCheckContext *IN_context, 
					   SXFCKValue *val);
protected:
//-----------------------------------------------------------------------------
//	��`�^�f�[�^
//-----------------------------------------------------------------------------
	SXFCKAttrLink	m_definedtype;
};

//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			�쐬���F2000.04.23

	�P�D�@�\�T�v
		SELECT�^�`�F�b�N

	�Q�D����
	����ԍ�	���t��		�S����		�T�v
	�쐬		2000.04.23	�@�@���{(FQS)	�Ȃ��B

**/
class SXFCKSelectC : public SXFCKTypeDefC {
public:
//-----------------------------------------------------------------------------
//	�R���X�g���N�^
//-----------------------------------------------------------------------------
	SXFCKSelectC(SXFCKSchemaC *IN_schema) : SXFCKTypeDefC(IN_schema) {
	}

//-----------------------------------------------------------------------------
//	�f�X�g���N�^
//-----------------------------------------------------------------------------
	virtual ~SXFCKSelectC() {
//		for (int i = 0; i < m_select.GetSize(); i++) {
//			delete m_select[i];
//		}
		for(POSITION pos = m_select.GetHeadPosition(); pos; ) {
			delete m_select.GetNext(pos) ;
		}
	}

//-----------------------------------------------------------------------------
//	������
//-----------------------------------------------------------------------------
	virtual BOOL Initialize();

//-----------------------------------------------------------------------------
//	�`�F�b�N
//-----------------------------------------------------------------------------
	virtual BOOL Check(SXFEntityDataC *IN_entity, 
					   SXFCheckContext *IN_contex, 
					   SXFCKValue *valt);
protected:
//-----------------------------------------------------------------------------
//	SELECT�f�[�^
//-----------------------------------------------------------------------------
	CList<SXFCKAttrLink*,SXFCKAttrLink*>	m_select;
};

//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			�쐬���F2000.04.23

	�P�D�@�\�T�v
		ENUMERATION�^�`�F�b�N

	�Q�D����
	����ԍ�	���t��		�S����		�T�v
	�쐬		2000.04.23	�@�@���{(FQS)	�Ȃ��B

**/
class SXFCKEnumerationC : public SXFCKTypeDefC {
public:
//-----------------------------------------------------------------------------
//	�R���X�g���N�^
//-----------------------------------------------------------------------------
	SXFCKEnumerationC(SXFCKSchemaC *IN_schema) : SXFCKTypeDefC(IN_schema) {
	}
//-----------------------------------------------------------------------------
//	�f�X�g���N�^
//-----------------------------------------------------------------------------
	virtual ~SXFCKEnumerationC() {
//		for (int i = 0; i < m_enum.GetSize(); i++) {
//			delete m_enum[i];
//		}
		for(POSITION pos = m_enum.GetHeadPosition(); pos; ) {
			delete m_enum.GetNext(pos) ;
		}
	}

//-----------------------------------------------------------------------------
//	�`�F�b�N
//-----------------------------------------------------------------------------
	virtual BOOL Check(SXFEntityDataC *IN_entity, 
					   SXFCheckContext *IN_context, 
					   SXFCKValue *val);
protected:
//-----------------------------------------------------------------------------
//	ENUMERATION�f�[�^
//-----------------------------------------------------------------------------
	CList<SXFCKAttrLink*,SXFCKAttrLink*>	m_enum;
};

#endif // !defined(SXFCKSchemaC_INCLUDED_)
