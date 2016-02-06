#include "ClassicBonus.h"
#include "Equipment.h"

ClassicBonus::ClassicBonus(Character* target, Caracteristic carac,
	int value, counterVerification counter, bool canBeRemoved,
	int durability, GameState typeOfDurabilityTimer)
	: Bonus(target, counter, canBeRemoved, durability, typeOfDurabilityTimer)
{
	m_carac = carac;
	m_value = value;
}

Bonus* ClassicBonus::applyBonus(Hero* hero)
{
	if (m_counterBonus != NULL && m_counterBonus(hero))
		return NULL;

	switch (m_carac)
	{
		case Caracteristic::CHARISMA :
			hero->addCharisma(m_value);
			break;

		case Caracteristic::KARMA :
			hero->addKarma(m_value);
			break;

		case Caracteristic::LIFE :
			hero->addLife(m_value);
			break;

		case Caracteristic::MONEY :
			hero->addMoney(m_value);
			break;

		case Caracteristic::STRENGTH :
			hero->addStrength(m_value);
			break;

		case Caracteristic::WISDOM :
			hero->addWisdom(m_value);
			break;

		case Caracteristic::DAMAGE:
			hero->addDamage(m_value);
			break;

		default :
			std::cout << "Caracteristique non pris en compte dans"
				"l'application des bonus" << std::endl;
	}
	if (m_typeOfDurabiltyTimer != GameState::PAUSE)
		return this;

	return NULL;
}

void ClassicBonus::deleteBonus(Hero* hero)
{
	if (m_canBeRemoved)
	{
		m_value *= -1;
		applyBonus(hero);
	}
}