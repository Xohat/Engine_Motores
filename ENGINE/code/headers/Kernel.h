#pragma once
#include "Task.h"
#include <cstddef>

//using std::

class Kernel 
{
	list < Task* > tasks;

	bool exit;

public:

	void stop() 
	{
		exit = true;
	}

	void run()
	{
		exit = false;

		float elpased = 1.f / 60.f;

		while (!exit)
		{
			Timer timer;

			for (auto task : tasks) task->run();

			elapsed = timer.get_elapsed_seconds;
		}
	}
};