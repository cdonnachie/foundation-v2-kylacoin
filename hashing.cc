#include <node.h>
#include <node_buffer.h>
#include <v8.h>
#include <stdint.h>
#include <iostream>
#include "nan.h"

// Main Imports
#include "algorithms/flex/flex.h"
#include "algorithms/sha3d/sha3d.h"
#include "algorithms/sha256d/sha256d.h"

using namespace node;
using namespace v8;

#define THROW_ERROR_EXCEPTION(x) Nan::ThrowError(x)
const char* ToCString(const Nan::Utf8String& value) {
  return *value ? *value : "<string conversion failed>";
}

// Flex Algorithm
NAN_METHOD(flex) {

  // Check Arguments for Errors
  if (info.Length() < 1)
    return THROW_ERROR_EXCEPTION("You must provide one argument.");

  // Process/Define Passed Parameters
  char * input = Buffer::Data(Nan::To<v8::Object>(info[0]).ToLocalChecked());
  uint32_t input_len = Buffer::Length(Nan::To<v8::Object>(info[0]).ToLocalChecked());
  char output[32];

  // Hash Input Data and Return Output
  flex_hash(input, output, input_len);
  info.GetReturnValue().Set(Nan::CopyBuffer(output, 32).ToLocalChecked());
}

// Flex Algorithm
NAN_METHOD(sha3d) {

  // Check Arguments for Errors
  if (info.Length() < 1)
    return THROW_ERROR_EXCEPTION("You must provide one argument.");

  // Process/Define Passed Parameters
  char * input = Buffer::Data(Nan::To<v8::Object>(info[0]).ToLocalChecked());
  uint32_t input_len = Buffer::Length(Nan::To<v8::Object>(info[0]).ToLocalChecked());
  char output[32];

  // Hash Input Data and Return Output
  sha3d_hash(input, output, input_len);
  info.GetReturnValue().Set(Nan::CopyBuffer(output, 32).ToLocalChecked());
}

// Sha256d Algorithm
NAN_METHOD(sha256d) {

  // Check Arguments for Errors
  if (info.Length() < 1)
    return THROW_ERROR_EXCEPTION("You must provide one argument.");

  // Process/Define Passed Parameters
  char * input = Buffer::Data(Nan::To<v8::Object>(info[0]).ToLocalChecked());
  uint32_t input_len = Buffer::Length(Nan::To<v8::Object>(info[0]).ToLocalChecked());
  char output[32];

  // Hash Input Data and Return Output
  sha256d_hash(input, output, input_len);
  info.GetReturnValue().Set(Nan::CopyBuffer(output, 32).ToLocalChecked());
}

NAN_MODULE_INIT(init) {
  Nan::Set(target, Nan::New("flex").ToLocalChecked(), Nan::GetFunction(Nan::New<FunctionTemplate>(flex)).ToLocalChecked());
  Nan::Set(target, Nan::New("sha3d").ToLocalChecked(), Nan::GetFunction(Nan::New<FunctionTemplate>(sha3d)).ToLocalChecked());
  Nan::Set(target, Nan::New("sha256d").ToLocalChecked(), Nan::GetFunction(Nan::New<FunctionTemplate>(sha256d)).ToLocalChecked());
}

NODE_MODULE(hashing, init)
