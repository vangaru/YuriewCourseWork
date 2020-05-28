#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct Cities {
	char nameOfCity[20];
	float amountOfCitizens;
	char mainSight[20];
	char continent[20];
	enum Continent { Continent_Europe = 1, Continent_Asia, Continent_Africa, Continent_Australia, Continent_SouthAmerica, Continent_NorthAmerica };
	union seaAccess {
		int hasAccess;
		char flag;
		seaAccess() {};
		~seaAccess() {};
	}access;
};

