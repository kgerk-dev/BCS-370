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
	
	//used as iterator
	//int length;
	//used as next position iterator.
	//int nextIndex;


public:
	int SIZE = 10;
	//**************** Constructors/Destructors ***************************
	GameStorage();

	GameStorage(int&);

	GameStorage(const GameStorage& copy);

	~GameStorage();

	//*************** Member Functions *********************************
	//Sets index for game
	void Set(int index, Game games);
	//Gets index of game
	const Game& Get(int index);
	//Returns num of games between price range
	int gamePriceCount(double lowerbound, double upperbound);
	//Returns most expensive game, by price
	Game& mostExpensive();
	//T/F if game title is correct
	bool findByTitle(std::string name, Game& g);
	//Returns sum of all games by price
	double priceTotal();
	//Returns size of storage collection
	int size();
	//Rests games info to default values
	void initialize();
	//Returns Author of Game Collection
	std::string getAuthor();
	//resizes the array used, can be smaller or larger
	void reSize(int);
	//Creates a deep copy of primary list into a new list
	GameStorage* deepCopy();
	//overloads assignment operator for gamestorage
	GameStorage& operator=(const GameStorage& rhs);
	//overlaods extraction operator for GameStroage to output list into console.
	friend std::ostream& operator<<(std::ostream& os, GameStorage& rhs);

};