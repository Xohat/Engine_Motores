#pragma once

#include <string>
//#include <OpenGL.hpp>

//using namespace glt;

class SDL_Window;

namespace Xohat
{
	class Window
	{

    public:

        
        /** Esta clase Event es espec�fica para los eventos de la ventana.
          * Por ello est� anidada dentro de Window. Se podr�a generalizar.
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

		SDL_Window * window;		// Declaraci�n del miembro window
		//SDL_GLContext gl_context;	// OpenGlToolkit context

	public:

		Window(const std::string title, unsigned width, unsigned height, bool fullScreen);

		~Window();

		void show();
		void hide();

		void setFullScreen();
		void setWindowed();

		void swapBuffers();

		bool poll(Event& event);
	};
}