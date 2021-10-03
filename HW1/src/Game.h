#pragma once
//****************************************************
//File: Game.h
//
//Purpose: Creates Game identifiers.
//
//Written by: Kyle Gerken
//
//Compiler: Visual C++ 2019
//
//
//
//
//
//
//****************************************************




#include <iostream>
#include <string>
#include <iomanip>

class Game
{
	//Members = Title, ESRB, and Price for Game Class
private:
	std::string m_title;
	std::string m_esrb;
	double m_price;

public:
	/*************** Constructors *******************/
	//Default constructor
	Game();
	//Paramaterized Constructor
	Game(std::string title, std::string esrb, double price);
	//Copy Constructor
	Game(const Game& obj);

	/**************** Setters *********************/
	void setTitle(std::string title);

	void setEsrb(std::string esrb);

	void setPrice(double d);

	/*************** Getters ***********************/
	std::string getTitle();

	std::string getEsrb();

	double getPrice();

	/********* Assignment overloads ************/
	//Member overload
	Game& operator=(const Game& rhs);

	//Non-Member overload
	friend std::ostream& operator<<(std::ostream& os, const Game& g);
};

