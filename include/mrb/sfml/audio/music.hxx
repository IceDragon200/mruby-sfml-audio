#ifndef MRB_SFML_MUSIC_H
#define MRB_SFML_MUSIC_H

#include <mruby.h>
#include <mruby/data.h>
#include <SFML/Audio/Music.hpp>

extern "C" const struct mrb_data_type mrb_sfml_music_type;

static inline sf::Music*
mrb_sfml_music_ptr(mrb_state *mrb, mrb_value self)
{
  return static_cast<sf::Music*>(mrb_data_get_ptr(mrb, self, &mrb_sfml_music_type));
}

#endif
