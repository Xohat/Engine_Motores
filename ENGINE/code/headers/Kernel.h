/**
* @file Kernel.h
* @brief Sistema encargado de ejecutar todoe l sistema de tareas y hacerlas en un cíclo contínuo
* @author Arturo Vilar Carretero
*/

// Copyright (c) 2023 Arturo / Xohat
// arturovilarc@gmail.com / xohatlatte@gmail.com
// 2023.05 - 2023.06

#pragma once

#include "Task.h"
#include "Timer.h"

#include <cstddef>
#include <list>

using namespace std;

namespace Xohat
{
	class Kernel
	{
		/// <summary>
		/// Lista de tasks
		/// </summary>
		list < Task* > tasks;

		bool exit;

	public:

		/// <summary>
		/// Para añadir nuevas tasks (Las del mismo tipo solo tienen una instancia en todo el motor)
		/// </summary>
		/// <param name="new_task"></param>
		void add_task(Task* new_task) 
		{
			tasks.push_back(new_task);
		}

		/// <summary>
		/// Para apagar el programa
		/// </summary>
		void stop()
		{
			exit = true;
		}

		/// <summary>
		/// Ciclo de todas las tasks en la escena
		/// </summary>
		void run()
		{
			exit = false;
			Timer timer;
			float elpased = 1.f / 60.f;

			while (!exit)
			{
				for (auto task : tasks) task->run(0.016f);

				float elapsed = timer.get_elapsed_seconds();
			}
		}
	};
}