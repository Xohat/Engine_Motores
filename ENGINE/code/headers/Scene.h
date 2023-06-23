/**
* @file Scene.h
* @brief Código relacionado con todo el ciclo de la escena
* @author Arturo Vilar Carretero
*/

// Copyright (c) 2023 Arturo / Xohat
// arturovilarc@gmail.com / xohatlatte@gmail.com
// 2023.05 - 2023.06

#pragma once

#include "Kernel.h"
#include "Window.h"

#include "Entity.h"
#include "Input_task.h"
#include "Render_Task.h"
#include "Update_task.h"
#include "Sample_Renderer.hpp"

#include "Message.h"

using namespace engine;
using namespace glt;

namespace Xohat 
{
	class Scene 
	{
		/// <summary>
		/// Kernel encargado del manejo del sistema de tasks
		/// </summary>
		Kernel kernel;

		/// <summary>
		/// Tasks
		/// </summary>
		Input_Task* i_task;
		Render_Task* r_task;
		Update_task* u_task;

		/// <summary>
		/// Central de mensajes, donde se mandan todos y luego al gente se suscribe para recibirlos
		/// </summary>
		Message_Dispatcher* message_dispatcher;
		
		
		/// <summary>
		/// Mapa de entidades
		/// </summary>  
		map< string, shared_ptr<Entity> > entities;
		      //ID   //Object Pointer
		
		/// <summary>
		/// Referencia a la ventana para poder tener una escena donde se define la escena
		/// </summary>
		Window * window;

	public:

		/// <summary>
		/// Constructor de escena, define toda la configración básica de la escena
		/// </summary>
		Scene(Window& given_window)
		{
			window = &given_window;

			window->enable_vsync();

			message_dispatcher = new Message_Dispatcher();

			// Asignación de Tasks
			i_task = new Input_Task(this);
			u_task = new Update_task();
			r_task = new Render_Task();

			// Creación del contexto básico de OpenGlToolkit
			r_task->initialize_render_task(this);

			// Creación de Entidades
			create_entity(*r_task, "Right_wall_entity"	, { 4.5f, 0, 0 }	, { 0.25f, 1, 0.25f });
			create_entity(*r_task, "Left_wall_entity"	, { -4.5f, 0, 0 }	, { 0.25f, 1, 0.25f });
			create_entity(*r_task, "Ball_entity"		, { 0, 0, 0 }		, { 0.25f, 0.25f, 0.25f });

			// Asignacion de tasks para la escena
			kernel.add_task(i_task);
			kernel.add_task(r_task);
			kernel.add_task(u_task);
		}

		/// <summary>
		/// Creador de entities genéricas de tipo cubo
		/// </summary>
		/// <param name="render_task"></param>
		/// <param name="entity_name"></param>
		/// <param name="position"></param>
		/// <param name="scale"></param>
		void create_entity(Render_Task& render_task, string entity_name, glm::vec3 position, glm::vec3 scale)
		{
			// Se crea una entidad vácia
			shared_ptr<Entity> entity_to_add = make_shared<Entity>(this);
			entity_to_add->set_name(entity_name);

			// Configuración de valores iniciales
			render_task.add_mesh_component_to_meshes(entity_to_add.get());
			entity_to_add->get_transform()->set_position(position);
			entity_to_add->get_transform()->set_scale(scale);

			// Añade la entidad al mapa de entidades tras configurarase
			add_entity(entity_to_add->get_name(), entity_to_add);
		}

		/// <summary>
		/// Como su nombre indica añade el componente de update a 
		/// la entidad de ID especificada para el mapa de entidades
		/// </summary>
		/// <param name="entity_id"></param>
		/// <param name="update_c"></param>
		void add_update_component_to_entity(string entity_id, std::shared_ptr<Update_Component> update_c)
		{
			shared_ptr<Entity> entity = entities[entity_id];

			entity->update_comp = update_c;
			update_c->set_owner(entity.get());

			u_task->add_update_component(update_c);
		}

		/// <summary>
		/// Getter de Window
		/// </summary>
		/// <returns></returns>
		Window* get_window() const
		{
			return window;
		}
		
		/// <summary>
		/// Getter de message_dispatcher
		/// </summary>
		/// <returns></returns>
		Message_Dispatcher* get_dispatcher() 		
		{
			return message_dispatcher;
		}

		/// <summary>
		/// Ciclo para cerrar la escena
		/// </summary>
		void stop() 
		{
			kernel.stop();
		}

		/// <summary>
		/// Ciclo de tasks, definido en mayor profundidad dentro de kernel.run
		/// </summary>
		void run() 
		{
			kernel.run();
		}

		/// <summary>
		/// Añade una entidad nueva al array de entidades con una ID
		/// </summary>
		/// <param name="ID"></param>
		/// <param name="entity_to_add"></param>
		void add_entity(string ID, shared_ptr< Entity > entity_to_add)
		{
			if (!entities.count(ID)) 
			{
				entities[ID] = entity_to_add;
			}
		}

		/// <summary>
		/// Getter de input task, usado para la recepcion de mensajes en el main del proyecto de Sandbox
		/// </summary>
		/// <returns></returns>
		Input_Task* get_input_task() 
		{
			return i_task;
		}

		/// <summary>
		/// Getter de mapa de entidades
		/// </summary>
		/// <returns></returns>
		map< string, shared_ptr< Entity > > get_entity()
		{
			return entities;
		}
	};
}