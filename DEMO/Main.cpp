#include "Window.h"
#include "Scene.h"

using namespace Xohat;

int main()
{
	std::string name("Engine Motores");
	//Chunked_Memory_Pool<4> testpool (100000);
	Window MainWindow(name, 1024, 768, false);

	Scene scene(MainWindow);
	scene.run();

	//shared_ptr< Entity > entity;

	/*
	Racket_Controller controller;
	scene->get_message_dispatcher()->register_listener (controller);

	shared_ptr< Control_Component > control_component = scene->get_system("control")->create_component (controller)
	//shared_ptr< Mesh_Component > mesh = make_shared< Mesh_Component > (ruta_de_la_mesh);
	shared_ptr< Mesh_Component > mesh = scene.get_system ("render")->create_component (ruta);

	entity->add_component (control_component);
	entity->add_component (mesh);

	Scene.add_entity(entity);

	entity.get_transform ()->set_position (?);

	//---------------------

	Audio_manager audio_manager;

	scene.add_task (audio_amanager)

	//---------------------

	scene.run();
	*/

	//while (true) {}
	return 0;
}
