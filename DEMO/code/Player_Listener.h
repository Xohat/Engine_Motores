/**
* @file Player_Listener.h
* @brief Hijo de Message_Listener se encarga de crear una implementación para que los hijos de los jugadores puedan usar apra poder ejecutar su movimiento correspondiente
* @author Arturo Vilar Carretero
*/

// Copyright (c) 2023 Arturo / Xohat
// arturovilarc@gmail.com / xohatlatte@gmail.com
// 2023.05 - 2023.06

#pragma once

#pragma once
#include "Message.h"

using namespace Xohat;

class Player_Listener : public Message_Listener
{

public:

	/// <summary>
	/// Método heredado de Message_Listener
	/// </summary>
	/// <param name="m"></param>
	void handle(const Message& m) 
	{
		received = true;
	}
};