#ifndef LINKEDLISTMAP_H_
#define LINKEDLISTMAP_H_

#include "IMap.h"
#include "MapEntryNode.h"
namespace base{
	namespace map{

		class LinkedListMap : public base::map::IMap
		{
			
		private:
					MapEntryNode * m_pEntries;
					unsigned long m_ulEntriesCount;
		
					MapEntryNode * findValue(void * pKey, PayloadSizeUnit ulKeySize);
								
				public:
					LinkedListMap();
					virtual ~LinkedListMap(void);
		
		
					
					bool LinkedListMap::lookup(void * pKeyData, PayloadSizeUnit ulKeySize, Value & v);					
					void setAt(void * pKeyData, PayloadSizeUnit ulKeySize, void * pValue, PayloadSizeUnit ulValueSize);
		
		};
	}
}

#endif /*LINKEDLISTMAP_H_*/
