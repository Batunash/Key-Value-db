#ifndef COMMANDS_H
#define COMMANDS_H

#include "KeyValueStore.h"
#include <string>

void executeSet(KeyValueStore& kv, const std::string& args);
void executeGet(KeyValueStore& kv, const std::string& args);
void executeDelete(KeyValueStore& kv, const std::string& args);

#endif

