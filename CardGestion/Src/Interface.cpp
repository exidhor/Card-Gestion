#include "Interface.h"

Interface::Interface(sf::Vector2u windowSize, int posYBottomCard, sf::Font const& font, Hero* hero)
	
	: m_graphicParty(sf::Vector2f(2 * windowSize.x / 3, windowSize.y - (posYBottomCard + windowSize.y / 10))),
	
	m_infoHeroBackground(sf::Vector2f(windowSize.x - m_graphicParty.getSize().x - windowSize.x / 25,
		m_graphicParty.getSize().y)),
	
	m_inventory(sf::Vector2f(m_infoHeroBackground.getSize().x, 2 * m_infoHeroBackground.getSize().y / 3))
{
	/*
	m_item1.setSize(sf::Vector2f(2, 1));
	m_item2.setSize(sf::Vector2f(2, 1));
	*/
	//BIDON = 0;
	/*std::cout << "item 1 : " << m_item1.getSize().x << std::endl;
	std::cout << "item 2 : " << m_item1.getSize().x << std::endl;*/

	m_hero = hero;

	m_graphicParty.setFillColor(sf::Color::Blue);
	m_infoHeroBackground.setFillColor(sf::Color::White);
	m_inventory.setFillColor(sf::Color::Red);

	m_graphicParty.setPosition(0, posYBottomCard + windowSize.y / 10);
	m_infoHeroBackground.setPosition(m_graphicParty.getSize().x + windowSize.x / 25,
		m_graphicParty.getPosition().y);
	m_inventory.setPosition(m_infoHeroBackground.getPosition().x,
		m_infoHeroBackground.getPosition().y + m_infoHeroBackground.getSize().y / 3);

	//sert pour l'affichage en 2 colonnes
	int column = 0;
	int x = 0;
	for (int i = 0; i < 6; i++)
	{
		if (i == 3)
		{
			x = 0;
			column = m_infoHeroBackground.getSize().x / 2;
		}

		m_caracteristicName.push_back(sf::Text());
		m_caracteristicName[i].setColor(sf::Color::Black);
		m_caracteristicName[i].setStyle(sf::Text::Bold);
		m_caracteristicName[i].setFont(font);
		m_caracteristicName[i].setScale(0.43f, 0.43f);
		m_caracteristicName[i].setPosition(m_infoHeroBackground.getPosition().x
			+ m_infoHeroBackground.getSize().x / 25 + column,
			m_infoHeroBackground.getPosition().y + x * 20 + 10);

		std::cout << "x : " << m_caracteristicName[i].getPosition().x;
		std::cout << "    y : " << m_caracteristicName[i].getPosition().y << std::endl;

		m_caracteristicValue.push_back(sf::Text());
		m_caracteristicValue[i].setColor(sf::Color::Black);
		m_caracteristicValue[i].setStyle(sf::Text::Bold);
		m_caracteristicValue[i].setFont(font);
		m_caracteristicValue[i].setScale(0.43f, 0.43f);
		m_caracteristicValue[i].setPosition(m_infoHeroBackground.getPosition().x
			+ 100 + column,
			m_infoHeroBackground.getPosition().y + x * 20 + 10);
		x++;
	}
	m_caracteristicName[0].setString("vie");
	m_caracteristicName[1].setString("degats");
	m_caracteristicName[2].setString("force");
	m_caracteristicName[3].setString("charisme");
	m_caracteristicName[4].setString("argent");
	m_caracteristicName[5].setString("karma");
}

void Interface::draw(sf::RenderWindow & window)
{
	m_caracteristicValue[0].setString(std::to_string(m_hero->getLife()));
	m_caracteristicValue[1].setString(std::to_string(m_hero->getDamage()));
	m_caracteristicValue[2].setString(std::to_string(m_hero->getStrength()));
	m_caracteristicValue[3].setString(std::to_string(m_hero->getCharisma()));
	m_caracteristicValue[4].setString(std::to_string(m_hero->getMoney()));
	m_caracteristicValue[5].setString(std::to_string(m_hero->getKarma()));

	window.draw(m_graphicParty);
	window.draw(m_infoHeroBackground);
	window.draw(m_inventory);

	for (int i = 0; i < m_caracteristicName.size(); i++)
	{
		window.draw(m_caracteristicName[i]);
		window.draw(m_caracteristicValue[i]);
	}
}

void Interface::setHero(Hero* hero)
{
	m_hero = hero;
}