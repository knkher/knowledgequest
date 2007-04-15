#ifndef KQ_B_DS_IDN
#define KQ_B_DS_IDN


namespace kq{
	namespace base{
		namespace datastructures{
			class IData{

				friend class DataFactory;

			protected:	
				virtual void cleanup();
				~IData();
				


			public:

				virtual unsigned long transfer(
												void * pTargetLocation,
												unsigned long ulBytes,
												bool bReadFromTarget = true,
												unsigned long ulInternalOffset = 0
											) = 0;
				
				virtual unsigned long transfer(
												IData * pTargetData,
												unsigned long ulBytes,
												bool bReadFromTarget = true,
												unsigned long ulTargetOffset = 0,												
												unsigned long ulInternalOffset = 0												
											) = 0;

				//Get the size of the data in bytes
				virtual unsigned long getDataSize() = 0;

				//The destructor isnt virtual, derived people should deallocate their memory in cleanup
				

			
			};
		}
	}
}


#endif