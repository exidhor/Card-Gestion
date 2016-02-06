#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "ClassicBonus.h"
#include "Generator.h"
#include "Equipment.h"

/**Cree les cartes equipments
*/

class EquipmentGenerator : public Generator<Equipment>
{
private:
	std::vector <int> m_cardNotAllowed;
public:
	EquipmentGenerator(sf::Font const& font);

	//cartes
	Equipment* createPorteMonaie();
	Equipment* createCarteDeLaVille();
	Equipment* createCagoule();
	Equipment* createChaineEnOr();
};