#include "pch.h"
#include "NumSet.h"

//Constractor
NumSet::NumSet()
{
	int i;
	for (i = 0; i < 5; i++) {
		this->_hand[i] = (rand() % 10) + 1;
	}

	this->sortHand();
}

//Copy Constractor
NumSet::NumSet(NumSet& other) {
	int i;
	for (i = 0; i < 5; i++) {
		this->_hand[i] = other._hand[i];
	}

	this->sortHand();
}

//Function operation: get the max value in the arr
int  NumSet::max() {
	int i;
	int max = 0;
	for (i = 0; i < 5; i++) {
		if(max< this->_hand[i])
			max = this->_hand[i];
	}

	return max;
}

//Function operation: get the min value in the arr
int NumSet:: min() {
	int i;
	int min = this->_hand[0];
	for (i = 1; i < 5; i++) {
		if (min > this->_hand[i])
			min = this->_hand[i];
	}

	return min;
}

// Function Operation: put number in empty cell ('0')
void NumSet::insert(int n) {
	int i;
	for (i = 4; i>-1  ; i--) {
		if (this->_hand[i] == 0) {
			this->_hand[i] = n;
			break;
		}
	}
	this->sortHand();
}

//Input: index, number
//Function Operatrion: replace the number in the index
void NumSet::replace(int index, int num) {
	this->_hand[index] = num;
	this->sortHand();
}


//Function Operation: get the average of the exist cells (cell != 0)
float NumSet::average() {
	int i;
	int sum = 0;
	int count = 0;
	
	for (i = 0; i < 5; i++) {
		//cheak for exist card
		if (this->_hand[i] != 0) {
			sum += this->_hand[i];
			count++;
		}
	}

	return (float)sum / (float)count;
}
//Input: number
//Function Operation: the amount of cell which equal or bigger then it
int NumSet::biggerThan(int num) {
	int i;
	int counter = 0;
	for (i = 0; i < 5; i++) {
		if(num<this->_hand[i]|| num == this->_hand[i])
			counter++;
	}

	return counter;
}

//Input: number
//Function Operation: the amount of cell which smaller then it
int NumSet::smallerThan(int num) {
	int i;
	int counter = 0;
	for (i = 0; i < 5; i++) {
		if (num > this->_hand[i])
			counter++;
	}

	return counter;
}

// Fonction Operation: get number, return true if it exist in the hand
bool NumSet:: numExist(int num) {
	int i;

	for (i = 0; i < 5; i++) {
		if (num == this->_hand[i])
			return true;
	}

	return false;
}

//Function Operation: delete cell by index (change value to '0')
void NumSet::del(int index) {
	int i;

	for (i = 0; i < 5; i++) {
		if (i == index)
			this->_hand[i] = 0;
	}
	this->sortHand();

}

//Function Operation: sort the hand
NumSet& NumSet::sortHand() {
	int i, j;
	int temp;

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5 - i-1; j++)
			if (this->_hand[j] > this->_hand[j + 1]) {
				temp = this->_hand[j];
				this->_hand[j] = this->_hand[j + 1];
				this->_hand[j + 1] = temp;
			}

	}

	return(*this);
}



//Function Operation: print the arr
void NumSet::print() {
	int i;
	cout << "The hand: ";
	for (i = 0; i < 5; i++) {
		if(this->_hand[i]!=0)cout << this->_hand[i] << " ";
	}
	cout << endl;
}

NumSet::~NumSet()
{
}
