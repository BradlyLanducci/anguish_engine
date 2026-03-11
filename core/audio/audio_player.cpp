#include <audio/audio_player.h>
#include <utilities/logger.h>

#include <stdio.h>

//------------------------------------------------------------------//

AudioPlayer::AudioPlayer(const std::string &audioFilePath)
    : m_audioFilePath(audioFilePath)
{
    initDecoder();
    m_decoders.try_emplace(&m_decoder, MA_FALSE);
}

//------------------------------------------------------------------//

AudioPlayer::~AudioPlayer()
{
    deInitDecoder();
    deInitDevice();
}

//------------------------------------------------------------------//

void AudioPlayer::setFile(const std::string &audioFilePath)
{
    m_audioFilePath = audioFilePath;
}

//------------------------------------------------------------------//

void AudioPlayer::play()
{
    initDevice();

    if (ma_device_start(&m_device) == MA_SUCCESS)
    {
        reset();
        m_decoders[&m_decoder] = MA_TRUE;
    }
    else
    {
        Log(Error) << "Failed to start playback device";
    }
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

    m_decoders[&m_decoder] = MA_FALSE;

    ma_bool32 isPlaying{ MA_FALSE };
    for (const auto &[decoder, playing] : m_decoders)
    {
        isPlaying |= playing;
    }

    if (isPlaying == MA_FALSE)
    {
        ma_device_stop(&m_device);
    }
}

//------------------------------------------------------------------//

void AudioPlayer::deInitDevice()
{
    if (m_deviceInitialized)
    {
        m_deviceInitialized = false;
        ma_device_uninit(&m_device);
    }
}

//------------------------------------------------------------------//

void AudioPlayer::initDevice()
{
    if (!m_deviceInitialized)
    {
        m_deviceInitialized = true;

        m_deviceConfig = ma_device_config_init(ma_device_type_playback);
        m_deviceConfig.playback.format = m_decoder.outputFormat;
        m_deviceConfig.playback.channels = m_decoder.outputChannels;
        m_deviceConfig.sampleRate = m_decoder.outputSampleRate;
        m_deviceConfig.dataCallback = dataCallback;
        m_deviceConfig.pUserData = this;

        if (ma_device_init(nullptr, &m_deviceConfig, &m_device) != MA_SUCCESS)
        {
            Log(Error) << "Failed to open playback device";
            return;
        }
    }
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

void AudioPlayer::dataCallback(ma_device *p_device, void *p_output, const void *p_input, ma_uint32 frameCount)
{
    (void)p_input;

    auto *p_this{ static_cast<AudioPlayer *>(p_device->pUserData) };

    if (p_this)
    {
        auto &decoders{ p_this->m_decoders };
        auto p_out{ static_cast<float *>(p_output) };

        ma_uint64 framesRead;
        m_tempBuffer.resize(frameCount * p_device->playback.channels);

        for (auto &[decoder, playing] : p_this->m_decoders)
        {
            if (playing)
            {
                ma_decoder_read_pcm_frames(decoder, m_tempBuffer.data(), frameCount, &framesRead);

                if (framesRead < frameCount)
                {
                    decoders[decoder] = MA_FALSE;
                }

                for (size_t i = 0; i < framesRead * p_device->playback.channels; i++)
                {
                    p_out[i] += m_tempBuffer[i];
                }
            }
        }
    }
}

//------------------------------------------------------------------//
