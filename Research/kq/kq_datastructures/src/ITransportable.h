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
