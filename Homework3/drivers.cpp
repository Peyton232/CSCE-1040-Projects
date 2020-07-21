//
//  Drivers.cpp
//  eagleLift
//
//  Created by Peyton Thibodeaux on 3/12/20.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <typeinfo>
#include "driver.h"
#include "drivers.h"
using namespace std;

//list counting functions
int drivers::getcount(){return driverCount;}
void drivers::inccount(){driverCount++;}
void drivers::deccount(){driverCount--;}

//add driver
void drivers::addDriver(){
	//variables
	int id, vc; 
	string fn, ln;
	std::string on;	
	float rt;
	bool av, pa;
	char choice;
	driver *temp;
	
	//prompts/calculations and storage of data
	cout << endl;

	//first and last name
	cout << "Enter the first name of the new driver: ";
	cin >> fn;
	cout << "\nEnter the last name of the new driver: ";
	cin >> ln;
	
	//calulate id (note can only handle 47368 drivers, after that the id will be larger than 6 digits)
	id = 100000 + (19 * driverCount) + 1;
	
	//defaults
	//set rt of new driver at 3
	rt = 3;
	//set available to true by default
	av = true;
	
	
	//vehicle details
	cout << "\nWhat is the capacity of your vehicle: ";
	cin >> vc;
	cout << "\nAre pets allowed in your vehicle(y = yes| n = no): ";
	cin >> choice;
	if (choice == 'y' || choice == 'Y'){
		pa = true;
	} else {
		pa = false;
	}
	
	//other notes
	cout << "\nWould you like to add any other notes to this profile(y = yes| n = no): ";
	cin >> choice;
	if (choice == 'y' || choice == 'Y'){
		cout << "\nPut notes here: ";
		cin.ignore();
		std::getline (std::cin,on);
	} else {
		on = "N / A";
	}
	
	//create the driver and put into the list
	temp = new driver(id,fn,ln,vc,rt ,av ,pa ,on );
	driverList.push_back(temp);
	
	
	
	
	cout << endl;
}




void drivers::delDriver(int id)
{
    //create temp holder
    driver* drive;
	//find by ID
    for (auto it = driverList.begin(); it !=driverList.end(); it++)
    {
        if ((*it)->getID() == id)
        {
            driverList.erase(it);
        }
    }
    
    return;
}

 driver* drivers::finditem(int id){
	//find by ID
	driver *temp;
    for (int i = 0; i < driverCount; i++)
    {
        if (driverList[i]->getID() == id) return driverList[i];
        
    }
    
    return NULL;
 }

void drivers::cleanup()
{
    for (auto it = driverList.begin(); it != driverList.end(); it++)
    {
        
        delete *it;
    }
    driverList.clear();
}

void drivers::prtlist()
{
    //loop
    for (auto it = driverList.begin(); it !=driverList.end(); it++)
    {
        //print ID and name
        cout << "ID: " << (*it)->getID() << " Name: " <<  (*it)->getFirst() << " " << (*it)->getLast() << endl;
		cout << endl;
    }
}

void drivers::prtDriver(int id)
{
	//find by ID
	driver *temp;
	int i = 0;
    for (auto it = driverList.begin(); it !=driverList.end(); it++)
    {
		
		if (driverList[i]->getID() == id){
			//temp = driverList[it];	//may have issues	
			cout << "ID: " << (*it)->getID() << " Name: " <<  (*it)->getFirst() << " " << (*it)->getLast() << endl;
			cout << endl;
		}
		i++;
    }
	
	/*

		temp = driverList[it];	//may have issues	
		 
		//cout << endl;
		
	*/
}	

void drivers::storeDrivers()
{
    ofstream fout;
    fout.open("drivers.dat");
    fout << driverCount<< endl;
    
    driver *temp;
    for (auto it = driverList.begin(); it !=driverList.end(); ++it)
    {
		//print each driver on a line
        temp=*it;
        fout << temp->getID() << " " << temp->getFirst() << " " <<  temp->getLast() << " " << temp->getCap() << " " <<  temp->getRating() << " " << temp->getAvailable() << " " << temp->getPets() << " " << temp->getNotes() << " " << endl;
    }
    fout.close();
}

void drivers::loadDrivers()
{
	//in stream
    ifstream fin;
    //variables
	int id, vc; 
	string fn, ln, on;  
	float rt;
	bool av, pa;
	char choice;
	driver *temp;
    fin.open("drivers.dat");
    fin >> driverCount; fin.ignore();
    
    for ( int i=0; i < driverCount; i++)
    {
        //record all stuff
        fin >> id >> fn >> ln >> vc >> rt >> av >> pa;
		//fin.ignore();
		getline(fin,on);
        //cout << id << fn << ln << vc << rt << av << pa << on;
		//push list
		driver* myDriver= new driver(id,fn,ln,vc,rt ,av ,pa ,on );
		driverList.push_back( myDriver);
        
    }
    fin.close();
    
}









