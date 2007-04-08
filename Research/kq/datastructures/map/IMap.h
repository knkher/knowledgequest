#ifndef IMAP_H_
#define IMAP_H_

#include "Value.h"


namespace datastructures
{
	namespace map{
		class IMap
		{
		public:
			virtual bool lookup(void * pKeyData, PointerSizeUnit ulKeySize, Value & v) = 0;					
			virtual void setAt(void * pKeyData, PointerSizeUnit ulKeySize, void * pValue, PointerSizeUnit ulValueSize) = 0;
			virtual ~IMap();
		};
	}
}

#endif /*IMAP_H_*/
