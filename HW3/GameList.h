#pragma once

//***************************************************************************************
// File: GameList.h
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
// Date: 11/02/2021
// Description: 	
//		- New class specifically designed for an unsorted linked list foe Games.
//		- Use with "Game.h" included in the source files, as the data to be used in 
//		- the container.
//		- Included a Template library to open up the oppurtunity to include this class in
//		- future use of multiple data types.
//
//***************************************************************************************
#include <iostream>;
#include <string>;


// Included Project Files
#include "Game.h"

//*****************************************************
// Function: GameListNode Constructor; Template Class-
// 
// Purpose: 
// 
// Update Information:
// ------------------------------------------
// 
// Name: Kyle Gerken
// Date: 11/02/2021
// Description: All member variables were changed to pointers. Instantiated new data types.
// 
//*****************************************************

struct GameListNode {
	Game data;
	GameListNode *next;
};


//*****************************************************
// Function: GameList Class Declaration of members & member functions
// 
// Purpose: 
// 
// Update Information:
// ------------------------------------------
// 
// Name: Kyle Gerken
// Date: 11/02/2021
// Description: 
//		- All member variables were changed to pointers. Instantiated new data types.
//		- Rule of Three: used specifically for this class. 1. Copy Constructor, 2. Destructor, 
//		  3. Assignment Operator Overload operator=.
// 
//*****************************************************

class GameList
{
public:

	//******************* Constructor(s) *************************
	GameList();

	//******************* Rule of Three *************************
	GameList(const GameList& otherList);
	~GameList();
	GameList operator=(GameList& rhs);

	//****************** Member Functions ***********************

	void Clear();
	int Length() const; //O(1)
	void Add(const Game e);
	void Add(const GameList& otherList);
	bool FindGame(std::string title, Game& result) const;
	void Delete(std::string title);


	//******************** Non-Member Overloads *****************

	friend std::ostream& operator<<(std::ostream& os, GameList& rhs);

	friend std::istream& operator>>(std::istream& is, GameList& rhs);

	//****************** Private Members ************************
private:
	GameListNode* m_head;
	GameListNode* m_tail;
	int m_length; //Change this to something less difficult to Read
};

