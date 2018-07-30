#include "cfg.h"

float GetPrivateProfileFloat(LPCSTR lpAppName, LPCSTR lpKeyName, FLOAT flDefault, LPCSTR lpFileName)
{
	char szData[32];

	GetPrivateProfileStringA(lpAppName, lpKeyName, std::to_string(flDefault).c_str(), szData, 32, lpFileName);

	return (float)atof(szData);
}

void WritePrivateProfileFloat(LPCSTR lpAppName, LPCSTR lpKeyName, FLOAT flValue, LPCSTR lpFileName)
{
	WritePrivateProfileStringA(lpAppName, lpKeyName, std::to_string((int)flValue).c_str(), lpFileName);
}


void SaveColor(Color color, std::string AppName, std::string keyname, std::string file)
{
	std::string r = keyname + ".r";
	std::string g = keyname + ".g";
	std::string b = keyname + ".b";

	WritePrivateProfileFloat(AppName.c_str(), r.c_str(), color.r, file.c_str());
	WritePrivateProfileFloat(AppName.c_str(), g.c_str(), color.g, file.c_str());
	WritePrivateProfileFloat(AppName.c_str(), b.c_str(), color.b, file.c_str());
}

Color ReadColor(std::string AppName, std::string keyname, std::string file)
{
	std::string r = keyname + ".r";
	std::string g = keyname + ".g";
	std::string b = keyname + ".b";

	int ir = GetPrivateProfileFloat(AppName.c_str(), r.c_str(), 0, file.c_str());
	int ig = GetPrivateProfileFloat(AppName.c_str(), g.c_str(), 0, file.c_str());
	int ib = GetPrivateProfileFloat(AppName.c_str(), b.c_str(), 0, file.c_str());

	return Color{ ir,ig,ib };

}


CFG::CFG()
{

}

CFG::~CFG()
{

}


void CFG::LoadCfg()
{
	static TCHAR path[MAX_PATH];
	std::string folder, file;

	if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, path)))
	{
		folder = std::string(path) + "\\Arghware\\";
		file = std::string(path) + "\\Arghware\\Autosave.cfg";
	}

	CreateDirectory(folder.c_str(), NULL);

	
	tRadar.cCommon = ReadColor("Radar","Color.Common", file);
	tRadar.cRare = ReadColor("Radar", "Color.Rare", file);
	tRadar.cLegendary = ReadColor("Radar", "Color.Legendary", file);
	tRadar.cMythical = ReadColor("Radar", "Color.Mythical", file);
	tRadar.cHigher = ReadColor("Radar", "Color.Higher", file);
	tRadar.bCommon = GetPrivateProfileFloat("Radar", "Show.Common", 0, file.c_str());
	tRadar.bRare = GetPrivateProfileFloat("Radar", "Show.Rare", 0, file.c_str());
	tRadar.bLegendary = GetPrivateProfileFloat("Radar", "Show.Legendary", 0, file.c_str());
	tRadar.bMythical = GetPrivateProfileFloat("Radar", "Show.Mythical", 0, file.c_str());
	tRadar.bHigher = GetPrivateProfileFloat("Radar", "Show.Higher", 0, file.c_str());
	// ESP item (AActor) on/off display toggles.
	tDisplay.btAnimals = GetPrivateProfileFloat("DisplayToggles", "Show.Animals", 0, file.c_str());
	tDisplay.btArtifacts = GetPrivateProfileFloat("DisplayToggles", "Show.Artifacts", 0, file.c_str());
	tDisplay.btChests = GetPrivateProfileFloat("DisplayToggles", "Show.Chests", 0, file.c_str());
	tDisplay.btGunpowders = GetPrivateProfileFloat("DisplayToggles", "Show.Gunpowders", 0, file.c_str());
	tDisplay.btMerchantCrates = GetPrivateProfileFloat("DisplayToggles", "Show.MerchantCrates", 0, file.c_str());
	tDisplay.btMermaids = GetPrivateProfileFloat("DisplayToggles", "Show.Mermaids", 0, file.c_str());
	tDisplay.btSharks = GetPrivateProfileFloat("DisplayToggles", "Show.Sharks", 0, file.c_str());
	tDisplay.btShips = GetPrivateProfileFloat("DisplayToggles", "Show.Ships", 0, file.c_str());
	tDisplay.btPirates = GetPrivateProfileFloat("DisplayToggles", "Show.Pirates", 0, file.c_str());
	tDisplay.btMsgBottles = GetPrivateProfileFloat("DisplayToggles", "Show.MsgBottles", 0, file.c_str());
	tDisplay.btSkullForts = GetPrivateProfileFloat("DisplayToggles", "Show.SkullFort", 0, file.c_str());
	tDisplay.btSunkenCurse = GetPrivateProfileFloat("DisplayToggles", "Show.SunkenCurse", 0, file.c_str());
	tDisplay.btSkulls = GetPrivateProfileFloat("DisplayToggles", "Show.Skulls", 0, file.c_str());
	tDisplay.btTreasureMaps = GetPrivateProfileFloat("DisplayToggles", "Show.TreasureMaps", 0, file.c_str());
	tDisplay.btSkeletons = GetPrivateProfileFloat("DisplayToggles", "Show.MerchantCrates", 0, file.c_str());
	tDisplay.btMermaids = GetPrivateProfileFloat("DisplayToggles", "Show.Skeletons", 0, file.c_str());
	//tDisplay.btChickens = GetPrivateProfileFloat("DisplayToggles", "Show.Chickens", 0, file.c_str());	//Toggle on/off Chickens. (unnecessary at the moment)
	//tDisplay.btPigs = GetPrivateProfileFloat("DisplayToggles", "Show.Pigs", 0, file.c_str());			//Toggle on/off Pigs. (unnecessary at the moment)
	//tDisplay.btSnakes = GetPrivateProfileFloat("DisplayToggles", "Show.Snakes", 0, file.c_str());		//Toggle on/off Snakes. (unnecessary at the moment)
}

