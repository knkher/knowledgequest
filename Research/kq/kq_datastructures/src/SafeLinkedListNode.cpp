#include "SafeLinkedListNode.h"

using namespace kq::datastructures;

SafeLinkedListNode::SafeLinkedListNode()
{
	init();
}

SafeLinkedListNode::~SafeLinkedListNode()
{
	clean();
}

void SafeLinkedListNode::init(){
	m_pLeft = 0;
	m_pRight = 0;
	m_spData.init();			
}

void SafeLinkedListNode::clean(){
	m_spData.clean();
	init();
}

void SafeLinkedListNode::insertAfter(SafeLinkedListNode * pLeft){
	SafeLinkedListNode *pRight = pLeft->m_pRight;

	//Linked from self to left;
	m_pLeft = pLeft;

	//Link from self to right;
	m_pRight = pRight;

	//Linked from left to self
	if(pLeft){
		pLeft->m_pRight = this;
	}

	//Link from right to self
	if(pRight){
		pRight->m_pLeft = this;
	}
}

void SafeLinkedListNode::setData(void * pDataLocation, unsigned long uDataSize){
	m_spData.makeEqualTo(pDataLocation, uDataSize);
}

void SafeLinkedListNode::setData(const SafePointer & spData){
	m_spData.makeEqualTo(spData);
}

SafePointer SafeLinkedListNode::getData(){
	return m_spData;
}

SafeLinkedListNode * SafeLinkedListNode::getLeftNode(){
	return m_pLeft;
}

SafeLinkedListNode * SafeLinkedListNode::getRigthNode(){
	return m_pRight;
}
