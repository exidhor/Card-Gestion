#include "Counter.h"

bool Counter::haveTongue(Hero* hero)
{
	if (hero->haveThisEquip("Une tongue"))
		return true;
	
	return false;
}