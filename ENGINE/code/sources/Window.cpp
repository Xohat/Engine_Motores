#include "../headers/Window.h"
#include <SDL.h>
#include <iostream>

namespace Xohat
{
	Window::Window(const std::string title, unsigned width, unsigned height, bool fullScreen)
	{
		int window_flag = SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL;

		if (fullScreen)
			window_flag |= SDL_WINDOW_FULLSCREEN;

		// Guardar la ventana creada en un miembro de la clase
		window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, (int)width, (int)height, window_flag);
	}

	Window::~Window()
	{
		// Liberar la ventana cuando se destruye el objeto
		SDL_DestroyWindow(window);
	}

	void Window::show()
	{
		// Mostrar la ventana
		SDL_ShowWindow(window);
	}

	void Window::hide()
	{
		// Ocultar la ventana
		SDL_HideWindow(window);
	}

	void Window::setFullScreen()
	{
		// Cambiar a pantalla completa
		SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
	}

	void Window::setWindowed()
	{
		// Cambiar a modo de ventana
		SDL_SetWindowFullscreen(window, 0);
	}

	void Window::swapBuffers()
	{
		// Intercambiar los buffers de la ventana
		SDL_GL_SwapWindow(window);
	}

	bool Window::poll(Event& event)
	{
		if (window)     // Aunque sería raro, puede llegar a ocurrir que no se haya conseguido crear la ventana...
		{
			// Se extrae un evento usando SDL y se convierte a un evento propio de
			// nuestro engine:

			SDL_Event sdl_event;

			if (SDL_PollEvent(&sdl_event) > 0)
			{
				switch (sdl_event.type)
				{
					case SDL_QUIT:
					{
						event.type = Event::CLOSE;
						break;
					}

					case SDL_KEYDOWN:
					{
						event.type = Event::KEY_PRESSED;
						//event.data.keyboard.key_code = Keyboard::translate_sdl_key_code(sdl_event.key.keysym.sym);
						break;
					}

					case SDL_KEYUP:
					{
						event.type = Event::KEY_RELEASED;
						//event.data.keyboard.key_code = Keyboard::translate_sdl_key_code(sdl_event.key.keysym.sym);
						break;
					}
				}

				return true;
			}
		}

		return false;
	}
}