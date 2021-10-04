#include "Game.h"
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
//Function: Game Default Constructor
// 
// Purpose: Initialize member variables of Game to default values
// 
// Update Information:
// ------------------------------------------
// 
//*****************************************************
Game::Game() {
	m_title = "NoTitle";
	m_esrb = "NoESRB";
	m_price = 0.0;
}



//*****************************************************
//Function: Game Paramterized Constructor
// 
// Purpose: Initialize member variables passed in from initialized Class Object
// 
// Update Information:
// ------------------------------------------
// 
//*****************************************************
Game::Game(std::string title, std::string esrb, double price)
{
	m_title = title;
	m_esrb = esrb;
	m_price = price;
}



//*****************************************************
//Function: Game Copy Constructor
// 
// Purpose: Deep copy of Game object values passed into paramter. Writes over default member values.
// 
// Update Information:
// ------------------------------------------
// 
//*****************************************************
Game::Game(const Game& copy)
{
	//Needs Work Don't Understand Copy Constructors fully. 
	m_title = copy.m_title;
	m_esrb = copy.m_esrb;
	m_price = copy.m_price;
}




//*****************************************************
//Function: Set member function: Ttile
// 
// Purpose: Changes value of Title
// 
// Update Information:
// ------------------------------------------
// 
//*****************************************************
void Game::setTitle(std::string title) {
	m_title = title;
}


//*****************************************************
//Function: Set member function: ESRB
// 
// Purpose: Changes value of ESRB
// 
// Update Information:
// ------------------------------------------
// 
//*****************************************************
void Game::setEsrb(std::string esrb)
{
	m_esrb = esrb;
}

//*****************************************************
//Function: Set member function: Price
// 
// Purpose: Changes value of Price
// 
// Update Information:
// ------------------------------------------
// 
//*****************************************************
void Game::setPrice(double price) {
	m_price = price;
}



//*****************************************************
//Function: Get member function: Title
// 
// Purpose: Returns value of Game:Title
// 
// Update Information:
// ------------------------------------------
// 
//*****************************************************
std::string Game::getTitle()
{
	return m_title;
}


//*****************************************************
//Function: Get member function: ESRB
// 
// Purpose: Returns value of Game:ESRB
// 
// Update Information:
// ------------------------------------------
// 
//*****************************************************
std::string Game::getEsrb()
{
	return m_esrb;
}


//*****************************************************
//Function: Get member function: Price
// 
// Purpose: Returns value of Game:Price
// 
// Update Information:
// ------------------------------------------
// 
//*****************************************************
double Game::getPrice()
{
	return m_price;
}


//*****************************************************
//Function: Assignment Operator Member Overlaod
// 
// Purpose: Overloads operator= to assign one game object passed by reference to other game object
// 
// Update Information:
// ------------------------------------------
// 
//*****************************************************
Game& Game::operator=(const Game& rhs)
{
	m_title = rhs.m_title;
	m_esrb = rhs.m_esrb;
	m_price = rhs.m_price;

	return *this;
}

//*****************************************************
//Function: Extraction Operator Non-Member Overlaod
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
	os << "Title: " << g.m_title << std::endl;
	os << "ESRB: " << g.m_esrb << std::endl;
	os << std::fixed << std::setprecision(2) << "Price: $ " << g.m_price << std::endl;

	return os;
}