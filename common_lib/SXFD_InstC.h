/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_InstC.h						作成日：2000.04.12

	１．クラス概要
		インスタンスを保持し出力するクラス

	２．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.12	宮園(FQS)	なし。
**/
#ifndef _SXFD_INSTC_H_
#define _SXFD_INSTC_H_
#include "SXFInstanceC.h"
#include <afx.h>

class SXFPart21FileC;
//
//	APP INSTANCE DEFINITION
//
class SXFD_InstC : public SXFInstanceC{
protected :
	int			m_Flg;
	int			m_InstanceID ;
	CString  	m_Entity ;
	CObList		m_Data ;
public :
//
//	Default Constructor
//
	SXFD_InstC( ) ;
//
//	Constructor
//
	SXFD_InstC(int) ;
//
//	Destructor
//
	~SXFD_InstC( ) ;
//
//	Entity Definition
//
	void	SetEntity( CString ) ;
//
//	Instance Attribute Data Definition
//
	void	AddAttr( CObject * ) ;
//
//
//
	CObList&	GetAttr(  ) ;
//
//
//
//	void		SetInsID();
//
//
//
	int		GetInsID();
//
//
//
    void	WriteP21(SXFPart21FileC *IN_file) ;
//
//
//
	void    WriteAttr(SXFPart21FileC *IN_file);
} ;

#endif	// _D_INST_H_
