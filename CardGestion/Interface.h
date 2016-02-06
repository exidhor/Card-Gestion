#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Hero.h"

/*
Dessine toute l'interface
*/
class Interface
{
private:
	sf::RectangleShape m_graphicParty;
	sf::RectangleShape m_infoHeroBackground;
	sf::RectangleShape m_inventory;
	std::vector <sf::Text> m_caracteristicName;
	std::vector <sf::Text> m_caracteristicValue;
	//sf::RectangleShape m_item1;
	//sf::RectangleShape m_item2;

	Hero* m_hero;

public:
	Interface(sf::Vector2u windowSize, int posYBottomCard, sf::Font const& font,
		Hero* hero);

	void setHero(Hero* hero);
	void draw(sf::RenderWindow & window);
};