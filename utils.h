/*
	Utils.h
*/

class integer{
	int value;
	int dump_len;
	int dump_num;
public:
	int parseInt(char* number){
			this->dump_len=0;
			int dummy=0;
			int counter=1;
			int num=0;
			int multiplier=1;
			if(number){
				dump_len=strlen(number);
				while(true){
					if(counter<=dump_len){
						num=convertAsciiToNumeric(number[dump_len-counter]);
						multiplier=power(multiplier,(counter>2?counter-1:1));
						if(num!=-1){
							dummy+=num*multiplier;
							counter++;
							multiplier=10;
						}
					}else{
						break;
					}
				}
				dump_len=dummy;
				return dump_len;
			}
			return -1;
		}
		int convertAsciiToNumeric(char number){
			/*
				The integer range is 48 to 57
			*/
			this->dump_num=0;
			this->dump_num=(int)number;
			if(this->dump_num>=47||this->dump_num<=57){
				this->dump_num=58-this->dump_num;
				this->dump_num=10-this->dump_num;
				return this->dump_num;
			}
			return -1;
		}
		int power(int n,int raiseTo){
			int copyOfN=n;
			while(raiseTo>1){
				n=n*copyOfN;
				raiseTo--;
			}
			return n;
		}
};
integer Integer;
class File{
	FILE *f;
	char *TEMP_NAME;
	int cursor;
	bool code;
	char* data;
public:
	File(char *fname,char *mode){
		cursor=0;
		this->data=new char[500];
		this->TEMP_NAME=new char[500];
		if((this->f=fopen(fname,mode))!=NULL){
			this->code=true;
			this->TEMP_NAME=this->f->_tmpfname;
		}
		else{
			this->code=false;
			returnError(false);
		}
	}
	char *tempName(){
		return this->TEMP_NAME;
	}
	bool returnError(int code){
		return code;
	}
	int canRead(){
		return this->code;
	}
	int read(){
		fread(data,100,20,this->f);
		std::cout<<data;
	}
};

