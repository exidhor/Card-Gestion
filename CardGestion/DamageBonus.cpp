#include "DamageBonus.h"

DamageBonus::DamageBonus(Character* target, int value)
	:Bonus(target, NULL, true)
{
	m_value = value;
}

Bonus* DamageBonus::applyBonus(Hero* hero)
{
	hero->addDamage(m_value);

	return NULL;
}

void DamageBonus::deleteBonus(Hero* hero)
{
	hero->addDamage(-m_value);
}

int DamageBonus::getValue()
{
	return m_value;
}