#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Bonus.h"
#include "Caracteristic.h"

class Equipment;

/**Modifie uniquement les caract de base
*/
class ClassicBonus : public Bonus
{
private:
	Caracteristic m_carac;
	int m_value;
public:
	ClassicBonus(Character* target, Caracteristic carac,
		int value, counterVerification counter = NULL, bool canBeRemoved = false,
		int durability = 1, GameState typeOfDurabilityTimer = GameState::PAUSE);

	virtual Bonus* applyBonus(Hero* hero);
	virtual void deleteBonus(Hero* hero);
};			