/**
* @file Main.cpp
* @brief Manera de ejecutar el código por parte del engine
* @author Arturo Vilar Carretero
*/

// Copyright (c) 2023 Arturo / Xohat
// arturovilarc@gmail.com / xohatlatte@gmail.com
// 2023.05 - 2023.06

#include "Window.h"
#include "Scene.h"
#include "Entity.h"
#include "Ball_Script.h"
#include "Player1_Controller.h"

using namespace Xohat;

int main()
{
    //Se crea la ventana
	std::string name("Engine Motores");
	Window MainWindow(name, 1024, 768, false);

    //Se crea la escena
	Scene scene(MainWindow);

    //Creación de la bola
	std::shared_ptr <Ball_Script> ball = std::make_shared<Ball_Script>();
	ball->set_players(scene.get_entity().at("Left_wall_entity").get(), scene.get_entity().at("Right_wall_entity").get());

    // Creación de los players
    std::shared_ptr <Player1_Controller> player_1 = std::make_shared<Player1_Controller>();
    std::shared_ptr <Player2_Controller> player_2 = std::make_shared<Player2_Controller>();

    // Adición del update component para las entidadaes
	scene.add_update_component_to_entity("Ball_entity", ball);
	scene.add_update_component_to_entity("Left_wall_entity", player_1);
	scene.add_update_component_to_entity("Right_wall_entity", player_2);


    //-----------------------------------INPUT Y LISTENER--------------------------------------------

    // Configurar input devices
    scene.get_input_task()->add_Input(Input_Task::Input_devices_for_messages::KEYBOARD_W_PRESSED, "subir_p1");
    scene.get_input_task()->add_Input(Input_Task::Input_devices_for_messages::KEYBOARD_S_PRESSED, "bajar_p1");
    scene.get_input_task()->add_Input(Input_Task::Input_devices_for_messages::KEYBOARD_Q_PRESSED, "subir_p2");
    scene.get_input_task()->add_Input(Input_Task::Input_devices_for_messages::KEYBOARD_A_PRESSED, "bajar_p2");

    // Condifgurar listeners
    scene.get_dispatcher()->register_listener("subir_p1", &player_1->player1_up_listener);
    scene.get_dispatcher()->register_listener("bajar_p1", &player_1->player1_down_listener);
    scene.get_dispatcher()->register_listener("subir_p2", &player_2->player2_up_listener);
    scene.get_dispatcher()->register_listener("bajar_p2", &player_2->player2_down_listener);

    scene.run();

	return 0;
}

void configure_Input_devices(Scene scene) 
{

}

void configure_listeners(Scene scene, std::shared_ptr < Player1_Controller> p1, std::shared_ptr < Player2_Controller > p2)
{

}
