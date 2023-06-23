/**
* @file Ball_Script.h
* @brief Hijo del engine Update_Component, encargado del manejo de la bola del pong
* @author Arturo Vilar Carretero
*/

// Copyright (c) 2023 Arturo / Xohat
// arturovilarc@gmail.com / xohatlatte@gmail.com
// 2023.05 - 2023.06

#pragma once
#include "Update_Component.h"
#include "Entity.h"

#include "Player1_Controller.h"
#include "Player2_Controller.h"

using namespace Xohat;

class Ball_Script : public Update_Component
{
	//Referencia a los otros jugadores para poder determinar cuando se iguala o pasa la posición de uno
	Entity* player1;
	Entity* player2;

	/// <summary>
	/// Posición actual
	/// </summary>
	glm::vec3 curr_position;

	/// <summary>
	/// Velocidad con la que se mueve
	/// </summary>
	glm::vec3 speed_vector = {10, 2, 0};

public:

	/// <summary>
	/// Configura las referencias a los jugadores
	/// </summary>
	/// <param name="given_player1"></param>
	/// <param name="given_player2"></param>
	void set_players(Entity* given_player1, Entity* given_player2)
	{
		player1 = given_player1;
		player2 = given_player2;
	}

	/// <summary>
	/// Se configura la velocidad con la que que se mueve
	/// </summary>
	/// <param name="new_speed"></param>
	void set_speed(glm::vec3 new_speed)
	{
		speed_vector = new_speed;
	}

	/// <summary>
	/// Se actualiza la posición actual
	/// </summary>
	void check_position() 
	{
		curr_position = owner->get_transform()->get_position();
	}

	/// <summary>
	/// El update ocurre una vez por fotograma y revisa, 
	/// primero la posición actual del jugador, 
	/// luego le añade el movimiento en base a la velocidad y 
	/// finalmente mira si ha llegado a los límites para cambiar de sentido
	/// </summary>
	/// <param name="t"></param>
	void update(float t) override 
	{
		check_position();

		owner->get_transform()->set_position({ curr_position.x + speed_vector.x * t, 
											   curr_position.y + speed_vector.y * t, 
											   curr_position.z + speed_vector.z * t });

		check_bounce();
	}

	/// <summary>
	/// Se comprueba si se ha llegado al límite de uno de los jugadores para forzar un rebote
	/// </summary>
	void check_bounce() 
	{
					// Ha pasado la position del jugador 1								   
		if (curr_position.x <= player1->get_transform()->get_position().x)
		{
			speed_vector.x = 10.f;
			speed_vector.y = -2.f;
		}
					// Ha pasado la position del jugador 2
		else if (curr_position.x >= player2->get_transform()->get_position().x)
		{
			speed_vector.x = -10.f;
			speed_vector.y = 2.f;
		}
	}
};
