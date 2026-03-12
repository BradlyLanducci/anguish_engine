#pragma once

#include <audio/stereo_sample.h>

//------------------------------------------------------------------//

class AudioEffect
{
public:
    virtual ~AudioEffect() = default;

    virtual void process(StereoSampleBuffer &buffer) = 0;
};

//------------------------------------------------------------------//
