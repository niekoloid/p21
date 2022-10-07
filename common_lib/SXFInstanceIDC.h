//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFInstanceIDC.h                     作成日：2000.04.07
//
//	１．クラス概要
//      エンティティデータオブジェクトのアドレスを
//      ハッシューテーブルで管理し、エンティティデータの
//      FileMappingのFile作成と管理する
//      
//	２．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2000.04.07    周
//
//------------------------------------------------------------
#ifndef _SXFINSTANCEIDC_H_
#define _SXFINSTANCEIDC_H_

#include "Afxtempl.h"
#include "SXFFetIDC.h"

#include "SXFDataStructC.h"
class SXFEntityDataC;

/*	==>	Commented by S.Kakizawa(KLS) on 2006/01/12	//
typedef CMap<int,int&,SXFEntityDataC*,SXFEntityDataC*&> SXFMapIntToPtrC;
/*	<==	Commented by S.Kakizawa(KLS) on 2006/01/12	*/
/*	==>	Modified by S.Kakizawa(KLS) on 2006/01/12	*/
#define	ARRAY_GROWSIZE			(32768)				//	Growing Size of the Array of the Entity

//------------------------------------------------------------------------------------------------
//	Entity Name:
//		SXFTableInstanceC
//	Exposition:
//		Instance Table in the P21 File.
//	History:
//		Created by S.Kakizawa(KLS) on 2006/01/12.
//	Notes:
//		All Rights Reserved,(c) JACIC 2006
//------------------------------------------------------------------------------------------------
class SXFTableInstanceC
{
public:
	//------------------------------------------------------------------------------------------------
	//	SXFTableInstanceC::SXFTableInstanceC
	//------------------------------------------------------------------------------------------------
	SXFTableInstanceC( );

	//------------------------------------------------------------------------------------------------
	//	SXFTableInstanceC::~SXFTableInstanceC
	//------------------------------------------------------------------------------------------------
	~SXFTableInstanceC( );

	//------------------------------------------------------------------------------------------------
	//	SXFTableInstanceC::Add
	//------------------------------------------------------------------------------------------------
	void Add( SXFEntityDataC* poEntity );

	//------------------------------------------------------------------------------------------------
	//	Method Name:
	//		SXFTableInstanceC::operator []
	//	Exposition:
	//		Get the Entity at the Specified Index.
	//	Protective:
	//		public
	//	Return Value:
	//		SXFEntityDataC* : Pointer to the 'SXFEntityDataC' Object.
	//	Parameters:
	//		DWORD dwIndex : Index where Entity is Got at.
	//	History:
	//		Created by S.Kakizawa(KLS) on 2006/01/12.
	//	Notes:
	//		All Rights Reserved,(c) JACIC 2006
	//------------------------------------------------------------------------------------------------
	inline SXFEntityDataC* operator []( DWORD dwIndex ) const
	{
		if( m_dwMaxCount <= dwIndex )
		{
			return	NULL;
		}

		return	m_pData[dwIndex/ARRAY_GROWSIZE][dwIndex%ARRAY_GROWSIZE];
	}


private:
	//------------------------------------------------------------------------------------------------
	//	Attribute Name:
	//		m_pData
	//	Exposition:
	//		Table of the Entities.
	//	Protective:
	//		private
	//	Type:
	//		SXFEntityDataC*** : Triple Pointer to the Entities.
	//	History:
	//		Created by S.Kakizawa(KLS) on 2006/01/12.
	//	Notes:
	//		All Rights Reserved,(c) JACIC 2006
	//------------------------------------------------------------------------------------------------
	SXFEntityDataC*** m_pData;

	//------------------------------------------------------------------------------------------------
	//	Attribute Name:
	//		m_dwTableCount
	//	Exposition:
	//		Count of the Array.
	//	Protective:
	//		private
	//	Type:
	//		DWORD : DWORD.
	//	History:
	//		Created by S.Kakizawa(KLS) on 2006/01/12.
	//	Notes:
	//		All Rights Reserved,(c) JACIC 2006
	//------------------------------------------------------------------------------------------------
	DWORD m_dwTableCount;

