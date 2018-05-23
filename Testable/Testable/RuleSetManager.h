#ifndef RULESETMANAGER_H
#define RULESETMANAGER_H

#include <list>
#include <string>

#include "Unit.h"
#include "Terrain.h"

using namespace std;

class RuleSetManager
{
private:
	list<Unit*> _unitTemplates;
	list<Terrain*> _terrainTemplates;
	void _loadDefaultConfiguration();
public:
	RuleSetManager(bool useDefaultConfiguration);
	void setUnitFile(string fileName);
	void setTerrainFile(string fileName);
};

#endif