# C++ Thread Safe Container

This repository will show how to simulate problem and some working solutions for thread safe containers in C++, like **map**.  

Inside folders (like **01-simple**) we have the source of that sample, so you can check the source code, build and execute that.  

## Sample: 01-simple

This sample show how we can simulate the problem (race condition problem).

## Sample: 02-fluentcpp

This sample show how we can solve the problem using ***Louis-Charles Caron*** solution called **safe** library.  

References: 

- https://www.fluentcpp.com/2019/04/26/how-to-write-safe-and-expressive-multi-threaded-code-in-cpp11/
- https://github.com/LouisCharlesC/safe

## How to build and execute

Run the following commands:

> make build  
> make run  

Other commands can be execute, execute ***help*** command:

> make help

## Requirements

- cmake
- C++ 11 compiler