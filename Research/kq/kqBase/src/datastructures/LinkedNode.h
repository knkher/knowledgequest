#ifndef KQ_B_DS_LINKEDNODE
#define KQ_B_DS_LINKEDNODE

//#include "IData.h"
#include "DataContainer.h"
#include "NodeTraversalPattern.h"

namespace kq
{
namespace base
{
namespace datastructures
{	
	class LinkedNode/*:public DataContainer*/
	{	
	public:		
	private:
		void init();		
		void clean();

	protected:
		//The Array of LinkedNode pointers which are pointed to by this node
		unsigned long m_nLinks;
		LinkedNode ** m_pLinks;		
	public:
		//Number of initial links == nLinks
		//During allocation links are allocated in blocks of nLinksPerAllocationBlock
		LinkedNode(unsigned long nLinks);

		//Destructor
		virtual ~LinkedNode();		

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