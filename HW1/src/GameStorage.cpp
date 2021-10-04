#include "GameStorage.h"
#include "Game.h"


//****************************************************
//File: GameStorage.cpp
//
//Purpose: Add games to Game Storage
//
//Written by: Kyle Gerken
//
//Compiler: Visual C++ 2019
//
//
//****************************************************
GameStorage::GameStorage() {

	//should add new game to Game storage
	gameList = new Game[3];
	for (int i = 0; i < 3; i++) {
		gameList[i].getTitle();
		gameList[i].getEsrb();
		gameList[i].getPrice();
	}
	length = 3;
	nextIndex = 0;
	//std::cout << "Default Constructor called: GameStorage" << std::endl;
}

//******************************************
//Function: GameStorage - Constructor
//
//Purpose: assign default values to GameStorage.
//
//Update Information:
//
//By: Kyle Gerken
//
//******************************************

GameStorage::~GameStorage() {
	delete [] gameList;
	gameList = nullptr;

	//std::cout << "Destructor called: GameStorage. " << std::endl;
}

//******************************************
//Function: set
//
//Purpose: Store Games into Game Storage based on index input
//
//Update Information:
//
//By: Kyle Gerken
//
//******************************************

void GameStorage::Set(int index, Game g)
{
	if (index < 3) {
		gameList[index] = g;
	}
	else {
		std::cout << "Sorry index is invalid, try again. " << std::endl;
	}
}

//******************************************
//Function: getGameStorage
//
//Purpose: Returns gamestorage index of game
//
//Update Information:
//
//By: Kyle Gerken
//
//******************************************

const Game& GameStorage::Get(int index)
{
	return gameList[index];
}

int GameStorage::gamePriceCount(double lowerbound, double upperbound)
{
	int count = 0;
	for (int i = 0; i < 3 ; i++)
	{
		if (gameList[i].getPrice() > lowerbound && gameList[i].getPrice() < upperbound)
			count++;
	}

	return count;
}

Game& GameStorage::mostExpensive()
{
	double price = 0;
	int num= 0;
	int i=0;

	for (i = 0; i < 3; i++) {

		if (gameList[i].getPrice() > price) {

			price = gameList[i].getPrice();
			num = i;
		}
	}
	
	return gameList[num];
}

bool GameStorage::findByTitle(std::string name, Game& g)
{
	for (int i = 0; i < 3; i++) {
		if (name == g.getTitle()) {
			return &g;
		}
		else {
			return false;
		}
	}
	return false;
}

double GameStorage::priceTotal()
{
	double sum = 0.0;
	for (int i = 0; i < 3; i++) {
		sum += gameList[i].getPrice();
	}
	return sum;
}

//******************************************
//Function: size
//
//Purpose: returns the game location reference.
//
//Update Information:
//
//By: Kyle Gerken
//
//******************************************

int GameStorage::size()
{
	 //(N[SIZE]/N[0]) +1 
	int size = (sizeof(gameList[3]) / sizeof(gameList[0])) + 1;

	return size;
}

void GameStorage::initialize()
{
	for (int i = 0; i < 3; i++) {
		
		gameList[i].setTitle("NoTitle");
		gameList[i].setEsrb("NoESRB");
		gameList[i].setPrice(0.0);
	}
	std::cout << "Game list values reset to default" << std::endl;
}

//******************************************
//Function: getAuthor
//
//Purpose: Returns Games author, for this example its my name.
//
//Update Information:
//
//By: Kyle Gerken
//
//******************************************

std::string GameStorage::getAuthor()
{
	std::string author = "Author: Kyle Gerken\n";
	return author;
}