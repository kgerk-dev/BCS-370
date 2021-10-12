#include <iostream>
#include "GameStorage_HW2.h"
#include "Game_HW2.h"

//*******************************************************
//File: main.cpp
//
//Purpose: Main file to istantiate Game and GameStorage Classes
// 
// Written By: Kyle Gerken
// 
// Compiler: Visual C++ 2019
// 
// Update Information:
//*******************************************************


void AssignGames(GameStorage*);


int main() {
	//Declare Games and Game List Tests
	//Default GameStorage constructor test

	

	// ***************** Test for Game Class ******************************
	Game game1("Witcher 3", "Mature", 39.99);
	//operator<< test -- game1;
	//std::cout << "Game Class: Paramterized Constructor Test " << game1 << std::endl; 

	Game game2;
	game2.SetTitle("Rocket League");
	game2.SetEsrb("Everyone");
	game2.SetPrice(20.00);
	//std::cout << "Game Class: Default Constructor Test " << game2 << std::endl;
	
	Game game3 = game2;
	//std::cout << "Game Class: Copy Constructor Test " << std::endl
	//	<< "Game 2:\t" << game2 << "\nGame 3: \t" << game3 << std::endl;

	/*std::cout << "operator>> Test. Enter a Game when prompted." << std::endl;
	Game game4;
	std::cout << "Enter in order: Title, Esrb, and price, EX: \"Title\", \"ESRB\", 00.00" << std::endl;
	std::cin >> game4;
	std::cout << "Your Game input: \n" << game4.GetTitle() << "\t"
		<< game4.GetEsrb() << "\t" << game4.GetPrice() << std::endl;*/


	//****************** GameStorage Class Tests ********************************
	GameStorage* gs = nullptr;

	gs = new GameStorage[5];
	//List One 3 games
	gs->Set(0, game1);
	gs->Set(1, game2);
	gs->Set(2, game3);
	std::cout << gs << std::endl;
	
	



	


}

void AssignGames(GameStorage *list) {
	//*********************** GAMES LIST ******************************************
	
	
	Game game3("Age Of Empires IV", "Teen", 49.99);
	Game game4("Apex Legends", "Teen", 00.00);
	Game game5("Witcher 2: Kings Assassin", "Mature", 15.99);
	Game game6("Fifa 2021", "Everyone", 59.99);
	Game game7("Among Us", "Everyone", 4.99);
	Game game8("Farcry 6", "Mature", 59.99);
	Game game9("Satifactory", "Everyone", 20.00);
	Game game10("NBA 2k21", "Everyone", 59.99);


	//*********************** ASSIGN LIST GAMES 1 - 10 *****************************
	
	
	list->Set(2, game3);
	list->Set(3, game4);
	list->Set(4, game5);
	list->Set(5, game6);
	list->Set(6, game7);
	list->Set(7, game8);
	list->Set(8, game9);
	list->Set(9, game10);
}