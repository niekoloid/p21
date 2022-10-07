//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.h                    作成日：2000.04.10
// 
//	１．クラス概要
//      定義テーブルデータ値と定義テーブルMapping管理
//      オブジェクトのアドレスを保持し、定義テーブル
//      Mapping管理オブジェクトを管理する
//
//	２．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2000.04.10     周
//
//------------------------------------------------------------
#ifndef _SXFTABLEMANAGERC_H_
#define _SXFTABLEMANAGERC_H_

#include <afxtempl.h>

#include "SXFLayerC.h"
#include "SXFPreDefFontC.h"
#include "SXFUserDefFontC.h"
#include "SXFPreDefColorC.h"
#include "SXFUserDefColorC.h"
#include "SXFWidthC.h"
#include "SXFTextFontC.h"
#include "SXFDataStructC.h"
#include "SXFStruct.h"

class SXFPart21FileC;
class SXFComInfoC;
class SXFPart21FileWriteC;
class SXFInstanceIDC;

////////////////////////////////////////////////////////
class SXFPresentationSizeC {
public:
	SXFPresentationSizeC(){};
	~SXFPresentationSizeC(){};
	int sheetid;
	int planarboxid;
};

class SXFDranghtingTitleC{
public:
	SXFDranghtingTitleC(){};
	~SXFDranghtingTitleC(){};
	CArray<int,int> sheetidlist;
	CString    sheettitle;
};

// TableCodeのHASH用に追加：emoto010510
struct SXFTableCodeElem {
	int	id;
	int	getcode;
	int	codetype;
	SXFTableCodeElem & operator= (SXFTableCodeElem &src) {
		id = src.id;
		getcode = src.getcode;
		codetype = src.codetype;
		return *this;
	};
};

//	ADD(S)	Ver3.0対応	K.Naono	04.01.30
typedef struct tagATTRIBUTEINFO {
	int					id_draug_drw_rev ;
	int					id_draug_con_ass ;
	int					id_approval ;
	Attribute_Struct	attr_body ;

	tagATTRIBUTEINFO() {
		id_draug_drw_rev = id_draug_con_ass = -1 ;
		ZeroMemory(&attr_body, sizeof(Attribute_Struct)) ;
	}
} ATTRIBUTEINFO ;

typedef struct tagAPPDATETIMEINFO {
	int				id_cal_date ;
	int				id_approval ;
	tagAPPDATETIMEINFO() {
		id_cal_date = -1 ;
		id_approval = -1 ;
	}
} APPDATETIMEINFO ;

//	ADD(E)	Ver3.0対応	K.Naono	04.01.30

///////////////////////////////////////////
class SXFTableManagerC	
{
public:
	SXFTableManagerC();
	SXFTableManagerC(SXFComInfoC* IN_CommonInfo);
	SXFTableManagerC(SXFPart21FileC* IN_File);
	SXFTableManagerC(SXFPart21FileC* IN_File,SXFComInfoC* IN_CommonInfo,SXFPart21FileWriteC* IN_WriteFile,SXFInstanceIDC* IN_InstanceIDManager);
	SXFTableManagerC(SXFComInfoC* IN_CommonInfo,SXFInstanceIDC* IN_InstanceIDManager);
	virtual ~SXFTableManagerC();
	int RegisterStructTable( int IN_Type, LPVOID IN_Struct);
	int GetID(int IN_Type, int IN_Code);
	int GetCode(int IN_Type, int IN_ID);
	BOOL SetLayerElement(int IN_LayerCode, int IN_ElementID);
	BOOL SetLayerSheetID(int IN_SheetID);
	BOOL GetTextFontProperty(int IN_Code, double& OUT_Ascent,double& OUT_Decent);

	BOOL CheckSameLayer( LPCTSTR IN_Name);
	BOOL CheckSamePreDefColor( LPCTSTR IN_Name);
	BOOL CheckSamePreDefFont( LPCTSTR IN_Name);
	BOOL CheckSameUserDefFont( LPCTSTR IN_Name);
	
	///////// this check is not unsuitable ??????
	BOOL CheckSameWidth( double IN_Width);

	BOOL CheckSameTextFont( LPCTSTR IN_Name);

	BOOL LayerMapping();
	BOOL MappingInvisibility();

