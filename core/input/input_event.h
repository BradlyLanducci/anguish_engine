#pragma once

//------------------------------------------------------------------//

#include <math/vector2.h>
#include <input/input_manager.h>
#include <input/keyboard.h>

#include <GLFW/glfw3.h>
#include <unordered_map>
#include <atomic>

//------------------------------------------------------------------//

struct InputEvent
{
    enum class Type : uint32_t
    {
        Mouse,
        Keyboard
    };

    friend InputManager;
};

//------------------------------------------------------------------//

struct MouseInputEvent : public InputEvent
{
    Vector2 position;
    bool pressed{ false };
};

//------------------------------------------------------------------//

struct KeyboardEvent : public InputEvent
{
    Keyboard::Key key;
    bool pressed{ false };
};

//------------------------------------------------------------------//
