/**
* @file Task.h
* @brief Padre de todos las clases llamadas Algo_task
* @author Arturo Vilar Carretero
*/

// Copyright (c) 2023 Arturo / Xohat
// arturovilarc@gmail.com / xohatlatte@gmail.com
// 2023.05 - 2023.06

#pragma once

namespace Xohat 
{
	/// <summary>
	/// Clase encargada de hacer una acción distinta dependiendo del tipo, mas detalle en todos los archivos Algo_Task
	/// </summary>
	class Task
	{
	public:

		virtual void run(float t) = 0;
	};
}