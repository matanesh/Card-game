#pragma once
#include"NumSet.h"
#include <iostream>
#include<string>
using namespace std;

class Player
{
private:
	NumSet _cards;
	string _name;

public:
	Player();

	float getAverage();
	void getCard(int num);
	void setCard(int num);
	int getMaxCard() { return _cards.max(); }
	int getMinCard() { return _cards.min(); }
	void setName(string name) { this->_name= name; }
	string& getName() { return this->_name; }
	NumSet& getCards();
	void penalty();

	//Function Operation: get num, return true if the num exist in the _card
	bool isExist(int num) { return _cards.numExist(num); }

	~Player();
};

