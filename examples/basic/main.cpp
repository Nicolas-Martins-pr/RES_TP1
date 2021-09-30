#include <iostream>

#include <ProjectExample/object.hpp>
#include <ProjectExample/world.hpp>

int main(int argc, char* argv[])
{
	uqac::world::World w = uqac::world::World();

	w.RegisterOnCreateObject([](std::shared_ptr<uqac::world::Object> object) {
			std::cout << "Youpi" << std::endl;
		});

	w.CreateObject();

}