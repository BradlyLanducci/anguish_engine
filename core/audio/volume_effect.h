#pragma once

#include <audio/audio_effect.h>

//------------------------------------------------------------------//

BEGIN_AE_NAMESPACE

//------------------------------------------------------------------//

class VolumeEffect : public AudioEffect
{
public:
    VolumeEffect() = default;
    VolumeEffect(double volumeDb);

    void setVolumeDb(double volumeDb);

    void process(StereoSampleBuffer &buffer) override;

private:
    double m_volumeLinear{ 1.f };
};

//------------------------------------------------------------------//

END_AE_NAMESPACE

//------------------------------------------------------------------//
