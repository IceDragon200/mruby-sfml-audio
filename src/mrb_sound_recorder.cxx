#include <string>
#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <mruby/string.h>
#include <SFML/Audio/SoundRecorder.hpp>
#include "mrb/cxx/helpers.hxx"
#include "mrb_sound_recorder.hxx"

static struct RClass *sound_recorder_class;
static mrb_data_free_func sound_recorder_free = cxx_mrb_data_free<sf::SoundRecorder>;
extern "C" const struct mrb_data_type mrb_sfml_sound_recorder_type = { "sf::SoundRecorder", sound_recorder_free };

/* @!class SFML::SoundRecorder
 * @!class-method get_available_devices
 *   @return [Array<String>]
 */
static mrb_value
sound_recorder_s_get_available_devices(mrb_state *mrb, mrb_value klass)
{
  return cxx_mrb_ary_new_vector<std::string>(mrb, sf::SoundRecorder::getAvailableDevices());
}

/* @!class SFML::SoundRecorder
 * @!class-method get_default_device
 *   @return [String]
 */
static mrb_value
sound_recorder_s_get_default_device(mrb_state *mrb, mrb_value klass)
{
  return mrb_str_new_cstr(mrb, sf::SoundRecorder::getDefaultDevice().c_str());
}

/* @!class SFML::SoundRecorder
 * @abstract
 */
extern "C" void
mrb_sfml_sound_recorder_init_bind(mrb_state *mrb, struct RClass *mod)
{
  sound_recorder_class = mrb_define_class_under(mrb, mod, "SoundRecorder", mrb_class_get_under(mrb, mod, "AlResource"));

  mrb_define_class_method(mrb, sound_recorder_class, "get_available_devices", sound_recorder_s_get_available_devices, MRB_ARGS_NONE());
  mrb_define_class_method(mrb, sound_recorder_class, "get_default_device", sound_recorder_s_get_default_device, MRB_ARGS_NONE());
}
