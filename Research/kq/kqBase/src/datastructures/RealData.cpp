#include "RealData.h"


#include "malloc.h"

using namespace kq::base::datastructures;


unsigned long RealData::getDataSize(){
	return 0;
}

RealData::RealData(unsigned long ulSize){	
	m_PseudoData.pointTo(malloc(ulSize), ulSize);
	if(!m_PseudoData.getLocation()){
		m_PseudoData.pointTo(0,0);
	}
}

void RealData::cleanup(){
	void * pLocation = m_PseudoData.getLocation();
	if(pLocation){
		delete pLocation;
	}
}


unsigned long RealData::transfer(
						IData * pTargetData,
						unsigned long ulBytes,
						bool bReadFromTarget,
						unsigned long ulTargetOffset,
						unsigned long ulInternalOffset
						){

	return m_PseudoData.transfer(pTargetData, ulBytes, bReadFromTarget, ulTargetOffset, ulInternalOffset);

}

unsigned long RealData::transfer(
						void * pTargetLocation,
						unsigned long ulBytes,
						bool bReadFromTarget,
						unsigned long ulInternalOffset
						){

	return m_PseudoData.transfer(pTargetLocation, ulBytes, bReadFromTarget, ulInternalOffset);

}

