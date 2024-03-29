#ifndef KQ_DS_PSEUDODATA
#define KQ_DS_PSEUDODATA

#include "IData.h"

namespace kq{
	namespace base{
		namespace datastructures{
			class PseudoData:public IData{

			/////////////////////////////
			///////IData Impl////////////
			/////////////////////////////


			protected:
				void cleanup();
			public:
		
				unsigned long transfer(
										void * pTargetLocation,
										unsigned long ulBytes,
										bool bReadFromTarget,
										unsigned long ulInternalOffset
									);
				
				unsigned long transfer(
										IData * pTargetData,
										unsigned long ulBytes,
										bool bReadFromTarget,
										unsigned long ulTargetOffset,
										unsigned long ulInternalOffset
									);

		
				unsigned long getDataSize();


			protected:
				void * m_pLocation;
				unsigned long m_ulSize;
			public:
				void pointTo(void * pLocation, unsigned long ulSize);
				void * getLocation();
			
			};
		};
	};
};

#endif