cmake_minimum_required(VERSION 2.8)
FIND_PACKAGE(PythonInterp)
FIND_PACKAGE(PythonLibs)
FIND_PACKAGE(Boost COMPONENTS python)

PYTHON_ADD_MODULE(say_hello say_hello.cpp)
