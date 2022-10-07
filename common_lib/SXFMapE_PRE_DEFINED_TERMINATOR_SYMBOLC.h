/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC.h						�쐬���F2000.05.12

	�P�D�N���X�T�v
		PRE_DEFINED_TERMINATOR_SYMBOL���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
	    �쐬		2000.05.12	���{(FQS)	�Ȃ��B
**/

/*

			ENTITY pre_defined_terminator_symbol
				SUBTYPE OF (pre_defined_symbol);
				WHERE
					wr1: SELF.name IN [
									   'blanked arrow',
									   'blanked box',
									   'blanked dot',
									   'dimension origin',
									   'filled arrow',
									   'filled box',
									   'filled dot',
									   'integral symbol',
									   'open arrow',
									   'slash',
									   'unfilled arrow'
									   ];
			END_ENTITY;
*/

#ifndef _SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC_CLASS_
#define _SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC_CLASS_

class SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC:public SXFMapEntityBaseC{
public :

//-----------------------------------------------------------------------------
//	�R���X�g���N�^
//-----------------------------------------------------------------------------
	SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC( );
	SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC(
		SXFInstanceIDC* IN_InstanceIDManeger);

//-----------------------------------------------------------------------------
//	�f�X�g���N�^
//-----------------------------------------------------------------------------
	~SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC( );

//-----------------------------------------------------------------------------
//	���R�[�h���Z�b�g���郁���o�֐�
//-----------------------------------------------------------------------------
	int	SetParameter( );

public:

//-----------------------------------------------------------------------------
//	�����o�ϐ�
//----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//	�G���e�B�e�B��
//-----------------------------------------------------------------------------
	CString m_Name;

//-----------------------------------------------------------------------------
//	���R�[�h
//-----------------------------------------------------------------------------
	int		m_code;

};
#endif
////////////////////////////
