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

	Game game3 = game2;
	Game game4("Apex Legends", "Teen", 00.00);
	Game game5("Witcher 2: Kings Assassin", "Mature", 15.99);
	Game game6("Fifa 2021", "Everyone", 59.99);
	Game game7("Among Us", "Everyone", 4.99);
	Game game8("Farcry 6", "Mature", 59.99);
	Game game9("Satifactory", "Everyone", 20.00);
	Game game10("NBA 2k21", "Everyone", 59.99);
	std::cout << "Game Class: Default Constructor Test " << game2 << std::endl;
	
	
	std::cout << "Game Class: Copy Constructor Test " << std::endl
		<< "Game 2:\t" << game2 << "\nGame 3: \t" << game3 << std::endl;

	std::cout << "operator>> Test. Enter a Game when prompted." << std::endl;

	std::cout << "Enter in order: Title, Esrb, and price, EX: \"Title\", \"ESRB\", 00.00" << std::endl;
	std::cin >> game4;
	std::cout << "Your Game input: \n" << game4.GetTitle() << "\t"
		<< game4.GetEsrb() << "\t" << game4.GetPrice() << std::endl;


	//****************** GameStorage Class Tests ********************************
	GameStorage* gs = nullptr;

	gs = new GameStorage[5];
	//List One 3 games
	gs->Set(0, game1);
	gs->Set(1, game2);
	gs->Set(2, game3);
	gs->Set(3, game4);
	gs->Set(4, game5);
	gs->Set(5, game6);
	gs->Set(6, game7);
	gs->Set(7, game8);
	gs->Set(8, game9);
	gs->Set(9, game10);

	
	
	if (gs->FindByTitle("Rocket League", game2) == true) {
		std::cout << "Test for GameStorage::FindByTitle() == PASS\n" << game2 << std::endl;
	}
	else
	{
		std::cout << "Test for GameStorage::FindByTitle() == FAIL" << game2 << std::endl;
	}

	
	std::cout << "Return pointer address of GameStorage.DeepCopy() - > "  << gs->DeepCopy() << std::endl;
	
	std::cout << *gs << std::endl;
	
	std::cout << "\n----------- Copy Old List into New List Tests-------------\n";

	GameStorage* newStorage = new GameStorage(50);
	//Copy gs into newStorage
	newStorage = gs;
	
	//*****Memory Leak on Resize
	newStorage->ReSize(20);
	//Resize newStorage to only show 3 games of the originial List
	std::cout << *newStorage << std::endl;

	delete[] gs;
	//delete[] newStorage;

}

