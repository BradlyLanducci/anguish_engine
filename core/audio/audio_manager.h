#pragma once

//------------------------------------------------------------------//

#include <miniaudio.h>

#include <vector>

//------------------------------------------------------------------//

class AudioPlayer;

//------------------------------------------------------------------//

class AudioManager
{
public:
    static AudioManager &get();

    void initialize();
    void deInitialize();

    void addAudioPlayer(AudioPlayer *audioPlayer);
    void removeAudioPlayer(AudioPlayer *audioPlayer);

    ma_device &device();

    void process();

    AudioManager(const AudioManager &) = delete;
    AudioManager &operator=(const AudioManager &) = delete;

private:
    AudioManager() = default;

    static void dataCallback(ma_device *p_device, void *p_output, const void *p_input, ma_uint32 frameCount);

    /*
        TODO: For some reason making these variables not static causes issues with the mini audio callback...
        That doesn't really make any sense to me right now
    */
    static inline std::vector<float> m_tempBuffer;

    static inline ma_bool32 m_deviceInitialized{ false };
    static inline ma_device m_device;
    static inline bool m_deviceRunning{ false };

    static inline std::vector<AudioPlayer *> m_audioPlayers;
    static inline ma_device_config m_deviceConfig;
};

//------------------------------------------------------------------//
