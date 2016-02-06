#include "Equipment.h"
#include "Hero.h"
#include "Bonus.h"

Equipment::Equipment(sf::Vector2f position, std::string const& name, std::vector <std::string> const& text,
	sf::Font const& font, std::vector <Bonus*> *bonus, int price)
	: Card(position, name, text, font)
{
	m_owner = NULL;
	m_bonus = bonus;
	m_price = price;
}

std::vector <Bonus*> *Equipment::getBonus()
{
	return m_bonus;
}

void Equipment::action(Hero* hero)
{
	if (m_bonus != NULL)
	{
		std::cout << "Equipment action" << std::endl;
		if (!hero->haveThisEquip((std::string)m_name.getString()))
		{
			for (int i = 0; i < m_bonus->size(); i++)
			{
				(*m_bonus)[i]->applyBonus(hero);
			}
			hero->addEquipment(this);
			m_owner = hero;
		}
	}
}

GameState Equipment::getGameState()
{
	return GameState::ACTION;
}

std::vector <Bonus*> *Equipment::use()
{
	return NULL;
}

void Equipment::deleteBonus()
{
	if (m_bonus != NULL)
	{
		for (int i = 0; i < m_bonus->size(); i++)
		{
			if ((*m_bonus)[i]->getCanBeRemoved() && m_owner != NULL)
				(*m_bonus)[i]->deleteBonus(m_owner);
		}
	}
}

EquipmentType Equipment::getType()
{
	return EquipmentType::OTHER;
}