#include "Edible.h"
#include "Hero.h"
#include "Bonus.h"

Edible::Edible(sf::Vector2f position, std::string const& name, std::vector <std::string> const& text,
	sf::Font const& font, std::vector <Bonus*> *bonus, int price)
	: Equipment(position, name, text, font, bonus, price)
{
	
}
Edible::~Edible()
{

}

void Edible::action(Hero* hero)
{
	hero->addEquipment(this);
}

std::vector <Bonus*> *Edible::use()
{
	return m_bonus;
}

EquipmentType Edible::getType()
{
	return EquipmentType::EDIBLE;
}