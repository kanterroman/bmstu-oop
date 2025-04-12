cmake_minimum_required(VERSION 3.28)
project(lab_02)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab_02 main.cpp
        Iterators/Iterator.h
        Iterators/Iterator.hpp
        Iterators/BaseIterator.h
        Iterators/ConstIterator.h
        Iterators/ConstIterator.hpp
        Exceptions/BaseException.h
        Exceptions/IterExceptions.h
        Vector/BaseVector.h
        Vector/Vector.h
        Vector/Vector.hpp
        Exceptions/VectorExceptions.h
        Vector/VectorConcepts.h)

include_directories(Vector Iterators Exceptions)
