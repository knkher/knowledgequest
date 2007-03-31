#include ".\socket.h"
#include "memory.h"
#include "Winsock2.h"




using namespace Utilities::Networking;


////////////////////////////////////////
////////////////////////////////////////
/////////////Static ////////////////////
////////////////////////////////////////
////////////////////////////////////////



WinsockInit * WinsockInit::g_pTheOne = 0;

WinsockInit * WinsockInit::GetInstance(){
	if(!g_pTheOne){		
		g_pTheOne = new WinsockInit();
	}
	return g_pTheOne;
}


bool WinsockInit::GetWinsockInitData(WSAData * pDest){
	if(!pDest){
		return false;
	}

	WinsockInit * pObj =  GetInstance();

	if(!pObj->m_bInit){
		return false;
	}
	
	void * pRet = memcpy(pDest, &(pObj->m_oWinsockInitData), sizeof(pObj->m_oWinsockInitData));

	if(pRet == pDest){
		return true;
	}
	return false;
	
}


bool WinsockInit::Initialize(WORD wRequiredVersion){

	WinsockInit * pObj =  GetInstance();

	if(pObj->m_bInit){
		return true;
	}
	return pObj->InitializeWinsock(wRequiredVersion);

}




////////////////////////////////////////
////////////////////////////////////////
////////////Members/////////////////////
////////////////////////////////////////
////////////////////////////////////////



WinsockInit::WinsockInit(){

	InitilizeMembers();
	
}

bool WinsockInit::InitializeWinsock(WORD wRequiredVersion){

	int iError = WSAStartup(wRequiredVersion, &m_oWinsockInitData);
	if(iError){
		InitilizeMembers();
		return false;
	}

	m_bInit = true;
	m_wVersion = wRequiredVersion;

	return true;	
}

void WinsockInit::InitilizeMembers(){

	m_bInit = false;
	m_wVersion = (WORD)-1;		
	memset(&m_oWinsockInitData, 0, sizeof(m_oWinsockInitData));

}

