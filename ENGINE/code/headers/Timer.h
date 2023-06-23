/**
* @file Timer.h
* @brief Código relacionado con el cronometraje de acciones
* @author Arturo Vilar Carretero
*/

// Copyright (c) 2023 Arturo / Xohat
// arturovilarc@gmail.com / xohatlatte@gmail.com
// 2023.05 - 2023.06

#pragma once

#include <chrono>

namespace Xohat 
{
	class Timer
	{
    private:
        std::chrono::high_resolution_clock::time_point start_time;

    public:
        Timer()
        {
            reset();
        }

        void reset()
        {
            start_time = std::chrono::high_resolution_clock::now();
        }

        float get_elapsed_seconds()
        {
            std::chrono::high_resolution_clock::time_point current_time = std::chrono::high_resolution_clock::now();
            std::chrono::duration<float> elapsed_seconds = current_time - start_time;
            return elapsed_seconds.count();
        }
	};
}