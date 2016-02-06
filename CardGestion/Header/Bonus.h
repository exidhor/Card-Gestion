#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "GameState.h"
#include "Hero.h"

typedef bool (*counterVerification)(Hero*);

/**Effet modifiant les caracteristiques,
ayant une cible
*/
class Bonus
{
protected:
	Character* m_target;
	counterVerification m_counterBonus;
	bool m_canBeRemoved;
	int m_durability;
	GameState m_typeOfDurabiltyTimer;
public:
	Bonus(Character* target = NULL, counterVerification counter = NULL,
		bool canBeRemoved = false, int durability = 1, GameState typeOfDurabilityTimer = GameState::PAUSE);

	//getters
	Character* getTarget();
	GameState getTypeOfDurabilityTimer();
	bool getCanBeRemoved();

	//setters
	void setTarget(Character* target);

	void decreaseDurability();
	bool isWorking();

	virtual Bonus* applyBonus(Hero* hero) = 0;
	virtual void deleteBonus(Hero* hero) = 0;
};