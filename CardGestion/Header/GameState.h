#pragma once

/* D�finit les �tats du jeu
PAUSE, DRAFT, FIGHT, CHOICE, ACTION
*/
typedef enum {
	PAUSE,
	DRAFT,
	FIGHT,
	CHOICE,
	ACTION
} GameState;