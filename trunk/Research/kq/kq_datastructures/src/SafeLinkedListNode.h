#ifndef SafeLinkedListNODE_H_
#define SafeLinkedListNODE_H_

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
		SafeLinkedListNode * getNodeAtRelativePosition(const int iRelativePosition);

		SafeLinkedListNode * operator +(int iRelativePosition);
		SafeLinkedListNode * operator -(int iRelativePosition);
	};

}
}
#endif /*SafeLinkedListNODE_H_*/
