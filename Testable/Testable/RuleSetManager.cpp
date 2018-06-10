#include <string>
#include <fstream>
#include <list>
#include <algorithm>

#include <nlohmann\json.hpp>

#include "Unit.h"
#include "Terrain.h"
#include "SerializationHelper.h"
#include "RuleSetManager.h"

const std::string DEFAULT_TERRAIN_FILE = "terrain.json";
const std::string DEFAULT_UNITS_FILE = "units.json";

using json = nlohmann::json;

RuleSetManager::RuleSetManager(bool useDefaultConfiguration)
{
	if (useDefaultConfiguration)
	{
		_loadDefaultConfiguration();
	}
}

void RuleSetManager::setUnitFile(std::string fileName)
{
	std::unique_ptr<SerializationHelper<Unit>> serializationHelper = std::make_unique<SerializationHelper<Unit>>(new SerializationHelper<Unit>());
	_unitTemplates = serializationHelper->serializeToList(fileName, "units");
}

void RuleSetManager::setTerrainFile(std::string fileName)
{
	std::unique_ptr<SerializationHelper<Terrain>> serializationHelper = std::make_unique<SerializationHelper<Terrain>>(new SerializationHelper<Terrain>());
	_terrainTemplates = serializationHelper->serializeToList(fileName, "terrain");
}

void RuleSetManager::_loadDefaultConfiguration()
{
	setUnitFile(DEFAULT_UNITS_FILE);
	setTerrainFile(DEFAULT_TERRAIN_FILE);
}

std::unique_ptr<Unit> RuleSetManager::getUnitTemplate(int unitId)
{
	for (auto unit : _unitTemplates) 
	{
		if (unit->getId() == unitId)
		{
			return unit;
		}
	}
	throw std::invalid_argument("Could not find unit " + unitId);
}

std::unique_ptr<Terrain> RuleSetManager::getTerrainTemplate(int terrainId)
{
	for (auto terrain : _terrainTemplates)
	{
		if (terrain->getId() == terrainId)
		{
			return terrain;
		}
	}
	throw std::invalid_argument("Could not find terrain " + terrainId);
}