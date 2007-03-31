#pragma once

#include "Winsock2.h"

namespace Utilities{

	namespace Networking{		

		class WinsockInit{
		private:

			static WinsockInit * g_pTheOne;
			static WinsockInit * GetInstance();

		public:
			static bool Initialize(WORD wRequiredVersion);
			static bool GetWinsockInitData(WSAData * pDest);


		private:
			bool m_bInit;		
			WinsockInit();
			bool InitializeWinsock(WORD wRequiredVersion);
			void InitilizeMembers();

			WORD m_wVersion;
			WSAData m_oWinsockInitData;
			
		};



		class WindowsSocketWrapper{
		private:
			SOCKET m_hSocket;

			void _clean();
			

		public:
			SOCKET GetSafeHandle();	

			WindowsSocketWrapper();
			~WindowsSocketWrapper();

			bool create(int af, int type, int protocol);
			bool destroy();

		};


		class IPv4WindowsSocket
		{
		
		public:
			IPv4WindowsSocket(void);
			~IPv4WindowsSocket(void);
		};
		
	};
};


