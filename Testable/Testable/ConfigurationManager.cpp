#include <string>
#include <fstream>
#include <list>

#include <nlohmann\json.hpp>

#include "Unit.h"
#include "Terrain.h"
#include "SerializationHelper.h"
#include "ConfigurationManager.h"

const string DEFAULT_TERRAIN_FILE = "terrain.json";
const string DEFAULT_UNITS_FILE = "units.json";

using json = nlohmann::json;

ConfigurationManager::ConfigurationManager(bool useDefaultConfiguration)
{
	if (useDefaultConfiguration)
	{
		_loadDefaultConfiguration();
	}
}

void ConfigurationManager::setUnitFile(string fileName)
{
	SerializationHelper<Unit>* serializationHelper = new SerializationHelper<Unit>();
	serializationHelper->serializeToList(fileName, "units", _unitTemplates);
	delete serializationHelper;
}

void ConfigurationManager::setTerrainFile(string fileName)
{
	SerializationHelper<Terrain>* serializationHelper = new SerializationHelper<Terrain>();
	serializationHelper->serializeToList(fileName, "terrain", _terrainTemplates);
	delete serializationHelper;
}

void ConfigurationManager::_loadDefaultConfiguration()
{
	setUnitFile(DEFAULT_UNITS_FILE);
	setTerrainFile(DEFAULT_TERRAIN_FILE);
}