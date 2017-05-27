
#include<iostream>
#include "VALID.cpp"
#include "BIR.cpp"
using namespace std;
int main(){
	BIR obj1;
	obj1.read("100000000+1000");
	cout << obj1.getNum1() << endl;
	cout << obj1.getNum2() << endl;
	obj1.subtraction();
return 0;
}
