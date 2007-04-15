#ifndef KQ_DS_TLL_H_
#define KQ_DS_TLL_H_

#include "SafeLinkedList.h"
#include "ITransportable.h"

namespace kq{
	namespace datastructures{
		class TransportableLinkedList:
			public ITransportable,
			public SafeLinkedList
		{
			//ITransportable
			virtual Payload toPayload();
			virtual void fromPayload(const Payload & payload);


		};
	};
}

#endif

