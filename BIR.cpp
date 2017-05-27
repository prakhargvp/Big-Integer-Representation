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
	// To Trim Zero's from the front of answer
	string removeZero(string)
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
// Addition Function
void BIR::addition(){
	n1 = "+12311231231";
	n2 = "+12312313";
// Addition Logic goes here
	char ch1,ch2,ch;
	int rem=0;
	if(n1.length()<n2.length())
		swap(n1,n2);
	if((n1[0]=='+' && n2[0]='-')||(n1[0]=='-' && n2[0]='+'))
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
			ans+=ch;
			n1.pop_back();
			n2.pop_back();
		}
		if(n1.length()!=n2.length()){
			while(n1.length()!=1){
				ch=n1.back();
				if(ch=='9' && rem==1)
					ans+='0';
				else{
					ans+=ch+rem;
					rem=0;	
				}
				n1.pop_back();
			}
		}
		if(rem!=0)
			ans+='1';
		reverse(ans.begin(),ans.end());
		ans=n1[0]+ans;
		cout << ans;
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
	// Subtraction Logic goes here
	char a, b;
	int carry=0,len1,len2,i,j,k=0,borrow=0;
	if(n2[0]=='+')
		n2[0]='-';
	else
		n2[0]='+';
	if(n1.length()<n2.length())
		swap(n1,n2);
	else if(n1.size()==n2.size()){
		i = 1;
		while(n1[i]==n2[i] && i<n2.size())
			i++;
		if(n1[i]<n2[i]){
			// Code for swap
			// n1 is greater & n2 is smaller
			swap(n1,n2);	
		}
	}
	len1=n1.length();
	len2=n2.length();
	i = len1-1;
	j = len2-1;
	if((n1[0]=='+' && n2[0]=='+')||(n1[0]=='-' && n2[0]=='-'))
		addition();
	else{
		while(j>0){
			a = n1[i];		
			b = n2[j];
			if(a < b){
				n2[j-1] += 1;
				a += 10;
				if(j==1){
					borrow = 1;
				}
			}
			a = a - b + '0';
			ans += a;
			//cout << a << endl;
			i--;
			j--;
		}
		while(i>0){
			a = n1[i--];
			if(borrow){
				if(a=='0'){
					a = '9';
				}else{
					a = a - 1;			
					borrow = 0;
				}
			}	
			ans += a;	
		}
	}
	reverse(ans.begin(),ans.end());	
	ans = removeZero(ans);
	cout << n1[0] << ans << endl;
}
