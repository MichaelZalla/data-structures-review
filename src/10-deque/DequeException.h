#ifndef DEQUE_EXCEPTION_H
#define DEQUE_EXCEPTION_H

#include <stdexcept>

class DequeEmptyException : public std::runtime_error {

public:

	DequeEmptyException(const char* message) : runtime_error(message) {}

};

#endif
