#pragma once

#include "Kernel.h"
#include "Window.h"

#include "Entity.h"
//#include "Message.h"

namespace Xohat 
{
	class Scene 
	{
		Kernel kernel;

		/*
		Input_Task i_task;
		Update_Task u_task;
		Render_Task r_task;
		*/

		//Message_Dispatcher message_dispatcher;

			  //ID     //Object Pointer
		map< string, shared_ptr< Entity > > entities;

		Window * window;

	public:

		// en el constructor de scene añadir las tareas de Scene
		// Orden: Escala, rotación, translación
		Scene(Window& given_window)
		{
			window = &given_window;
		}

		// getter window
		Window* get_window() const
		{
			return window;
		}
		
		/*
		// getter de message_dispatcher
		Message_Dispatcher* get_dispatcher() 		
		{
			return &message_dispatcher;
		}

		// getter mapa de entidades
		map< string, shared_ptr< Entity > > get_entity() 
		{
			return entities;
		}
		*/

		void stop() 
		{
			kernel.stop();
		}

		void run() 
		{
			kernel.run();
		}
	};
}