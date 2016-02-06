#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Bonus.h"

/*
Utiliser pour les weapon, C'est un 
classicBonus qui fonctionne differement
*/
class DamageBonus : public Bonus
{
private:
	int m_value;
public:
	DamageBonus(Character* target, int value);

	virtual Bonus* applyBonus(Hero* hero);
	virtual void deleteBonus(Hero* hero);

	int getValue();
};	