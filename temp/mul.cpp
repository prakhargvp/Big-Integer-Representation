#include<iostream>
#include<string>
#define MAX 1000000
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
	int pro[MAX]={0},s1=1,s2=1;
	cin >> num1 >> num2;
	if(num1[0]=='-'){
		s1=-1;
		num1[0]='0';
	}
	if(num2[0]=='-'){
		s2=-1;
		num2[0]='0';
	}
	int len1=num1.length(),i,j,a;
	int len2=num2.length(),rem=0,carry=0;
	num1=reverse(num1,len1);
	num2=reverse(num2,len2);
	for(i=0;i<len2;i++){
		for(j=0;j<len1;j++){
			a=(num1[j]-'0')*(num2[i]-'0')+rem;
			rem=a/10;
			pro[i+j]+=a%10+carry;
			carry=pro[i+j]/10;
			pro[i+j]%=10;
		}
		if(j==len1){
			while(rem!=0){
				pro[i+j]+=rem%10+carry;
				rem/=10;
				carry=pro[i+j]/10;
				j++;
			}
		}
	}
	if(s1*s2<0)
		cout << "-";
	for(i=i+j-2;i>=0;i--){
		cout << pro[i];
	}
	return 0;
} 
