#ifndef STACK_EXCEPTION_H
#define STACK_EXCEPTION_H

#include <stdexcept>

class StackEmptyException : public std::runtime_error {

public:

	StackEmptyException(const char* message) : runtime_error(message) {}

};

class StackFullException : public std::runtime_error {

public:

	StackFullException(const char* message) : runtime_error(message) {}

};

#endif
