#include ".\socket.h"
//#include "memory.h"
#include "Winsock2.h"

/*
accept Permits an incoming connection attempt on a socket. 
AcceptEx Accepts a new connection, returns the local and remote address, and receives the first block of data sent by the client application. 
bind Associates a local address with a socket. 
closesocket Closes an existing socket. 
connect Establishes a connection to a specified socket. 
ConnectEx Establishes a connection to a specified socket, and optionally sends data once the connection is established. 
DisconnectEx Closes a connection on a socket, and allows the socket handle to be reused. 
freeaddrinfo Frees address information that the getaddrinfo function dynamically allocates. 
gai_strerror Assists in printing error messages based on the EAI_* errors returned by the getaddrinfo function. 
GetAcceptExSockaddrs Parses the data obtained from a call to the AcceptEx function. 
GetAddressByName Queries a name space, or a set of default name spaces, to retrieve network address information for a specified network service. This process is known as service name resolution. 
getaddrinfo Provides protocol-independent translation from host name to address. 
gethostbyaddr Retrieves the host information corresponding to a network address. 
gethostbyname Retrieves host information corresponding to a host name from a host database. 
gethostname Retrieves the standard host name for the local computer. 
getnameinfo Provides name resolution from an address to the host name. 
getpeername Retrieves the name of the peer to which a socket is connected. 
getprotobyname Retrieves the protocol information corresponding to a protocol name. 
getprotobynumber Retrieves protocol information corresponding to a protocol number. 
getservbyname Retrieves service information corresponding to a service name and protocol. 
getservbyport Retrieves service information corresponding to a port and protocol. 
getsockname Retrieves the local name for a socket. 
getsockopt Retrieves a socket option. 
htonl Converts a u_long from host to TCP/IP network byte order (which is big-endian). 
htons Converts a u_short from host to TCP/IP network byte order (which is big-endian). 
inet_addr Converts a string containing an (Ipv4) Internet Protocol dotted address into a proper address for the IN_ADDR structure. 
inet_ntoa Converts an (Ipv4) Internet network address into a string in Internet standard dotted format. 
ioctlsocket Controls the I/O mode of a socket. 
listen Places a socket a state where it is listening for an incoming connection. 
ntohl Converts a u_long from TCP/IP network order to host byte order (which is little-endian on Intel processors). 
ntohs Converts a u_short from TCP/IP network byte order to host byte order (which is little-endian on Intel processors). 
recv Receives data from a connected or bound socket. 
recvfrom Receives a datagram and stores the source address. 
select Determines the status of one or more sockets, waiting if necessary, to perform synchronous I/O. 
send Sends data on a connected socket. 
sendto Sends data to a specific destination. 
setsockopt Sets a socket option. 
shutdown Disables sends or receives on a socket. 
socket Creates a socket that is bound to a specific service provider. 
TransmitFile Transmits file data over a connected socket handle. 
TransmitPackets 
*/



using namespace Utilities::Networking;


WindowsSocketWrapper::WindowsSocketWrapper(){
	_clean();
}
WindowsSocketWrapper::~WindowsSocketWrapper(){
}


bool WindowsSocketWrapper::create(int af, int type, int protocol){

	if(m_hSocket){
		return false;
	}

	m_hSocket = socket(af, type, protocol);

	if(m_hSocket == INVALID_SOCKET){
		return false;
	}

	return true;
}
bool WindowsSocketWrapper::destroy(){
	int iError = closesocket(m_hSocket);
	if(iError == SOCKET_ERROR){
		return false;
	}
	_clean();
	return true;
}

void WindowsSocketWrapper::_clean(){
	m_hSocket = 0;
}