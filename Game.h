#pragma once
#include"NumSet.h"
#include <iostream>
#include<string>
#include"Player.h"
using namespace std;


class Game
{
	Player _human;
	Player _comp;
	int _packCards;
public:
	Game();
	void VSCompByHigher();
	void VSCompBySmaller();
	void winner ();
	void menu();

	~Game();
};

