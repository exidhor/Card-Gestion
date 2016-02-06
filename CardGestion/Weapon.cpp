#include "Weapon.h"
#include "Hero.h"
#include "Bonus.h"
#include "DamageBonus.h"

Weapon::Weapon(sf::Vector2f position, std::string const& name, std::vector <std::string> const& text,
	sf::Font const& font, std::vector <Bonus*> *bonus, int damage, int price)
	:Equipment(position, name, text, font, bonus, price)
{
	m_damageBonus = new DamageBonus(NULL, damage);
	m_owner = NULL;
}

Weapon::~Weapon()
{
	// TO DO, OR NOT
}

void Weapon::action(Hero* hero)
{
	Equipment::action(hero);
	hero->addWeapon(this);

	if (hero->getDamage() < m_damageBonus->getValue())
	{
		m_damageBonus->applyBonus(hero);
		hero->setEquipedWeapon(this);
	}
}

std::vector <Bonus*> *Weapon::use()
{
	return NULL;
}

EquipmentType Weapon::getType()
{
	return EquipmentType::WEAPON;
}

void Weapon::deleteBonus()
{
	Equipment::deleteBonus();
}

int Weapon::getDamage()
{
	return m_damageBonus->getValue();
}