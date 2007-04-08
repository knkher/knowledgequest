#include "SafeLinkedList.h"

using namespace kq::datastructures;



SafeLinkedList::SafeLinkedList(){
	init();
}

SafeLinkedList::~SafeLinkedList(){
	clean();
	delete m_pStart;
}

void SafeLinkedList::init(){
	
	m_pStart = new SafeLinkedListNode();	
	m_ulSize = 0;
}

void SafeLinkedList::clean(){
	SafeLinkedListNode * pNextTarget = 0;
	SafeLinkedListNode * pCurrentTarget = m_pStart->getRigthNode();
	while(pCurrentTarget){
		pNextTarget = pCurrentTarget->getRigthNode();
		delete pCurrentTarget;
		pCurrentTarget = pNextTarget;
	}
	m_pStart->clean();
}
