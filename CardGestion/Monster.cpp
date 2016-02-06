#include "Monster.h"
#include "Hero.h"

Monster::Monster(sf::Vector2f position, std::string const& name,
	std::vector <std::string> const& text, sf::Font const& font, Bonus* bonus,
	std::vector <Card*> choices)
	: Card(position, name, text, font, choices)
{
	m_bonus = bonus;
}

Monster::~Monster()
{
	//delete m_bonus;
}

Bonus* Monster::getBonus()
{
	return m_bonus;
}

void Monster::test()
{
	std::cout << "Monster" << std::endl;
}

GameState Monster::getGameState()
{
	if (m_choices.size() != 0)
	{
		return GameState::CHOICE;
	}

	return GameState::ACTION;
}

 void Monster::action(Hero* hero)
{
	std::cout << "Monster action" << std::endl;
}