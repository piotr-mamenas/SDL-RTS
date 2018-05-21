#ifndef SERIALIZATIONHELPER_H
#define SERIALIZATIONHELPER_H

#include <list>
#include <string>

#include "Unit.h"
#include "Terrain.h"

using namespace std;
using json = nlohmann::json;

template<typename T>
class SerializationHelper
{
private:
public:
	void serializeToList(string fileName, string objectName, list<T*> objectContainer)
	{
		ifstream objectFile(fileName);

		try
		{
			json objectJson;
			objectFile >> objectJson;

			for (auto& element : objectJson)
			{
				for (auto& object : element.at(objectName))
				{
					int objectId = object.at("id").get<int>();
					T* objectTemplate = new T(objectId, 0, 0);
					objectTemplate->deserializeFrom(object);

					objectContainer.push_back(objectTemplate);
				}
			}
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