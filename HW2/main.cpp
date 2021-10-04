#include <iostream>
#include "GameStorage.h"
#include "Game.h"

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

void testGame(Game&);



int main() {
	//Declare Games and Game List Tests
	//Default GameStorage constructor test
	GameStorage list; //Default size of 3

	//Paramterized Constructor Game Test
	Game game1("Witcher 3", "Mature", 39.99);

	//Default Constructor Game Test
	Game game2;
	game2.setTitle("Rocket League");
	game2.setEsrb("Everyone");
	game2.setPrice(49.99);

	//Copy Constructor, Game Test
	Game game3 = game1;

	//Getters and overload operator<< test
	testGame(game1);
	testGame(game2);


	/********************************  GameStorage  *******************************/
	list.Set(0, game1);
	list.Set(1, game2);
	list.Set(2, game3);

	std::cout << "-------------GameStorage: Test-------------" << std::endl;
	std::cout << list.Get(0) << std::endl;
	std::cout << list.Get(1) << std::endl;
	std::cout << list.Get(2) << std::endl;


	//GameStorage: PriceCount # of games in range
	std::cout << "Number of games between prices $15.00 and $45.00: \n" << list.gamePriceCount(15.00, 45.00) << std::endl;

	//GameStorage: Most Expensize game in list
	std::cout << list.mostExpensive() << std::endl;

	//GameStorage: Find Game by Title Boolean.
	std::cout << list.findByTitle("Witcher 3", game1) << std::endl;

	//GameStorage: Total Price of Games in List
	std::cout << "Total price of games: $" << list.priceTotal() << std::endl;

	//GameStorage: Size of Storage Array
	std::cout << "Size of List: " << list.size() << std::endl;

	//GameStorage: Initialize Games back to default
	list.initialize();


	//GameStorage: Author test
	std::cout << list.getAuthor();



}

void testGame(Game& game) {
	std::cout << "--------Game Class test ------------\n";
	std::cout << game.getTitle() << std::endl;
	std::cout << game.getEsrb() << std::endl;
	std::cout << game.getPrice() << std::endl;


	std::cout << "Non-member overload operator<< test:\n" << game << std::endl;

}
