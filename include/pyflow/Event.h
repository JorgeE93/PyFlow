// Event.h
#pragma once

#include <memory>

namespace pyflow {

class EventBase {
public:
    virtual ~EventBase() = default;
};

using EventPtr = std::shared_ptr<EventBase>;

} // namespace pyflow
