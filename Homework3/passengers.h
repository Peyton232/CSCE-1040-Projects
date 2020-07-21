//
//  passengers.h
//  EagleLift
//
//  Created by Peyton Thibodeaux on 3/27/20.
//

#include <vector>
using namespace std;

class passengers
{
private:
    int passCount;							//keep track of how many passenger there are		
    typedef vector<passenger*> passType;	//type of passengers
    passType passengerList;					//list of passengers					
public:
    passengers() {passCount = 0; }			//initilaize count at 0
    int getcount();							//get count

    void inccount();						//increase counter by 1
    void deccount();						//decrease counter by 1

    void addPassenger();					//add passenger to list
	//void editPassenger();					//edit passenger
    void delPassenger(int);					//delete passenger
    passenger* findPassenger(int);			//search for a passenger
    void cleanup();							//cleans up stuff
    void prtlist();							//print all passengers
	void prtPassenger(int);					//print 1 passenger
    void loadPassengers();					//load dat file
    void storePassengers();					//store dat file
};
