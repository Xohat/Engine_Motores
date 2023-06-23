/**
* @file Entity.h
* @brief Código del sistema de entidades
* @author Arturo Vilar Carretero
*/

// Copyright (c) 2023 Arturo / Xohat
// arturovilarc@gmail.com / xohatlatte@gmail.com
// 2023.05 - 2023.06

#pragma once

#include "Message.h"
#include "Mesh_Component.h"
#include "Transform_Component.h"
#include "Update_Component.h"

#include "glm/glm.hpp"

#include <map>
#include <string>
#include <memory>

using namespace std;
using namespace glm;

/// <summary>
/// Declaración adelantada
/// </summary>
namespace glt 
{
	class Model;
}

namespace Xohat 
{
	// Declración adelantada
	class Scene;

	class Entity
	{
		/// <summary>
		/// Referencia a la escena donde van a existir las entidades
		/// </summary>
		Scene* scene = 0;

		/// <summary>
		/// Dichas entidades pueden tener un padre
		/// </summary>
		Entity* parent = nullptr;

		/// <summary>
		/// Nombre de la entidad
		/// </summary>
		std::string name;

		/// <summary>
		/// Variable Transform_Component ya que todos los objetos entity en este caso deberian ser capaces de moverse
		/// </summary>
		Transform_Component* transform;

		/// <summary>
		/// Variable Mesh_Component ya que todos los objetos entity tienen una mesh al ser objetos físicos
		/// </summary>
		shared_ptr < Mesh_Component > mesh;

	public:

		/// <summary>
		/// Definición inicial del componente de update, 
		/// pero no se inicializa a menos que se use el método de add_update_component de Update_task
		/// </summary>
		shared_ptr < Update_Component > update_comp;

		/// <summary>
		/// El constructor inicializa una entidad haciendo new a los transform y mesh, 
		/// además de configurando la pertenencia de los componentes por el set_owner, esta requiere una escena para poder funcionar
		/// </summary>
		/// <param name="given_scene"></param>
		Entity(Scene* given_scene)
		{
			name = "";

			scene = given_scene;

			transform = new Transform_Component();			// Crea un nuevo objeto Transform_Component
			transform->set_owner(this);

			mesh = std::make_shared< Mesh_Component >();	// Crea un nuevo objeto Mesh_Component
			mesh->set_owner(this);
		}

		/// <summary>
		/// Destructor
		/// </summary>
		~Entity()
		{
			//delete transform; // Libera la memoria del objeto Transform_Component al destruir el objeto Entity		
		}

		/// <summary>
		/// Getter de padre (Si lo hay)
		/// </summary>
		/// <returns></returns>
		Entity* get_parent () const
		{
			return parent;		
		}

		/// <summary>
		/// Getter de Transform_Component
		/// </summary>
		/// <returns></returns>
		Transform_Component* get_transform () const
		{
			return transform;
		}

		/// <summary>
		/// Getter de Mesh_Component
		/// </summary>
		/// <returns></returns>
		std::shared_ptr<Mesh_Component> get_mesh () const
		{
			return mesh;
		}

		/// <summary>
		/// Setter de nombre
		/// </summary>
		/// <param name="new_name"></param>
		void set_name (std::string new_name)
		{
			name = new_name;
		}

		/// <summary>
		/// Getter de nombre
		/// </summary>
		/// <returns></returns>
		std::string get_name () 
		{
			return name;
		}
	};
}