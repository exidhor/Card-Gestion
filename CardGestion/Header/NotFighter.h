#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Monster.h"

/**Carte NotFighter
*/
class NotFighter : public Monster
{
protected:

public:
	NotFighter(sf::Vector2f position, std::string const& name,
		std::vector <std::string> const& text, sf::Font const& font,
		Bonus* bonus, std::vector <Card*> choices = std::vector <Card*>());
	
	virtual void test();
	virtual void action(Hero* hero);
};