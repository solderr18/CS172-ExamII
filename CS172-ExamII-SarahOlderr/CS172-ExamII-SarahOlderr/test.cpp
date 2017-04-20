#include <iostream>
#include <string>
#include <vector>
#include "Citizen.h"
#include "City.h"
using namespace std;

//test code taken directly from exam prompt
int main() {
	
	int errors = 0;
	
	//creating cities
	City* katchem = new City("Katchem");
	City* spokane = new City("Spokane");
	City* seattle = new City("Seattle");

	//bonus if you know why he picked these names and ids
	if (spokane->populationSize() == 0)
	{
		Citizen* brandon = new Citizen(1, "Brandon", "Semenuk", "Green");
		spokane->addCitizen(brandon);
		delete brandon;

		Citizen*antoine = new Citizen(2, "Antoine", "Bizet", "Blue");
		spokane->addCitizen(antoine);
		delete antoine;

		Citizen* carson = new Citizen(3, "Carson", "Storch", "Pink");
		spokane->addCitizen(carson);
		delete carson;
		
		Citizen* kurt = new Citizen(4, "Kurt", "Sorge", "Blue");
		spokane->addCitizen(kurt);
		delete kurt;

		Citizen* kyle = new Citizen(5, "Kyle", "Strait", "Pink");
		spokane->addCitizen(kyle);
		delete kyle;
	}

	//check if need to add citizens to katchem
	//XC if u know why he chose these names
	if (katchem->populationSize() == 0)
	{
		Citizen* Bartley = new Citizen(6, "Bartley", "Andre", "Green");
		katchem->addCitizen(Bartley);
		delete Bartley;

		Citizen* Daniel = new Citizen(7, "Daniel", "Coster", "Blue");
		katchem->addCitizen(Daniel);
		delete Daniel;

		Citizen* Daniele = new Citizen(8, "Daniele", "DeLuliss", "Blue");
		katchem->addCitizen(Daniele);
		delete Daniele;

		Citizen* Richard = new Citizen(9, "Richard", "Howarth", "Pink");
		katchem->addCitizen(Richard);
		delete Richard;
	}
	else
	{
		Citizen* Richard = katchem->getCitizenWithId(9);
		if (Richard == NULL)
		{
			cout << "ERROR: Could not find Richard" << endl;
		}
		else
		{
			cout << "SUCCESS: Ricard's color successfully changed!" << endl;
		}

		if (Richard->getFavoriteColor() == "Pink")
		{
			Richard->setFavoriteColor("Purple");
		}
		else if (Richard->getFavoriteColor() == "Purple")
		{
			cout << "SUCCESS: Richard's color successfully changed!" << endl;
		}
		else
		{
			errors++;
			cout << "ERROR: Richard's color is wrong. " << endl;
		}
	}
	if (seattle->populationSize() == 0)
	{
		//We are going to add 1000's of citizens to seattle
		for (int i = 0; i < 1000; i++)
		{
			string firstname = "first" + to_string(i);
			string lastname = "last" + to_string(i);
			Citizen *c = new Citizen(1000 + i, firstname, lastname, "Green");
			seattle->addCitizen(c);
			delete c;
		}
	}

	if (katchem->populationSize() != 4)
	{
		errors++;
		cout << "ERROR: Katchem has the wrong population size" << endl;;
	}
	if (spokane->populationSize() != 5)
	{
		errors++;
		cout << "ERROR: SPokane has the wrong population size" << endl;;
	}
	if (seattle->populationSize() != 1000)
	{
		errors++;
		cout << "ERROR: Seattle has the wrong population size" << endl;;
	}
	

	return 0;
}