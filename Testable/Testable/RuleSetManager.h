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
	std::vector<std::shared_ptr<Unit>> _unitTemplates;
	std::vector<std::shared_ptr<Terrain>> _terrainTemplates;
	void _loadDefaultConfiguration();
public:
	RuleSetManager(bool useDefaultConfiguration);
	void setUnitFile(std::string fileName);
	void setTerrainFile(std::string fileName);
    std::shared_ptr<Unit> getUnitTemplate(int unitId);
	std::shared_ptr<Terrain> getTerrainTemplate(int terrainId);
};

#endif