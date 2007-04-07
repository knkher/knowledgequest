#ifndef PAYLOAD_H_
#define PAYLOAD_H_

#include "dataTypes.h"
namespace base{
	class Payload
	{
	private:
		void * m_pLocation;
		
		unsigned int m_uSize;
		
		
		int _deepCopy(Payload * pPayload);
		
		
	public:	
		Payload(void * pLocation = 0, unsigned int uSize = 0);
		Payload(Payload & payload);
		virtual ~Payload();
		void clean();
		void init();
		
		unsigned int getSize();
		void * getLocation();	
		int deepCopy(Payload &pPayload);
		bool operator==(Payload &pPayload);
		Payload & operator= (Payload & payload);		 
	};
	
}

typedef base::Payload SafePointer;


#endif /*PAYLOAD_H_*/
