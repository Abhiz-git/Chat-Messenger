# Chat-Messenger
Chat Messenger using Socket Programing in C++

Client-Server Chat Application

1.	Introduction

1.1 Purpose
The purpose of this documentation is to describe the design, implementation, and functionality of a client-server chat application developed using C++ and Winsock.

1.2 Scope
This application allows multiple clients to connect to a central server over a network. Clients can send and receive messages through the server, enabling real-time communication between users.

1.	Architecture Overview

2.1  System Architecture
	The application follows a client-server architecture:
•	Server: Acts as a central hub for all client communications. Manages client connections, relays messages between clients, and ensures data integrity.
•	Clients: Connect to the server using TCP/IP sockets. Send messages to the server, which then distributes these messages to other connected clients.

2.2 Technologies Used
•	Programming Language: C++
•	Network Library: Winsock (Windows Sockets)
•	Threading: Utilized for concurrent message handling in clients and server.

3. Functional Requirements
3.1 Server Features
•	Accept Connections: Listens for incoming client connections.
•	Message Relay: Receives messages from clients and broadcasts them to all other connected clients.
•	Error Handling: Manages socket errors and client disconnections gracefully.

3.2 Client Features
•	Connect to Server: Establishes a socket connection with the server.
•	Send Message: Allows users to type messages and send them to the server.
•	Receive Message: Displays incoming messages from other clients via the server.
•	Disconnect: Terminates the client's connection with the server.

4. Design Details

4.1 Server Design
•	Initialization: Initializes Winsock and creates a listening socket.
•	Connection Handling: Accepts incoming client connections and assigns dedicated threads for each client.
•	Message Handling: Receives messages from clients and broadcasts them to all other clients.

4.2 Client Design
•	Initialization: Initializes Winsock and creates a socket for communication with the server.
•	User Interface: Simple console-based interface for sending and displaying messages.
•	Thread Management: Uses separate threads for sending and receiving messages to ensure responsiveness.

 5. Implementation Details
5.1 Server Implementation
•	Socket Creation: Creates a TCP socket for listening to incoming connections.
•	Connection Acceptance: Accepts client connections and spawns threads to handle each client independently.
•	Message Handling: Uses synchronization techniques to manage shared resources and ensure thread safety.
5.2 Client Implementation
•	Socket Connection: Connects to the server using its IP address and port number.
•	Message Sending: Allows users to type messages and send them to the server.
•	Message Receiving: Displays messages received from other clients via the server.

6. Usage Instructions

6.1 Server Setup
•	Compile and run the server application on a designated host machine.
•	Note down the server's IP address and port number for client configuration.

6.2 Client Setup
•	Compile and run the client application on multiple machines.
•	Enter the server's IP address and port number to connect each client to the server.

6.3 Chatting
•	Type messages in the client console and press enter to send them to the server.
•	Received messages from other clients will appear in the client console.
