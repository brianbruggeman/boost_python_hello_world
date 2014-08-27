#include <iostream>

void say_hello(const char* name) {
    std::cout << "Hello " <<  name << "!\n";
}


int main(){return 0;}

#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
namespace boost {
namespace python {

BOOST_PYTHON_MODULE(hello)
{
    def("say_hello", say_hello);
}
}
}