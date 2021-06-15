#pragma once

#include "Comparable.hpp"
#include "Debug.hpp"
#include "Serializable.hpp"

using namespace std;

const char NEW_LINE = '\n';

class Object : public Comparable, public Debug, public Serializable {
protected:
    string name;
    string location;
    string extension;

public:
    Object(const std::string &name, const std::string &location, const std::string &extension);

    string get_name() const;

    void set_name(string &newName);

    string get_location() const;

    void set_location(string &newLocation);

    string get_extension() const;

    void set_extension(string &newExtension);

    string get_fullpath() const;
};