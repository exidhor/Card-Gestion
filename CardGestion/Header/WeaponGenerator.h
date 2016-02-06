#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "ClassicBonus.h"
#include "DamageBonus.h"
#include "Generator.h"
#include "Weapon.h"

/*
Créer les cartes Weapon
*/
class WeaponGenerator : public Generator < Weapon >
{
private:
	std::vector <int> m_cardNotAllowed;
public:
	WeaponGenerator(sf::Font const& font);
	
	// cartes
	Weapon* createMatraque();
	Weapon* createTongue();
	Weapon* createPoele();
	Weapon* createPetiteCuillere();
};