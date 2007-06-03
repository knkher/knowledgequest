#ifndef KQ_DS_REALDATA
#define KQ_DS_REALDATA

#include "IData.h"
#include "PseudoData.h"

namespace kq{
	namespace base{
		namespace datastructures{
			class RealData:public IData{

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
				PseudoData m_PseudoData;
			public:				
				RealData(unsigned long ulSize);
			};
		};
	};
};

#endif