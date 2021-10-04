#pragma once

#include "Game.h"

#include <iostream>



class GameStorage
{
	
	
private:
	
	Game* gameList; //points to array
	//static Game games[SIZE];
	int length;
	int nextIndex;

public:
	
	//Default Constructor
	GameStorage();

	~GameStorage();

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

