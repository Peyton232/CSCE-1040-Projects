/*
Made by Peyton Thibodeaux
4/10/2020
Lab 10 CSCE 1040
*/

#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

//display information function
void display() {
	cout << "*********************************************************\n";
	cout << "             Computer Science and Engineering            \n";
	cout << "                         Lab 10                          \n";
	cout << "             CSCE 1040 - Computer Science II             \n";
	cout << "   Peyton Thibodeaux    pwt0013    pwt0013@my.unt.edu    \n";
	cout << "*********************************************************\n\n\n";
}

int Liar(int n){
	//value
	int value = -1;
	//if first number or second it = -1
	if(n == 1){
		value = -1;
	} else if(n == 2){
		value = -1;
	} else {
		//return liar-liar value
		value = 2 * (Liar(n-1) + Liar(n-2));
	}
	
	//stop point
	return value;
	
}

int main(){
	//variable
	int position;
	
	//hardcode line of numbers
	for (int i = 0; i < 3; i++){
		for (int j = 1; j < 11; j++){
				if (j == 10){
					cout << "0";
				} else {
					cout << j;
				}
		}
	}
	//new line
	cout << "\n";
	
	//print 23 liar-liar values
	for (int i  = 1; i <=23; i++){
		cout << "Liar-Liar(" << setw(2) << i << ") = ";
		cout << right << setw(12) << Liar(i) << endl;
	}
	cout << endl;
	
	
	return 0;
}