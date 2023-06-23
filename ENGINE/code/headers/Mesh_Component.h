/**
* @file Mesh_Component.h
* @brief C�digo del componente Mesh
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
/// Declaraci�n adelantada de Model
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
		/// Modelo b�sico
		/// </summary>
		std::shared_ptr< glt::Model > model;

	public:

		// TODO: A�adir carga de meshes customizadas
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
