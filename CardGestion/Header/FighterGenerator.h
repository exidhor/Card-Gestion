#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "EffectOnPlayerBonus.h"
#include "NotFighter.h"
#include "Choice.h"
#include "Generator.h"
#include "Fighter.h"
#include "ClassicBonus.h"
#include "Counter.h"

/**Cree les cartes monster
*/
class FighterGenerator : public Generator<Fighter>
{
private:
	std::vector <int> m_cardNotAllowed;
public:
	FighterGenerator(sf::Font const& font);

	//generic choice
	Fighter* createFightChoice(Fighter* fighter);
	NotFighter* createDontFightChoice(Fighter* fighter,
		std::vector <std::string> const& text);

	//cartes
	Fighter* createHommeSandwich();
	Fighter* createFlics();
};