#ifndef MRB_SFML_SOUND_BUFFER_RECORDER_H
#define MRB_SFML_SOUND_BUFFER_RECORDER_H

#include <mruby.h>
#include <mruby/data.h>
#include <SFML/Audio/SoundBufferRecorder.hpp>

extern "C" const struct mrb_data_type mrb_sfml_sound_buffer_recorder_type;

static inline sf::SoundBufferRecorder*
mrb_sfml_sound_buffer_recorder_ptr(mrb_state *mrb, mrb_value self)
{
  return static_cast<sf::SoundBufferRecorder*>(mrb_data_get_ptr(mrb, self, &mrb_sfml_sound_buffer_recorder_type));
}

#endif
