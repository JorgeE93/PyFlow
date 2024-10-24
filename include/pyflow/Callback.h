// Callback.h
#pragma once

#include "Event.h"
#include <functional>
#include <memory>

namespace pyflow {

class CallbackBase {
public:
    virtual ~CallbackBase() = default;
    virtual void invoke(EventPtr event) = 0;
};

template<typename EventType>
class Callback : public CallbackBase {
public:
    using FuncType = std::function<void(const EventType&)>;

    explicit Callback(FuncType&& func) : func_(std::move(func)) {}

    void invoke(EventPtr event) override {
        auto casted_event = std::static_pointer_cast<EventType>(event);
        func_(*casted_event);
    }

private:
    FuncType func_;
};

} // namespace pyflow

