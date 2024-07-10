# Client-Server Chat Application

<hr>
<h3>Chat Messenger using Socket Programing, Client-Server Architecture in C++</h3> <br>

<ol>
	<li><b>Introduction</b>
<br>
	<ol>
		<li><b>Purpose: </b><br>&emsp;The purpose of this documentation is to describe the design, implementation, and functionality of a client-server chat application developed using C++ and Winsock.</li>
		<br>
		<li><b>Scope: </b><br>
		&emsp; This application allows multiple clients to connect to a central server over a network. Clients can send and receive messages through the server, enabling real-time communication between users.</li>
<br>
<br>
	</ol>
<li><b>Architecture Overview</b></li>
	<br>
	<ol>
		<li><b>System Architecture</b></li>
		The application follows a client-server architecture:
		<br>
		<ul>
		<li>&emsp;Server: Acts as a central hub for all client communications. Manages client connections, relays messages between clients, and ensures data integrity.</li>
		<br>
		<li>&emsp;Clients: Connect to the server using TCP/IP sockets. Send messages to the server, which then distributes these messages to other connected clients.</li>
		</ul>
  <br>
		<li><b>Technologies Used</b></li>
		<ul>
			<li><b>Programming Language:</b> C++.</li>
			<li><b>Network Library:</b> Winsock (Windows Sockets).</li>   
			<li><b>Threading:</b> Utilized for concurrent message handling in clients and server.</li>
		</ul>
	</ol>
<br>
<br>
	<li>Functional Requirements</li>
	<br>
	<ol>
		<li><b>Server Features</b></li>
	<ul>
<li>&emsp;Accept Connections: Listens for incoming client connections.</li>
<li>&emsp;Message Relay: Receives messages from clients and broadcasts them to all other connected clients.</li>
<li>&emsp;Error Handling: Manages socket errors and client disconnections gracefully.</li>
	</ul>
		<br>
<li><b>Client Features</b></li>
		<ul>
<li>&emsp;Connect to Server: Establishes a socket connection with the server.</li>
<li>&emsp;Send Message: Allows users to type messages and send them to the server.</li>
<li>&emsp;Receive Message: Displays incoming messages from other clients via the server.</li>
<li>&emsp;Disconnect: Terminates the client's connection with the server.</li>
		</ul>
	</ol>
 <br>
	<li><b>Design Details</b></li>
<ol>
	<br>
<li><b>Server Design</b></li>
	<ul>
<li>&emsp;Initialization: Initializes Winsock and creates a listening socket.</li>
<li>&emsp;Connection Handling: Accepts incoming client connections and assigns dedicated threads for each client.</li>
<li>&emsp;Message Handling: Receives messages from clients and broadcasts them to all other clients.</li>
	</ul>
 <br>
<li><b>Client Design</b></li>
	<ul>
<li>&emsp;Initialization: Initializes Winsock and creates a socket for communication with the server.</li>
<li>&emsp;User Interface: Simple console-based interface for sending and displaying messages.</li>
<li>&emsp;Thread Management: Uses separate threads for sending and receiving messages to ensure responsiveness.</li>
	</ul>
 <br>
</ol>
 	<li><b>Implementation Details</b></li>
		<br>
		<ol>
<li><b>Server Implementation</b></li>
			<ul>
<li>&emsp;Socket Creation: Creates a TCP socket for listening to incoming connections.</li>
<li>&emsp;Connection Acceptance: Accepts client connections and spawns threads to handle each client independently.</li>
<li>&emsp;Message Handling: Uses synchronization techniques to manage shared resources and ensure thread safety.</li>
			</ul>
			<br>
<li><b>Client Implementation</b></li>
			<ul>
<li>&emsp;Socket Connection: Connects to the server using its IP address and port number.</li>
<li>&emsp;Message Sending: Allows users to type messages and send them to the server.</li>
<li>&emsp;Message Receiving: Displays messages received from other clients via the server.</li>
			</ul>
		</ol>
<br>
<li><b>Usage Instructions</b></li>
<br>
<ol>
<li><b>Server Setup</b></li>
	<ul><li>&emsp;Compile and run the server application on a designated host machine.</li>
<li>&emsp;Note down the server's IP address and port number for client configuration.</li>
<br>
	</ul>
<li><b>Client Setup</b></li>
	<ul>
<li>&emsp;Compile and run the client application on multiple machines.</li>
<li>&emsp;Enter the server's IP address and port number to connect each client to the server.</li>
	</ul>
	<br>
<li><b>Chatting</b></li>
	<ul>
<li>&emsp;Type messages in the client console and press enter to send them to the server.</li>
<li>&emsp;Received messages from other clients will appear in the client console.</li>
	</ul>
</ol>
	</ol>

