#pragma once

#include <iostream>;
#include <string>;

#include "Game.h"


template <class T>
struct GameListNode {
	T data;
	GameListNode<T> *next;
};

template <class T>
class GameList
{
public:
	GameList();
	GameList(const GameList& otherList);
	~GameList();

	GameList operator=(GameList& rhs);

	void clear();
	int length() const; //O(1)
	void Add(const Game e);
	void Add(const GameList<T>& otherList);
	bool FindGame(std::string title, Game& result) const;
	void Delete(std::string title);

	friend std::ostream& operator<<(std::ostream& os, GameList& rhs);

	friend std::istream& operator>>(std::istream& is, GameList& rhs);

private:
	GameListNode* m_head;
	GameListNode* m_current;
	int m_iter;
	
};

