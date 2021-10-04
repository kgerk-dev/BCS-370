#pragma once

#include "Game.h"

#include <iostream>

//***************************************************************************************
// File: GameStorage.cpp
//
// Purpose: Creates GameStorage Array, Declaration of Class
//
// Written By: Kyle Gerken
//
// Compiler: Visual C++ 2019
//
// Update Information:
// -----------------------------
// Name: Kyle Gerken
// Date: 9/18/2021
// Description: Version 1.0:	Declares Game Array of game objects. Size limit of 
//								of 3 games in each list
// 
// Name: Kyle Gerken
// Date: 10/3/2021
//
//***************************************************************************************

class GameStorage
{


private:

	Game* gameList; //points to array
	//static Game games[SIZE];
	int length;
	int nextIndex;

public:

	//**************** Constructors/Destructors ***************************
	GameStorage();

	~GameStorage();

	//*************** Member Functions *********************************

	void Set(int index, Game games);

	const Game& Get(int index);

	int gamePriceCount(double lowerbound, double upperbound);

	Game& mostExpensive();

	bool findByTitle(std::string name, Game& g);

	double priceTotal();

	int size();

	void initialize();

	std::string getAuthor();

};