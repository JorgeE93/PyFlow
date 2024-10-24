// main.cpp
#include "pyflow/EventManager.h"
#include "pyflow/Events.h"
#include <iostream>

void onEventA(const pyflow::EventA& event) {
    std::cout << "Received EventA with data: " << event.data << std::endl;
}

void onEventB(const pyflow::EventB& event) {
    std::cout << "Received EventB with message: " << event.message << std::endl;
}

int main() {
    pyflow::EventManager manager;

    // Subscribe to events
    manager.subscribe<pyflow::EventA>(onEventA);
    manager.subscribe<pyflow::EventB>(onEventB);

    // Publish events
    auto event_a = std::make_shared<pyflow::EventA>(42);
    manager.publish(event_a);

    auto event_b = std::make_shared<pyflow::EventB>("Hello, PyFlow!");
    manager.publish(event_b);

    return 0;
}

