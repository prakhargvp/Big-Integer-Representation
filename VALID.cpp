#include<iostream>
#include<regex>
using namespace std;
class VALID{
	public:
	VALID(){
		//string regex_str = "[a-z]";
		// regex_constants::icase =>  To ignore case
		// regex reg1(regex_str, regex_constants::icase);
	}	
	// isNumber
	template <typename T>
	int is_match(regex reg,T str){
		string S;
		//S = to_string(str);
		S = str;
		if(regex_match(S,reg)){
			return 1;
		}else{
			return 0;
		}

	}

	template <typename T>
	int isOperator(T str){
		regex reg("[*+-/]");
		return is_match<T>(reg,str);
	}
	
	template <typename T>
	int isNumber(T str){
		regex reg("[0-9]+");
		return is_match<T>(reg,str);
	}
	template <typename T>
	int isSingleSignNumber(T str){
		regex reg("[+-]?[0-9]+");	
		return is_match<T>(reg,str);
	}
	// 123*1231 = true
	// +12312/+123 = true

	template <typename T>
	int isSingleSignWithOperation(T str){
		regex reg("[+-]?[0-9]+[*/+-][+-]?[0-9]+");	
		return is_match<T>(reg,str);
	}

	template <typename T>
	int isMultiSignNumber(T str){
		regex reg("[+-]*[0-9]+");	
		return is_match<T>(reg,str);
	}
	// 123*1231 = true
	// ++--12312/+++123 = true

	template <typename T>
	int isMultiSignWithOperation(T str){
		regex reg("[+-]*[0-9]+[*/+-][+-]*[0-9]+");	
		return is_match<T>(reg,str);
	}
};
/*
int main(){
	VALID obj1;
	string str;
	cin >> str;
	cout << obj1.isMultiSignNumber(str) << endl;
	cout << obj1.isMultiSignWithOperation(str) << endl;
return 0;
}
*/
