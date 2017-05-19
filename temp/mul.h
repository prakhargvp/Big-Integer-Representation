#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void multiplication(string num1,string num2){
	int s1=1,s2=1;
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
	int pro[len1+len2]={0};
	num1=reverse(num1);
	num2=reverse(num2);
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
	for(int temp=i+j-2;temp>=0;temp--){
		cout << pro[temp];
	}
	return 0;
} 


