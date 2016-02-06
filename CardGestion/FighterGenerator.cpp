#include "FighterGenerator.h"

FighterGenerator::FighterGenerator(sf::Font const& font)
	: Generator(font)
{
	m_cards.insert(std::pair<std::string, Fighter*>(m_keyGenerator.createKey("HommeSandwich"), createHommeSandwich()));
	m_cards.insert(std::pair<std::string, Fighter*>(m_keyGenerator.createKey("Flics"), createFlics()));

	std::cout << "FighterGenerator : ";
	test();
}

// Choice
Fighter* FighterGenerator::createFightChoice(Fighter* fighter)
{
	std::vector <std::string> text;
	text.push_back("     FIGHT !!!");
	return new Fighter(fighter->getLife(), fighter->getStrength(), sf::Vector2f(0, 0), fighter->getName(),
		text, rfont, NULL, fighter->getInitiative(), fighter->getReward());
}

NotFighter* FighterGenerator::createDontFightChoice(Fighter* fighter,
	std::vector <std::string> const& text)
{
	return new NotFighter(sf::Vector2f(0, 0), fighter->getName(), text, rfont, fighter->getBonus());
}

// cartes
Fighter* FighterGenerator::createHommeSandwich()
{
	std::string name = "Homme sandwich";
	std::vector <std::string> text;
	text.push_back("Vie : 2");
	text.push_back("Force : 1");
	text.push_back("");
	text.push_back("Recompense :");
	text.push_back("100po, -10 Karma");
	Bonus* bonus = new ClassicBonus(NULL, Caracteristic::LIFE, 0, Counter::haveTongue);
	
	std::vector <Bonus*> rewards;
	rewards.push_back(new ClassicBonus(NULL, Caracteristic::MONEY, 100, NULL));
	rewards.push_back(new ClassicBonus(NULL, Caracteristic::KARMA, -10, NULL));

	return new Fighter(2, 1, sf::Vector2f(0, 0), name, text, rfont, bonus, 5, rewards);
}

Fighter* FighterGenerator::createFlics()
{
	// creation du texte de la carte
	std::string name = "Les Flics";
	std::vector <std::string> text;
	text.push_back("effectue un controle");
	std::string textBonus = "Vole 2 items";
	text.push_back(textBonus);
	text.push_back("");
	text.push_back("Vie : 6");
	text.push_back("Force : 8");
	text.push_back("");
	text.push_back("Recompense :");
	text.push_back("300po, Matraque,");
	text.push_back("-40 Karma");

	//creation des Bonus
	Bonus* bonus = new EffectOnPlayerBonus(Effect::stealEquipment, 2);

	std::vector <Bonus*> rewards;
	rewards.push_back(new ClassicBonus(NULL, Caracteristic::MONEY, 300, NULL));
	rewards.push_back(new ClassicBonus(NULL, Caracteristic::KARMA, -40, NULL));

	//creation de la carte
	Fighter* fighter = new Fighter(6, 8, sf::Vector2f(0, 0), name, text, rfont, bonus, 5, rewards);

	//ajout des choix
	std::vector < Card* > choices;
	choices.push_back(createFightChoice(fighter));

	std::vector <std::string> textsBonus;
	textsBonus.push_back(textBonus);
	choices.push_back(createDontFightChoice(fighter, textsBonus));

	fighter->setChoices(choices);

	return fighter;
}
