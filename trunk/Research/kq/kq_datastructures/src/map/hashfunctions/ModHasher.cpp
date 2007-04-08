#include "map/hashfunctions/ModHasher.h"

#include "stdio.h"

using namespace kq::datastructures::map::hashfunctions;




ModHash::ModHash(unsigned long ulRange){
	m_ulRange = ulRange;
	//printf("\nModHash::ModHash(%ld) = %p",m_ulRange, this);
}

ModHash::~ModHash(){
	//printf("\nModHash::~ModHash(%ld) = %p",m_ulRange, this);
}

unsigned long ModHash::getRange(){
	return m_ulRange;
}

unsigned long ModHash::hash(const void * pData, unsigned long ulDataSize){

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

		retnVal = hash(&retnVal, sizeof(unsigned long));
		

	}else{	
		retnVal = (*((unsigned long *)(pData))) % m_ulRange;
	}
	
	return retnVal;
}
