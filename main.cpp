#include <cstdlib>
#include <winsock2.h>
#include <iostream>
#include <windows.h>
#include <assert.h>
#include "errors.h"
#include "config.h"
#include "server.h"
using namespace std;
template <class ErrorDescription>
class Error{
private:
        ErrorDescription description;
        bool isCritical;
public:
       Error(ErrorDescription desc,bool isCritical=false){
                   this->description=desc;
                   this->isCritical=isCritical;
                   if(isCritical)
                   this->getDescription();
       }
       ErrorDescription getDescription(){
             if(this->isCritical){
             cout<<this->description;
              WSACleanup();
             exit(0x00);
             }
             return this->description;
       }
};
Server ServerSocket;
int main(int argc, char *argv[])
{   //System::Configuration Configuration=*(new System::Configuration());
       string a;
       a="Hello World";
       cout<<a;
    Server ServerSocket=*(new Server());
    ServerSocket.start();
    system("Pause");
    ServerSocket.close();
    return EXIT_SUCCESS;
}
