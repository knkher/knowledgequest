#ifndef KQ_B_DS_TN
#define KQ_B_DS_TN

#include "DataContainer.h"
#include "LinkedNode.h"

namespace kq{
	namespace base{
		namespace datastructures{
			class TreeNode:/*public DataContainer,*/ protected LinkedNode{
			protected:				
				unsigned long m_nMaxChildren;
				unsigned long m_nChildren;
			public:				
				TreeNode(unsigned long nMaxChildren);
				~TreeNode();

				TreeNode * getParent();
				TreeNode * getFirstChild();
				TreeNode * getNextSibling();

			protected:
			};
		}
	}
}






#endif //KQ_B_DS_TN