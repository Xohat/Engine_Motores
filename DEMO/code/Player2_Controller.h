/**
* @file Player2_Controller.h
* @brief Controlador del jugador 2, tambíen hijo de Update_Component
* @author Arturo Vilar Carretero
*/

// Copyright (c) 2023 Arturo / Xohat
// arturovilarc@gmail.com / xohatlatte@gmail.com
// 2023.05 - 2023.06

#pragma once
#include "Update_Component.h"
#include "Entity.h"
#include "Message.h"

using namespace Xohat;

class Player2_Controller : public Update_Component
{
	/// <summary>
	/// Variable de posición del jugador
	/// </summary>
	glm::vec3 position;

public:

	/// <summary>
	/// Listener para las acciones de ascenso
	/// </summary>
	Player_Listener player2_up_listener;
	/// <summary>
	/// Listener para las acciones de descenso
	/// </summary>
	Player_Listener player2_down_listener;

	/// <summary>
	/// Obtiene la posición actual del jugador
	/// </summary>
	/// <returns></returns>
	glm::vec3 get_current_pos()
	{
		position = owner->get_transform()->get_position();
		return position;
	}

	/// <summary>
	/// El update ocurre una vez por fotograma y revisa, 
	/// primero la posición actual del jugador, tras esto revisa si el mensaje ha sidor ecibido para alguna de las dos acciones y lo ejecuta si es asi,
	///  al acabar de pulsar se vuelve a marcar la señal como falsa para poder escribirla otra vez
	/// </summary>
	/// <param name="t"></param>
	void update(float t) override
	{
		get_current_pos();

		if (player2_up_listener.received)
		{
			get_owner()->get_transform()->set_position({ position.x, position.y + 50.f * t, position.z });
			player2_up_listener.received = false;
		}

		if (player2_down_listener.received)
		{
			get_owner()->get_transform()->set_position({ position.x, position.y - 50.f * t, position.z });
			player2_down_listener.received = false;
		}
	}
};
