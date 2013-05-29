/*
  	Mime Type Handler
*/
#define _mime_html "text/html"
#define _mime_css "text/css"
#define _mime_js "application/javascript"
#define _mime_png "image/png"
#define _mime_jpg "image/jpeg"
#define _mime_gif "image/gif"
typedef struct ml{
	   string extension;
	   string mimeType;
	   struct m1 *nextMime;
}mimeNode,*mimeList;
class Mimes{
private:
		mimeList MimeList;
		LPSTR pszFileText;
		HANDLE hFile;
		DWORD dwFileSize;
		int cursor;
		string line;
		File *mimeFile;
		bool insideComment;
public:
	  Mimes(LPSTR fileName){
	  		mimeFile=(new File(fileName));
	  		this->line="";
	  		if(mimeFile->canRead()){
				pszFileText=mimeFile->read();
				this->cursor=0;
				this->dwFileSize=mimeFile->size();
				this->parse();
			}
	  }
private:
		void parse(){
	  		 this->cursor=0;
	  		 while(this->cursor<dwFileSize){					
				  this->readNextLine();
			 }
			 this->mimeFile->free();
	  	}
	  	string readNextLine(){
			   this->line="";
			   insideComment=false;
			   while(this->pszFileText[cursor]!='\n'){
			   	if(this->pszFileText[cursor]=='#')
					  insideComment=true;
				if(!insideComment)
			   	this->line+=this->pszFileText[cursor];
			   	cursor++;
				}
				cursor++;
				return this->line;
		}
};
