#pragma once
#include "NotFighterGenerator.h"
#include "FighterGenerator.h"
#include "NotFighter.h"

#define PURCENT_GET_NOTFIGHTER 50
#define PURCENT_GET_FIGHTER 50

/*
Effectue les requetes select
*/
class SelectorMonster
{
private:
	NotFighterGenerator* m_notFighterGenerator;
	FighterGenerator* m_fighterGenerator;

public:
	SelectorMonster(FighterGenerator* fighterGenerator,
		NotFighterGenerator* notFighterGenerator);

	std::vector <Card*> select(int nb);
};