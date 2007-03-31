#include ".\map.h"

#include "memory.h"
#include "malloc.h"


using namespace Utilities::Map;


////////////////////////////
////////////////////////////
//////Safe Pointer//////////
////////////////////////////
////////////////////////////

SafeData::SafeData(){
	m_ulSize = 0;
	clean();
}

SafeData::SafeData(SafeData &sdSource)
{
	m_ulSize = 0;	
	deepCopy(&sdSource);
}
SafeData::~SafeData(){
	clean();
}

void SafeData::clean(){	
	if(m_ulSize){
		delete m_pData;
	}
	m_pData = 0;
	m_ulSize = 0;
}

bool SafeData::deepCopy(SafeData * pSource){
	return deepCopy(pSource->m_pData,pSource->m_ulSize);	
}

bool SafeData::deepCopy(void * pData, unsigned long ulDataSize){
	clean();
	if(!ulDataSize) return false;

	m_ulSize = ulDataSize;
	m_pData = malloc(ulDataSize);
	if(!m_pData){
		return false;
	}

	memcpy(m_pData, pData, m_ulSize);	
	return true;
}

void SafeData::operator = (SafeData & sdSource){
	deepCopy(&sdSource);
}

bool SafeData::operator == (SafeData & sdSource){
	
	return isEqual(sdSource.m_pData, sdSource.m_ulSize);
}

bool SafeData::isEqual(void * pData, unsigned long ulDataSize){
	if(m_ulSize != ulDataSize){
		return false;
	}
	if(m_ulSize == 0){
		return false;
	}

	if(memcmp(m_pData,pData, m_ulSize) == 0){
		return true;
	}

	return false;
}

////////////////////////////
////////////////////////////
////////Linear Map//////////
////////////////////////////
////////////////////////////


LinearMap::LinearMap(){
	m_pEntries = 0;
	m_ulEntriesCount = 0;
}

LinearMap::~LinearMap(void)
{
	IMapEntry * pNextEntry = m_pEntries;
	IMapEntry * pTemp;
	while(pNextEntry){
		pTemp = pNextEntry->pNext;
		delete pNextEntry;
		pNextEntry = pTemp;
	};
}

bool LinearMap::lookup(void * pKey, unsigned long ulKeySize, Value & v){
	IMapEntry * pEntry = 0;
	pEntry = findValue(pKey, ulKeySize);
	if(!pEntry){
		return false;
	}
	v = pEntry->v;
	return true;
}
void LinearMap::setAt(void * pKey, unsigned long ulKeySize, void * pValue, unsigned long ulValueSize){
	IMapEntry * pEntry = findValue(pKey,ulKeySize);	
	if(!pEntry){
		pEntry = new IMapEntry();
		pEntry->pNext = m_pEntries;
		m_pEntries = pEntry;
		pEntry->k.deepCopy(pKey, ulKeySize);
	}	
	pEntry->v.deepCopy(pValue,ulValueSize);
}

IMapEntry * LinearMap::findValue(void * pKey, unsigned long ulKeySize){
	IMapEntry * pEntry = m_pEntries;
	
	while(pEntry != 0){

		if(pEntry->k.isEqual(pKey, ulKeySize)){
			return pEntry;
		}

		pEntry = pEntry->pNext;
	};
	return pEntry;
}




////////////////////////////
////////////////////////////
///////Simple Map///////////
////////////////////////////
////////////////////////////

SimpleBucketMap::SimpleBucketMap(HashFunctions::IHashFunction * pHasher){
	
	m_pHasher = pHasher;
	m_ulBuckets = pHasher->GetRange();

	m_pBuckets = new LinearMap *[m_ulBuckets];

	

	unsigned long iBucket;
	for( iBucket = 0; iBucket < m_ulBuckets ; iBucket++){
		m_pBuckets[iBucket] = new LinearMap();
	}
	
}

SimpleBucketMap::~SimpleBucketMap(void){	

	unsigned long iBucket;
	for( iBucket = 0; iBucket < m_ulBuckets ; iBucket++){
		delete (m_pBuckets[iBucket]);
		m_pBuckets[iBucket] = 0;
	}

	delete []m_pBuckets;
	m_pBuckets = 0;
}


bool SimpleBucketMap::lookup(void * pKey, unsigned long ulKeySize, Value & v){
	unsigned long iBucket = m_pHasher->Hash(pKey, ulKeySize);
	return m_pBuckets[iBucket]->lookup(pKey, ulKeySize, v);	
}


void SimpleBucketMap::setAt(void * pKey, unsigned long ulKeySize, void * pValue, unsigned long ulValueSize){
	unsigned long iBucket = m_pHasher->Hash(pKey, ulKeySize);
	m_pBuckets[iBucket]->setAt(pKey, ulKeySize, pValue, ulValueSize);
}

