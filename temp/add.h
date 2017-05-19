#include <iostream>
#include <string>
#include <algorithm>    // std::swap
#include "fun.h"
#include "sub.cpp"
using namespace std;

void addition(string num1,string num2){
	int len1=num1.length(),i=0,a,len2=num2.length(),rem=0,s1=1,s2=1,r_sign=1;
	if(len1==len2){
		int i,j;
		i = 1;
		j = 1;
		while(num1[i]==num2[j] && i<num1.size()){
			i++;
			j++;
		}
		if(num1[i]<num2[j]){
			// Code for swap
			// x is greater & y is smaller
			swap(num1,num2);	
		}
	}
	if(num1[0]=='-')
		s1=-1;
	if(num2[0]=='-')
		s2=-1;
	if(num1[0]=='+'||num1[0]=='-')
		num1[0]=0;
	if(num2[0]=='+'||num2[0]=='-')
		num2[0]=0;
	num1=reverse(num1);
	num2=reverse(num2);
	if(len1>len2){
		if(s1==-1)
			cout << "-";
		else
			cout << "+";
		if(s1*s2>0){
			for(i=0;i<len2;i++){
				a=(num1[i]-'0')+(num2[i]-'0')+rem;
				rem=a/10;
				num1[i]=((a%10)+'0');
			}
			while(i<len1){
				a=(num1[i]-'0')+rem;
				rem=a/10;
				num1[i]=((a%10)+'0');
				i++;
			}
			if(rem!=0){
				cout << rem;
			}
			num1=reverse(num1);
			print(num1);
		}
		else{
			subtraction(num1,num2);
		}
	}
	else if(len1<len2){
		if(s1==-1)
			cout << "+";
		else
			cout << "-";
		if(s1*s2>0){
			for(i=0;i<len1;i++){
				a=(num1[i]-'0')+(num2[i]-'0')+rem;
				rem=a/10;
				num2[i]=((a%10)+'0');
			}
			while(i<len2){
				a=(num2[i]-'0')+rem;
				rem=a/10;
				num2[i]=((a%10)+'0');
				i++;
			}
			if(rem!=0){
				cout << rem;
			}
			num2=reverse(num2);
			print(num2);
		}
		else{
			subtraction(num1,num2);
		}
	}
	else{
		if(s1*s2>0){
			for(i=0;i<len2;i++){
				a=(num1[i]-'0')+(num2[i]-'0')+rem;
				rem=a/10;
				num1[i]=((a%10)+'0');
			}
			if(rem!=0){
				cout << rem;
			}
			num1=reverse(num1);
			print(num1);
		}
		else{
			subtraction(num1,num2);
		}
	}
}
