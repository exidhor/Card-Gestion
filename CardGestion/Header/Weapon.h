#pragma once
#include "Equipment.h"

class DamageBonus;

/*
Equipement qui permet d'avoir des Damage
*/
class Weapon : public Equipment
{
private:
	DamageBonus* m_damageBonus;
public:
	Weapon(sf::Vector2f position, std::string const& name, std::vector <std::string> const& text,
		sf::Font const& font, std::vector <Bonus*> *bonus, int damage, int price);
	~Weapon();

	virtual void deleteBonus();
	virtual void action(Hero* hero);
	virtual std::vector <Bonus*> *use();
	virtual EquipmentType getType();

	int getDamage();
};