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
	m_title = obj.title;
	m_esrb = obj.esrb;
	m_price = obj.price;
}

/************* Setters ****************/
void Game::setTitle(std::string t) {
	title = t;
}

void Game::setEsrb(std::string e) {
	esrb = e;
}

void Game::setPrice(double d) {
	price = d;
}

/************* Getters ****************/

std::string Game::getTitle() {
	return m_title;
}

std::string Game::getEsrb() {
	return m_esrb;
}

double Game::getPrice() {
	return m_price;
}
