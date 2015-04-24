#include <mruby.h>
#include <mruby/class.h>
//#include <SFML/Audio/AlResource.hpp>
#include "mrb_al_resource.hxx"

/* @!class SFML::AlResource
 * @abstract
 */
extern "C" void
mrb_sfml_al_resource_init_bind(mrb_state *mrb, struct RClass *mod)
{
  mrb_define_class_under(mrb, mod, "AlResource", mrb->object_class);
}
