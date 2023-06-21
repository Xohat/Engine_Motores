#pragma once

#include "Task.h"

namespace Xohat 
{
	class Scene;

	class Input_Task : public Task
	{
		Scene* scene;

	public:

		void run(float t) override;
	};
}

