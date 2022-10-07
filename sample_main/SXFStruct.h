//------------------------------------------------
//	�\���̂��`
//------------------------------------------------
#ifndef _STRUCT_H_
#define _STRUCT_H_

#include <afx.h>
#include <afxtempl.h>
#include "max.h"

//------------------------------------------------
//	�p��
//------------------------------------------------
typedef struct Sheet_StructDF{
	char name[MAXSHEETNAME];
	int type;
	int orient;
	int x;
	int y;
} Sheet_Struct;

//------------------------------------------------
//	���C��
//------------------------------------------------
typedef struct Layer_StructDF{
	char name[MAXLAYERNAME2];
	int lflag;
} Layer_Struct;

//------------------------------------------------
//	����`����
//------------------------------------------------
typedef struct Predefined_Linetype_StructDF{
	char name[MAXLINETYPENAME];
} Predefined_Linetype_Struct;

//------------------------------------------------
//	���[�U��`����
//------------------------------------------------
typedef struct Userdefined_Linetype_StructDF{
	char name[MAXLINETYPENAME];
	int segment;
	double pitch[MAXPITCH];
} Userdefined_Linetype_Struct;

//------------------------------------------------
//	����`�F
//------------------------------------------------
typedef struct Predefined_Colour_StructDF{
	char name[MAXCOLOURNAME];
} Predefined_Colour_Struct;

//------------------------------------------------
//	���[�U��`�F
//------------------------------------------------
typedef struct Userdefined_Colour_StructDF{
	int		red ;			//���C���R�[�h
	int		green ;			//�F�R�[�h
	int		blue ;			//����R�[�h
} Userdefined_Colour_Struct ;

//------------------------------------------------
//	����
//------------------------------------------------
typedef struct Line_Width_StructDF{
	double width;
} Line_Width_Struct;

//------------------------------------------------
//	�����t�H���g
//------------------------------------------------
typedef struct Text_Font_StructDF{
	char name[MAXTEXTFONTNAME];
} Text_Font_Struct;

//------------------------------------------------
//	�}�ʕ\�藓
//------------------------------------------------
typedef struct Attribute_StructDF{
	char	p_name[MAXTEXT];		/* ���Ɩ� */
	char	c_name[MAXTEXT];		/* �H���� */
	char	c_type[MAXTEXT];		/* �_��敪 */
	char	d_title[MAXTEXT];		/* �}�ʖ� */
	char	d_number[MAXTEXT];		/* �}�ʔԍ� */
	char	d_type[MAXTEXT];		/* �}�ʎ�� */
	char	d_scale[MAXTEXT];		/* �ړx */
	int		d_year;					/* �}�ʍ쐬�N(����) */
	int		d_month;				/* �}�ʍ쐬��(����) */
	int		d_day;					/* �}�ʍ쐬��(����) */
	char	c_contractor[MAXTEXT];	/* �󒍉�Ж� */
	char	c_owner[MAXTEXT];		/* �������ƎҖ� */
} Attribute_Struct;

//------------------------------------------------
//	�_�}�[�J
//------------------------------------------------
typedef struct Point_Marker_StructDF{
	int layer;				//���C���R�[�h
	int color;				//�F�R�[�h
	double start_x;			//�z�u�ʒuX���W
	double start_y;			//�z�u�ʒuY���W
	int marker_code;		//�}�[�J�R�[�h
	double rotate_angle;	//��]�p
	double scale;			//�ړx
} Point_Marker_Struct;

//------------------------------------------------
//	����
//------------------------------------------------
typedef struct Line_StructDF{
	int layer;				//���C���R�[�h
	int color;				//�F�R�[�h
	int type;				//����R�[�h
	int line_width;			//�����R�[�h
	double start_x;			//�n�_�w���W
	double start_y;			//�n�_�x���W
	double end_x;			//�I�_�w���W
	double end_y;			//�I�_�x���W
} Line_Struct;

