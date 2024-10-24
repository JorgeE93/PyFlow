// EventManager.h
#pragma once

#include "Event.h"
#include "Callback.h"
#include <unordered_map>
#include <vector>
#include <typeindex>
#include <mutex>

namespace pyflow {

class EventManager {
public:
    template<typename EventType>
    void subscribe(std::function<void(const EventType&)> func) {
        std::lock_guard<std::mutex> lock(mutex_);
        auto& callbacks = subscribers_[typeid(EventType)];
        callbacks.emplace_back(std::make_shared<Callback<EventType>>(std::move(func)));
    }

    void publish(EventPtr event) {
        std::lock_guard<std::mutex> lock(mutex_);
        auto it = subscribers_.find(typeid(*event));
        if (it != subscribers_.end()) {
            for (auto& callback : it->second) {
                callback->invoke(event);
            }
        }
    }

private:
    std::unordered_map<std::type_index, std::vector<std::shared_ptr<CallbackBase>>> subscribers_;
    std::mutex mutex_;
};

} // namespace pyflow

