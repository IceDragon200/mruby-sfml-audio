#include <mruby.h>
#include <mruby/class.h>
#include <mruby/numeric.h>
#include <SFML/Audio/Listener.hpp>
#include "mrb/sfml/system/vector3.hxx"
#include "mrb_listener.hxx"

static struct RClass *listener_module;

static mrb_value
listener_set_global_volume(mrb_state *mrb, mrb_value self)
{
  mrb_float volume;
  mrb_get_args(mrb, "f", &volume);
  sf::Listener::setGlobalVolume(volume);
  return self;
}

static mrb_value
listener_get_global_volume(mrb_state *mrb, mrb_value self)
{
  return mrb_float_value(mrb, sf::Listener::getGlobalVolume());
}

static mrb_value
listener_set_position(mrb_state *mrb, mrb_value self)
{
  mrb_value x;
  mrb_float y, z;
  mrb_int argc = mrb_get_args(mrb, "o|ff", &x, &y, &z);
  if (argc == 1) {
    sf::Listener::setPosition(*mrb_sfml_vector3f_ptr(mrb, x));
  } else if (argc == 3) {
    sf::Listener::setPosition(mrb_to_flo(mrb, x), y, z);
  } else {
    mrb_raise(mrb, E_ARGUMENT_ERROR, "expected 1 or 3 arguments");
  }
  return self;
}

static mrb_value
listener_get_position(mrb_state *mrb, mrb_value self)
{
  return mrb_sfml_vector3f_value(mrb, sf::Listener::getPosition());
}

static mrb_value
listener_set_direction(mrb_state *mrb, mrb_value self)
{
  mrb_value x;
  mrb_float y, z;
  mrb_int argc = mrb_get_args(mrb, "o|ff", &x, &y, &z);
  if (argc == 1) {
    sf::Listener::setDirection(*mrb_sfml_vector3f_ptr(mrb, x));
  } else if (argc == 3) {
    sf::Listener::setDirection(mrb_to_flo(mrb, x), y, z);
  } else {
    mrb_raise(mrb, E_ARGUMENT_ERROR, "expected 1 or 3 arguments");
  }
  return self;
}

static mrb_value
listener_get_direction(mrb_state *mrb, mrb_value self)
{
  return mrb_sfml_vector3f_value(mrb, sf::Listener::getDirection());
}

static mrb_value
listener_set_up_vector(mrb_state *mrb, mrb_value self)
{
  mrb_value x;
  mrb_float y, z;
  mrb_int argc = mrb_get_args(mrb, "o|ff", &x, &y, &z);
  if (argc == 1) {
    sf::Listener::setUpVector(*mrb_sfml_vector3f_ptr(mrb, x));
  } else if (argc == 3) {
    sf::Listener::setUpVector(mrb_to_flo(mrb, x), y, z);
  } else {
    mrb_raise(mrb, E_ARGUMENT_ERROR, "expected 1 or 3 arguments");
  }
  return self;
}

static mrb_value
listener_get_up_vector(mrb_state *mrb, mrb_value self)
{
  return mrb_sfml_vector3f_value(mrb, sf::Listener::getUpVector());
}

extern "C" void
mrb_sfml_listener_init_bind(mrb_state *mrb, struct RClass *mod)
{
  listener_module = mrb_define_module_under(mrb, mod, "Listener");

  mrb_define_class_method(mrb, listener_module, "set_global_volume", listener_set_global_volume, MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb, listener_module, "get_global_volume", listener_get_global_volume, MRB_ARGS_NONE());
  mrb_define_class_method(mrb, listener_module, "set_position",      listener_set_position,      MRB_ARGS_ARG(1,2));
  mrb_define_class_method(mrb, listener_module, "get_position",      listener_get_position,      MRB_ARGS_NONE());
  mrb_define_class_method(mrb, listener_module, "set_direction",     listener_set_direction,     MRB_ARGS_ARG(1,2));
  mrb_define_class_method(mrb, listener_module, "get_direction",     listener_get_direction,     MRB_ARGS_NONE());
  mrb_define_class_method(mrb, listener_module, "set_up_vector",     listener_set_up_vector,     MRB_ARGS_ARG(1,2));
  mrb_define_class_method(mrb, listener_module, "get_up_vector",     listener_get_up_vector,     MRB_ARGS_NONE());
}
