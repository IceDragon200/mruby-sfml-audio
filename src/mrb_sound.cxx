#include <string>
#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <mruby/variable.h>
#include <SFML/Audio/Sound.hpp>
#include "mrb/cxx/helpers.hxx"
#include "mrb/sfml/system/time.hxx"
#include "mrb/sfml/system/vector2.hxx"
#include "mrb/sfml/audio/sound.hxx"
#include "mrb/sfml/audio/sound_buffer.hxx"
#include "mrb_sound.hxx"
#include "mrb_sound_source.hxx"

static struct RClass *sound_class;
static mrb_data_free_func sound_free = cxx_mrb_data_free<sf::Sound>;
extern "C" const struct mrb_data_type mrb_sfml_sound_type = { "sf::Sound", sound_free };

static mrb_value
sound_initialize(mrb_state *mrb, mrb_value self)
{
  sf::Sound *sound;
  mrb_value obj;
  mrb_int argc = mrb_get_args(mrb, "|o", &obj);
  if (argc == 0) {
    sound = new sf::Sound();
  } else if (argc == 1) {
    cxx_mrb_ensure_type_data(mrb, obj);
    if (DATA_TYPE(obj) == &mrb_sfml_sound_type) {
      sound = new sf::Sound(*mrb_sfml_sound_ptr(mrb, obj));
    } else if (DATA_TYPE(obj) == &mrb_sfml_sound_buffer_type) {
      sound = new sf::Sound(*mrb_sfml_sound_buffer_ptr(mrb, obj));
    } else {
      mrb_raise(mrb, E_TYPE_ERROR, "expected SFML::Sound or SFML::SoundBuffer.");
      return mrb_nil_value();
    }
  } else {
    mrb_raise(mrb, E_ARGUMENT_ERROR, "expected 0 or 1 arguments.");
    return mrb_nil_value();
  }
  sound_free(mrb, DATA_PTR(self));
  mrb_data_init(self, sound, &mrb_sfml_sound_type);
  return self;
}

static mrb_value
sound_play(mrb_state *mrb, mrb_value self)
{
  mrb_sfml_sound_ptr(mrb, self)->play();
  return self;
}

static mrb_value
sound_pause(mrb_state *mrb, mrb_value self)
{
  mrb_sfml_sound_ptr(mrb, self)->pause();
  return self;
}

static mrb_value
sound_stop(mrb_state *mrb, mrb_value self)
{
  mrb_sfml_sound_ptr(mrb, self)->stop();
  return self;
}

static mrb_value
sound_set_buffer(mrb_state *mrb, mrb_value self)
{
  mrb_value buffer_obj;
  mrb_get_args(mrb, "o", &buffer_obj);
  mrb_sfml_sound_ptr(mrb, self)->setBuffer(*mrb_sfml_sound_buffer_ptr(mrb, buffer_obj));
  mrb_iv_set(mrb, self, mrb_intern_lit(mrb, "__sfml_sound_buffer"), buffer_obj);
  return self;
}

static mrb_value
sound_set_loop(mrb_state *mrb, mrb_value self)
{
  mrb_bool luup;
  mrb_get_args(mrb, "b", &luup);
  mrb_sfml_sound_ptr(mrb, self)->setLoop(luup);
  return self;
}

static mrb_value
sound_set_playing_offset(mrb_state *mrb, mrb_value self)
{
  sf::Time *tme;
  mrb_get_args(mrb, "d", &tme, &mrb_sfml_time_type);
  mrb_sfml_sound_ptr(mrb, self)->setPlayingOffset(*tme);
  return self;
}

static mrb_value
sound_get_buffer(mrb_state *mrb, mrb_value self)
{
  return mrb_iv_get(mrb, self, mrb_intern_lit(mrb, "__sfml_sound_buffer"));
}

static mrb_value
sound_get_loop(mrb_state *mrb, mrb_value self)
{
  return mrb_bool_value(mrb_sfml_sound_ptr(mrb, self)->getLoop());
}

static mrb_value
sound_get_playing_offset(mrb_state *mrb, mrb_value self)
{
  return mrb_sfml_time_value(mrb, mrb_sfml_sound_ptr(mrb, self)->getPlayingOffset());
}

static mrb_value
sound_get_status(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(mrb_sfml_sound_ptr(mrb, self)->getStatus());
}

static mrb_value
sound_reset_buffer(mrb_state *mrb, mrb_value self)
{
  mrb_sfml_sound_ptr(mrb, self)->resetBuffer();
  return self;
}

extern "C" void
mrb_sfml_sound_init_bind(mrb_state *mrb, struct RClass *mod)
{
  sound_class = mrb_define_class_under(mrb, mod, "Sound", mrb_class_get_under(mrb, mod, "SoundSource"));
  MRB_SET_INSTANCE_TT(sound_class, MRB_TT_DATA);

  mrb_sfml_sound_source_bind_class<sf::Sound>(mrb, sound_class);
  mrb_define_method(mrb, sound_class, "initialize",         sound_initialize,         MRB_ARGS_OPT(1));
  mrb_define_method(mrb, sound_class, "play",               sound_play,               MRB_ARGS_NONE());
  mrb_define_method(mrb, sound_class, "pause",              sound_pause,              MRB_ARGS_NONE());
  mrb_define_method(mrb, sound_class, "stop",               sound_stop,               MRB_ARGS_NONE());
  mrb_define_method(mrb, sound_class, "set_buffer",         sound_set_buffer,         MRB_ARGS_REQ(1));
  mrb_define_method(mrb, sound_class, "set_loop",           sound_set_loop,           MRB_ARGS_REQ(1));
  mrb_define_method(mrb, sound_class, "set_playing_offset", sound_set_playing_offset, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, sound_class, "get_buffer",         sound_get_buffer,         MRB_ARGS_NONE());
  mrb_define_method(mrb, sound_class, "get_loop",           sound_get_loop,           MRB_ARGS_NONE());
  mrb_define_method(mrb, sound_class, "get_playing_offset", sound_get_playing_offset, MRB_ARGS_NONE());
  mrb_define_method(mrb, sound_class, "get_status",         sound_get_status,         MRB_ARGS_NONE());
  mrb_define_method(mrb, sound_class, "reset_buffer",       sound_reset_buffer,       MRB_ARGS_NONE());

  mrb_define_alias(mrb, sound_class, "loop=", "set_loop");
  mrb_define_alias(mrb, sound_class, "loop?", "get_loop");
}
