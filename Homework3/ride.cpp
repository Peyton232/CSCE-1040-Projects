//
//  ride.cpp
//  eagle lyft
//
//  Created by Peyton Thibodeaux on 3/27/17.
//
#include <iostream>
#include <string>
#include "ride.h"
using namespace std;
	
//default
ride::ride(int id, std::string pi, std::string dr, time_t pt, int pr, bool pe, time_t dt, char st, int rt)
{rideID = id; pickupLoc = pi; dropoffLoc = dr; pickupTime = pt; partySize = pr; pets = pe; dropoffTime = dt; status = st; rating = rt;}	
	
//accessors 
int ride::getID() {return rideID;}
string ride::getPickup() {return pickupLoc;}
string ride::getDropoff() {return dropoffLoc;}
time_t ride::getPickupTime() {return pickupTime;}
time_t ride::getDropoffTime() {return dropoffTime;}
int ride::getParty() {return partySize;}
bool ride::getPets() {return pets;}
char ride::getStatus() {return status;}
int ride::getRating() {return rating;}

//mutators
void ride::setID(int id) {rideID = id;}
void ride::setPickup(string pi) {pickupLoc = pi;}
void ride::setDropoff(string dr) {dropoffLoc = dr;}
void ride::setPickupTime(time_t pt) {pickupTime = pt;}
void ride::setDropoffTime(time_t dt) {dropoffTime = dt;}
void ride::setParty(int pr) {partySize = pr;}
void ride::setPets(bool pe) {pets = pe;}
void ride::setStatus(char st) {status = st;}
void ride::setRating(int rt) {rating = rt;}
	
//print

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	