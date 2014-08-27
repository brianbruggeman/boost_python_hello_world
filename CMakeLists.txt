project(hello)
cmake_minimum_required(VERSION 2.8)

FIND_PACKAGE(PythonInterp)
FIND_PACKAGE(PythonLibs)
FIND_PACKAGE(Boost COMPONENTS python)

include_directories(${PYTHON_INCLUDE_DIRS} ${Boost_INCLUD_DIRS})
link_directories(${PYTHON_LIBRARY_DIRS} ${Boost_LIBRARY_DIRS})

add_executable(hello hello.cpp)
target_link_libraries(hello
  ${Boost_LIBRARIES}
  ${PYTHON_LIBRARIES})