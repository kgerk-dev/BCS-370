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

void AssignGames(GameStorage&);


int main() {
	//Declare Games and Game List Tests
	//Default GameStorage constructor test
	GameStorage* list = nullptr;
	
	int arraySize = GameStorage::SIZE;
	list = new GameStorage[arraySize];
	std::cout << list->size() << std::endl;

	AssignGames(list);



	


}

void AssignGames(GameStorage *list) {
	//*********************** GAMES LIST ******************************************
	Game game1("Witcher 3", "Mature", 39.99);
	Game game2("Rocket League", "Everyone", 20.00);
	Game game3("Age Of Empires IV", "Teen", 49.99);
	Game game4("Apex Legends", "Teen", 00.00);
	Game game5("Witcher 2: Kings Assassin", "Mature", 15.99);
	Game game6("Fifa 2021", "Everyone", 59.99);
	Game game7("Among Us", "Everyone", 4.99);
	Game game8("Farcry 6", "Mature", 59.99);
	Game game9("Satifactory", "Everyone", 20.00);
	Game game10("NBA 2k21", "Everyone", 59.99);


	//*********************** ASSIGN LIST GAMES 1 - 10 *****************************
	list->Set(0, game1);
	list->Set(1, game2);
	list->Set(2, game3);
	list->Set(3, game4);
	list->Set(4, game5);
	list->Set(5, game6);
	list->Set(6, game7);
	list->Set(7, game8);
	list->Set(8, game9);
	list->Set(9, game10);
}