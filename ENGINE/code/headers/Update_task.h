/**
* @file Update_task.h
* @brief Task encargado de procesos de update
* @author Arturo Vilar Carretero
*/

// Copyright (c) 2023 Arturo / Xohat
// arturovilarc@gmail.com / xohatlatte@gmail.com
// 2023.05 - 2023.06

#pragma once

#include "Task.h"
#include "Update_Component.h"
#include <list>
#include <memory>

using namespace std;

namespace Xohat 
{
	class Update_task : public Task
	{
		/// <summary>
		/// Lista de métodos update a accionar en el run
		/// </summary>
		list< shared_ptr< Update_Component > > updates;

		/// <summary>
		/// Acciona el método update de todo lo que tenga en la lista
		/// </summary>
		/// <param name="t"></param>
		void run(float t) 
		{
			for (auto& update : updates)
			{
				update->update(0.0016f);
			}
		}

	public:

		/// <summary>
		/// Se añade un Update_Component a la lista
		/// </summary>
		/// <param name="update"></param>
		void add_update_component(shared_ptr< Update_Component > update)
		{
			updates.push_back(update);
		}
	};
}