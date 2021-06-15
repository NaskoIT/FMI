#include "Repository.hpp"

void Repository::add(Subscriber *subscriber) {
    this->subscribers.push_back(subscriber->clone());
}

Repository::Repository(const Repository &other) {
    copy(other);
}

Repository &Repository::operator=(const Repository &other) {
    if (&other != this) {
        clear();
        copy(other);
    }

    return *this;
}

Repository::~Repository() {
    clear();
}

Subscriber *Repository::get(std::string id) {
    int index = getIndex(id);

    return index == -1 ? nullptr : subscribers[index];
}

bool Repository::remove(std::string id) {
    int index = getIndex(id);
    if (index == -1) {
        return false;
    }

    subscribers.erase(subscribers.begin() + index);
    return true;
}

int Repository::getIndex(std::string id) const {
    for (int i = 0; i < subscribers.size(); ++i) {
        if (subscribers[i]->id == id) {
            return i;
        }
    }

    return -1;
}

vector<Subscriber *> Repository::getSubscribers() const {
    return this->subscribers;
}

void Repository::copy(const Repository &other) {
    for (auto subscriber : other.subscribers) {
        this->subscribers.push_back(subscriber->clone());
    }
}

void Repository::clear() {
    for (auto subscriber : subscribers) {
        delete subscriber;
    }

    subscribers.clear();
}
