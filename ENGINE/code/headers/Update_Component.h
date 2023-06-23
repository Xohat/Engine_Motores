/**
* @file Transform_Component.h
* @brief Codigo del componente Transform
* @author Arturo Vilar Carretero
*/

// Copyright (c) 2023 Arturo / Xohat
// arturovilarc@gmail.com / xohatlatte@gmail.com
// 2023.05 - 2023.06

#pragma once

#include "Components.h"

namespace Xohat 
{
	class Update_Component : public Component 
	{

	public:

		virtual void update(float t) = 0;

		/// <summary>
		/// Nombre del componente
		/// </summary>
		/// <returns></returns>
		static std::string name()
		{
			return "Update_Component";
		}
	};
}
