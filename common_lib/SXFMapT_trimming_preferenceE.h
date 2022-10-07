
/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapT_trimming_preferenceE.h						作成日：2000.04.21

	１．機能概要
		trimming_preferenceを定義する

		  TYPE trimming_preference = ENUMERATION OF
		    (cartesian,
		     parameter,
		     unspecified);
		  END_TYPE; -- trimming_preference

	２．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.21	
**/

#ifndef _trimming_preference_H_
#define	_trimming_preference_H_

typedef enum preferencetype{
	cartesian,
	parameter,
	unspecified
}trimming_preference_kind;

#endif
