#include "SelectorEquipment.h"

SelectorEquipment::SelectorEquipment(EquipmentGenerator* equipmentGenerator,
	EdibleGenerator* edibleGenerator, WeaponGenerator* weaponGenerator)
{
	m_equipmentGenerator = equipmentGenerator;
	m_edibleGenerator = edibleGenerator;
	m_weaponGenerator = weaponGenerator;
}

std::vector <Card*> SelectorEquipment::select(int nb)
{
	std::vector <Card*> cardsSelected; //= new std::vector <Card*>();
	for (int i = 0; i < nb; i++)
	{
		int index = rand() % (PURCENT_GET_EQUIPMENT + PURCENT_GET_EDIBLE
			+ PURCENT_GET_WEAPON); 
		if (index <= PURCENT_GET_EQUIPMENT)
		{
			cardsSelected.push_back(m_equipmentGenerator->select());
		}
		else if (index <= PURCENT_GET_EQUIPMENT + PURCENT_GET_EDIBLE)
		{
			cardsSelected.push_back(m_edibleGenerator->select());
		}
		else
		{
			cardsSelected.push_back(m_weaponGenerator->select());
		}
	}
	return cardsSelected;
}