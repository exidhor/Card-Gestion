#include "NotFighter.h"
#include "Hero.h"

NotFighter::NotFighter(sf::Vector2f position, std::string const& name,
	std::vector <std::string> const& text, sf::Font const& font, Bonus* bonus,
	std::vector <Card*> choices)
	: Monster(position, name, text, font, bonus, choices)
{

}

void NotFighter::test()
{
	std::cout << "NotFighter" << std::endl;
}

void NotFighter::action(Hero* hero)
{
	std::cout << "action not fighter" << std::endl;
	m_bonus->applyBonus(hero);
}