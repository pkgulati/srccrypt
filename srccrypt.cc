#include <nan.h>
#include <v8.h>

void Method(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.Length() != 1)
    {
        info.GetIsolate()->ThrowException(
            v8::String::NewFromUtf8(info.GetIsolate(), "Bad parameters"));
        return;
    }

    //v8::String::Utf8Value param1(info[0]->ToString());
    //v8::Local<v8::String> param1 = info[0]->ToString();

    v8::Isolate* isolate = info.GetIsolate();
    v8::String::Utf8Value s(info[0]);
    std::string str(*s);
    std::reverse(str.begin(), str.end());    

    v8::Local<v8::String> retval = v8::String::NewFromUtf8(isolate, str.c_str());

    info.GetReturnValue().Set(retval);
}

void Init(v8::Local<v8::Object> exports) {
  exports->Set(Nan::New("decrypt").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(Method)->GetFunction());
}

NODE_MODULE(srcrypt, Init)
