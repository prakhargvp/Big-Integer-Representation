string reverse(string str){
	int i,len;
	len = str.size();
	for(i=0;i<len/2;i++){
		swap(str[i],str[len-i-1]);
	}
	return str;
}

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

char checkChoice(char choice){
	while(choice!='Y' || choice!='N' || choice!='n' || choice!='n'){
		cin >> choice;
	}
	return choice;
}

void print(string str){
	int len=str.length();
	for(int i=0;i<len;i++)
		cout << str[i];
}
