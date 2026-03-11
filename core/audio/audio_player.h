#pragma once

#include <miniaudio.h>

#include <string>
#include <unordered_map>

//------------------------------------------------------------------//

class AudioPlayer
{
public:
    AudioPlayer(const std::string &audioFilePath);
    ~AudioPlayer();

    void setFile(const std::string &audioFilePath);

    void play(bool loop = false);
    void reset();
    void stop();

private:
    static void dataCallback(ma_device *p_device, void *p_output, const void *p_input, ma_uint32 frameCount);

    void deInitDevice();
    void initDevice();

    void deInitDecoder();
    void initDecoder();

    static inline ma_bool32 m_deviceInitialized{ false };
    static inline ma_device m_device;

    static inline std::unordered_map<ma_decoder *, ma_bool32> m_decoders;
    static inline ma_device_config m_deviceConfig;

    static inline std::vector<float> m_tempBuffer;

    std::string m_audioFilePath;

    ma_decoder m_decoder;
};

//------------------------------------------------------------------//
