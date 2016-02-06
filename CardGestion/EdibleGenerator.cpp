#include "EdibleGenerator.h"

EdibleGenerator::EdibleGenerator(sf::Font const& font)
	: Generator(font)
{
	m_cards.insert(std::pair<std::string, Edible*>(m_keyGenerator.createKey("Drogue"), createDrogue()));
	m_cards.insert(std::pair<std::string, Edible*>(m_keyGenerator.createKey("HotDog"), createHotDog()));
	m_cards.insert(std::pair<std::string, Edible*>(m_keyGenerator.createKey("Mure"), createMure()));
	m_cards.insert(std::pair<std::string, Edible*>(m_keyGenerator.createKey("CafeSoluble"), createCafeSoluble()));
	m_cards.insert(std::pair<std::string, Edible*>(m_keyGenerator.createKey("Steak70Viande"), createSteak70Viande()));
	m_cards.insert(std::pair<std::string, Edible*>(m_keyGenerator.createKey("YumYum"), createYumYum()));

	std::cout << "EdibleGenerator :";
	test();
}


Edible* EdibleGenerator::createDrogue()
{
	std::string name = "De la droooooogue";
	std::vector <std::string> text;
	text.push_back("+5 de Force pour les 3");
	text.push_back("prochains combats");
	text.push_back("-2 en Vie");
	text.push_back("'La drogue c'est cool mais");
	text.push_back("c'est pas bon pour la");
	text.push_back("sante !'");
	std::vector <Bonus*> *vbonus = new std::vector <Bonus*>();
	Bonus* bonus = new ClassicBonus(NULL, Caracteristic::LIFE, -2, NULL, false);
	Bonus* bonus2 = new ClassicBonus(NULL, Caracteristic::LIFE, -2, NULL, false, 3, GameState::FIGHT);
	vbonus->push_back(bonus);
	vbonus->push_back(bonus2);
	return new Edible(sf::Vector2f(0, 0), name, text, rfont, vbonus, 50);
}

Edible* EdibleGenerator::createHotDog()
{
	std::string name = "Un Hot Dog";
	std::vector <std::string> text;
	text.push_back("+ 3 en force");
	text.push_back("'C'est a peine OP'");
	std::vector <Bonus*> *vbonus = new std::vector <Bonus*>();
	Bonus* bonus = new ClassicBonus(NULL, Caracteristic::STRENGTH, 3, NULL, false);
	vbonus->push_back(bonus);
	return new Edible(sf::Vector2f(0, 0), name, text, rfont, vbonus, 10);
}

Edible* EdibleGenerator::createMure()
{
	std::string name = "La mûre";
	std::vector <std::string> text;
	text.push_back("Vie : +1");
	text.push_back("Force : +1");
	std::vector <Bonus*> *vbonus = new std::vector <Bonus*>();
	Bonus* bonus = new ClassicBonus(NULL, Caracteristic::LIFE, 1, NULL, false);
	Bonus* bonus2 = new ClassicBonus(NULL, Caracteristic::STRENGTH, 1, NULL, false);
	vbonus->push_back(bonus);
	vbonus->push_back(bonus2);
	return new Edible(sf::Vector2f(0, 0), name, text, rfont, vbonus, 5);
}

Edible* EdibleGenerator::createCafeSoluble()
{
	std::string name = "Un café soluble";
	std::vector <std::string> text;
	text.push_back("x2 ta force pour");
	text.push_back("le prochain combat");
	text.push_back("!*** TO DO ***!");
	std::vector <Bonus*> *vbonus = new std::vector <Bonus*>();
	Bonus* bonus = new ClassicBonus(NULL, Caracteristic::STRENGTH, 0, NULL, true);
	vbonus->push_back(bonus);
	return new Edible(sf::Vector2f(0, 0), name, text, rfont, vbonus, 0);
}

Edible* EdibleGenerator::createSteak70Viande()
{
	std::string name = "Un steak 70% viande";
	std::vector <std::string> text;
	text.push_back("Force : +1");
	std::vector <Bonus*> *vbonus = new std::vector <Bonus*>();
	Bonus* bonus = new ClassicBonus(NULL, Caracteristic::STRENGTH, 1, NULL, true);
	vbonus->push_back(bonus);
	return new Edible(sf::Vector2f(0, 0), name, text, rfont, vbonus, 8);
}

Edible* EdibleGenerator::createYumYum()
{
	std::string name = "YumYum";
	std::vector <std::string> text;
	text.push_back("Sagesse : +10");
	text.push_back("Vie : +1");
	text.push_back("'Efficace et pas");
	text.push_back("cher !'");
	std::vector <Bonus*> *vbonus = new std::vector <Bonus*>();
	Bonus* bonus = new ClassicBonus(NULL, Caracteristic::LIFE, 1, NULL, true);
	Bonus* bonus2 = new ClassicBonus(NULL, Caracteristic::WISDOM, 10, NULL, true);
	vbonus->push_back(bonus);
	vbonus->push_back(bonus2);
	return new Edible(sf::Vector2f(0, 0), name, text, rfont, vbonus, 1);
}