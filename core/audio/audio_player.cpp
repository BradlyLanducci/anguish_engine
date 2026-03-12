#include <audio/audio_effect.h>
#include <audio/audio_player.h>
#include <audio/audio_manager.h>
#include <audio/stereo_sample.h>
#include <audio/volume_effect.h>
#include <utilities/logger.h>

#include <stdio.h>

//------------------------------------------------------------------//

AudioPlayer::AudioPlayer(const std::string &audioFilePath)
    : m_audioFilePath(audioFilePath)
{
    initDecoder();
    AudioManager::get().addAudioPlayer(this);
}

//------------------------------------------------------------------//

AudioPlayer::~AudioPlayer()
{
    AudioManager::get().removeAudioPlayer(this);
    deInitDecoder();
}

//------------------------------------------------------------------//

void AudioPlayer::setFile(const std::string &audioFilePath)
{
    m_audioFilePath = audioFilePath;
}

//------------------------------------------------------------------//

void AudioPlayer::setVolumeDb(double volumeDb)
{
    m_volume.setVolumeDb(volumeDb);
}

//------------------------------------------------------------------//

bool AudioPlayer::isPlaying() const
{
    return m_isPlaying;
}

//------------------------------------------------------------------//

void AudioPlayer::play(bool loop)
{
    m_isPlaying = true;
    ma_data_source_set_looping(&m_decoder, static_cast<ma_bool32>(loop));
    reset();
}

//------------------------------------------------------------------//

void AudioPlayer::reset()
{
    ma_decoder_seek_to_pcm_frame(&m_decoder, 0);
}

//------------------------------------------------------------------//

void AudioPlayer::stop()
{
    reset();

    m_isPlaying = false;
}

//------------------------------------------------------------------//

void AudioPlayer::addEffect(AudioEffect *p_effect)
{
    m_effects.push_back(p_effect);
}

//------------------------------------------------------------------//

void AudioPlayer::deInitDecoder()
{
    ma_decoder_uninit(&m_decoder);
}

//------------------------------------------------------------------//

void AudioPlayer::initDecoder()
{
    auto result = ma_decoder_init_file(m_audioFilePath.c_str(), nullptr, &m_decoder);
    if (result != MA_SUCCESS)
    {
        Log(Error) << "Failed to init decoder for " << m_audioFilePath;
        return;
    }
}

//------------------------------------------------------------------//

ma_decoder &AudioPlayer::decoder()
{
    return m_decoder;
}

//------------------------------------------------------------------//

void AudioPlayer::process(StereoSampleBuffer &buffer)
{
    m_volume.process(buffer);

    for (const auto &p_effect : m_effects)
    {
        p_effect->process(buffer);
    }
}

//------------------------------------------------------------------//
