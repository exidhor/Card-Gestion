#include "Choice.h"

Choice::Choice(Card* display, std::vector <Choice*> choices)
{
	m_display = display;
	m_choices = choices;
}