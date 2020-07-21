//
//  Drivers.h
//  eagleLift
//
//  Created by Peyton Thibodeaux on 3/12/20.
//

#include <string>
#include <iostream>
#include "driver.h"
using namespace std;

//assign everything
driver::driver(int id, string fn, string ln, int vc, float rt, bool av, bool pa, string on){
	driverID = id;	firstName = fn;	lastName =ln;	vehicleCap = vc;	rating = rt;	available = av;	petsAllowed = pa;	notes = on;}

//accessors
int driver::getID(){return driverID;}
string driver::getFirst(){return firstName;}
string driver::getLast(){return lastName;}
int driver::getCap(){return vehicleCap;}
float driver::getRating(){return rating;}
bool driver::getAvailable(){return available;}
bool driver::getPets(){return petsAllowed;}
string driver::getNotes(){return notes;}

//mutators
void driver::setID(int id){driverID = id;}
void driver::setFirst(string fn){firstName = fn;}
void driver::setLast(string ln){lastName = ln;}
void driver::setCap(int vc){vehicleCap = vc;}
void driver::setRating(float rt){rating = rt;}
void driver::setAvailable(bool av){available = av;}
void driver::setPets(bool pa){petsAllowed = pa;}
void driver::setNotes(string on){notes = on;}

//print
void driver::printDriver(){
	//print stuff here
	cout << "\nHey Peyton finish the print function please\n";
}






