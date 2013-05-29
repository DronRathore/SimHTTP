#define WSOCK_VER_NOT_FOUND "WSOCK_VER_NOT_FOUND:Winsock Version 2.2 Required"
#define INVALID_PORT_TO_BIND "INVALID_PORT_TO_BIND:Port number should be greater than 10"
#define BIND_FAILURE "BIND_FAILURE: Cannot Bind to the defined port."
#define LISTEN_FAILURE "LISTEN_FAILURE: Cannot Listen on the defined port, port in use or permision denied."
#define SOCKET_CREATION_FAILED "SOCKET_CREATION_FAILED: Could'nt Create Socket!"
#define ACCEPT_ERROR "ACCEPT_FAILURE: Can't Accept Connection from client, check for proper priviliges."
typedef const char* Text;
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
