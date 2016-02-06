#pragma once
#include "Bonus.h"

//effet sur le joueur
typedef void(*effect)(Hero*, int number);

/*Bonus qui affecte le joueur, et non ses 
caracteristiques
*/
class EffectOnPlayerBonus : public Bonus
{
protected:
	effect m_effectOnPlayer;
	counterVerification m_counter;
	int m_value;
public:
	EffectOnPlayerBonus(effect,int value = 1, counterVerification = NULL);

	virtual Bonus* applyBonus(Hero* hero);
	virtual void deleteBonus(Hero* hero);
};

/*Les différents effets possibles*/
namespace Effect
{
	void stealEquipment(Hero* hero, int number);
}