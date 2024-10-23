# Lab1-b Circular Buffer

## General information
A ring buffer is an array whose beginning and end are closed. In particular, this means that when you add elements to the end of the buffer, when its capacity is exhausted, the elements from the beginning of the buffer will begin to be overwritten, and the "beginning" will shift accordingly.

A detailed description of this data structure can be found in the English Wikipedia: http://en.wikipedia.org/wiki/Circular_buffer

An example of a production implementation of a ring buffer is contained in the Boost library:
http://www.boost.org/doc/libs/1_51_0/libs/circular_buffer/doc/circular_buffer.html

## Task
1. Implement a ring buffer with a specified interface (see Implementation).

2. Carefully document public class members in a language close to technical English.

3. Write unit tests for all public methods of the class using any specialized library (Google Test Framework http://code.google.com/p/googletest/ is recommended), or without it (at the discretion of the teacher). Make sure that the code is fully covered by tests (each line of code must be executed by at least one test).