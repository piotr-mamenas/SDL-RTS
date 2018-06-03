#include <string>
#include <fstream>
#include <list>
#include <algorithm>

#include <nlohmann\json.hpp>

#include "Unit.h"
#include "Terrain.h"
#include "SerializationHelper.h"
#include "RuleSetManager.h"

const string DEFAULT_TERRAIN_FILE = "terrain.json";
const string DEFAULT_UNITS_FILE = "units.json";

using json = nlohmann::json;

RuleSetManager::RuleSetManager(bool useDefaultConfiguration)
{
	if (useDefaultConfiguration)
	{
		_loadDefaultConfiguration();
	}
}

void RuleSetManager::setUnitFile(string fileName)
{
	SerializationHelper<Unit>* serializationHelper = new SerializationHelper<Unit>();
	_unitTemplates = serializationHelper->serializeToList(fileName, "units");
	delete serializationHelper;
}

void RuleSetManager::setTerrainFile(string fileName)
{
	SerializationHelper<Terrain>* serializationHelper = new SerializationHelper<Terrain>();
	_terrainTemplates = serializationHelper->serializeToList(fileName, "terrain");
	delete serializationHelper;
}

void RuleSetManager::_loadDefaultConfiguration()
{
	setUnitFile(DEFAULT_UNITS_FILE);
	setTerrainFile(DEFAULT_TERRAIN_FILE);
}

Unit* RuleSetManager::getUnitTemplate(int unitId)
{
	for (auto unit : _unitTemplates) 
	{
		if (unit->getId() == unitId)
		{
			return unit;
		}
	}
	return NULL;
}

Terrain* RuleSetManager::getTerrainTemplate(int terrainId)
{
	for (auto terrain : _terrainTemplates)
	{
		if (terrain->getId() == terrainId)
		{
			return terrain;
		}
	}
	return NULL;
}