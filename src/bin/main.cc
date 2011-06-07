/*
 * elev8 - javascript for EFL
 *
 * The script's job is to prepare for the main loop to run
 * then exit
 */

#include "main.h"

#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>

Evas_Object *main_win;

void button_on_click(void *data, Evas *e, Evas_Object *obj, void *event_info)
{
  v8::Persistent<v8::Function> fn(static_cast<v8::Function*>(data));
  v8::Handle<v8::Value> args[] = { v8::String::New("arg") };
  v8::Local<v8::Value> result = fn->Call(fn, 1, args);
}

v8::Handle<v8::Value> Realize(const v8::Arguments& args) {
   if (args.Length() != 1)
      return v8::ThrowException(v8::String::New("Bad parameters"));

   v8::Local<v8::Object> obj = v8::Local<v8::Object>::Cast(args[0]);
   v8::Local<v8::Value> label_val = obj->Get(v8::String::New("label"));
   v8::Local<v8::Value> width_val = obj->Get(v8::String::New("width"));
   v8::Local<v8::Value> height_val = obj->Get(v8::String::New("height"));
   v8::Local<v8::Function> on_clicked_local = v8::Local<v8::Function>::Cast(obj->Get(v8::String::New("on_clicked")));
   v8::Persistent<v8::Function> clicked_val = v8::Persistent<v8::Function>::New(on_clicked_local);
   v8::Local<v8::Value> x_val = obj->Get(v8::String::New("x"));
   v8::Local<v8::Value> y_val = obj->Get(v8::String::New("y"));
   v8::String::Utf8Value str(label_val);

   Evas_Object *button = elm_button_add(main_win);
   evas_object_resize(button, width_val->ToInteger()->Value(), height_val->ToInteger()->Value());
   evas_object_move(button, x_val->ToInteger()->Value(), y_val->ToInteger()->Value());
   evas_object_event_callback_add(button, EVAS_CALLBACK_MOUSE_DOWN, &button_on_click, static_cast<void*>(*clicked_val));

   elm_button_label_set(button, *str);
   evas_object_show(button);
   return v8::Undefined();
}


v8::Handle<v8::String> string_from_file(const char *filename)
{
   v8::Handle<v8::String> ret = v8::Handle<v8::String>();
   int fd, len;
   void *bad_ret = reinterpret_cast<void*>(-1);
   void *p = bad_ret;

   fd = open(filename, O_RDONLY);
   if (fd < 0)
      goto fail;

   len = lseek(fd, 0, SEEK_END);
   if (len <= 0)
      goto fail;

   p = mmap(NULL, len, PROT_READ, MAP_PRIVATE, fd, 0);
   if (p == bad_ret)
      goto fail;

   ret = v8::String::New(reinterpret_cast<char*>(p), len);

fail:
   if (p == bad_ret)
      munmap(p, len);

   if (fd >= 0)
      close(fd);

   return ret;
}

void
run_script(const char *filename)
{
   v8::HandleScope handle_scope;
   v8::TryCatch try_catch;

   /* load the script and run it */
   v8::Handle<v8::String> origin = v8::String::New(filename);
   v8::Handle<v8::String> source = string_from_file(filename);
   if (source.IsEmpty())
     {
        fprintf(stderr, "Failed to read source %s\n", filename);
        return;
     }

   v8::Handle<v8::Script> script = v8::Script::Compile(source, origin);
   if (script.IsEmpty())
      fprintf(stderr, "compile failed\n");
   v8::Handle<v8::Value> result = script->Run();
}

static void
es_window_delete(void *data, Evas_Object *obj, void *event_info)
{
   elm_exit();
}

void
elev8_run(const char *script)
{
   v8::HandleScope handle_scope;
   v8::Handle<v8::ObjectTemplate> global = v8::ObjectTemplate::New();

   global->Set(v8::String::New("realize"), v8::FunctionTemplate::New(Realize));

   /* create an empty window first */
   main_win = elm_win_add(NULL, "main", ELM_WIN_BASIC);
   elm_win_title_set(main_win, basename(script));
   evas_object_focus_set(main_win, 1);
   evas_object_smart_callback_add(main_win, "delete,request", es_window_delete, NULL);
   evas_object_resize(main_win, 320, 480);
   Evas_Object *bg = elm_bg_add(main_win);
   elm_win_resize_object_add(main_win, bg);
   evas_object_show(bg);

   /* setup V8 */
   v8::Persistent<v8::Context> context = v8::Context::New(NULL, global);
   v8::Context::Scope context_scope(context);
   run_script(script);

   evas_object_show(main_win);
   elm_run();

   context.Dispose();
}

int
elm_main(int argc, char **argv)
{
   v8::V8::SetFlagsFromCommandLine(&argc, argv, true);
   elev8_run(argv[1]);
   v8::V8::Dispose();

   return 0;
}

ELM_MAIN()
