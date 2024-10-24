// Events.h
#pragma once

#include "Event.h"
#include <string>

namespace pyflow {

class EventA : public EventBase {
public:
    int data;
    explicit EventA(int d) : data(d) {}
};

class EventB : public EventBase {
public:
    std::string message;
    explicit EventB(const std::string& msg) : message(msg) {}
};

} // namespace pyflow

