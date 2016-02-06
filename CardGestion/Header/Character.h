#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

/**Personnages disposant de vie pouvant
recevoir des coups
*/
class Character
{
protected:
	int m_life;
	int m_strength;
public:
	Character(int life, int strength);

	void receiveDamage(unsigned int damage);
	bool isAlive();
	virtual int attack();

	// getters
	int getStrength();
	int getLife();

	//ajouts
	void addLife(int life);
	void addStrength(int strength);
};