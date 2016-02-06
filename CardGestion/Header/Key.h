#pragma once
#include <iostream>

/*
Tuple du nom(string) et de son identifiant(int)
*/
class Key
{
public:
	std::string name;
	int index;

	Key(int aindex, std::string aname)
	{
		name = aname;
		index = aindex;
	}
};