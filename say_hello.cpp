#include <iostream>
#include <boost/python/module.hpp>
#include <boost/python/def.hpp>


int main() {
    return 0;
}


void say_hello(const char* name) {
    std::cout << "Hello " <<  name << "!\n";
}

using namespace boost::python;

BOOST_PYTHON_MODULE(say_hello)
{

    def("say_hello", say_hello);
}
