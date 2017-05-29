
#include<iostream>
#include "BIR.cpp"
using namespace std;
int main(){
	BIR obj1;
	string str;
	cin >> str;
	if(obj1.read(str)){
		obj1.operation("-");
		cout << obj1.getNum1() << endl;
		cout << obj1.getNum2() << endl;
		cout << obj1.result() << endl;
	}
return 0;
}
