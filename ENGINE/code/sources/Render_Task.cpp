/**
* @file Render_Task.cpp
* @brief Implementación de Render_task.h
* @author Arturo Vilar Carretero
*/

// Copyright (c) 2023 Arturo / Xohat
// arturovilarc@gmail.com / xohatlatte@gmail.com
// 2023.05 - 2023.06

#include "..\headers\Entity.h"
#include "..\headers\Scene.h"

#include "..\headers\Render_task.h"

#include "..\headers\Sample_Renderer.hpp"
#include "..\headers\Transform_Component.h"
#include "..\headers\Render_Node.hpp"
#include "..\headers\Camera.hpp"
#include "..\headers\Light.hpp"
#include "..\headers\Model.hpp"

namespace Xohat 
{
	// Inicializa toda la configuración inicial de la escena, con la cámara y la luz
	void Render_Task::initialize_render_task(Scene* scene)
	{
		renderer = std::make_shared< glt::Render_Node>();

		set_scene(scene);

		// Se crean los elementos básicos necesarios para dibujar una escena

		std::shared_ptr< glt::Camera > camera(new glt::Camera(20.f, 1.f, 50.f, 1.f));
		std::shared_ptr< glt::Light  > light(new glt::Light);

		// Se añaden los nodos a la escena:

		renderer->add("camera", camera);
		renderer->add("light", light);

		// Se configuran algunas propiedades de transformación:

		renderer->get("camera")->translate(glt::Vector3(0.f, 0.f, 8.f));
		renderer->get("light")->translate(glt::Vector3(10.f, 10.f, 10.f));
	}

	// Añade el componente al mapa de meshes
	void Render_Task::add_mesh_component_to_meshes(Entity* entity)
	{
		// Se configura la mesh básica de cubo
		entity->get_mesh()->set_cube_Model();
		entity->get_mesh()->set_owner(entity);

		// Se añade dicha mesh configurada al array de mesh_components
		meshes.push_back(entity->get_mesh());

		renderer->add(entity->get_name(), entity->get_mesh()->model);
	}

	// Ciclo de renderizado que se pasa por todas las meshes del array de mesh y las renderiza por medio de Render_Node
	void Render_Task::run(float t)
	{
		for (auto& mesh : meshes)
		{
			Transform_Component * transform = mesh->get_owner()->get_transform();
			mesh->model->set_transformation(transform->get_matrix());
		}

		// Se renderiza la escena y se intercambian los buffers de la ventana para
		// hacer visible lo que se ha renderizado:

		scene->get_window()->clear();

		renderer->render();

		scene->get_window()->swap_buffers();
	}
}