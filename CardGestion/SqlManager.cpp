#include "SqlManager.h"

SqlManager::SqlManager(SqlCreator* sqlCreator)
{
	m_sqlCreator = sqlCreator;
	if (m_sqlCreator == NULL)
	{
		std::cout << "sqlCreator NULL !" << std::endl;
	}
}

void SqlManager::createTable()
{
	m_sqlCreator->query(createEquipmentsTable());
	m_sqlCreator->query(createClassicMeetsTable());
	m_sqlCreator->query(createInteractionMeetsTable());
	m_sqlCreator->query(createMonstersTable());
	m_sqlCreator->query(createInteractionsTable());
}

//------------------------- TABLES PRINCIPALES -------------------------

char* SqlManager::createEquipmentsTable()
{
	return "DROP TABLE IF EXISTS Equipments;"
		"CREATE TABLE Equipments(Id INTEGER PRIMARY KEY, Name TEXT(50), Durability INT, Price INT, ForcedUtilisation BOOLEAN);"
		"INSERT INTO Equipments(Name, Durability, Price, ForcedUtilisation) VALUES('Tongue',			-1,		30,		'false');"
		"INSERT INTO Equipments(Name, Durability, Price, ForcedUtilisation) VALUES('Carte de la ville',	2,		50,		'false');"
		"INSERT INTO Equipments(Name, Durability, Price, ForcedUtilisation) VALUES('Chaine en or',		-1,		150,	'false');"
		"INSERT INTO Equipments(Name, Durability, Price, ForcedUtilisation) VALUES('Porte monnaie',		1,		0,		'true');"
		"INSERT INTO Equipments(Name, Durability, Price, ForcedUtilisation) VALUES('Petite cuillere',	-1,		5,		'false');"
		"INSERT INTO Equipments(Name, Durability, Price, ForcedUtilisation) VALUES('Steak 70% viande',	1,		10,		'false');"
		"INSERT INTO Equipments(Name, Durability, Price, ForcedUtilisation) VALUES('Cafe soluble',		1,		10,		'false');"
		"INSERT INTO Equipments(Name, Durability, Price, ForcedUtilisation) VALUES('Poele',				-1,		50,		'false');"
		"INSERT INTO Equipments(Name, Durability, Price, ForcedUtilisation) VALUES('Croissant',			2,		30,		'false');"
		"INSERT INTO Equipments(Name, Durability, Price, ForcedUtilisation) VALUES('Cagoule',			1,		60,		'false');"
		"INSERT INTO Equipments(Name, Durability, Price, ForcedUtilisation) VALUES('Yum Yum',			1,		2,		'false');"
		"INSERT INTO Equipments(Name, Durability, Price, ForcedUtilisation) VALUES('Drogue',			1,		0,		'true');"
		"INSERT INTO Equipments(Name, Durability, Price, ForcedUtilisation) VALUES('Hot-dog',			1,		15,		'false');"
		"INSERT INTO Equipments(Name, Durability, Price, ForcedUtilisation) VALUES('Matraque',			-1,		70,		'false');"
		"INSERT INTO Equipments(Name, Durability, Price, ForcedUtilisation) VALUES('Tarte',				1,		45,		'false');"
		"INSERT INTO Equipments(Name, Durability, Price, ForcedUtilisation) VALUES('Pain',				2,		20,		'false');"
		"INSERT INTO Equipments(Name, Durability, Price, ForcedUtilisation) VALUES('Journal',			-1,		5,		'true');"
		"INSERT INTO Equipments(Name, Durability, Price, ForcedUtilisation) VALUES('Flan',				1,		35,		'false');"
		"INSERT INTO Equipments(Name, Durability, Price, ForcedUtilisation) VALUES('Bonbon',			1,		5,		'false');"
		"INSERT INTO Equipments(Name, Durability, Price, ForcedUtilisation) VALUES('Canne',				-1,		25,		'false');"
		"INSERT INTO Equipments(Name, Durability, Price, ForcedUtilisation) VALUES('Mure',				1,		3,		'false');"
		"INSERT INTO Equipments(Name, Durability, Price, ForcedUtilisation) VALUES('Plume',				-1,		3,		'false');";
}

char* SqlManager::createClassicMeetsTable()
{
	return "DROP TABLE IF EXISTS ClassicMeets;"
		"CREATE TABLE ClassicMeets(Id INTEGER PRIMARY KEY, Name TEXT(50));"
		"INSERT INTO ClassicMeets(Name) VALUES('Un vieillard');"
		"INSERT INTO ClassicMeets(Name) VALUES('Un mec louche');"
		"INSERT INTO ClassicMeets(Name) VALUES('Une voyante');"
		"INSERT INTO ClassicMeets(Name) VALUES('Un prof de chant');"
		"INSERT INTO ClassicMeets(Name) VALUES('Le dealer');"
		"INSERT INTO ClassicMeets(Name) VALUES('La boulangere');"
		"INSERT INTO ClassicMeets(Name) VALUES('Le maire');";
}

