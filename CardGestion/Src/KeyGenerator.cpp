#include "KeyGenerator.h"

KeyGenerator::KeyGenerator()
{
	currentIndex = 0;
}

/*Crée une cle et l'ajoute dans la table*/
std::string const& KeyGenerator::createKey(std::string name)
{
	m_keys.push_back(Key(currentIndex, name));
	currentIndex++;

	return m_keys[currentIndex-1].name;
}

/*a partir de l'index, trouve le nom associé et le renvoie*/
std::string KeyGenerator::selectString(int index)
{
	if (index >= 0 && index < m_keys.size())
		return m_keys[index].name;

	else
	{
		std::cout << "ERROR : index out of keyGenerator bounds" << std::endl;
		return m_keys[0].name;
	}
}

// renvoie la taille
int KeyGenerator::getNumberKeys()
{
	return m_keys.size();
}