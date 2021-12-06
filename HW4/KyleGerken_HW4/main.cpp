#include <iostream>

#include "Game.h"
#include "BST.h"
#include <string>

using namespace std;

//*******************************************************
//File: main.cpp
//
//Purpose: Main file for HW4, using a Binsary Search Tree Class
// 
// Written By: Kyle Gerken
// 
// Compiler: Visual C++ 2019
// 
// Update Information:
// Name: Kyle Gerken
// Date: 12/6/2021
// Description:
//			- Transferrred Project from Visual Studio 2019 to Visual Studio 2022.
//			  Small bug fixes but .sln file compiles correctly after update.
//*******************************************************

int main() {
	Game g1("Witcher 3", "Mature", 39.99);
	Game g2("Rocket League", "Everyone", 20.00);
	Game g3("Fallout New Vegas", "Teen", 14.99);
	Game g4("Satisfactory", "Everyone", 29.99);

	
	BST bst;
	bst.Add(g1);
	bst.Add(g2);
	bst.Add(g3);
	bst.Add(g4);
	cout << bst.Size() << endl;

	BST bst2 = bst;

	cout << bst2 << endl;

	bst2.Clear();

	BST bst3;
	
	
	bst.InOrder();
	
	bst.PreOrder();

	bst.PostOrder();

	string str = g1.GetTitle();
	double pr = g1.GetPrice();

	cout << bst.GetGameScore(str, pr) << endl;


	// Single Delete of Game form Tree
	// Not apart of HW
	bst.DeleteNode(g2);

	cout << bst << endl;
}