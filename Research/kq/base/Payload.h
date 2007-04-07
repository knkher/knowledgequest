#ifndef PAYLOAD_H_
#define PAYLOAD_H_

#include "dataTypes.h"
namespace base{
	
	typedef unsigned int PayloadSizeUnit;
	class Payload
	{
	private:
		void * m_pLocation;
		
		PayloadSizeUnit m_uSize;
		
		int deepCopy(void * pLocation, PayloadSizeUnit uSize);
		
	public:	
		Payload();
		Payload(Payload & payload);
		virtual ~Payload();
		void clean();
		void init();
		
		PayloadSizeUnit getSize();
		void * getLocation();	
		//int deepCopy(Payload &pPayload);
		
		
		bool operator==(Payload &pPayload);
		bool isEqualTo(void * pLocation, PayloadSizeUnit uSize);
		
		Payload & operator= (Payload & payload);
		Payload & makeEqualTo(void * pLocation, PayloadSizeUnit uSize);		 
	};
	
}

typedef base::Payload SafePointer;

#endif /*PAYLOAD_H_*/
