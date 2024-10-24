// CompositeState.h
#pragma once

#include "State.h"
#include <memory>

namespace pyflow {

class CompositeState : public State {
public:
    void onEntry() override {
        if (initial_state_) {
            initial_state_->onEntry();
            current_state_ = initial_state_;
        }
    }

    void onExit() override {
        if (current_state_) {
            current_state_->onExit();
        }
    }

    bool handleEvent(const EventPtr& event) override {
        if (current_state_ && current_state_->handleEvent(event)) {
            return true;
        }
        // Handle event at this level if not handled by substates
        return false;
    }

    void setInitialState(std::shared_ptr<State> state) {
        initial_state_ = state;
        state->setStateMachine(state_machine_);
    }

    void changeState(std::shared_ptr<State> state) {
        if (current_state_) {
            current_state_->onExit();
        }
        current_state_ = state;
        current_state_->setStateMachine(state_machine_);
        current_state_->onEntry();
    }

private:
    std::shared_ptr<State> initial_state_;
    std::shared_ptr<State> current_state_;
};

} // namespace pyflow

