#ifndef CONFIGURATIONMANAGER_H
#define CONFIGURATIONMANAGER_H

#include <list>
#include <string>

#include "Unit.h"
#include "Terrain.h"

using namespace std;

class ConfigurationManager
{
private:
	list<Unit*> _unitTemplates;
	list<Terrain*> _terrainTemplates;
	void _loadDefaultConfiguration();
public:
	ConfigurationManager(bool useDefaultConfiguration);
	void setUnitFile(string fileName);
	void setTerrainFile(string fileName);
};

#endif