//////////////////////////////////////////////////////////  <summary> ////////////////////////////////////////////////////////////////////
/// Name: Abhishek Dilipkumar Nale
/// Date: 30/ 06 / 2024
/// Today's Task:		
///						intialize winsock library
///						create the socket
///						connect to server
///						send 
///						close the socket
/// 
///	Abbrevation:	Init -> Intialization
//////////////////////////////////////////////////////////// </summary> ///////////////////////////////////////////////////////////////////


#include <iostream>
#include <WinSock2.h>
#include <ws2tcpip.h>

#include <thread>
#include <string>

using namespace std;

#pragma comment(lib, "ws2_32.lib")

void Sent(SOCKET s);
void Recv(SOCKET s);

bool Init()
{
	WSADATA data;
	return WSAStartup(MAKEWORD(2, 2), &data) == 0;
}

int main()
{
	if (!Init())
	{
		cout << "Winsock initailization failed " << endl;
		return 1;
	}

	SOCKET s;
	s = socket(AF_INET, SOCK_STREAM, 0);
	if (s == INVALID_SOCKET)
	{
		cout << "Invalid socket created" << endl;
		return 1;
	}

	// int port = 12345;												//
	int port;															//
	cout << "Enter port number to connect: ";							//
	cin >> port;														//		Address structure
	string serveraddress = "127.0.0.1";									//
	sockaddr_in serveraddr;												//
	serveraddr.sin_family = AF_INET;									//   
	serveraddr.sin_port = htons(port);									//
	inet_pton(AF_INET, serveraddress.c_str(), &(serveraddr.sin_addr));	//

	if (connect(s, reinterpret_cast<sockaddr*>(&serveraddr), sizeof(serveraddr)) == SOCKET_ERROR)		// Validating Connection
	{
		cout << "not able to connect to server" << endl;
		closesocket(s);
		WSACleanup();
		return 1;
	}

	cout << "client program started" << endl;

	thread sender_T(Sent, s);													// thread
	thread receiver_T(Recv, s);													// thread	

	sender_T.join();
	receiver_T.join();


	string message = "Namaskar..!";
	const char* m_c_str = message.c_str();
	if (!m_c_str)
	{
		cout << "Failed to convert" << endl;
		return 1;
	}

	int bytesend;
	bytesend = send(s, message.c_str(), message.length(), 0);					// Send message

	if (bytesend == SOCKET_ERROR)
	{
		cout << "send failed" << endl;
	}

	return 0;
}
