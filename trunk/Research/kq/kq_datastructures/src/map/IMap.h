#ifndef IMAP_H_
#define IMAP_H_

#include "Value.h"

namespace kq{
namespace datastructures{
	namespace map{
		class IMap
		{
		public:
			virtual const Value * lookup(const void * pKeyData, unsigned long ulKeySize) = 0;					
			virtual void setAt(const void * pKeyData, unsigned long ulKeySize, const void * pValue, unsigned long ulValueSize) = 0;
			virtual ~IMap();
		};
	}
}
}

#endif /*IMAP_H_*/
