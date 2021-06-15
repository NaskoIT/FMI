#pragma once

#include "Object.hpp"
#include <vector>

using namespace std;

const int NOT_FOUND_INDEX = -1;

class KeyValueDatabase : public Object {
private:
    vector<pair<string, int>> entries;

    int getEntryIndex(const string key) const;

public:
    KeyValueDatabase(const std::string &name, const std::string &location, const std::string &extension);

    void add_entry(const std::pair<std::string, int> &entry);

    int get_value(const std::string &key) const;

    bool operator==(const Comparable *comparable) const override;

    bool operator!=(const Comparable *comparable) const override;

    string to_string() const override;

    void from_string(const string &input) override;

    string debug_print() const override;
};
