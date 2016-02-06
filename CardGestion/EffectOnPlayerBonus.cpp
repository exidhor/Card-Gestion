#include "EffectOnPlayerBonus.h"

EffectOnPlayerBonus::EffectOnPlayerBonus(effect effectOnPlayer,
	int value, counterVerification counter)
	:Bonus(NULL, counter, false, 0, GameState::PAUSE)
{
	m_effectOnPlayer = effectOnPlayer;
	m_value = value;
}

Bonus* EffectOnPlayerBonus::applyBonus(Hero* hero)
{
	m_effectOnPlayer(hero, m_value);

	if (m_typeOfDurabiltyTimer != GameState::PAUSE)
		return this;

	return NULL;
}

void EffectOnPlayerBonus::deleteBonus(Hero* hero)
{

}


// ----------------- EFFECT -------------------
void Effect::stealEquipment(Hero* hero, int number)
{
	hero->deleteRandomEquipment(number);
}