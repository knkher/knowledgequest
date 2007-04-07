#include "LinkedListMap.h"

using namespace base::map;

LinkedListMap::LinkedListMap()
{
	m_pEntries = 0;
	m_ulEntriesCount = 0;
}

LinkedListMap::~LinkedListMap()
{
	MapEntryNode * pNextEntry = m_pEntries;
	MapEntryNode * pTemp;
	while(pNextEntry){
		pTemp = pNextEntry->pNext;
		delete pNextEntry;
		pNextEntry = pTemp;
	};
}


bool LinkedListMap::lookup(void * pKeyData, PayloadSizeUnit ulKeySize, Value & v){
	MapEntryNode * pEntry = 0;
	pEntry = findValue(pKeyData, ulKeySize);
	if(!pEntry){
		return false;
	}
	v = pEntry->v;
	return true;
}
void LinkedListMap::setAt(void * pKeyData, PayloadSizeUnit ulKeySize, void * pValue, PayloadSizeUnit ulValueSize){
	MapEntryNode * pEntry = findValue(pKeyData,ulKeySize);	
	if(!pEntry){
		pEntry = new MapEntryNode();
		pEntry->pNext = m_pEntries;
		m_pEntries = pEntry;
		pEntry->k.makeEqualTo(pKeyData, ulKeySize);
	}	
	pEntry->v.makeEqualTo(pValue, ulValueSize);
}

MapEntryNode * LinkedListMap::findValue(void * pKeyData,PayloadSizeUnit ulKeySize){
	MapEntryNode * pEntry = m_pEntries;
	
	while(pEntry != 0){
		
		if(pEntry->k.isEqualTo(pKeyData, ulKeySize)){
			return pEntry;
		}

		pEntry = pEntry->pNext;
	};
	return pEntry;
}



