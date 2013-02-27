#include <iostream>
using namespace std;
 typedef struct LA{
  string name;
	string value;
	struct LA* next;
}link_array;
/*
	The String Class to extend the features provided by the
	inbuilt std::string
*/
class String{
	private:
		string self;
	public:
		String(char *character){
			this->self=character;
		}
		String(const char* characters){
			this->self=characters;
		}
		string getValue(){
			return this->self;
		}
		String operator <<(String a){
			string temp=this->getValue();
			cout<<temp;
			delete (&temp);
		    return *this;
            }
		void operator >>(istream in){
		
		}
		int getLength(){
            
            return 1;
        }
};
/*
	A JAVA type mimic System namespace
	
*/
namespace System{
	using namespace std;
	class Thread{
		HANDLE h;
		
	
	};
	class Configuration{
		private:
			Text file_name;
			Text paths[];
			public:
				Configuration(){cout<<"Created\n";}
			
	};
	class out{
		private:
			bool working;
		public:
			int println(char *string){
				if(this->working)
					return false;
				else
					this->working=true;
					cout<<string;
					this->working=false;
				return strlen(string);
			}
			int println(String string){
				if(this->working)
					return false;
				else
					this->working=true;
					cout<<string;
					this->working=false;
				return string.getLength();
			}			
			
	};
	namespace Util{
		class StringArray{
			private:
				link_array *head;
				link_array *current;
			public:
				StringArray(){
					link_array *new_node=(link_array*)(malloc(sizeof(link_array)));
					new_node->next=NULL;
					head=new_node;
					current=head;
				}
				void add(Text in){
					
				}
				Text explode(Text in){
					
				}
		};
	}
}
/*
namespace Listener{
	class Thread{
	char *request
	
	};
}*/

