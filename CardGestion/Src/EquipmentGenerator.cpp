#include "EquipmentGenerator.h"

EquipmentGenerator::EquipmentGenerator(sf::Font const& font)
	: Generator(font)
{
	m_cards.insert(std::pair<std::string, Equipment*>(m_keyGenerator.createKey("PorteMonaie"), createPorteMonaie()));
	m_cards.insert(std::pair<std::string, Equipment*>(m_keyGenerator.createKey("CarteDeLaVille"), createCarteDeLaVille()));
	m_cards.insert(std::pair<std::string, Equipment*>(m_keyGenerator.createKey("Cagoule"), createCagoule()));
	m_cards.insert(std::pair<std::string, Equipment*>(m_keyGenerator.createKey("ChaineEnOr"), createChaineEnOr()));

	std::cout << "EquipmentGenerator : ";
	test();
}

//cartes
Equipment* EquipmentGenerator::createPorteMonaie()
{
	std::string name = "Un porte-monnaie";
	std::vector <std::string> text;
	text.push_back("Argent : +100");
	std::vector <Bonus*> *vbonus = new std::vector <Bonus*>();
	Bonus* bonus = new ClassicBonus(NULL, Caracteristic::MONEY, 100, NULL, true);
	vbonus->push_back(bonus);
	return new Equipment(sf::Vector2f(0, 0), name, text, rfont, vbonus, 100);
}

Equipment* EquipmentGenerator::createCarteDeLaVille()
{
	std::string name = "La carte de la ville";
	std::vector <std::string> text;
	text.push_back("Tire une carte de plus");
	text.push_back("pour les 5 prochaines fois");
	text.push_back("!*** TO DO ***!");
	std::vector <Bonus*> *vbonus = new std::vector <Bonus*>();
	Bonus* bonus = new ClassicBonus(NULL, Caracteristic::STRENGTH, 0, NULL, true);
	vbonus->push_back(bonus);
	return new Equipment(sf::Vector2f(0, 0), name, text, rfont, vbonus, 0);
}

Equipment* EquipmentGenerator::createCagoule()
{
	std::string name = "Une cagoule";
	std::vector <std::string> text;
	text.push_back("permet d'eviter la");
	text.push_back("prochaine rencontre");
	text.push_back("!*** TO DO ***!");
	std::vector <Bonus*> *vbonus = new std::vector <Bonus*>();
	Bonus* bonus = new ClassicBonus(NULL, Caracteristic::STRENGTH, 0, NULL, true);
	vbonus->push_back(bonus);
	return new Equipment(sf::Vector2f(0, 0), name, text, rfont, vbonus, 0);
}

Equipment* EquipmentGenerator::createChaineEnOr()
{
	std::string name = "Une chaine en or";
	std::vector <std::string> text;
	text.push_back("Argent : +50");
	text.push_back("Force : +1");
	std::vector <Bonus*> *vbonus = new std::vector <Bonus*>();
	Bonus* bonus = new ClassicBonus(NULL, Caracteristic::MONEY, 50, NULL, true);
	Bonus* bonus2 = new ClassicBonus(NULL, Caracteristic::STRENGTH, 1, NULL, true);
	vbonus->push_back(bonus);
	vbonus->push_back(bonus2);
	return new Equipment(sf::Vector2f(0, 0), name, text, rfont, vbonus, 50);
}
