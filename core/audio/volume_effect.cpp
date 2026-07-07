#include <audio/volume_effect.h>

#include <utilities/logger.h>

#include <cmath>

//------------------------------------------------------------------//

BEGIN_AE_NAMESPACE

//------------------------------------------------------------------//

VolumeEffect::VolumeEffect(double volumeDb)
{
    setVolumeDb(volumeDb);
}

//------------------------------------------------------------------//

void VolumeEffect::setVolumeDb(double volumeDb)
{
    m_volumeLinear = std::pow(10.0, volumeDb / 20.0);
}

//------------------------------------------------------------------//

void VolumeEffect::process(StereoSampleBuffer &buffer)
{
    for (auto &s : buffer)
    {
        s.left *= m_volumeLinear;
        s.right *= m_volumeLinear;
    }
}

//------------------------------------------------------------------//

END_AE_NAMESPACE

//------------------------------------------------------------------//
