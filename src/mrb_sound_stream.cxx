#include <mruby.h>
#include <mruby/class.h>
#include <SFML/Audio/SoundStream.hpp>
#include "mrb_sound_stream.hxx"

/* @class SFML::SoundStream
 * @abstract
 */
extern "C" void
mrb_sfml_sound_stream_init_bind(mrb_state *mrb, struct RClass *mod)
{
  mrb_define_class_under(mrb, mod, "SoundStream", mrb_class_get_under(mrb, mod, "SoundSource"));
}
