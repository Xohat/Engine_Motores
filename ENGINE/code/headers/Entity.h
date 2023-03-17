#pragma once

class Entity 
{
	Scene * scene;

	Entity * parent = nullptr;

	map< string, shared_ptr < Component > > components;

	Transform_Component * transform;   // puntero al componente transform del mapa "componentes"
									   // para acceder más rápidamente a él

	// métodos get / set públicos

	// el constructor añade directamente un componente transform
};

class Component 
{
protected:

	Entity * owner;

	// métodos get / set
};

class Transform_Component : public Component 
{
	Vec3 position;
	Vec3 scale;
	Vec3 euler_angles;

public:

	void set_position ();
	void set_scale ();

	mat4 get_matrix() const 
	{
		mat4 transform_matrix;

		//aplicar escala, rotación y translación

		if (owner->get_parent () != nullptr)
			return owner->get_parent ()->get_transform()->get_matrix() * transform_matrix;
		else
			return transform_matrix;
	}
};

class Mesh_Component : public Component 
{
	shared_ptr<glt::Model> model;
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

class Racket_Controler : public Controller , public Message_Listener
{
public:
	void update(Scene & scene, Entity & entitiy, float t) 
	{
		// preguntar a la escena por otras entidades
		// mover entity
		// etc.
	}

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