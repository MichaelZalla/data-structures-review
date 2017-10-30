#include <stdexcept>

class PriorityQueueEmptyException : std::runtime_error {

public:

	PriorityQueueEmptyException(const char* message) : runtime_error(message) {}

};
