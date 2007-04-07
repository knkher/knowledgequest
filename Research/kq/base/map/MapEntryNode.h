#ifndef MAPENTRYNODE_H_
#define MAPENTRYNODE_H_

#include "key.h"
#include "value.h"

namespace base
{

namespace map
{

class MapEntryNode
{
public:	
	Key k;
	Value v;
	MapEntryNode * pNext;
};

}

}

#endif /*MAPENTRYNODE_H_*/
