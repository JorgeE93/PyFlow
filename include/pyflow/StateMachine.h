// StateMachine.h
#pragma once

#include "State.h"
#include "Event.h"
#include <memory>

namespace pyflow {

class StateMachine {
public:
    explicit StateMachine(std::shared_ptr<State> initial_state)
        : current_state_(std::move(initial_state)) {
        if (current_state_) {
            current_state_->setStateMachine(this);
            current_state_->onEntry();
        }
    }

    void handleEvent(const EventPtr& event) {
        if (current_state_) {
            if (!current_state_->handleEvent(event)) {
                // Optionally handle unhandled events at the state machine level
            }
        }
    }

    void changeState(std::shared_ptr<State> new_state) {
        if (current_state_) {
            current_state_->onExit();
        }
        current_state_ = std::move(new_state);
        if (current_state_) {
            current_state_->setStateMachine(this);
            current_state_->onEntry();
        }
    }

private:
    std::shared_ptr<State> current_state_;
};

} // namespace pyflow

