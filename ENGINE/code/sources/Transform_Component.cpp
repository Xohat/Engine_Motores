/**
* @file Transform_Component.cpp
* @brief Implementación del código de Transform_Component.h
* @author Arturo Vilar Carretero
*/

// Copyright (c) 2023 Arturo / Xohat
// arturovilarc@gmail.com / xohatlatte@gmail.com
// 2023.05 - 2023.06

#include "..\headers\Transform_Component.h"
#include "..\headers\Entity.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/matrix_decompose.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;

namespace Xohat
{
	glm::mat4 Transform_Component::get_matrix() const
	{
		// Se crea la matriz de transformación básica
		glm::mat4 transform_matrix; 

		// Se aplican las transformaciones
		transform_matrix = glm::translate(glm::mat4(1), position);
		transform_matrix = glm::scale(transform_matrix, { scale.x, scale.y, scale.z });

		// Si tiene padre usa la matriz de transformación del padre y la multiplica por la nueva, si no tiene solo se usa la matriz de transformación nueva
		if (owner->get_parent() != nullptr)
			return owner->get_parent()->get_transform()->get_matrix() * transform_matrix;
		else
			return transform_matrix;
	}
}