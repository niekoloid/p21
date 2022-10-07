////////////////////////////
/////
/////ŠO•”•Ï”::SXF_EXT.h
/////
/////////////////////////////
#ifndef _SXF_EXT_H_
#define _SXF_EXT_H_

#ifdef EXT_BODY
#	define SEXT
#else
#	define SEXT extern
#endif

#include <fstream>
#include <afx.h>
#include "SXFManageC.h"

SEXT int gl_InstanceID;
SEXT SXFManageC *gl_Man;
SEXT ofstream *gl_log_file;
SEXT CObList gl_ErrorList;
SEXT CString gl_FileVersion;

#endif
