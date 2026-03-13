#pragma once

#include <audio/stereo_sample.h>

//------------------------------------------------------------------//

class AudioEffect
{
public:
    virtual ~AudioEffect() = default;

    /// @brief Audio effects override this method and are given the current stereo sample buffer
    /// from the owning audio player stream.
    /// @param buffer The buffer to process.
    virtual void process(StereoSampleBuffer &buffer) = 0;
};

//------------------------------------------------------------------//
