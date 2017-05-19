#include <iostream>
#include <algorithm>    // std::swap
#include <string.h>
#include "fun.h"
#include "mul.h"
#include "add.h"
#include "sub.h"
using namespace std;

int main(){
	string num1,num2,ans;
	int option;
	char choice;
	do{
			//MENU
		cout << "\tMENU" << endl;
		cout << "1. Addition\n2. Subtraction\n3. Multiplication\n4. Exit\n";
		cout << "Enter your choice : ";
		cin >> option;
		cin >> num1 >> num2;
		switch(option){
			case 1:
				addition(num1,num2);
			break;
			case 2:
				multiplication(num1,num2);
			break;
			case 3:
				subtraction(num1,num2);
			break;
			case 4:			
			break;
			default : cout << "WRONG CHOICE\n";
		}
		if(option!=4){
			cout << "Do you want to continue 'Y/N' : ";
			cin >> choice;
			choice=checkChoice(choice);
		}
	}while(toupper(choice)=='Y' && option!=4);
}
