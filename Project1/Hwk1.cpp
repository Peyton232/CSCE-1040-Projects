//Umm as far as documentaion goes I went to a few labs for help and went to walk-in turoring with Mathew at the learning center. 
//stackoverflow.com and cplusplus.com I spent a lot of time on but did not copy code from either
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include "student.h"
#include "bubble.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

//display information function
void display() {
	cout << "*********************************************************\n";
	cout << "             Computer Science and Engineering            \n";
	cout << "                         Homework 01                     \n";
	cout << "             CSCE 1040 - Computer Science II             \n";
	cout << "   Peyton Thibodeaux    pwt0013    pwt0013@my.unt.edu    \n";
	cout << "*********************************************************\n\n\n";
}

//structure to hold the class statistics
typedef struct classStats {
	float mean;
	float min;
	float max;
	float median;
	string name;	
}classStats;

int main()
{
	//display course information and name
	display();
	
	//variables
	int numOfStudents = 19;				//number of students, in this case 19
	student *students[numOfStudents];	//array of student pointers	
	classStats classData;				//class stats structure variable
	
	//set up file stream
	ifstream fin;
	
	//open file
	fin.open("grades");

	//check if file openeing has failed
	if (!fin) {
		cout << "File failed, something went wrong\n\n";
	} else {
		cout << "File found\n\n";
	}

	//get course name form the file 
	fin >> classData.name;
	
	//allocate memory
	for(int i = 0; i < numOfStudents; i++)
    {
		students[i] = new student;
		students[i]->first = new char[1];
		students[i]->last = new char[1];
	}
	
	//loop to get data from the file
	for(int i = 0; i < numOfStudents; i++)
    {
		fin >> students[i]->first;
		fin >> students[i]->last;
		fin >> students[i]->exam1;
		fin >> students[i]->exam2;
		fin >> students[i]->exam3;
		//calulate mean
		students[i]->mean = ((double)students[i]->exam1 + students[i]->exam2 + students[i]->exam3) / 3;
    }

	//set baseline 
	classData.min = students[0]->mean;
	classData.max = students[0]->mean;
	
	//calculation max, min, and mean
	for(int i = 0; i < numOfStudents; i++)
    {
		//add up total of each students mean
		classData.mean += students[i]->mean;
		
		//if statement seeing if a new minimum value has bene found
		if (students[i]->mean < classData.min){
			classData.min = students[i]->mean;
		}
		
		//if statement seeing if a new max value has bene found
		if (students[i]->mean > classData.max){
			classData.max = students[i]->mean;
		}
	
		//at end of loop find mean of the group
		if (i == (numOfStudents - 1)){
			classData.mean = classData.mean / numOfStudents;
		}
	}
	
	//call bubble sort
	bubble(students, numOfStudents);

	//find median
	classData.median = students[numOfStudents / 2]->mean;
	
	//formatting
	cout.precision (4);
	cout.setf(ios::showpoint); 
	
	//display results
	cout << classData.name << "\tMEAN:" << classData.mean;
	cout << "\tMIN:" << classData.min << "\tMAX:" << classData.max;
	cout << "\tMEDIAN:" << classData.median << endl;
	
	//loop to print data
	for(int i = 0; i < numOfStudents; i++)
    {
		//format the data also with setw
		cout << setw(17) << left << students[i]->first;
		cout << setw(17) << left << students[i]->last;
		cout << setw(17) << left << students[i]->mean;
		cout << endl;
    }
	
	//delete memorywith a loop
  for(int i = 0; i < numOfStudents; i++)
    {
		//delete memory
		delete (students[i]->first);
		delete (students[i]->last);
		delete (students[i]);
	}
  return 0;
}