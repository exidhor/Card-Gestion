#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "stdlib.h"
#include "Hero.h"	
#include "Fighter.h"
#include "ClassicBonus.h"
#include "NotFighterGenerator.h"
#include "EquipmentGenerator.h"
#include "FighterGenerator.h"
#include "EdibleGenerator.h"
#include "SelectorEquipment.h"
#include "SelectorMonster.h"
//#include "Interface.h"

#define PURCENT_EQUIPMENT 15
#define PURCENT_MONSTER 40
#define PURCENT_INTERACTION_MEETING 25
#define PURCENT_CHOICE_MEETING 20

/**
Represente une partie, gere le deroulement
*/
class Game
{
private:
	//vue
	sf::RenderWindow* m_window;
	//Interface m_interface;
	//modele
	GameState m_gameState;
	GameState m_oldGameState;
	Hero m_hero;
	bool m_clicUsed;
	// GENERATORS !!!
	/*NotFighterGenerator* m_notFighterGenerator;
	EquipmentGenerator* m_equipmentGenerator;
	EdibleGenerator* m_edibleGenerator;
	FighterGenerator* m_fighterGenerator;*/
	// SELECTORS !!
	SelectorEquipment* m_selectorEquipment;
	SelectorMonster* m_selectorMonster;
	
	
	int testi;
	
	//affichage select
	std::vector <Card*> m_cardsDisplay;
	Card* m_cardSelected;
	Card* m_cardChosen;
	std::vector <Entity*> m_entityDisplay;
	std::vector <sf::Vector2f> m_positonCardsDisplay;
	int m_numberCardsDisplay;
	//fight
	std::vector <Bonus*> m_bonusToApplyFight;
	std::vector <Bonus*> m_bonusToApplyDraft;
	bool fight(Fighter* monster);

public:
	Game(sf::RenderWindow* window, FighterGenerator* fighterGenerator,
		NotFighterGenerator* notFighterGenerator, EquipmentGenerator* equipmentGenerator,
		EdibleGenerator* edibleGenerator, SelectorMonster* selectorMonster,
		SelectorEquipment* selectorEquipment, sf::Font const& font);

	std::vector <sf::Vector2f> positionCardsDisplay();
	void inputGestion(sf::Event & e);
	bool gameLoop();
	void drawEntity();
	int manageFocusing(sf::Event & e);
	sf::Vector2f positionCardSelected();
	bool choseCard(sf::Event & e);
	bool printGameState();

	void choiceRandCategory();
	void gestionBonus(GameState gameState);
};