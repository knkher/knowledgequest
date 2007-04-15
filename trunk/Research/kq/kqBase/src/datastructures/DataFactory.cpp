#include "DataFactory.h"

#include "PseudoData.h"


using namespace kq::base::datastructures;


DataFactory * DataFactory::s_pTheOneFactory = 0;
DataFactory::DataFactory(void)
{
}

DataFactory::~DataFactory(void)
{
}


DataFactory * DataFactory::getInstance(){
	if(s_pTheOneFactory){
		return s_pTheOneFactory;
	}
	s_pTheOneFactory = new DataFactory();
	return s_pTheOneFactory;
	
}
void DataFactory::destroyFactory(){
	delete s_pTheOneFactory;
	s_pTheOneFactory = 0;
}

void DataFactory::destroyData(IData * pData){
	delete pData;
}

IData * DataFactory::createPseudoData(void * pDataLocation, unsigned long uDataSize){
	PseudoData * pData = new PseudoData();
	if(!pData){
		return 0;
	}
	pData->pointTo(pDataLocation, uDataSize);
	IData * pRet = dynamic_cast<IData *>(pData);
	if(!pRet){
		_asm int 3;
		pRet = pData;
	}
	return pRet;
}