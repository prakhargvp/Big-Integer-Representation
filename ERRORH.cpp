#include<iostream>
#ifndef DEBUG
	#define DEBUG true 
#endif
using namespace std;
class ERRORH{
	string msg;
public:
	ERRORH(){
		msg = "";	
	}		
	ERRORH(string str){
		msg = str;	
	}		
	string what(){
		return msg;
	}
	void print(){
		if(DEBUG)
			cout << msg << endl;
	}
};
