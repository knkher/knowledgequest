#ifndef LINKEDLISTMAP_H_
#define LINKEDLISTMAP_H_

#include "IMap.h"
#include "MapEntryNode.h"
namespace kq{
namespace datastructures{
	namespace map{

		class LinkedListMap : public datastructures::map::IMap
		{
			
		private:
					MapEntryNode * m_pEntries;
					unsigned long m_ulEntriesCount;
		
					MapEntryNode * findValue(const void * pKey, unsigned long ulKeySize);
								
				public:
					LinkedListMap();
					virtual ~LinkedListMap(void);
		
		
					
					const Value * LinkedListMap::lookup(const void * pKeyData, unsigned long ulKeySize);					
					void setAt(const void * pKeyData, unsigned long ulKeySize, const void * pValue, unsigned long ulValueSize);
		
		};
	}
}
}

#endif /*LINKEDLISTMAP_H_*/
