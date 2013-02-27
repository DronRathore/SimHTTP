/*
    The Server Class
*/
class Server{
private:
        int port,Socket_Size;
   bool TERMINATE;
        SOCKET Socket;
        SOCKADDR_IN Server_Socket;
        WSADATA WsaData;
SOCKET Client;
public:

         Server(int port=6666){
                    this->port=0;
                    this->TERMINATE=false;
                try{
                     if(port<=10||WSAStartup(MAKEWORD(2,2),&this->WsaData)!=0)
                           throw *(new Error<Text>(port<=10?INVALID_PORT_TO_BIND:WSOCK_VER_NOT_FOUND,true));
                     else
                         this->port=port;
                         this->_init();
                    }catch(Error<Text> e){
                                   cout<<e.getDescription()<<endl;
                    }
         
        }
        
         private:
                 void _init(){
                    try{
                        this->Socket=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
                        if(this->Socket==-1)
                             throw *(new Error<Text>(SOCKET_CREATION_FAILED,true));
                        else
                           this->Server_Socket.sin_port=htons(this->port);
                           this->Server_Socket.sin_family=AF_INET;
                           this->Server_Socket.sin_addr.s_addr=INADDR_ANY;
                    }catch(Error<Text> e){}
         }
        public:
               void start(){
                    try{ this->Socket_Size=sizeof(this->Server_Socket);
                        if(bind(Socket,(SOCKADDR *)&this->Server_Socket,sizeof(this->Server_Socket))==SOCKET_ERROR)
                             throw *(new Error<Text>(BIND_FAILURE,true));
                            else if(listen(Socket,25)==SOCKET_ERROR)
                                   throw *(new Error<Text>(LISTEN_FAILURE,true));
                                  // while(!this->TERMINATE){
                                            Client=accept(Socket,(SOCKADDR *)&this->Server_Socket,&this->Socket_Size);
                                    char *buffer=new char[1200];
                                    while(recvfrom(Client,buffer,1200,0,(SOCKADDR *)&this->Server_Socket,&this->Socket_Size)){
                                        cout<<buffer<<endl;
                                        
                                      /* if(((int)buffer[0]==13)
&&((int)buffer[1]==10)
&&((int)buffer[2]==13)
&&((int)buffer[3]==10))
break;
if(((int)buffer[0]==10))
break;
*/
                                        }
                                        
                                   //}
                       }catch(Error<Text> e){}
                    }
               
               void close(){
                    WSACleanup();
                    closesocket(this->Socket);
              }
};
