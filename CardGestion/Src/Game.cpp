#include "Game.h"

Game::Game(sf::RenderWindow* window, FighterGenerator* fighterGenerator,
	NotFighterGenerator* notFighterGenerator, EquipmentGenerator* equipmentGenerator,
	EdibleGenerator* edibleGenerator, SelectorMonster* selectorMonster,
	SelectorEquipment* selectorEquipment, sf::Font const& font)
	: m_hero()/*,
	m_interface(window->getSize(), (window->getSize().y - HEIGHT_CARD) / 4 + HEIGHT_CARD,
	font, &m_hero)*/
{
	testi = 0;
	m_cardSelected = NULL;
	m_window = window;
	/*m_fighterGenerator = fighterGenerator;
	m_notFighterGenerator = notFighterGenerator;
	m_equipmentGenerator = equipmentGenerator;
	m_edibleGenerator = edibleGenerator;*/
	m_selectorMonster = selectorMonster;
	m_selectorEquipment = selectorEquipment;
	m_numberCardsDisplay = 1;
	m_gameState = GameState::DRAFT;
	m_oldGameState = GameState::PAUSE;
	m_clicUsed = false;
}

bool Game::gameLoop()
{
	std::cout << testi << std::endl;
	testi++;
	sf::Event e;
	m_clicUsed = false;
	inputGestion(e);

	drawEntity();

	printGameState();

	if (m_gameState == GameState::DRAFT)
	{
		m_cardSelected = NULL;
		choseCard(e);
	}

	if (m_gameState == GameState::FIGHT)
	{
		fight((Fighter*)m_cardSelected);
		m_gameState = GameState::PAUSE;
	}

	else if (m_gameState == GameState::CHOICE)
	{
		// TO DO
		if (m_cardSelected != NULL)
		{
			m_cardChosen = m_cardSelected;
			m_cardSelected = NULL;
			m_cardsDisplay = m_cardChosen->getChoice();

			std::cout << "SIZE position : " << m_cardsDisplay.size() << std::endl;
			m_positonCardsDisplay = positionCardsDisplay();
		}

		choseCard(e);
	}
	
	else if (m_gameState == GameState::ACTION)
	{
		m_cardSelected->action(&m_hero);
		m_gameState = GameState::PAUSE;
	}

	else if (m_gameState == GameState::PAUSE)
	{
		// TO DO
	}

	return true;
}

/*verifie que l'utilisateur clic sur une carte,
et la place dans cardSelected*/
bool Game::choseCard(sf::Event & e)
{
	int indexCardSelected;
	if (!m_clicUsed && (indexCardSelected = manageFocusing(e)) != -1)
	{
		m_cardSelected = m_cardsDisplay[indexCardSelected];
		m_positonCardsDisplay = positionCardsDisplay();
		m_gameState = m_cardSelected->getGameState();
		std::cout << "Choix fait" << std::endl;
		m_cardSelected->test();
		m_clicUsed = true;
		return true;
	}

	return false;
}

/*Dessine tout*/
void Game::drawEntity()
{
	if (m_window == NULL)
	{
		std::cout << "NULL" << std::endl;
	}
	m_window->clear();
	
	if (m_cardSelected == NULL && m_cardsDisplay.size() != 0)
	{
		for (int i = 0; i < m_cardsDisplay.size(); i++)
		{
			m_cardsDisplay[i]->setPosition(m_positonCardsDisplay[i]);
			m_cardsDisplay[i]->draw(*m_window);
		}
	}
	else if (m_cardSelected != NULL)
	{
		m_cardSelected->setPosition(positionCardSelected());
		m_cardSelected->draw(*m_window);
	}

	//m_interface.draw(*m_window);

	m_window->display();
}

/**
Gere les entrees joueurs hors controles du jeu
*/
void Game::inputGestion(sf::Event & event)
{
	while (m_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window->close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			choiceRandCategory();
			m_positonCardsDisplay = positionCardsDisplay();
			m_gameState = GameState::DRAFT;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			std::cout << "Equipements : ";
			for (int i = 0; i < m_hero.getEquipments().size(); i++)
			{
				std::cout << m_hero.getEquipments()[i]->getName() << " | ";
			}
			std::cout << std::endl;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			m_numberCardsDisplay--;
			if (m_numberCardsDisplay < 0)
				m_numberCardsDisplay = 0;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			m_numberCardsDisplay++;
		}
	}
}

/**
Calcul la position des cartes en fonction du nombre de carte à
afficher
*/
std::vector <sf::Vector2f> Game::positionCardsDisplay()
{
	std::vector <sf::Vector2f> position;
	float widthWindow =(float) m_window->getSize().x;
	float heightWindow =(float) m_window->getSize().y;

	float x = (widthWindow - m_cardsDisplay.size() * WIDTH_CARD) /
		(m_cardsDisplay.size() + 1);
	float y = (heightWindow - HEIGHT_CARD) / 4;

	for (int i = 0; i < m_cardsDisplay.size(); i++)
	{
		position.push_back(sf::Vector2f((i + 1) * x + i * WIDTH_CARD, y));
	}
	return position;
}

