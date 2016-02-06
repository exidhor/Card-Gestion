#include "Hero.h"

Hero::Hero()
	: Character(5, 0)
{
	m_charisma = 30;
	m_money = 100;
	m_karma = 50;
	m_damage = 0;	

	m_equipedWeapon = NULL;
}

void Hero::draw(sf::RenderWindow & window)
{

}

void Hero::setEquipedWeapon(Weapon* weapon)
{
	m_equipedWeapon = weapon;
}

void Hero::addEquipment(Equipment* equipment)
{
	m_equipments.push_back(equipment);
}

void Hero::addWeapon(Weapon* weapon)
{
	m_equipments.push_back(weapon);
	m_weapons.push_back(weapon);
}

void Hero::addMoney(int money)
{
	m_money += money;
	if (m_money < 0)
		m_money = 0;
}

void Hero::addCharisma(int charisma)
{
	m_charisma += charisma;
	if (m_charisma < 0)
		m_charisma = 0;
}

void Hero::addKarma(int karma)
{
	m_karma += karma;
	if (m_karma < 0)
		m_karma = 0;
}

void Hero::addWisdom(int wisdom)
{
	m_wisdom += wisdom;
	if (m_wisdom < 0)
		m_wisdom = 0;
}

void Hero::addDamage(int damage)
{
	if (damage > m_damage)
	{
		m_damage = damage;
	}

	else if (damage < 0)
	{
		m_damage += damage;

		// TO DO : trouver les nouveaux degats
	}
}

bool Hero::haveThisEquip(std::string const& EquipName)
{
	for (int i = 0; i < m_equipments.size(); i++)
	{
		if (m_equipments[i]->getName().compare(EquipName) == 0)
			return true;
	}
	return false;
}

std::vector <Equipment*> const& Hero::getEquipments()
{
	return m_equipments;
}

int Hero::getDamage()
{
	return m_damage;
}

int Hero::getKarma()
{
	return m_karma;
}

void Hero::deleteRandomEquipment(int number)
{
	int i;
	for (i = 0; i < number && m_equipments.size() != 0; i++)
	{
		int index = rand() % m_equipments.size();

		if (m_equipments[index]->getType() == EquipmentType::WEAPON)
		{
			for (int j = 0; j < m_weapons.size(); j++)
			{
				if (m_equipments[index] == m_weapons[j])
					m_weapons.erase(m_weapons.begin() + j);
			}

			if (m_equipments[index] == m_equipedWeapon &&
				m_weapons.size() != 0)
			{
				int maxDamage = m_weapons[0]->getDamage();
				int indexMaxDamage = 0;
				for (int h = 1; h < m_weapons.size(); h++)
				{
					if (m_weapons[h]->getDamage() > maxDamage)
					{
						indexMaxDamage = h;
					}
				}
				m_equipedWeapon = m_weapons[indexMaxDamage];
				m_damage = m_equipedWeapon->getDamage();
			}
		}
		m_equipments[index]->deleteBonus();
		m_equipments.erase(m_equipments.begin() + index);
	}
	std::cout << "Equipement ciblé : " << number << " // Equipement supprimé " << i << std::endl;
}

int Hero::getCharisma()
{
	return m_charisma;
}

int Hero::getMoney()
{
	return m_money;
}