#include "NotFighterGenerator.h"

NotFighterGenerator::NotFighterGenerator(sf::Font const& font)
	: Generator(font)
{
	m_cards.insert(std::pair<std::string, NotFighter*>(m_keyGenerator.createKey("PetitCaillou"), createPetitCaillou()));
	m_cards.insert(std::pair<std::string, NotFighter*>(m_keyGenerator.createKey("LaFilleDuQuartier"), createLaFilleDuQuartier()));
	
	std::cout << "NotFighterGenerator : ";
	test();
}


NotFighter* NotFighterGenerator::createDontFightChoice(NotFighter* fighter,
	std::vector <std::string> const& text)
{
	return new NotFighter(sf::Vector2f(0, 0), fighter->getName(), text, rfont, fighter->getBonus());
}


// ------------ cartes ------------------------------
NotFighter* NotFighterGenerator::createPetitCaillou()
{
	std::string name = "Petit Caillou";
	std::vector <std::string> text;
	text.push_back("Inflige 1 degat a moins");
	text.push_back("que vous possediez");
	text.push_back("'Tongue'");
	Bonus* bonus = new ClassicBonus(NULL, Caracteristic::LIFE, -1, Counter::haveTongue);

	return new NotFighter(sf::Vector2f(0,0), name, text, rfont, bonus);
}

NotFighter* NotFighterGenerator::createLaFilleDuQuartier()
{
	std::string name = "La fille du quartier";
	std::vector <std::string> text;
	text.push_back("Te fais perdre ton temps :");
	text.push_back("CHOIX :");
	std::string textBonus1 = "- 100po";
	text.push_back(textBonus1);
	text.push_back(" OU ");
	std::string textBonus2 = "- 2 VIE";
	text.push_back(textBonus2);
	Bonus* bonus = new ClassicBonus(NULL, Caracteristic::LIFE, -1, Counter::haveTongue);

	//creation de la carte
	NotFighter* notFighter = new NotFighter(sf::Vector2f(0, 0), name, text, rfont, bonus);

	//ajout des choix
	std::vector < Card* > choices;

	std::vector <std::string> textBonusCard1;
	textBonusCard1.push_back(textBonus1);
	choices.push_back(createDontFightChoice(notFighter, textBonusCard1));

	std::vector <std::string> textBonusCard2;
	textBonusCard2.push_back(textBonus2);
	choices.push_back(createDontFightChoice(notFighter, textBonusCard2));

	notFighter->setChoices(choices);

	return notFighter;
}