#include "WeaponGenerator.h"

WeaponGenerator::WeaponGenerator(sf::Font const& font)
	: Generator(font)
{
	m_cards.insert(std::pair < std::string, Weapon*>(m_keyGenerator.createKey("Matraque"), createMatraque()));
	m_cards.insert(std::pair < std::string, Weapon*>(m_keyGenerator.createKey("Tongue"), createTongue()));
	m_cards.insert(std::pair < std::string, Weapon*>(m_keyGenerator.createKey("Poele"), createPoele()));
	m_cards.insert(std::pair < std::string, Weapon*>(m_keyGenerator.createKey("PetiteCuillere"), createPetiteCuillere()));

	std::cout << "WeaponGenerator : ";
	test();
}

Weapon* WeaponGenerator::createMatraque()
{
	std::string name = "Une matraque";
	std::vector <std::string> text;
	text.push_back("Degats : 5");
	return new Weapon(sf::Vector2f(0, 0), name, text, rfont, NULL, 5, 35);
}


Weapon* WeaponGenerator::createTongue()
{
	std::string name = "Une tongue";
	std::vector <std::string> text;
	text.push_back("Degats : 1");
	text.push_back("+1 en Force");
	text.push_back("'C'est deja ca !'");
	std::vector <Bonus*> *vbonus = new std::vector <Bonus*>();
	Bonus* bonus = new ClassicBonus(NULL, Caracteristic::STRENGTH, 1, NULL, true);
	vbonus->push_back(bonus);
	return new Weapon(sf::Vector2f(0, 0), name, text, rfont, vbonus, 1, 7);
}

Weapon* WeaponGenerator::createPoele()
{
	std::string name = "Une poele";
	std::vector <std::string> text;
	text.push_back("Degats : 3");
	return new Weapon(sf::Vector2f(0, 0), name, text, rfont, NULL, 3, 15);
}

Weapon* WeaponGenerator::createPetiteCuillere()
{
	std::string name = "Une petite cuillère";
	std::vector <std::string> text;
	text.push_back("Degats : 1");
	return new Weapon(sf::Vector2f(0, 0), name, text, rfont, NULL, 1, 3);
}