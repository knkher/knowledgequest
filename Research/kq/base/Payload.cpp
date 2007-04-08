#include "Payload.h"





using namespace datastructures;


SafePointer::SafePointer()
{
	init();
}

SafePointer::SafePointer(SafePointer & payload)
{
	init();
	makeEqualTo(payload.m_pLocation, payload.m_uSize);		
}

SafePointer::~SafePointer()
{
	clean();
	if(m_pLocation && m_uSize){
		printf("\nbase::Payload::~Payload::Warning: Data left floating.");
	}	
}

//void SafePointer::clean(){
//	if(m_uSize && m_pLocation){
//		printf("\nFreeing %u bytes at %p", m_uSize, m_pLocation);
//		free(m_pLocation);
//	}	
//	init();
//}
//
//void SafePointer::init(){
//	m_pLocation = 0;
//	m_uSize = 0;	
//}

//PointerSizeUnit SafePointer::getSize(){
//	return m_uSize;
//}
//void * SafePointer::getLocation(){
//	return m_pLocation;
//}



//int SafePointer::deepCopy(void * pLocation, PointerSizeUnit uSize){
//	clean();
//	
//	m_pLocation = malloc(uSize);
//	if(!m_pLocation){
//		return iFailure;
//	}
//	m_uSize = uSize;	
//	memcpy(m_pLocation, pLocation, m_uSize);	
//	return iSuccess;
//}

//
//bool SafePointer::isEqualTo(void * pLocation, PointerSizeUnit uSize){
//	
//	//If not of the same size then definitely not equal
//	if(m_uSize != uSize){
//		return false;
//	}
//	//Assume same size below
//	
//	//Now if same location then surely the same
//	if(m_pLocation == pLocation){
//		return true;
//	}
//	
//	if(memcmp(m_pLocation, pLocation, m_uSize) == 0){
//		return true;
//	}
//	
//	return false;
//}

//bool SafePointer::operator==(SafePointer & payload){
//	
//	if(this == &payload){
//		return true;
//	}
//	return isEqualTo(payload.m_pLocation, payload.m_uSize);	
//}

SafePointer & SafePointer::operator= (SafePointer & payload){
	deepCopy(payload.m_pLocation, payload.m_uSize);
	return *this;
}

SafePointer &  SafePointer::makeEqualTo (void * pLocation, PointerSizeUnit uSize){
	deepCopy(pLocation,uSize);
	return *this;
}
