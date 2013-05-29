HANDLE mutexClientThreadExecutionHandler=CreateMutex(NULL,false,NULL);
class Thread{
private:
HANDLE self;
DWORD ThreadId;
Thread *ref;
void (*threader)(Thread*);
public:
	HANDLE getHandler(){return this->self;}
	void start(void (*function)(Thread*)){
		if(function!=NULL){ 
			threader=function;
			this->_start();
		}
	}
	void _start(){
		self=CreateThread(NULL,0,
		(LPTHREAD_START_ROUTINE)threader,
		this->ref,
		0,
		&this->ThreadId
		);
		if(self==NULL){
			new Error(THREAD_INIT);
		}
	}
	void setObject(Thread * ref){
 			this->ref=ref;
 }
 virtual void run(){}
};
class myThread:public Thread{
private:
Socket client;
Server *server;
char* pszFileText;
Client* response;
LPSTR data;
int size;
public:
myThread(Socket client,Server* server){
		this->server=server;
		this->client=client;
		pszFileText=new char[1200];
		setObject((Thread*)this);
		start(&this->_run);
}
static void _run(Thread* ref){
	  WaitForSingleObject(mutexClientThreadExecutionHandler,INFINITE);
	  myThread *pointer=(myThread*)ref;
	  ref->run();
	 ExitThread(1);
}
void run(){
	 ReleaseMutex(mutexClientThreadExecutionHandler);
	System.log("Request Recieved");
	 File f("server.h");
	 if(f.canRead()){
	 	System.log("Sending Data");
	     SetThreadPriority(this->getHandler(),1);
	     this->data=f.read();
	     this->size=f.size();
	 	 sendto(this->client,data,size,1, (SOCKADDR *)this->server->getSockAddr(),this->size);
	 	 closesocket(this->client);
	 }
	 ExitThread(1);
}
};
