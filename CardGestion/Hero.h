#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Character.h"
#include "Equipment.h"
#include "Weapon.h"

/**Personnage principal, avatar de
l'utilisateur
*/
class Hero : public Character
{
private:
	std::vector <Equipment*> m_equipments;
	std::vector <Weapon*> m_weapons;
	Weapon* m_equipedWeapon;
	//caracteristiques
	int m_money;
	int m_charisma;
	int m_karma;
	int m_wisdom;
	int m_damage;

public:
	Hero();

	// useless
	void draw(sf::RenderWindow & window);

	bool haveThisEquip(std::string const& EquipName);

	//getters
	std::vector <Equipment*> const& getEquipments();
	int getDamage();
	int getKarma();
	int getCharisma();
	int getMoney();
	//setters
	void setEquipedWeapon(Weapon* weapon);

	//ajouts
	void addEquipment(Equipment* equipment);
	void addWeapon(Weapon* weapon);
	void addMoney(int money);
	void addCharisma(int charisma);
	void addKarma(int karma);
	void addWisdom(int wisdom);
	void addDamage(int damage);

	//special effect
	void deleteRandomEquipment(int number);
};