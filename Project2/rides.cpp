//
//  rides.cpp
//  eagle lif
//
//  Created by Peyton Thibodeaux on 3/27/17.
//

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iterator>
#include <ctime>
#include "ride.h"
#include "rides.h"


using namespace std;

//rides methods

int rides::getcount()  {return rideCount;}

void rides::inccount() {rideCount++;}

void rides::deccount() {rideCount--;}

//add ride
void rides::addRide()
{
    //variables
	int id, pr, rt;
	time_t pt, dt;
	string pi, dr;
	bool pe; 
	char st;
	ride *temp;
	int hours, minutes;
	char choice;
	
	//8 digit id
	id = 10000000 + (13 * rideCount) + 1;
	
	//tell passenger their ride ID
	cout << "\nYour ID is " << id << " we reccoment writing this down\n";
	
	//pickup
	cout << "Where should you be picked up?: ";
	cin.ignore();
	getline(cin, pi);
	
	//drop off
	cout << "Where do you want to go?: ";
	cin.ignore();
	getline(cin, dr);
	
	//pickup time
	cout << "how long from now should we pick you up? (input as hours and minutes sperated by a space): " ;
	cin >> hours;
	cin >> minutes;
	//set time from now then add for 
	pt = time(NULL) + (hours * 3600) + (minutes * 60);
	//drop off is 15 minutes later
	dt = pt + 900;
	
	//party size
	cout << "How many people are traveling?: ";
	cin >> pr;
	
	//pets
	cout << "Do you have pets with you? (y = yes| n = no): ";
	cin >> choice;
	if (choice == 'y' || choice == 'Y'){
		pe = false;
	} else {
		pe = true;
	}
	
	//default status is active
	st = 'a';
	
	//default rating is 5 until the customer enters one after the ride
	rt = 5;
}

//cancel ride
void rides::delRide(int id){
	//create temp holder
    ride* temp;
	int i;
	
	//find by ID
	for(auto it = rideList.begin(); it !=rideList.end(); it++)
    {
        if ((*it)->getID() == id)
        {
            rideList.at(i)->setID('c');
        }
		i++;
    }
    return;
}

//find ride
ride* rides::findRide(int id){
	//find by ID
	ride *temp;
    for (int i = 0; i < rideCount; i++)
    {
        if (rideList[i]->getID() == id) return rideList[i];
        
    }
    
    return NULL;
 }

void rides::cleanup(){
	//deletes the orphans
	for (auto it = rideList.begin(); it !=rideList.end(); it++)
    {
        //delete orphan
        delete *it;
    }
    rideList.clear();
}

void rides::prtlist(){
	//temp holder
	ride *temp;
	//loop
    for (auto it = rideList.begin(); it !=rideList.end(); it++)
    {
        temp = *it;
        cout << "ride id: " << temp->getID() << " ";
		cout << "Pickup location: " << temp->getPickup() << " "; 
		cout << "Drop-off location: " << temp->getDropoff() << " ";
		cout << "Party Size: " << temp->getParty() << " "; 
		cout << "Drop-off location: " << temp->getDropoff() << " ";
		cout << "Status(a = active| c = cancelled | d = done): " << temp->getStatus() << " "; 
	    cout <<endl;
    }
}

void rides::prtActivelist(){
	//temp holder
	ride *temp;
	//loop
    for (auto it = rideList.begin(); it !=rideList.end(); it++)
    {
		temp = *it;
		if (temp->getStatus() == 'c'){
			temp = *it;
			cout << "ride id: " << temp->getID() << " ";
			cout << "Pickup location: " << temp->getPickup() << " "; 
			cout << "Drop-off location: " << temp->getDropoff() << " ";
			cout << "Party Size: " << temp->getParty() << " "; 
			cout << "Drop-off location: " << temp->getDropoff() << " ";
			cout << "Status(a = active| c = cancelled | d = done): " << temp->getStatus() << " "; 
			cout <<endl;
		}
    }
}

void rides::storeRide(){
	
	//set up file out
    ofstream fout;
	//open file
    fout.open("rides.dat");
	//set number in set
    fout << rideCount << endl;
    
    ride *temp;
	//loop
    for (auto it = rideList.begin(); it !=rideList.end(); it++)
    {
		//print each driver on a line
        temp=*it;
        fout << temp->getID() <<  " " << temp->getPickupTime() << " " <<  temp->getDropoffTime() << " " << temp->getParty() << " " << temp->getPets() << " " << temp->getStatus() << " " << temp->getRating() << endl;
		fout << temp->getPickup() << "\n" <<  temp->getDropoff() << "\n";
    }
    fout.close();
}

void rides::loadRide(){
	//setup file in
    ifstream fin;
	
	///variables
	int id, pr, rt;
	time_t pt, dt;
	string pi, dr;
	bool pe; 
	char st;
	
	//open file
    fin.open("rides.dat");
	//get count
    fin >> rideCount; fin.ignore();
    //loop
    for ( int i=0; i < rideCount; i++)
    {
        //record all the stuff
        fin >> id >> pt >> dt >> pr >> pe >> st >> rt;
		//fin.ignore();
		getline(fin, pi);
		getline(fin, dr);
		
		//push list
		ride* myRide= new ride(id,pi,dr,pt,pr,pe,dt,st,rt);
        rideList.push_back(myRide);
    }
	
	//close file
    fin.close();
	
	
}























