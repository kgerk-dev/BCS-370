#include "GameStorage_HW2.h"
#include "Game_HW2.h"


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
GameStorage::GameStorage()
{

	
	gameList = new Game[SIZE];
	
	
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
	SIZE = newSize;
	gameList = new Game[SIZE];
	
	
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
	gameList = new Game;
	*gameList = *copy.gameList;
	SIZE = copy.SIZE;
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
	if (index < SIZE) {
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
	for (int i = 0; i < SIZE; i++)
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
	

	for (int i = 0; i < SIZE; i++) {

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
	for (int i = 0; i < SIZE; i++) {
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
	for (int i = 0; i < SIZE; i++) {
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
// 
//*****************************************************
int GameStorage::size()
{
	return SIZE;
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
// Description: Added Size as the Array length. 
//*****************************************************
void GameStorage::initialize()
{
	for (int i = 0; i < SIZE; i++) {

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



//*****************************************************
//Function: reSize
// 
// Purpose: Changes the Size of the passed in Array. If new size if larger. 
//			Array size passes in new info and leaves blank new spots.
//			Arrays that are smaller, will only include game data of index values
//			within th enew size paramters. Any info at the end of the list is deleted.
//			
// Update Information:
// ------------------------------------------
// 
//*****************************************************
//For code: "newArray = new Game[2 * newSize];" -- size_t is implemented to avoid byte overload error
void GameStorage::reSize(size_t newSize) 
{
	//Create new Array temp pointer
	Game* newArray = new Game[newSize];
	
	if (newSize >= SIZE)
	{
		//Allocate more memory for Array, double size is best
		newArray = new Game[newSize];
		//Values must be retained in new array
		//Should only iterate through SIZE. Values greater are non-existent
		for (int i = 0; i < SIZE; i++) {
			newArray[i] = gameList[i];
			
		}

		//Delete old array, to prevent memory leak
		delete[] gameList;
		//New Array must be assigned to original name value.
		gameList = newArray;

		//reset value newArr
		newArray = nullptr;
		
		//Update SIZE Variable to new Array size
		SIZE = newSize;

	}
	else if (newSize <= SIZE)
	{	//Smaller input of newSize than SIZE.
		newArray = new Game[newSize];
		for (int j = 0; j < newSize; j++)
		{
			gameList[j] = newArray[j];
	
		}
		
		delete[] gameList;

		gameList = newArray;

		newArray = nullptr;

		SIZE = newSize;

	};
	
}

//GameStorage* GameStorage::deepCopy() {
//
//}

GameStorage& GameStorage::operator=(const GameStorage& rhs)
{
	if (this == &rhs) {
		return *this;
	}

	this->SIZE = rhs.SIZE;
	*this->gameList = *rhs.gameList;

	return *this;
}

std::ostream& operator<<(std::ostream& os, GameStorage& rhs) {
	std::cout << "\n------------GameStorage List---------------\n";
	std::cout << "Size of List: " << rhs.SIZE << std::endl;
	for (int i = 0; i < rhs.SIZE; i++) {
		std::cout << ". " << std::endl;
	}

	return os;
}




