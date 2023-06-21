#include "..\headers\Components.h"
#include "..\headers\Entity.h"

namespace Xohat 
{
	glm::mat4 Transform_Component::get_matrix() const
	{
		glm::mat4 transform_matrix;

		//aplicar escala, rotación y translación

		if (owner->get_parent() != nullptr)
			return owner->get_parent()->get_transform()->get_matrix() * transform_matrix;
		else
			return transform_matrix;
	}
}
