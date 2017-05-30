#include<iostream>
#include<bits/stdc++.h>
#include "CONTROL.cpp"
#include "VALID.cpp"
#include "ERRORH.cpp"
using namespace std;
class BIR{
	private: 
	string n1,n2,res,inlineStr;
	string op;	// operation
	int e;
	VALID val;	// Validation Object
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
	// To read input from user
	int input();
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

	void resolveSign();
	string resolveSign(string);
	//o
	void firstBig();
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
int BIR::input(){
	
}
int BIR::read(string str1,string str2,string op1){
	try{
		n1 = str1;
		n2 = str2;
		op = op1;
		//1. validation
		//2. resolve sign
		//3. first numebr is greate or equal to second
		initOperation();

	}catch(ERRORH err){
		err.print();	
	}
}
int BIR::read(string str){

	try{
		inlineStr = str;
		if(!val.isMultiSignWithOperation(str)){
			throw ERRORH("Not Valid String : ");
		}
		// split string into 3 strings
		// number1 operation number2
		split(str);
		//1. validation
		//2. resolve sign
		//3. first numebr is greate or equal to second
		initOperation();
	}catch(ERRORH err){
		err.print();
		return 0;
	}
return 1;
}

void BIR::initOperation(){
	// Validity of Number
	validation();
	// resolve the signs
	resolveSign();
	// first number be greate than or equal to second one
	firstBig();
}
bool BIR::validation(){
	try{
		// To detect input type
		// 1. single line 
		// 2. multi-line
		// To detect input number type
		// 1. No sign / single sign
		// 2. No sign / multi sing
		if(MULTILINE_INPUT==true){
				
		}

		if(!val.isMultiSignNumber(n1)){
			throw ERRORH("Num1 is Not Valid");	
		}	
		if(!val.isMultiSignNumber(n2)){
			throw ERRORH("Num2 is Not Valid");	
		}
		if(!val.isOperator(op)){
			throw ERRORH("Operator is not Valid");	
		}

	}catch(ERRORH err){
		err.print();	
	}

}
void BIR::resolveSign(){
	n1 = resolveSign(n1);
	n2 = resolveSign(n2);
}
string BIR::resolveSign(string str){
	string::iterator it1;
	it1 = str.begin();
	char op1='+';
	while(it1!=str.end() && (*it1=='+' || *it1=='-')){

		if((*it1=='-' && op1=='+') || (*it1=='+' && op1=='-')){
			op1 = '-';	
		}else{
			op1 = '+';
		}	
		it1++;
	}
	str = op1 + string(it1, str.end());
return str;
}
void BIR::firstBig(){
	try{
		string::iterator itx=n1.begin() + 1,ity=n2.begin() + 1;

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
	}catch(...){
	
	}
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

// Operation
void BIR::operation(string opr){
	op = opr;
}
//
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
// Result
string BIR::result(){
	try{
		int ms=0;
		if(op=="-"){	ms++;	}
		if(n2[0]=='-'){	ms++;	}
		if(n1[0]=='-'){	ms++;	}

		if((op=="+" || op=="-" ) && ms%2!=0){
			subtraction();
		}else if(op=="+" || op=="-"){
			addition();
		}else if(op=="*"){
			multiplication();
		}else{
			throw ERRORH("No Operation is Selected.");

		}
	}catch(ERRORH err){
		err.print();
	}
	return res;
}

// Addition Function
void BIR::addition(){
	// Addition Logic goes here
	char ch1,ch2,ch;
	int rem=0;
		string::iterator itx=n1.end()-1,ity=n2.end()-1;
		while(ity!=n2.begin()){
			ch1=(*itx);
			ch2=(*ity);
			ch=ch1+ch2-'0'+rem;
			if(ch>'9'){
				rem=1;
				ch-=10;
			}
			else rem=0;
			//cout << ch << " ";
			res+=ch;
			--itx;
			--ity;
		}
		while(itx!=n1.begin()){
			ch=(*itx);
			if(ch=='9' && rem==1)
				res+='0';
			else{
				res+=ch+rem;
				rem=0;	
			}
			--itx;
		}
		if(rem!=0)
			res+='1';
		reverse(res.begin(),res.end());
		res=n1[0]+res;
}



// Multiplication Function
void BIR::multiplication(){
	// Multiplication Logic goes here
	string::iterator it1,it2, itr, itrt;
	int rem, mul, carry, a, b;

	it2 = n2.end() - 1;
	res = "0";
	// Number of Digits in Product of two numbers, A & B
	// = Floor (Log (A) + Log(B)) + 1
	// pre determine the size of result in multiplication
	// because resize in mid of program might invalidate all iterators pointing into the vector.
	res.resize( n1.size() + n2.size() + 1 ,'0');

	itr = res.begin();
	
	while(it2!=n2.begin()){
        	it1 = n1.end() - 1;	
		carry = 0;
		//res = "";
		itrt = itr;
		while(it1!=n1.begin()){	
			a = (*it1 - '0');
			b = (*it2 - '0');
			mul = a * b + carry;
			if(it2!=n2.end()-1){
				mul += (*itrt - '0');
			}

			rem = mul%10;
			carry = mul/10;
			(*itrt) = rem + '0'; 	
		--it1;
		++itrt;
		}
		while(carry>0){
			a = *itrt - '0' + carry;
			(*itrt) = a + '0';	
			carry = a/10;
		++itrt;
		}
		itr++;
	--it2;	
	}
	reverse(res.begin(),res.end());
	res = removeZero(res);
	if((n1[0]=='-' && n2[0]=='-') || (n1[0]=='+' && n2[0]=='+')){
		res = '+' + res;
	}else{
		res = '-' + res;
	}
}

// Subtraction Function
void BIR::subtraction(){

	int borrow=0;
	char a, b;
	
		string::iterator itx=n1.end() - 1,ity=n2.end() - 1;

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
