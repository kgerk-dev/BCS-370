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
// Name: Kyle Gerken
// Date: 10/3/2021
// Description: Changed static array of gameList[] to a Dynamic Array with Deallocation in Destructor.
// 
// Name: Kyle Gerken
// Date: 10/3/2021
// Description: Added Size as the Array length. 
//*****************************************************
GameStorage::GameStorage() {

	//should add new game to Game storage
	SIZE = new int;
	*SIZE = 10;
	gameList = new Game[*SIZE];
	//length = *SIZE; //dereferencing Size;
	//nextIndex = 0;
	//std::cout << "Default Constructor called: GameStorage" << std::endl;
}



//*****************************************************
//Function: GameStorage Paramterized Constructor Constructor
// 
// Purpose: Initializes Game array with a set value for SIZE
// 
// Update Information:
// ------------------------------------------
// 
//*****************************************************
GameStorage::GameStorage(int &newSize)
{
	*SIZE = newSize;
	gameList = new Game[*SIZE];
	
	//nextIndex = 0;
}

//*****************************************************
//Function: GameStorage Copy Constructor
// 
// Purpose: Copys value of Obj 1 (lhs) to passed in Obj 2(rhs or copy)
// 
// Update Information:
// ------------------------------------------
// Name: Kyle Gekren
// Date: 10/5/2021
// Description: Changed object variables to pointers. Created new allocations of SIZE and gameList. 
//				Performed a deep copy by dereferencing gameList & SIZE into the object seeking a copy.
//*****************************************************
GameStorage::GameStorage(const GameStorage& copy)
{
	SIZE = new int;
	gameList = new Game;
	*gameList = *copy.gameList;
	*SIZE = *copy.SIZE;
}



//******************************************
//Function: GameStorage - Destructor
//
//Purpose: Deallocates dynamic array of Game
//
//Update Information:
//------------------------------------------
//
//******************************************
GameStorage::~GameStorage() {

	delete [] gameList;
	gameList = nullptr;

}



//******************************************
//Function: GameStorage Set Member Function
//
//Purpose: Sets the indicated Game into the index position of the Gamestorage collection.
//
//Update Information:
//-----------------------------------------
//
//Name: Kyle Gerken
// Date: 10/3/2021
// Description: Added Size as the Array length. 
//******************************************
void GameStorage::Set(int index, Game g)
{
	if (index < *SIZE) {
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
//-----------------------------------------
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
// Name: Kyle Gerken
// Date: 10/3/2021
// Description: Added Size as the Array length. 
//*****************************************************
int GameStorage::gamePriceCount(double lowerbound, double upperbound)
{
	int count = 0;
	for (int i = 0; i < *SIZE; i++)
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
// Name: Kyle Gerken
// Date: 10/3/2021
// Description: Added a pointer to Size as the Array length. 
//*****************************************************
Game& GameStorage::mostExpensive()
{
	double price = 0;
	int num = 0;
	int i = 0;

	for (i = 0; i < *SIZE; i++) {

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
// Name: Kyle Gerken
// Date: 10/3/2021
// Description: Added a pointer to Size as the Array length. 
//*****************************************************
bool GameStorage::findByTitle(std::string name, Game& g)
{
	for (int i = 0; i < *SIZE; i++) {
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
// Name: Kyle Gerken
// Date: 10/3/2021
// Description: Added a pointer to Size as the Array length. 
//*****************************************************
double GameStorage::priceTotal()
{
	double sum = 0.0;
	for (int i = 0; i < *SIZE; i++) {
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
// Name: Kyle Gerken
// Date: 10/3/2021
// Description: Added a pointer to Size as the Array length. 
//*****************************************************
int GameStorage::size()
{
	//(N[SIZE]/N[0]) +1 
	int size = (sizeof(gameList[*SIZE]) / sizeof(gameList[0])) + 1;

	return size;
}



//*****************************************************
//Function: initialize
// 
// Purpose: Initializes set Game variables indicated in the collection back to default values.
// 
// Update Information:
// ------------------------------------------
// Name: Kyle Gerken
// Date: 10/3/2021
// Description: Added a pointer to Size as the Array length. 
//*****************************************************
void GameStorage::initialize()
{
	for (int i = 0; i < *SIZE; i++) {

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


void GameStorage::reSize(int newSize) 
{
	Game *newArr;
	
	if (newSize >= *SIZE) 
	{
		newArr = new Game[newSize];
		for (int i = 0; i < *SIZE; i++) {
			gameList[i] = newArr[i];
		}
		*SIZE = newSize;
		delete[] gameList;
		gameList = newArr;

	}
	else if (newSize <= *SIZE) 
	{
		newArr = new Game[newSize];
		for (int j = 0; j < newSize; j++) 
		{
			gameList[j] = newArr[j];
		}
		*SIZE = newSize;
		delete[] gameList;
		gameList = newArr;
	}
}

GameStorage* GameStorage::deepCopy() {

}

GameStorage& GameStorage::operator=(const GameStorage& rhs)
{
	if (this == &rhs) {
		return *this;
	}

	*this->SIZE = *rhs.SIZE;
	*this->gameList = *rhs.gameList;

}

std::ostream& operator<<(std::ostream& os, GameStorage& rhs) {
	std::cout << "\n------------GameStorage List---------------\n";
	std::cout << "Size of List: " << *rhs.SIZE << std::endl;
	for (int i = 0; i < *rhs.SIZE; i++) {
		std::cout << ". " << std::endl;
	}
}

