#ifndef MRB_SFML_SOUND_SOURCE_PRIV_H
#define MRB_SFML_SOUND_SOURCE_PRIV_H

#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <mruby/numeric.h>
#include <SFML/Audio/SoundSource.hpp>
#include "mrb/cxx/helpers.hxx"
#include "mrb/sfml/system/vector3.hxx"

extern "C" void mrb_sfml_sound_source_init_bind(mrb_state *mrb, struct RClass *mod);

template <class T>
static inline T*
get_sound_source(mrb_state *mrb, mrb_value self)
{
  return cxx_mrb_data_get_ptr<T>(mrb, self);
}

template <class T>
static mrb_value
sound_source_set_pitch(mrb_state *mrb, mrb_value self)
{
  mrb_float pitch;
  mrb_get_args(mrb, "f", &pitch);
  get_sound_source<T>(mrb, self)->setPitch(pitch);
  return self;
}

template <class T>
static mrb_value
sound_source_set_volume(mrb_state *mrb, mrb_value self)
{
  mrb_float volume;
  mrb_get_args(mrb, "f", &volume);
  get_sound_source<T>(mrb, self)->setVolume(volume);
  return self;
}

template <class T>
static mrb_value
sound_source_set_position(mrb_state *mrb, mrb_value self)
{
  mrb_value x;
  mrb_float y, z;
  mrb_int argc = mrb_get_args(mrb, "o|ff", &x, &y, &z);
  if (argc == 1) {
    get_sound_source<T>(mrb, self)->setPosition(*mrb_sfml_vector3f_ptr(mrb, x));
  } else if (argc == 3) {
    get_sound_source<T>(mrb, self)->setPosition(mrb_to_flo(mrb, x), y, z);
  } else {
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Expected 1 or 3 arguments.");
  }
  return self;
}

template <class T>
static mrb_value
sound_source_set_relative_to_listener(mrb_state *mrb, mrb_value self)
{
  mrb_bool rel;
  mrb_get_args(mrb, "b", &rel);
  get_sound_source<T>(mrb, self)->setRelativeToListener(rel);
  return self;
}

template <class T>
static mrb_value
sound_source_set_min_distance(mrb_state *mrb, mrb_value self)
{
  mrb_float min_distance;
  mrb_get_args(mrb, "f", &min_distance);
  get_sound_source<T>(mrb, self)->setMinDistance(min_distance);
  return self;
}

template <class T>
static mrb_value
sound_source_set_attenuation(mrb_state *mrb, mrb_value self)
{
  mrb_float attenuation;
  mrb_get_args(mrb, "f", &attenuation);
  get_sound_source<T>(mrb, self)->setAttenuation(attenuation);
  return self;
}

template <class T>
static mrb_value
sound_source_get_pitch(mrb_state *mrb, mrb_value self)
{
  return mrb_float_value(mrb, get_sound_source<T>(mrb, self)->getPitch());
}

template <class T>
static mrb_value
sound_source_get_volume(mrb_state *mrb, mrb_value self)
{
  return mrb_float_value(mrb, get_sound_source<T>(mrb, self)->getVolume());
}

template <class T>
static mrb_value
sound_source_get_position(mrb_state *mrb, mrb_value self)
{
  return mrb_sfml_vector3f_value(mrb, get_sound_source<T>(mrb, self)->getPosition());
}

template <class T>
static mrb_value
sound_source_is_relative_to_listener(mrb_state *mrb, mrb_value self)
{
  return mrb_bool_value(get_sound_source<T>(mrb, self)->isRelativeToListener());
}

template <class T>
static mrb_value
sound_source_get_min_distance(mrb_state *mrb, mrb_value self)
{
  return mrb_float_value(mrb, get_sound_source<T>(mrb, self)->getMinDistance());
}

template <class T>
static mrb_value
sound_source_get_attenuation(mrb_state *mrb, mrb_value self)
{
  return mrb_float_value(mrb, get_sound_source<T>(mrb, self)->getAttenuation());
}

template <class T>
static inline void
mrb_sfml_sound_source_bind_class(mrb_state *mrb, struct RClass *cls)
{
  mrb_define_method(mrb, cls, "set_pitch",                sound_source_set_pitch<T>,                MRB_ARGS_REQ(1));
  mrb_define_method(mrb, cls, "set_volume",               sound_source_set_volume<T>,               MRB_ARGS_REQ(1));
  mrb_define_method(mrb, cls, "set_position",             sound_source_set_position<T>,             MRB_ARGS_ARG(1,2));
  mrb_define_method(mrb, cls, "set_relative_to_listener", sound_source_set_relative_to_listener<T>, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, cls, "set_min_distance",         sound_source_set_min_distance<T>,         MRB_ARGS_REQ(1));
  mrb_define_method(mrb, cls, "set_attenuation",          sound_source_set_attenuation<T>,          MRB_ARGS_REQ(1));
  mrb_define_method(mrb, cls, "get_pitch",                sound_source_get_pitch<T>,                MRB_ARGS_NONE());
  mrb_define_method(mrb, cls, "get_volume",               sound_source_get_volume<T>,               MRB_ARGS_NONE());
  mrb_define_method(mrb, cls, "get_position",             sound_source_get_position<T>,             MRB_ARGS_NONE());
  mrb_define_method(mrb, cls, "is_relative_to_listener",  sound_source_is_relative_to_listener<T>,  MRB_ARGS_NONE());
  mrb_define_method(mrb, cls, "get_min_distance",         sound_source_get_min_distance<T>,         MRB_ARGS_NONE());
  mrb_define_method(mrb, cls, "get_attenuation",          sound_source_get_attenuation<T>,          MRB_ARGS_NONE());

  mrb_define_alias(mrb, cls, "pitch=",                "set_pitch");
  mrb_define_alias(mrb, cls, "volume=",               "set_volume");
  mrb_define_alias(mrb, cls, "position=",             "set_position");
  mrb_define_alias(mrb, cls, "relative_to_listener=", "set_relative_to_listener");
  mrb_define_alias(mrb, cls, "min_distance=",         "set_min_distance");
  mrb_define_alias(mrb, cls, "attenuation=",          "set_attenuation");
  mrb_define_alias(mrb, cls, "pitch",                 "get_pitch");
  mrb_define_alias(mrb, cls, "volume",                "get_volume");
  mrb_define_alias(mrb, cls, "position",              "get_position");
  mrb_define_alias(mrb, cls, "relative_to_listener?", "is_relative_to_listener");
  mrb_define_alias(mrb, cls, "min_distance",          "get_min_distance");
  mrb_define_alias(mrb, cls, "attenuation",           "get_attenuation");
}

#endif
