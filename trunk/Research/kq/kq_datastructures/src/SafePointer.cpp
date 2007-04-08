
#include "SafePointer.h"

#include "malloc.h"
#include "memory.h"

#include "stdio.h"

using namespace kq::datastructures;


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
}

inline void SafePointer::init(){
	m_pLocation = 0;
	m_uSize = 0;	
}



inline void SafePointer::clean(){
	if(m_uSize && m_pLocation){
		//printf("\nSafePointer::clean()::Freeing %u bytes at %p", m_uSize, m_pLocation);
		free(m_pLocation);
		
	}	
	init();
}



inline int SafePointer::_replaceWith(const void * pLocation, unsigned long uSize){
	clean();

	m_pLocation = malloc(uSize);
	if(!m_pLocation){
		return iFailure;
	}
	m_uSize = uSize;	
	memcpy(m_pLocation, pLocation, m_uSize);
	//printf("\nSafePointer::_replaceWith::%ld bytes at %p are now safe",m_uSize, m_pLocation);
	return iSuccess;
}


void * SafePointer::getUnsafeCopy(){
	void * pRet = 0;
	pRet = malloc(m_uSize);
	if(pRet){
		memcpy(pRet,m_pLocation,m_uSize);
	}
	return pRet;
}



unsigned long SafePointer::getSize(){
	return m_uSize;
}


const void * SafePointer::revealLocation(){
	return (const void *)m_pLocation;
}


void SafePointer::makeEqualTo(const void * pLocation, unsigned long uSize){
	_replaceWith(pLocation, uSize);
}

void SafePointer::makeEqualTo(const SafePointer & spSource){
	_replaceWith(spSource.m_pLocation, spSource.m_uSize);
}

void SafePointer::operator =(const SafePointer & spSource){
	makeEqualTo(spSource);
}

bool SafePointer::isEqualTo(const void * pLocation, unsigned long uSize){
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

bool SafePointer::isEqualTo(const SafePointer & spOther){
	if(&spOther == this){
		return true;
	}
	return isEqualTo(spOther.m_pLocation, spOther.m_uSize);
}

void SafePointer::operator ==(const SafePointer & spOther){
	isEqualTo(spOther);
}

