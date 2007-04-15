#ifndef SAFEPOINTER_H_
#define SAFEPOINTER_H_

#include "dataTypes.h"
#include "Pointer.h"

namespace kq{
namespace datastructures{
	
	class SafePointer:protected Pointer
	{
	private:
		
		int _replaceWith(const void * pLocation, unsigned long uSize);
		
	public:	
		SafePointer();
		SafePointer(SafePointer & payload);
		virtual ~SafePointer();
		void clean();
		void init();
		
		unsigned long getSize() const;
		void * getUnsafeCopy() const;
		void * revealLocation() const;
				
		void makeEqualTo(const void * pLocation, unsigned long uSize);
		void SafePointer::makeEqualTo(const SafePointer & spSource);
		
		bool isEqualTo(const void * pLocation, unsigned long uSize) const;
		bool isEqualTo(const SafePointer & spOther) const;


		void SafePointer::operator =(const SafePointer & spSource);
		void SafePointer::operator ==(const SafePointer & spOther) const;
		
	};
	
}
}

#endif /*PAYLOAD_H_*/
