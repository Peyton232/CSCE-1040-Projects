 //
//  Drivers.h
//  eagleLift
//
//  Created by Peyton Thibodeaux on 3/10/20.
//
 
 using namespace std;
 
 class driver
 {
 private:
	int driverID;			//6 digit driver ID
	string firstName;		//driver first name (could use char[20] if wanting a specific limi of 20 characters)
	string lastName;		//drive rlast name
	int vehicleCap;			//number of passengers a driver can hold in a vehicle
	float rating;			//rating from 0-5 stars
	bool available;			//if driver is available or not
	bool petsAllowed;		//if pets are allowed or not
	string notes;			//could include any data not already specified

public: 
	//default
	driver(int id, string fn, string ln, int vc, float rt, bool av, bool pa, string on);	//set everything at once
	
	//accessors
	int getID();		
	string getFirst();
	string getLast();
	int getCap();
	float getRating();
	bool getAvailable();
	bool getPets();
	string getNotes();
	
	//mutators
	void setID(int id);		
	void setFirst(string fn);
	void setLast(string ln);
	void setCap(int vc);
	void setRating(float rt);
	void setAvailable(bool av);
	void setPets(bool pa);
	void setNotes(string on);
	
	//other
	void printDriver();

 };
 