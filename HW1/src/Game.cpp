#include "Game.h"

//Defining the Default Constructor
Game::Game() {
	m_title = "NoTitle";
	m_esrb = "NoESRB";
	m_price = 0.0;
}
//Defining Paramaterized constructor
Game::Game(std::string title, std::string esrb, double price)
{
	m_title = title;
	m_esrb = esrb;
	m_price = price;
}
//Defining the Copy Constructor
Game::Game(const Game& copy)
{
	//Needs Work Don't Understand Copy Constructors fully. 
	m_title = copy.m_title;
	m_esrb = copy.m_esrb;
	m_price = copy.m_price;
}

/************* Setters ****************/
void Game::setTitle(std::string title) {
	m_title = title;
}

void Game::setEsrb(std::string esrb)
{
	m_esrb = esrb;
}

void Game::setPrice(double price) {
	m_price = price ;
}

/************* Getters ****************/

std::string Game::getTitle()
{
	return m_title;
}

std::string Game::getEsrb() 
{
	return m_esrb;
}

double Game::getPrice()
{
	return m_price;
}


Game& Game::operator=(const Game& rhs)
{
	m_title = rhs.m_title;
	m_esrb = rhs.m_esrb;
	m_price = rhs.m_price;

	return *this;
}


std::ostream& operator<<(std::ostream& os, const Game& g)
{
	os << "\n-----------------------------" << std::endl;
	os << "Title: " << g.m_title << std::endl;
	os << "ESRB: " << g.m_esrb << std::endl;
	os << std::fixed << std::setprecision(2) <<  "Price: $ " << g.m_price << std::endl;

	return os;
}
