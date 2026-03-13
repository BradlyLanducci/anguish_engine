#pragma once

//------------------------------------------------------------------//

#include <utilities/window.h>

#include <vector>
#include <thread>

//------------------------------------------------------------------//

class Layer;

//------------------------------------------------------------------//

class App
{
public:
    App();
    /// @brief Runs the main app loop. Each of these loops is considered
    /// a 'App Frame'.
    /// @return
    int run();

    template <typename LayerType, typename... Args>
        requires(std::is_base_of_v<Layer, LayerType>)
    void addLayer(Args... args)
    {
        m_layers.push_back(std::make_unique<LayerType>(args...));
    }

private:
    GLFWwindow *mp_window;

    std::vector<std::unique_ptr<Layer>> m_layers;
};

//------------------------------------------------------------------//
