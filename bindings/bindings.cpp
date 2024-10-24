// bindings.cpp
#include <pybind11/pybind11.h>
#include <pybind11/functional.h>
#include "pyflow/EventManager.h"
#include "pyflow/Events.h"

namespace py = pybind11;
using namespace pyflow;

PYBIND11_MODULE(pyflow, m) {
    m.doc() = "PyFlow Event System Module";

    // Bind EventBase
    py::class_<EventBase, std::shared_ptr<EventBase>>(m, "EventBase");

    // Bind EventA
    py::class_<EventA, EventBase, std::shared_ptr<EventA>>(m, "EventA")
        .def(py::init<int>())
        .def_readwrite("data", &EventA::data);

    // Bind EventB
    py::class_<EventB, EventBase, std::shared_ptr<EventB>>(m, "EventB")
        .def(py::init<const std::string &>())
        .def_readwrite("message", &EventB::message);

    // Bind EventManager
    py::class_<EventManager>(m, "EventManager")
        .def(py::init<>())
        .def("subscribe_event_a", [](EventManager &self, std::function<void(const EventA &)> func) {
            self.subscribe<EventA>(func);
        })
        .def("subscribe_event_b", [](EventManager &self, std::function<void(const EventB &)> func) {
            self.subscribe<EventB>(func);
        })
        .def("publish", &EventManager::publish);
}

