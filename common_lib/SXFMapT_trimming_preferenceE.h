
/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapT_trimming_preferenceE.h						�쐬���F2000.04.21

	�P�D�@�\�T�v
		trimming_preference���`����

		  TYPE trimming_preference = ENUMERATION OF
		    (cartesian,
		     parameter,
		     unspecified);
		  END_TYPE; -- trimming_preference

	�Q�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.21	
**/

#ifndef _trimming_preference_H_
#define	_trimming_preference_H_

typedef enum preferencetype{
	cartesian,
	parameter,
	unspecified
}trimming_preference_kind;

#endif
