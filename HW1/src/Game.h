#pragma once

class Game
{
	//Members = Title, ESRB, and Price for Game Class
private:
	std::string m_title, m_esrb;
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
	void setTitle(std::string s);

	void setEsrb(std::string s);

	void setPrice(double d);

	/*************** Getters ***********************/
	std::string Game::getTitle() const;

	std::string Game::getEsrb() const ;

	double Game::getPrice() const;

	/********* Assignment overloads ************/
	//Member overload
	friend Game& operator=(const Game& rhs);

	//Non-Member overload
	friend std::ostream& operator<<(std::ostream& os, Game& g);
};

