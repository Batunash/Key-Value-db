#ifndef KEYVALUESTORE_H
#define KEYVALUESTORE_H

#include<map>
#include<string>

class KeyValueStore {
	private:
		std::map<std::string , std::string>store;
		std::string filename;
	public:
		explicit KeyValueStore(const std::string& file);
		void loadFromDisk();
		void appendToDisk(const std::string& commandLine);
		bool exists(const std::string& key) const;
		void set(const std::string& key, const std::string& value);
		bool get(const std::string& key,std::string& value)const;
		bool remove(const std::string& key);
	};
#endif
