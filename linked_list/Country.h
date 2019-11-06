#pragma once
#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::string;
class Country
{
public:
	string name;
	double area;
	int population;
	Country();
	Country(string name, double area, int population);
	void show();
};

Country::Country(string name, double area, int population)
{
	this->name = name;
	this->area = area;
	this->population = population;
}

Country::Country()
{
	name = "USA";
	area = 3430.42;
	population = 343;
}

void Country::show()
{
	cout << "---------------------------------------" << endl;
	cout << "Name: " << this->name << endl;
	cout << "Area: " << this->area << " (k km ^ 2)" << endl;
	cout << "Population: " << this->population <<" kk"<< endl;
	cout << "---------------------------------------" << endl;
}
