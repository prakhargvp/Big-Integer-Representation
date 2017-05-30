#include<iostream>
#include "BIR.cpp"
using namespace std;
int main(){
	BIR obj1;
	if(obj1.input()){
		//obj1.operation("-");
		cout << obj1.getNum1() << endl;
		cout << obj1.getNum2() << endl;
		cout << obj1.result() << endl;
	}else{
		cout << "Invalid Input" << endl;
	}
return 0;
}
