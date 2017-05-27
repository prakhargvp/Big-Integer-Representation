#include <iostream>
#include<bits/stdc++.h>
using namespace std;



string removeZero(string str){
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

void subtraction(string x,string y){
	unsigned long long len1,len2;
	string z;
	
	// [0] for sign
	string::iterator itx=x.begin() + 1;
	string::iterator ity=y.begin() + 1;

	// calculate output sign
	if(x[0]!='+' && x[0]!='-'){
		x = '+'+x;
	}
	if(y[0]!='+' && y[0]!='-'){
		y = '-'+y;
	}else if(y[0]=='-'){
		y[0] = '+';
	}
	// x is greater or equal to y
	// swap if x is smaller
	if(y.size()>x.size()){
		swap(x,y);
	}else if(x.size()==y.size()){
		
		while(*itx == *ity && itx!=x.end()){
			itx++;
			ity++;
		}
		if(*itx < *ity){
			// Code for swap
			// x is greater & y is smaller
			swap(x,y);	
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
	
	itx = x.end() - 1;
	ity = y.end() - 1;

	if((x[0]=='+' && y[0]=='+')|| (x[0]=='-' && y[0]=='-')){
		cout << "Addition Code" << endl;
	}
	else{
		while(ity!=y.begin()){

			b = (*ity);
			a = (*itx);		

			if(a < b){
				*(ity - 1) += 1;
				a += 10;
				if(ity == y.begin()+1){
					borrow = 1;
				}
			}
			a = a - b + '0';
			z = z + a;

			--itx;
			--ity;
		}
		while(itx!=x.begin()){
			a = *itx;
			if(borrow){
				if(a=='0'){
					a = '9';
				}else{
					a = a - 1;			
					borrow = 0;
				}
			}	
			z = z + a;	
			--itx;
		}

		reverse(z.begin(),z.end());
		z = removeZero(z);
		cout << x[0] << z << endl;
	}
}
int main(){
	string s1,s2;
	cin >> s1 >> s2;
	subtraction(s1,s2);
return 0;
}