//------------------------------------------------
//	�ܐ�
//------------------------------------------------
typedef struct Polyline_StructDF{
	int	layer ;					//���C���R�[�h
	int	color ;					//�F�R�[�h
	int	type ;					//����R�[�h
	int	line_width ;			//�����R�[�h
	int number;					//���_��
	CArray<double,double> x;	//X���W
	CArray<double, double> y;	//Y���W
} Polyline_Struct;

//------------------------------------------------
//	�~
//------------------------------------------------
typedef struct Circle_StructDF{
	int		layer ;			//���C���R�[�h
	int		color ;			//�F�R�[�h
	int		type ;			//����R�[�h
	int		line_width ;	//�����R�[�h
	double	center_x ;		//���S�w���W
	double	center_y ;		//���S�x���W
	double	radius ;		//���a
} Circle_Struct;

//------------------------------------------------
//	�~��
//------------------------------------------------
typedef struct Arc_StructDF{
	int	layer ;					//���C���R�[�h
	int	color ;					//�F�R�[�h
	int	type ;					//����R�[�h
	int	line_width ;			//�����R�[�h
	double	center_x ;			//���S�w���W
	double	center_y ;			//���S�x���W
	double	radius ;			//���a
	int direction;				//�����t���O
	double start_angle;			//�n�p
	double end_angle;			//�I�p
} Arc_Struct;

//------------------------------------------------
//	�ȉ~
//------------------------------------------------
typedef struct Ellipse_StructDF{

	int	layer ;					//���C���R�[�h
	int	color ;					//�F�R�[�h
	int	type ;					//����R�[�h
	int	line_width ;			//�����R�[�h
	double	center_x ;			//���S�w���W
	double	center_y ;			//���S�x���W
	double	radius_x ;			//X�������a
	double	radius_y ;			//Y�������a
	double rotation_angle;		//��]�p
} Ellipse_Struct;

//------------------------------------------------
//	���~��
//------------------------------------------------
typedef struct Ellipse_Arc_StructDF{
	int	layer ;					//���C���R�[�h
	int	color ;					//�F�R�[�h
	int	type ;					//����R�[�h
	int	line_width ;			//�����R�[�h
	double	center_x ;			//���S�w���W
	double	center_y ;			//���S�x���W
	double	radius_x ;			//X�������a
	double	radius_y ;			//Y�������a
	int direction;				//�����t���O
	double rotation_angle;		//��]�p
	double start_angle;			//�n�p
	double end_angle;			//�I�p
} Ellipse_Arc_Struct;

//------------------------------------------------
//	�����v�f
//------------------------------------------------
typedef struct Text_StructDF{
	int layer;				//���C���R�[�h
	int color;				//�F�R�[�h
	int font;				//�����t�H���g�R�[�h
	char str[MAXTEXT];		//������
	double text_x;			//�����z�u��_�w���W
	double text_y;			//�����z�u��_�x���W
	double height;			//�����͈͍�
	double width;			//�����͈͕�
	double spc;				//�����Ԋu
	double angle;			//������]�p
	double slant;			//�X�����g�p
	int b_pnt;				//�����z�u��_
	int direct;				//���������o������
} Text_Struct;

//------------------------------------------------
//	�X�v���C���Ȑ�
//------------------------------------------------
typedef struct Spline_StructDF{
	int	layer ;					//���C���R�[�h
	int	color ;					//�F�R�[�h
	int	type ;					//����R�[�h
	int	line_width ;			//�����R�[�h
	int open_close;				//�J�敪
	int number;					//���_��
	CArray<double,double> x;	//X���W
	CArray<double, double> y;	//Y���W
} Spline_Struct;

