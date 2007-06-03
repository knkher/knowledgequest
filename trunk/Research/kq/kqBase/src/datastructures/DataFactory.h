#ifndef KQ_B_DS_DF
#define KQ_B_DS_DF

#include "IData.h"

namespace kq{
	namespace base{
		namespace datastructures{			
		
			class DataFactory
			{
			private:
				static DataFactory  * s_pTheOneFactory;
				
			public:
				static DataFactory * getInstance();
				static void	destroyFactory();


			private:
				DataFactory(void);
				virtual ~DataFactory(void);


			public:

				void destroyData(IData * pData);

				//Will get a thin (light weight) IData, basically just a pointer
				IData * createPseudoData(void * pDataLocation, unsigned long uDataSize);

				//Will get a managed (heavyt weight) IData, basically just a area in memory
				IData * createRealData(void * pDataLocation, unsigned long uDataSize);
				IData * createRealData(unsigned long uDataSize);

			};

		}//DS
	}//B
}//KQ

#endif
