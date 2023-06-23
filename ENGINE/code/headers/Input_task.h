/**
* @file Input_task.h
* @brief Código relacionado con las tasks por inputs del jugador
* @author Arturo Vilar Carretero
*/

// Copyright (c) 2023 Arturo / Xohat
// arturovilarc@gmail.com / xohatlatte@gmail.com
// 2023.05 - 2023.06

#pragma once

#include "Task.h"
#include "Keyboard.hpp"
#include "Message.h"

namespace Xohat 
{
	// Declaración adelantada de Scene
	class Scene;

	class Input_Task : public Task
	{
	public:

		/// <summary>
		/// Enumaerador de 
		/// </summary>
		enum Input_devices_for_messages
		{
			KEYBOARD_KEY_PRESSED,

			KEYBOARD_A_PRESSED,
			KEYBOARD_Q_PRESSED,
			KEYBOARD_S_PRESSED,
			KEYBOARD_W_PRESSED,

			KEYBOARD_U_PRESSED,
			KEYBOARD_H_PRESSED,
			KEYBOARD_J_PRESSED,
			KEYBOARD_K_PRESSED,

			KEYBOARD_KEY_RELEASED,
			MOUSE_LEFT_BUTTON_PRESSED,
		};

	private:

		// Referencia a la escena
		Scene* scene;

		std::map< Input_devices_for_messages, Message> input_m_mapping;

	public:

		/// <summary>
		/// Constructor de Input_task
		/// </summary>
		/// <param name="given_scene"></param>
		Input_Task(Scene* given_scene)
		{
			scene = given_scene;
		}

		/// <summary>
		/// Añade el evento de input por la id proporcionada
		/// </summary>
		/// <param name="event"></param>
		/// <param name="messageID"></param>
		void add_Input(Input_devices_for_messages event, std::string&& messageID)
		{
			Message message("");
			message.id = messageID;
			input_m_mapping[event] = message;
		}

		/// <summary>
		/// Se encarga de recibir todos los inputs por parte de teclado
		/// </summary>
		/// <param name="t"></param>
		void run(float t) override;
	};
}

