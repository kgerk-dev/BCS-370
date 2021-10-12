#pragma once

#include "Game_HW2.h"

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
	
	int size = 10;
	
	
	//used as iterator
	
	//used as next position iterator.
	//int nextIndex;


public:
	
	//**************** Constructors/Destructors ***************************
	GameStorage();

	GameStorage(int);

	GameStorage(const GameStorage& copy);

	~GameStorage();

	//*************** Member Functions *********************************
	//Sets index for game
	void Set(int index, Game games);

	//Gets index of game
	const Game& Get(int index);

	//Returns num of games between price range
	int GamePriceCount(double lowerbound, double upperbound);

	//Returns most expensive game, by price
	Game& MostExpensive();

	//T/F if game title is correct
	bool FindByTitle(std::string name, Game& g);

	//Returns sum of all games by price
	double PriceTotal();

	//Returns size of storage collection
	int Size() const ;

	//Rests games info to default values
	void Initialize();

	//Returns Author of Game Collection
	std::string GetAuthor();

	//resizes the array used, can be smaller or larger
	void ReSize(int);

	//Creates a deep copy of primary list into a new list
	GameStorage* DeepCopy();
	//overloads assignment operator for gamestorage
	GameStorage& operator=(const GameStorage& rhs);

	//overlaods extraction operator for GameStroage to output list into console.
	friend std::ostream& operator<<(std::ostream& os,const GameStorage& rhs);
};