#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <string>
using namespace std;

typedef struct customerInfo {
  char *name;
  int customerID;
  float accountBalance;
}customer;

typedef struct employeeInfo {
  char *name;
  int employeeID;
} employee;

int main() {

	//variables
	char letter;					//variable to hold input of what kind of row (e, c, t)
	customer *customerData[50];		//variable to hold array of customerData
	employee *employeeData[50];		//variable to hold array of employeeData
	int placeholderInt;				//placeholder value for arranging values
	int placeholderInt2;				//placeholder value for arranging values
	float transaction;				//hold transaction amount;

	//allocate memory for the customerData array
	for(int i = 0; i < 50; i++)
		{
			customerData[i] = new customer;
			customerData[i]->name = new char[15];
		}
		
	//allocate memory for the employeeData array
	for(int i = 0; i < 50; i++)
		{
			employeeData[i] = new employee;
			employeeData[i]->name = new char[15];
		}

	//loop to call functions depending on the first letter of the row, works only with c and e 
	for(int i = 0; i < 100; i++){

		//check letter	
		cin >> letter;

		if (letter == 'c'){
			//get customer id
			cin >> placeholderInt;
			
			//store customer id in the array, and have the position of the array match (subtract 1) for easier searching later
			customerData[placeholderInt - 1]->customerID = placeholderInt;
			
			//store name in the same place in the array
			cin >> customerData[placeholderInt - 1]->name;
			
			//store account balance 
			cin >> customerData[placeholderInt - 1]->accountBalance;
			
		} else if (letter == 'e'){
			//get employee id
			cin >> placeholderInt;
			
			//store employee id in the array, and have the position of the array match (subtract 1) for easier searching later
			employeeData[placeholderInt - 1]->employeeID = placeholderInt;
			
			//store name in the same place in the array
			cin >> employeeData[placeholderInt - 1]->name;
		} else if (letter == 't') {
			//terminate loop for transactions
			break;
		}
		
	}

	/* test data for customer
	for (int i = 0; i < 49; i++){
		cout << customerData[i + 1]->customerID << "\t\t";
		cout << customerData[i + 1]->name << "\t\t";
		cout << customerData[i + 1]->accountBalance << "\t\t";
		cout << endl;
	}
	
	//test data employee
	for (int i = 0; i < 49; i++){
		cout << employeeData[i + 1]->employeeID << "\t\t";
		cout << employeeData[i + 1]->name << "\t\t";
		cout << endl;
	}*/
	
	//loop for transactions
	do {
		//check the customer number
		cin >> placeholderInt;
		placeholderInt2 = placeholderInt;
		
		//print customer name
		cout << setw(17) << left << customerData[placeholderInt - 1]->name;
		
		//check the employee number
		cin >> placeholderInt;
		
		//print employee name
		cout << setw(17) << left << employeeData[placeholderInt - 1]->name;
		
		//check if withdraw or deposit
		cin >> letter;
		if (letter == 'w') {
			//turn the number negative
			cin >> transaction;
			transaction *= -1;
		} else {
			//keep the number as is
			cin >> transaction;
		}
		
		//print withdraw/deposit amount
		cout << setw(1) << left << "$" << setw(17) << fixed << setprecision(2) << transaction;
		
		//calculate new balance
		customerData[placeholderInt2 - 1]->accountBalance += transaction;
		
		//calculate and print new balance
		cout << setw(1) << left << "$" << fixed << setprecision(2) << customerData[placeholderInt2 - 1]->accountBalance;
		
		//new line
		cout << endl;
		
		//check if there is another transaction
		cin >> letter;
	} while (letter == 't');

	//delete memory for customer array
	for(int i = 0; i < 50; i++)
    {
		delete (customerData[i]->name);
		delete (customerData[i]);
		
	}
	
	//delete memory for employee array
	for(int i = 0; i < 50; i++)
    {
		delete (employeeData[i]->name);
		delete (employeeData[i]);
		
	}

	return 0;
}
