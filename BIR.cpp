#include<iostream>
#include<bits/stdc++.h>
#include "VALID.cpp"
using namespace std;
class BIR{
	private: 
	string n1,n2,res;
	string op;	// operation
	int e;
	VALID val;
	public:
	// Declaration
	// Constructor
	BIR(){
		n1 = n2 = res = "";
		op = '+';
		VALID valObj;
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
	int read(string);
	int read(string,string,string);
	// To Trim Zero's from the front of answer
	string removeZero(string);
	// To return output result
	string result();
	//
	void initOperation();		
	//
	void split(string);
	//
	bool validation();
	// Resolve Sign
	string resolveSign(string);
	//
	void operation(string);
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
int BIR::read(string str){

	try{
		if(!val.isMultiSignWithOperation(str)){throw 0;}
		split(str);
	}catch(int e){
		cout << "Invalid String :" << endl;	
		return 0;
	}
return 1;
}

void BIR::initOperation(){
	// Validity of Number
	// resolve the signs
}
void BIR::split(string str){
	// split number1 operation number2
	string::iterator it1= str.begin();
	VALID val;
	// 1 2 3
	int flag=1;
	n1 = n2 = "";
	while(it1!=str.end()){
		if(flag==1){
			n1 += *it1;	
		}else if(flag==2){
			op = *it1;		
			flag = 3;
		}else if(flag==3){
			n2 += *it1;	
		}
		if(val.isNumber(*it1)==1 && val.isOperator(*(it1+1))==1){
			flag = 2;
		}
		// Copy the content in the respective string/variable
		it1++;
	}
}
bool BIR::validation(){

}
// Operation
void BIR::operation(string opr){
	op = opr;
}
//
string resolveSign(string str){
}
// Result
string BIR::result(){
	try{
		if(op=="-"){
			subtraction();
		}else if(op=="+"){
			addition();
		}else if(op=="*"){
			multiplication();
		}else{
			throw 0;

		}
	}catch(int e){
		cout << "No Operation Selected." << endl;	
	}
	return res;
}
// Addition Function
void BIR::addition(){
	n1 = "+12311231231";
	n2 = "+12312313";
// Addition Logic goes here
	char ch1,ch2,ch;
	int rem=0;
	if(n1.length()<n2.length())
		swap(n1,n2);
	if((n1[0]=='+' && n2[0]=='-')||(n1[0]=='-' && n2[0]=='+'))
		subtraction();
	else{		
		while(n2.length()!=1){
			ch1=n1.back();
			ch2=n2.back();
			ch=ch1+ch2-'0'+rem;
			if(ch>'9'){
				rem=1;
				ch-=10;
			}
			else rem=0;
			//cout << ch << " ";
			res+=ch;
			n1.pop_back();
			n2.pop_back();
		}
		if(n1.length()!=n2.length()){
			while(n1.length()!=1){
				ch=n1.back();
				if(ch=='9' && rem==1)
					res+='0';
				else{
					res+=ch+rem;
					rem=0;	
				}
				n1.pop_back();
			}
		}
		if(rem!=0)
			res+='1';
		reverse(res.begin(),res.end());
		res=n1[0]+res;
		cout << res;
	}
}

string BIR::removeZero(string str){
	int i = 0;
	while(i<str.size()){
		//cout << str <<endl;
		if(str[0]=='0'){
		//		cout << str[i] << endl;
			str.erase(str.begin()+i,str.begin()+i+1);
		//	cout << "After erase" <<str <<endl;
		}else{
			break;
		}
	}
	return str;
}

// Multiplication Function
void BIR::multiplication(){
	n1 = "-12311231231";
	n2 = "+12312313";
	// Multiplication Logic goes here
	
}
// Subtraction Function
void BIR::subtraction(){
	n1 = "+12311231231";
	n2 = "-12312313";

	// [0] for sign
	string::iterator itx=n1.begin() + 1;
	string::iterator ity=n2.begin() + 1;

	// calculate output sign
	if(n1[0]!='+' && n1[0]!='-'){
		n1 = '+' + n1;
	}
	if(n2[0]!='+' && n2[0]!='-'){
		n2 = '-' + n2;
	}
	/*
	else if(n2[0] == '-'){
		n2[0] = '+';
	}
	*/
	// x is greater or equal to y
	// swap if x is smaller
	if(n2.size()>n1.size()){
		swap(n1,n2);
	}else if(n1.size()==n2.size()){
		
		while(*itx == *ity && itx!=n1.end()){
			itx++;
			ity++;
		}
		if(*itx < *ity){
			// Code for swap
			// x is greater & y is smaller
			swap(n1,n2);	
		}
	}

	//cout << x <<endl;
	//cout << y <<endl;
	// If Both are +ve then go for addition	
	// If Both are -ve then also go for addition
	// If one of them are -ve then go for subtraction
	// Subtraction logic

	int borrow=0;
	char a, b;
	
	itx = n1.end() - 1;
	ity = n2.end() - 1;

	if((n1[0]=='+' && n2[0]=='+')|| (n1[0]=='-' && n2[0]=='-')){
		cout << "Addition Code" << endl;
	}
	else{
		while(ity!=n2.begin()){

			b = (*ity);
			a = (*itx);		

			if(a < b){
				*(ity - 1) += 1;
				a += 10;
				if(ity == n2.begin()+1){
					borrow = 1;
				}
			}
			a = a - b + '0';
			res = res + a;

			--itx;
			--ity;
		}
		while(itx!=n1.begin()){
			a = *itx;
			if(borrow){
				if(a=='0'){
					a = '9';
				}else{
					a = a - 1;			
					borrow = 0;
				}
			}	
			res = res + a;	
			--itx;
		}

		reverse(res.begin(),res.end());
		res = removeZero(res);
		res =  n1[0] + res;
	}
}
