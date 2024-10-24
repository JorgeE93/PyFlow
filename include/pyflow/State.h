// State.h
#pragma once

#include "Event.h"
#include <memory>

namespace pyflow {

class StateMachine; // Forward declaration

class State {
public:
    virtual ~State() = default;

    virtual void onEntry() {}
    virtual void onExit() {}
    virtual bool handleEvent(const EventPtr& event) = 0;

    void setStateMachine(StateMachine* machine) {
        state_machine_ = machine;
    }

protected:
    StateMachine* state_machine_ = nullptr;
};

} // namespace pyflow

