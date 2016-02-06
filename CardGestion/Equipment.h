#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Card.h"
#include "EquipmentType.h"

class Bonus;
/**Carte Equipement
*/
class Equipment : public Card
{
protected:
	Hero* m_owner;
	std::vector <Bonus*> *m_bonus;
	int m_price;
public:
	Equipment(sf::Vector2f position, std::string const& name, std::vector <std::string> const& text,
		sf::Font const& font, std::vector <Bonus*> *bonus, int price);
	//~Equipment();

	virtual void deleteBonus();
	virtual void action(Hero* hero);
	virtual std::vector <Bonus*> *use();
	virtual EquipmentType getType();

	std::vector <Bonus*> *getBonus();
	GameState getGameState();
};