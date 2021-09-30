#pragma once

#include <functional>
#include <map>
#include <memory>
#include "iostream"

namespace uqac::world
{
	class Object;
	class World
	{
	public:
		World() = default;
		~World() = default;

		inline uint64_t GetSize() { m_objects.size(); }

		void CreateObject();

		using OnCreateObject = std::function<void(std::shared_ptr<Object>)>;

		void RegisterOnCreateObject(OnCreateObject callback);

	private:



		size_t m_nextId = 0;
		std::map<uint64_t, std::shared_ptr<Object>> m_objects;

		std::vector<OnCreateObject> m_onCreateObjects;

	};
}

