#include<iostream>
#include<string>
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

void print(string str,int len){
	for(int i=0;i<len;i++)
		cout << str[i];
}

int main(){
	string num1,num2;
	cin >> num1 >> num2;
	int len1=num1.length(),i=0,a;
	int len2=num2.length(),rem=0;
	num1=reverse(num1,len1);
	num2=reverse(num2,len2);
	if(len1>len2){
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
		num1=reverse(num1,len1);
		print(num1,len1);
	}
	else if(len1<len2){
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
		num2=reverse(num2,len2);
		print(num2,len2);
	}
	else{
		for(i=0;i<len2;i++){
			a=(num1[i]-'0')+(num2[i]-'0')+rem;
			rem=a/10;
			num1[i]=((a%10)+'0');
		}
		if(rem!=0){
			cout << rem;
		}
		num1=reverse(num1,len1);
		print(num1,len1);
	}
	return 0;
}
