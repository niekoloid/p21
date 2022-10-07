/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_TRIMMED_CURVEC.cpp						作成日：2000.04.17

	１．クラス概要
		TRIMMED_CURVEを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapE_CARTESIAN_POINTC.h"
#include "SXFMapE_LINEC.h"
#include "SXFMapE_CIRCLEC.h"
#include "SXFMapE_ELLIPSEC.h"
#include "SXFMapE_CLOTHOIDC.h"

#include "SXFMapEntAConvC.h"
#include "SXFErrorMsgC.h"
#include "SXFMapE_TRIMMED_CURVEC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_TRIMMED_CURVEC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapE_TRIMMED_CURVEC::SXFMapE_TRIMMED_CURVEC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_TRIMMED_CURVEC::SXFMapE_TRIMMED_CURVEC()
{
//	<初期化>
	m_EntityName = DEF_TRIMMED_CURVE;

//<エンティティデータ>
//#427 = TRIMMED_CURVE('trimmed_curve3', #426, (#422), (#421), .T., .CARTESIAN.);
//#521 = TRIMMED_CURVE('',#520,(#516,PARAMETER_VALUE(0.0)),(#517,
//       PARAMETER_VALUE(12.383404246416728)),.T.,.PARAMETER.);

	//1.nameパラメタ
	m_name.Empty();
	
	//2.basis_curve へのインスタンスID
	m_basis_curve_Inst=0;
	//basis_curveへのポインタ
	m_basis_curve_P = NULL;
	//basis_curveの名前
	m_basis_curve_Name.Empty();

	//3.trim_1 へのインスタンスID
	m_trim_1_Inst= 0;
	//trim_1へのポインタ
	m_trim_1_P = NULL;
	m_trim1_para = 0.;
	
	//3.trim_2 へのインスタンスID
	m_trim_2_Inst = 0;
	//trim_2へのポインタ
	m_trim_2_P = NULL;
	m_trim2_para = 0.;

	//4.sense_agreement
	m_sense = TRUE;

	//5.master_representation
	m_e_rep = cartesian;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_TRIMMED_CURVEC.cpp						作成日：2000.04.17

	１．機能概要
		インスタンスＩＤへのポインタを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapE_TRIMMED_CURVEC::SXFMapE_TRIMMED_CURVEC(
						SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	引数  ：	型				引数名				内容
				SXFInstanceIDC* IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ
			
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_TRIMMED_CURVEC::SXFMapE_TRIMMED_CURVEC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
{
//	<初期化>
	m_EntityName = DEF_TRIMMED_CURVE;
//<エンティティデータ>
//<エンティティデータ>
//#427 = TRIMMED_CURVE('trimmed_curve3', #426, (#422), (#421), .T., .CARTESIAN.);
//#521 = TRIMMED_CURVE('',#520,(#516,PARAMETER_VALUE(0.0)),(#517,
//       PARAMETER_VALUE(12.383404246416728)),.T.,.PARAMETER.);

	//1.nameパラメタ
	m_name.Empty();
	
	//2.basis_curve へのインスタンスID
	m_basis_curve_Inst=0;
	//basis_curveへのポインタ
	m_basis_curve_P = NULL;
	//basis_curveの名前
	m_basis_curve_Name.Empty();

	//3.trim_1 へのインスタンスID
	m_trim_1_Inst= 0;
	//trim_1へのポインタ
	m_trim_1_P = NULL;
	m_trim1_para = 0.;

	//3.trim_2 へのインスタンスID
	m_trim_2_Inst = 0;
	//trim_2へのポインタ
	m_trim_2_P = NULL;
	m_trim2_para = 0.;

	//4.sense_agreement
	m_sense = TRUE;

	//5.master_representation
	m_e_rep = cartesian;

	
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_TRIMMED_CURVEC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapE_TRIMMED_CURVEC::~SXFMapE_TRIMMED_CURVEC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_TRIMMED_CURVEC::~SXFMapE_TRIMMED_CURVEC()
{
	if(m_trim_1_P != NULL)
	{
		delete m_trim_1_P;
	}
	if(m_trim_2_P != NULL)
	{
		delete m_trim_2_P;
	}
	if(m_basis_curve_P != NULL)
	{
		if (m_basis_curve_Name==DEF_LINE)	
				delete (SXFMapE_LINEC*)m_basis_curve_P;
		if (m_basis_curve_Name==DEF_CIRCLE)
				delete (SXFMapE_CIRCLEC*)m_basis_curve_P;
		if (m_basis_curve_Name==DEF_ELLIPSE)
				delete (SXFMapE_ELLIPSEC*)m_basis_curve_P;
		if (m_basis_curve_Name==DEF_CLOTHOID)
				delete (SXFMapE_CLOTHOIDC*)m_basis_curve_P;
	}
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_TRIMMED_CURVEC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティのパラメタ設定

	２．インターフェイス
		int		SXFMapE_TRIMMED_CURVEC::SetParameter()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
int SXFMapE_TRIMMED_CURVEC::SetParameter()

{
	int ircode;
	int OUT_Num;

//	<1. エンティティパラメタの設定> ////////////////////////////////////////

//<エンティティデータ>
//#427 = TRIMMED_CURVE('trimmed_curve3', #426, (#422), (#421), .T., .CARTESIAN.);
//#521 = TRIMMED_CURVE('',#520,(#516,PARAMETER_VALUE(0.0)),(#517,
//       PARAMETER_VALUE(12.383404246416728)),.T.,.PARAMETER.);
//#104 = TRIMMED_CURVE('trimmed_curve1', #103, (PARAMETER_VALUE(3.141593)), 
//(PARAMETER_VALUE(0.)), .T., .PARAMETER.);

	SXFMapEntAConvC convent(m_EntityArray);
	//	1.nameパラメタ>
	convent.GetCString(0,m_name);
	
	//	2.basis_curve へのインスタンスID
	convent.GetInst(1,m_basis_curve_Inst);


	//4.sense_agreement
	convent.GetBOOL(4,m_sense);

	//5.master_representation
	CString IN_EntityData;
	convent.GetCString(5,IN_EntityData);
	ircode = GetEnumType(IN_EntityData,m_e_rep);
		if ( ircode < 0 ){
		// SCADECの対象ではないENTITYです
			SXFErrorMsgC::RecordError(
				SXFEXCEPT,			//errメッセージ番号
				m_EntityName,		//エンティティ名
				2,					//パラメタの個数
				m_RootID,			//パラメタ
				m_EntityName
				);
			return SXFEXCEPT;
		}
		


//	<2. trim1,trim2の値設定>///////////////////////////////////////////////

	if ( m_e_rep == cartesian ) {

		CArray<int,int> Out_IntArray;
		//	3.trim_1 へのインスタンスID
		convent.GetSetInst(2,OUT_Num,Out_IntArray);
		m_trim_1_Inst= Out_IntArray[0];

		//	3.trim_2 へのインスタンスID
		convent.GetSetInst(3,OUT_Num,Out_IntArray);
		m_trim_2_Inst= Out_IntArray[0];

		//CARTESIAN_POINT
		//エンティティインスタンスを作成
		m_trim_1_P = new SXFMapE_CARTESIAN_POINTC(m_InstanceIDManager);
		ircode = m_trim_1_P->SetRootID(m_trim_1_Inst);
			if ( ircode < 0 )	return ircode ;
		//エンティティパラメタの設定
		ircode = m_trim_1_P->SetParameter();
			if ( ircode < 0 )	return ircode ;

		//CARTESIAN_POINT
		//エンティティインスタンスを作成
		m_trim_2_P = new SXFMapE_CARTESIAN_POINTC(m_InstanceIDManager);
		ircode = m_trim_2_P->SetRootID(m_trim_2_Inst);
			if ( ircode < 0 )	return ircode ;
		//エンティティパラメタの設定
		ircode = m_trim_2_P->SetParameter();
			if ( ircode < 0 )	return ircode ;
	}
	else if ( m_e_rep == parameter ) {
		CArray<double,double> Out_DoubleArray;
		//	3.trim_1 へのインスタンスID
		convent.GetSetSelectDouble(2,DEF_PARAMETER_VALUE,OUT_Num, Out_DoubleArray);
		m_trim1_para= Out_DoubleArray[0];

		//	3.trim_2 へのインスタンスID
		convent.GetSetSelectDouble(3,DEF_PARAMETER_VALUE,OUT_Num,Out_DoubleArray);
		m_trim2_para= Out_DoubleArray[0];
	}
	
//	<3. basis_curve //////////////////////////////////////////////////////////
	CString InstEntityName;
	//basis_curveを取得し、判別する。
	InstEntityName = SXFMapInstIDC::GetEntityName(m_basis_curve_Inst);

	//LINE
	if (InstEntityName.Find(DEF_LINE) != -1){
		m_basis_curve_Name=DEF_LINE;
		m_basis_curve_P = new SXFMapE_LINEC(m_InstanceIDManager);
		((SXFMapE_LINEC*)m_basis_curve_P)->SetRootID(m_basis_curve_Inst);
		((SXFMapE_LINEC*)m_basis_curve_P)->SetParameter();
	}
	//CIRCLE
	else if (InstEntityName.Find(DEF_CIRCLE) != -1){
		m_basis_curve_Name=DEF_CIRCLE;
		m_basis_curve_P = new SXFMapE_CIRCLEC(m_InstanceIDManager);
		((SXFMapE_CIRCLEC*)m_basis_curve_P)->SetRootID(m_basis_curve_Inst);
		((SXFMapE_CIRCLEC*)m_basis_curve_P)->SetParameter();
	}
	//ELLIPSE
	else if (InstEntityName.Find(DEF_ELLIPSE) != -1){
		m_basis_curve_Name=DEF_ELLIPSE;
		m_basis_curve_P = new SXFMapE_ELLIPSEC(m_InstanceIDManager);
		((SXFMapE_ELLIPSEC*)m_basis_curve_P)->SetRootID(m_basis_curve_Inst);
		((SXFMapE_ELLIPSEC*)m_basis_curve_P)->SetParameter();	
	}
	//CLOTHOID
	else if (InstEntityName.Find(DEF_CLOTHOID) != -1){
		m_basis_curve_Name=DEF_CLOTHOID;
		m_basis_curve_P = new SXFMapE_CLOTHOIDC(m_InstanceIDManager);
		((SXFMapE_CLOTHOIDC*)m_basis_curve_P)->SetRootID(m_basis_curve_Inst);
		((SXFMapE_CLOTHOIDC*)m_basis_curve_P)->SetParameter();	
	}
	//その他
	else {
			// SCADECの対象ではないENTITYです
		SXFErrorMsgC::RecordError(
			SXFEXCEPT,			//errメッセージ番号
			m_EntityName,		//エンティティ名
			2,					//パラメタの個数
			m_RootID,			//パラメタ
			m_EntityName
			);
		return SXFEXCEPT;
	}


	return 0;
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapT_trimming_preferenceE.cpp						作成日：2000.04.21

	１．機能概要
		trimming_preferenceを定義する

		  TYPE trimming_preference = ENUMERATION OF
		    (cartesian,
		     parameter,
		     unspecified);
		  END_TYPE; -- trimming_preference

	２．インターフェース
	int	GetEnumType(CString IN_EntityData,	preferencetype& OUT_Enum )
	
	引数:	型				引数名			内容
			CString 		IN_EntityData
			preferencetype& OUT_Enum

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.21	
**/

int	SXFMapE_TRIMMED_CURVEC::GetEnumType(CString IN_EntityData,	preferencetype& OUT_Enum )
{

		if (IN_EntityData.Find(DEF_D_CARTESIAN) != -1){
			OUT_Enum = 	cartesian;
		}
		else if ( IN_EntityData.Find(DEF_D_PARAMETER) != -1){
			OUT_Enum = 	parameter;
		}
		else if ( IN_EntityData.Find(DEF_D_UNSPECIFIED) != -1){
			OUT_Enum = 	unspecified;
		}
		else{
			//SCADECの対象外エンティティ -54000
			return SXFEXCEPT;
		}
	
	return 0;
}


