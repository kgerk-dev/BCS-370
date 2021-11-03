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
GameList::GameList() {
	m_head = nullptr;
	m_tail = nullptr;
	m_length = 0;
}



//*****************************************************
// Function: GameList(const GameList<T>& otherList) --  Copy Constructor Definition
// 
// Purpose: Rule of Three Part 1. Copy Constructor
// 
// Update Information:
// ------------------------------------------
//*****************************************************

GameList::GameList(const GameList& otherList) 
{
	GameListNode* temp = otherList.m_head;
	GameListNode* current = m_head;

	m_length = otherList.m_length;

	//Clear the list if the nodes are full.
	if (m_head != nullptr)
	{
		Clear();
	}
	//Check if otherList is empty. Set private members to null if otherList is empty.
	if (m_head == nullptr)
	{
		m_head = nullptr;
		m_tail = nullptr;
	}
	else
	{
		// Set current pointer to list that should be copied.
		current = otherList.m_head;

		m_length = otherList.m_length;

		// Now Copy the Nodes from referenced list to current list.
		m_head = new GameListNode;
		m_head->data = current->data;
		m_head->next = nullptr; //link pointer (next) must be set to null (last position).
		m_tail = m_head; 

		//iterate to next node
		m_head = m_head->next;

		//last position set. Copy remaining nodes into list.
		while (current != nullptr) 
		{
			temp = new GameListNode;
			temp->data = current->data;
			temp->next = nullptr;

			m_tail->next = temp;
			m_tail = temp;

			current = current->next;
		}
	}
}//end Copy Constructor



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
GameList::~GameList() 
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
GameList GameList::operator=(GameList& rhs)
{
	if (this != &rhs)
	{
		GameListNode* temp;
		GameListNode* current;

		if (m_head == nullptr)
		{
			Clear();
		}
		if (rhs.m_head == nullptr)
		{
			m_head = nullptr;
			m_tail = nullptr;
			m_length = 0;
		}
		else
		{
			// Set current pointer to list that should be copied.
			current = rhs.m_head;

			m_length = rhs.m_length;

			// Now Copy the Nodes from referenced list to current list.
			m_head = new GameListNode;
			m_head->data = current->data;
			m_head->next = nullptr; //link pointer (next) must be set to null (last position).
			m_tail = m_head;

			//iterate to next node
			m_head = m_head->next;

			//last position set. Copy remaining nodes into list.
			while (current != nullptr)
			{
				temp = new GameListNode;
				temp->data = current->data;
				temp->next = nullptr;

				m_tail->next = temp;
				m_tail = temp;

				current = current->next;
			}
		}
	}

	return *this;
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
void GameList::Clear() 
{
	GameListNode* temp;

	while (m_head != nullptr) 
	{
		temp = m_head;
		m_head = m_head->next;
		delete temp;
	}

	m_tail = nullptr;

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
int GameList::Length() const 
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
void GameList::Add(const Game e) {

	//Create new NodeType item (dynamically allocate)
	GameListNode* temp = new GameListNode;

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

void GameList::Add(const GameList& otherList)
{
	GameListNode* temp, * newNode;

	newNode = new GameListNode;

	newNode->data = m_head->data; //reads data in head
	newNode->next = m_head; //points to next node after head

	if (m_head == nullptr)
	{
		//empty original list
		m_head = newNode;
	}
	else
	{
		temp = m_head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		//add new nodes to end of list
		GameListNode* otherNode;
		otherNode = otherList.m_head;

		while (otherNode != nullptr)
		{
			temp->data = otherNode->data;
			temp = temp->next;
			otherNode = otherNode->next;
		}

		temp->next = newNode;
	}

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
bool GameList::FindGame(std::string title, Game & result) const
{
	GameListNode* temp;
	bool found = false; // identify if result in search is True

	// temp node should point to first node in list.
	temp = m_head;

	while (temp != nullptr && !found)
	{
		if (temp->data.GetTitle() == title)
		{
			found = true;
		}
		else
		{
			// set temp to iterate to next node.
			temp = temp->next;
		}
	}

	return found;
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
void GameList::Delete(std::string title)
{
	GameListNode* location = m_head, * tempLocation = nullptr;
	// 1. Find the target item to delete (title)
	

	//		a. The start item is the target item.
	if (title == location->data.GetTitle())
	{	
		m_head = m_head->next;
		delete location;
		m_length--;
	}
	else
	{
		//		b. The target item is elsewhere in the list
		while ((location->next != nullptr) && (title != (location->next)->data.GetTitle()))
		{
			location = location->next;
		}

		if (location->next == nullptr) { return; } //No Target

		// 2. Updating the pointers in the list so that the target item is removed
		tempLocation = location->next = (location->next)->next;
		// 3. Deallocate the target item so memory for that item is given back to the system.
		delete tempLocation;
		// 4. Decrement the length
		m_length--;
	}

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

std::ostream& operator<<(std::ostream& os, GameList& rhs)
{
	GameListNode* location = rhs.m_head;
	while (location != nullptr)
	{
		os << location->data << std::endl;
		rhs.m_head = rhs.m_head->next;
	}
	return os;
}


std::istream& operator>>(std::istream& is, GameList& rhs)
{
	

	return is;
}






