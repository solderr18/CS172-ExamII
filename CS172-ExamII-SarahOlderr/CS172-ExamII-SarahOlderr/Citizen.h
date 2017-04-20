#ifndef CITIZEN_H
#define CITIZEN_H
#include <iostream>
#include <string>
using namespace std;

class Citizen {
private:
	int id;
	string firstName; 
	string lastName; 
	string color; 
public:
	Citizen( int iD,  string fName,  string lName, string clr) //need const? no qay to change anyways
	{
		id = iD;
		firstName = fName;
		lastName = lName;
		color = clr;
	}
	Citizen(Citizen* citizen)
	{
		if (citizen != NULL)
		{
			id = citizen->getId();
			firstName = citizen->getFirstName();
			lastName = citizen->getLastName();
			color = citizen->getFavoriteColor();
		}
	}
	string getFirstName() { return firstName; }
	string getLastName() { return lastName; }
	int getId() { return id; }
	string getFavoriteColor() { return color; }
	void setFavoriteColor(string clr) { color = clr; }
};
#endif