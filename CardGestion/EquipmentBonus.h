#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Bonus.h"
#include "EquipmentGenerator.h"	
#include "EdibleGenerator.h"

/*
Reception d'un equipement par le joueur
*/
class EquipmentBonus : public Bonus
{
private:
	Equipment* equipment;
public:
	EquipmentBonus();
};