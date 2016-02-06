#pragma once
#include "SqlCreator.h"
#include <iostream>

int callbackManager(void *NotUsed, int argc, char **argv,
	char **azColName);

class SqlManager
{
private:
	SqlCreator* m_sqlCreator;
public:
	SqlManager(SqlCreator* sqlCreator);
	void createTable();

	//tables principales
	char* createEquipmentsTable();
	char* createClassicMeetsTable();
	char* createInteractionMeetsTable();
	char* createMonstersTable();
	char* createInteractionsTable();
	char createMeetingChoicesTable();

	//Tables de jointure
	char* createEquipmentsLinkToEffectsTable();
	char* createMeetingChoicesLinkToEffectsTable();
	char* createMeetingChoicesLinkToClassicMeetsTable();
	char* createMonstersLinkToEffects();
	char* createInteractionsMeetsLinkToInteractionsLinkToEffectsTable();

	//Bonus
	char* createEffectsTable(); //Lie les tables de jointures et les effets
	char* createClassicBonusTable();
	char* createEquipmentBonusTable();
	char* createModifyingRulesTable();

	void select();
};