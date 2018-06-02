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
			
			json objects = objectJson.at(objectName);
			for (auto object : objects)
			{
				T* objectTemplate = new T(object);
				objectContainer.push_back(objectTemplate);
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