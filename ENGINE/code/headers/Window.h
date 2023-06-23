/**
* @file Window.h
* @brief Código relacionado con la Ventana, esto sera luego usado para la clase más importante de la Scene
* @author Arturo Vilar Carretero
*/

// Copyright (c) 2023 Arturo / Xohat
// arturovilarc@gmail.com / xohatlatte@gmail.com
// 2023.05 - 2023.06

#pragma once

#include <string>
#include "internal/declarations.hpp" //< Usado para las declaraciones adelantadas de SDL para que el proyecto de Sandbox no requiera las inclusiones
#include "Keyboard.hpp"

namespace Xohat
{
	class Window
	{

    public:
        
        /** Esta clase Event es específica para los eventos de la ventana.
          * Por ello está anidada dentro de Window. Se podría generalizar.
          */

        struct Event
        {
            enum Type
            {
                CLOSE,
                KEY_PRESSED,
                KEY_RELEASED
            }
            type;

            union Data
            {
                struct { int key_code; } keyboard;
            }
            data;
        };

	private:

		SDL_Window  * window;		// Declaración del miembro window
		SDL_GLContext gl_context;	// OpenGlToolkit context

        // Propiedaddes de la ventana
        int width;
        int height;

	public:

		/// <summary>
		/// Constructor de Ventana
		/// </summary>
		/// <param name="title"></param>
		/// <param name="width"></param>
		/// <param name="height"></param>
		/// <param name="fullScreen"></param>
		Window(const std::string title, unsigned width, unsigned height, bool fullScreen);

		/// <summary>
		/// Destructor de ventana
		/// </summary>
		~Window();

        void update_window_dimensions();

		/// <summary>
		/// Muestra la ventana
		/// </summary>
		void show();

		/// <summary>
		/// Esconde la ventana
		/// </summary>
		void hide();

		/// <summary>
		/// Pone la escena en pantalla completa (Cuidado, fuerza la resolución puesta en la window a la pantalla)
		/// </summary>
		void set_FullScreen();

		/// <summary>
		/// Pone la escena en modo ventana (Con las propiedades de la ventana correspondientes
		/// </summary>
		void set_Windowed();

		/// <summary>
		/// Cambia los buffers para pintar
		/// </summary>
		void swap_buffers();

        /// <summary>
        /// Getter de width de la ventana
        /// </summary>
        /// <returns></returns>
        unsigned int get_width();

        /// <summary>
        /// Getter de height de la ventana
        /// </summary>
        /// <returns></returns>
        unsigned int get_height();

        /// <summary>
        /// Pone la sincronización vertical
        /// </summary>
        void enable_vsync();

        /// <summary>
        /// Quita la sincronización vertical
        /// </summary>
        void disable_vsync();

        /// <summary>
        /// Limpia la pantalla de lo pintado
        /// </summary>
        void clear() const;

		/// <summary>
		/// Event de reconocimiento de objetos de la ventana
		/// </summary>
		/// <param name="event"></param>
		/// <returns></returns>
		bool poll(Event& event);
	};
}