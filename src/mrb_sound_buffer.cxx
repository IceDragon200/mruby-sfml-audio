#include <string>
#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <mruby/variable.h>
#include <SFML/Audio/SoundBuffer.hpp>
#include "mrb/cxx/helpers.hxx"
#include "mrb/sfml/audio/sound_buffer.hxx"
#include "mrb/sfml/system/time.hxx"
#include "mrb_sound_buffer.hxx"

static struct RClass *sound_buffer_class;
static mrb_data_free_func sound_buffer_free = cxx_mrb_data_free<sf::SoundBuffer>;
extern "C" const struct mrb_data_type mrb_sfml_sound_buffer_type = { "sf::SoundBuffer", sound_buffer_free };

static mrb_value
sound_buffer_initialize(mrb_state *mrb, mrb_value self)
{
  sf::SoundBuffer *sound_buffer;
  sf::SoundBuffer *src = NULL;
  mrb_get_args(mrb, "|d", &src, &mrb_sfml_sound_buffer_type);
  if (src) {
    sound_buffer = new sf::SoundBuffer(*src);
  } else {
    sound_buffer = new sf::SoundBuffer();
  }
  mrb_data_init(self, sound_buffer, &mrb_sfml_sound_buffer_type);
  return self;
}

static mrb_value
sound_buffer_load_from_file(mrb_state *mrb, mrb_value self)
{
  char *str;
  mrb_get_args(mrb, "z", &str);
  mrb_sfml_sound_buffer_ptr(mrb, self)->loadFromFile(std::string(str));
  return self;
}

static mrb_value
sound_buffer_save_to_file(mrb_state *mrb, mrb_value self)
{
  char *str;
  mrb_get_args(mrb, "z", &str);
  mrb_sfml_sound_buffer_ptr(mrb, self)->saveToFile(std::string(str));
  return self;
}

static mrb_value
sound_buffer_get_sample_count(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(mrb_sfml_sound_buffer_ptr(mrb, self)->getSampleCount());
}

static mrb_value
sound_buffer_get_sample_rate(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(mrb_sfml_sound_buffer_ptr(mrb, self)->getSampleRate());
}

static mrb_value
sound_buffer_get_channel_count(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(mrb_sfml_sound_buffer_ptr(mrb, self)->getChannelCount());
}

static mrb_value
sound_buffer_get_duration(mrb_state *mrb, mrb_value self)
{
  return mrb_sfml_time_value(mrb, mrb_sfml_sound_buffer_ptr(mrb, self)->getDuration());
}

extern "C" void
mrb_sfml_sound_buffer_init_bind(mrb_state *mrb, struct RClass *mod)
{
  sound_buffer_class = mrb_define_class_under(mrb, mod, "SoundBuffer", mrb_class_get_under(mrb, mod, "AlResource"));
  MRB_SET_INSTANCE_TT(sound_buffer_class, MRB_TT_DATA);

  mrb_define_method(mrb, sound_buffer_class, "initialize",        sound_buffer_initialize,        MRB_ARGS_OPT(1));
  mrb_define_method(mrb, sound_buffer_class, "load_from_file",    sound_buffer_load_from_file,    MRB_ARGS_REQ(1));
  mrb_define_method(mrb, sound_buffer_class, "save_to_file",      sound_buffer_save_to_file,      MRB_ARGS_REQ(1));
  mrb_define_method(mrb, sound_buffer_class, "get_sample_count",  sound_buffer_get_sample_count,  MRB_ARGS_NONE());
  mrb_define_method(mrb, sound_buffer_class, "get_sample_rate",   sound_buffer_get_sample_rate,   MRB_ARGS_NONE());
  mrb_define_method(mrb, sound_buffer_class, "get_channel_count", sound_buffer_get_channel_count, MRB_ARGS_NONE());
  mrb_define_method(mrb, sound_buffer_class, "get_duration",      sound_buffer_get_duration,      MRB_ARGS_NONE());

  mrb_define_alias(mrb, sound_buffer_class, "sample_count", "get_sample_count");
  mrb_define_alias(mrb, sound_buffer_class, "sample_rate", "get_sample_rate");
  mrb_define_alias(mrb, sound_buffer_class, "channel_count", "get_channel_count");
  mrb_define_alias(mrb, sound_buffer_class, "duration", "get_duration");
}
