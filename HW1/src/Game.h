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
	std::string getTitle();

	std::string getEsrb();

	double getPrice();
};

