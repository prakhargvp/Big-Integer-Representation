#include<iostream>
#include<stdio.h>
#include<string.h>
#include "BIR.cpp"
using namespace std;
int main(int argc,char *argv[]){
	int ch=0,imode,omode,r_option;
	FILE *fin=NULL,*fout=NULL;
	char input_file[100],output_file[100];
	BIR ob;
	if(argc > 1){
		strcpy(input_file,argv[1]);
		if(fopen(input_file,"r")==NULL){
			cout << "Invalid Input File\n";
			return 0;
		}else{
			imode=1;
		}
		if(argc > 2){
			strcpy(output_file,argv[2]);
			omode=1;
		}else{
			omode=0;
		}
	}else{
		cout << "Select the Mode : \n";
		do{
			cout << "Input Mode (0-Screen , 1-File) : ";
			cin >> imode;
			if(imode==1){
				do{
					cout << "Enter File : ";
					cin.ignore();
					cin.getline(input_file,100);
				}while(fopen(input_file,"r")==NULL);
			}
		}while(imode!=0 && imode!=1);
		do{
			cout << "Output Mode (0-Screen , 1-File) : ";
			cin >> omode;
			if(omode==1){
				cout << "Enter File : ";
				cin.ignore();
				cin.getline(output_file,100);
			}
		}while(omode!=0 && omode!=1);
	}
	if(argc>3){
		cout << "\t\tWRONG INPUT" << endl;
		cout << "Input format should be in following manner" << endl << endl;
		cout << "<Executable filename>" << endl;
		cout << "<Executable filename>  <input_filename>  " << endl;
		cout << "<Executable filename>  <input_filename>  <output_filename>"<< endl;
	}else{
		if(imode==1){
			fin=freopen(input_file,"r",stdin);
			do{
				r_option=ob.input();
			}while(r_option!=1 && r_option!=0);
			fclose(fin);
		}else{
			do{
				r_option=ob.input();
			}while(r_option!=1 && r_option!=0);
		}
		if(r_option==1){
            if(omode==1){
                fout=freopen(output_file,"w",stdout);
                cout << ob.result() << endl;
                fclose(fout);
            }else{
                cout << ob.result() << endl;
            }
		}
	}
return 0;
}
