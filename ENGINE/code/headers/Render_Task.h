/**
* @file Render_Task.h
* @brief Código relacionado con la tarea de renderizado de objetos, usando opengltoolkit
* @author Arturo Vilar Carretero
*/

// Copyright (c) 2023 Arturo / Xohat
// arturovilarc@gmail.com / xohatlatte@gmail.com
// 2023.05 - 2023.06

#pragma once

#include "Task.h"
#include "Mesh_Component.h"

#include <memory>
#include <list>

using namespace std;

/// <summary>
/// Declaración adlenatada de Render_Node
/// </summary>
namespace glt 
{
	class Render_Node;
}

namespace Xohat 
{
	//Declraciones adelantadas par evitar el include
	class Scene;
	class Entity;

	class Render_Task : public Task
	{
		/// <summary>
		/// Lista de meshes añadidads
		/// </summary>
		list< shared_ptr< Mesh_Component > > meshes;

		/// <summary>
		/// Renderer de glt
		/// </summary>
		std::shared_ptr<glt::Render_Node> renderer;

		/// <summary>
		/// Referencia a la escena
		/// </summary>
		Scene* scene;

	public:

		/// <summary>
		/// Configuración inicial de la escena
		/// </summary>
		/// <param name="scene"></param>
		void initialize_render_task(Scene* scene);

		/// <summary>
		/// Setter de la escena
		/// </summary>
		/// <param name="new_scene"></param>
		void set_scene(Scene* new_scene)
		{
			scene = new_scene;
		}

		/// <summary>
		/// Añade una entity con un mesh component (Como tienen todas) a 
		/// la lista de meshes tras inicializarla como un cubo
		/// </summary>
		/// <param name="entity"></param>
		void add_mesh_component_to_meshes(Entity* entity);

		/// <summary>
		/// Ciclo de renderizado por medio del renderer de glt
		/// </summary>
		/// <param name="t"></param>
		void run(float t) override;
	};
}

