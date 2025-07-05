#include "KeyValueStore.h"
#include "REPL.h"
#include <iostream>
int main() {
    KeyValueStore kv("data.txt");
    std::cout << "Simple KV Store. Use SET, GET, DELETE, EXIT.\n";
    startREPL(kv);
    return 0;
}

