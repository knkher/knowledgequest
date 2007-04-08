#ifndef SAFELINKEDLISTNODE_H_
#define SAFELINKEDLISTNODE_H_

#include "SafePointer.h"

namespace datastructures
{

	class SafeLinkedListNode
	{
	private:
		datastructures::SafePointer m_spData;
		datastructures::SafePointer m_spNextNode;
		
		void init();
		void clean();
		
		
	public:
		SafeLinkedListNode();
		virtual ~SafeLinkedListNode();
	};

}

#endif /*SAFELINKEDLISTNODE_H_*/
