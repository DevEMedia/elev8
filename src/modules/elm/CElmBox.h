#ifndef C_ELM_BOX_H
#define C_ELM_BOX_H

#include "elm.h"
#include "CElmObject.h"

namespace elm {

using namespace v8;

class CElmBox : public CElmObject {
private:
   static Persistent<FunctionTemplate> tmpl;

protected:
   CElmBox(Local<Object> _jsObject, CElmObject *parent);
   static Handle<FunctionTemplate> GetTemplate();

   static void Delete(Persistent<Value>, void *);

public:
   static void Initialize(Handle<Object> target);

   virtual void DidRealiseElement(Local<Value> obj);

   void horizontal_set(Handle<Value> val);
   virtual Handle<Value> horizontal_get() const;

   void homogeneous_set(Handle<Value> val);
   virtual Handle<Value> homogeneous_get() const;

   friend Handle<Value> CElmObject::New<CElmBox>(const Arguments& args);
};

}

#endif // C_ELM_BOX_H
