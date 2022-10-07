#ifndef _SXFAPIFUNCEXTAP202_H_
#define _SXFAPIFUNCEXTAP202_H_

#include <afx.h>

extern int WINAPI SXFdelete_assembly_AP202(int, void*&);
extern int WINAPI SXFdelete_feature_AP202(char*,void*&);
extern int WINAPI SXFopen_AP202(char[257],int,double,double,double,int,int,char[257],char[257],char[257],char[257]);
extern int WINAPI SXFset_file_version_AP202(char[257]);
extern int WINAPI SXFget_file_version_AP202(char[257]);
extern int WINAPI SXFclose_AP202();
extern int WINAPI SXFwrite_next_feature_AP202(char*, void*);
extern int WINAPI SXFread_assembly_name_AP202(int,void* &,int*);
extern int WINAPI SXFread_next_feature_AP202(char*,void* &,int*);
extern int WINAPI SXFwrite_assembly_name_AP202(int,void*);
extern int WINAPI SXFwrite_table_AP202(int,void*);
extern int WINAPI SXFread_table_AP202(int,void*,int*);
extern int WINAPI SXFPopMsg_AP202(char*&,int*,char* &);

#endif