//------------------------------------------------
//	�N���\�C�h�Ȑ�
//------------------------------------------------
typedef struct Clothoid_StructDF{
	int	layer ;					/* ���C���R�[�h */
	int	color ;					/* �F�R�[�h */
	int	type ;					/* ����R�[�h */
	int	line_width ;			/* �����R�[�h */
	double	base_x ;			/* �z�u��_�w���W */
	double	base_y ;			/* �z�u��_�x���W */
	double	parameter ;			/* �N���\�C�h�p�����[�^ */
	int direction;				/* �����t���O */
	double angle;				/* ��]�p */
	double start_length;		/* �J�n�Ȑ��� */
	double end_length;			/* �I���Ȑ��� */
} Clothoid_Struct;

//------------------------------------------------
//	�����}�`��`
//------------------------------------------------
typedef struct Sfigorg_StructDF{
	char name[MAXFIGURENAME];
	int flag;
} Sfigorg_Struct;

//------------------------------------------------
//	�����}�`�z�u
//------------------------------------------------
typedef struct Sfigloc_StructDF{
	int layer;						//���C���R�[�h
	char name[MAXFIGURENAME];		//�����}�`��
	double x;						//�z�u�ʒuX���W
	double y;						//�z�u�ʒuY���W
	double angle;					//��]�p
	double ratio_x;					//X�����ړx
	double ratio_y;					//Y�����ړx
} Sfigloc_Struct;

//------------------------------------------------
//	����`�V���{��
//------------------------------------------------
typedef struct Externally_Defined_Symbol_StructDF{
	int layer;						//���C���R�[�h
	int color_flag;					//�F�R�[�h�t���O
	int color;						//�F�R�[�h
	char name[MAXSYMBOLNAME];		//�V���{����
	double start_x;					//�z�u�ʒuX���W
	double start_y;					//�z�u�ʒuY���W
	double rotate_angle;			//��]�p
	double scale;					//�{��
} Externally_Defined_Symbol_Struct;

//------------------------------------------------
//	�������@
//------------------------------------------------
typedef struct LinearDim_StructDF{
	int		layer ;			//���C���R�[�h
	int		color ;			//�F�R�[�h
	int		type ;			//����R�[�h
	int		line_width ;	//�����R�[�h

	double	sun_x1 ;		//���@���n�_�w���W
	double	sun_y1 ;		//���@���n�_�x���W
	double	sun_x2 ;		//���@���I�_�w���W
	double	sun_y2 ;		//���@���I�_�x���W

	int		flg2 ;			//�⏕���P�̗L���t���O(�O�F���A�P�F�L)
	double	ho1_x0 ;		//�⏕���P��_�w���W
	double	ho1_y0 ;		//�⏕���P��_�x���W
	double	ho1_x1 ;		//�⏕���P��_�w���W
	double	ho1_y1 ;		//�⏕���P��_�x���W
	double	ho1_x2 ;		//�⏕���P��_�w���W
	double	ho1_y2 ;		//�⏕���P��_�x���W

	int		flg3 ;			//�⏕���Q�̗L���t���O(�O�F���A�P�F�L)
	double	ho2_x0 ;		//�⏕���Q��_�w���W
	double	ho2_y0 ;		//�⏕���Q��_�x���W
	double	ho2_x1 ;		//�⏕���Q��_�w���W
	double	ho2_y1 ;		//�⏕���Q��_�x���W
	double	ho2_x2 ;		//�⏕���Q��_�w���W
	double	ho2_y2 ;		//�⏕���Q��_�x���W

	int		arr1_code1 ;	//���P�R�[�h
	int		arr1_code2 ;	//���P���O�R�[�h(�O�F�Ȃ��A�P�F�O�����A�Q�F������)
	double	arr1_x ;		//���P�z�u�n�_�w���W
	double	arr1_y ;		//���P�z�u�n�_�x���W
	double	arr1_r ;		//���P�z�u�{��

	int		arr2_code1 ;	//���Q�R�[�h
	int		arr2_code2 ;	//���Q���O�R�[�h(�O�F�Ȃ��A�P�F�O�����A�Q�F������)
	double	arr2_x ;		//���Q�z�u�n�_�w���W
	double	arr2_y ;		//���Q�z�u�n�_�x���W
	double	arr2_r ;		//���Q�z�u�{��

	int		flg4 ;			//���@�l�̗L���t���O(�O�F���A�P�F�L)
	int		font ;			//�����t�H���g�R�[�h
	char	str[MAXTEXT] ;	//������
	double	text_x ;		//������z�u��_�w���W
	double	text_y ;		//������z�u��_�x���W
	double	height ;		//�����͈͍�
	double	width ;			//�����͈͕�
	double	spc ;			//�����Ԋu
	double	angle ;			//�������]�p
	double	slant ;			//�X�����g�p�x
	int		b_pnt ;			//�����z�u��_(�P�F�����A�Q�F�����A�R�F�E���A�S�F�����A�T�F�����A�U�F�E���A�V�F����A�W�F����A�X�E��F)
	int		direct ;		//�������o������(�P�F�������A�Q�F�c����)
} LinearDim_Struct;

