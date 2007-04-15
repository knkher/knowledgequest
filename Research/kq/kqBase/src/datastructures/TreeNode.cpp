#include "TreeNode.h"

using namespace kq::base::datastructures;

TreeNode::TreeNode(unsigned long nMaxChildren)
//One more link for parent
//One more for the first child, other for siblings
:LinkedNode(nMaxChildren + 1 + 1)
{

}

TreeNode::~TreeNode(){

}
