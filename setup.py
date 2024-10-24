# setup.py
from setuptools import setup, Extension
import pybind11
from pybind11.setup_helpers import Pybind11Extension

ext_modules = [
    Pybind11Extension(
        "pyflow",
        [
            "bindings/bindings.cpp",
            "src/Event.cpp",
            "src/EventManager.cpp",
            "src/Callback.cpp",
            "src/State.cpp",
            "src/CompositeState.cpp",
            "src/Events.cpp",
        ],
        include_dirs=[
            pybind11.get_include(),
            "include",  # Include headers from the include directory
        ],
        language="c++",
        cxx_std=14,
    ),
]

setup(
    name="PyFlow",
    version="1.0.0",
    author="Your Name",
    author_email="your.email@example.com",
    description="An event system with type-erased polymorphic callbacks and hierarchical state machines",
    long_description=open("README.md").read(),
    long_description_content_type="text/markdown",
    ext_modules=ext_modules,
    install_requires=["pybind11>=2.6.0"],
    classifiers=[
        "Programming Language :: Python :: 3",
        "Programming Language :: C++",
        "Operating System :: OS Independent",
    ],
    python_requires=">=3.6",
)

