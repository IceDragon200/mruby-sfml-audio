#include <mruby.h>
#include <mruby/class.h>
#include <SFML/Audio.hpp>
#include "mrb_al_resource.hxx"
#include "mrb_sound.hxx"
#include "mrb_sound_buffer.hxx"
#include "mrb_sound_source.hxx"
#include "mrb_sound_stream.hxx"

static struct RClass *sfml_module;

extern "C" void
mrb_mruby_sfml_audio_gem_init(mrb_state *mrb)
{
  sfml_module = mrb_define_module(mrb, "SFML");

  mrb_sfml_al_resource_init_bind(mrb, sfml_module);
  mrb_sfml_sound_source_init_bind(mrb, sfml_module);
  mrb_sfml_sound_stream_init_bind(mrb, sfml_module);
  mrb_sfml_sound_init_bind(mrb, sfml_module);
  mrb_sfml_sound_buffer_init_bind(mrb, sfml_module);
}

extern "C" void
mrb_mruby_sfml_audio_gem_final(mrb_state *mrb)
{
}
