#ifndef _SXFINSTANCEC_H_
#define _SXFINSTANCEC_H_

#include <fstream>
#include <afx.h>

class SXFPart21FileC;

class SXFInstanceC : public CObject{
public :
	virtual ~SXFInstanceC(){}
	virtual void WriteP21(SXFPart21FileC *IN_file){}
	virtual void WriteAttr(SXFPart21FileC *IN_file){}
	// ‘½díœ–hŽ~
	static void InitDeleteMap() {
		if (m_deleteMap) delete m_deleteMap;
		m_deleteMap = new CMapPtrToPtr;
	}
	static void EndDeleteMap() {
		if (m_deleteMap) delete m_deleteMap;
		m_deleteMap = NULL;
	}
	static CMapPtrToPtr *m_deleteMap;
	static BOOL CheckDeleteable(CObject *obj) {
		if (m_deleteMap == NULL) return TRUE;
		void *val;
		return  !m_deleteMap->Lookup((void*)obj, val);
	}
	static void AddDeleted(CObject *obj) {
		if (m_deleteMap) {
			m_deleteMap->SetAt((void*)obj, (void*)obj);
		}
	}
};
#endif // _SXFINSTANCEC_H_