//------------------------------------------------
//  �ʒ����@
//------------------------------------------------
typedef struct CurveDim_StructDF{
	int layer;				/* ���C���R�[�h */
	int color;				/* �F�R�[�h */
	int type;				/* ����R�[�h */
	int line_width;			/* �����R�[�h */
	double sun_x;			/* ���@�����_�w���W */
	double sun_y;			/* ���@�����_�x���W */
	double sun_radius;		/* ���@�����a */
	double sun_angle0;		/* ���@���n�p */
	double sun_angle1;		/* ���@���I�p */
	int flg2;				/* �⏕���P�̗L���t���O(0:�� 1:�L) */
	double ho1_x0;			/* �⏕���P��_�w���W */
	double ho1_y0;			/* �⏕���P��_�x���W */
	double ho1_x1;			/* �⏕���P�n�_�w���W */
	double ho1_y1;			/* �⏕���P�n�_�x���W */
	double ho1_x2;			/* �⏕���P�I�_�w���W */
	double ho1_y2;			/* �⏕���P�I�_�x���W */
	int flg3;				/* �⏕���Q�̗L���t���O(0:�� 1:�L) */
	double ho2_x0;			/* �⏕���Q��_�w���W */
	double ho2_y0;			/* �⏕���Q��_�x���W */
	double ho2_x1;			/* �⏕���Q�n�_�w���W */
	double ho2_y1;			/* �⏕���Q�n�_�x���W */
	double ho2_x2;			/* �⏕���Q�I�_�w���W */
	double ho2_y2;			/* �⏕���Q�I�_�x���W */
	int arr1_code1;			/* ���P�R�[�h */
	int arr1_code2;			/* ���P���O�R�[�h */
	double arr1_x;			/* ���P�z�u�_�w���W */
	double arr1_y;			/* ���P�z�u�_�x���W */
	double arr1_r;			/* ���P�z�u�{�� */
	int arr2_code1;			/* ���Q�R�[�h */
	int arr2_code2;			/* ���Q���O�R�[�h */
	double arr2_x;			/* ���Q�z�u�_�w���W */
	double arr2_y;			/* ���Q�z�u�_�x���W */
	double arr2_r;			/* ���Q�z�u�{�� */
	int flg4;				/* ���@�l�̗L���t���O */
	int font;				/* �����t�H���g�R�[�h */
	char str[MAXTEXT];		/* ������ */
	double text_x;			/* ������z�u��_�w���W */
	double text_y;			/* ������z�u��_�x���W */
	double height;			/* �����͈͍� */
	double width;			/* �����͈͕� */
	double spc;				/* �����Ԋu */
	double angle;			/* �������]�p */
	double slant;			/* �X�����g�p�x */
	int b_pnt;				/* �����z�u��_ */
	int direct;				/* �������o������ */
} CurveDim_Struct;

