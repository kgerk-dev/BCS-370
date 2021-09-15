#pragma once

#include <iostream>
#include <array>

class GameStorage
{
	const int SIZE = 20;
private:
	
	Game gameList[SIZE];

public:
	
	

	//Default Constructor
	GameStorage()
	{
		
	};	//Paramaters and other members?

	void setGameStorage(int index, Game g);

	void getGameStorage(int index) const;

	int gamePriceCount(double lowerbound, double upperbound);

	Game mostExpensive();

	bool findByTitle(std::string name, Game& g);

	double priceTotal();

	int size();

	void initialize();

	std::string getAuthor();

	
};

