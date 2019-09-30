#include "functionexample.h"

std::string functionexample::hello(){
  return "Hello World!!!";
}

int functionexample::add(int a, int b){
  return a + b;
}

void functionexample::myfunction(){
  Sleep(2000); //헤더에 Window.h 가 있어서 사용가능해

}

Napi::Number functionexample::myfunctionWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    functionexample::myfunction(); //내가만든함수호출

    char mytempbuffer[255];
    std::cin.getline(mytempbuffer,255);
    std::cout<<"니가입력한것:"<<mytempbuffer<<std::endl;
    return Napi::Number::New(env, true);
}


Napi::String functionexample::HelloWrapped(const Napi::CallbackInfo& info) 
{
  Napi::Env env = info.Env();
  Napi::String returnValue = Napi::String::New(env, functionexample::hello());
  
  return returnValue;
}


Napi::Number functionexample::AddWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    if (info.Length() < 2 || !info[0].IsNumber() || !info[1].IsNumber()) {
        Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
    } 

   Napi::Number first = info[0].As<Napi::Number>();
   Napi::Number second = info[1].As<Napi::Number>();

    int returnValue = functionexample::add(first.Int32Value(), second.Int32Value());
   
    return Napi::Number::New(env, returnValue);
}


Napi::Object functionexample::Init(Napi::Env env, Napi::Object exports) 
{
  exports.Set("myfunction", Napi::Function::New(env, functionexample::myfunctionWrapped));
  exports.Set("hello", Napi::Function::New(env, functionexample::HelloWrapped));
  exports.Set("add", Napi::Function::New(env, functionexample::AddWrapped));
  return exports;
}