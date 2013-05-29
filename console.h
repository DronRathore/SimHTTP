/*
  	Synchronous Console printing class
*/
#include <iostream>
using namespace std;
typedef SOCKET Socket;
HANDLE consoleIOSyncMutexHandler=CreateMutex(NULL,false,NULL);
template<class T,class V>class console{
public:
	   static bool log(T input,V type){
 	   		WaitForSingleObject(consoleIOSyncMutexHandler,INFINITE);
	   		if(cout<<input<<type<<endl){
			   ReleaseMutex(consoleIOSyncMutexHandler);
			   return true;
			}
 		    else{
				 ReleaseMutex(consoleIOSyncMutexHandler);
 		    	 return false;
			}
			ReleaseMutex(consoleIOSyncMutexHandler);
	   }
};
class _sys{
public:
std::string sys_in_read;
	   _sys(){
			  sys_in_read="";
		}
	   bool log(string input){
	   		fflush(stdout);
	   		  WaitForSingleObject(consoleIOSyncMutexHandler,INFINITE);
	   		  cout<<input<<endl;
	   		  fflush(stdout);
	   		  ReleaseMutex(consoleIOSyncMutexHandler);
	   }
	   string read(){
  		   sys_in_read="";
	   	   WaitForSingleObject(consoleIOSyncMutexHandler,INFINITE);
	   	   fflush(stdin);
		   cin>>sys_in_read;
		   ReleaseMutex(consoleIOSyncMutexHandler);
		   return sys_in_read;
	   }
};
_sys System;
