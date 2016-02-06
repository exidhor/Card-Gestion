#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Card.h"
#include "Bonus.h"

/**Carte Monster
*/
class Monster : public Card
{
protected:
	Bonus *m_bonus;
public:
	Monster(sf::Vector2f position, std::string const& name,
		std::vector <std::string> const& text,
		sf::Font const& font, Bonus* bonus = NULL, 
		std::vector <Card*> choices = std::vector <Card*> ());
	~Monster();

	virtual void test();
	virtual void action(Hero* hero);

	Bonus* getBonus();
	virtual GameState getGameState();
}; 