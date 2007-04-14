#include "SingleLevelBucketMap.h"

using namespace kq::datastructures;
using namespace kq::datastructures::map;

SingleLevelBucketMap::SingleLevelBucketMap(hashfunctions::IHashFunction * pHasher){
	
	m_pHasher = pHasher;
	m_ulBuckets = pHasher->getRange();

	m_pBuckets = new LinkedListMap *[m_ulBuckets];

	

	unsigned long iBucket;
	for( iBucket = 0; iBucket < m_ulBuckets ; iBucket++){
		m_pBuckets[iBucket] = new LinkedListMap();
	}
	
}

SingleLevelBucketMap::~SingleLevelBucketMap(void){	

	unsigned long iBucket;
	for( iBucket = 0; iBucket < m_ulBuckets ; iBucket++){
		delete (m_pBuckets[iBucket]);
		m_pBuckets[iBucket] = 0;
	}

	delete []m_pBuckets;
	m_pBuckets = 0;
}


const Value * SingleLevelBucketMap::lookup(const void * pKeyData, unsigned long ulKeySize){
	unsigned long iBucket = m_pHasher->hash(pKeyData, ulKeySize);
	return m_pBuckets[iBucket]->lookup(pKeyData, ulKeySize);	
}


void SingleLevelBucketMap::setAt(const void * pKeyData, unsigned long ulKeySize, const void * pValue, unsigned long ulValueSize){
	unsigned long iBucket = m_pHasher->hash(pKeyData, ulKeySize);
	m_pBuckets[iBucket]->setAt(pKeyData, ulKeySize, pValue, ulValueSize);
}

