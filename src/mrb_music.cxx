#include <string>
#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <SFML/Audio/Music.hpp>
#include "mrb/cxx/helpers.hxx"
#include "mrb/sfml/system/time.hxx"
#include "mrb/sfml/system/vector2.hxx"
#include "mrb/sfml/audio/music.hxx"
#include "mrb_music.hxx"
#include "mrb_sound_stream.hxx"

static struct RClass *music_class;
static mrb_data_free_func music_free = cxx_mrb_data_free<sf::Music>;
extern "C" const struct mrb_data_type mrb_sfml_music_type = { "sf::Music", music_free };

/* @!class SFML::Music
 * @!method initialize
 *   @return [self]
 */
static mrb_value
music_initialize(mrb_state *mrb, mrb_value self)
{
  music_free(mrb, DATA_PTR(self));
  mrb_data_init(self, new sf::Music(), &mrb_sfml_music_type);
  return self;
}

/* @!class SFML::Music
 * @!method open_from_file(filename)
 *   @param [String] filename
 *   @return [self]
 */
static mrb_value
music_open_from_file(mrb_state *mrb, mrb_value self)
{
  char *str;
  mrb_get_args(mrb, "z", &str);
  mrb_sfml_music_ptr(mrb, self)->openFromFile(std::string(str));
  return self;
}

/* @!class SFML::Music
 * @!method get_duration
 *   @return [Time]
 *   @return [self]
 */
static mrb_value
music_get_duration(mrb_state *mrb, mrb_value self)
{
  return mrb_sfml_time_value(mrb, mrb_sfml_music_ptr(mrb, self)->getDuration());
}

/* @!class SFML::Music
 */
extern "C" void
mrb_sfml_music_init_bind(mrb_state *mrb, struct RClass *mod)
{
  music_class = mrb_define_class_under(mrb, mod, "Music", mrb_class_get_under(mrb, mod, "SoundStream"));
  MRB_SET_INSTANCE_TT(music_class, MRB_TT_DATA);

  mrb_sfml_sound_stream_bind_class<sf::Music>(mrb, music_class);
  mrb_define_method(mrb, music_class, "initialize",     music_initialize,     MRB_ARGS_NONE());
  mrb_define_method(mrb, music_class, "open_from_file", music_open_from_file, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, music_class, "get_duration",   music_get_duration,   MRB_ARGS_NONE());

  mrb_define_alias(mrb, music_class, "duration", "get_duration");
}