///////////////////////////
//�p�x���@�t�B�[�`���\����
///////////////////////////
typedef struct AngularDim_StructDF{

	int layer;
	int color;
	int type;
	int line_width;

	double sun_x;
	double sun_y;
	double sun_radius;
	double sun_angle0;
	double sun_angle1;
//
	int flg2;
	double ho1_x0;
	double ho1_y0;
	double ho1_x1;
	double ho1_y1;
	double ho1_x2;
	double ho1_y2;
//

	int flg3;
	double ho2_x0;
	double ho2_y0;
	double ho2_x1;
	double ho2_y1;
	double ho2_x2;
	double ho2_y2;
//
	int arr1_code1;
	int arr1_code2;
	double arr1_x;
	double arr1_y;
	double arr1_r;
//
	int arr2_code1;
	int arr2_code2;
	double arr2_x;
	double arr2_y;
	double arr2_r;
//
	int flg4;
	int font;
	char str[MAXTEXT];
	double text_x;
	double text_y;
	double height;
	double width;
	double spc;
	double angle;
	double slant;
	int b_pnt;
	int direct;

} AngularDim_Struct;

///////////////////////////
//�p�x���@�t�B�[�`���\����
///////////////////////////
typedef struct RadiusDim_StructDF{

	int layer;
	int color;
	int type;
	int line_width;
//
	double sun_x1;
	double sun_y1;
	double sun_x2;
	double sun_y2;
//
	int arr_code1;
	int arr_code2;
	double arr_x;
	double arr_y;
	double arr_r;
//
	int flg;
	int font;
	char str[MAXTEXT];
	double text_x;
	double text_y;
	double height;
	double width;
	double spc;
	double angle;
	double slant;
	int b_pnt;
	int direct;
} RadiusDim_Struct;

///////////////////////////
//���a���@�t�B�[�`���\����
///////////////////////////
typedef struct DiameterDim_StructDF{

	int layer;
	int color;
	int type;
	int line_width;
//
	double sun_x1;
	double sun_y1;
	double sun_x2;
	double sun_y2;
//
	int arr1_code1;
	int arr1_code2;
	double arr1_x;
	double arr1_y;
	double arr1_r;
//
	int arr2_code1;
	int arr2_code2;
	double arr2_x;
	double arr2_y;
	double arr2_r;

	int flg;
	int font;
	char str[MAXTEXT];
	double text_x;
	double text_y;
	double height;
	double width;
	double spc;
	double angle;
	double slant;
	int b_pnt;
	int direct;
} DiameterDim_Struct;

typedef struct Label_StructDF{

	int layer;
	int color;
	int type;
	int line_width;
	int vertex_number;

	CArray<double, double> vertex_x;
	CArray<double, double> vertex_y;
		
	int arr_code;
	double arr_r;
	
	int flg;
	int font;
	char str[MAXTEXT];
	double text_x;
	double text_y;
	double height;
	double width;
	double spc;
	double angle;
	double slant;
	int b_pnt;
	int direct;
} Label_Struct;

typedef struct Balloon_StructDF{

	int layer;
	int color;
	int type;
	int line_width;
	int vertex_number;
	CArray<double,double> vertex_x;
	CArray<double,double> vertex_y;

	double center_x;
	double center_y;
	double radius;
	
	int arr_code;
	double arr_r;

	int flg;
	int font;
	char str[MAXTEXT];
	double text_x;
	double text_y;
	double height;
	double width;
	double spc;
	double angle;
	double slant;
	int b_pnt;
	int direct;
} Balloon_Struct;

typedef struct Externally_Defined_Hatch_StructDF{
	int layer;
	char name[MAXHATCHNAME];
	int out_id;
	int number;
	CArray<int, int> in_id;
} Externally_Defined_Hatch_Struct;

