#include<iostream>
#include <algorithm>    // std::swap
#include<string.h>
using namespace std;
string reverse(string str,int len){
	int i;
	for(i=0;i<len/2;i++){
		char t=str[i];
		str[i]=str[len-1-i];
		str[len-1-i]=t;
	}
	return str;
}
string removeZero(string str){
	for(int i=0;i<str.size();i++){
		cout << str <<endl;
		if(str[i]=='0'){
			str.erase(str.begin()+i,str.begin()+i+1);
		}else{
			break;
		}
	}
return str;
}
int main(){
	unsigned long long len1,len2;
	string x,y,z;
	cin >> x >> y;
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

	cout << x <<endl;
	cout << y <<endl;
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

	z = reverse(z,z.size());
	z = removeZero(z);
	cout << z << endl;
return 0;
}