char* SqlManager::createInteractionMeetsTable()
{
	return "DROP TABLE IF EXISTS InteractionMeets;"
		"CREATE TABLE InteractionMeets(Id INTEGER PRIMARY KEY, Name TEXT(50));"
		"INSERT INTO InteractionMeets(Name) VALUES('Homme Sandwich');"
		"INSERT INTO InteractionMeets(Name) VALUES('Moine Tibetain');"
		"INSERT INTO InteractionMeets(Name) VALUES('un arbre');"
		"INSERT INTO InteractionMeets(Name) VALUES('un cactus');"
		"INSERT INTO InteractionMeets(Name) VALUES('Pigeon');"
		"INSERT INTO InteractionMeets(Name) VALUES('une fille');";

}

char* SqlManager::createMonstersTable()
{
	return "DROP TABLE IF EXISTS Monsters;"
		"CREATE TABLE Monsters(Id INTEGER PRIMARY KEY, Name TEXT(50), Life INT, Strength INT);"
		"INSERT INTO Monsters(Name, Life, Strength) VALUES('un chewing gum',		-1, 2);"
		"INSERT INTO Monsters(Name, Life, Strength) VALUES('Les flics',				6,	8);"
		"INSERT INTO Monsters(Name, Life, Strength) VALUES('un petit caillou',		-1, 1);"
		"INSERT INTO Monsters(Name, Life, Strength) VALUES('Homme Sandwich',		2, 1);"
		"INSERT INTO Monsters(Name, Life, Strength) VALUES('Ta mere',				-1, 2);"
		"INSERT INTO Monsters(Name, Life, Strength) VALUES('un clebard',			3, 3);"
		"INSERT INTO Monsters(Name, Life, Strength) VALUES('Voyou',					3, 3);"
		"INSERT INTO Monsters(Name, Life, Strength) VALUES('Clochard',				2, 3);"
		"INSERT INTO Monsters(Name, Life, Strength) VALUES('Ronce',					-1, 3);"
		"INSERT INTO Monsters(Name, Life, Strength) VALUES('Voiture folle',			-1, 0);"
		"INSERT INTO Monsters(Name, Life, Strength) VALUES('Un passant pressé',		-1, 1);"
		"INSERT INTO Monsters(Name, Life, Strength) VALUES('Moto rapide',			-1, 0);"
		"INSERT INTO Monsters(Name, Life, Strength) VALUES('Une Seringue',			-1, 3);"
		"INSERT INTO Monsters(Name, Life, Strength) VALUES('La fille du quartier',	-1, 0);"
		"INSERT INTO Monsters(Name, Life, Strength) VALUES('Un chef d entreprise',	3, 1);";
}

char* SqlManager::createInteractionsTable()
{
	return "DROP TABLE IF EXISTS Interactions;"
		"CREATE TABLE Interactions(Id INTEGER PRIMARY KEY, Name TEXT(50));"
		"INSERT INTO Interactions(Name) VALUES('Taper');"
		"INSERT INTO Interactions(Name) VALUES('Faire un calin');"
		"INSERT INTO Interactions(Name) VALUES('Pisser dessus');"
		"INSERT INTO Interactions(Name) VALUES('Parler');"
		"INSERT INTO Interactions(Name) VALUES('Faire peur');"
		"INSERT INTO Interactions(Name) VALUES('Se moquer');"
		"INSERT INTO Interactions(Name) VALUES('Essayer de manger');"
		"INSERT INTO Interactions(Name) VALUES('Caresser');";
}

//------------------------- TABLES DE JOINTURES -------------------------

/*
// TO DO
char* SqlManager::createEquipmentsLinkToEffectsTable()
{
	return;
}

// TO DO
char* SqlManager::createMeetingChoicesLinkToEffectsTable()
{
	return;
}

// TO DO
char* SqlManager::createMeetingChoicesLinkToClassicMeetsTable()
{
	return;
}

// TO DO
char* SqlManager::createMonstersLinkToEffects()
{
	return;
}

// TO DO
char* createInteractionsMeetsLinkToInteractionsLinkToEffectsTable()
{
	return;
}
*/

//------------------------- TABLES DES BONUS -----------------------------

// TO DO
char* SqlManager::createEffectsTable()
{
	return "DROP TABLE IF EXISTS Effects;"
		"CREATE TABLE Effects(Id INTEGER PRIMARY KEY, IdBonusClass INT, IdBonusEquip INT, IdBonusRule INT"
		"CONSTRAINT fkIdForeign FOREIGN KEY (idAuteur) REFERENCES AUTEUR(idAuteur));"
		"INSERT INTO Effects(name) VALUES('test');";
}


//TO DO
char* SqlManager::createClassicBonusTable()
{
	return"";
}

/*
// TO DO
char* SqlManager::createEquipmentBonusTable()
{
	return;
}

//TO DO
char* SqlManager::createModifyingRulesTable()
{
	return;
}
*/

void SqlManager::select()
{
	char* sql_request = "SELECT * FROM interactions;";

	m_sqlCreator->query(sql_request, callbackManager);
}

int callbackManager(void *NotUsed, int argc, char **argv,
	char **azColName)
{
	NotUsed = 0;

	for (int i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}

	printf("\n");

	return 0;
}