#ifndef KQ_DS_ITRANSPOTABLE_H_
#define KQ_DS_ITRANSPOTABLE_H_


#include "Payload.h"

namespace kq{
	namespace datastructures{
		class ITransportable{
		public:
			virtual Payload toPayload() = 0;
			virtual void fromPayload(const Payload & payload) = 0;
			virtual ~ITransportable();
		};
	}
}

#endif
