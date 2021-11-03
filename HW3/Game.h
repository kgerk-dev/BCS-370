#pragma once
//***************************************************************************************
// File: Game.h
//
// Purpose: Declarations class member functions
//
// Written By: Kyle Gerken
//
// Compiler: Visual C++ 2019
//
// Update Information:
// -----------------------------
// Name: Kyle Gerken
// Date: 10/29/2021 -- Original version used form HW1 / HW2.
// 
// Description:		- Created Private member variables: Title, ESRB, and Price
//					- Created appropriate Set/Get methods
//					- Overloaded "operator=" and "operator<<"  for appropriate object usage
// 
// Name: Kyle Gerken
// Date: 10/29/2021
//					- For HW3, no changes have been done to Game.h/.cpp as of yet.
//
//***************************************************************************************
#include <iostream>
#include <string>
#include <iomanip>


class Game
{
	//Members = Title, ESRB, and Price for Game Class
private:
	std::string* m_title;
	std::string* m_esrb;
	double* m_price;

public:
	/*************** Constructors *******************/
	//Default constructor
	Game();
	//Paramaterized Constructor
	Game(std::string title, std::string esrb, double price);
	//Copy Constructor
	Game(const Game& obj);
	//Destructor
	~Game();

	/**************** Setters *********************/
	void SetTitle(std::string title);

	void SetEsrb(std::string esrb);

	void SetPrice(double d);

	/*************** Getters ***********************/
	std::string GetTitle();

	std::string GetEsrb();

	double GetPrice();

	/********* Assignment overloads ************/
	//Member overload
	Game& operator=(const Game& rhs);

	//Non-Member overloads
	friend std::ostream& operator<<(std::ostream& os, const Game& rhs);

	friend std::istream& operator>>(std::istream& is, const Game& rhs);
};