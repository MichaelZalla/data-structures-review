#ifndef QUEUE_EXCEPTION_H
#define QUEUE_EXCEPTION_H

#include <stdexcept>

class QueueEmptyException : public std::runtime_error {

public:

	QueueEmptyException(const char* message) : runtime_error(message) {}

};

class QueueFullException : public std::runtime_error {

public:

	QueueFullException(const char* message) : runtime_error(message) {}

};

#endif
