/**
* @file Mesh_Component.cpp
* @brief Implementación del código de Mesh_Component.h
* @author Arturo Vilar Carretero
*/

// Copyright (c) 2023 Arturo / Xohat
// arturovilarc@gmail.com / xohatlatte@gmail.com
// 2023.05 - 2023.06

#include "..\headers\Mesh_Component.h"

#include <Cube.hpp>
#include <Model.hpp>
#include <Light.hpp>
#include <Render_Node.hpp>
#include "..\headers\Sample_Renderer.hpp"
#include "..\headers\Window.h"

using namespace engine;
using namespace glt;

namespace Xohat 
{
    void Mesh_Component::set_cube_Model()
    {
        model = std::make_shared <glt::Model>();
        std::shared_ptr < glt::Drawable > drawable = std::make_shared< glt::Cube >();
        std::shared_ptr < glt::Material > material = glt::Material::default_material();

        model->add(drawable, material);
    }
}