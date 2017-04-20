#ifndef CITY_H
#define CITY_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Citizen.h"
using namespace std;

class City {
private:
	string cityName;
	int popSize; //I dont think I need this
	vector<Citizen*> c;
public:
	City(string ctyName)
	{
		cityName = ctyName;
		string filename = cityName + ".txt";

		fstream infile(filename, ios::in);

		infile.open(filename);
		if (infile.fail()) { //WHY WONT IT OPEN...does it need to create one???
			cout << "can't open file" << endl;
		}
		if (infile.is_open())
		{
			while (infile >> popSize) {
				cout << popSize << endl;
			}
		}
		/*
		cityName = ctyName;
		
		string filename = ctyName + ".txt";
		fstream fout;
		fout.open(filename, ios:: in | ios::out);
		if (fout.fail()) {
			cout << "can't open file" << endl;
		}
		else
			fout >> popSize; //setting c.size?
	*/
	}
	~City()
	{
		string filename = cityName + ".txt";
		fstream outfile(filename, ios::out);
		if (outfile.is_open())
		{
			outfile << c.size(); //only storing population size
			for (int i = 0; i < c.size(); i++) 
			{
				delete c[i]; //correct use of delete?
			}
		}
		//destructor for city
	}
	string getCityName() { return cityName; }
	int populationSize() 
	{
		return c.size();
	}
	Citizen* getCitizenAtIndex(int index) //need a vector to search through
	{
		return c[index]; //c is vector of citizens
	}
	void addCitizen(Citizen* citizen) 
	{
		c.push_back(citizen);
	}

	Citizen* getCitizenWithId(int iD) { //getsongbyname
		for (int i = 0; i < populationSize(); i++)
		{
			if ((c[i]->getId()) == iD)
				return c[i];
		}
	}
	vector <Citizen*> getCitizenForFavoriteColor(string clr)
	{
		vector<Citizen*> v;
		int j = 0;
		for (int i = 0; i < populationSize(); i++) {
			if (c[i]->getFavoriteColor() == clr) { //pushback ???
				v[j] = c[i];
				j++;
			}
		}
		return v;
	}
};


#endif