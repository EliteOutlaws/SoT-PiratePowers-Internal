#pragma once
#include "Functions.h"
#include <ShlObj.h>

// Booleans to toggle on/off the display of different things.
bool btAnimals, btChests, btSkulls, btArtifacts, btGunpowders, btMerchantCrates, btTreasureMaps; // Commonly changed display items.
bool btShips, btPirates, btSkeletons, btSkullForts, btSunkenCurse, btMermaids, btSharks, btMsgBottles; // Uncommonly changed display items.

struct Types {
	Color cCommon;
	Color cRare;
	Color cLegendary;
	Color cMythical;
	Color cHigher;

	bool bCommon, bRare, bLegendary, bMythical, bHigher;
};
struct Animals {
	bool chicken, snake, pig;
};
struct AnimalCrates {
	bool chicken, snake, pig;
};
struct Items {
	Color cAnimalCrates, cMerchant, cResources, cGunpowder, cPlayers, cShips, cSkeletons; //, cSkullFort, cTreasures, cSunkenCurse;
	bool bChests, bSkulls, bMerchant, bArtifacts, bResources, bGunpowder, bAnimals, bAnimalCrates, bPlayers, bShips, bSkeletons, bSkullForts, bTreasureMaps, bSunkenCurse;
	Animals Animals;
	AnimalCrates AnimalCrates;
};
struct btESP {
	// Booleans to toggle on/off the display of different things.
	bool btAnimals, btChests, btSkulls, btArtifacts, btGunpowders, btMerchantCrates, btTreasureMaps; // Commonly changed display items.
	bool btShips, btPirates, btSkeletons, btSkullForts, btSunkenCurse, btMermaids, btSharks, btMsgBottles; // Uncommonly changed display items.
};

class CFG
{
public:
	CFG();
	~CFG();

	void LoadCfg();
	void SaveCfg();
public:

	Types tRadar;
	Types tESP;
	btESP tDisplay;


};

static CFG cfg;

//std::shared_ptr<CFG> cfg = nullptr;
