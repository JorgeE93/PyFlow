# setup.py
from setuptools import setup
from pybind11.setup_helpers import Pybind11Extension, build_ext
import sys

extra_compile_args = []
if sys.platform == "win32":
    extra_compile_args.append("/EHsc")  # Enable exception handling in MSVC

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
            "src/StateMachine.cpp",
            "src/Events.cpp",
        ],
        include_dirs=[
            "include",
        ],
        language="c++",
        cxx_std=14,
        extra_compile_args=extra_compile_args,
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
    cmdclass={"build_ext": build_ext},
    install_requires=["pybind11>=2.6.0"],
    classifiers=[
        "Programming Language :: Python :: 3",
        "Programming Language :: C++",
        "Operating System :: OS Independent",
    ],
    python_requires=">=3.7",
)

