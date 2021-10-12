#include "Game_HW2.h"
//***************************************************************************************
// File: Game.cpp
//
// Purpose: Definitions for Class member functions. Creates Game, identified with Title,ESRB,Price.
//
// Written By: Kyle Gerken
//
// Compiler: Visual C++ 2019
//
// Update Information:
// -----------------------------
// Name: Kyle Gerken
// Date: 9/18/2021
// Description: 	- Created Private member variables: Title, ESRB, and Price
//					- Created appropriate Set/Get methods
//					- Overloaded "operator=" and "operator<<"  for appropriate object usage
// 
// Name: Kyle Gerken
// Date: 10/3/2021
//
//***************************************************************************************

//*****************************************************
// Function: Game Default Constructor
// 
// Purpose: Initialize member variables of Game to default values
// 
// Update Information:
// ------------------------------------------
// 
// Name: Kyle Gerken
// Date: 10/3/2021
// Description: All member variables were changed to pointers. Instantiated new data types.
// 
//*****************************************************
Game::Game() {
	m_title = new std::string;
	*m_title = "NoTitle";

	m_esrb = new std::string;
	*m_esrb = "NoESRB";

	m_price = new double;
	*m_price = 0.0;
}



//*****************************************************
// Function: Game Paramterized Constructor
// 
// Purpose: Initialize member variables passed in from initialized Class Object
// 
// Update Information:
// ------------------------------------------
// Name: Kyle Gerken
// Date: 10/3/2021
// Description:	Paramterized Constructor modified for dynamic allocation of member variables set to pointers.
//*****************************************************
Game::Game(std::string title, std::string esrb, double price)
{
	m_title = new std::string;
	*m_title = title;

	m_esrb = new std::string;
	*m_esrb = esrb;

	m_price = new double;
	*m_price = price;
}



//*****************************************************
// Function: Game Copy Constructor
// 
// Purpose: Deep copy of Game object values passed into paramter. Writes over default member values.
// 
// Update Information:
// ------------------------------------------
// Name: Kyle Gerken
// Date: 10/3/2021
// Description: Added for HW2, member variables were set as pointers. 
//*****************************************************
Game::Game(const Game& copy)
{	//Deep copy of member variables
	m_title = new std::string;
	*m_title = *copy.m_title;

	m_esrb = new std::string;
	*m_esrb = *copy.m_esrb;

	m_price = new double;
	*m_price = *copy.m_price;
}



//*****************************************************
// Function: Game Destructor
// 
// Purpose: Deallocates new member variables initialized from constructors
// 
// Update Information:
// ------------------------------------------
// Name: Kyle Gerken
// Date: 10/3/2021
// Description: Destructor deallocates member variables and releases pointer ot memory
//*****************************************************
Game::~Game() {
	delete m_title;
	m_title = nullptr;
	delete m_esrb;
	m_esrb = nullptr;
	delete m_price;
	m_price = nullptr;
}



//*****************************************************
// Function: setTitle
// 
// Purpose: Changes value of Title
// 
// Update Information:
// ------------------------------------------
// Name: Kyle Gerken	
// Date: 10/3/2021
// Description: Changed member to a pointer
//*****************************************************
void Game::SetTitle(std::string title) {
	*m_title = title;
}


//*****************************************************
// Function: Set member function: ESRB
// 
// Purpose: Changes value of ESRB
// 
// Update Information:
// ------------------------------------------
// Name: Kyle Gerken
// Date: 10/3/2021
// Description: Changed varaible to a pointer
//*****************************************************
void Game::SetEsrb(std::string esrb)
{
	*m_esrb = esrb;
}

//*****************************************************
// Function: Set member function: Price
// 
// Purpose: Changes value of Price
// 
// Update Information:
// ------------------------------------------
// Name: Kyle Gerken
// Date: 10/3/2021
// Description: Changed varaible to a pointer
//*****************************************************
void Game::SetPrice(double price) {
	*m_price = price;
}



//*****************************************************
// Function: Get member function: Title
// 
// Purpose: Returns value of Game:Title
// 
// Update Information:
// ------------------------------------------
// Name: Kyle Gerken
// Date: 10/3/2021
// Description: Changed return variable to a pointer
//*****************************************************
std::string Game::GetTitle()
{
	return *m_title;
}


//*****************************************************
// Function: Get member function: ESRB
// 
// Purpose: Returns value of Game:ESRB
// 
// Update Information:
// ------------------------------------------
// Name: Kyle Gerken
// Date: 10/3/2021
// Description: Changed return variable to a pointer
//*****************************************************
std::string Game::GetEsrb()
{
	return *m_esrb;
}


//*****************************************************
// Function: Get member function: Price
// 
// Purpose: Returns value of Game:Price
// 
// Update Information:
// ------------------------------------------
// Name: Kyle Gerken
// Date: 10/3/2021
// Description: Changed return variable to a pointer
//*****************************************************
double Game::GetPrice()
{
	return *m_price;
}


//*****************************************************
// Function: Assignment Operator Member Overlaod
// 
// Purpose: Overloads operator= to assign one game object passed by reference to other game object
// 
// Update Information:
// ------------------------------------------
// / Name: Kyle Gerken
// Date: 10/3/2021
// Description: Changed member variable and referenced variables of object (rhs) to	pointers.
//				Added an if statement to check if the referenced object was already equal to object 
//				to be copied. Updated function using this to implicitly use the object reference.
//				
//*****************************************************
Game& Game::operator=(const Game& rhs)
{
	if (this == &rhs) 
	{	//returns dereferenced "this"
		return *this;
	}

	this->m_title = rhs.m_title;
	this->m_esrb  = rhs.m_esrb;
	this->m_price = rhs.m_price;

	return *this;
}



//*****************************************************
// Function: Extraction Operator Non-Member Overlaod
// 
// Purpose: Overloads extraction operator "operator<<" to output game objects to console 
// 
// Update Information:
// ------------------------------------------
// 
//*****************************************************
std::ostream& operator<<(std::ostream& os, const Game& g)
{
	os << "\n-----------------------------" << std::endl;
	os << "Title: " << *g.m_title << std::endl;
	os << "ESRB: " << *g.m_esrb << std::endl;
	os << std::fixed << std::setprecision(2) << "Price: $ " << *g.m_price << std::endl;

	return os;
}


//*****************************************************
// Function: operator>>
// 
// Purpose: Overloads insertion operator " >> " as non-member overload to take input directly from user
//			to apply change member values 
// 
// Update Information:
// ------------------------------------------
// 
//*****************************************************
std::istream& operator>>(std::istream& is, const Game& rhs)
{
	is >> *rhs.m_title >> *rhs.m_esrb >> *rhs.m_price;

	return is;
}