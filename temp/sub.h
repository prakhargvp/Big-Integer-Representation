#include <iostream>
#include <string>
#include <algorithm>    // std::swap
#include "fun.h"
#include "add.cpp"
using namespace std;

void subtraction(string x,string y){
	unsigned long long len1,len2;
	string z;
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
		int i,j;
		i = 1;
		j = 1;
		while(x[i]==y[j] && i<x.size()){
			i++;
			j++;
		}
		if(x[i]<y[j]){
			// Code for swap
			// x is greater & y is smaller
			swap(x,y);	
		}
	}

	len1 = x.size();
	len2 = y.size();

	//cout << x <<endl;
	//cout << y <<endl;
	// If Both are +ve then go for addition	
	// If Both are -ve then also go for addition
	// If one of them are -ve then go for subtraction
	// Subtraction logic

	int i,j,k;
	int borrow=0;
	char a, b;
	i = len1-1;
	j = len2-1;
	k = 0;
	if((x[0]=='+' && y[0]=='+')|| (x[0]=='-' && y[0]=='-')){
		addition(x,y);
	}
	else{
		while(j>0){
			a = x[i];		
			b = y[j];
			if(a < b){
				y[j-1] += 1;
				a += 10;
				if(j==1){
					borrow = 1;
				}
			}
			a = a - b + '0';
			z = z + a;
			//cout << a << endl;
			i--;
			j--;
		}
		while(i>0){
			a = x[i--];
			if(borrow){
				if(a=='0'){
					a = '9';
				}else{
					a = a - 1;			
					borrow = 0;
				}
			}	
			z = z + a;	
		}

		z = reverse(z);
		z = removeZero(z);
		cout << x[0] << z << endl;
	}
}
