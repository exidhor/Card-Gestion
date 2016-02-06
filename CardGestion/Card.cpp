#include "Card.h"
#include "Hero.h"

Card::Card()
	: m_background(sf::Vector2f(WIDTH_CARD, HEIGHT_CARD)),
	m_framedName(sf::Vector2f(WIDTH_FRAMEDNAME, HEIGHT_FRAMEDNAME)),
	m_framedText(sf::Vector2f(WIDTH_FRAMEDTEXT, HEIGHT_FRAMEDTEXT))
{
	m_isFocused = false;

	m_background.setOutlineColor(sf::Color::Yellow);
	setPosition(sf::Vector2f(0, 0));
	m_background.setFillColor(sf::Color::White);
	m_framedName.setFillColor(sf::Color::Cyan);
	m_framedText.setFillColor(sf::Color::Magenta);
}

Card::Card(sf::Vector2f position)
	: Card()
{
	setPosition(position);
}

Card::Card(sf::Vector2f position, std::string const& name, std::vector <std::string> const& text,
	sf::Font const& font, std::vector <Card*> choices)
	: Card(position)
{
	m_name.setColor(sf::Color::Black);
	m_name.setStyle(sf::Text::Bold);
	m_name.setString(name);
	m_name.setFont(font);
	m_name.setScale(0.43f, 0.43f);
	
	for (int i = 0; i < text.size(); i++)
	{
		m_text.push_back(sf::Text(text[i], font));
		m_text[i].setColor(sf::Color::White);
		m_text[i].setStyle(sf::Text::Bold);
		m_text[i].setScale(0.33f, 0.33f);
	}
	setPosition(position);

	m_choices = choices;
}

Card::Card(Card const& card)
	: m_background(card.m_background),
	m_framedName(card.m_framedName),
	m_framedText(card.m_framedText),
	m_text(card.m_text),
	m_name(card.m_name)
{
	m_isFocused = card.m_isFocused;
}

/*
place la carte a partir du coin haut gauche du fond de la carte
*/
void Card::setPosition(sf::Vector2f position)
{
	m_background.setPosition(position);
	
	float xFramedName = position.x + (WIDTH_CARD - WIDTH_FRAMEDNAME) / 2;
	float yFramedName = position.y + (WIDTH_CARD - WIDTH_FRAMEDNAME) / 2;
	m_framedName.setPosition(xFramedName, yFramedName);

	float xFramedText = position.x + (WIDTH_CARD - WIDTH_FRAMEDTEXT) / 2;
	float yFramedText = position.y + HEIGHT_CARD - 
		(WIDTH_CARD - WIDTH_FRAMEDTEXT) / 2 - HEIGHT_FRAMEDTEXT;
	m_framedText.setPosition(xFramedText, yFramedText);

	m_name.setPosition(xFramedName, yFramedName);
	for (int i = 0; i < m_text.size(); i++)
	{
		m_text[i].setPosition(xFramedText, yFramedText + i*10);
	}
}

sf::Vector2f Card::getPosition()
{
	return m_background.getPosition();	
}

void Card::draw(sf::RenderWindow & window)
{
	window.draw(m_background);
	window.draw(m_framedName);
	window.draw(m_framedText);
	for (int i = 0; i < m_text.size(); i++)
	{
		window.draw(m_text[i]);
	}
	window.draw(m_name);
}

bool Card::manageFocusing(sf::Vector2i mousePosition)
{
	if (!m_isFocused)
	{
		if (m_background.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
		{
			//m_isFocused = true;
			//m_background.setOutlineThickness(3);
			return true;
		}
		return false;
	}
	else
	{
		if (!m_background.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
		{
			//m_isFocused = false;
			//m_background.setOutlineThickness(0);
			return false;
		}
		return true;
	}
}

sf::Vector2f Card::getSize()
{
	return m_background.getSize();
}

void Card::test()
{
	std::cout << "Card" << std::endl;
}

GameState Card::getGameState()
{
	return GameState::DRAFT;
}

void Card::action(Hero* hero)
{
	std::cout << "Card action" << std::endl;
	//return m_choices;
}

std::string Card::getName()
{
	return m_name.getString();
}

void Card::setChoices(std::vector <Card*> & choices)
{
	m_choices = choices;
}

std::vector <Card*> Card::getChoice()
{
	return m_choices;
}