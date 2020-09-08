#include "pch.h"
#include "Player.h"
#include"NumSet.h"
#include <string>
using namespace std;

//Constractor
Player::Player()
{
	this->_name = "None";
}

//Function Operation: get the average value of the player hand
float Player::getAverage() {
	return this->_cards.average();
}

//Function Operation: delete the card which the player choose from his hand
void Player::getCard(int num) {
	this->_cards.del(num);
}

//Function Operation: put the card in the hand
void Player::setCard(int num) {
	this->_cards += num;
}

//Function Opreation: return the cards (NumSet type)
NumSet& Player::getCards() {
	return (this->_cards);
}

//Function Operation: decrease the player hand's which got penalty 
void Player::penalty() {
	--this->_cards;
}

Player::~Player()
{
}
