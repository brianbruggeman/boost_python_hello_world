// Copyright (c) 2014  Brian Bruggeman - All Rights Reserved
// ---------------------------------------------------------------------
// This is free and unencumbered software released into the public
// domain.
//
// Anyone is free to copy, modify, publish, use, compile, sell, or
// distribute this software, either in source code form or as a compiled
// binary, for any purpose, commercial or non-commercial, and by any
// means.
//
// In jurisdictions that recognize copyright laws, the author or authors
// of this software dedicate any and all copyright interest in the
// software to the public domain. We make this dedication for the
// benefit of the public at large and to the detriment of our heirs and
// successors. We intend this dedication to be an overt act of
// relinquishment in perpetuity of all present and future rights to this
// software under copyright law.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY
// CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
// SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
// For more information, please refer to <http://unlicense.org>
// ---------------------------------------------------------------------
#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
#include <boost/python.hpp>
#include <iostream>


//using namespace boost::python;
using boost::python::def;
using boost::python::object;
using boost::python::dict;
using boost::python::handle;
using boost::python::extract;
using boost::python::import;
using boost::python::borrowed;
using boost::python::error_already_set;
using std::string;
using std::cout;


// C++ function to be embedded within python
void say_hello(const char* name) {
    cout << "Hello " <<  name << "!\n";
}


// Extending python
BOOST_PYTHON_MODULE(say_hello) {
    def("say_hello", say_hello);
}


// Embedding python
int main(int argc, char** argv)
{
    int data = 0;
    Py_Initialize();
    try {
        PyRun_SimpleString("result = 5 ** 2.0");
        PyRun_SimpleString("data = 5");
        object module(handle<>(borrowed(PyImport_AddModule("__main__"))));
        object dictionary = module.attr("__dict__");
        object result = dictionary["result"];
        object data = dictionary["data"];
        // char* data_value = extract<char*>(data);
        float result_value = extract<float>(result);
        std::cout << "5 ** 2 == " << result_value << std::endl;
        dictionary["result"] = 20;
        PyRun_SimpleString("print '5 ** 2 != %s' % (result)");
    } catch (error_already_set& e) {
        PyErr_Print();
    }
    Py_Finalize();
    return 0;
}
