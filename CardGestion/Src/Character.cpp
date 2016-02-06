#include "Character.h"

Character::Character(int life, int strength)
{
	m_life = life;
	m_strength = strength;
}

void Character::receiveDamage(unsigned int damage)
{
	m_life -= damage;
	if (m_life < 0)
		m_life = 0;
}

bool Character::isAlive()
{
	return m_life > 0;
}

int Character::attack()
{
	return m_strength;
}

void Character::addLife(int life)
{
	m_life += life;
	if (m_life < 0)
		m_life = 0;
}

void Character::addStrength(int strength)
{
	m_strength += strength;
	if (m_strength < 0)
		m_strength = 0;
}

int Character::getStrength()
{
	return m_strength;
}

int Character::getLife()
{
	return m_life;
}