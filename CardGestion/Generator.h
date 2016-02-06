#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <unordered_map>
#include "KeyGenerator.h"
#include "stdlib.h"
#include "Card.h"
#include "Key.h"

/*
Modele de Generator
*/
template <class T>
class Generator
{
protected:
	KeyGenerator m_keyGenerator;
	std::unordered_map<std::string, T*> m_cards;
	sf::Font rfont;
	std::vector <int> m_cardNotAllowed;
public:
	Generator(sf::Font const& font)
	{
		rfont = font;
		time_t* t;
		srand(time(NULL));
	}

	T* select();
	void test();
};

template <class T>
T* Generator<T>::select()
{
	if (m_cards.size() == 0)
	{
		std::cerr << "Aucune carte dans cette table" << std::endl;
	}

	int index = rand() % (m_keyGenerator.getNumberKeys());
	
	return m_cards[m_keyGenerator.selectString(index)];
}

template <class T>
void Generator<T>::test()
{
	if (m_cards.size() == m_keyGenerator.getNumberKeys())
		std::cout << " OK (";
	else
		std::cout << "ERROR !!! (" << m_cards.size();
	std::cout << m_keyGenerator.getNumberKeys() << ")" << std::endl;
}