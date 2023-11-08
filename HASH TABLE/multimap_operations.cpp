// multimap_operations.cpp
#include "multimap_operations.h"
#include <climits>
#include <iostream>

std::unordered_multimap<std::string, int> hash_table;

void Insert(const std::string& key, int value) {
    hash_table.insert(std::make_pair(key, value));
}

bool Search(const std::string& key, int value) {
    auto range = hash_table.equal_range(key);
    for (auto it = range.first; it != range.second; ++it) {
        if (it->second == value) {
            return true;
        }
    }
    return false;
}

bool Delete(const std::string& key, int value) {
    auto range = hash_table.equal_range(key);
    for (auto it = range.first; it != range.second; /* No increment here */) {
        if (it->second == value) {
            it = hash_table.erase(it);
            return true;
        } else {
            ++it;
        }
    }
    return false;
}

int Min(const std::string& key) {
    auto range = hash_table.equal_range(key);
    int min_value = INT_MAX;
    for (auto it = range.first; it != range.second; ++it) {
        if (it->second < min_value) {
            min_value = it->second;
        }
    }
    return min_value;
}

int Max(const std::string& key) {
    auto range = hash_table.equal_range(key);
    int max_value = INT_MIN;
    for (auto it = range.first; it != range.second; ++it) {
        if (it->second > max_value) {
            max_value = it->second;
        }
    }
    return max_value;
}

bool Next(const std::string& key, int value) {
    auto range = hash_table.equal_range(key);
    bool found = false;
    for (auto it = range.first; it != range.second; ++it) {
        if (found) {
            std::cout << "Next Value: " << it->second << std::endl;
            return true;
        }
        if (it->second == value) {
            found = true;
        }
    }
    return false;
}

bool Prev(const std::string& key, int value) {
    auto range = hash_table.equal_range(key);
    int prev_value = INT_MIN;
    bool found = false;
    for (auto it = range.first; it != range.second; ++it) {
        if (it->second == value) {
            if (found) {
                std::cout << "Previous Value: " << prev_value << std::endl;
                return true;
            }
            found = true;
        }
        prev_value = it->second;
    }
    return false;
}
