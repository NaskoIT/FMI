#include "Object.hpp"

Object::Object(const std::string &name, const std::string &location, const std::string &extension) {
    this->name = name;
    this->location = location;
    this->extension = extension;
}

std::string Object::get_name() const {
    return name;
}

std::string Object::get_location() const {
    return location;
}

std::string Object::get_extension() const {
    return extension;
}

std::string Object::get_fullpath() const {
    return location + "/" + name + "." + extension;
}

void Object::set_name(string &newName) {
    this->name = newName;
}

void Object::set_location(string &newLocation) {
    this->location = newLocation;
}

void Object::set_extension(string &newExtension) {
    this->extension = newExtension;
}
