#include "Task1.h"

#include <cstdlib> 
#include <iostream> 
using namespace std; 

void Task1::dispalyage(){
	int age; 
	age=10; 
    cout<<" You are "<<age<<" years old.\n"; 
    cout<<" You are too young to play the game.\n"; 
    system("PAUSE"); 
}

void Task1::dispalylines(int linenum){
	for(int i=0; i<linenum; ++i){
		cout<<"....."<<endl; 
	}
	system("PAUSE");
}

void Task1::printnum(int a, int b, float c){
	cout<<"a="<<a<<"b="<<b <<"c="<<c<<endl;
	system("PAUSE");
}

void Task1::login(){
	char username[20];
	cout<<"Please input your name:..."<<endl;
	cin>>username;
	cout<<"Hello "<<username<<"!\n"<<endl;
	system("PAUSE");
}

void Task1::shownum(){
	int val1=0,val2=0,val3=0;
	cout<<"Please input 3 integer num:..."<<endl;
    cin>>val1;
    cin>>val2;
    cin>>val3;
    cout<<"In forward order"<<endl;
    cout<<val1<<" "<<val2<<" "<<val3<<endl;
    cout<<"In reveser order"<<endl;
    cout<<val3<<" "<<val2<<" "<<val1<<endl;
}

void Task1::maketab(){
	int x;
    int y;
    x=10;
    y=5;
    cout<<"Result:\n";
    cout<<"x value\t"<<"y value\t"<<"Expressions\t"<<"Result\n";
    cout<<x<<" |\t"<<y<<" |\t"<<"x=y+3\t"<<"\t|"<<"x="<<y+3<<"\n";
    cout<<x<<" |\t"<<y<<" |\t"<<"x=y-2\t"<<"\t|"<<"x="<<y-2<<"\n";
    cout<<x<<" |\t"<<y<<" |\t"<<"x=y*5\t"<<"\t|"<<"x="<<y*5<<"\n";
    cout<<x<<" |\t"<<y<<" |\t"<<"x=x/y\t"<<"\t|"<<"x="<<(float)(x/y)<<"\n";
    cout<<x<<" |\t"<<y<<" |\t"<<"x=x%y\t"<<"\t|"<<"x="<<x%y<<"\n";

    system("PAUSE");
}

void Task1::increment(){
	int x=5;
	cout<<"x++"<<" "<<x++<<endl;
    cout<<"++x"<<" "<<++x<<endl;
    cout<<"--x"<<" "<<--x<<endl;
    cout<<"x--"<<" "<<x--<<endl;
}
