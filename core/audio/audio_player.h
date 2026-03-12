#pragma once

#include <audio/audio_manager.h>
#include <audio/volume_effect.h>

#include <miniaudio.h>
#include <string>
#include <unordered_map>

//------------------------------------------------------------------//

struct StereoSampleBuffer;

//------------------------------------------------------------------//

class AudioPlayer
{
public:
    AudioPlayer(const std::string &audioFilePath);
    ~AudioPlayer();

    void setFile(const std::string &audioFilePath);
    void setVolumeDb(double volumeDb);

    bool isPlaying() const;

    void play(bool loop = false);
    void reset();
    void stop();

    void addEffect(AudioEffect *p_effect);

private:
    void deInitDecoder();
    void initDecoder();

    ma_decoder &decoder();
    void process(StereoSampleBuffer &buffer);

    friend AudioManager;

    bool m_isPlaying{ false };

    std::string m_audioFilePath;

    ma_decoder m_decoder;

    VolumeEffect m_volume;
    std::vector<AudioEffect *> m_effects;
};

//------------------------------------------------------------------//
