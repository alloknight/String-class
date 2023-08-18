#include <iostream>
class String{
	private:
		char* value;
		int length;
	public:
		String():value(nullptr),length(0){
			value= new char[1];
			value[0]= '\0';
	       	}
		String(const char* str):value(nullptr),length(0){
			length = strlen(str);
			value = new char[length +1];
			strcpy(value,str);		
		}

		String(const String& s):value(nullptr),length(0){
			length = s.getLength();
			value = new char[length+1];
			strcpy(value,s.getValue());
		}
		~String(){
			delete[] value;
		}

		
		static void strcpy(char* destination,const char* original){
			int length = strlen(original);
			for(int i =0;i<length+1;i++){
				destination[i] = original[i];
			}
		
		}
		static int strlen(const char* str){
			int result =0;
			while (*str != '\0'){
				result++;
				str++;
			}
			return result;
		}
		void print() const{
			for(int i=0; i<length;i++){
				std::cout << value[i];	
			}
			std::cout<< std::endl;
		}
		char* getValue() const{return value;}
		int getLength() const{return length;}
		
		String operator=(const String& str){
			if(this != &str){
				delete[] value;
				length = str.getLength();
				value = new char[length+1];
				strcpy(value,str.getValue());
			}
			return *this;
		
		}

		String operator+(const String& str) const{
			int resLength = length+ str.getLength();
			char* resValue = new char[resLength +1];
			strcpy(resValue,value);
			for(int i = length, j =0; i< resLength+1; i++,j++){
				resValue[i]=str.getValue()[j];
			}
			String result(resValue);
			return result;
		
		
		}

};
int main() {
    String s1 = "Hello, ";
    String s2 = "world!";
    String s3 = s1 + s2;

    s1.print();
    s2.print();
    s3.print();

    return 0;
}






