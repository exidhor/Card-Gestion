#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

/**Elements possedant une interaction
avec l'utilisateur
*/
class Entity
{
protected:
	bool m_isSelected;
public:
	Entity();
};