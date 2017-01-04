#include <mruby.h>
#include <mruby/class.h>
#include <SFML/Audio/SoundStream.hpp>
#include "mrb_sound_stream.hxx"

/* @class SFML::SoundStream
 * @abstract
 */
MRB_SFML_EXTERN void
mrb_sfml_sound_stream_init_bind(mrb_state *mrb, struct RClass *mod)
{
  mrb_define_class_under(mrb, mod, "SoundStream", mrb_class_get_under(mrb, mod, "SoundSource"));
}