	//------------------------------------------------------------------------------------------------
	//	Attribute Name:
	//		m_dwCount
	//	Exposition:
	//		Count of the Entities.
	//	Protective:
	//		private
	//	Type:
	//		DWORD : DWORD.
	//	History:
	//		Created by S.Kakizawa(KLS) on 2006/01/12.
	//	Notes:
	//		All Rights Reserved,(c) JACIC 2006
	//------------------------------------------------------------------------------------------------
	DWORD m_dwCount;

	//------------------------------------------------------------------------------------------------
	//	Attribute Name:
	//		m_dwMaxCount
	//	Exposition:
	//		Maximum Count for Setting Entities.
	//	Protective:
	//		private
	//	Type:
	//		DWORD : DWORD.
	//	History:
	//		Created by S.Kakizawa(KLS) on 2006/01/12.
	//	Notes:
	//		All Rights Reserved,(c) JACIC 2006
	//------------------------------------------------------------------------------------------------
	DWORD m_dwMaxCount;
};

//------------------------------------------------------------------------------------------------
//	Entity Name:
//		SXFMapIntToPtrC
//	Exposition:
//		Mapping Table for Instance Number(Integer) to the Pointer of the Instance.
//	History:
//		Created by S.Kakizawa(KLS) on 2006/01/12.
//	Notes:
//		All Rights Reserved,(c) JACIC 2006
//------------------------------------------------------------------------------------------------
class SXFMapIntToPtrC
{
public:
	//------------------------------------------------------------------------------------------------
	//	Method Name:
	//		SXFMapIntToPtrC::SXFMapIntToPtrC
	//	Exposition:
	//		Default Constructor.
	//	Protective:
	//		public
	//	Return Value:
	//		None.
	//	Parameters:
	//		None.
	//	History:
	//		Created by S.Kakizawa(KLS) on 2006/01/12.
	//	Notes:
	//		All Rights Reserved,(c) JACIC 2006
	//------------------------------------------------------------------------------------------------
	SXFMapIntToPtrC( )
	{
		for( int iLoop=0; iLoop<10; iLoop++ )
		{
			m_pData[iLoop]	= NULL;
		}
	}

	//------------------------------------------------------------------------------------------------
	//	Method Name:
	//		SXFMapIntToPtrC::~SXFMapIntToPtrC
	//	Exposition:
	//		Destructor.
	//	Protective:
	//		public
	//	Return Value:
	//		None.
	//	Parameters:
	//		None.
	//	History:
	//		Created by S.Kakizawa(KLS) on 2006/01/12.
	//	Notes:
	//		All Rights Reserved,(c) JACIC 2006
	//------------------------------------------------------------------------------------------------
	~SXFMapIntToPtrC( )
	{
		for( int iLoop=0; iLoop<10; iLoop++ )
		{
			if( m_pData[iLoop] )
			{
				delete m_pData[iLoop];
			}
		}
	}

	//------------------------------------------------------------------------------------------------
	//	Method Name:
	//		SXFMapIntToPtrC::Lookup
	//	Exposition:
	//		Look up the Instance which has the Specified Instance Number from the Mapping Table.
	//	Protective:
	//		public
	//	Return Value:
	//		BOOL : Result of the Check.
	//				TRUE	: Is Inside
	//				FALSE	: Is Outside
	//	Parameters:
	//		DWORD IN_InstanceID : Instance Number
	//		SXFEntityDataC*& rec : Reference to the Pointer to the Instance.
	//	History:
	//		Created by S.Kakizawa(KLS) on 2006/01/12.
	//	Notes:
	//		All Rights Reserved,(c) JACIC 2006
	//------------------------------------------------------------------------------------------------
	BOOL Lookup( DWORD IN_InstanceID, SXFEntityDataC*& rec )
	{
		rec	= NULL;

		int					iArray	= IN_InstanceID % 10;
		SXFTableInstanceC*&	pData	= m_pData[iArray];
		if( m_pData[iArray] )
		{
			rec	= (*m_pData[iArray])[IN_InstanceID/10];
		}

		return	NULL != rec;
	}

