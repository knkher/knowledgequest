#include "Payload.h"
#include "stdio.h"
#include "memory.h"
#include "malloc.h"


using namespace base;


Payload::Payload()
{
	init();
}

Payload::Payload(Payload & payload)
{
		
}

Payload::~Payload()
{
	clean();
	if(m_pLocation && m_uSize){
		printf("\nbase::Payload::~Payload::Warning: Data left floating.");
	}	
}

void Payload::clean(){
	if(m_uSize && m_pLocation){
		printf("\nFreeing %u bytes at %p", m_uSize, m_pLocation);
		free(m_pLocation);
	}	
	init();
}

void Payload::init(){
	m_pLocation = 0;
	m_uSize = 0;	
}

PayloadSizeUnit Payload::getSize(){
	return m_uSize;
}
void * Payload::getLocation(){
	return m_pLocation;
}



//int Payload::deepCopy(Payload & payload){
//	if(&payload == this){
//		return iSuccess;
//	}
//	return deepCopy(payload.m_pLocation, payload.m_uSize);
//}

int Payload::deepCopy(void * pLocation, PayloadSizeUnit uSize){
	
//	if(m_pLocation && m_uSize){
//		printf("\nbase::Payload::_deepCopy::Warning: Data left floating.");
//	}

	clean();
	
	m_pLocation = malloc(uSize);
	if(!m_pLocation){
		return iFailure;
	}
	m_uSize = uSize;	
	memcpy(m_pLocation, pLocation, m_uSize);	
	return iSuccess;
}


bool Payload::isEqualTo(void * pLocation, PayloadSizeUnit uSize){
	
	//If not of the same size then definitely not equal
	if(m_uSize != uSize){
		return false;
	}
	//Assume same size below
	
	//Now if same location then surely the same
	if(m_pLocation == pLocation){
		return true;
	}
	
	if(memcmp(m_pLocation, pLocation, m_uSize) == 0){
		return true;
	}
	
	return false;
}

bool Payload::operator==(Payload & payload){
	
	if(this == &payload){
		return true;
	}
	return isEqualTo(payload.m_pLocation, payload.m_uSize);	
}

Payload & Payload::operator= (Payload & payload){
	deepCopy(payload.m_pLocation, payload.m_uSize);
	return *this;
}

Payload &  Payload::makeEqualTo (void * pLocation, PayloadSizeUnit uSize){
	deepCopy(pLocation,uSize);
	return *this;
}
