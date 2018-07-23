#pragma once
#include "configuration.h"

#if defined WIN32_I2N
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#pragma comment(lib, "Ws2_32.lib")
#endif
class GeneralUtility
{
public:
	GeneralUtility(void);
	~GeneralUtility(void);

	class socketcommunication{
	public :
		 socketcommunication();
		virtual ~socketcommunication();
		int opensocketConnection();
		int closesocketConnection();
		int GetDataFromConnection();
		int SendDataToConnection();
		int ListenOnPort();
		
	private:
		// Varibles:
		#if defined WIN32_I2N
		LPWSADATA lpwsaData;
		struct addrinfo *struaddrinfo;
		SOCKET ListenSocket;
		SOCKET ConnectSocket;
#endif
		// Members:
		int InitilizeSocket(){
#if defined WIN32_I2N
			return  WSAStartup(MAKEWORD(2,2),lpwsaData);
#else


			
#endif

		}
		int Socket(){
			#if defined WIN32_I2N
			return socket(struaddrinfo->ai_family,struaddrinfo->ai_socktype,struaddrinfo->ai_protocol);
			
#endif
		}
		int Bind(){
			#if defined WIN32_I2N
			return bind( ListenSocket, struaddrinfo->ai_addr, (int)struaddrinfo->ai_addrlen);
			
#endif
		}
		int Listen(){
			#if defined WIN32_I2N
			return listen( ListenSocket, SOMAXCONN );
			
#endif
		}
		int Accept(){
			#if defined WIN32_I2N
			return accept(ListenSocket, NULL, NULL);
			
#endif
		}
		int Connect(){
			#if defined WIN32_I2N
			
			return connect(ConnectSocket,struaddrinfo->ai_addr,(int)struaddrinfo->ai_addrlen);
#endif
		}
		int Send(){
			#if defined WIN32_I2N
			
			
#endif
		}
		int Receive(){
			#if defined WIN32_I2N
			
			
#endif
		}
		int Close(){
			#if defined WIN32_I2N
			return closesocket(ListenSocket);
			
			
#endif
		}
		int deinilizeSocket(){
			#if defined WIN32_I2N
			return WSACleanup();
			
			
#endif
		}
		void SetDefaultValue(){
			#if defined WIN32_I2N
			struaddrinfo->ai_family = AF_INET;
			struaddrinfo->ai_socktype = SOCK_STREAM;
			struaddrinfo->ai_protocol = IPPROTO_TCP;
			struaddrinfo->ai_flags = AI_PASSIVE;
#endif
		}

	};
	class Logging{
	public :
		Logging();
		~Logging();

	};
};

