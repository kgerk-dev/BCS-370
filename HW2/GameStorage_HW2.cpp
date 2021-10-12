#include "GameStorage_HW2.h"
#include "Game_HW2.h"


//***************************************************************************************
// File: GameStorage_HW2.cpp
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

	gameList = new Game[size];
	
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
GameStorage::GameStorage(int newSize)
{
	
	gameList = new Game[newSize];
	
	
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
	size = copy.size;
	gameList = new Game[size];

	for (int i = 0; i < size; i++)
	{
		gameList[i] = copy.gameList[i];
	}
	
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
	if (index < size) {
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
int GameStorage::GamePriceCount(double lowerbound, double upperbound)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (gameList[i].GetPrice() > lowerbound && gameList[i].GetPrice() < upperbound)
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
Game& GameStorage::MostExpensive()
{
	double price = 0;
	int num = 0;
	

	for (int i = 0; i < size; i++) {

		if (gameList[i].GetPrice() > price) {

			price = gameList[i].GetPrice();
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
bool GameStorage::FindByTitle(std::string name, Game& g)
{
	for (int i = 0; i < size; i++) {
		if (name == g.GetTitle()) {
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
double GameStorage::PriceTotal()
{
	double sum = 0.0;
	for (int i = 0; i < size; i++) {
		sum += gameList[i].GetPrice();
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
int GameStorage::Size() const 
{
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
// Description: Added Size as the Array length. 
//*****************************************************
void GameStorage::Initialize()
{
	for (int i = 0; i < size; i++) {

		gameList[i].SetTitle("NoTitle");
		gameList[i].SetEsrb("NoESRB");
		gameList[i].SetPrice(0.0);
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
std::string GameStorage::GetAuthor()
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
void GameStorage::ReSize(int newSize) 
{
	//Create new Array temp pointer
	Game* newArray = new Game[newSize];
	
	if (newSize >= size)
	{
		//Allocate more memory for Array, double size is best
		newArray = new Game[newSize];
		//Values must be retained in new array
		//Should only iterate through SIZE. Values greater are non-existent
		for (int i = 0; i < size; i++) {
			newArray[i] = gameList[i];
			
		}

		//Delete old array, to prevent memory leak
		delete[] gameList;
		//New Array must be assigned to original name value.
		gameList = newArray;

		//reset value newArr
		newArray = nullptr;
		
		//Update SIZE Variable to new Array size
		size = newSize;

	}
	else if (newSize <= size)
	{	//Smaller input of newSize than SIZE.
		newArray = new Game[newSize];
		for (int j = 0; j < newSize; j++)
		{
			gameList[j] = newArray[j];
	
		}
		
		delete[] gameList;

		gameList = newArray;

		newArray = nullptr;

		size = newSize;

	};
	
}

GameStorage* GameStorage::DeepCopy() {
	GameStorage* temp;

	temp = this;

	return temp;
}

GameStorage& GameStorage::operator=(const GameStorage& rhs)
{
	//Gathered from textbook pg.180 - Pointers and Array-Based Lists
	if (this != &rhs)
	{	//delete old instance of gamelist, 
		delete[] gameList;
		//assign values of rhs to member values
		size = rhs.size;
		//Create the array
		gameList = new Game[size];

		//apply new data to orignial list name
		for (int i = 0; i < size; i++)
		{
			gameList[i] = rhs.gameList[i];
		}
	}

	return *this;
}

std::ostream& operator<<(std::ostream& os, const GameStorage &rhs) {
	
	os << "\n------------GameStorage List---------------\n";
	for (int i = 0; i < rhs.size; i++) {
		os << rhs.gameList[i] << std::endl;
	}

	return os;
}




