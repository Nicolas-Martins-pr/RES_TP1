#include "ProjectExample/world.hpp"

#include "ProjectExample/object.hpp"

namespace uqac::world
{
	void World::CreateObject()
	{
		auto obj = std::make_shared<Object>();
		m_objects.insert(std::make_pair(m_nextId++, obj));

		for (auto c : m_onCreateObjects)
		{
			c(obj);
		}

	}

	void World::RegisterOnCreateObject(OnCreateObject callback)
	{
		m_onCreateObjects.push_back(callback);
	}
}