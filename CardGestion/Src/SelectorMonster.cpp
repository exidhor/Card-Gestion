#include "SelectorMonster.h"

SelectorMonster::SelectorMonster(FighterGenerator* fighterGenerator,
	NotFighterGenerator* notFighterGenerator)
{
	m_fighterGenerator = fighterGenerator;
	m_notFighterGenerator = notFighterGenerator;
}

std::vector <Card*> SelectorMonster::select(int nb)
{
	std::vector <Card*> cardsSelected;// = new std::vector <Card*>();
	for (int i = 0; i < nb; i++)
	{
		int index = rand() % (PURCENT_GET_NOTFIGHTER + PURCENT_GET_FIGHTER);
		if (index <= PURCENT_GET_NOTFIGHTER)
		{
			cardsSelected.push_back(m_notFighterGenerator->select());
		}
		else
		{
			cardsSelected.push_back(m_fighterGenerator->select());
		}
	}
	return cardsSelected;
}
