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
		list < Task* > tasks;

		bool exit;

	public:

		void add_task(Task* new_task) 
		{
			tasks.push_back(new_task);
		}

		void stop()
		{
			exit = true;
		}

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