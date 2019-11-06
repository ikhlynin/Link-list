#pragma once
#include<iostream>
#include"list.h"
#include"Country.h"
#include<string>

using namespace std;

int main()
{
	list<Country> newList;
	newList.push_front(Country("USA", 3430.834, 343));
	newList.push_back(Country("UK", 242.43, 66));
	newList.push_back(Country("UA",603.628, 44));
	cout << "=======================================" << endl;
	for (int i = 0; i < newList.getSize(); i++)
	{
		newList[i].show();
	}
	cout << "=======================================" << endl;
	newList.pop_front();
	for (int i = 0; i < newList.getSize(); i++)
	{
		newList[i].show();
	}
	return 0;
}