typedef struct Fill_area_style_colour_StructDF{
	int layer;
	int color;
	int out_id;
	int number;
	CArray<int,int> in_id;
} Fill_area_style_colour_Struct;

typedef struct Fill_area_style_hatching_StructDF{
	int layer;								//���C���R�[�h
	int hatch_number;						//�n�b�`���O���̃p�^�[����
	int hatch_color[MAXHATCHNUMBER];		//�n�b�`���O���̐F�R�[�h
	int hatch_type[MAXHATCHNUMBER];			//�n�b�`���O���̐���R�[�h
	int hatch_line_width[MAXHATCHNUMBER];	//�n�b�`���O���̐����R�[�h
	double hatch_start_x[MAXHATCHNUMBER];	//�n�b�`���O���̃p�^�[���J�n�_X���W
	double hatch_start_y[MAXHATCHNUMBER];	//�n�b�`���O���̃p�^�[���J�n�_Y���W
	double hatch_spacing[MAXHATCHNUMBER];	//�n�b�`���O�Ԋu
	double hatch_angle[MAXHATCHNUMBER];		//�n�b�`���O���̊p�x
	int out_id;								//�O�`�̕����Ȑ��̃t�B�[�`���R�[�h
	int number;								//�������̗̈搔
	CArray<int,int> in_id;					//�������̕����Ȑ��̃t�B�[�`���R�[�h
} Fill_area_style_hatching_Struct;				

typedef struct Fill_area_style_tiles_Struct{
	int layer;								//���C���R�[�h
	char name[MAXPRESYMBOLNAME];			//����`�V���{����
	int hatch_color;						//�n�b�`�p�^�[���̐F�R�[�h
	double hatch_pattern_x;					//�n�b�`�p�^�[���z�u�ʒuX���W
	double hatch_pattern_y;					//�n�b�`�p�^�[���z�u�ʒuY���W
	double hatch_pattern_vector1;			//�n�b�`�p�^�[���̌J��Ԃ��x�N�g���P�̑傫��
	double hatch_pattern_vector1_angle;		//�n�b�`�p�^�[���̌J��Ԃ��x�N�g���P�̊p�x
	double hatch_pattern_vector2;			//�n�b�`�p�^�[���̌J��Ԃ��x�N�g���Q�̑傫��
	double hatch_pattern_vector2_angle;		//�n�b�`�p�^�[���̌J��Ԃ��x�N�g���Q�̊p�x
	double hatch_pattern_scale_x;			//�n�b�`�p�^�[����X�ړx
	double hatch_pattern_scale_y;			//�n�b�`�p�^�[����Y�ړx
	double hatch_pattern_angle;				//�n�b�`�p�^�[���̌����̊p�x
	int out_id;								//�O�`�̕����Ȑ��̃t�B�[�`���R�[�h
	int number;								//�������̕̈搔
	CArray<int,int> in_id;					//�������̕����Ȑ��̃t�B�[�`���R�[�h
} Fill_area_style_tiles_Struct;

typedef struct Ccurve_Org_StructDF{
	int color;			//�F�R�[�h
	int type;			//����R�[�h
	int line_width;		//�����R�[�h
	int flag;			//�\��/��\���t���O
} Ccurve_Org_Struct;

//���@���pTerminator Symbol
typedef struct TermSymbol_StructDF{
	int target_ID;
	int flag;
	int color;
	int code;
	double direction_x;
	double direction_y;
	double x;
	double y;
	double scale;
} TermSymbol_Struct;

//���@���pProjection Line
typedef struct ProjLine_StructDF{
	int target_ID;
	double ho_x0;
	double ho_y0;
	double ho_x1;
	double ho_y1;
	double ho_x2;
	double ho_y2;
} ProjLine_Struct;

enum assembly{
	SHEET = 1,
	SFIG_ORG,
	CCURVE_ORG
};

typedef struct tagSXF_POINT {
	double	x ;
	double	y ;
} SXF_POINT;

#endif
