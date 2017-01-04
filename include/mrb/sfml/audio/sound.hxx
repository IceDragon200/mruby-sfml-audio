#ifndef MRB_SFML_SOUND_H
#define MRB_SFML_SOUND_H

#include <mruby.h>
#include <mruby/data.h>
#include <SFML/Audio/Sound.hpp>
#include "mrb/sfml/helpers.hxx"

MRB_SFML_EXTERN const struct mrb_data_type mrb_sfml_sound_type;

static inline sf::Sound*
mrb_sfml_sound_ptr(mrb_state *mrb, mrb_value self)
{
  return static_cast<sf::Sound*>(mrb_data_get_ptr(mrb, self, &mrb_sfml_sound_type));
}

#endif
