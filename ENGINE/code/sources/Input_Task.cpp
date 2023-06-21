#include "..\headers\Input_task.h"
#include "..\headers\Window.h"
#include "..\headers\Scene.h"

namespace Xohat 
{
	void Input_Task::run(float t)
	{
		Window* window = scene->get_window();

		Window::Event windowEvents;

		while (window->poll(windowEvents))
		{
			switch (windowEvents.type)
			{
				case windowEvents.Type::KEY_PRESSED:
				{
					/*
					switch (windowEvents.key.code)
					{
						case ARROW_UP:
						{
							Message message("subir");
							scene->get_message_dispatcher()->send(message);
							break;
						}
					}
					*/

					break;
				}
			}
		}
	}
}