#include <napi.h>
#include <Windows.h>
#include<iostream>
namespace functionexample {
  std::string hello();
  int add(int a, int b);
  void myfunction();
  Napi::Number myfunctionWrapped(const Napi::CallbackInfo& info);
  Napi::String HelloWrapped(const Napi::CallbackInfo& info);
  Napi::Number AddWrapped(const Napi::CallbackInfo& info);
  Napi::Object Init(Napi::Env env, Napi::Object exports);

}