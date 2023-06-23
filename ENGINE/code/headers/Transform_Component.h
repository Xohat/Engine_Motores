/**
* @file Transform_Component.h
* @brief Codigo del componente Transform
* @author Arturo Vilar Carretero
*/

// Copyright (c) 2023 Arturo / Xohat
// arturovilarc@gmail.com / xohatlatte@gmail.com
// 2023.05 - 2023.06

#pragma once

#include "glm/glm.hpp"
#include "Components.h"
#include "string"

using std::string;

namespace Xohat 
{
	// Orden: Escala, rotación, translación

	class Transform_Component : public Component
	{
		// Variables
		glm::vec3 position;
		glm::vec3 scale;
		glm::vec3 euler_angles;

	public:		

		/// <summary>
		/// Constructor que inicializa todas las variables a unos valores estandar
		/// </summary>
		Transform_Component() 
		{
			position		=	{ 0, 0, 0 };
			scale			=	{ 1, 1, 1 };
			euler_angles	=	{ 0, 0, 0 };
		}

		/// <summary>
		/// Getter de la posición
		/// </summary>
		/// <returns></returns>
		glm::vec3 get_position() 
		{
			return position;
		}

		/// <summary>
		/// Setter de la posición
		/// </summary>
		/// <param name="new_position"></param>
		void set_position(glm::vec3 new_position)
		{
			position = new_position;
		}

		/// <summary>
		/// Setter de la escala
		/// </summary>
		/// <param name="new_scale"></param>
		void set_scale(glm::vec3 new_scale)
		{
			scale = new_scale;
		}

		/// <summary>
		/// Getter de la matriz de transformación
		/// </summary>
		/// <returns></returns>
		glm::mat4 get_matrix() const;

		/// <summary>
		/// Nombre del componente
		/// </summary>
		/// <returns></returns>
		static std::string name()
		{
			return "Transform_Component";
		}
	};
}