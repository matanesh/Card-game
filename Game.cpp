#include "pch.h"
#include "Game.h"
#include"NumSet.h"
#include <iostream>
#include<string>
#include"Player.h"

#define ROUNDS  3

Game::Game()
{
	this->_packCards =  (rand() % 10) + 1;
}

void Game::VSCompByHigher() {

	int c_human;
	int c_comp;
	bool ok = false;
	cout << endl;
	cout << "Game against the comp by the higer card!!!" << endl;
	cout << endl;
	for (int i = 0; i < ROUNDS; i++) {
		cout << "Round number " << i + 1 << endl;
		cout << "*******************" << endl;
		cout << endl;
		cout << this->_human.getName() << " cards: " << this->_human.getCards() << endl;
		cout << endl;
		cout<< this->_comp.getName() << " cards: " << this->_comp.getCards() << endl;
		cout << endl;
		
		//show the card from the pack
		cout << "The card is: " << this->_packCards << endl;
		cout << endl;

		//players choose cards
		while (!ok)
		{
			cout << this->_human.getName() << " choose your card" << endl;
			cin >> c_human;
			//check if the card exist
			for (int j = 0; j < 5; j++) {
				if (this->_human.isExist(c_human)) ok = true;
			}
			if (!ok) cout << "Your choose don't exist, choose again" << endl;
		}
		//for the next round
		ok = false;

		//delete the card whoch choosen from the hand
		this->_human.getCard(c_human);
		c_comp = this->_comp.getMaxCard();
		this->_comp.getCard(c_comp);
		cout << endl;
		cout << "Computer choose: " << c_comp << endl;
		cout << this->_human.getName() << " choose: " << c_human << endl;
		cout << endl;

		//if the human win
		if (c_human > c_comp || c_human == c_comp) {
			cout << this->_human.getName() << " win this round" << endl;

			this->_human.setCard(this->_packCards);

			this->_comp.setCard(c_comp);
			this->_comp.penalty();
		}
		//if the comp win
		else {
			cout << " The computer win this round" << endl;

			this->_human.setCard(c_human);

			this->_human.penalty();
			this->_comp.setCard(this->_packCards);
		}
		// take new card from pack
		this->_packCards = (rand() % 10) + 1;
		cout << endl;
	}
	cout << this->_human.getName() << " cards: " << this->_human.getCards() << endl;
	cout << endl;
	cout << this->_comp.getName() << " cards: " << this->_comp.getCards() << endl;
	cout << endl;
	cout << endl;
	this->winner();
}
void Game::VSCompBySmaller() {

	int c_human;
	int c_comp;
	bool ok = false;

	cout << "Game against the comp by the smaller card!!!" << endl;
	cout << endl;
	for (int i = 0; i < ROUNDS; i++) {
		cout << "Round number " << i + 1 << endl;
		cout << "*******************" << endl;
		cout << this->_human.getName() << " cards: " << this->_human.getCards() << endl;
		cout << endl;
		cout << this->_comp.getName() << " cards: " << this->_comp.getCards() << endl;
		cout << endl;

		//show the card from the pack
		cout << "The card is: " << this->_packCards << endl;

		//players choose cards
		while (!ok)
		{
			cout << this->_human.getName() << " choose your card" << endl;
			cin >> c_human;
			//check if the card exist
			for (int j = 0; j < 5; j++) {
				 if (this->_human.isExist(c_human)) ok = true;
			}
			if (!ok) cout << "Your choose don't exist, choose again" << endl;
		}
		//for the next round
		ok = false;

		//delete the card which choosen from the hand
		this->_human.getCard(c_human);

		//Computer choose card
		c_comp = this->_comp.getMinCard();
		this->_comp.getCard(c_comp);

		cout << "Computer choose: " << c_comp << endl;
		cout << this->_human.getName() << " choose: " << c_human << endl;

		//if the human win
		if (c_human > c_comp || c_human == c_comp) {
			cout << this->_human.getName() << " win this round" << endl;

			this->_human.setCard(this->_packCards);

			this->_comp.setCard(c_comp);
			this->_comp.penalty();
		}
		//if the comp win
		else {
			cout << " The computer win this round" << endl;

			this->_human.setCard(c_human);

			this->_human.penalty();
			this->_comp.setCard(this->_packCards);
			cout << endl;
		}
		// take new card from pack
		this->_packCards = (rand() % 10) + 1;
	}
	cout << this->_human.getName() << " cards: " << this->_human.getCards() << endl;
	cout << endl;
	cout << this->_comp.getName() << " cards: " << this->_comp.getCards() << endl;
	cout << endl;
	cout << endl;
	this->winner();
}

//Function operation: show the winner
void Game::winner ()  {
	cout << this->_human.getName()<< " average is : " << this->_human.getAverage()<< endl;
	cout << "Computer" << " average is : " << this->_comp.getAverage() << endl;
	if (this->_human.getAverage() > this->_comp.getAverage())
		cout << "The winner is : " << this->_human.getName() << endl;
	else if (this->_human.getAverage() < this->_comp.getAverage())
		cout << "The winner is : " << "Computer"<< endl;
	else cout << "The winner is : " << this->_human.getName() << endl;
}

//Function operation: menu for user
void Game::menu()
{
	string name;
	int choice;
	while (1) {
		cout << endl;
		cout << "MENU" << endl;
		cout << "****" << endl;
		cout << "Hellow, please enter your name: ";
		cin >> name;
		this->_human.setName(name);
		this->_comp.setName("Computer");
		cout << "1) Player VS Computer By Higher" << endl;
		cout << "2) Player VS Computer By Smaller" << endl;
		cout << "3) Exit" << endl;
		cout << endl;
		cout << "Your choice : ";
		cin >> choice;
		switch (choice) {
		case 1:this->VSCompByHigher();
			break;
		case 2:this->VSCompBySmaller();
			break;
		case 3:
			return;
			break;
		default:
			cout << "Wrong choice, plese try again" << endl;
		}
	}
}



Game::~Game() 
{
}

