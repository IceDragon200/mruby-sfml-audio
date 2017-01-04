#include <mruby.h>
#include <mruby/class.h>
#include <SFML/Audio/SoundSource.hpp>
#include "mrb_sound_source.hxx"

/* @class SFML::SoundSource
 * @abstract
 */
MRB_SFML_EXTERN void
mrb_sfml_sound_source_init_bind(mrb_state *mrb, struct RClass *mod)
{
  struct RClass *sound_source_class = mrb_define_class_under(mrb, mod, "SoundSource", mrb_class_get_under(mrb, mod, "AlResource"));
  struct RClass *sound_source_status_module = mrb_define_module_under(mrb, sound_source_class, "Status");
  mrb_define_const(mrb, sound_source_status_module, "Stopped", mrb_fixnum_value(sf::SoundSource::Status::Stopped));
  mrb_define_const(mrb, sound_source_status_module, "Paused",  mrb_fixnum_value(sf::SoundSource::Status::Paused));
  mrb_define_const(mrb, sound_source_status_module, "Playing", mrb_fixnum_value(sf::SoundSource::Status::Playing));
}
