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
		virtual unsigned long getRange();
		virtual unsigned long hash(const void * pData, unsigned long ulDataSize);

};

}

}

}

}

#endif /*MODHASHER_H_*/
