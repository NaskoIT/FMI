#include <sstream>
#include "Document.hpp"

Document::Document(const std::string &name, const std::string &location, const std::string &extension)
        : Object(name, location, extension) {
    currentLine = START_LINE;
}

void Document::write_line(const string &line) {
    lines.push_back(line);
}

std::string Document::read_line() {
    if (currentLine >= lines.size()) {
        throw out_of_range("There are no more lines in the document!");
    }

    return lines[currentLine++];
}

std::string Document::read_line(const unsigned int line) {
    if (line <= 0 || line > lines.size()) {
        throw out_of_range("Invalid line!");
    }

    this->currentLine = line;
    return lines[currentLine - 1];
}

bool Document::operator==(const Comparable *comparable) const {
    const Document *document = dynamic_cast<const Document *>(comparable);
    if (!document) {
        return false;
    }
    if (document->lines.size() != this->lines.size()) {
        return false;
    }

    for (int i = 0; i < this->lines.size(); ++i) {
        if (this->lines[i] != document->lines[i]) {
            return false;
        }
    }

    return true;
}

bool Document::operator!=(const Comparable *comparable) const {
    return !this->operator==(comparable);
}

string Document::to_string() const {
    string result = "";
    result += this->get_name() + NEW_LINE + this->get_location() + NEW_LINE + this->get_extension() + NEW_LINE;

    for (const string &line : lines) {
        result += line + NEW_LINE;
    }

    return result;
}

void Document::from_string(const string &input) {
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

    lines.clear();

    string temp;
    while (getline(io, temp, NEW_LINE)) {
        lines.push_back(temp);
    }
}

string Document::debug_print() const {
    string debugResult = "";
    for (int i = 0; i < lines.size(); i++) {
        debugResult += "Line " + std::to_string(i + 1) + ':' + lines[i] + NEW_LINE;
    }

    return debugResult;
}
