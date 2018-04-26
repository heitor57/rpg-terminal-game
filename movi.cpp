#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "controls.h"
using namespace std;
void clearchar(){
	cout << "\033[1D"<<" "<<"\033[1D";
}
void printbody(){
	cout << "O"<<"\033[1D";
}
int main(){	
	char button;int i=0;
	system("/bin/stty raw");
	cout << "\n\n\n\n\n\n\n";
	while((button=getchar())!='p'){
		clearchar();
		
		printbody();
		switch(button){
			case controls::up:
				
				cout <<"\033[1A";
				break;
			case controls::down:
				cout <<"\033[1B";
				break;
			case controls::right:
				cout <<"\033[1C";
				break;
			case controls::left:
				cout <<"\033[1D";			
				break;
		}
	}
	system("/bin/stty cooked");

}
