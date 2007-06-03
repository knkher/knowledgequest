#ifndef KQ_B_DS_DYNAMICLINKEDNODE
#define KQ_B_DS_DYNAMICLINKEDNODE


#include "LinkedNode.h"

#include "DataContainer.h"

namespace kq
{
namespace base
{
namespace datastructures
{	
	class DynamicLinkedNode:protected LinkedNode
	{		
	private:
		//Number of Unused links
		unsigned long m_nFreeLinks;		

		//Flanks will contain the surrounding DLNs
		LinkedNode m_Flanks;		
		static const unsigned long s_nFlanks = 2;
		enum FlankLocation{
			eFlankLocation_Left,
			eFlankLocation_Right,
		};
		
	private:		
		void setFlank(FlankLocation fl, DynamicLinkedNode * pFlank);
		DynamicLinkedNode * getFlank(FlankLocation fl);
	public:
		DynamicLinkedNode(unsigned long nLinksPerAllocationBlock);


		void init();
		void clean();




		///////////////////////////////////////
		/////////LinkedNode////////////////////
		//Get the number of links
		unsigned long getLinkCount();
		
		

		LinkedNode * getNodeOnLink(unsigned long iLink, unsigned long nTimes);
		LinkedNode * getLastNodeOnLink(unsigned long iLink);
		void setNodeOnLink(unsigned long iLink, LinkedNode * pNode);
		LinkedNode * traverse(NodeTraversalPattern ntp);

		
		
	};

}//DS
}//BASE
}//KQ













#endif