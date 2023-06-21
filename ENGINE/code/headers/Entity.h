#pragma once

#include "Message.h"
#include "Components.h"

#include "glm/glm.hpp"

#include <map>
#include <string>
#include <memory>

using namespace std;
using namespace glm;

namespace glt 
{
	class Model;
}

namespace Xohat 
{
	class Scene;

	class Entity
	{
		Scene* scene;

		Entity* parent = nullptr;

		map< string, shared_ptr < Component > > components;

		Transform_Component* transform;   // puntero al componente transform del mapa "componentes"
		// para acceder m�s r�pidamente a �l

	public:

		// el constructor a�ade directamente un componente Transform_Component
		Entity()
		{
			transform = new Transform_Component(); // Crea un nuevo objeto Transform_Component
		}

		~Entity()
		{
			delete transform; // Libera la memoria del objeto Transform_Component al destruir el objeto Entity
		}

		// m�todos get / set p�blicos
		Entity* get_parent() const
		{
			return parent;
		}

		Transform_Component* get_transform() const
		{
			return transform;
		}
	};
}