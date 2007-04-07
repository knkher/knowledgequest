#include "Payload.h"
#include "stdio.h"
#include "memory.h"
#include "malloc.h"


using namespace base;


Payload::Payload(void * pLocation, unsigned int uSize)
{
	init();
	m_pLocation = pLocation;
	m_uSize = uSize;
}

Payload::Payload(Payload & payload)
{
	*this = payload;	
}

Payload::~Payload()
{
	if(m_pLocation && m_uSize){
		printf("\nbase::Payload::_deepCopy::Probably Data left floating. For safety use clean() before destruction.");
	}	
}

void Payload::clean(){
	if(m_uSize && m_pLocation){
		free(m_pLocation);
	}	
	init();
}

void Payload::init(){
	m_pLocation = 0;
	m_uSize = 0;	
}

unsigned int Payload::getSize(){
	return m_uSize;
}
void * Payload::getLocation(){
	return m_pLocation;
}


int Payload::_deepCopy(Payload * pPayload){
	if(m_pLocation && m_uSize){
		printf("\nbase::Payload::_deepCopy::Probably Data left floating. For safety use clean() before deep copy operations.");
	}	
	
	m_pLocation = malloc(pPayload->m_uSize);
	if(!m_pLocation){
		return iFailure;
	}
	m_uSize = pPayload->m_uSize;	
	memcpy(m_pLocation, pPayload->m_pLocation, m_uSize);
	
	return iSuccess;
	
}
int Payload::deepCopy(Payload & payload){
	if(&payload == this){
		return iSuccess;
	}
	return _deepCopy(&payload);
}

bool Payload::operator==(Payload & payload){
	//If not of the same size then definitely not equal
	if(m_uSize != payload.m_uSize){
		return false;
	}
	//Assume same size below
	
	//Now if same location then surely the same
	if(m_pLocation == payload.m_pLocation){
		return true;
	}
	
	if(memcmp(m_pLocation, payload.m_pLocation, m_uSize) == 0){
		return true;
	}
	
	return false;
	
}

Payload & Payload::operator= (Payload & payload){
	m_uSize = payload.m_uSize;
	m_pLocation = payload.m_pLocation;
	return *this;
}
