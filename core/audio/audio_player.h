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
    /// @brief Creates an audio player and initializes it with an audio file.
    /// @param audioFilePath The path to the audio file.
    AudioPlayer(const std::string &audioFilePath);

    ~AudioPlayer();

    /// @brief Reinitializes this audio player with a new audio file
    /// @param audioFilePath The new audio file to initialize.
    void setFile(const std::string &audioFilePath);

    /// @brief Sets this audio players volume in decibels.
    /// @param volumeDb Volume in decibels.
    void setVolumeDb(double volumeDb);

    bool isPlaying() const;

    /// @brief Starts this audio player at the beginning of the next game frame.
    /// @param loop Whether or not this audio player should continously play its audio in a loop.
    void play(bool loop = false);

    /// @brief Seeks the playhead for this audio player to zero.
    void reset();

    /// @brief Stops this audio player at the beginning of the next game frame.
    void stop();

    /// @brief Adds an audio effect that will over the audio stream associated with this player.
    /// @param p_effect The effect to add.
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
