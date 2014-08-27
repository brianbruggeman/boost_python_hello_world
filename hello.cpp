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
#include <boost/python.hpp>
#include <iostream>

namespace bp = boost::python;

// Embedding python
int main(int argc, char** argv)
{
    int data = 0;
    Py_Initialize();
    PyRun_SimpleString("data = 1");
    bp::object module(bp::handle<>(bp::borrowed(PyImport_AddModule("__main__"))));
    bp::object dictionary = module.attr("__dict__");
    bp::object data_obj = dictionary["data"];
    // Error:  The following line seg-faults
    data = bp::extract<int>(data_obj);
    std::cout << "data = " << data << std::endl;
    Py_Finalize();
    return 0;
}
