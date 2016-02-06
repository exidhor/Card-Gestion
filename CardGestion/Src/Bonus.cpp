#include "Bonus.h"

Bonus::Bonus(Character* target, counterVerification counter, bool canBeRemoved,
	int durability, GameState typeOfDurabilityTimer)
{
	m_target = target;
	m_counterBonus = counter;
	m_canBeRemoved = canBeRemoved;
	m_durability = durability;
	m_typeOfDurabiltyTimer = typeOfDurabilityTimer;
}

Character* Bonus::getTarget()
{
	return m_target;
}

void Bonus::setTarget(Character* target)
{
	m_target = target;
}

GameState Bonus::getTypeOfDurabilityTimer()
{
	return m_typeOfDurabiltyTimer;
}

void Bonus::decreaseDurability()
{
	m_durability--;
	if (m_durability < 0)
		m_durability = 0;
}

bool Bonus::isWorking()
{
	return m_durability > 0;
}

bool Bonus::getCanBeRemoved()
{
	return m_canBeRemoved;
}