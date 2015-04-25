#ifndef MRB_SFML_SOUND_RECORDER_PRIV_H
#define MRB_SFML_SOUND_RECORDER_PRIV_H

#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <mruby/string.h>
#include <SFML/Audio/SoundRecorder.hpp>
#include "mrb/cxx/helpers.hxx"

extern "C" void mrb_sfml_sound_recorder_init_bind(mrb_state *mrb, struct RClass *mod);

template <class T>
static inline T*
get_sound_recorder(mrb_state *mrb, mrb_value self)
{
  return cxx_mrb_data_get_ptr<T>(mrb, self);
}

/* @!class SFML::SoundRecorder<T>
 * @!method start(sample_rate)
 *   @param [Integer] sample_rate
 *   @return [self]
 */
template <class T>
static mrb_value
sound_recorder_start(mrb_state *mrb, mrb_value self)
{
  mrb_int sample_rate;
  mrb_get_args(mrb, "i", &sample_rate);
  return mrb_bool_value(get_sound_recorder<T>(mrb, self)->start(sample_rate));
}

/* @!class SFML::SoundRecorder<T>
 * @!method stop
 *   @return [self]
 */
template <class T>
static mrb_value
sound_recorder_stop(mrb_state *mrb, mrb_value self)
{
  get_sound_recorder<T>(mrb, self)->stop();
  return self;
}

/* @!class SFML::SoundRecorder<T>
 * @!method get_sample_rate
 *   @return [Integer]
 */
template <class T>
static mrb_value
sound_recorder_get_sample_rate(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(get_sound_recorder<T>(mrb, self)->getSampleRate());
}

/* @!class SFML::SoundRecorder<T>
 * @!method set_device(device)
 *   @param [String] device
 *   @return [Boolean]
 */
template <class T>
static mrb_value
sound_recorder_set_device(mrb_state *mrb, mrb_value self)
{
  char *str;
  mrb_get_args(mrb, "z", &str);
  return mrb_bool_value(get_sound_recorder<T>(mrb, self)->setDevice(std::string(str)));
}

/* @!class SFML::SoundRecorder<T>
 * @!method get_device
 *   @return [String]
 */
template <class T>
static mrb_value
sound_recorder_get_device(mrb_state *mrb, mrb_value self)
{
  return mrb_str_new_cstr(mrb, get_sound_recorder<T>(mrb, self)->getDevice().c_str());
}

/* @!class SFML::SoundRecorder<T>
 */
template <class T>
static inline void
mrb_sfml_sound_recorder_bind_class(mrb_state *mrb, struct RClass *cls)
{
  mrb_define_method(mrb, cls, "start",           sound_recorder_start<T>,           MRB_ARGS_REQ(1));
  mrb_define_method(mrb, cls, "stop",            sound_recorder_stop<T>,            MRB_ARGS_NONE());
  mrb_define_method(mrb, cls, "get_sample_rate", sound_recorder_get_sample_rate<T>, MRB_ARGS_NONE());
  mrb_define_method(mrb, cls, "set_device",      sound_recorder_set_device<T>,      MRB_ARGS_NONE());
  mrb_define_method(mrb, cls, "get_device",      sound_recorder_get_device<T>,      MRB_ARGS_NONE());

  mrb_define_alias(mrb, cls, "sample_rate", "get_sample_rate");
  mrb_define_alias(mrb, cls, "device=", "set_device");
  mrb_define_alias(mrb, cls, "device", "get_device");
}

#endif
