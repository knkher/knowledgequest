#ifndef LINKEDLISTMAP_H_
#define LINKEDLISTMAP_H_

#include "IMap.h"
#include "MapEntryNode.h"
namespace datastructures{
	namespace map{

		class LinkedListMap : public datastructures::map::IMap
		{
			
		private:
					MapEntryNode * m_pEntries;
					unsigned long m_ulEntriesCount;
		
					MapEntryNode * findValue(void * pKey, PointerSizeUnit ulKeySize);
								
				public:
					LinkedListMap();
					virtual ~LinkedListMap(void);
		
		
					
					bool LinkedListMap::lookup(void * pKeyData, PointerSizeUnit ulKeySize, Value & v);					
					void setAt(void * pKeyData, PointerSizeUnit ulKeySize, void * pValue, PointerSizeUnit ulValueSize);
		
		};
	}
}

#endif /*LINKEDLISTMAP_H_*/
