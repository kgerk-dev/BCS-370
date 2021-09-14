#pragma once

class GameStorage
{

private:
	
	int index;
	Game gameList[];

public:
	//Controls number of Games in gameList[];
	

	//Default Constructor
	GameStorage()
	{
		
	};	//Paramaters and other members?

	void setGameStorage(int index, Game g);

	void getGameStorage(int index) const;

	int gamePriceCount(double lowerbound, double upperbound);

	Game mostExpensive();

	bool findByTitle(std::string name, Game & g);

	double priceTotal();

	int size();

	void initialize();

	std::string getAuthor();

	
};

