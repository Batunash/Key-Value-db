#include "KeyValueStore.h"
#include <fstream>
#include <sstream>
#include <iostream>
KeyValueStore::KeyValueStore(const std::string& file) : filename(file) {
    loadFromDisk();
}

void KeyValueStore::loadFromDisk() {
    std::ifstream infile(filename);
    if (!infile.is_open()){
	    std::cout<<"something went wrong"<<std::endl;
	    return;
    }
    std::string line;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::string command, key, value;
        iss >> command >> key;
        std::getline(iss, value);
        if (!value.empty() && value[0] == ' ') value.erase(0, 1);

        if (command == "SET") {
            store[key] = value;
        } else if (command == "DELETE") {
            store.erase(key);
        }
    }
    infile.close();
}

void KeyValueStore::appendToDisk(const std::string& commandLine) {
    std::ofstream outfile(filename, std::ios::app);
    outfile << commandLine << "\n";
    outfile.close();
}

bool KeyValueStore::exists(const std::string& key) const {
    return store.find(key) != store.end();
}

void KeyValueStore::set(const std::string& key, const std::string& value) {
    store[key] = value;
    appendToDisk("SET " + key + " " + value);
}

bool KeyValueStore::get(const std::string& key, std::string& value) const {
    auto it = store.find(key);
    if (it != store.end()) {
        value = it->second;
        return true;
    }
    return false;
}

bool KeyValueStore::remove(const std::string& key) {
    if (store.erase(key)) {
        appendToDisk("DELETE " + key);
        return true;
    }
    return false;
}

