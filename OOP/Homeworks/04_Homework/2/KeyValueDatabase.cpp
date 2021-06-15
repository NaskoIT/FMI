#include <sstream>
#include "KeyValueDatabase.hpp"

KeyValueDatabase::KeyValueDatabase(const std::string &name, const std::string &location, const std::string &extension)
        : Object(name, location, extension) {
}

void KeyValueDatabase::add_entry(const pair<string, int> &entry) {
    if (getEntryIndex(entry.first) != NOT_FOUND_INDEX) {
        throw invalid_argument("This key already exists!");
    }

    entries.push_back(entry);
}

int KeyValueDatabase::get_value(const string &key) const {
    int index = getEntryIndex(key);
    if (index == NOT_FOUND_INDEX) {
        throw invalid_argument("The key was not found!");
    }

    return entries[index].second;
}

bool KeyValueDatabase::operator==(const Comparable *comparable) const {
    const KeyValueDatabase *database = dynamic_cast<const KeyValueDatabase *>(comparable);
    if (!database) {
        return false;
    }

    if (database->entries.size() != this->entries.size()) {
        return false;
    }

    for (const pair<string, int> &kvp : this->entries) {
        int index = database->getEntryIndex(kvp.first);
        if (index == NOT_FOUND_INDEX) {
            return false;
        }

        pair<string, int> entry = database->entries[index];
        if (entry.second != kvp.second) {
            return false;
        }
    }

    return true;
}

bool KeyValueDatabase::operator!=(const Comparable *comparable) const {
    return !this->operator==(comparable);
}

string KeyValueDatabase::to_string() const {
    string result = get_name() + NEW_LINE + get_location() + NEW_LINE + get_extension() + NEW_LINE;
    for (pair<string, int> kvp : entries) {
        result += kvp.first + ':' + std::to_string(kvp.second) + NEW_LINE;
    }

    return result;
}

void KeyValueDatabase::from_string(const string &input) {
    stringstream io(input);

    string newName;
    getline(io, newName, NEW_LINE);
    set_name(newName);

    string newLocation;
    getline(io, newLocation, NEW_LINE);
    set_location(newLocation);

    string newExtension;
    getline(io, newExtension, NEW_LINE);
    set_extension(newExtension);

    entries.clear();

    string temp;
    string key;
    string value;

    while (getline(io, temp, NEW_LINE)) {
        int doublePointIndex = temp.find(':');
        key = temp.substr(0, doublePointIndex);
        temp.erase(0, doublePointIndex + 1);

        value = temp.substr(0, temp.find(NEW_LINE));

        this->add_entry(pair<std::string, int>(key, stoi(value)));
    }
}

string KeyValueDatabase::debug_print() const {
    string debugResult = "";
    for (int i = 0; i < entries.size(); i++) {
        debugResult += "{" + entries[i].first + ':' + std::to_string(entries[i].second) + "}" + NEW_LINE;
    }

    return debugResult;
}

int KeyValueDatabase::getEntryIndex(const string key) const {
    for (int i = 0; i < entries.size(); i++) {
        if (entries[i].first == key) {
            return i;
        }
    }

    return NOT_FOUND_INDEX;
}

