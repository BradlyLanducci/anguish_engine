#pragma once

//------------------------------------------------------------------//

#include <cstdint>

//------------------------------------------------------------------//

struct StereoSample
{
    float left{};
    float right{};
};

//------------------------------------------------------------------//

struct StereoSampleBuffer
{
    StereoSample *begin()
    {
        return p_samples;
    }

    StereoSample *end()
    {
        return p_samples + numSamples;
    }

    size_t numSamples{};
    StereoSample *p_samples{ nullptr };
};

//------------------------------------------------------------------//
