#ifndef PAYLOAD_H_
#define PAYLOAD_H_

#include "dataTypes.h"
#include "malloc.h"
#include "memory.h"
#include "stdio.h"

namespace base{
	
	typedef unsigned int PayloadSizeUnit;
	class Payload
	{
	private:
		void * m_pLocation;
		
		PayloadSizeUnit m_uSize;
		
		inline int deepCopy(void * pLocation, PayloadSizeUnit uSize){
			clean();
	
			m_pLocation = malloc(uSize);
			if(!m_pLocation){
				return iFailure;
			}
			m_uSize = uSize;	
			memcpy(m_pLocation, pLocation, m_uSize);	
			return iSuccess;
		}
		
	public:	
		Payload();
		Payload(Payload & payload);
		virtual ~Payload();
		
		inline void clean(){
			if(m_uSize && m_pLocation){
				printf("\nFreeing %u bytes at %p", m_uSize, m_pLocation);
				free(m_pLocation);
			}	
			init();
		}
		
		inline void init(){
			m_pLocation = 0;
			m_uSize = 0;	
		}
		
		inline PayloadSizeUnit getSize(){
			return m_uSize;
		}
		inline void * getLocation(){
			return m_pLocation;	
		}		
				
		bool operator==(Payload & payload){	
			if(this == &payload){
				return true;
			}
			return isEqualTo(payload.m_pLocation, payload.m_uSize);	
		}
		
		inline bool isEqualTo(void * pLocation, PayloadSizeUnit uSize){
			//If not of the same size then definitely not equal
			if(m_uSize != uSize){
				return false;
			}
			//Assume same size below
			
			//Now if same location then surely the same
			if(m_pLocation == pLocation){
				return true;
			}
			
			if(memcmp(m_pLocation, pLocation, m_uSize) == 0){
				return true;
			}
			
			return false;
		}
		
		Payload & operator= (Payload & payload);
		Payload & makeEqualTo(void * pLocation, PayloadSizeUnit uSize);		 
	};
	
}

typedef base::Payload SafePointer;

#endif /*PAYLOAD_H_*/