sf::Vector2f Game::positionCardSelected()
{
	float widthWindow = (float)m_window->getSize().x;
	float heightWindow = (float)m_window->getSize().y;

	float x = (widthWindow - WIDTH_CARD) / 2;
	float y = (heightWindow - HEIGHT_CARD) / 4;

	return sf::Vector2f(x, y);
}

/**
Gere ce que regarde le joueur
@return l'indice de la carte selectionnée par le joueur
ou -1 si pas de carte selectionnée
*/
int Game::manageFocusing(sf::Event & e)
{
	if (m_cardSelected == NULL && m_cardsDisplay.size() != 0)
	{
		for (int i = 0; i < m_cardsDisplay.size(); i++)
		{
			m_cardsDisplay[i]->setPosition(m_positonCardsDisplay[i]);

			if (m_cardsDisplay[i]->manageFocusing(sf::Vector2i(e.mouseButton.x, e.mouseButton.y)))
			{
				if (e.type == sf::Event::MouseButtonReleased)
				{
					if (e.mouseButton.button == sf::Mouse::Left)
					{
						return i;
					}
				}
			}
		}
	}
	else
	{
		// nothing
	}

	return -1;
}

/*
Choisi aleatoirement une categorie
puis ajoute les cartes selectionnées
*/
void Game::choiceRandCategory()
{
	int max = PURCENT_EQUIPMENT + PURCENT_MONSTER;
	int randNb = rand() % max + 1;

	int limit = PURCENT_EQUIPMENT;
	limit += PURCENT_EQUIPMENT;
	if (randNb <= limit)
	{
		m_cardsDisplay = m_selectorEquipment->select(m_numberCardsDisplay);
		return;
	}

	limit += PURCENT_MONSTER;
	if (randNb <= limit)
	{
		m_cardsDisplay = m_selectorMonster->select(m_numberCardsDisplay);
		return;
	}
}

/*
ajoute les bonus au heros
*/
void Game::gestionBonus(GameState gameState)
{
	switch (gameState)
	{
		case GameState::DRAFT:
			for (int i = 0; i < m_bonusToApplyDraft.size(); i++)
			{
				m_bonusToApplyDraft[i]->decreaseDurability();
				if (!m_bonusToApplyDraft[i]->isWorking())
				{
					m_bonusToApplyDraft.erase(m_bonusToApplyDraft.begin() + i);
				}
			}
			break;

		case GameState::FIGHT:
			for (int i = 0; i < m_bonusToApplyFight.size(); i++)
			{
				m_bonusToApplyDraft[i]->decreaseDurability();
				if (!m_bonusToApplyDraft[i]->isWorking())
				{
					m_bonusToApplyDraft.erase(m_bonusToApplyDraft.begin() + i);
				}
			}
			break;
	}
}

/*
Fait combattre le héros avec le monstre selectionné
*/
bool Game::fight(Fighter* monster)
{
	bool monsterTurn = monster->getInitiative() <= m_hero.getKarma();

	while (monster->getLife() > 0 && m_hero.getLife() > 0)
	{ 
		if (monsterTurn)
		{
			std::cout << "Monstre attaque : " << monster->getStrength() << std::endl;
			m_hero.receiveDamage(monster->getStrength());
			monsterTurn = false;
		}
		else if (m_hero.getDamage() > 0)
		{
			std::cout << "J'attaque : " << m_hero.getStrength() + m_hero.getDamage() << std::endl;
			monster->receiveDamage(m_hero.getDamage() + m_hero.getStrength());
			monsterTurn = true;
		}
		else
		{
			monsterTurn = true;
		}
	}
	if (monster->getLife() == 0)
	{
		std::vector <Bonus*> rewards = monster->getReward();

		for (int i = 0; i < rewards.size(); i++)
		{
			rewards[i]->applyBonus(&m_hero);
		}

		std::cout << "Victoire !" << std::endl;

		return true;
	}

	std::cout << "Defaite !" << std::endl;
	
	return false;

}

/*affiche l'avancement de la partie*/
bool Game::printGameState()
{
	if (m_gameState != m_oldGameState)
	{
		switch (m_gameState)
		{
			case GameState::ACTION :
				std::cout << "------ ACTION -----" << std::endl;
				break;
			case GameState::CHOICE :
				std::cout << "------ CHOICE -----" << std::endl;
				break;
			case GameState::DRAFT :
				std::cout << "------ DRAFT -----" << std::endl;
				break;
			case GameState::FIGHT :
				std::cout << "------ FIGHT -----" << std::endl;
				break;
			case GameState::PAUSE :
				std::cout << "------ PAUSE -----" << std::endl;
				break;
		}

		m_oldGameState = m_gameState;

		return true;
	}

	return false;
}