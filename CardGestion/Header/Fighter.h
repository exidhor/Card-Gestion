#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Monster.h"
#include "Character.h"
#include "Bonus.h"

/**Carte fighter
qui lance un combat
*/
class Fighter : public Monster, public Character
{
private:
	std::vector <Bonus*> m_rewards;
	int m_initiative;
public:
	Fighter(int life, int strength, sf::Vector2f position, std::string const& name,
		std::vector <std::string> const& text, sf::Font const& font, Bonus* bonus,
		int initiative, std::vector <Bonus*> rewards,
		std::vector <Card*> choices = std::vector <Card*>());

	bool isAlive();

	virtual void action(Hero* hero);
	virtual void test();

	std::vector <Bonus*> getReward();
	virtual GameState getGameState();
	int getInitiative();
};