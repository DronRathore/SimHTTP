#include <cstdlib>
#include <iostream>
#include <string.h>
#include <windows.h>
#include <winsock2.h>
#include "Error.h"
#include "serverSocket.h"
#include "Threads.h"
using namespace std;
void shutDown(void);
Server server(1880,true);
int main(int argc, char *argv[])
{	myThread *Client=NULL;
 	atexit(shutDown);
	while(true){
	Socket client=server.hear();
	Client=new myThread(client,&server);
	}
	server.close();
    return EXIT_SUCCESS;
}
void shutDown(void){
	 server.close();
	 cout<<"\n + Server closed at user stroke";	 
}
