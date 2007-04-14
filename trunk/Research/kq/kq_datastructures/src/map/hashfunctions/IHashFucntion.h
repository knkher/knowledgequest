#ifndef IHASHFUCNTION_H_
#define IHASHFUCNTION_H_

namespace kq
{

namespace datastructures
{

namespace map
{
	
namespace hashfunctions{

	class IHashFunction{
	public:
		virtual unsigned long getRange() = 0;
		virtual unsigned long hash(const void * pData, unsigned long ulDataSize) = 0;
		virtual ~IHashFunction();
	};

}

}

}

}
#endif /*IHASHFUCNTION_H_*/
