/**
* @file Mesh_Component.h
* @brief Código del componente Mesh
* @author Arturo Vilar Carretero
*/

// Copyright (c) 2023 Arturo / Xohat
// arturovilarc@gmail.com / xohatlatte@gmail.com
// 2023.05 - 2023.06

#pragma once

#include "Components.h"
#include <memory>
#include <string>

/// <summary>
/// Declaración adelantada de Model
/// </summary>
namespace glt 
{
	class Model;
}

namespace Xohat 
{
	class Mesh_Component : public Component
	{
	public:

		/// <summary>
		/// Modelo básico
		/// </summary>
		std::shared_ptr< glt::Model > model;

	public:

		// TODO: Añadir carga de meshes customizadas
		// void setModel(std::shared_ptr<glt::Model> model) { this->model = model; }

		/// <summary>
		/// Carga una mesh de glt::cube
		/// </summary>
		void set_cube_Model();

		/// <summary>
		/// Nombre del componente
		/// </summary>
		/// <returns></returns>
		static std::string name()
		{
			return "Mesh_Component";
		}
	};
}
