#include "elm.h"
#include "CElmWindow.h"

namespace elm {

using namespace v8;

GENERATE_PROPERTY_CALLBACKS(CElmWindow, title);
GENERATE_PROPERTY_CALLBACKS(CElmWindow, conformant);
GENERATE_PROPERTY_CALLBACKS(CElmWindow, autodel);
GENERATE_PROPERTY_CALLBACKS(CElmWindow, borderless);
GENERATE_PROPERTY_CALLBACKS(CElmWindow, shaped);
GENERATE_PROPERTY_CALLBACKS(CElmWindow, alpha);
GENERATE_PROPERTY_CALLBACKS(CElmWindow, override);
GENERATE_PROPERTY_CALLBACKS(CElmWindow, fullscreen);
GENERATE_PROPERTY_CALLBACKS(CElmWindow, maximized);
GENERATE_PROPERTY_CALLBACKS(CElmWindow, iconified);
GENERATE_PROPERTY_CALLBACKS(CElmWindow, withdrawn);
GENERATE_PROPERTY_CALLBACKS(CElmWindow, urgent);
GENERATE_PROPERTY_CALLBACKS(CElmWindow, demand_attention);
GENERATE_PROPERTY_CALLBACKS(CElmWindow, modal);
GENERATE_PROPERTY_CALLBACKS(CElmWindow, sticky);
GENERATE_PROPERTY_CALLBACKS(CElmWindow, quickpanel);
GENERATE_PROPERTY_CALLBACKS(CElmWindow, screen_constrain);
GENERATE_PROPERTY_CALLBACKS(CElmWindow, focus_highlight_enabled);
GENERATE_PROPERTY_CALLBACKS(CElmWindow, keyboard_win);
GENERATE_PROPERTY_CALLBACKS(CElmWindow, rotation);

GENERATE_TEMPLATE(CElmWindow,
                  PROPERTY(title),
                  PROPERTY(conformant),
                  PROPERTY(autodel),
                  PROPERTY(borderless),
                  PROPERTY(shaped),
                  PROPERTY(alpha),
                  PROPERTY(override),
                  PROPERTY(fullscreen),
                  PROPERTY(maximized),
                  PROPERTY(iconified),
                  PROPERTY(withdrawn),
                  PROPERTY(urgent),
                  PROPERTY(demand_attention),
                  PROPERTY(modal),
                  PROPERTY(sticky),
                  PROPERTY(quickpanel),
                  PROPERTY(screen_constrain),
                  PROPERTY(focus_highlight_enabled),
                  PROPERTY(keyboard_win),
                  PROPERTY(rotation));

// Getters and Settters

Handle<Value> CElmWindow::title_get() const
{
   const char *s = elm_win_title_get(eo);
   return s ? String::New(s) : Undefined();
}

void CElmWindow::title_set(Handle<Value> val)
{
   if (val->IsString())
     elm_win_title_set(eo, *String::Utf8Value(val));
}

Handle<Value> CElmWindow::conformant_get() const
{
   return Boolean::New(elm_win_conformant_get(eo));
}

void CElmWindow::conformant_set(Handle<Value> val)
{
   if (val->IsBoolean())
     elm_win_conformant_set(eo, val->BooleanValue());
}

Handle<Value> CElmWindow::autodel_get() const
{
   return Boolean::New(elm_win_autodel_get(eo));
}

void CElmWindow::autodel_set(Handle<Value> val)
{
   if (val->IsBoolean())
     elm_win_autodel_set(eo, val->BooleanValue());
}

Handle<Value> CElmWindow::borderless_get() const
{
   return Boolean::New(elm_win_borderless_get(eo));
}

void CElmWindow::borderless_set(Handle<Value> val)
{
   if (val->IsBoolean())
     elm_win_borderless_set(eo, val->BooleanValue());
}

Handle<Value> CElmWindow::shaped_get() const
{
   return Boolean::New(elm_win_shaped_get(eo));
}

void CElmWindow::shaped_set(Handle<Value> val)
{
   if (val->IsBoolean())
     elm_win_shaped_set(eo, val->BooleanValue());
}

Handle<Value> CElmWindow::alpha_get() const
{
   return Boolean::New(elm_win_alpha_get(eo));
}

void CElmWindow::alpha_set(Handle<Value> val)
{
   if (val->IsBoolean())
     elm_win_alpha_set(eo, val->BooleanValue());
}

Handle<Value> CElmWindow::override_get() const
{
   return Boolean::New(elm_win_override_get(eo));
}

void CElmWindow::override_set(Handle<Value> val)
{
   if (val->IsBoolean())
     elm_win_override_set(eo, val->BooleanValue());
}

Handle<Value> CElmWindow::fullscreen_get() const
{
   return Boolean::New(elm_win_fullscreen_get(eo));
}

void CElmWindow::fullscreen_set(Handle<Value> val)
{
   if (val->IsBoolean())
     elm_win_fullscreen_set(eo, val->BooleanValue());
}

Handle<Value> CElmWindow::maximized_get() const
{
   return Boolean::New(elm_win_maximized_get(eo));
}

void CElmWindow::maximized_set(Handle<Value> val)
{
   if (val->IsBoolean())
     elm_win_maximized_set(eo, val->BooleanValue());
}

Handle<Value> CElmWindow::iconified_get() const
{
   return Boolean::New(elm_win_iconified_get(eo));
}

void CElmWindow::iconified_set(Handle<Value> val)
{
   if (val->IsBoolean())
     elm_win_iconified_set(eo, val->BooleanValue());
}

Handle<Value> CElmWindow::withdrawn_get() const
{
   return Boolean::New(elm_win_withdrawn_get(eo));
}

void CElmWindow::withdrawn_set(Handle<Value> val)
{
   if (val->IsBoolean())
     elm_win_withdrawn_set(eo, val->BooleanValue());
}

Handle<Value> CElmWindow::urgent_get() const
{
   return Boolean::New(elm_win_urgent_get(eo));
}

void CElmWindow::urgent_set(Handle<Value> val)
{
   if (val->IsBoolean())
     elm_win_urgent_set(eo, val->BooleanValue());
}

Handle<Value> CElmWindow::demand_attention_get() const
{
   return Boolean::New(elm_win_demand_attention_get(eo));
}

void CElmWindow::demand_attention_set(Handle<Value> val)
{
   if (val->IsBoolean())
     elm_win_demand_attention_set(eo, val->BooleanValue());
}

Handle<Value> CElmWindow::modal_get() const
{
   return Boolean::New(elm_win_modal_get(eo));
}

void CElmWindow::modal_set(Handle<Value> val)
{
   if (val->IsBoolean())
     elm_win_modal_set(eo, val->BooleanValue());
}

Handle<Value> CElmWindow::sticky_get() const
{
   return Boolean::New(elm_win_sticky_get(eo));
}

void CElmWindow::sticky_set(Handle<Value> val)
{
   if (val->IsBoolean())
     elm_win_sticky_set(eo, val->BooleanValue());
}

Handle<Value> CElmWindow::quickpanel_get() const
{
   return Boolean::New(elm_win_quickpanel_get(eo));
}

void CElmWindow::quickpanel_set(Handle<Value> val)
{
   if (val->IsBoolean())
     elm_win_quickpanel_set(eo, val->BooleanValue());
}

Handle<Value> CElmWindow::screen_constrain_get() const
{
   return Boolean::New(elm_win_screen_constrain_get(eo));
}

void CElmWindow::screen_constrain_set(Handle<Value> val)
{
   if (val->IsBoolean())
     elm_win_screen_constrain_set(eo, val->BooleanValue());
}

Handle<Value> CElmWindow::focus_highlight_enabled_get() const
{
   return Boolean::New(elm_win_focus_highlight_enabled_get(eo));
}

void CElmWindow::focus_highlight_enabled_set(Handle<Value> val)
{
   if (val->IsBoolean())
     elm_win_focus_highlight_enabled_set(eo, val->BooleanValue());
}

Handle<Value> CElmWindow::keyboard_win_get() const
{
   return Boolean::New(elm_win_keyboard_win_get(eo));
}

void CElmWindow::keyboard_win_set(Handle<Value> val)
{
   if (val->IsBoolean())
     elm_win_keyboard_win_set(eo, val->BooleanValue());
}

Handle<Value> CElmWindow::rotation_get() const
{
   return Integer::New(elm_win_rotation_get(eo));
}

void CElmWindow::rotation_set(Handle <Value> val)
{
   if (val->IsInt32())
     elm_win_rotation_set(eo, val->ToInt32()->Value());
}

void CElmWindow::rotation_with_resize_set(Handle <Value> val)
{
   if (val->IsInt32())
     elm_win_rotation_with_resize_set(eo, val->ToInt32()->Value());
}

//---------------------

CElmWindow::CElmWindow(Local<Object> _jsObject, CElmObject *parent)
   : CElmObject(_jsObject, elm_win_add(parent ? parent->GetEvasObject() : NULL, "main", ELM_WIN_BASIC))
{
   evas_object_focus_set(eo, 1);
   evas_object_smart_callback_add(eo, "delete,request", &quit, NULL);
   evas_object_show(eo);
}

void CElmWindow::Initialize(Handle<Object> target)
{
   target->Set(String::NewSymbol("Window"), GetTemplate()->GetFunction());
}

void CElmWindow::quit(void *, Evas_Object *, void *)
{
   //TODO: check if his window has parent
   ecore_main_loop_quit();
}

}
