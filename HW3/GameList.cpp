#include "GameList.h"

//constexpr int MAX_ITEMS = 100;

template <class T>
GameList<T>::GameList() {
	m_head = nullptr;
	m_current = nullptr;
	m_iter = 0;
}

template <class T>
GameList<T>::GameList(const GameList<T>& otherList) 
{

	GameListNode<T>* newNode = nullptr;
	GameListNode<T>* currentNode = nullptr;

	if (m_head != nullptr) 
	{
		Delete();
	}

	if (otherList.m_head == nullptr) 
	{
		m_head = nullptr;
		m_current = nullptr;
		m_iter = 0;
	}
	else 
	{
		currentNode = otherList.m_head;

		m_iter = otherList.m_iter;

		m_head = new GameListNode<T>;
		m_head->data = currentNode->data;
		m_head->next = nullptr;
		m_current = m_head;
		currentNode = currentNode->next;

		while (currentNode != nullptr) 
		{
			newNode = new GameListNode<T>;
			newNode->data = currentNode->data;
			newNode->next = nullptr;
			m_current->next = newNode;
			m_current = newNode;

			currentNode = currentNode->next;
			
		} // end while

	}//end else
}//end Constructor

template <class T>
GameList<T>::~GameList() 
{
	GameListNode<T>* tempNode;

	while (m_head != nullptr) 
	{
		tempNode = m_head;
		m_head = m_head->next;
		delete tempNode;
	}

	m_current = nullptr;

	m_iter = 0;
}

template <class T>
void GameList<T>::clear() 
{
	GameListNode<T>* tempNode;

	while (m_head != nullptr) 
	{
		tempNode = m_head;
		m_head = m_head->data;
		delete tempNode;
	}

	m_current = nullptr;

	m_iter = 0;
}

template <class T>
int GameList<T>::length() const 
{
	return m_iter;
}

template <class T>
void GameList<T>::Add(const Game e) {
	GameListNode<T>* tempNode = new GameListNode<T>;

	tempNode->data = e;
	tempNode->next = m_current;


}
