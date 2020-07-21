#include <iostream> 
#include <string>
//#define NUM_EMPLOYEES 6
using namespace std;

//base
class Employee {
	private:
		string name; 
		float salary;
		
	public:
		//constructors
		Employee(string name, float salary){
			this->name = name;
			this->salary = salary;
		}

		// virtual function
		virtual void show_info ()
		{
			cout << "Employee" << endl;
		}
		
		string getName() { return name; } 
		float getSalary() {return salary;}
};

//manager
class Manager : public Employee {
	private:
	string degree;

    public:

        Manager(string name, float salary, string degree): Employee(name, salary) 
		{
			this->degree = degree;
		}

        void show_info() {
            cout << "Manager( " << getName() << " )" << "salary: " << getSalary() << " Degree: " << degree;
			cout << endl;
        }

};

//workjer
class Worker : public Employee {
	private:
		string position;
		
    public:

        Worker(string name, float salary, string position): Employee(name, salary)
        {
            this->position = position;
        }

        void show_info() {
            cout << "Worker( " << getName() << " )" << "salary: " << getSalary() << " position: " << position;
			cout << endl;
        }
};

//officer
class Officer : public Employee {
	private:
		string role;
		
    public:

        Officer(string name, float salary, string role): Employee(name, salary)
        {
            this->role = role;
        }

        void show_info() {
            cout << "Officer( " << getName() << " )" << "salary: " << getSalary() << " Role: " << role;
			cout << endl;
        }
};

//technician
class Technician : public Employee {
	private:
		string field;
		
    public:

        Technician(string name, float salary, string field): Employee(name, salary)
        {
            this->field = field;
        }

        void show_info() {
            cout << "Technician( " << getName() << " )" << "salary: " << getSalary() << " field: " << field;
			cout << endl;
        }

};



int main(){
	int employeeNum;
	cout << "How many employees do you want to process? ";
	cin >> employeeNum;

	Employee* EmployeeList[employeeNum];
	/* 
	EmployeeList[0] = new Manager("Carla Garcia", 35000, "Economist");
	EmployeeList[1] = new Manager ("Juan Perez", 38000, "Engineer");
	EmployeeList[2] = new Officer("Pedro Egia", 18000, " Officer 1");
	EmployeeList[3] = new Officer ("Luisa Penia", 15000, " Officer 2");
	EmployeeList[4] = new Technician("Javier Ramos", 19500, "Welder");
	EmployeeList[5] = new Technician ("Amaia Bilbao", 12000, "Electricist"); 
	*/
	
	//loop
	for(int i=0;i<employeeNum;i++) 
		EmployeeList[i]->show_info(); 
	
	return 0;
}