#pragma once

#include <iostream>
#include <array>

class GameStorage
{
	
private:
	
	Game gameList[];

public:
	
	
	//Default Constructor
	GameStorage()
	{
		gameList[] = 0;
	};	//Paramaters and other members?

	void setGameStorage(size_t index, Game g);
	/*
	Sets the value at the given index to the given Game.
	You should test the index to make sure that it is valid. If the index is not valid then
	do not set the value.
	*/

	void getGameStorage(size_t index) const;

	int gamePriceCount(double lowerbound, double upperbound);

	Game mostExpensive();

	bool findByTitle(std::string name, Game& g);

	double priceTotal();

	int size();

	void initialize();

	std::string getAuthor();

	
};

