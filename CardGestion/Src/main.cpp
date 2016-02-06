#pragma once
#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "KeyGenerator.h"
#include "Card.h"
#include "Game.h"
#include "WeaponGenerator.h"
#include "EquipmentGenerator.h"
#include "EdibleGenerator.h"
#include "NotFighterGenerator.h"
#include "FighterGenerator.h"
#include "SelectorEquipment.h"
#include "SelectorMonster.h"
#include "Interface.h"

//ESPACE NAME : 17
//ESPACE TEXT : 23

// TO DO :
// FINIR CE PUTAIN DE BUG DINTERFACE
// Finir les Class Bonus
// refaire de facon generique les counters
// ajout d'aleatoirité dans les armes
// Faire la class ClassicMeeting
// Lier l'apparition des monstres au Karma
// Faire l'interface de l'equipement
// Equipement :
//		->Gestion de use() consomable

int main(void)
{
	//gestion Font
	sf::Font fontArial;
	if (!fontArial.loadFromFile("arial.ttf"))
	{
		std::cerr << "Error while loading font" << std::endl;
	}

	int widthWindow = 1000;
	int heightWindow = 600;
	
	// GENERATORS !!!
	
	NotFighterGenerator notFighterGenerator(fontArial);
	FighterGenerator fighterGenerator(fontArial);
	EdibleGenerator edibleGenerator(fontArial);
	EquipmentGenerator equipmentGenerator(fontArial);
	WeaponGenerator weaponGenerator(fontArial);

	// SELECTORS !!
	SelectorEquipment selectorEquipment(&equipmentGenerator, &edibleGenerator,
		&weaponGenerator);
	SelectorMonster selectorMonster(&fighterGenerator, &notFighterGenerator);

	sf::RenderWindow window(sf::VideoMode(widthWindow, heightWindow), "Card Gestion");
	window.setFramerateLimit(100);

	//Interface testInterface(window.getSize(), 1, fontArial, NULL);

	std::cout << "Window : x(" << window.getSize().x << ")  y(" << window.getSize().y << ")\n";

	Game game(&window, &fighterGenerator, &notFighterGenerator, &equipmentGenerator,
		&edibleGenerator, &selectorMonster, &selectorEquipment, fontArial);
		
	while (window.isOpen())
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		game.gameLoop();
	}

	return 0;
}