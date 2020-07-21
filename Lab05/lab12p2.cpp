#include <iostream> 
#include <string>
using namespace std;

class Employee {
	private:
		string name; 
	public:
		//constructors
		Employee(string name){
			this->name = name;
		}

		// virtual function
		virtual void show_info ()
		{
			cout << "Employee" << endl;
		}
		
		string getName() { return name; } 
};

class Manager : public Employee {

    public:

        Manager(string name): Employee(name) {}

        void show_info() {
            cout << "Manager( " << getName() << " )";
			cout << endl;
        }

};

class Worker : public Employee {

    public:

        Worker(string name) : Employee(name){}

        void show_info() {
            cout << "Worker( " << getName() << " )";
			cout << endl;
        }
};

class Officer : public Employee {

    public:

        Officer(string name): Employee(name){}

        void show_info() {
            cout << "Officer( " << getName() << " )";
			cout << endl;
        }
};

class Technician : public Employee {

    public:

        Technician(string name): Employee(name){}

        void show_info() {
            cout << "Technician( " << getName() << " )";
			cout << endl;
        }

};



int main(){
	
	Employee Rafa("Rafa"); Manager Mario("Mario"); Worker Anton("Anton"); Officer
	Luis("Luis"); Technician Pablo("Pablo");
	
	// The type of object pointed by a pointer to the base class 
	// determines the function that is being called
	Employee *pe; cout << "\nInheritance and Polymorphism:\n" << endl;
	
	pe = &Rafa; pe->show_info(); pe =
	&Mario; pe-> show_info(); pe =
	&Anton; pe-> show_info(); pe =
	&Luis; pe-> show_info(); pe =
	&Pablo; pe-> show_info();
	cout << "Ya he terminado." << endl; 
	
	return 0;
}