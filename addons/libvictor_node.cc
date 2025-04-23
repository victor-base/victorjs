#include "libvictor_node.h"

using namespace Napi;

Victor::Victor(const Napi::CallbackInfo& info) : ObjectWrap<Victor>(info) {
    if (info.Length() < 1) {
        this->_data = nullptr;
        return;
    }

    this->_data = info[0].As<Napi::String>().Utf8Value();
}

Napi::Value Victor::Test(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments")
            .ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsString()) {
        Napi::TypeError::New(env, "Expected a string")
            .ThrowAsJavaScriptException();
        return env.Null();
    }

    Napi::String name = info[0].As<Napi::String>();

    printf("Hello %s\n", name.Utf8Value().c_str());
    printf("I am %s\n", this->_data.c_str());

    return Napi::Value();
}

// Napi::Value Victor::Alloc_index(const Napi::CallbackInfo& info) {
//     Napi::Env env = info.Env();

//     return Napi::Value();
// };
// Napi::Value Victor::Load_index(const Napi::CallbackInfo& info) {
//     Napi::Env env = info.Env();

//     return Napi::Value();
// };
Napi::Value Victor::Destroy_index(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    return Napi::Value();
};
Napi::Value Victor::Insert(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    return Napi::Value();
};
Napi::Value Victor::Delete(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    return Napi::Value();
};
Napi::Value Victor::Search(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    return Napi::Value();
};
Napi::Value Victor::Search_n(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    return Napi::Value();
};
Napi::Value Victor::Contains(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    return Napi::Value();
};
Napi::Value Victor::Stats(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    return Napi::Value();
};
Napi::Value Victor::Size(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    return Napi::Value();
};
Napi::Value Victor::Update_context(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    return Napi::Value();
};
Napi::Value Victor::Dump(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    return Napi::Value();
};

Napi::Value Victor::Load(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments")
            .ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsString()) {
        Napi::TypeError::New(env, "Expected a filename")
            .ThrowAsJavaScriptException();
        return env.Null();
    }

    Napi::String filename = info[0].As<Napi::String>();

    return Victor::GetClass(env).New({ filename });
}

Napi::Function Victor::GetClass(Napi::Env env) {
    const char version[] = "libvictor 1.0.0 (x64 Windows) [2023-10-01 12:00:00]"; 
    const char shortVersion[] = "1.0.0";


    return DefineClass(env, "Victor", {
        StaticValue("version", Napi::String::New(env, version)),
        StaticValue("shortVersion", Napi::String::New(env, shortVersion)),

        StaticMethod("load", &Victor::Load),
    
        InstanceMethod("destroyIndex", &Victor::Destroy_index),
        InstanceMethod("insert", &Victor::Insert),
        InstanceMethod("delete", &Victor::Delete),
        InstanceMethod("search", &Victor::Search),
        InstanceMethod("searchN", &Victor::Search_n),
        InstanceMethod("contains", &Victor::Contains),
        InstanceMethod("stats", &Victor::Stats),
        InstanceMethod("size", &Victor::Size),
        InstanceMethod("updateContext", &Victor::Update_context),
        InstanceMethod("dump", &Victor::Dump),

        InstanceMethod("test", &Victor::Test),
    });
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    Napi::String name = Napi::String::New(env, "Victor");
    exports.Set(name, Victor::GetClass(env));
    return exports;
}

NODE_API_MODULE(addon, Init)