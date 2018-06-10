#ifndef SERIALIZATIONHELPER_H
#define SERIALIZATIONHELPER_H

#include <vector>
#include <memory>
#include <string>

#include "Unit.h"
#include "Terrain.h"

using json = nlohmann::json;

template<typename T>
class SerializationHelper
{
private:
public:
	std::vector<std::unique_ptr<T>> serializeToList(string fileName, string objectName)
	{
		ifstream objectFile(fileName);

		try
		{
			json objectJson;
			objectFile >> objectJson;
			
			json objects = objectJson.at(objectName);
			std::vector<std::unique_ptr<T>> objectContainer;

			for (auto object : objects)
			{
				T* objectTemplate = new T(object);
				objectContainer.push_back(objectTemplate);
			}
			return objectContainer;
		}
		catch (json::parse_error& e)
		{
			std::cout << "message: " << e.what() << '\n'
				<< "exception id: " << e.id << '\n'
				<< "byte position of error: " << e.byte << std::endl;
		}
	}
};

#endif