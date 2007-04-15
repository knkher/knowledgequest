#include "Pointer.h"

#include "malloc.h"
#include "memory.h"

using namespace kq::datastructures;

Pointer::Pointer(void)
{
	pointTo();
}

Pointer::Pointer(void * pLocation, unsigned long uSize){
	pointTo(pLocation,uSize);
}

Pointer::Pointer(Pointer &pointer){
	pointTo(pointer.m_pLocation, pointer.m_uSize);
}


Pointer::~Pointer(void)
{
	pointTo();
}


void Pointer::pointTo(void * pLocation, unsigned long ulSize){
	m_uSize = ulSize;
	m_pLocation = pLocation;
}


Pointer * Pointer::getDataCopy(){
	Pointer * pRet = new Pointer(malloc(m_uSize),m_uSize);
	memcpy(pRet->m_pLocation, m_pLocation, m_uSize);
	return pRet;
}