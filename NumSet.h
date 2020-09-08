#pragma once
#include <iostream>
using namespace std;

class NumSet
{
private:
	int _hand[5];
public:
	NumSet();
	NumSet(NumSet& other);

	int  max ();
	int min();
	void insert(int n);
	void replace(int index, int num);

	float average();
	int biggerThan(int num);
	int smallerThan(int num);
	void del(int index);

	int& getHand() { return (*_hand); }

	bool numExist(int i);

	NumSet& sortHand();
	void print();

	//like insert
	//put number in empty cell ('0')
	NumSet& operator +=(int num)  {
		this->insert(num);

		return *this;
	}

	//Operator Operation: add one hand to other hand by cell 
	NumSet& operator+=(const NumSet other) {
		int i;
		for (i = 0; i < 5; i++) {
			this->_hand[i] = this->_hand[i] + other._hand[i];
		}
		return *this;
	}

	//Operator Operation: increase the cells by one
	NumSet& operator++ () {
		int i;
		for (i = 0; i < 5; i++) {
			this->_hand[i] ++;
		}
		return (*this);
	}

	//Operator Operation: decrease the cells by one
	NumSet& operator-- () {
		int i;
		for (i = 0; i < 5; i++) {
			if(this->_hand[i]!=0)
			this->_hand[i] --;
		}
		return (*this);
	}
	
	//Operator Operation: return true if the hands equal
	bool operator ==(const NumSet hand) {
		int i;
		for (i = 0; i < 5; i++) {
			if (this->_hand[i] != hand._hand[i]) return false;
		}
		return true;
	}

	//Operator Operation: insert arr[5] into the NumSet object
	NumSet& operator =(int hand[5]) {
		int i;
		for (i = 0; i < 5; i++) {
			this->_hand[i] = hand[i];
		}
		return *this;
	}

	//Operator Operation: insert NumSet into NumSet
	NumSet& operator = (const NumSet other) {
		int i;
		for (i = 0; i < 5; i++) {
			this->_hand[i] = other._hand[i];
		}
		return *this;
	}

	//Operator Operation: return the vlaue of the cell of _hand (arr) by index
	int operator [](int i) {
		return _hand[i];
	}
	
	friend ostream & operator << (ostream & out, const NumSet& hand) {
		int i;
		bool empty = true;

		for (i = 0; i < 5; i++) {
			if (hand._hand[i] != 0) {
				out << hand._hand[i] << " ";
				empty = false;
			}
		}

		if (empty == true) out << "Empty NumSet";

		

		return out;
	}

	

	~NumSet();
};

