//
//  ride.h
//  eaglelift
//
//  Created by Peyton Thibodeaux on 3/27/17.
//

class ride
{
private:
    int rideID;					//ID for this ride
    std::string pickupLoc;		//location for pickup
	std::string dropoffLoc;		//location for drop off
	time_t pickupTime;				//pickup time
	int partySize;				//how many people in the cra
	bool pets;					//pets present?
	time_t dropoffTime;			//drop off time
	char status;				//status (active, completed, cancelled)
	int rating;					//rarting given from custoemr (1-5)
public:
	//accessors
    int getID();		
    std::string getPickup();
	std::string getDropoff();
	time_t getPickupTime();
	time_t getDropoffTime();
	int getParty();
	bool getPets();
	char getStatus();
	int getRating();
    
	//mutators
    void setID(int);		
    void setPickup(std::string);
	void setDropoff(std::string);
	void setPickupTime(time_t);
	void setDropoffTime(time_t);
	void setParty(int);
	void setPets(bool);
	void setStatus(char);
	void setRating(int);
    
	//other
    void print();
	ride(int, std::string, std::string, time_t, int, bool, time_t, char, int);
};
