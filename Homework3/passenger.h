//
//  passenger.h
//  EagleLift
//
//  Created by Peyton Thibodeaux on 3/27/20.
//

class passenger
	{
	private:
		int passID;				//6 digit ID
		std::string name;		//name
		char payment;			//payment preference
		bool handicapped;		//handicapped or not
		float ratingLevel;		//rating required
		bool hasPets;			//has pets or not
		passenger *next;		//not sure yet
		
	public:
		//accessors (gets)
		int getID();
		std::string getName();
		char getPayment();
		bool getHandicapped();
		float getRatingLevel();
		bool getPets();
		passenger* getnext();

		//mutators (sets)
		void setID(int);
		void setName(std::string);
		void setPayment(char);
		void setHandicapped(bool);
		void setRating(float);
		void setPets(bool);
		void setNext(passenger*);
		
		//other
		passenger(int id, std::string nm, char pm, bool hc, float rl, bool pe);
		void print();
	};