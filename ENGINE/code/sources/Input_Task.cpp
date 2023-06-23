/**
* @file Input_Task.cpp
* @brief Implementación del código de Input_task.h
* @author Arturo Vilar Carretero
*/

// Copyright (c) 2023 Arturo / Xohat
// arturovilarc@gmail.com / xohatlatte@gmail.com
// 2023.05 - 2023.06

#include "..\headers\Input_task.h"
#include "..\headers\Window.h"
#include "..\headers\Scene.h"

#include "SDL.h"

namespace Xohat 
{
	void Input_Task::run(float t)
	{
		Window* window = scene->get_window();

		Window::Event windowEvents;

		float y_increase = 0.1f;

		while (window->poll(windowEvents))
		{
			switch (windowEvents.type)
			{
				// Cierre de ventana
				case windowEvents.CLOSE:
				{
					exit(0);
					break;
				}

				// Presionar una tecla
				case windowEvents.Type::KEY_PRESSED:
				{
					switch (windowEvents.data.keyboard.key_code)
					{
						// Pone full screen
						case Keyboard::Key_Code::KEY_F:
						{
							scene->get_window()->set_FullScreen();
							break;
						}

						// Pone windowed
						case Keyboard::Key_Code::KEY_G:
						{
							scene->get_window()->set_Windowed();
							break;
						}
						

						// Manda el mensaje para subir el objeto player_1
						case Keyboard::Key_Code::KEY_W:
						{
							Message message("subir_p1");
							scene->get_dispatcher()->send(message);

							break;
						}

						// Manda el mensaje para bajar el objeto player_1
						case Keyboard::Key_Code::KEY_S:
						{
							Message message("bajar_p1");
							scene->get_dispatcher()->send(message);

							break;
						}

						// Manda el mensaje para subir el objeto player_2
						case Keyboard::Key_Code::KEY_Q:
						{
							Message message("subir_p2");
							scene->get_dispatcher()->send(message);

							break;
						}

						// Manda el mensaje para bajar el objeto player_2
						case Keyboard::Key_Code::KEY_A:
						{
							Message message("bajar_p2");
							scene->get_dispatcher()->send(message);

							break;
						}
					}

					break;
				}
			}
		}
	}
}