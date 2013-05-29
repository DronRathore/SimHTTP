/*
  	HTTP Error renderer
*/
#define header_404 "HTTP/1.1 404 NOT FOUND\r\n"
#define header_200 "HTTP/1.1 200 OK\r\n"
#define header_301 "HTTP/1.1 301 MOVED PERMANENTLEY\r\n"
#define header_501 "HTTP/1.1 501 INTERNAL SERVER ERROR\r\n"
#define header_504 "HTTP/1.1 504 ACCESS DENIED\r\n"
#define _text_404 "Thats a 404!"
#define _text_501 "The Server get drowned!"
#define _text_504 "<h1>Forbidden Area!</h1>You are not supposed to be here, are you?"
LPSTR __e_404;
LPSTR __e_501;
LPSTR __e_504;
LPSTR __init__HTTPErrors(int code){
	  return new char[1];
}
