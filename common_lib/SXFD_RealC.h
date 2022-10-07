/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_RealC.h						作成日：2001.06.12

	１．クラス概要
		実数型要素を保持し出力するクラス

	２．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.12	佐々木(FQS)	なし。
**/
#ifndef _SXFD_REALC_H_
#define _SXFD_REALC_H_

#include "SXFInstanceC.h"

class SXFPart21FileC;

//
//	REAL DEFINITION
//
class SXFD_RealC : public SXFInstanceC {
protected :
//	float	m_Data ;////////m
	double	m_Data ;
public :
//
//	Default Constructor
//
	SXFD_RealC( ) { }
//
//	Constructor with Data
//
	SXFD_RealC(float) ;
	SXFD_RealC(double) ;
	SXFD_RealC(int) ;
//
//	Destructor
//
	~SXFD_RealC( ) { }
//
//	Data Set
//
	void	SetData( float data ) ;
	void	SetData( double data ) ;
	void	SetData( int data ) ;
//
//	Data Get
//
//	float	GetData( ) ;////////m
	double	GetData( ) ;////////m
//
//
//
	void WriteP21(SXFPart21FileC *IN_file){}
	virtual void WriteAttr(SXFPart21FileC *IN_file);
} ;

class SXFD_AngleC : public SXFD_RealC {
public:
	SXFD_AngleC() : SXFD_RealC() { }
	SXFD_AngleC(float data) : SXFD_RealC(data) {}
	SXFD_AngleC(double data) : SXFD_RealC(data) {}
	SXFD_AngleC(int data) : SXFD_RealC(data) {}
	virtual void WriteAttr(SXFPart21FileC *IN_file);
};

#endif	// _D_REAL_H_
