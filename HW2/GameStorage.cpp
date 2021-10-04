#include "GameStorage.h"
#include "Game.h"


//***************************************************************************************
// File: Game.cpp
//
// Purpose: 
//
// Written By: Kyle Gerken
//
// Compiler: Visual C++ 2019
//
// Update Information:
// -----------------------------
// Name: Kyle Gerken
// Date: 9/18/2021
// Description: Version 1.0:	Game object can identify with title, ESRB, or Price of game.
//								Games are create statically with Getters and Setters to modify 
//								member variables
// 
// Name: Kyle Gerken
// Date: 10/3/2021
//
//***************************************************************************************


//*****************************************************
//Function: GameStorage Default Constructor
// 
// Purpose: Initializes Game array as a dynamic array
// 
// Update Information:
// ------------------------------------------
// 
//*****************************************************
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
//Function: GameStorage - Destructor
//
//Purpose: Deallocates dynamic array of Game
//
//Update Information:
//
//
//******************************************
GameStorage::~GameStorage() {

	delete[] gameList;
	gameList = nullptr;

}



//******************************************
//Function: GameStorage Set Member Function
//
//Purpose: Sets the indicated Game into the index position of the Gamestorage collection.
//
//Update Information:
//
//
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
//Function: GameStorage Get Member Function
//
//Purpose: Returns the index Position of the Game in the GameStorage Collection
//
//Update Information:
//
//
//
//******************************************
const Game& GameStorage::Get(int index)
{
	return gameList[index];
}



//*****************************************************
//Function: gamePriceCount
// 
// Purpose: Returns the number of games at the price range of selected values, lowerbound and upperbound, indicated by user
// 
// Update Information:
// ------------------------------------------
// 
//*****************************************************
int GameStorage::gamePriceCount(double lowerbound, double upperbound)
{
	int count = 0;
	for (int i = 0; i < 3; i++)
	{
		if (gameList[i].getPrice() > lowerbound && gameList[i].getPrice() < upperbound)
			count++;
	}

	return count;
}



//*****************************************************
//Function: mostExpensive
// 
// Purpose: Returns the most expensive game in the collection according to price
// 
// Update Information:
// ------------------------------------------
// 
//*****************************************************
Game& GameStorage::mostExpensive()
{
	double price = 0;
	int num = 0;
	int i = 0;

	for (i = 0; i < 3; i++) {

		if (gameList[i].getPrice() > price) {

			price = gameList[i].getPrice();
			num = i;
		}
	}

	return gameList[num];
}



//*****************************************************
//Function: findByTitle
// 
// Purpose: Returns True or False (1 or 0) if the Game identified by Title, is in the index position requested.
// 
// Update Information:
// ------------------------------------------
// 
//*****************************************************
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



//*****************************************************
//Function: priceTotal
// 
// Purpose: Returns the total price of all games in the collection
// 
// Update Information:
// ------------------------------------------
// 
//*****************************************************
double GameStorage::priceTotal()
{
	double sum = 0.0;
	for (int i = 0; i < 3; i++) {
		sum += gameList[i].getPrice();
	}
	return sum;
}



//*****************************************************
//Function: size
// 
// Purpose: Returns the Size of the Array to the user as an integer
// 
// Update Information:
// ------------------------------------------
// 
//*****************************************************
int GameStorage::size()
{
	//(N[SIZE]/N[0]) +1 
	int size = (sizeof(gameList[3]) / sizeof(gameList[0])) + 1;

	return size;
}



//*****************************************************
//Function: initialize
// 
// Purpose: Initializes set Game variables indicated in the collection back to default values.
// 
// Update Information:
// ------------------------------------------
// 
//*****************************************************
void GameStorage::initialize()
{
	for (int i = 0; i < 3; i++) {

		gameList[i].setTitle("NoTitle");
		gameList[i].setEsrb("NoESRB");
		gameList[i].setPrice(0.0);
	}
	std::cout << "Game list values reset to default" << std::endl;
}



//*****************************************************
//Function: getAuthor
// 
// Purpose: Returns teh author of the collection of Games. In this scenario it Harcoded to myself
// 
// Update Information:
// ------------------------------------------
// 
//*****************************************************
std::string GameStorage::getAuthor()
{
	std::string author = "Author: Kyle Gerken\n";
	return author;
}