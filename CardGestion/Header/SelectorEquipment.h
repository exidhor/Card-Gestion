#pragma once
#include "EquipmentGenerator.h"
#include "EdibleGenerator.h"
#include "WeaponGenerator.h"
#include "Card.h"

#define PURCENT_GET_EQUIPMENT 33
#define PURCENT_GET_EDIBLE 34
#define PURCENT_GET_WEAPON 33

/*
Effectue les requetes select
*/
class SelectorEquipment
{
private:
	EquipmentGenerator* m_equipmentGenerator;
	EdibleGenerator* m_edibleGenerator;
	WeaponGenerator* m_weaponGenerator;

public:
	SelectorEquipment(EquipmentGenerator* equipmentGenerator,
		EdibleGenerator* edibleGenerator, WeaponGenerator* weaponGenerator);

	std::vector <Card*> select(int nb);
};