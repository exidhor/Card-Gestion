#include "Fighter.h"
#include "Hero.h"

Fighter::Fighter(int life, int strength, sf::Vector2f position, std::string const& name, std::vector <std::string> const& text,
	sf::Font const& font, Bonus* bonus, int initiative, std::vector <Bonus*> rewards, std::vector <Card*> choices)
	: Monster(position, name, text, font, bonus, choices), Character(life, strength)
{
	m_rewards = rewards;
	m_initiative = initiative;
}

void Fighter::action(Hero* hero)
{

}

std::vector <Bonus*> Fighter::getReward()
{
	return m_rewards;
}

GameState Fighter::getGameState()
{
	if (m_choices.size() != 0)
	{
		return GameState::CHOICE;
	}

	return GameState::FIGHT;
}

void Fighter::test()
{
	std::cout << "Fighter" << std::endl;
}

int Fighter::getInitiative()
{
	return m_initiative;
}