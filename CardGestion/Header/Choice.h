#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Card.h"

/*
Nouvelles selections de choix qui pop quand
on selectionne la carte qui possede ces choix
*/
class Choice
{
protected:

public:
	Card* m_display;
	std::vector <Choice*> m_choices;
	Choice(Card* display, std::vector <Choice*> choices);
};

