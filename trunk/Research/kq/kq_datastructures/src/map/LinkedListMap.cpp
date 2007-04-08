#include "map/LinkedListMap.h"

using namespace kq::datastructures;
using namespace kq::datastructures::map;


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


const Value * LinkedListMap::lookup(const void * pKeyData, unsigned long ulKeySize){
	MapEntryNode * pEntry = 0;
	pEntry = findValue(pKeyData, ulKeySize);
	return &pEntry->v;
}
void LinkedListMap::setAt(const void * pKeyData, unsigned long ulKeySize, const void * pValue, unsigned long ulValueSize){
	MapEntryNode * pEntry = findValue(pKeyData,ulKeySize);	
	if(!pEntry){
		pEntry = new MapEntryNode();
		pEntry->pNext = m_pEntries;
		m_pEntries = pEntry;
		pEntry->k.makeEqualTo(pKeyData, ulKeySize);
	}	
	pEntry->v.makeEqualTo(pValue, ulValueSize);
}

MapEntryNode * LinkedListMap::findValue(const void * pKeyData,unsigned long ulKeySize){
	MapEntryNode * pEntry = m_pEntries;
	
	while(pEntry != 0){
		
		if(pEntry->k.isEqualTo(pKeyData, ulKeySize)){
			return pEntry;
		}

		pEntry = pEntry->pNext;
	};
	return pEntry;
}



