#include <iostream>
#include <string>
#include <fstream>
#include <vector>

// Included Project Files
#include "Game.h"
#include "GameList.h"

struct GameTypes {
	std::string title;
	std::string esrb;
	double price;
};

int main() 
{
	//read game data file.
	std::vector<GameTypes>games;
	GameTypes temp;
	GameList gl;
	std::ifstream infile;
	infile.open("GameData.txt", std::ios::in);

	if (infile.is_open())
	{
		std::cout << "Your file has an error";
	}
	else
	{
		while (getline(infile, temp.title ))
		{
			getline(infile, temp.esrb);
			infile >> temp.price;
		}

		for (int i = 0; i < games.size(); i++)
		{
			std::cout << games[i].title << " " << games[i].esrb << " " << games[i].price << std::endl;
		}
	}
}