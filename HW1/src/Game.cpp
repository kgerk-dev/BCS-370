#include "Game.h"

//Defining the Default Constructor
Game::Game() {
	m_title = "Unassigned";
	m_esrb = "None";
	m_price = "0.0";
}
//Defining Paramaterized constructor
Game::Game(std::string title, std::string esrb, double price)
{
	title = m_title;
	esrb = m_esrb;
	price = m_price;
}
//Defining the Copy Constructor
Game::Game(const Game& obj)
{
	//Needs Work Don't Understand Copy Constructors fully. 
	m_title = obj.m_title;
	m_esrb = obj.m_esrb;
	m_price = obj.m_price;
}

/************* Setters ****************/
void Game::setTitle(std::string title) {
	m_title = title;
}

void Game::setEsrb(std::string esrb) {
	m_esrb = esrb;
}

void Game::setPrice(double price) {
	m_price = price ;
}

/************* Getters ****************/

std::string Game::getTitle() const
{
	return m_title;
}

std::string Game::getEsrb() const 
{
	return m_esrb;
}

double Game::getPrice() const
{
	return m_price;
}


Game& operator=(const Game& rhs)
{
	m_title = rhs.m_title;
	m_esrb = rhs.m_esrb;
	m_price = rhs.m_price;

	return *this
}

std::ostream& operator<<(std::ostream& os, Game& g)
{
	os << g.m_title << std::endl;
	os << g.m_esrb << std::endl;
	os << g.m_price << std::endl;

	return *this;
}
