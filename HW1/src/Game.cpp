#include "Game.h"

//Defining the Default Constructor
Game::Game() {	}
//Defining Paramaterized constructor
Game::Game(std::string title, std::string esrb, double price)
{
	m_title = title;
	esrb = "Everyone";
	price = 0.00;
}
//Defining the Copy Constructor
Game::Game(const Game& obj)
{
	//Needs Work Don't Understand Copy Constructors fully. 
	title = obj.title;
	esrb = obj.esrb;
	price = obj.price;
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
	return title;
}

std::string Game::getEsrb() {
	return esrb;
}

double Game::getPrice() {
	return price;
}
