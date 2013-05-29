class File{
	FILE *f;
	bool code;
	bool isEmpty;
	char* data;
	DWORD dwFileSize;
	HANDLE hFile;
	LPSTR pszFileText;
public:
	File(LPSTR fname){
		hFile= hFile = CreateFile(fname, GENERIC_READ, FILE_SHARE_READ, NULL,
      	OPEN_EXISTING, 0, 0);
      	 if(hFile != INVALID_HANDLE_VALUE)
   		 {
      	  		  dwFileSize = GetFileSize(hFile, NULL);
				  if(dwFileSize != 0xFFFFFFFF)
      			  {
  				   				this->code=true;
  				   				isEmpty=false;
				 	}
		else{
			 isEmpty=true;
		}
		}else{
			this->code=false;
			returnError(false);
		}
	}
	int size(){
		return dwFileSize;
	}
	bool returnError(int code){
		return code;
	}
	int canRead(){
		return this->code;
	}
	void free(){
 	HeapFree(GetProcessHeap(), 0, pszFileText);
 	delete pszFileText;
 	delete this;
 	}
	LPSTR read(){
		if(this->code){
           if(this->isEmpty){
		   		pszFileText = (LPSTR)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY,
                2);
				pszFileText[1] = 0;
		   			return	pszFileText;	   	
			  }
  		pszFileText = (LPSTR)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY,
                dwFileSize + 1);
  		 DWORD dwRead;
            if(ReadFile(hFile, pszFileText, dwFileSize, &dwRead, NULL))
            {
               pszFileText[dwFileSize] = 0;
            }
		CloseHandle(hFile);
		return pszFileText;
	}
}
~File(){
		HeapFree(GetProcessHeap(), 0, pszFileText);
}
};
