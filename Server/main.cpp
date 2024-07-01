//////////////////////////////////////////////////////////////////// <summary> //////////////////////////////////////////////////////////////
/// Name: Abhishek Dilipkumar Nale
/// Date: 30/ 06 / 2024
/// Today's Task:		
///						intialize winsock library
///						create the socket
///						get ip and port
///						bind the ip / port with the socket
///						listen on the socket
///						accept
///						recv and send
///						close the socket
/// 
///	Abbrevation:	Init -> Intialization
///					
//////////////////////////////////////////////////////////////////// </summary> ///////////////////////////////////////////////////////////

#include <iostream>
#include <WinSock2.h>
#include <ws2tcpip.h>
#include <tchar.h>
#include <thread>
#include <vector>

using namespace std;
																			// boiler plate code
bool Init()																	// Code Intialized
{
	WSADATA data;		
	return WSAStartup(MAKEWORD(2, 2), &data) == 0;
}

void IWC(SOCKET clientSocket, vector<SOCKET>& clients);						// IWC Defined

int main()
{
	if (!Init())
	{
		cout << "Winsock initailization failed " << endl;
		return 1;
	}

	cout << "Server here" << endl;

	SOCKET listenSocket = socket(AF_INET, SOCK_STREAM, 0);			// socket created

	if (listenSocket == INVALID_SOCKET)
	{
		cout << "Socket creation failed" << endl;
		return 1;
	}

	int port = 12345;
	sockaddr_in serveraddr;						//
	serveraddr.sin_family = AF_INET;			//   Address structure
	serveraddr.sin_port = htons(port);			//

	if (InetPton(AF_INET, _T("0.0.0.0"), &serveraddr.sin_addr) != 1)	//
	{																	//
		cout << "setting address sturcture failed" << endl;				//		Convert the ipaddress (0.0.0.0) put it inside the sin_family
		closesocket(listenSocket);										//		in binarry format
		WSACleanup();													//
		return 1;														//
	}

	if (bind(listenSocket, reinterpret_cast<sockaddr*>(&serveraddr), sizeof(serveraddr)) == SOCKET_ERROR) // Bind
	{
		cout << "bind failed" << endl;
		closesocket(listenSocket);
		WSACleanup();
		return 1;
	}

	if (listen(listenSocket, SOMAXCONN) == SOCKET_ERROR)				// Listen
	{
		cout << "Listen failed" << endl;
		closesocket(listenSocket);
		WSACleanup();

		return 1;
	}
	cout << "server has started listening on port: " << port << endl;
	
	vector <SOCKET> clients;
	
	while (1)
	{
		SOCKET clientSocket = accept(listenSocket, nullptr, nullptr);			//Accept
		if (clientSocket == INVALID_SOCKET)
		{
			cout << "Invalid client socket " << endl;

		}
		
		clients.push_back(clientSocket);

		thread t (IWC, clientSocket, ref(clients) );

		t.detach();
	}

	closesocket(listenSocket);
	WSACleanup();
	
		return 0;

}
