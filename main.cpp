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
#include <iostream>
#include <Python/Python.h>

#include "hello.h"
#include "boost_glue.h"

using std::string;
using std::cout;
using std::endl;

// Embedding python
int main(int argc, char** argv)
{
    int data = 0;
    Py_Initialize();
    try {
        object main = import("__main__");
        // extract the path from the function
        object os = import("os");
        object getcwd = os.attr("getcwd");
        string local_path = extract<string>(getcwd());
        // add local path to sys path
        object sys = import("sys");
        object sys_path = sys.attr("path");
        sys_path.attr("insert")(0, local_path);
        // look for local python version of function
        object path = os.attr("path");
        object exists = path.attr("exists");
        object module(handle<>(borrowed(PyImport_AddModule("__main__"))));
        object dictionary = module.attr("__dict__");
        object global(main.attr("__dict__"));
        object _hello = import("hello");
        _hello.attr("hello")("Extensions");
    } catch (error_already_set& e) {
        hello("Default");
    }
    Py_Finalize();
    return 0;
}
