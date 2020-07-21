//
//  main.cpp
//  Mean Green EagleLift
//
//  Created by Peyton Thibodeaux on 3/02/20.
//

#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#include "driver.h"
#include "drivers.h"
#include "passenger.h"
#include "passengers.h"
#include "ride.h"
#include "rides.h"
using namespace std;

//classes
drivers drivs;
passengers pass;
rides rid;

//display information function
void display() {
	cout << "*********************************************************\n";
	cout << "             Computer Science and Engineering            \n";
	cout << "                         Homework 01                     \n";
	cout << "             CSCE 1040 - Computer Science II             \n";
	cout << "   Peyton Thibodeaux    pwt0013    pwt0013@my.unt.edu    \n";
	cout << "*********************************************************\n\n\n";
}


int main(){
	//display info 
	display();
	
	//variables
	int choice = -1;
    int id = 0;
	int menu = 4;
	
	//load files
	drivs.loadDrivers();
    rid.loadRide();
    pass.loadPassengers();
	
	//menu loop
	while (choice != 0)
    {
		if (menu == 4){
			//customer screen or driver screen
			printf ("are you a customer, a driver, or a data analysis?\n");
			printf (" 1 - customer\n 2 - driver\n 3 - data analysis (see rides data)\n");
			printf ("Enter your selection: ");
			scanf ("%d%*c", &menu);
			if (menu > 3) {
				menu = 4;
			} else if ( menu < 1){
				menu = 4;
			}
		}
		
		if (menu == 2){
			//questions for drivers
			printf ("What do you want to do?\n");
			printf (" 0 - quit\n 1 - Add driver\n 2 - edit Driver\n 3 - Delete Driver\n 4 - Find Driver\n 5 - print All Drivers\n 6 - print 1 driver\n 7 - all active rides\n");
			printf ("Enter your selection: ");
			scanf ("%d%*c", &choice);
			
			//switch loop drivers
			switch (choice)
			{
					
				case 1: 
				{
					drivs.addDriver();
					drivs.inccount();
					break;
				}
				//case 2: drivs.editDriver(); break;
				case 3: 
				{
					cout << "what driver to delete? ";
					cin >> id; cin.ignore();
					drivs.delDriver(id);
					drivs.deccount();
					break;
				}
				case 4: 
				{
					cout << "what driver to find? ";
					cin >> id; cin.ignore();
					drivs.finditem(id);
					break;
				}
				case 5: drivs.prtlist();break;
				case 6:  
				{
					cout << "what driver to print? ";
					cin >> id; cin.ignore();
					drivs.prtDriver(id);
					break;
				}
				case 7: 
				{
					rid.prtActivelist();
					break;
				}
				
			}
		}  else if (menu == 1){
		//questions for passnegers
		printf ("What do you want to do?\n");
		printf (" 0 - quit\n 1 - Add passenger\n 2 - edit passenger\n 3 - Delete passenger\n 4 - Find Passenger\n 5 - print All passenger\n 6 - print 1 passenger\n 7 - request a ride\n 8 - cancel ride\n");
		printf ("Enter your selection: ");
		scanf ("%d%*c", &choice);
		
		//loop for passengers
		switch (choice)
			{
					
				case 1: 
				{
					pass.addPassenger();
					pass.inccount();
					break;
				}
				//case 2: pass.editDriver(); break; //this is where I would put an edit if I had one
				case 3: 
				{
					cout << "what passenger to delete? ";
					cin >> id; cin.ignore();
					pass.delPassenger(id);
					pass.deccount();
					break;
				}
				case 4: 
				{
					cout << "what passenger to find? ";
					cin >> id; cin.ignore();
					pass.findPassenger(id);
					break;
				}
				case 5: pass.prtlist();break;
				case 6:  
				{
					cout << "what passenger to print? ";
					cin >> id; cin.ignore();
					pass.prtPassenger(id);
					break;
				}
				case 7: 
				{
					rid.addRide();
					rid.inccount();
					break;
				}
				case 8: 
				{
					cout << "what passenger to find? ";
					cin >> id; cin.ignore();
					rid.delRide(id);
					rid.deccount();
					break;
				}

			}
		} else if (menu == 3){
		//questions for passnegers
		printf ("What do you want to do?\n");
		printf (" 0 - quit\n 1 - print all rides \n 2 - print all active rides\n ");
		printf ("Enter your selection: ");
		scanf ("%d%*c", &choice);
		
		//loop for passengers
		switch (choice)
			{
					
				case 1: 
				{
					rid.prtlist();
					break;
				}
				case 3: 
				{
					rid.prtActivelist();
					break;
				}
				case 4: break;
				case 5: break;

			}
		}
    }
	
	
	//store
    pass.storePassengers();
    rid.storeRide();
    drivs.storeDrivers();
	//cleanup
    pass.cleanup();
    rid.cleanup();
    drivs.cleanup();
    return 0;
	
	
	
	return 0;
}