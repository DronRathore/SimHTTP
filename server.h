HTTP/1.1 200 OK
Content-Type: text/html
Connection: Keep-Alive


<html>
/*
	The Server Class
*/
# this is a comment
class Server{
private:
	int port,Socket_Size;
	SOCKET Socket;
	SOCKADDR_IN Server_Socket;
	WSADATA WsaData;
	SOCKET Client;
	int RequestCounter;
public:
	Server(int port=6666){
		this->port=0;
		this->RequestCounter=0;
		try{
			if(port<=10||WSAStartup(MAKEWORD(2,2),&this->WsaData)!=0)
				throw *(new Error<Text>(port<=10?INVALID_PORT_TO_BIND:WSOCK_VER_NOT_FOUND,true));
			else
				this->port=port;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			returnError(-12);
		}
		 
	}		
private:
	int _init(){
		try{
			this->Socket=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
				if(this->Socket==-1)
					throw *(new Error<Text>(SOCKET_CREATION_FAILED,true));
				else
					this->Server_Socket.sin_port=htons(this->port);
				this->Server_Socket.sin_family=AF_INET;
				this->Server_Socket.sin_addr.s_addr=INADDR_ANY;
				return 1;
			}catch(Error<Text> e){
				cout<<e.getDescription()<<endl;
				return -11;
			}
	}
public:
	int returnError(int error){return error;}
	int start(int port=6666){
		this->port=port;
		if(this->_init()!=1){
			return -11;
		}
		try{
			this->Socket_Size=sizeof(this->Server_Socket);
				if(bind(Socket,(SOCKADDR *)&this->Server_Socket,sizeof(this->Server_Socket))==SOCKET_ERROR)
					throw *(new Error<Text>(BIND_FAILURE,true));
				else if(listen(Socket,25)==SOCKET_ERROR)
						throw *(new Error<Text>(LISTEN_FAILURE,true));
				else
					return 1;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return -11;
		}
	}
	SOCKET hear(){
		try{
			if(Client=accept(this->Socket,(SOCKADDR *)&this->Server_Socket,&this->Socket_Size)==SOCKET_ERROR){
				throw *(new Error<Text>(ACCEPT_ERROR,true));
			}else{
				this->RequestCounter++;
				return this->Client;
			}
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return false;
		}
	}
	int getCounter(){return this->RequestCounter;}
	void close(){
		WSACleanup();
		closesocket(this->Socket);
	}
};
</html>
<html>
/*
	The Server Class
*/
# this is a comment
class Server{
private:
	int port,Socket_Size;
	SOCKET Socket;
	SOCKADDR_IN Server_Socket;
	WSADATA WsaData;
	SOCKET Client;
	int RequestCounter;
public:
	Server(int port=6666){
		this->port=0;
		this->RequestCounter=0;
		try{
			if(port<=10||WSAStartup(MAKEWORD(2,2),&this->WsaData)!=0)
				throw *(new Error<Text>(port<=10?INVALID_PORT_TO_BIND:WSOCK_VER_NOT_FOUND,true));
			else
				this->port=port;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			returnError(-12);
		}
		 
	}		
private:
	int _init(){
		try{
			this->Socket=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
				if(this->Socket==-1)
					throw *(new Error<Text>(SOCKET_CREATION_FAILED,true));
				else
					this->Server_Socket.sin_port=htons(this->port);
				this->Server_Socket.sin_family=AF_INET;
				this->Server_Socket.sin_addr.s_addr=INADDR_ANY;
				return 1;
			}catch(Error<Text> e){
				cout<<e.getDescription()<<endl;
				return -11;
			}
	}
public:
	int returnError(int error){return error;}
	int start(int port=6666){
		this->port=port;
		if(this->_init()!=1){
			return -11;
		}
		try{
			this->Socket_Size=sizeof(this->Server_Socket);
				if(bind(Socket,(SOCKADDR *)&this->Server_Socket,sizeof(this->Server_Socket))==SOCKET_ERROR)
					throw *(new Error<Text>(BIND_FAILURE,true));
				else if(listen(Socket,25)==SOCKET_ERROR)
						throw *(new Error<Text>(LISTEN_FAILURE,true));
				else
					return 1;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return -11;
		}
	}
	SOCKET hear(){
		try{
			if(Client=accept(this->Socket,(SOCKADDR *)&this->Server_Socket,&this->Socket_Size)==SOCKET_ERROR){
				throw *(new Error<Text>(ACCEPT_ERROR,true));
			}else{
				this->RequestCounter++;
				return this->Client;
			}
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return false;
		}
	}
	int getCounter(){return this->RequestCounter;}
	void close(){
		WSACleanup();
		closesocket(this->Socket);
	}
};
</html>
<html>
/*
	The Server Class
*/
# this is a comment
class Server{
private:
	int port,Socket_Size;
	SOCKET Socket;
	SOCKADDR_IN Server_Socket;
	WSADATA WsaData;
	SOCKET Client;
	int RequestCounter;
public:
	Server(int port=6666){
		this->port=0;
		this->RequestCounter=0;
		try{
			if(port<=10||WSAStartup(MAKEWORD(2,2),&this->WsaData)!=0)
				throw *(new Error<Text>(port<=10?INVALID_PORT_TO_BIND:WSOCK_VER_NOT_FOUND,true));
			else
				this->port=port;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			returnError(-12);
		}
		 
	}		
private:
	int _init(){
		try{
			this->Socket=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
				if(this->Socket==-1)
					throw *(new Error<Text>(SOCKET_CREATION_FAILED,true));
				else
					this->Server_Socket.sin_port=htons(this->port);
				this->Server_Socket.sin_family=AF_INET;
				this->Server_Socket.sin_addr.s_addr=INADDR_ANY;
				return 1;
			}catch(Error<Text> e){
				cout<<e.getDescription()<<endl;
				return -11;
			}
	}
public:
	int returnError(int error){return error;}
	int start(int port=6666){
		this->port=port;
		if(this->_init()!=1){
			return -11;
		}
		try{
			this->Socket_Size=sizeof(this->Server_Socket);
				if(bind(Socket,(SOCKADDR *)&this->Server_Socket,sizeof(this->Server_Socket))==SOCKET_ERROR)
					throw *(new Error<Text>(BIND_FAILURE,true));
				else if(listen(Socket,25)==SOCKET_ERROR)
						throw *(new Error<Text>(LISTEN_FAILURE,true));
				else
					return 1;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return -11;
		}
	}
	SOCKET hear(){
		try{
			if(Client=accept(this->Socket,(SOCKADDR *)&this->Server_Socket,&this->Socket_Size)==SOCKET_ERROR){
				throw *(new Error<Text>(ACCEPT_ERROR,true));
			}else{
				this->RequestCounter++;
				return this->Client;
			}
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return false;
		}
	}
	int getCounter(){return this->RequestCounter;}
	void close(){
		WSACleanup();
		closesocket(this->Socket);
	}
};
</html>
<html>
/*
	The Server Class
*/
# this is a comment
class Server{
private:
	int port,Socket_Size;
	SOCKET Socket;
	SOCKADDR_IN Server_Socket;
	WSADATA WsaData;
	SOCKET Client;
	int RequestCounter;
public:
	Server(int port=6666){
		this->port=0;
		this->RequestCounter=0;
		try{
			if(port<=10||WSAStartup(MAKEWORD(2,2),&this->WsaData)!=0)
				throw *(new Error<Text>(port<=10?INVALID_PORT_TO_BIND:WSOCK_VER_NOT_FOUND,true));
			else
				this->port=port;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			returnError(-12);
		}
		 
	}		
private:
	int _init(){
		try{
			this->Socket=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
				if(this->Socket==-1)
					throw *(new Error<Text>(SOCKET_CREATION_FAILED,true));
				else
					this->Server_Socket.sin_port=htons(this->port);
				this->Server_Socket.sin_family=AF_INET;
				this->Server_Socket.sin_addr.s_addr=INADDR_ANY;
				return 1;
			}catch(Error<Text> e){
				cout<<e.getDescription()<<endl;
				return -11;
			}
	}
public:
	int returnError(int error){return error;}
	int start(int port=6666){
		this->port=port;
		if(this->_init()!=1){
			return -11;
		}
		try{
			this->Socket_Size=sizeof(this->Server_Socket);
				if(bind(Socket,(SOCKADDR *)&this->Server_Socket,sizeof(this->Server_Socket))==SOCKET_ERROR)
					throw *(new Error<Text>(BIND_FAILURE,true));
				else if(listen(Socket,25)==SOCKET_ERROR)
						throw *(new Error<Text>(LISTEN_FAILURE,true));
				else
					return 1;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return -11;
		}
	}
	SOCKET hear(){
		try{
			if(Client=accept(this->Socket,(SOCKADDR *)&this->Server_Socket,&this->Socket_Size)==SOCKET_ERROR){
				throw *(new Error<Text>(ACCEPT_ERROR,true));
			}else{
				this->RequestCounter++;
				return this->Client;
			}
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return false;
		}
	}
	int getCounter(){return this->RequestCounter;}
	void close(){
		WSACleanup();
		closesocket(this->Socket);
	}
};
</html>
<html>
/*
	The Server Class
*/
# this is a comment
class Server{
private:
	int port,Socket_Size;
	SOCKET Socket;
	SOCKADDR_IN Server_Socket;
	WSADATA WsaData;
	SOCKET Client;
	int RequestCounter;
public:
	Server(int port=6666){
		this->port=0;
		this->RequestCounter=0;
		try{
			if(port<=10||WSAStartup(MAKEWORD(2,2),&this->WsaData)!=0)
				throw *(new Error<Text>(port<=10?INVALID_PORT_TO_BIND:WSOCK_VER_NOT_FOUND,true));
			else
				this->port=port;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			returnError(-12);
		}
		 
	}		
private:
	int _init(){
		try{
			this->Socket=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
				if(this->Socket==-1)
					throw *(new Error<Text>(SOCKET_CREATION_FAILED,true));
				else
					this->Server_Socket.sin_port=htons(this->port);
				this->Server_Socket.sin_family=AF_INET;
				this->Server_Socket.sin_addr.s_addr=INADDR_ANY;
				return 1;
			}catch(Error<Text> e){
				cout<<e.getDescription()<<endl;
				return -11;
			}
	}
public:
	int returnError(int error){return error;}
	int start(int port=6666){
		this->port=port;
		if(this->_init()!=1){
			return -11;
		}
		try{
			this->Socket_Size=sizeof(this->Server_Socket);
				if(bind(Socket,(SOCKADDR *)&this->Server_Socket,sizeof(this->Server_Socket))==SOCKET_ERROR)
					throw *(new Error<Text>(BIND_FAILURE,true));
				else if(listen(Socket,25)==SOCKET_ERROR)
						throw *(new Error<Text>(LISTEN_FAILURE,true));
				else
					return 1;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return -11;
		}
	}
	SOCKET hear(){
		try{
			if(Client=accept(this->Socket,(SOCKADDR *)&this->Server_Socket,&this->Socket_Size)==SOCKET_ERROR){
				throw *(new Error<Text>(ACCEPT_ERROR,true));
			}else{
				this->RequestCounter++;
				return this->Client;
			}
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return false;
		}
	}
	int getCounter(){return this->RequestCounter;}
	void close(){
		WSACleanup();
		closesocket(this->Socket);
	}
};
</html>
<html>
/*
	The Server Class
*/
# this is a comment
class Server{
private:
	int port,Socket_Size;
	SOCKET Socket;
	SOCKADDR_IN Server_Socket;
	WSADATA WsaData;
	SOCKET Client;
	int RequestCounter;
public:
	Server(int port=6666){
		this->port=0;
		this->RequestCounter=0;
		try{
			if(port<=10||WSAStartup(MAKEWORD(2,2),&this->WsaData)!=0)
				throw *(new Error<Text>(port<=10?INVALID_PORT_TO_BIND:WSOCK_VER_NOT_FOUND,true));
			else
				this->port=port;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			returnError(-12);
		}
		 
	}		
private:
	int _init(){
		try{
			this->Socket=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
				if(this->Socket==-1)
					throw *(new Error<Text>(SOCKET_CREATION_FAILED,true));
				else
					this->Server_Socket.sin_port=htons(this->port);
				this->Server_Socket.sin_family=AF_INET;
				this->Server_Socket.sin_addr.s_addr=INADDR_ANY;
				return 1;
			}catch(Error<Text> e){
				cout<<e.getDescription()<<endl;
				return -11;
			}
	}
public:
	int returnError(int error){return error;}
	int start(int port=6666){
		this->port=port;
		if(this->_init()!=1){
			return -11;
		}
		try{
			this->Socket_Size=sizeof(this->Server_Socket);
				if(bind(Socket,(SOCKADDR *)&this->Server_Socket,sizeof(this->Server_Socket))==SOCKET_ERROR)
					throw *(new Error<Text>(BIND_FAILURE,true));
				else if(listen(Socket,25)==SOCKET_ERROR)
						throw *(new Error<Text>(LISTEN_FAILURE,true));
				else
					return 1;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return -11;
		}
	}
	SOCKET hear(){
		try{
			if(Client=accept(this->Socket,(SOCKADDR *)&this->Server_Socket,&this->Socket_Size)==SOCKET_ERROR){
				throw *(new Error<Text>(ACCEPT_ERROR,true));
			}else{
				this->RequestCounter++;
				return this->Client;
			}
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return false;
		}
	}
	int getCounter(){return this->RequestCounter;}
	void close(){
		WSACleanup();
		closesocket(this->Socket);
	}
};
</html>
<html>
/*
	The Server Class
*/
# this is a comment
class Server{
private:
	int port,Socket_Size;
	SOCKET Socket;
	SOCKADDR_IN Server_Socket;
	WSADATA WsaData;
	SOCKET Client;
	int RequestCounter;
public:
	Server(int port=6666){
		this->port=0;
		this->RequestCounter=0;
		try{
			if(port<=10||WSAStartup(MAKEWORD(2,2),&this->WsaData)!=0)
				throw *(new Error<Text>(port<=10?INVALID_PORT_TO_BIND:WSOCK_VER_NOT_FOUND,true));
			else
				this->port=port;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			returnError(-12);
		}
		 
	}		
private:
	int _init(){
		try{
			this->Socket=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
				if(this->Socket==-1)
					throw *(new Error<Text>(SOCKET_CREATION_FAILED,true));
				else
					this->Server_Socket.sin_port=htons(this->port);
				this->Server_Socket.sin_family=AF_INET;
				this->Server_Socket.sin_addr.s_addr=INADDR_ANY;
				return 1;
			}catch(Error<Text> e){
				cout<<e.getDescription()<<endl;
				return -11;
			}
	}
public:
	int returnError(int error){return error;}
	int start(int port=6666){
		this->port=port;
		if(this->_init()!=1){
			return -11;
		}
		try{
			this->Socket_Size=sizeof(this->Server_Socket);
				if(bind(Socket,(SOCKADDR *)&this->Server_Socket,sizeof(this->Server_Socket))==SOCKET_ERROR)
					throw *(new Error<Text>(BIND_FAILURE,true));
				else if(listen(Socket,25)==SOCKET_ERROR)
						throw *(new Error<Text>(LISTEN_FAILURE,true));
				else
					return 1;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return -11;
		}
	}
	SOCKET hear(){
		try{
			if(Client=accept(this->Socket,(SOCKADDR *)&this->Server_Socket,&this->Socket_Size)==SOCKET_ERROR){
				throw *(new Error<Text>(ACCEPT_ERROR,true));
			}else{
				this->RequestCounter++;
				return this->Client;
			}
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return false;
		}
	}
	int getCounter(){return this->RequestCounter;}
	void close(){
		WSACleanup();
		closesocket(this->Socket);
	}
};
</html>
<html>
/*
	The Server Class
*/
# this is a comment
class Server{
private:
	int port,Socket_Size;
	SOCKET Socket;
	SOCKADDR_IN Server_Socket;
	WSADATA WsaData;
	SOCKET Client;
	int RequestCounter;
public:
	Server(int port=6666){
		this->port=0;
		this->RequestCounter=0;
		try{
			if(port<=10||WSAStartup(MAKEWORD(2,2),&this->WsaData)!=0)
				throw *(new Error<Text>(port<=10?INVALID_PORT_TO_BIND:WSOCK_VER_NOT_FOUND,true));
			else
				this->port=port;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			returnError(-12);
		}
		 
	}		
private:
	int _init(){
		try{
			this->Socket=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
				if(this->Socket==-1)
					throw *(new Error<Text>(SOCKET_CREATION_FAILED,true));
				else
					this->Server_Socket.sin_port=htons(this->port);
				this->Server_Socket.sin_family=AF_INET;
				this->Server_Socket.sin_addr.s_addr=INADDR_ANY;
				return 1;
			}catch(Error<Text> e){
				cout<<e.getDescription()<<endl;
				return -11;
			}
	}
public:
	int returnError(int error){return error;}
	int start(int port=6666){
		this->port=port;
		if(this->_init()!=1){
			return -11;
		}
		try{
			this->Socket_Size=sizeof(this->Server_Socket);
				if(bind(Socket,(SOCKADDR *)&this->Server_Socket,sizeof(this->Server_Socket))==SOCKET_ERROR)
					throw *(new Error<Text>(BIND_FAILURE,true));
				else if(listen(Socket,25)==SOCKET_ERROR)
						throw *(new Error<Text>(LISTEN_FAILURE,true));
				else
					return 1;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return -11;
		}
	}
	SOCKET hear(){
		try{
			if(Client=accept(this->Socket,(SOCKADDR *)&this->Server_Socket,&this->Socket_Size)==SOCKET_ERROR){
				throw *(new Error<Text>(ACCEPT_ERROR,true));
			}else{
				this->RequestCounter++;
				return this->Client;
			}
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return false;
		}
	}
	int getCounter(){return this->RequestCounter;}
	void close(){
		WSACleanup();
		closesocket(this->Socket);
	}
};
</html>
<html>
/*
	The Server Class
*/
# this is a comment
class Server{
private:
	int port,Socket_Size;
	SOCKET Socket;
	SOCKADDR_IN Server_Socket;
	WSADATA WsaData;
	SOCKET Client;
	int RequestCounter;
public:
	Server(int port=6666){
		this->port=0;
		this->RequestCounter=0;
		try{
			if(port<=10||WSAStartup(MAKEWORD(2,2),&this->WsaData)!=0)
				throw *(new Error<Text>(port<=10?INVALID_PORT_TO_BIND:WSOCK_VER_NOT_FOUND,true));
			else
				this->port=port;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			returnError(-12);
		}
		 
	}		
private:
	int _init(){
		try{
			this->Socket=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
				if(this->Socket==-1)
					throw *(new Error<Text>(SOCKET_CREATION_FAILED,true));
				else
					this->Server_Socket.sin_port=htons(this->port);
				this->Server_Socket.sin_family=AF_INET;
				this->Server_Socket.sin_addr.s_addr=INADDR_ANY;
				return 1;
			}catch(Error<Text> e){
				cout<<e.getDescription()<<endl;
				return -11;
			}
	}
public:
	int returnError(int error){return error;}
	int start(int port=6666){
		this->port=port;
		if(this->_init()!=1){
			return -11;
		}
		try{
			this->Socket_Size=sizeof(this->Server_Socket);
				if(bind(Socket,(SOCKADDR *)&this->Server_Socket,sizeof(this->Server_Socket))==SOCKET_ERROR)
					throw *(new Error<Text>(BIND_FAILURE,true));
				else if(listen(Socket,25)==SOCKET_ERROR)
						throw *(new Error<Text>(LISTEN_FAILURE,true));
				else
					return 1;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return -11;
		}
	}
	SOCKET hear(){
		try{
			if(Client=accept(this->Socket,(SOCKADDR *)&this->Server_Socket,&this->Socket_Size)==SOCKET_ERROR){
				throw *(new Error<Text>(ACCEPT_ERROR,true));
			}else{
				this->RequestCounter++;
				return this->Client;
			}
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return false;
		}
	}
	int getCounter(){return this->RequestCounter;}
	void close(){
		WSACleanup();
		closesocket(this->Socket);
	}
};
</html>
<html>
/*
	The Server Class
*/
# this is a comment
class Server{
private:
	int port,Socket_Size;
	SOCKET Socket;
	SOCKADDR_IN Server_Socket;
	WSADATA WsaData;
	SOCKET Client;
	int RequestCounter;
public:
	Server(int port=6666){
		this->port=0;
		this->RequestCounter=0;
		try{
			if(port<=10||WSAStartup(MAKEWORD(2,2),&this->WsaData)!=0)
				throw *(new Error<Text>(port<=10?INVALID_PORT_TO_BIND:WSOCK_VER_NOT_FOUND,true));
			else
				this->port=port;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			returnError(-12);
		}
		 
	}		
private:
	int _init(){
		try{
			this->Socket=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
				if(this->Socket==-1)
					throw *(new Error<Text>(SOCKET_CREATION_FAILED,true));
				else
					this->Server_Socket.sin_port=htons(this->port);
				this->Server_Socket.sin_family=AF_INET;
				this->Server_Socket.sin_addr.s_addr=INADDR_ANY;
				return 1;
			}catch(Error<Text> e){
				cout<<e.getDescription()<<endl;
				return -11;
			}
	}
public:
	int returnError(int error){return error;}
	int start(int port=6666){
		this->port=port;
		if(this->_init()!=1){
			return -11;
		}
		try{
			this->Socket_Size=sizeof(this->Server_Socket);
				if(bind(Socket,(SOCKADDR *)&this->Server_Socket,sizeof(this->Server_Socket))==SOCKET_ERROR)
					throw *(new Error<Text>(BIND_FAILURE,true));
				else if(listen(Socket,25)==SOCKET_ERROR)
						throw *(new Error<Text>(LISTEN_FAILURE,true));
				else
					return 1;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return -11;
		}
	}
	SOCKET hear(){
		try{
			if(Client=accept(this->Socket,(SOCKADDR *)&this->Server_Socket,&this->Socket_Size)==SOCKET_ERROR){
				throw *(new Error<Text>(ACCEPT_ERROR,true));
			}else{
				this->RequestCounter++;
				return this->Client;
			}
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return false;
		}
	}
	int getCounter(){return this->RequestCounter;}
	void close(){
		WSACleanup();
		closesocket(this->Socket);
	}
};
</html>
<html>
/*
	The Server Class
*/
# this is a comment
class Server{
private:
	int port,Socket_Size;
	SOCKET Socket;
	SOCKADDR_IN Server_Socket;
	WSADATA WsaData;
	SOCKET Client;
	int RequestCounter;
public:
	Server(int port=6666){
		this->port=0;
		this->RequestCounter=0;
		try{
			if(port<=10||WSAStartup(MAKEWORD(2,2),&this->WsaData)!=0)
				throw *(new Error<Text>(port<=10?INVALID_PORT_TO_BIND:WSOCK_VER_NOT_FOUND,true));
			else
				this->port=port;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			returnError(-12);
		}
		 
	}		
private:
	int _init(){
		try{
			this->Socket=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
				if(this->Socket==-1)
					throw *(new Error<Text>(SOCKET_CREATION_FAILED,true));
				else
					this->Server_Socket.sin_port=htons(this->port);
				this->Server_Socket.sin_family=AF_INET;
				this->Server_Socket.sin_addr.s_addr=INADDR_ANY;
				return 1;
			}catch(Error<Text> e){
				cout<<e.getDescription()<<endl;
				return -11;
			}
	}
public:
	int returnError(int error){return error;}
	int start(int port=6666){
		this->port=port;
		if(this->_init()!=1){
			return -11;
		}
		try{
			this->Socket_Size=sizeof(this->Server_Socket);
				if(bind(Socket,(SOCKADDR *)&this->Server_Socket,sizeof(this->Server_Socket))==SOCKET_ERROR)
					throw *(new Error<Text>(BIND_FAILURE,true));
				else if(listen(Socket,25)==SOCKET_ERROR)
						throw *(new Error<Text>(LISTEN_FAILURE,true));
				else
					return 1;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return -11;
		}
	}
	SOCKET hear(){
		try{
			if(Client=accept(this->Socket,(SOCKADDR *)&this->Server_Socket,&this->Socket_Size)==SOCKET_ERROR){
				throw *(new Error<Text>(ACCEPT_ERROR,true));
			}else{
				this->RequestCounter++;
				return this->Client;
			}
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return false;
		}
	}
	int getCounter(){return this->RequestCounter;}
	void close(){
		WSACleanup();
		closesocket(this->Socket);
	}
};
</html>
<html>
/*
	The Server Class
*/
# this is a comment
class Server{
private:
	int port,Socket_Size;
	SOCKET Socket;
	SOCKADDR_IN Server_Socket;
	WSADATA WsaData;
	SOCKET Client;
	int RequestCounter;
public:
	Server(int port=6666){
		this->port=0;
		this->RequestCounter=0;
		try{
			if(port<=10||WSAStartup(MAKEWORD(2,2),&this->WsaData)!=0)
				throw *(new Error<Text>(port<=10?INVALID_PORT_TO_BIND:WSOCK_VER_NOT_FOUND,true));
			else
				this->port=port;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			returnError(-12);
		}
		 
	}		
private:
	int _init(){
		try{
			this->Socket=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
				if(this->Socket==-1)
					throw *(new Error<Text>(SOCKET_CREATION_FAILED,true));
				else
					this->Server_Socket.sin_port=htons(this->port);
				this->Server_Socket.sin_family=AF_INET;
				this->Server_Socket.sin_addr.s_addr=INADDR_ANY;
				return 1;
			}catch(Error<Text> e){
				cout<<e.getDescription()<<endl;
				return -11;
			}
	}
public:
	int returnError(int error){return error;}
	int start(int port=6666){
		this->port=port;
		if(this->_init()!=1){
			return -11;
		}
		try{
			this->Socket_Size=sizeof(this->Server_Socket);
				if(bind(Socket,(SOCKADDR *)&this->Server_Socket,sizeof(this->Server_Socket))==SOCKET_ERROR)
					throw *(new Error<Text>(BIND_FAILURE,true));
				else if(listen(Socket,25)==SOCKET_ERROR)
						throw *(new Error<Text>(LISTEN_FAILURE,true));
				else
					return 1;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return -11;
		}
	}
	SOCKET hear(){
		try{
			if(Client=accept(this->Socket,(SOCKADDR *)&this->Server_Socket,&this->Socket_Size)==SOCKET_ERROR){
				throw *(new Error<Text>(ACCEPT_ERROR,true));
			}else{
				this->RequestCounter++;
				return this->Client;
			}
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return false;
		}
	}
	int getCounter(){return this->RequestCounter;}
	void close(){
		WSACleanup();
		closesocket(this->Socket);
	}
};
</html>
<html>
/*
	The Server Class
*/
# this is a comment
class Server{
private:
	int port,Socket_Size;
	SOCKET Socket;
	SOCKADDR_IN Server_Socket;
	WSADATA WsaData;
	SOCKET Client;
	int RequestCounter;
public:
	Server(int port=6666){
		this->port=0;
		this->RequestCounter=0;
		try{
			if(port<=10||WSAStartup(MAKEWORD(2,2),&this->WsaData)!=0)
				throw *(new Error<Text>(port<=10?INVALID_PORT_TO_BIND:WSOCK_VER_NOT_FOUND,true));
			else
				this->port=port;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			returnError(-12);
		}
		 
	}		
private:
	int _init(){
		try{
			this->Socket=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
				if(this->Socket==-1)
					throw *(new Error<Text>(SOCKET_CREATION_FAILED,true));
				else
					this->Server_Socket.sin_port=htons(this->port);
				this->Server_Socket.sin_family=AF_INET;
				this->Server_Socket.sin_addr.s_addr=INADDR_ANY;
				return 1;
			}catch(Error<Text> e){
				cout<<e.getDescription()<<endl;
				return -11;
			}
	}
public:
	int returnError(int error){return error;}
	int start(int port=6666){
		this->port=port;
		if(this->_init()!=1){
			return -11;
		}
		try{
			this->Socket_Size=sizeof(this->Server_Socket);
				if(bind(Socket,(SOCKADDR *)&this->Server_Socket,sizeof(this->Server_Socket))==SOCKET_ERROR)
					throw *(new Error<Text>(BIND_FAILURE,true));
				else if(listen(Socket,25)==SOCKET_ERROR)
						throw *(new Error<Text>(LISTEN_FAILURE,true));
				else
					return 1;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return -11;
		}
	}
	SOCKET hear(){
		try{
			if(Client=accept(this->Socket,(SOCKADDR *)&this->Server_Socket,&this->Socket_Size)==SOCKET_ERROR){
				throw *(new Error<Text>(ACCEPT_ERROR,true));
			}else{
				this->RequestCounter++;
				return this->Client;
			}
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return false;
		}
	}
	int getCounter(){return this->RequestCounter;}
	void close(){
		WSACleanup();
		closesocket(this->Socket);
	}
};
</html>
<html>
/*
	The Server Class
*/
# this is a comment
class Server{
private:
	int port,Socket_Size;
	SOCKET Socket;
	SOCKADDR_IN Server_Socket;
	WSADATA WsaData;
	SOCKET Client;
	int RequestCounter;
public:
	Server(int port=6666){
		this->port=0;
		this->RequestCounter=0;
		try{
			if(port<=10||WSAStartup(MAKEWORD(2,2),&this->WsaData)!=0)
				throw *(new Error<Text>(port<=10?INVALID_PORT_TO_BIND:WSOCK_VER_NOT_FOUND,true));
			else
				this->port=port;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			returnError(-12);
		}
		 
	}		
private:
	int _init(){
		try{
			this->Socket=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
				if(this->Socket==-1)
					throw *(new Error<Text>(SOCKET_CREATION_FAILED,true));
				else
					this->Server_Socket.sin_port=htons(this->port);
				this->Server_Socket.sin_family=AF_INET;
				this->Server_Socket.sin_addr.s_addr=INADDR_ANY;
				return 1;
			}catch(Error<Text> e){
				cout<<e.getDescription()<<endl;
				return -11;
			}
	}
public:
	int returnError(int error){return error;}
	int start(int port=6666){
		this->port=port;
		if(this->_init()!=1){
			return -11;
		}
		try{
			this->Socket_Size=sizeof(this->Server_Socket);
				if(bind(Socket,(SOCKADDR *)&this->Server_Socket,sizeof(this->Server_Socket))==SOCKET_ERROR)
					throw *(new Error<Text>(BIND_FAILURE,true));
				else if(listen(Socket,25)==SOCKET_ERROR)
						throw *(new Error<Text>(LISTEN_FAILURE,true));
				else
					return 1;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return -11;
		}
	}
	SOCKET hear(){
		try{
			if(Client=accept(this->Socket,(SOCKADDR *)&this->Server_Socket,&this->Socket_Size)==SOCKET_ERROR){
				throw *(new Error<Text>(ACCEPT_ERROR,true));
			}else{
				this->RequestCounter++;
				return this->Client;
			}
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return false;
		}
	}
	int getCounter(){return this->RequestCounter;}
	void close(){
		WSACleanup();
		closesocket(this->Socket);
	}
};
</html>
<html>
/*
	The Server Class
*/
# this is a comment
class Server{
private:
	int port,Socket_Size;
	SOCKET Socket;
	SOCKADDR_IN Server_Socket;
	WSADATA WsaData;
	SOCKET Client;
	int RequestCounter;
public:
	Server(int port=6666){
		this->port=0;
		this->RequestCounter=0;
		try{
			if(port<=10||WSAStartup(MAKEWORD(2,2),&this->WsaData)!=0)
				throw *(new Error<Text>(port<=10?INVALID_PORT_TO_BIND:WSOCK_VER_NOT_FOUND,true));
			else
				this->port=port;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			returnError(-12);
		}
		 
	}		
private:
	int _init(){
		try{
			this->Socket=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
				if(this->Socket==-1)
					throw *(new Error<Text>(SOCKET_CREATION_FAILED,true));
				else
					this->Server_Socket.sin_port=htons(this->port);
				this->Server_Socket.sin_family=AF_INET;
				this->Server_Socket.sin_addr.s_addr=INADDR_ANY;
				return 1;
			}catch(Error<Text> e){
				cout<<e.getDescription()<<endl;
				return -11;
			}
	}
public:
	int returnError(int error){return error;}
	int start(int port=6666){
		this->port=port;
		if(this->_init()!=1){
			return -11;
		}
		try{
			this->Socket_Size=sizeof(this->Server_Socket);
				if(bind(Socket,(SOCKADDR *)&this->Server_Socket,sizeof(this->Server_Socket))==SOCKET_ERROR)
					throw *(new Error<Text>(BIND_FAILURE,true));
				else if(listen(Socket,25)==SOCKET_ERROR)
						throw *(new Error<Text>(LISTEN_FAILURE,true));
				else
					return 1;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return -11;
		}
	}
	SOCKET hear(){
		try{
			if(Client=accept(this->Socket,(SOCKADDR *)&this->Server_Socket,&this->Socket_Size)==SOCKET_ERROR){
				throw *(new Error<Text>(ACCEPT_ERROR,true));
			}else{
				this->RequestCounter++;
				return this->Client;
			}
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return false;
		}
	}
	int getCounter(){return this->RequestCounter;}
	void close(){
		WSACleanup();
		closesocket(this->Socket);
	}
};
</html>
<html>
/*
	The Server Class
*/
# this is a comment
class Server{
private:
	int port,Socket_Size;
	SOCKET Socket;
	SOCKADDR_IN Server_Socket;
	WSADATA WsaData;
	SOCKET Client;
	int RequestCounter;
public:
	Server(int port=6666){
		this->port=0;
		this->RequestCounter=0;
		try{
			if(port<=10||WSAStartup(MAKEWORD(2,2),&this->WsaData)!=0)
				throw *(new Error<Text>(port<=10?INVALID_PORT_TO_BIND:WSOCK_VER_NOT_FOUND,true));
			else
				this->port=port;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			returnError(-12);
		}
		 
	}		
private:
	int _init(){
		try{
			this->Socket=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
				if(this->Socket==-1)
					throw *(new Error<Text>(SOCKET_CREATION_FAILED,true));
				else
					this->Server_Socket.sin_port=htons(this->port);
				this->Server_Socket.sin_family=AF_INET;
				this->Server_Socket.sin_addr.s_addr=INADDR_ANY;
				return 1;
			}catch(Error<Text> e){
				cout<<e.getDescription()<<endl;
				return -11;
			}
	}
public:
	int returnError(int error){return error;}
	int start(int port=6666){
		this->port=port;
		if(this->_init()!=1){
			return -11;
		}
		try{
			this->Socket_Size=sizeof(this->Server_Socket);
				if(bind(Socket,(SOCKADDR *)&this->Server_Socket,sizeof(this->Server_Socket))==SOCKET_ERROR)
					throw *(new Error<Text>(BIND_FAILURE,true));
				else if(listen(Socket,25)==SOCKET_ERROR)
						throw *(new Error<Text>(LISTEN_FAILURE,true));
				else
					return 1;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return -11;
		}
	}
	SOCKET hear(){
		try{
			if(Client=accept(this->Socket,(SOCKADDR *)&this->Server_Socket,&this->Socket_Size)==SOCKET_ERROR){
				throw *(new Error<Text>(ACCEPT_ERROR,true));
			}else{
				this->RequestCounter++;
				return this->Client;
			}
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return false;
		}
	}
	int getCounter(){return this->RequestCounter;}
	void close(){
		WSACleanup();
		closesocket(this->Socket);
	}
};
</html>
<html>
/*
	The Server Class
*/
# this is a comment
class Server{
private:
	int port,Socket_Size;
	SOCKET Socket;
	SOCKADDR_IN Server_Socket;
	WSADATA WsaData;
	SOCKET Client;
	int RequestCounter;
public:
	Server(int port=6666){
		this->port=0;
		this->RequestCounter=0;
		try{
			if(port<=10||WSAStartup(MAKEWORD(2,2),&this->WsaData)!=0)
				throw *(new Error<Text>(port<=10?INVALID_PORT_TO_BIND:WSOCK_VER_NOT_FOUND,true));
			else
				this->port=port;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			returnError(-12);
		}
		 
	}		
private:
	int _init(){
		try{
			this->Socket=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
				if(this->Socket==-1)
					throw *(new Error<Text>(SOCKET_CREATION_FAILED,true));
				else
					this->Server_Socket.sin_port=htons(this->port);
				this->Server_Socket.sin_family=AF_INET;
				this->Server_Socket.sin_addr.s_addr=INADDR_ANY;
				return 1;
			}catch(Error<Text> e){
				cout<<e.getDescription()<<endl;
				return -11;
			}
	}
public:
	int returnError(int error){return error;}
	int start(int port=6666){
		this->port=port;
		if(this->_init()!=1){
			return -11;
		}
		try{
			this->Socket_Size=sizeof(this->Server_Socket);
				if(bind(Socket,(SOCKADDR *)&this->Server_Socket,sizeof(this->Server_Socket))==SOCKET_ERROR)
					throw *(new Error<Text>(BIND_FAILURE,true));
				else if(listen(Socket,25)==SOCKET_ERROR)
						throw *(new Error<Text>(LISTEN_FAILURE,true));
				else
					return 1;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return -11;
		}
	}
	SOCKET hear(){
		try{
			if(Client=accept(this->Socket,(SOCKADDR *)&this->Server_Socket,&this->Socket_Size)==SOCKET_ERROR){
				throw *(new Error<Text>(ACCEPT_ERROR,true));
			}else{
				this->RequestCounter++;
				return this->Client;
			}
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return false;
		}
	}
	int getCounter(){return this->RequestCounter;}
	void close(){
		WSACleanup();
		closesocket(this->Socket);
	}
};
</html>
<html>
/*
	The Server Class
*/
# this is a comment
class Server{
private:
	int port,Socket_Size;
	SOCKET Socket;
	SOCKADDR_IN Server_Socket;
	WSADATA WsaData;
	SOCKET Client;
	int RequestCounter;
public:
	Server(int port=6666){
		this->port=0;
		this->RequestCounter=0;
		try{
			if(port<=10||WSAStartup(MAKEWORD(2,2),&this->WsaData)!=0)
				throw *(new Error<Text>(port<=10?INVALID_PORT_TO_BIND:WSOCK_VER_NOT_FOUND,true));
			else
				this->port=port;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			returnError(-12);
		}
		 
	}		
private:
	int _init(){
		try{
			this->Socket=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
				if(this->Socket==-1)
					throw *(new Error<Text>(SOCKET_CREATION_FAILED,true));
				else
					this->Server_Socket.sin_port=htons(this->port);
				this->Server_Socket.sin_family=AF_INET;
				this->Server_Socket.sin_addr.s_addr=INADDR_ANY;
				return 1;
			}catch(Error<Text> e){
				cout<<e.getDescription()<<endl;
				return -11;
			}
	}
public:
	int returnError(int error){return error;}
	int start(int port=6666){
		this->port=port;
		if(this->_init()!=1){
			return -11;
		}
		try{
			this->Socket_Size=sizeof(this->Server_Socket);
				if(bind(Socket,(SOCKADDR *)&this->Server_Socket,sizeof(this->Server_Socket))==SOCKET_ERROR)
					throw *(new Error<Text>(BIND_FAILURE,true));
				else if(listen(Socket,25)==SOCKET_ERROR)
						throw *(new Error<Text>(LISTEN_FAILURE,true));
				else
					return 1;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return -11;
		}
	}
	SOCKET hear(){
		try{
			if(Client=accept(this->Socket,(SOCKADDR *)&this->Server_Socket,&this->Socket_Size)==SOCKET_ERROR){
				throw *(new Error<Text>(ACCEPT_ERROR,true));
			}else{
				this->RequestCounter++;
				return this->Client;
			}
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return false;
		}
	}
	int getCounter(){return this->RequestCounter;}
	void close(){
		WSACleanup();
		closesocket(this->Socket);
	}
};
</html>
<html>
/*
	The Server Class
*/
# this is a comment
class Server{
private:
	int port,Socket_Size;
	SOCKET Socket;
	SOCKADDR_IN Server_Socket;
	WSADATA WsaData;
	SOCKET Client;
	int RequestCounter;
public:
	Server(int port=6666){
		this->port=0;
		this->RequestCounter=0;
		try{
			if(port<=10||WSAStartup(MAKEWORD(2,2),&this->WsaData)!=0)
				throw *(new Error<Text>(port<=10?INVALID_PORT_TO_BIND:WSOCK_VER_NOT_FOUND,true));
			else
				this->port=port;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			returnError(-12);
		}
		 
	}		
private:
	int _init(){
		try{
			this->Socket=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
				if(this->Socket==-1)
					throw *(new Error<Text>(SOCKET_CREATION_FAILED,true));
				else
					this->Server_Socket.sin_port=htons(this->port);
				this->Server_Socket.sin_family=AF_INET;
				this->Server_Socket.sin_addr.s_addr=INADDR_ANY;
				return 1;
			}catch(Error<Text> e){
				cout<<e.getDescription()<<endl;
				return -11;
			}
	}
public:
	int returnError(int error){return error;}
	int start(int port=6666){
		this->port=port;
		if(this->_init()!=1){
			return -11;
		}
		try{
			this->Socket_Size=sizeof(this->Server_Socket);
				if(bind(Socket,(SOCKADDR *)&this->Server_Socket,sizeof(this->Server_Socket))==SOCKET_ERROR)
					throw *(new Error<Text>(BIND_FAILURE,true));
				else if(listen(Socket,25)==SOCKET_ERROR)
						throw *(new Error<Text>(LISTEN_FAILURE,true));
				else
					return 1;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return -11;
		}
	}
	SOCKET hear(){
		try{
			if(Client=accept(this->Socket,(SOCKADDR *)&this->Server_Socket,&this->Socket_Size)==SOCKET_ERROR){
				throw *(new Error<Text>(ACCEPT_ERROR,true));
			}else{
				this->RequestCounter++;
				return this->Client;
			}
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return false;
		}
	}
	int getCounter(){return this->RequestCounter;}
	void close(){
		WSACleanup();
		closesocket(this->Socket);
	}
};
</html>
<html>
/*
	The Server Class
*/
# this is a comment
class Server{
private:
	int port,Socket_Size;
	SOCKET Socket;
	SOCKADDR_IN Server_Socket;
	WSADATA WsaData;
	SOCKET Client;
	int RequestCounter;
public:
	Server(int port=6666){
		this->port=0;
		this->RequestCounter=0;
		try{
			if(port<=10||WSAStartup(MAKEWORD(2,2),&this->WsaData)!=0)
				throw *(new Error<Text>(port<=10?INVALID_PORT_TO_BIND:WSOCK_VER_NOT_FOUND,true));
			else
				this->port=port;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			returnError(-12);
		}
		 
	}		
private:
	int _init(){
		try{
			this->Socket=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
				if(this->Socket==-1)
					throw *(new Error<Text>(SOCKET_CREATION_FAILED,true));
				else
					this->Server_Socket.sin_port=htons(this->port);
				this->Server_Socket.sin_family=AF_INET;
				this->Server_Socket.sin_addr.s_addr=INADDR_ANY;
				return 1;
			}catch(Error<Text> e){
				cout<<e.getDescription()<<endl;
				return -11;
			}
	}
public:
	int returnError(int error){return error;}
	int start(int port=6666){
		this->port=port;
		if(this->_init()!=1){
			return -11;
		}
		try{
			this->Socket_Size=sizeof(this->Server_Socket);
				if(bind(Socket,(SOCKADDR *)&this->Server_Socket,sizeof(this->Server_Socket))==SOCKET_ERROR)
					throw *(new Error<Text>(BIND_FAILURE,true));
				else if(listen(Socket,25)==SOCKET_ERROR)
						throw *(new Error<Text>(LISTEN_FAILURE,true));
				else
					return 1;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return -11;
		}
	}
	SOCKET hear(){
		try{
			if(Client=accept(this->Socket,(SOCKADDR *)&this->Server_Socket,&this->Socket_Size)==SOCKET_ERROR){
				throw *(new Error<Text>(ACCEPT_ERROR,true));
			}else{
				this->RequestCounter++;
				return this->Client;
			}
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return false;
		}
	}
	int getCounter(){return this->RequestCounter;}
	void close(){
		WSACleanup();
		closesocket(this->Socket);
	}
};
</html>
<html>
/*
	The Server Class
*/
# this is a comment
class Server{
private:
	int port,Socket_Size;
	SOCKET Socket;
	SOCKADDR_IN Server_Socket;
	WSADATA WsaData;
	SOCKET Client;
	int RequestCounter;
public:
	Server(int port=6666){
		this->port=0;
		this->RequestCounter=0;
		try{
			if(port<=10||WSAStartup(MAKEWORD(2,2),&this->WsaData)!=0)
				throw *(new Error<Text>(port<=10?INVALID_PORT_TO_BIND:WSOCK_VER_NOT_FOUND,true));
			else
				this->port=port;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			returnError(-12);
		}
		 
	}		
private:
	int _init(){
		try{
			this->Socket=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
				if(this->Socket==-1)
					throw *(new Error<Text>(SOCKET_CREATION_FAILED,true));
				else
					this->Server_Socket.sin_port=htons(this->port);
				this->Server_Socket.sin_family=AF_INET;
				this->Server_Socket.sin_addr.s_addr=INADDR_ANY;
				return 1;
			}catch(Error<Text> e){
				cout<<e.getDescription()<<endl;
				return -11;
			}
	}
public:
	int returnError(int error){return error;}
	int start(int port=6666){
		this->port=port;
		if(this->_init()!=1){
			return -11;
		}
		try{
			this->Socket_Size=sizeof(this->Server_Socket);
				if(bind(Socket,(SOCKADDR *)&this->Server_Socket,sizeof(this->Server_Socket))==SOCKET_ERROR)
					throw *(new Error<Text>(BIND_FAILURE,true));
				else if(listen(Socket,25)==SOCKET_ERROR)
						throw *(new Error<Text>(LISTEN_FAILURE,true));
				else
					return 1;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return -11;
		}
	}
	SOCKET hear(){
		try{
			if(Client=accept(this->Socket,(SOCKADDR *)&this->Server_Socket,&this->Socket_Size)==SOCKET_ERROR){
				throw *(new Error<Text>(ACCEPT_ERROR,true));
			}else{
				this->RequestCounter++;
				return this->Client;
			}
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return false;
		}
	}
	int getCounter(){return this->RequestCounter;}
	void close(){
		WSACleanup();
		closesocket(this->Socket);
	}
};
</html>
<html>
/*
	The Server Class
*/
# this is a comment
class Server{
private:
	int port,Socket_Size;
	SOCKET Socket;
	SOCKADDR_IN Server_Socket;
	WSADATA WsaData;
	SOCKET Client;
	int RequestCounter;
public:
	Server(int port=6666){
		this->port=0;
		this->RequestCounter=0;
		try{
			if(port<=10||WSAStartup(MAKEWORD(2,2),&this->WsaData)!=0)
				throw *(new Error<Text>(port<=10?INVALID_PORT_TO_BIND:WSOCK_VER_NOT_FOUND,true));
			else
				this->port=port;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			returnError(-12);
		}
		 
	}		
private:
	int _init(){
		try{
			this->Socket=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
				if(this->Socket==-1)
					throw *(new Error<Text>(SOCKET_CREATION_FAILED,true));
				else
					this->Server_Socket.sin_port=htons(this->port);
				this->Server_Socket.sin_family=AF_INET;
				this->Server_Socket.sin_addr.s_addr=INADDR_ANY;
				return 1;
			}catch(Error<Text> e){
				cout<<e.getDescription()<<endl;
				return -11;
			}
	}
public:
	int returnError(int error){return error;}
	int start(int port=6666){
		this->port=port;
		if(this->_init()!=1){
			return -11;
		}
		try{
			this->Socket_Size=sizeof(this->Server_Socket);
				if(bind(Socket,(SOCKADDR *)&this->Server_Socket,sizeof(this->Server_Socket))==SOCKET_ERROR)
					throw *(new Error<Text>(BIND_FAILURE,true));
				else if(listen(Socket,25)==SOCKET_ERROR)
						throw *(new Error<Text>(LISTEN_FAILURE,true));
				else
					return 1;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return -11;
		}
	}
	SOCKET hear(){
		try{
			if(Client=accept(this->Socket,(SOCKADDR *)&this->Server_Socket,&this->Socket_Size)==SOCKET_ERROR){
				throw *(new Error<Text>(ACCEPT_ERROR,true));
			}else{
				this->RequestCounter++;
				return this->Client;
			}
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return false;
		}
	}
	int getCounter(){return this->RequestCounter;}
	void close(){
		WSACleanup();
		closesocket(this->Socket);
	}
};
</html>
<html>
/*
	The Server Class
*/
# this is a comment
class Server{
private:
	int port,Socket_Size;
	SOCKET Socket;
	SOCKADDR_IN Server_Socket;
	WSADATA WsaData;
	SOCKET Client;
	int RequestCounter;
public:
	Server(int port=6666){
		this->port=0;
		this->RequestCounter=0;
		try{
			if(port<=10||WSAStartup(MAKEWORD(2,2),&this->WsaData)!=0)
				throw *(new Error<Text>(port<=10?INVALID_PORT_TO_BIND:WSOCK_VER_NOT_FOUND,true));
			else
				this->port=port;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			returnError(-12);
		}
		 
	}		
private:
	int _init(){
		try{
			this->Socket=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
				if(this->Socket==-1)
					throw *(new Error<Text>(SOCKET_CREATION_FAILED,true));
				else
					this->Server_Socket.sin_port=htons(this->port);
				this->Server_Socket.sin_family=AF_INET;
				this->Server_Socket.sin_addr.s_addr=INADDR_ANY;
				return 1;
			}catch(Error<Text> e){
				cout<<e.getDescription()<<endl;
				return -11;
			}
	}
public:
	int returnError(int error){return error;}
	int start(int port=6666){
		this->port=port;
		if(this->_init()!=1){
			return -11;
		}
		try{
			this->Socket_Size=sizeof(this->Server_Socket);
				if(bind(Socket,(SOCKADDR *)&this->Server_Socket,sizeof(this->Server_Socket))==SOCKET_ERROR)
					throw *(new Error<Text>(BIND_FAILURE,true));
				else if(listen(Socket,25)==SOCKET_ERROR)
						throw *(new Error<Text>(LISTEN_FAILURE,true));
				else
					return 1;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return -11;
		}
	}
	SOCKET hear(){
		try{
			if(Client=accept(this->Socket,(SOCKADDR *)&this->Server_Socket,&this->Socket_Size)==SOCKET_ERROR){
				throw *(new Error<Text>(ACCEPT_ERROR,true));
			}else{
				this->RequestCounter++;
				return this->Client;
			}
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return false;
		}
	}
	int getCounter(){return this->RequestCounter;}
	void close(){
		WSACleanup();
		closesocket(this->Socket);
	}
};
</html>
<html>
/*
	The Server Class
*/
# this is a comment
class Server{
private:
	int port,Socket_Size;
	SOCKET Socket;
	SOCKADDR_IN Server_Socket;
	WSADATA WsaData;
	SOCKET Client;
	int RequestCounter;
public:
	Server(int port=6666){
		this->port=0;
		this->RequestCounter=0;
		try{
			if(port<=10||WSAStartup(MAKEWORD(2,2),&this->WsaData)!=0)
				throw *(new Error<Text>(port<=10?INVALID_PORT_TO_BIND:WSOCK_VER_NOT_FOUND,true));
			else
				this->port=port;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			returnError(-12);
		}
		 
	}		
private:
	int _init(){
		try{
			this->Socket=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
				if(this->Socket==-1)
					throw *(new Error<Text>(SOCKET_CREATION_FAILED,true));
				else
					this->Server_Socket.sin_port=htons(this->port);
				this->Server_Socket.sin_family=AF_INET;
				this->Server_Socket.sin_addr.s_addr=INADDR_ANY;
				return 1;
			}catch(Error<Text> e){
				cout<<e.getDescription()<<endl;
				return -11;
			}
	}
public:
	int returnError(int error){return error;}
	int start(int port=6666){
		this->port=port;
		if(this->_init()!=1){
			return -11;
		}
		try{
			this->Socket_Size=sizeof(this->Server_Socket);
				if(bind(Socket,(SOCKADDR *)&this->Server_Socket,sizeof(this->Server_Socket))==SOCKET_ERROR)
					throw *(new Error<Text>(BIND_FAILURE,true));
				else if(listen(Socket,25)==SOCKET_ERROR)
						throw *(new Error<Text>(LISTEN_FAILURE,true));
				else
					return 1;
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return -11;
		}
	}
	SOCKET hear(){
		try{
			if(Client=accept(this->Socket,(SOCKADDR *)&this->Server_Socket,&this->Socket_Size)==SOCKET_ERROR){
				throw *(new Error<Text>(ACCEPT_ERROR,true));
			}else{
				this->RequestCounter++;
				return this->Client;
			}
		}catch(Error<Text> e){
			cout<<e.getDescription()<<endl;
			return false;
		}
	}
	int getCounter(){return this->RequestCounter;}
	void close(){
		WSACleanup();
		closesocket(this->Socket);
	}
};
</html>
