#include <mruby.h>
#include <mruby/class.h>
#include <SFML/Audio.hpp>
#include "mrb_al_resource.hxx"
#include "mrb_listener.hxx"
#include "mrb_music.hxx"
#include "mrb_sound.hxx"
#include "mrb_sound_buffer.hxx"
#include "mrb_sound_buffer_recorder.hxx"
#include "mrb_sound_recorder.hxx"
#include "mrb_sound_source.hxx"
#include "mrb_sound_stream.hxx"
#include "mrb/sfml/helpers.hxx"

static struct RClass *sfml_module;

MRB_SFML_EXTERN void
mrb_mruby_sfml_audio_gem_init(mrb_state *mrb)
{
  sfml_module = mrb_define_module(mrb, "SFML");

  mrb_sfml_al_resource_init_bind(mrb, sfml_module);
  mrb_sfml_listener_init_bind(mrb, sfml_module);
  mrb_sfml_sound_source_init_bind(mrb, sfml_module);
  mrb_sfml_sound_stream_init_bind(mrb, sfml_module);
  mrb_sfml_music_init_bind(mrb, sfml_module);
  mrb_sfml_sound_init_bind(mrb, sfml_module);
  mrb_sfml_sound_buffer_init_bind(mrb, sfml_module);
  mrb_sfml_sound_recorder_init_bind(mrb, sfml_module);
  mrb_sfml_sound_buffer_recorder_init_bind(mrb, sfml_module);
}

MRB_SFML_EXTERN void
mrb_mruby_sfml_audio_gem_final(mrb_state *mrb)
{
}
