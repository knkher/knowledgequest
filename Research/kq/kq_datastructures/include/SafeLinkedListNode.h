#ifndef SAFELINKEDLISTNODE_H_
#define SAFELINKEDLISTNODE_H_

#include "SafePointer.h"

namespace kq
{
namespace datastructures
{

	class SafeLinkedListNode
	{
	private:
		datastructures::SafePointer m_spData;
		
	public:
		SafeLinkedListNode * m_pLeft;
		SafeLinkedListNode * m_pRight;

		SafeLinkedListNode();
		virtual ~SafeLinkedListNode();
		
		void SafeLinkedListNode::init();
		
		void SafeLinkedListNode::clean();
		
		void SafeLinkedListNode::insertAfter(SafeLinkedListNode * pNode);
		
		void SafeLinkedListNode::setData(void * pDataLocation, unsigned long uDataSize);
		void SafeLinkedListNode::setData(const SafePointer & spData);
		
		SafePointer SafeLinkedListNode::getData();

		SafeLinkedListNode * getLeftNode();
		SafeLinkedListNode * getRigthNode();
	};

}
}
#endif /*SAFELINKEDLISTNODE_H_*/
