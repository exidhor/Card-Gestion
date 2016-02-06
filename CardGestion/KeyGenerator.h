#pragma once
#include <iostream>
#include <vector>
#include "Key.h"

/*
cree les cles, et permet d'acceder a un nom
a partir d'un id
*/
class KeyGenerator
{
private:
	int currentIndex;
	std::vector <Key> m_keys;
public:
	KeyGenerator();
	std::string const& createKey(std::string name);
	std::string selectString(int index);

	int getNumberKeys();
};