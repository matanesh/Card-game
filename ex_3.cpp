/*************************************
*task 3-matala 3
*
*yuval averbuch: 311309587
יובל אברבוך: 311309587
*matan eshel: 203502802
מתן אשל:  203502802
**************************************/
#include "pch.h"
#include <iostream>
#include "NumSet.h"
#include "Player.h"
#include "Game.h"
using namespace std;

int main()
{
	//Cheaking the first function;
	NumSet hand;

	hand.print();

	cout << "Max card: " << hand.max() << endl; 
	cout << "Min card: " << hand.min() << endl;

	cout<<"Average: "<<hand.average()<<endl;
	cout << "Card Bigger than 5: " << hand.biggerThan(5) << endl;
	cout << "Card Smaller than 5: " << hand.smallerThan(5) << endl;

	hand.replace(0, 7);
	cout << "Replace the first card by 7"<<endl;
	hand.print();

	NumSet hand_2;
	cout << "plus the hand"<<endl;
	hand += hand_2;
	hand_2.print();
	hand.print();

	cout << "increase the hand by one" << endl;
	++hand;
	hand.print();
	cout << "decrease the hand by one" << endl;
	--hand;
	hand.print();

	cout << "Is hand1 equal to hand2" << endl;	//check operator "=="
	cout << "hand1 - ";  hand.print(); cout << endl;
	cout << "hand2 - ";  hand_2.print(); cout << endl;
	if (hand == hand_2) cout << "Yes" << endl;
	else cout << "No" << endl;

	int arr[5] = { 1,2,3,4,5 };		//check operator NumSet = int[]
	hand = arr;
	hand.print();

	hand = hand_2;		//check operator NumSet = NumSet
	hand.print();

	hand.del(2);
	hand.print();

	hand.sortHand();
	hand.print();
	cout << hand << endl;

	

	for (int i = 0; i < 5; i++) hand.del(i); // check for empty print
	cout << hand << endl;

	Game myGame;
	myGame.menu();
	
	
	return 0;
}

