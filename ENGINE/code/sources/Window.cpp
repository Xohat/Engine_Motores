/**
* @file Window.cpp
* @brief Implementación del código de Window.h
* @author Arturo Vilar Carretero
*/

// Copyright (c) 2023 Arturo / Xohat
// arturovilarc@gmail.com / xohatlatte@gmail.com
// 2023.05 - 2023.06

#include "../headers/Window.h"
#include <SDL.h>
#include <iostream>
#include <OpenGL.hpp>
#include "..\headers\internal\initialize.hpp"

using namespace engine;

namespace Xohat
{
	Window::Window(const std::string title, unsigned given_width, unsigned given_height, bool fullScreen)
	{
		width = given_width;
		height = given_height;

		if (initialize(SDL_INIT_VIDEO))
		{
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

			window = SDL_CreateWindow
			(
				title.c_str(),
				SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED,
				width,
				height,
				SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
			);

			if (window)
			{
				gl_context = SDL_GL_CreateContext(window);

				if (gl_context && glt::initialize_opengl_extensions())
				{
					if (fullScreen)
					{
						SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
					}
				}
			}
		}
	}

	Window::~Window()
	{
		// Liberar la ventana cuando se destruye el objeto
		if (gl_context) SDL_GL_DeleteContext(gl_context);
		if (window) SDL_DestroyWindow(window);
	}

	void Window::update_window_dimensions()
	{
		if (window) SDL_GetWindowSize(window, &width, &height);
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

	void Window::set_FullScreen()
	{
		// Cambiar a pantalla completa
		SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
	}

	void Window::set_Windowed()
	{
		// Cambiar a modo de ventana
		SDL_SetWindowFullscreen(window, 0);
	}

	void Window::swap_buffers()
	{
		// Intercambiar los buffers de la ventana
		SDL_GL_SwapWindow(window);
	}

	unsigned int Window::get_width() 
	{
		return unsigned(width);
	}

	unsigned int Window::get_height()
	{
		return unsigned(height);
	}

	void Window::enable_vsync()
	{
		if (gl_context) SDL_GL_SetSwapInterval(1);
	}

	void Window::disable_vsync()
	{
		if (gl_context) SDL_GL_SetSwapInterval(0);
	}

	void Window::clear() const
	{
		if (gl_context) glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
						event.data.keyboard.key_code = Keyboard::translate_sdl_key_code(sdl_event.key.keysym.sym);
						break;
					}

					case SDL_KEYUP:
					{
						event.type = Event::KEY_RELEASED;
						event.data.keyboard.key_code = Keyboard::translate_sdl_key_code(sdl_event.key.keysym.sym);
						break;
					}
				}

				return true;
			}
		}

		return false;
	}
}