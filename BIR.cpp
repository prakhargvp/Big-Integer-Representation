#include<iostream>
using namespace std;
class BIR{
	private: 
	string n1,n2,res;
	char op;	// operation
	public:
	// Declaration
	// Constructor
	BIR(){
		n1 = n2 = res = "";
		op = '+';
	}
	BIR(string str){
		// To split str into 2 numbers	
		op = '+';
	}
	BIR(string a, string b){
		n1 = a;
		n2 = b;
		op = '+';
	}
	// To read input from main
	void read(string);
	void read(string,string);
	// To return output result
	string output();
	//
	void initOperation();		
	//
	void split(string);
	//
	bool validation();
	//
	void addition();
	//
	void subtraction();
	//
	void multiplication();
	// 
	string getNum1();
	string getNum2();
};
string BIR::getNum1(){
	return n1;
}
string BIR::getNum2(){
	return n2;
}
void BIR::read(string str){
	split(str);
}

void BIR::initOperation(){
	// Validity of Number
	// resolve the signs
}
void BIR::split(string str){
	// split number1 operation number2
}
bool BIR::validation(){

}
