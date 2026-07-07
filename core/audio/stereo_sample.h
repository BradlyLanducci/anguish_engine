#pragma once

#include <ae_core.h>

#include <cstdint>

//------------------------------------------------------------------//

BEGIN_AE_NAMESPACE

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

END_AE_NAMESPACE

//------------------------------------------------------------------//
