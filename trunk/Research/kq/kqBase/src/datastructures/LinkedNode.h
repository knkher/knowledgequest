#ifndef KQ_B_DS_LINKEDNODE
#define KQ_B_DS_LINKEDNODE

#include "IData.h"

namespace kq
{
namespace base
{
namespace datastructures
{	
	class LinkedNode
	{
	private:
		void init();		
		void clean();
		unsigned long m_nLinks;
		LinkedNode ** m_pLinks;			
	public:		
		LinkedNode(unsigned long nLinks);
		virtual ~LinkedNode();		

		unsigned long getLinkCount();

		LinkedNode * getNodeOnLink(unsigned long iLink, unsigned long iOffset);
		LinkedNode * getLastNodeOnLink(unsigned long iLink);
		void setNodeOnLink(unsigned long iLink, LinkedNode * pNode);		


	};

}//DS
}//BASE
}//KQ













#endif