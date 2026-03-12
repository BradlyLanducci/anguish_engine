#include <audio/audio_manager.h>
#include <audio/audio_player.h>
#include <audio/stereo_sample.h>
#include <utilities/logger.h>

//------------------------------------------------------------------//

constexpr ma_format sampleFormat{ ma_format_f32 };
constexpr ma_uint32 channels{ 2 };
constexpr ma_uint32 sampleRate{ 48'000 };

//------------------------------------------------------------------//

AudioManager &AudioManager::get()
{
    static AudioManager a;
    return a;
}

//------------------------------------------------------------------//

void AudioManager::initialize()
{
    m_deviceConfig = ma_device_config_init(ma_device_type_playback);
    m_deviceConfig.playback.format = sampleFormat;
    m_deviceConfig.playback.channels = 2;
    m_deviceConfig.sampleRate = sampleRate;
    m_deviceConfig.dataCallback = dataCallback;
    m_deviceConfig.pUserData = &m_audioPlayers;

    if (ma_device_init(nullptr, &m_deviceConfig, &m_device) != MA_SUCCESS)
    {
        Log(Error) << "Failed to open playback device";
    }
}

//------------------------------------------------------------------//

void AudioManager::deInitialize()
{
    ma_device_uninit(&m_device);
}

//------------------------------------------------------------------//

void AudioManager::addAudioPlayer(AudioPlayer *audioPlayer)
{
    m_audioPlayers.push_back(audioPlayer);
}

//------------------------------------------------------------------//

void AudioManager::removeAudioPlayer(AudioPlayer *audioPlayer)
{
    std::erase(m_audioPlayers, audioPlayer);
}

//------------------------------------------------------------------//

ma_device &AudioManager::device()
{
    return m_device;
}

//------------------------------------------------------------------//

void AudioManager::process()
{
    bool isPlaying{ false };
    for (auto &player : m_audioPlayers)
    {
        isPlaying |= player->isPlaying();
    }

    if (isPlaying && !m_deviceRunning)
    {
        m_deviceRunning = true;
        ma_device_start(&m_device);
    }
    else if (!isPlaying && m_deviceRunning)
    {
        m_deviceRunning = false;
        ma_device_stop(&m_device);
    }
}

//------------------------------------------------------------------//

void AudioManager::dataCallback(ma_device *p_device, void *p_output, const void *p_input, ma_uint32 frameCount)
{
    (void)p_input;

    auto p_this{ static_cast<AudioManager *>(p_device->pUserData) };

    if (p_this)
    {
        auto p_out{ static_cast<float *>(p_output) };
        auto &tempBuffer{ p_this->m_tempBuffer };

        ma_uint64 framesRead;
        tempBuffer.resize(frameCount * p_device->playback.channels, 0.f);

        for (auto &audioPlayer : p_this->m_audioPlayers)
        {
            if (audioPlayer->isPlaying())
            {
                ma_data_source_read_pcm_frames(&audioPlayer->decoder(), tempBuffer.data(), frameCount, &framesRead);

                if (framesRead < frameCount)
                {
                    audioPlayer->stop();
                }

                StereoSampleBuffer buffer{ tempBuffer.size() / 2, reinterpret_cast<StereoSample *>(tempBuffer.data()) };
                audioPlayer->process(buffer);

                for (size_t i = 0; i < framesRead * p_device->playback.channels; i++)
                {
                    p_out[i] += tempBuffer[i];
                }
            }
        }
    }
}

//------------------------------------------------------------------//
