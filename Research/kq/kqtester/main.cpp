#include "..\bin\kqBase.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"





#ifdef _VS

#include <crtdbg.h>


class LeakDetector{
	static bool s_bFirst;
public:
	LeakDetector(){
		if(!s_bFirst){
			_RPT0(_CRT_WARN,"\nLeakDetector::LeakDetector()::Monitoring Started\n");
			s_bFirst = true;
		}
	}
	void dump(){
		_RPT0(_CRT_WARN,"LeakDetector::LeakDetector()::Dumping Leaks if any\n");
		_CrtDumpMemoryLeaks();	
		
	}
	~LeakDetector(){
		if(s_bFirst){			
			dump();
			_RPT0(_CRT_WARN,"LeakDetector::LeakDetector()::Monitoring Ended\n");
			printf("\n\nCheck Debug Console For Memory Leaks!!\n");			
			_getch();
		}
	}
};
bool LeakDetector::s_bFirst = false;
LeakDetector l;

#endif



using namespace kq;
using namespace kq::base::datastructures;




int main(int /*argc*/, char /***argv*/){	


	/////////////////////////////////
	/////////IPseudoData/////////////
	/////////////////////////////////
	{
		char a[] = "testing!!!";
		char b[] = "abcdefg???";
		IData * pData = DataFactory::getInstance()->createPseudoData(a, sizeof(a));
		IData * pData2 = DataFactory::getInstance()->createPseudoData(b, sizeof(b));
		
		pData->transfer(pData2,sizeof(a),false);

		DataFactory::getInstance()->destroyData(pData);
		DataFactory::getInstance()->destroyData(pData2);
		DataFactory::destroyFactory();		
	}

	////////////////////////////////
	///////////Linked List Node/////
	////////////////////////////////
	{
		const unsigned long nLinksPerNode = 1000;
		const unsigned long nCircles = 1000;
		bool bPassTillNow = true;

		LinkedNode l(nLinksPerNode);
		//Make it circular on all dimesions
		{
			unsigned long iLink;
			for(iLink = 0; iLink < nLinksPerNode && bPassTillNow; iLink++){				
				l.setNodeOnLink(iLink, &l);
				LinkedNode * pNode;

				pNode = l.getNodeOnLink(iLink,nCircles);
				bPassTillNow = bPassTillNow && (pNode == &l);


				pNode = l.getLastNodeOnLink(iLink);
				bPassTillNow = bPassTillNow && (pNode == 0);
			}
			
		}
		if(bPassTillNow){
			printf("\nLinkedNode Test Passed");
		}else{
			printf("\nLinkedNode Test Failed");
		}				
	}

	
}
