#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Generator.h"
#include "NotFighter.h"
#include "ClassicBonus.h"
#include "Counter.h"

/**Cree les cartes monster, puis les
partage avec CardGenerator
*/
class NotFighterGenerator : public Generator<NotFighter>
{
private:
	std::vector <int> m_cardNotAllowed;
public:
	NotFighterGenerator(sf::Font const& font);

	NotFighter* createDontFightChoice(NotFighter* fighter,
		std::vector <std::string> const& text);

	//cartes
	NotFighter* createPetitCaillou();
	NotFighter* createLaFilleDuQuartier();
};