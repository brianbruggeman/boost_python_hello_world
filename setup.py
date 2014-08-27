from distutils.core import setup
from distutils.extension import Extension

setup(name="PackageName",
    ext_modules=[
        Extension("say_hello", ["say_hello.cpp"],
        libraries = ["boost_python"])
    ])
