// Copyright 2014 Brian Bruggeman

#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
#include <iostream>


void say_hello(const char* name) {
    std::cout << "Hello " <<  name << "!\n";
}


using boost::python::def;

BOOST_PYTHON_MODULE(say_hello) {
    def("say_hello", say_hello);
}

int main() {
    return 0;
}
