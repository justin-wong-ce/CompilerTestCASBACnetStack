# Compiler Test - CAS BACnet Stack

This project is used to test a compiler to ensure that it supports the prerequisites for the [CAS BACnet Stack](https://store.chipkin.com/services/stacks/bacnet-stack).The CAS BACnet Stack has a requirement for [C++11](https://en.wikipedia.org/wiki/C%2B%2B11) and [Standard Template Library](https://en.wikipedia.org/wiki/Standard_Template_Library) (STL)

Within the STL the CAS BACnet Stack uses the following libary features. These features must be supported by
the compiler: *std::string, std::nothrow, std::vector, std::map, std::stringstream, std::swap, std::list, std::set, std::pair, std::copy, std::ostringstream, std::queue, std::ostream, std::reverse*

## Building

A Visual Studios 2022 project is included for building on Windows.

A simple makefile is included for building on linux.
