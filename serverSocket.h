#include "console.h"
#include "fileIO.h"
#include "httpErrors.h"
#include "mimes.h"
#include <strings.h>
class Client;
class Server{
private:
SOCKET Socket, Client;
const static int BUFFER_SIZE=3400;
char* buffer;
WSADATA wsadata;
SOCKADDR_IN server;
int port;
int Sock_Size;
public:
	Server(int port,bool verbose=false){
		this->port=port;
	 	if(WSAStartup(MAKEWORD(2,2), &this->wsadata)!=0){
			throw new Error(WSOCK_ERROR);
		}
		if(verbose)
			cout<<" + Initialising Socket\n";
		this->Socket=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if(this->Socket==SOCKET_ERROR){
			throw new Error(SOCK_ERROR);
		}
		server.sin_port=htons(this->port);
		server.sin_family=AF_INET;
		server.sin_addr.s_addr=INADDR_ANY;
		if(verbose)
			cout<<" + Binding Server Socket @"<<port<<endl;
		this->Sock_Size=sizeof(server);
		if(bind(Socket, (SOCKADDR *)(&server), sizeof(server)) == SOCKET_ERROR){
			throw new Error(BIND_FAILURE);
		}
		if(verbose)
			cout<<" + Bind Successfull\n";
		listen(this->Socket,5000);
	}
	SOCKADDR_IN* getSockAddr(){
				return &this->server;
	}
	int getSocketSize(){
		return this->Sock_Size;
	}
	SOCKET hear(){
		this->Client=accept(this->Socket,(SOCKADDR *)&this->server,&this->Sock_Size);
		return this->Client;
	}
	int close(){
		WSACleanup();
		closesocket(this->Socket);
	}
};
class Client{
private:
Server* server;
SOCKET client;
string inBuffer;
string outBuffer;
char *charInBuffer;
int bufferInLength;
bool done;
bool saidMethod;
bool lookForNextRL;
int newLineCount;
int charCounter;
LPSTR resource;
int size;
public:
	   Client(SOCKET s,Server * ref){
			 this->client=s;
			 this->server=ref;
			 this->done=false;
			 inBuffer="";
			 charInBuffer=new char[1];
			 saidMethod=false;
			 newLineCount=0;
			 this->size=this->server->getSocketSize();
			 this->charCounter=0;
	   }
/*	   void read(){
	   		bool firstSpace=false;
	   		int place=0;
	     while(!this->done){
		   recvfrom(this->client,charInBuffer,1,0, (SOCKADDR *)this->server->getSockAddr(),&this->size);				 
		   charCounter++;
				 if(((int)charInBuffer[0])==13){
				    lookForNextRL=true;
				}
				if(newLineCount==1&&lookForNextRL){
				break;
				}
				if(!firstSpace){
				  if(charInBuffer[0]==' '){
				  firstSpace=true;
				  place=charCounter;
				  }
				}else{
				 if(charInBuffer[0]==' '){
		            place=charCounter-place;
				 }
				}
				if(newLineCount==1&&((int)charInBuffer[0]!=10||(int)charInBuffer[0]!=13)){
				 newLineCount--;
				}
				 if(((int)charInBuffer[0])==10&&lookForNextRL){
				   newLineCount++;
				   		   charCounter=0;
				   lookForNextRL=false;
				   }
				 if(!saidMethod){
				    if(charInBuffer[0]==13){
								saidMethod=true;
								setResource((string)(inBuffer+'\n'),place);
					}
				}
				inBuffer+=(char)charInBuffer[0];
		 }
	   }
	   void setResource(string buffer,int counter){
	   		this->resource=(LPSTR)GlobalAlloc(GPTR,
                counter + 1);
	   		int i=0;
	   		int j=0;
	   		bool foundSpace=false;
	   		while(buffer[i]){
	   		if(foundSpace){
				if(buffer[i]==' ')
				   break;
			   else
	   		   	   this->resource[j]=buffer[i];
	   		   	   j++;
	   		}else{
	   			if(buffer[i]==' ')
	   			foundSpace=true;
			}
			i++;
			}
			this->resource[counter+1]=0;
	   }
	   LPSTR getResource(){
	    	 return this->resource;
	   }*/
	   void end(LPSTR data,int size){
	   		  sendto(this->client,data,size,0, (SOCKADDR *)this->server->getSockAddr(),this->size);
	   }
};
