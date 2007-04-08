#ifndef MODHASHER_H_
#define MODHASHER_H_

#include "IHashFucntion.h"

namespace kq
{

namespace datastructures
{

namespace map
{

namespace hashfunctions
{

class ModHash:public IHashFunction{
	private:
		unsigned long m_ulRange;
	public:
		ModHash(unsigned long ulRange = 256);
		~ModHash();
		inline virtual unsigned long getRange();
		inline virtual unsigned long hash(const void * pData, unsigned long ulDataSize);

};

}

}

}

}

#endif /*MODHASHER_H_*/
