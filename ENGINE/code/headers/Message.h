/**
* @file Message.h
* @brief Código relacionado con el sistema de mensajería
* @author Arturo Vilar Carretero
*/

// Copyright (c) 2023 Arturo / Xohat
// arturovilarc@gmail.com / xohatlatte@gmail.com
// 2023.05 - 2023.06

#pragma once

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <memory>

#include "glm/glm.hpp"

using namespace std;

namespace Xohat 
{
	/// <summary>
	/// Mensaje básico, solo presenta una ID
	/// </summary>
	struct Message
	{
		string id;

		Message() = default;

        Message(string given_id) 
        {
            id = given_id;
        }
	};

	/// <summary>
	/// Encargado de escuchar los mensajes, la variable received se usa para activar 
	/// o desactivar el movimiento de los objetos player en el proyecto de Sandbox
	/// </summary>
	class Message_Listener
	{
	public:

        bool received = false;

		virtual void handle(const Message& m) = 0;
	};

	/// <summary>
	/// Encargado de transmitir mensajes, luego los Message_Listener tienen 
	/// que suscrbirse al flujo de información que proporciona
	/// </summary>
	class Message_Dispatcher
	{
		/// <summary>
		/// Lista de listeners
		/// </summary>
		map< string, list< Message_Listener* > > listeners;

	public:

		/// <summary>
		/// Añade al listener a escuchar, buscando una ID concreta dentro del flujo de información
		/// </summary>
		/// <param name="message_id"></param>
		/// <param name="listener"></param>
		void register_listener(const string& message_id, Message_Listener* listener)
		{
            if (listener)
            {
                listeners[message_id].push_back(listener);
            }
		}

		/// <summary>
		/// Envia un mensaje al flujo de información
		/// </summary>
		/// <param name="messsage"></param>
		void send(const Message& messsage)
		{
			auto handlers = listeners.find(messsage.id);

			if (handlers != listeners.end())
			{
				for (auto handler : handlers->second)
				{
					handler->handle(messsage);
				}
			}

			else
				cout << "meesage with ID = " << messsage.id << " lost!" << endl;
		}
	};
}