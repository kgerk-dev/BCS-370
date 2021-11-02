#include "GameList.h"
//***************************************************************************************
// File: GameList.cpp
//
// Purpose: Declarations for Gamelist container. Constainer constraints are as follows:
//			- Unsorted Linked List
//			- Reading data from a .txt file to insert into a Linked List
//			
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
//		- Decision to choose Template versus a Game linked list
// 
//
//***************************************************************************************
//constexpr int MAX_ITEMS = 100;


//*****************************************************
// Function: GameList() --  Constructor Definition
// 
// Purpose: Sets All dynamic private member variables to nullptr.
// 
// Update Information:
// ------------------------------------------
//*****************************************************
template <class T>
GameList<T>::GameList() {
	//m_head = nullptr;
	//m_current = nullptr;
	m_iter = 0;
}



//*****************************************************
// Function: GameList(const GameList<T>& otherList) --  Copy Constructor Definition
// 
// Purpose: Rule of Three Part 1. Copy Constructor
// 
// Update Information:
// ------------------------------------------
//*****************************************************
template <class T>
GameList<T>::GameList(const GameList<T>& otherList) 
{

	GameListNode<T>* newNode = nullptr;
	GameListNode<T>* currentNode = nullptr;

	if (m_head != nullptr) 
	{
		Delete();
	}

	if (otherList.m_head == nullptr) 
	{
		m_head = nullptr;
		m_current = nullptr;
		m_length = 0;
	}
	else 
	{
		currentNode = otherList.m_head;

		m_length = otherList.m_iter;

		m_head = new GameListNode<T>;
		m_head->data = currentNode->data;
		m_head->next = nullptr;
		m_current = m_head;
		currentNode = currentNode->next;

		while (currentNode != nullptr) 
		{
			newNode = new GameListNode<T>;
			newNode->data = currentNode->data;
			newNode->next = nullptr;
			m_current->next = newNode;
			m_current = newNode;

			currentNode = currentNode->next;
			
		} // end while

	}//end else
}//end Constructor



//*****************************************************
// Function: ~GameList() -- Destructor Definition
// 
// Purpose: Rule of Three Part 2. Destructor
// 
// Update Information:
// ------------------------------------------
// Name: Kyle Gerken
// Date: 11/02/2021
// Description:
//			- Destructor will perform the same actions as GameList::Clear(); 
//			- Refer to Clear for explicit implementation of the function
//			- line: 
//*****************************************************
template <class T>
GameList<T>::~GameList() 
{
	Clear();
}



//*****************************************************
// Function: GameList.operator=(GameList<T>& rhs) Function Definition
// 
// Purpose: Clears the current list. Remember, when items are removed you MUST release
//			memory.
// 
// Update Information:
// ------------------------------------------
//*****************************************************
template <class T>
GameList<T> GameList<T>::operator=(GameList<T>& rhs)
{

}
//*****************************************************
// Function: GameList.Clear() Function Definition
// 
// Purpose: Clears the current list. Remember, when items are removed you MUST release
//			memory.
// 
// Update Information:
// ------------------------------------------
//*****************************************************
template <class T>
void GameList<T>::Clear() 
{
	GameListNode<T>* tempNode;

	while (m_head != nullptr) 
	{
		tempNode = m_head;
		m_head = m_head->data;
		delete tempNode;
	}

	m_current = nullptr;

	m_length = 0;
}



//*****************************************************
// Function: GameList.lenth() const --Function Definition
// 
// Purpose: Returns the number of items in the current list. 
//			**Important: The runtime of this operation MUST be coded such that it is
//			Big - O(1).**
// 
// Update Information:
// ------------------------------------------
//*****************************************************
template <class T>
int GameList<T>::Length() const 
{
	return m_length;
}



//*****************************************************
// Function: GameList.Add() Function Definition 
// 
// Purpose: Adds a Game to the list 
// 
// Update Information:
// ------------------------------------------
//*****************************************************
template <class T>
void GameList<T>::Add(const Game e) {

	//Create new NodeType item (dynamically allocate)
	GameListNode<T>* temp = new GameListNode<T>;

	//Set fields on temp item. data = e, next = head to place in first position.
	temp->data = e;
	temp->next = m_head;

	//Set list head to temp
	m_head = temp;

	//increment length
	m_length++;

}



//*****************************************************
// Function: GameList.Add() Function Definition 
// 
// Purpose: Adds all elements from otherList on to the current list (appends). 
//			Any data that exists in this instance before this function call should 
//			still be in the list after the function call completes.
//			It does not matter where you add the elements.
//			The otherList object should not change after this method is run. 
//			This should perform a DEEP COPY of the elements from the other list.
//
//		EX: Here is sample call(assume aand b are GameList type objects):
// 
//			a.Add(b); // All elements of b will be added to a
// 
// Update Information:
// ------------------------------------------
//*****************************************************
template <class T>
void GameList<T>::Add(const GameList<T>& otherList)
{

}



//*****************************************************
// Function: GameList.FindGame(std::string title, Game& result)  -- Function Definition 
// 
// Purpose: Finds the game with the given title. If the game is found the 
//			result parameter should be populated with data from the target game.
//			If found the function should return	true and otherwise return false.
// 
// Update Information:
// ------------------------------------------
//*****************************************************
template <class T>
bool GameList<T>::FindGame(std::string title, Game & result) const
{

}



//*****************************************************
// Function: GameList.Delete(std::string title)  -- Function Definition 
// 
// Purpose: Deletes the game that matches the passed in title. Remember, when items are 
//			removed you MUST release memory
// 
// Update Information:
// ------------------------------------------
//*****************************************************
template <class T>
void GameList<T>::Delete(std::string title)
{

}



//*****************************************************
// Function: GameList.operator<< -- Non-Member Overload 
// 
// Purpose: Deletes the game that matches the passed in title. Remember, when items are 
//			removed you MUST release memory
// 
// Update Information:
// ------------------------------------------
//*****************************************************
template <class T>
std::ostream& operator<<(std::ostream os, GameList<T>& rhs)
{

}



template <class T>
std::istream& operator>>(std::istream is, GameList<T>& rhs)
{

}