#pragma once

//------------------------------------------------------------------//

#include <math/vector2.h>
#include <input/input_manager.h>
#include <input/keyboard.h>
#include <input/mouse.h>
#include <utilities/logger.h>

#include <GLFW/glfw3.h>
#include <unordered_map>
#include <atomic>
#include <sstream>

//------------------------------------------------------------------//

BEGIN_AE_NAMESPACE

//------------------------------------------------------------------//

struct InputEvent
{
    enum class Type : int
    {
        Mouse,
        Keyboard
    };

    virtual std::string toString() = 0;

    template <typename DesiredType, typename EventType>
    static Shared<DesiredType> GetType(Shared<EventType> inputEvent)
    {
        return std::dynamic_pointer_cast<DesiredType>(inputEvent);
    }

    friend InputManager;
};

//------------------------------------------------------------------//

struct MouseInputEvent : public InputEvent
{
    Vector2 position;

    std::string toString() override
    {
        std::stringstream ss;
        ss << "Mouse Input Event, Position: " << position;
        return ss.str();
    }
};

//------------------------------------------------------------------//

struct MouseMoveEvent final : public MouseInputEvent
{
    std::string toString() override
    {
        std::stringstream ss;
        ss << "Mouse Move Event, Position: " << position;
        return ss.str();
    }
};

//------------------------------------------------------------------//

struct MouseClickEvent final : public MouseInputEvent
{
    bool pressed{ false };
    Mouse::ButtonType buttonType;

    std::string toString() override
    {
        std::stringstream ss;
        ss << "Mouse Click Event, Position: " << position << " Pressed: " << pressed
           << " Button Type: " << magic_enum::enum_name<Mouse::ButtonType>(buttonType);
        return ss.str();
    }
};

//------------------------------------------------------------------//

struct KeyboardEvent final : public InputEvent
{
    Keyboard::Key key;
    bool pressed{ false };

    std::string toString() override
    {
        std::stringstream ss;
        ss << "Keyboard Event, Key: " << magic_enum::enum_name<Keyboard::Key>(key) << " Pressed: " << pressed;
        return ss.str();
    }
};

//------------------------------------------------------------------//

END_AE_NAMESPACE

//------------------------------------------------------------------//
