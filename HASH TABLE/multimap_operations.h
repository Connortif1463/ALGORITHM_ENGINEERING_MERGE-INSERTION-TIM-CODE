#pragma once

#include <unordered_map>
#include <string>

extern std::unordered_multimap<std::string, int> hash_table;

void Insert(const std::string& key, int value);
bool Search(const std::string& key, int value);
bool Delete(const std::string& key, int value);
int Min(const std::string& key);
int Max(const std::string& key);
bool Next(const std::string& key, int value);
bool Prev(const std::string& key, int value);
