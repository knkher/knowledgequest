#ifndef IMAP_H_
#define IMAP_H_

#include "Value.h"


namespace base
{
	namespace map{
		class IMap
		{
		public:
			virtual bool lookup(void * pKeyData, PayloadSizeUnit ulKeySize, Value & v) = 0;					
			virtual void setAt(void * pKeyData, PayloadSizeUnit ulKeySize, void * pValue, PayloadSizeUnit ulValueSize) = 0;
			virtual ~IMap();
		};
	}
}

#endif /*IMAP_H_*/