	//------------------------------------------------------------------------------------------------
	//	Method Name:
	//		SXFMapIntToPtrC::SetAt
	//	Exposition:
	//		Set the Instance which has the Specified Instance Number into the Mapping Table.
	//	Protective:
	//		public
	//	Return Value:
	//		None.
	//	Parameters:
	//		DWORD IN_InstanceID : Instance Number
	//		SXFEntityDataC*& rec : Reference to the Pointer to the Instance.
	//	History:
	//		Created by S.Kakizawa(KLS) on 2006/01/12.
	//	Notes:
	//		All Rights Reserved,(c) JACIC 2006
	//------------------------------------------------------------------------------------------------
	void SetAt( DWORD IN_InstanceID, SXFEntityDataC* rec )
	{
		int					iArray	= IN_InstanceID % 10;
		SXFTableInstanceC*&	pData	= m_pData[iArray];
		if( NULL == pData )
		{
			pData	= new SXFTableInstanceC;
		}

		pData->Add( rec );
	}

private:
	//------------------------------------------------------------------------------------------------
	//	Attribute Name:
	//		m_pData
	//	Exposition:
	//		Array of the Entity Table.
	//	Protective:
	//		private
	//	Type:
	//		SXFTableInstanceC* [10]: Array of the Pointer to the Entity Table.
	//	History:
	//		Created by S.Kakizawa(KLS) on 2006/01/12.
	//	Notes:
	//		All Rights Reserved,(c) JACIC 2006
	//------------------------------------------------------------------------------------------------
	SXFTableInstanceC* m_pData[10];
};
/*	<==	Modified by S.Kakizawa(KLS) on 2006/01/12	*/

class SXFInstanceIDC  
{
public:
	SXFInstanceIDC();
	virtual ~SXFInstanceIDC();

	BOOL RegisterInstance(INSTANCEDATA *IN_Instance);
	SXFEntityDataC* GetEntityDataPtr(int IN_InstanceID);
	int GetNewInstanceID();
//	MOD(S)	チューニング対応	K.Naono	03.07.03
//	CArray<SXFEntityDataC*,SXFEntityDataC*>	m_EntityArray;
	CList<SXFEntityDataC*,SXFEntityDataC*>	m_EntityArray;
//	MOD(E)	チューニング対応	K.Naono	03.07.03
/*  メソッドを追加  */
	SXFEntityDataC *Lookup(int IN_InstanceID) {
		SXFEntityDataC *rec;
		if (m_EntityMap.Lookup(IN_InstanceID, rec)) {
			return rec;
		}
		return NULL;
	};

	BOOL InitFileMapping(int IN_FileSize);

//	MOD(S)	チューニング対応	K.Naono	03.07.03
/*
	CArray<int,int>* GetIDArray(CString IN_InstanceName); 
*/
	CList<int,int>* GetIDArray(CString IN_InstanceName); 
//	MOD(E)	チューニング対応	K.Naono	03.07.03

public:

	SXFFetIDC	m_FeatureIDManager;
	int			m_TempFileSize;

private:

	SXFMapIntToPtrC	m_EntityMap;

	CString		m_FileName;
	LPVOID		m_MapViewPtr;
	LPVOID		m_DataPtrInMapFile;
	HANDLE		m_MapFile;
	HANDLE		m_TempFile;
//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
	size_t		m_AvailableSize;	// m_DataPtrInMapFileが利用できる残りサイズ

//	MOD(S)	チューニング対応	K.Naono	03.07.03
/*
	CArray<int,int> m_ComplexInstanceTable;
	CArray<int,int> m_StyledItemTable;
*/
	CList<int,int>	m_ComplexInstanceTable;
	CList<int,int>	m_StyledItemTable;
//	MOD(E)	チューニング対応	K.Naono	03.07.03
};

#endif

