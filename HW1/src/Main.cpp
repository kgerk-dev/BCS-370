#include "Game.h"
#include "GameStorage.h"
#include <iostream>
#include <string>


void testGame(Game &);



int main() {
	//Declare Games and Game List Tests
	GameStorage list; //Default size of 3

	Game game1("Witcher 3", "Mature", 39.99);

	Game game2;
	game2.setTitle("Rocket League");
	game2.setEsrb("Everyone");
	game2.setPrice(19.99);

	//testGame(game1);

	//testGame(game2);
	

	list.Set(0, game1);
	list.Set(1, game2);
	/*std::cout << list.Get(0) << std::endl;
	std::cout << list.Get(1) << std::endl;

	std::cout << "Number of games between prices $15.00 and $45.00: \n" << list.gamePriceCount(15.00, 45.00) << std::endl;*/

	/*Game mostExpensive = list.mostExpensive();
	std::cout << mostExpensive << std::endl;*/

	//std::cout << list.findByTitle("Witcher 3", game1) << std::endl;

	//std::cout << "Total price of games: $" << list.priceTotal() << std::endl;

	//std::cout << "Size of List: " << list.size() << std::endl;

	//list.initialize();

	std::cout << list.Get(0) << list.Get(1) << list.Get(2)<< std::endl;

	std::cout << list.getAuthor();


					
}

void testGame(Game &game) {
	std::cout << game.getTitle() << std::endl;
	std::cout << game.getEsrb() << std::endl;
	std::cout << game.getPrice() << std::endl;

	std::cout << game << std::endl;

}

