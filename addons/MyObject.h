#pragma once

#include <napi.h>

class Victor : public Napi::ObjectWrap<Victor> {
    public:
        Victor(const Napi::CallbackInfo& info);

        Napi::Value Test(const Napi::CallbackInfo& info);

        Napi::Value Destroy_index(const Napi::CallbackInfo& info);

        Napi::Value Insert(const Napi::CallbackInfo& info);
        Napi::Value Delete(const Napi::CallbackInfo& info);

        Napi::Value Search(const Napi::CallbackInfo& info);
        Napi::Value Search_n(const Napi::CallbackInfo& info);

        Napi::Value Contains(const Napi::CallbackInfo& info);

        Napi::Value Stats(const Napi::CallbackInfo& info);
        Napi::Value Size(const Napi::CallbackInfo& info);

        Napi::Value Update_context(const Napi::CallbackInfo& info);

        Napi::Value Dump(const Napi::CallbackInfo& info);

        static Napi::Value Load(const Napi::CallbackInfo& info);

        static Napi::Function GetClass(Napi::Env env);

    private:
        std::string _data;
};