#pragma once

#include "glm/glm.hpp"

namespace Xohat 
{
	
	class Entity;

	class Component
	{

	protected:

		Entity* owner;

		// métodos get / set
	};

	class Transform_Component : public Component
	{
		glm::vec3 position;
		glm::vec3 scale;
		glm::vec3 euler_angles;

	public:

		void set_position(glm::vec3 new_position)
		{
			position = new_position;
		}

		void set_scale(glm::vec3 new_scale)
		{
			scale = new_scale;
		}

		glm::mat4 get_matrix() const;
	};

	/*
	class Mesh_Component : public Component
	{
		// shared_ptr <glt::Model> model;
	};

	class Collider_Component : public Component
	{
		// colisiones
	};

	class Controller
	{
	public:
		virtual void update(float t) = 0;
	};

	class Control_Component : public Component
	{
		Controller* controller;
	};

	class Racket_Controler : public Controller, public Message_Listener
	{

	public:

		void update(Scene& scene, Entity& entitiy, float t)
		{
			// preguntar a la escena por otras entidades
			// mover entity
			// etc.
		}

		/*
		void handle(const Message& m)
		{
			if (m.id == "subir")
			{
				//Mover transform component arriba
			}
			else if (m.id == "bajar")
			{
				//mover transform component abajo
			}
		}
		
	};
	*/
}