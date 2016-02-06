#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "GameState.h"
#include "Entity.h"

#define HEIGHT_CARD 200
#define WIDTH_CARD 150
#define HEIGHT_FRAMEDNAME 25
#define WIDTH_FRAMEDNAME 130
#define HEIGHT_FRAMEDTEXT 100
#define WIDTH_FRAMEDTEXT 130

class Hero;


/**Carte affichée, avec son nom et son texte
*/
class Card : public Entity
{
protected:
	//correspond a la taille complete de la carte
	sf::RectangleShape m_background;
	//correspond a l'espace du nom
	sf::RectangleShape m_framedName;
	//correspond a l'espace du texte
	sf::RectangleShape m_framedText;
	bool m_isFocused;
	sf::Text m_name;
	std::vector <sf::Text> m_text;
	std::vector <Card*> m_choices;
public:
	Card();
	Card(sf::Vector2f position);
	Card(sf::Vector2f position, std::string const& name,
		std::vector <std::string> const& text, sf::Font const& font,
		std::vector <Card*> choices = std::vector <Card*>());
	Card(Card const& card);

	// affichage
	void draw(sf::RenderWindow & window);
	bool manageFocusing(sf::Vector2i mousePosition);

	virtual void test();
	virtual GameState getGameState();
	virtual void action(Hero* hero);

	// getters
	sf::Vector2f getPosition();
	sf::Vector2f getSize();
	std::string getName();
	std::vector <Card*> getChoice();

	//setters
	void setChoices(std::vector <Card*> & choices);
	void setPosition(sf::Vector2f position);
};