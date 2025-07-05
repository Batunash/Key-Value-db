#include "Commands.h"
#include <iostream>
#include <sstream>
void executeSet(KeyValueStore& kv, const std::string& args){
	std::istringstream iss(args);
	std::string key,value;
	iss>>key;
	std::getline(iss,value);
	if(!value.empty() && value[0]== ' ') value.erase(0,1);
	if key.empty()||value.empty()){
		std::cout<<"usage <key> <value>\n";
		return;
	}
	kv.handleSet(key, value);
}

void executeGet(KeyValueStore& kv,const std::string& args){
	std::istringstream iss(args);
	std::string key;
	iss>>key;
	if(key.empty()){
		std::cout<<"usage <key>\n";
		return;
	}
	kv.handleGet(key);
}

