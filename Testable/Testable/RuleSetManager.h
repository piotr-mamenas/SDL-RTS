#ifndef RULESETMANAGER_H
#define RULESETMANAGER_H

#include <vector>
#include <memory>
#include <string>

#include "Unit.h"
#include "Terrain.h"

class RuleSetManager
{
private:
	std::vector<std::unique_ptr<Unit>> _unitTemplates;
	std::vector<std::unique_ptr<Terrain>> _terrainTemplates;
	void _loadDefaultConfiguration();
public:
	RuleSetManager(bool useDefaultConfiguration);
	void setUnitFile(std::unique_ptr<std::string> fileName);
	void setTerrainFile(std::unique_ptr<std::string> fileName);
    std::unique_ptr<Unit> getUnitTemplate(int unitId);
	std::unique_ptr<Terrain> getTerrainTemplate(int terrainId);
};

#endif