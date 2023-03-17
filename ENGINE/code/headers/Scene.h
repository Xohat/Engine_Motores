#pragma once
#include "Kernel.h"
#include <SDL.h>

class Scene 
{
	Kernel kernel;

	Input_Task i_task;
	Update_Task u_task;
	Render_Task r_task;

	Message_Dispatcher message_dispatcher;

		  //ID           //Object Pointer
	map< string, shared_ptr< Entity > > entities;

	Window * window;

public:

	// en el constructor de scene a�adir las tareas de Scene
	// Orden: Escala, rotaci�n, translaci�n

	// getter window
	// getter de message_dispatcher

	// getter entidad

	Scene(Window given_window)
	{
		window = given_window;
	}

	void stop() 
	{
		kernel.stop();
	}

	void run() 
	{
		kernel.run();
	}
};