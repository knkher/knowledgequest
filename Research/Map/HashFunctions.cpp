#include "map.h"


using namespace Utilities::Map::HashFunctions;



ModHash::ModHash(unsigned long ulRange){
	m_ulRange = ulRange;
}

unsigned long ModHash::GetRange(){
	return m_ulRange;
}

unsigned long ModHash::Hash(void * pData, unsigned long ulDataSize){

	unsigned long retnVal = 0;

	if(ulDataSize < sizeof(unsigned long) ){

		//Store the important bytes only
		char * pInData = (char *)pData;
		char * pOutData = (char *)&retnVal;

		while(ulDataSize){
			*pOutData = *pInData;

			ulDataSize--;
			pOutData++;
			pInData++;
		}

		retnVal = Hash(&retnVal, sizeof(unsigned long));
		

	}else{	
		retnVal = (*((unsigned long *)(pData))) % m_ulRange;
	}
	
	return retnVal;
}