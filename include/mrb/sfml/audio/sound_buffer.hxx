#ifndef MRB_SFML_SOUND_BUFFER_H
#define MRB_SFML_SOUND_BUFFER_H

#include <mruby.h>
#include <mruby/data.h>
#include <SFML/Audio/SoundBuffer.hpp>

extern "C" const struct mrb_data_type mrb_sfml_sound_buffer_type;

static inline sf::SoundBuffer*
mrb_sfml_sound_buffer_ptr(mrb_state *mrb, mrb_value self)
{
  return static_cast<sf::SoundBuffer*>(mrb_data_get_ptr(mrb, self, &mrb_sfml_sound_buffer_type));
}

#endif
