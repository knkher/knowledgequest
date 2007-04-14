#ifndef SINGLELEVELBUCKETMAP_H_
#define SINGLELEVELBUCKETMAP_H_

#include "IMap.h"
#include "LinkedListMap.h"
#include "hashfunctions/IHashFucntion.h"
namespace kq
{
	namespace datastructures{
		namespace map{
			class SingleLevelBucketMap : public IMap
			{
			
			private:
	
				unsigned long m_ulBuckets;
				LinkedListMap ** m_pBuckets;
	
				hashfunctions::IHashFunction * m_pHasher;
				unsigned long m_ulRange;
							
			public:
				SingleLevelBucketMap(hashfunctions::IHashFunction * pHasher);
				~SingleLevelBucketMap(void);
				
				virtual const Value * lookup(const void * pKeyData, unsigned long ulKeySize);
				virtual void setAt(const void * pKeyData, unsigned long ulKeySize, const void * pValue, unsigned long ulValueSize);
			};
		}
}
}

#endif /*SINGLELEVELBUCKETMAP_H_*/