	//read
//	BOOL RegisterFeatureTable( INSTANCEDATA *IN_Instance );
// 	BOOL GetTableElement(int IN_Type, LPVOID& OUT_Struct, int& OUT_EndFlg);
 	BOOL GetTableElement(int IN_Type, LPVOID OUT_Struct, int* OUT_EndFlg);


///////////////////read ap202
	BOOL GetInvisibilityFlag(int IN_ID);
	BOOL RegisterInvisibility(INSTANCEDATA *IN_Instance);
	// TableCodeのHASH用に追加：emoto010510
	CMap<int,int&,SXFTableCodeElem,SXFTableCodeElem&>	m_TableCodeElemMap;
	BOOL	m_TableCodeElemMapInitialized;
	int  GetTableCode( int IN_ID, int& OUT_Type);
	int  RegisterAP202Table( int IN_ID,
							 int IN_Type,
							 LPVOID IN_Struct,
							 SXFTableMapManagerC* IN_MappingManager);

	BOOL MappingAP202Table();
	BOOL RegisterAP202IDTable(int IN_ID);
	BOOL SXFListToIntID(CString& IN_List, CUIntArray& OUT_IDArray);

	BOOL RegisterPresentationSize(INSTANCEDATA *IN_Instance);
	BOOL RegisterSheetTitle(INSTANCEDATA *IN_Instance);
	int GetPlanarBoxID(int IN_SheetID);
	BOOL GetSheetTitle(int IN_SheetID, CString& INOUT_SheetTitle);

public:
	int GetLevel1Code(int IN_Type,int IN_Code);
	//TABLEDATA:
	CArray<SXFLayerC,SXFLayerC&>				m_LayerTable;
	SXFPreDefFontC								m_PreDefFontTable[16];
	CArray<SXFUserDefFontC, SXFUserDefFontC&>	m_UserDefFontTable;
	SXFPreDefColorC								m_PreDefColorTable[16];
	CArray<SXFUserDefColorC, SXFUserDefColorC&> m_UserDefColorTable;
	SXFWidthC									m_WidthTable[16];
	CArray<SXFTextFontC, SXFTextFontC&>			m_TextFontTable;

	CUIntArray m_InvisibilityLayerTable;

	//make a big table include all of the table instance ID:
	//when read AP202 instance
	//only the instance id can register into the 1 idtable

	CUIntArray m_AP202IDTable;

	CArray<SXFPresentationSizeC*, SXFPresentationSizeC*> m_PresentationSizeTable;

	CArray<SXFDranghtingTitleC*, SXFDranghtingTitleC*> m_SheetTitleTable;

private:
	SXFPart21FileC* m_File;
	SXFPart21FileWriteC* m_WriteFile;
	SXFComInfoC* m_ComInfo;
	SXFInstanceIDC* m_InstanceIDManager;

	BOOL m_LayerFirstFlag;

	int m_CurrentType;
	int m_CurrentNumber;

	int m_PreDefWidthFlagTable[10];

	int userdefwidthcode;

//	ADD(S)	Ver3.0対応	K.Naono	04.01.30
public:
	BOOL				SetAttributeStruct(LPVOID IN_Struct) ;
	Attribute_Struct*	GetAttributeStruct() ;
	void				GetAttributeData(Attribute_Struct* OUT_Attr) ;
	BOOL				RegisterAttribute(INSTANCEDATA* IN_Instance) ;
	int					GetAttributeID() ;
	void				SetDraughtingDrawingRevID(int inID) {
		m_id_draug_drw_rev = inID ;
	}

private:
	//	(WRITE用)
	//	図面表題欄構造体
	Attribute_Struct*						m_Attribute_Str ;

	//	(READ用)
	//	DRAUGHTING_DRAWING_REVISIONのインスタンスID
	int		m_id_draug_drw_rev ;
    CArray<ATTRIBUTEINFO*,ATTRIBUTEINFO*&>		m_AttributeTable ;
    CArray<APPDATETIMEINFO,APPDATETIMEINFO&>	m_AppTimeTable ;
	ATTRIBUTEINFO*	GetAttributeInfo(int inID) ;
//	ADD(E)	Ver3.0対応	K.Naono	04.01.30

};

#endif
