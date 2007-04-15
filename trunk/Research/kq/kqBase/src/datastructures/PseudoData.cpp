#include "PseudoData.h"

#include "malloc.h"
#include "memory.h"

using namespace kq::base::datastructures;


void PseudoData::pointTo(void *pLocation, unsigned long ulSize){
	m_pLocation = pLocation;
	m_ulSize = ulSize;
}

unsigned long PseudoData::getDataSize(){
	return m_ulSize;
}

void PseudoData::cleanup(){
	
}


unsigned long PseudoData::transfer(
						IData * pTargetData,
						unsigned long ulBytes,
						bool bReadFromTarget,
						unsigned long ulTargetOffset,
						unsigned long ulInternalOffset
						){

	//Check feasibility
	if(ulInternalOffset + ulBytes > m_ulSize){
		ulBytes = m_ulSize - ulInternalOffset;
	}

	//If not feasible reject operation
	if(ulBytes < 0){
		return 0;
	}

	void * pInnerLocation = (void *)(((char *)m_pLocation) + ulInternalOffset);

	/*
	if(bReadFromTarget){
		//We need to read from the target
		//But since we do not have the pointer to the targets memory
		//We must ask the target to write into ours memory
		ulBytesTransfered = 
			pTargetData->transfer(

				//Our location where the pTargetData is supposed to write
				pInnerLocation,

				//Bytes to be copied
				ulBytes,

				//The target should start copying from the offset we were supposed to read from
				ulTargetOffset,

				//Ok pTargetData is the source
				//while pInnerLocation is the dest, not the source , hence false
				false
				)
	}else{
		//We need to write data into pTargetData
		//but since we do not have its pointer
		//We will ask him to read from our pointer
		ulBytesTransfered = 
			pTargetData->transfer(

				//Our location, from here the pTargetData is supposed to read
				pInnerLocation,

				//Bytes to be read
				ulBytes,

				//pTargetData should write into itself after the offset we were asked to write
				ulTargetOffset,

				//Yes the first parameter is the source
				true
				);
	}
	*/

	//Read above comment for a better explaination
	//Since we do not have target's memory location, we ask target to do the reverse of what we were supposed to do;
	return pTargetData->transfer(pInnerLocation, ulBytes,!bReadFromTarget, ulTargetOffset);

}

unsigned long PseudoData::transfer(
						void * pTargetLocation,
						unsigned long ulBytes,
						bool bReadFromTarget,
						unsigned long ulInternalOffset
						){

	//Check feasibility
	if(ulInternalOffset + ulBytes > m_ulSize){
		ulBytes = m_ulSize - ulInternalOffset;
	}

	//If not feasible reject operation
	if(ulBytes < 0){
		return 0;
	}

	void * pInnerLocation = (void *)(((char *)m_pLocation) + ulInternalOffset);
	void * pSrc = 0;
	void * pDest = 0;

	if(bReadFromTarget){
		//Copy into object
		pDest = pInnerLocation;
		pSrc = pTargetLocation;
	}
	else{
		//Copy from object
		pSrc = pInnerLocation;
		pDest = pTargetLocation;
	}

	memcpy(pDest, pSrc, ulBytes);
	return ulBytes;
}