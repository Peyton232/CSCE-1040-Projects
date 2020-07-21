//
//  passengers.cpp
//  EagleLift
//
//  Created by Peyton Thibodeaux on 3/27/20.
//


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include "passenger.h"
#include "passengers.h"

using namespace std;

//collections methods

int passengers::getcount() { return passCount;}

void passengers::inccount() {passCount++;}

void passengers::deccount() { passCount--;}

//add passenger
void passengers::addPassenger(){
	
	//variables
	int id; 
	string nm;
	char pm, choice;
	bool hc, pe;
	float rl;
	passenger *temp;
	
	//prompts/calculations and storage of data
	cout << endl;

	cout << "Enter new passenger ID: ";
	//<insert function that checks if ID is taken here>
    cin >> id;
    cin.ignore();
    
	//name
    cout << "Enter name: ";
    getline(cin, nm);
	
	//set rating requirement
	cout << "What is the minimum rating required for this passenger(1-5): ";
	cin >> rl;
	if (rl > 5){
		rl = 4;
	}
	
	//payment method
	cout << "What is your preferred payment method? (c = cash, d = debit, k = credit): ";
	cin >> pm;;
	if (pm != 'c' && pm != 'd' && pm != 'k'){
		pm = 'c';
	}
	
	//handicapped
	cout << "Are you handicapped in any way? (y = yes| n = no): ";
	cin >> choice;
	if (choice == 'y' || choice == 'Y'){
		hc = true;
	} else {
		hc = false;
	}
	
	//pets
	cout << "Will you be bringing pets with you? (y = yes| n = no): ";
	cin >> choice;
	if (choice == 'y' || choice == 'Y'){
		pe = true;
	} else {
		pe = false;
	}
	
	//create the passenger and put into the list
	temp = new passenger(id,nm,pm,hc,rl, pe);
	passengerList.push_back(temp);
	
	cout << endl;
}

//edit passenger
//<insert here>

//delete passenger
void passengers::delPassenger(int id){
	//create temp holder
    passenger* pass;
	//find by ID
    for (auto it = passengerList.begin(); it !=passengerList.end(); it++)
    {
        if ((*it)->getID() == id)
        {
            passengerList.erase(it);
        }
    }
    
    return;
}

//find passenger
passenger* passengers::findPassenger(int id){
	//find by ID
	passenger *temp;
    for (int i = 0; i < passCount; i++)
    {
        if (passengerList[i]->getID() == id) return passengerList[i];
        
    }
    
    return NULL;
 }

//cleanup
void passengers::cleanup()
{
       for (auto it = passengerList.begin(); it != passengerList.end(); it++)
    {
        
        delete *it;
    }
    passengerList.clear();
}

//print all items
void passengers::prtlist()
{
 
    passenger *temp;
    for (auto it = passengerList.begin(); it !=passengerList.end(); it++)
    {
        temp = *it;
        cout << "passenger id: " << temp->getID() << " passenger name: " << temp->getName() <<endl;
    }
}

//print 1 passenger
void passengers::prtPassenger(int id)
{
	//find by ID
	passenger *temp;
	int i = 0;
    for (auto it = passengerList.begin(); it !=passengerList.end(); it++)
    {
		
		if (passengerList[i]->getID() == id){
			//temp = passengerList[it];	//may have issues	
			cout << "ID: " << (*it)->getID() << " Name: " <<  (*it)->getName() << endl;
			cout << endl;
		}
		i++;
    }
}	

//store passengers
void passengers::storePassengers()
{
	//set up file out
    ofstream fout;
	//open file
    fout.open("passengers.dat");
	//set number in set
    fout << passCount<< endl;
    
    passenger *temp;
	//loop
    for (auto it = passengerList.begin(); it !=passengerList.end(); ++it)
    {
		//print each driver on a line
        temp=*it;
        fout << temp->getID() << " " << temp->getPets() << " " <<  temp->getPayment() << " " << temp->getHandicapped() << " " <<  temp->getRatingLevel() << " " << temp->getName() << endl;
    }
    fout.close();
}

//load passengers
void passengers::loadPassengers()
{
	//setup file in
    ifstream fin;
	
	//variables
	int id; 
	string nm;
	char pm, choice;
	bool hc, pe;
	float rl;
	
	//open file
    fin.open("passengers.dat");
	//get count
    fin >> passCount; fin.ignore();
    //loop
    for ( int i=0; i < passCount; i++)
    {
        //record all the stuff
        fin >> id >> pe >> pm >> hc >> rl;
		//fin.ignore();
		getline(fin, nm);
		
		//push list
		passenger* myPassenger= new passenger(id,nm,pm,hc,rl, pe);
        passengerList.push_back(myPassenger);
    }
	
	//close file
    fin.close();
    
}