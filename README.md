# C++ Thread Safe Container

This repository will show how to simulate problem and some working solutions for thread safe containers in C++, like **map**.  

Inside folders (like **01-simple**) we have the source of that sample, so you can check the source code, build and execute that.  

## How to build and execute

Run the following commands:

> make build  
> make run  

Other commands can be execute, execute ***help*** command:

> make help

## Requirements

- cmake
- C++ 11 compiler

## Sample: 01-simple

This sample show how we can simulate the problem (race condition problem).

## Sample: 02-fluentcpp

This sample show how we can solve the problem using ***Louis-Charles Caron*** solution called **safe** library.  

References: 

- https://www.fluentcpp.com/2019/04/26/how-to-write-safe-and-expressive-multi-threaded-code-in-cpp11/
- https://github.com/LouisCharlesC/safe

## About the tests

The working solution need output **apple** and **potato** counters with **500** each.

The sample **01-simple** is the related problem.  

The others samples are possible solutions that is working.  

```
> Running all samples...
> Running 01-simple...
cd out/01-simple/ && time ./01-simple
> Result: apple = 326, potato = 332

real	0m0.040s
user	0m0.016s
sys	0m0.056s
> Running 02-fluentcpp...
cd out/02-fluentcpp/ && time ./02-fluentcpp
> Result: apple = 500, potato = 500

real	0m0.060s
user	0m0.020s
sys	0m0.065s
> Running 03-std...
cd out/03-std/ && time ./03-std
> Result: apple = 500, potato = 500

real	0m0.063s
user	0m0.021s
sys	0m0.067s
```
