#pragma once

//Es como una interfaz
class Task 
{
protected:

	Scene* scene;

public:

	virtual void run(float t) = 0;
};

class Input_Task : public Task 
{
public:
	// constructor
	void run(float t) override 
	{
		Window & window scene->get_window();

		Event event;

		while (window.poll(event) > 0) 
		{
			switch (event.type) 
			{
				case KEY_PRESSED:
				{
					switch (event.key.code) 
					{
						case ARROW_UP: 
						{
							Message message("subir");
							scene->get_message_dispatcher()->send(message);
							break;
						}
					}

					break;
				}
			}
		}
	}
};

class Update_Task : public Task
{
public:
	//constructor
	void run(float t) override;
};

class Render_Task : public Task
{
	list< shared_ptr< Mesh_Component > > meshes;

	glt::Render_Node renderer;

public:

	shared_ptr< Component > create_component(?);

	//constructor
	void run(float t) override 
	{
		for (auto& mesh : meshes) 
		{
			mesh->model->set_transformation (mesh->owner->get_transform()->get_matrix ());
		}

		scene->get_window()->clear();

		renderer->render();

		scene->get_window()->swap_buffers();
	}
};

class Control_Task : public Task 
{
	list< shared_ptr< Control_Component > > control_components;

	void run(float t) override 
	{
		for (auto& component : control_components)
		{
			component->controller->update(*scene, component->owner, t);
		}
	}
};