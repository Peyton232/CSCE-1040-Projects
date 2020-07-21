//
//  Drivers.h
//  eagleLift
//
//  Created by Peyton Thibodeaux on 3/2/20.
//  
#include <vector>
using namespace std;

class drivers
{
private:
	int driverCount;					//keep track of how many drivers there are
    std::vector<driver*> driverList;	//list of drivers;

public:
    drivers() { driverCount = 0; }	//initialize count at 0
    
    int getcount();

    void inccount();		//increment the counter +1
    void deccount();		//decrement the counter -1

    void addDriver();		//add a drive rto the list
	//void editDriver();		//edit a driver's data
    void delDriver(int);	//delete a driver from the list 
    driver *finditem(int);	//search for something in the list by ID
    void cleanup();			//idk yet
    void prtlist();			//print the list of all drivers
	void prtDriver(int);		//PRINT 1 DRIVER
    void storeDrivers();	//store stuff in a data file
    void loadDrivers();		//load a data file with driver data
};
