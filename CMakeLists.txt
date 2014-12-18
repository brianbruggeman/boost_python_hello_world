project(say_hello)
cmake_minimum_required(VERSION 2.8)

set(PYTHON_LIBRARIES /usr/local/Frameworks/Python.framework/Versions/2.7/Python)
# set(PYTHON_INCLUDE_DIR /usr/local/Cellar/python/2.7.8_2/Frameworks/Python.framework/Headers)

set(CMAKE_C_FLAGS "-march=native -O2 -pipe -ggdb")
set(CMAKE_CXX_FLAGS ${CMAKE_C_FLAGS})


FIND_PACKAGE(PythonInterp)
FIND_PACKAGE(PythonLibs)
FIND_PACKAGE(Boost COMPONENTS
                system
                thread
                filesystem
                python
             REQUIRED)

include_directories(${PYTHON_INCLUDE_DIRS}
                    ${Boost_INCLUD_DIRS}
                    ${CMAKE_SOURCE_DIR})

link_directories(${PYTHON_LIBRARY_DIRS}
                 ${Boost_LIBRARY_DIRS}
                 ${CMAKE_SOURCE_DIR})

PYTHON_ADD_MODULE(_hello
    hello.cpp
    main.cpp)

target_link_libraries(_hello
  ${Boost_LIBRARIES}
  ${PYTHON_LIBRARIES}

)

add_executable(hello
    hello.cpp
    main.cpp)
target_link_libraries(hello
  ${Boost_LIBRARIES}
  ${PYTHON_LIBRARIES})
