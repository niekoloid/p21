/**
	All Rights Reserved,(c)JACIC 2001
	SXFutyConvKanjiC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		JIS�R�[�h����UNICODE�̕ϊ�

	�Q�D����
		����ԍ�	���t		�S����			�T�v
		�쐬		2000.04.17	�{��(FQS)		�Ȃ��B
		�X�V		2015.04.27	T.Matsushima	JPCERT/CC �w�E �Ǝ㐫�Ή�
**/

#if !defined(AFX_UTYCONVKANJI_H__26C0F4A1_D841_11D3_8D34_0000E2071B4B__INCLUDED_)
#define AFX_UTYCONVKANJI_H__26C0F4A1_D841_11D3_8D34_0000E2071B4B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class SXFutyConvKanjiC  
{
public:
	SXFutyConvKanjiC();
	virtual ~SXFutyConvKanjiC();
//	static int ConvKanji(char *Direction,char *InChar,char *OutChar);
//	MOD(S)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
//	static int ToJIS(char *InChar, char *OutChar) ;
//	static int FromJIS(char *InChar, char *OutChar) ;
	static int ToJIS(char *InChar, char *OutChar,size_t OutCharSize) ;		// �o�b�t�@�T�C�Y��n���悤�ɕύX
	static int FromJIS(char *InChar, char *OutChar,size_t OutCharSize) ;	// �o�b�t�@�T�C�Y��n���悤�ɕύX
//	MOD(E)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27

private:
	static int AddTable(int KanjiTable[]);

};

#endif // !defined(AFX_UTYCONVKANJI_H__26C0F4A1_D841_11D3_8D34_0000E2071B4B__INCLUDED_)