void CFG::SaveCfg()
{
	static TCHAR path[MAX_PATH];
	std::string folder, file;

	if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, path)))
	{
		folder = std::string(path) + "\\Arghware\\";
		file = std::string(path) + "\\Arghware\\Autosave.cfg";
	}

	CreateDirectory(folder.c_str(), NULL);


	SaveColor(tRadar.cCommon, "Radar", "Color.Common", file);
	SaveColor(tRadar.cRare, "Radar", "Color.Rare", file);
	SaveColor(tRadar.cLegendary, "Radar", "Color.Legendary", file);
	SaveColor(tRadar.cMythical, "Radar", "Color.Mythical", file);
	SaveColor(tRadar.cHigher, "Radar", "Color.Higher", file);
	WritePrivateProfileFloat("Radar", "Show.Common", tRadar.bCommon, file.c_str());
	WritePrivateProfileFloat("Radar", "Show.Rare", tRadar.bRare, file.c_str());
	WritePrivateProfileFloat("Radar", "Show.Legendary", tRadar.bLegendary, file.c_str());
	WritePrivateProfileFloat("Radar", "Show.Mythical", tRadar.bMythical, file.c_str());
	WritePrivateProfileFloat("Radar", "Show.Higher", tRadar.bHigher, file.c_str());
	
	// ESP (AActor) on/off display toggles
	WritePrivateProfileFloat("DisplayToggles", "Show.Animals", tDisplay.btAnimals, file.c_str());
	WritePrivateProfileFloat("DisplayToggles", "Show.Artifacts", tDisplay.btArtifacts, file.c_str());
	WritePrivateProfileFloat("DisplayToggles", "Show.Chests", tDisplay.btChests, file.c_str());
	WritePrivateProfileFloat("DisplayToggles", "Show.Gunpowders", tDisplay.btGunpowders, file.c_str());
	WritePrivateProfileFloat("DisplayToggles", "Show.MerchantCrates", tDisplay.btMerchantCrates, file.c_str());
	WritePrivateProfileFloat("DisplayToggles", "Show.Mermaids", tDisplay.btMermaids, file.c_str());
	WritePrivateProfileFloat("DisplayToggles", "Show.Sharks", tDisplay.btSharks, file.c_str());
	WritePrivateProfileFloat("DisplayToggles", "Show.Ships", tDisplay.btShips, file.c_str());
	WritePrivateProfileFloat("DisplayToggles", "Show.Pirates", tDisplay.btPirates, file.c_str());
	WritePrivateProfileFloat("DisplayToggles", "Show.MsgBottles", tDisplay.btMsgBottles, file.c_str());
	WritePrivateProfileFloat("DisplayToggles", "Show.SkullForts", tDisplay.btSkullForts, file.c_str());
	WritePrivateProfileFloat("DisplayToggles", "Show.SunkenCurse", tDisplay.btSunkenCurse, file.c_str());
	WritePrivateProfileFloat("DisplayToggles", "Show.Skulls", tDisplay.btSkulls, file.c_str());
	WritePrivateProfileFloat("DisplayToggles", "Show.TreasureMaps", tDisplay.btTreasureMaps, file.c_str());
	WritePrivateProfileFloat("DisplayToggles", "Show.Skeletons", tDisplay.btSkeletons, file.c_str());
	//WritePrivateProfileFloat("DisplayToggles", "Show.Chickens", tDisplay.btChickens, file.c_str());	//Toggle on/off display of Chickens (unnecessary at the moment)
	//WritePrivateProfileFloat("DisplayToggles", "Show.Pigs", tDisplay.btPigs, file.c_str());			//Toggle on/off display of Pigs (unnecessary at the moment)
	//WritePrivateProfileFloat("DisplayToggles", "Show.Snakes", tDisplay.btSnakes, file.c_str());		//Toggle on/off display of Snakes (unnecessary at the moment)
}