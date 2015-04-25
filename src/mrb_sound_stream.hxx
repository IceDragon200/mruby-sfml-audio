#ifndef MRB_SFML_SOUND_STREAM_PRIV_H
#define MRB_SFML_SOUND_STREAM_PRIV_H

#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <mruby/numeric.h>
#include <SFML/Audio/SoundStream.hpp>
#include "mrb/cxx/helpers.hxx"
#include "mrb/sfml/system/time.hxx"
#include "mrb_sound_source.hxx"

extern "C" void mrb_sfml_sound_stream_init_bind(mrb_state *mrb, struct RClass *mod);

template <class T>
static inline T*
get_sound_stream(mrb_state *mrb, mrb_value self)
{
  return cxx_mrb_data_get_ptr<T>(mrb, self);
}

/* @!class SFML::SoundStream<T>
 * @!method play
 *   @return [self]
 */
template <class T>
static mrb_value
sound_stream_play(mrb_state *mrb, mrb_value self)
{
  get_sound_stream<T>(mrb, self)->play();
  return self;
}

/* @!class SFML::SoundStream<T>
 * @!method pause
 *   @return [self]
 */
template <class T>
static mrb_value
sound_stream_pause(mrb_state *mrb, mrb_value self)
{
  get_sound_stream<T>(mrb, self)->pause();
  return self;
}

/* @!class SFML::SoundStream<T>
 * @!method stop
 *   @return [self]
 */
template <class T>
static mrb_value
sound_stream_stop(mrb_state *mrb, mrb_value self)
{
  get_sound_stream<T>(mrb, self)->stop();
  return self;
}

/* @!class SFML::SoundStream<T>
 * @!method get_channel_count
 *   @return [Integer]
 */
template <class T>
static mrb_value
sound_stream_get_channel_count(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(get_sound_stream<T>(mrb, self)->getChannelCount());
}

/* @!class SFML::SoundStream<T>
 * @!method get_sample_rate
 *   @return [Integer]
 */
template <class T>
static mrb_value
sound_stream_get_sample_rate(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(get_sound_stream<T>(mrb, self)->getSampleRate());
}

/* @!class SFML::SoundStream<T>
 * @!method get_status
 *   @return [SFML::SoundSource::Status]
 */
template <class T>
static mrb_value
sound_stream_get_status(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(get_sound_stream<T>(mrb, self)->getStatus());
}

/* @!class SFML::SoundStream<T>
 * @!method set_playing_offset(time)
 *   @param [SFML::Time] time
 *   @return [self]
 */
template <class T>
static mrb_value
sound_stream_set_playing_offset(mrb_state *mrb, mrb_value self)
{
  sf::Time *tme;
  mrb_get_args(mrb, "d", &tme, &mrb_sfml_time_type);
  get_sound_stream<T>(mrb, self)->setPlayingOffset(*tme);
  return self;
}

/* @!class SFML::SoundStream<T>
 * @!method get_playing_offset
 *   @return [SFML::Time]
 */
template <class T>
static mrb_value
sound_stream_get_playing_offset(mrb_state *mrb, mrb_value self)
{
  return mrb_sfml_time_value(mrb, get_sound_stream<T>(mrb, self)->getPlayingOffset());
}

/* @!class SFML::SoundStream<T>
 * @!method set_loop(bool)
 *   @param [Boolean] bool
 *   @return [self]
 */
template <class T>
static mrb_value
sound_stream_set_loop(mrb_state *mrb, mrb_value self)
{
  mrb_bool luup;
  mrb_get_args(mrb, "b", &luup);
  get_sound_stream<T>(mrb, self)->setLoop(luup);
  return self;
}

/* @!class SFML::SoundStream<T>
 * @!method get_loop
 *   @return [Boolean]
 */
template <class T>
static mrb_value
sound_stream_get_loop(mrb_state *mrb, mrb_value self)
{
  return mrb_bool_value(get_sound_stream<T>(mrb, self)->getLoop());
}

/* @!class SFML::SoundStream<T>
 */
template <class T>
static inline void
mrb_sfml_sound_stream_bind_class(mrb_state *mrb, struct RClass *cls)
{
  mrb_sfml_sound_source_bind_class<T>(mrb, cls);
  mrb_define_method(mrb, cls, "play",  sound_stream_play<T>,  MRB_ARGS_NONE());
  mrb_define_method(mrb, cls, "pause", sound_stream_pause<T>, MRB_ARGS_NONE());
  mrb_define_method(mrb, cls, "stop",  sound_stream_stop<T>,  MRB_ARGS_NONE());
  mrb_define_method(mrb, cls, "get_channel_count", sound_stream_get_channel_count<T>, MRB_ARGS_NONE());
  mrb_define_method(mrb, cls, "get_sample_rate", sound_stream_get_sample_rate<T>, MRB_ARGS_NONE());
  mrb_define_method(mrb, cls, "get_status", sound_stream_get_status<T>, MRB_ARGS_NONE());
  mrb_define_method(mrb, cls, "set_playing_offset", sound_stream_set_playing_offset<T>, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, cls, "get_playing_offset", sound_stream_get_playing_offset<T>, MRB_ARGS_NONE());
  mrb_define_method(mrb, cls, "set_loop", sound_stream_set_loop<T>, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, cls, "get_loop", sound_stream_get_loop<T>, MRB_ARGS_NONE());

  mrb_define_alias(mrb, cls, "channel_count", "get_channel_count");
  mrb_define_alias(mrb, cls, "sample_rate", "get_sample_rate");
  mrb_define_alias(mrb, cls, "status", "get_status");
  mrb_define_alias(mrb, cls, "playing_offset=", "set_playing_offset");
  mrb_define_alias(mrb, cls, "playing_offset", "get_playing_offset");
  mrb_define_alias(mrb, cls, "loop=", "set_loop");
  mrb_define_alias(mrb, cls, "loop?", "get_loop");
}

#endif
