//
//  passenger.cpp
//  EagleLift
//
//  Created by Peyton Thibodeaux on 3/27/20.
//


#include <iostream>
#include <string>
#include "passenger.h"
using namespace std;
//default
passenger::passenger(int id, string nm, char pm, bool hc, float rl, bool pe){ passID = id; name = nm; payment = pm; handicapped = hc; ratingLevel = rl; hasPets = pe;}

//accessors 
int passenger::getID() {return passID;}
string passenger::getName() {return name;}
char passenger::getPayment() {return payment;}
bool passenger::getHandicapped() {return handicapped;}
float passenger::getRatingLevel() {return ratingLevel;}
bool passenger::getPets() {return hasPets;}
passenger* passenger::getnext() {return next;}

//mutators
void passenger::setID(int id) {passID = id;}
void passenger::setName(string nm) {name = nm;}
void passenger::setPayment(char pm) {payment = pm;}
void passenger::setHandicapped(bool hc) {handicapped = hc;}
void passenger::setRating(float rt) {ratingLevel = rt;}
void passenger::setPets(bool pe) {hasPets = pe;}
void passenger::setNext(passenger* np) {next = np;}

//print
void passenger::print() {
    cout << "Passenger ID: " << passID << " Name: " << name <<endl;
}





















