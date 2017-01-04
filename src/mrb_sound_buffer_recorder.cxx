#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <SFML/Audio/SoundBufferRecorder.hpp>
#include "mrb/cxx/helpers.hxx"
#include "mrb/sfml/audio/sound_buffer.hxx"
#include "mrb/sfml/audio/sound_buffer_recorder.hxx"
#include "mrb_sound_recorder.hxx"
#include "mrb_sound_buffer_recorder.hxx"

static struct RClass *sound_buffer_recorder_class;
static mrb_data_free_func sound_buffer_recorder_free = cxx_mrb_data_free<sf::SoundBufferRecorder>;
MRB_SFML_EXTERN const struct mrb_data_type mrb_sfml_sound_buffer_recorder_type = { "sf::SoundBufferRecorder", sound_buffer_recorder_free };

/* @!class SFML::SoundBufferRecorder
 * @!method initialize
 *   @return [self]
 */
static mrb_value
sound_buffer_recorder_initialize(mrb_state *mrb, mrb_value self)
{
  sound_buffer_recorder_free(mrb, DATA_PTR(self));
  mrb_data_init(self, new sf::SoundBufferRecorder(), &mrb_sfml_sound_buffer_recorder_type);
  return self;
}

/* @!class SFML::SoundBufferRecorder
 * @!method get_buffer
 *   @return [SFML::SoundBuffer]
 */
static mrb_value
sound_buffer_recorder_get_buffer(mrb_state *mrb, mrb_value self)
{
  return mrb_sfml_sound_buffer_value(mrb, mrb_sfml_sound_buffer_recorder_ptr(mrb, self)->getBuffer());
}

/* @!class SFML::SoundBufferRecorder
 */
MRB_SFML_EXTERN void
mrb_sfml_sound_buffer_recorder_init_bind(mrb_state *mrb, struct RClass *mod)
{
  sound_buffer_recorder_class = mrb_define_class_under(mrb, mod, "SoundBufferRecorder", mrb_class_get_under(mrb, mod, "SoundRecorder"));
  MRB_SET_INSTANCE_TT(sound_buffer_recorder_class, MRB_TT_DATA);

  mrb_sfml_sound_recorder_bind_class<sf::SoundBufferRecorder>(mrb, sound_buffer_recorder_class);
  mrb_define_method(mrb, sound_buffer_recorder_class, "initialize", sound_buffer_recorder_initialize, MRB_ARGS_NONE());
  mrb_define_method(mrb, sound_buffer_recorder_class, "get_buffer", sound_buffer_recorder_get_buffer, MRB_ARGS_NONE());

  mrb_define_alias(mrb, sound_buffer_recorder_class, "buffer", "get_buffer");
}
