#include "DynamicLinkedNode.h"

using namespace kq::base::datastructures;


DynamicLinkedNode::DynamicLinkedNode(unsigned long nLinksPerAllocationBlock)
:LinkedNode(nLinksPerAllocationBlock),
m_Flanks(s_nFlanks){
	init();
}


unsigned long DynamicLinkedNode::getLinkCount(){
	DynamicLinkedNode * pNode = this;
	//The max returnable result is a full unsigned long
	//So we count how many FlankNodes's links will fill an unsined long
	unsigned long nMax = ((unsigned long)(-1));
	unsigned long bBadFit = (nMax % m_nLinks != 0)? 1 : 0;	
	unsigned long nFlankNodesCountable =  nMax / m_nLinks + bBadFit;


	unsigned long nFlankNodesPresent = 0;
	unsigned long nLinkCount = 0;
	while(pNode && (nFlankNodesPresent < nFlankNodesCountable)){
		nFlankNodesPresent++;
		nLinkCount += (pNode->m_nLinks - m_nFreeLinks);
		pNode->m_Flanks.getNodeOnLink(eFlankLocation_Right, 1);
	}

	if(nFlankNodesPresent >= nFlankNodesCountable){
		return nMax;
	}

	return nLinkCount;

}



LinkedNode * DynamicLinkedNode::getNodeOnLink(unsigned long iLink, unsigned long nTimes){

	DynamicLinkedNode * pNode = this;

	while(pNode && nTimes){
		unsigned long nFullNodesAhead = iLink / m_nLinks;
		unsigned long iLastNodeLink = iLink % m_nLinks;
	}
	

	return 0;
}
LinkedNode * DynamicLinkedNode::getLastNodeOnLink(unsigned long iLink){
	return 0;

}
void DynamicLinkedNode::setNodeOnLink(unsigned long iLink, LinkedNode * pNode){
}
LinkedNode * DynamicLinkedNode::traverse(NodeTraversalPattern ntp){
	//exit(-1);
	return 0;
}

		



void DynamicLinkedNode::init(){	
	m_nFreeLinks = m_nLinks;	
}

void DynamicLinkedNode::clean(){
	//See if anyone is there ahead
	DynamicLinkedNode * pNext = getFlank(eFlankLocation_Right);
	if(pNext){
		//Yes tell him to clean up
		pNext->clean();
		delete pNext;
	}

	//See if any one is there before
	//DynamicLinkedNode * pPrev = getFlank(eFlankLocation_Left);	
	//This shouldnt happen
	init();	
}



