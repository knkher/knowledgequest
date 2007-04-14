#ifndef KQ_DS_SLL_H_
#define KQ_DS_SLL_H_


#include "SafeLinkedListNode.h"

namespace kq{
	namespace datastructures{
		class SafeLinkedList{
			SafeLinkedListNode * m_pStart;
			unsigned long m_ulSize;

			void init();
			void clean();
		public:
			SafeLinkedList();
			~SafeLinkedList();

			SafeLinkedListNode * getLeftmostNode();
			SafeLinkedListNode * getRightmostNode();

			unsigned long getLength();

		};
	};
}

#endif

