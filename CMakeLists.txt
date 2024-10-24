# CMakeLists.txt
cmake_minimum_required(VERSION 3.14)
project(PyFlow)

# Find pybind11
find_package(pybind11 REQUIRED)

# Include directories
include_directories(include)

# Add the library target
add_library(pyflow SHARED
    src/Event.cpp
    src/EventManager.cpp
    src/Callback.cpp
    src/State.cpp
    src/CompositeState.cpp
    src/StateMachine.cpp   # Include StateMachine.cpp
    src/Events.cpp
    bindings/bindings.cpp
)

# Set the C++ standard
set_target_properties(pyflow PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

# Link pybind11
target_link_libraries(pyflow PRIVATE pybind11::module)

