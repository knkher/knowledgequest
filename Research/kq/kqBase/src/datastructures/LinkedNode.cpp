#include "LinkedNode.h"

using namespace kq::base::datastructures;

LinkedNode::LinkedNode(unsigned long nLinks)
{	
	m_nLinks = nLinks;
	init();
}


LinkedNode::~LinkedNode()
{
	clean();
}

unsigned long LinkedNode::getLinkCount(){	
	return m_nLinks;
}

void LinkedNode::init(){
	m_pLinks = 0;
	clean();
	m_pLinks = new LinkedNode *[m_nLinks];
	if(m_pLinks){
		unsigned long iLink;
		for(iLink = 0; iLink < m_nLinks ; iLink++){
			m_pLinks[iLink] = 0;
		}	
	}else{
		m_nLinks = 0;
	}	
}


void LinkedNode::clean(){
	delete[] m_pLinks;	
}

LinkedNode * LinkedNode::getNodeOnLink(unsigned long iLink, unsigned long nTimes){
	LinkedNode * pNode = this;
	while(nTimes && pNode && (iLink < pNode->m_nLinks)){

		pNode = *(pNode->m_pLinks + iLink);
		nTimes--;
	}

	if(nTimes == 0){
		return pNode;
	}

	return 0;
}


LinkedNode * LinkedNode::getLastNodeOnLink(unsigned long iLink){
	LinkedNode * pCurrent = this;
	LinkedNode * pNext = 0;		
	bool bError = false;
	if(!pCurrent){
		return 0;
	}
	for( ; ; ){
		//If node doesnt support "iLink" links then error
		//If cycle is detected return error
		if(!(iLink < pCurrent->m_nLinks) || pNext == this){
			bError = true;
			break;
		}

		//Ok the current node supports at least "iLink" pointers
		//so get the "iLink"th Pointer
		pNext = *(pCurrent->m_pLinks + iLink);


		//Check if no more nodes are present		
		if(!pNext){
			break;
		}
		pCurrent = pNext;
	}
	if(!bError){
		return pCurrent;
	}
	return 0;
}

void LinkedNode::setNodeOnLink(unsigned long iLink, LinkedNode * pNode){
	if(iLink < m_nLinks){
		m_pLinks[iLink] = pNode;
	}
} 


LinkedNode * LinkedNode::traverse(NodeTraversalPattern ntp){
	LinkedNode * pRet = this;
	LinkedNode * pNew = this;
	if(ntp.m_nSteps){
		unsigned long iStep = 0;
		NodeTraversalStep * pStep = ntp.m_ntsSteps;
		while(iStep < ntp.m_nSteps){
			pRet = pRet->getNodeOnLink(pStep->nLink, pStep->nSteps);
			pStep++;
			iStep++;
		};
		if(iStep != ntp.m_nSteps){
			pRet = 0;
		}
		
	}

	return pRet;

}



