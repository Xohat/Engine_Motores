/**
* @file Component.h
* @brief Padre de los hijos llamados Algo_Component
* @author Arturo Vilar Carretero
*/

// Copyright (c) 2023 Arturo / Xohat
// arturovilarc@gmail.com / xohatlatte@gmail.com
// 2023.05 - 2023.06

#pragma once

namespace Xohat 
{
	// Declaración adelantada de Entity
	class Entity;

	class Component
	{

	protected:

		// Todos los componentes requiren tener a un owner
		Entity* owner;

	public:

		/// <summary>
		/// Getter de owner
		/// </summary>
		/// <returns></returns>
		Entity* get_owner()
		{
			return owner;
		}

		/// <summary>
		/// Setter de owner
		/// </summary>
		/// <param name="new_owner"></param>
		void set_owner(Entity* new_owner)
		{
			owner = new_owner;
		}
	};
}