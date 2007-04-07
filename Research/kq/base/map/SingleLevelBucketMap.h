#ifndef SINGLELEVELBUCKETMAP_H_
#define SINGLELEVELBUCKETMAP_H_

#include "IMap.h"

class SingleLevelBucketMap : public base::map::IMap
{
public:
	SingleLevelBucketMap();
	virtual ~SingleLevelBucketMap();
};

#endif /*SINGLELEVELBUCKETMAP_H_*/
