project(say_hello)
cmake_minimum_required(VERSION 2.8)

FIND_PACKAGE(PythonInterp)
FIND_PACKAGE(PythonLibs)
set(PYTHON_LIBRARIES /usr/local/Frameworks/Python.framework/Versions/2.7/Python)
FIND_PACKAGE(Boost COMPONENTS
                system
                thread
                python
             REQUIRED)

include_directories(${PYTHON_INCLUDE_DIRS} ${Boost_INCLUD_DIRS})
link_directories(${PYTHON_LIBRARY_DIRS} ${Boost_LIBRARY_DIRS})

PYTHON_ADD_MODULE(say_hello say_hello.cpp)
target_link_libraries(
   say_hello
  ${Boost_LIBRARIES}
  ${PYTHON_LIBRARIES}
)

add_executable(hello say_hello.cpp)
target_link_libraries(hello
  ${Boost_LIBRARIES}
  ${PYTHON_LIBRARIES})
