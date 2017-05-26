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
	int is_match(regex reg,string str){
		if(regex_match(str,reg)){
			return 1;
		}else{
			return 0;
		}

	}
	int isNumber(string str){
		regex reg("[0-9]*");
		return is_match(reg,str);
	}

	int isMultiSignNumber(string str){
		regex reg("[+-]*[0-9]*");	
		return is_match(reg,str);
	}
	// 123*1231 = true
	// ++--12312/+++123 = true

	int isMultiSignWithOperation(string str){
		regex reg("[+-]*[0-9]*[*/+-][+-]*[0-9]*");	
		return is_match(reg,str);
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
