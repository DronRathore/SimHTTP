#include <iostream>
#define WSOCK_ERROR "WSAStartup Failure for version 2.2"
#define SOCK_ERROR "Socket initialisation failed!"
#define BIND_FAILURE "Bind Failure"
#define THREAD_INIT "Thread Initialisation Failed"
using namespace std;
class Error{
public:
	Error(const char *text){

		MessageBox(NULL,text,"Exception!",MB_ICONEXCLAMATION|MB_OK);
		cout<<"Exception: "<<text;
	}
	Error(int code){
		MessageBox(NULL,"Error code: "+code,"Exception!",MB_ICONEXCLAMATION|MB_OK);
		cout<<"Exception: "<<code;
	}
};
