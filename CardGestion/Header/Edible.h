#pragma once
#include "Equipment.h"

/*
Consommable, destructible et activable
*/
class Edible : public Equipment
{
private:
public:
	Edible(sf::Vector2f position, std::string const& name, std::vector <std::string> const& text,
		sf::Font const& font, std::vector <Bonus*> *bonus, int price);
	~Edible();

	virtual void action(Hero* hero);
	virtual std::vector <Bonus*> *use();
	virtual EquipmentType getType();
};