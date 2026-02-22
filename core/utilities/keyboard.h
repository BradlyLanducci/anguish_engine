#pragma once

//------------------------------------------------------------------//

#include <GLFW/glfw3.h>

#include <unordered_map>
#include <atomic>

//------------------------------------------------------------------//

class Keyboard
{
public:
    enum class Key : uint32_t
    {
        Backspace = 8,
        Tab = 9,
        Enter = 13,
        Escape = 27,
        Space = 32,
        Right = 262,
        Left = 263,
        Down = 264,
        Up = 265,
        Num_0 = '0',
        Num_1 = '1',
        Num_2 = '2',
        Num_3 = '3',
        Num_4 = '4',
        Num_5 = '5',
        Num_6 = '6',
        Num_7 = '7',
        Num_8 = '8',
        Num_9 = '9',
        A = 'A',
        B = 'B',
        C = 'C',
        D = 'D',
        E = 'E',
        F = 'F',
        G = 'G',
        H = 'H',
        I = 'I',
        J = 'J',
        K = 'K',
        L = 'L',
        M = 'M',
        N = 'N',
        O = 'O',
        P = 'P',
        Q = 'Q',
        R = 'R',
        S = 'S',
        T = 'T',
        U = 'U',
        V = 'V',
        W = 'W',
        X = 'X',
        Y = 'Y',
        Z = 'Z',
        Apostrophe = '\'',
        Comma = ',',
        Minus = '-',
        Period = '.',
        Slash = '/',
        Semicolon = ';',
        Equals = '=',
        Left_bracket = '[',
        Backslash = '\\',
        Right_bracket = ']',
        Back_tick = '`'
    };

    static void initialize(GLFWwindow *window);
    static bool isPressed(Key key);

private:
    static void processInput(GLFWwindow *window, int key, int scancode, int action, int mods);

    static inline std::unordered_map<Key, std::atomic<bool>> m_keyboard;
};

//------------------------------------------------------------------//