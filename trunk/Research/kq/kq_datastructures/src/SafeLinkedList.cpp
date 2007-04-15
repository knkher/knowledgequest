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


SafeLinkedListNode * SafeLinkedList::getLeftmostNode(){
	return m_pStart->getRigthNode();
}
SafeLinkedListNode * SafeLinkedList::getRightmostNode(){
	return m_pStart->getLeftNode();
}

unsigned long SafeLinkedList::getLength(){	
	return m_ulSize;
}


SafeLinkedListNode * SafeLinkedList::getNodeAt(unsigned int iPos){
	if(m_ulSize >= iPos || iPos < 0){
		return 0;
	}	
	//See if node is reachable faster from the other side of the linked list
	if(iPos > m_ulSize/2){
		return (m_pStart - iPos);
	}
	return (m_pStart + iPos);
}
void SafeLinkedList::addNodeAt(SafeLinkedListNode * pNode, unsigned int iPos){
	SafeLinkedListNode * pNodeToInsertAfter = 0;
	if(iPos == 0){
		pNodeToInsertAfter = m_pStart;
	}else{
		pNodeToInsertAfter = getNodeAt(iPos - 1);
	}

	if(pNodeToInsertAfter){
		pNode->insertAfter(pNodeToInsertAfter);
	}else{

	}
}