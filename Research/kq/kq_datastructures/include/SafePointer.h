#ifndef PAYLOAD_H_
#define PAYLOAD_H_

#include "dataTypes.h"

namespace kq{
namespace datastructures{
	
	class SafePointer
	{
	private:
		void * m_pLocation;		
		unsigned long m_uSize;

		int _replaceWith(const void * pLocation, unsigned long uSize);
		
	public:	
		SafePointer();
		SafePointer(SafePointer & payload);
		virtual ~SafePointer();
		void clean();
		void init();
		
		unsigned long getSize();
		void * getUnsafeCopy();
		const void * revealLocation();
				
		void makeEqualTo(const void * pLocation, unsigned long uSize);
		void SafePointer::makeEqualTo(const SafePointer & spSource);
		
		bool isEqualTo(const void * pLocation, unsigned long uSize);
		bool isEqualTo(const SafePointer & spOther);


		void SafePointer::operator =(const SafePointer & spSource);
		void SafePointer::operator ==(const SafePointer & spOther);
		
	};
	
}
}

#endif /*PAYLOAD_H_*/
