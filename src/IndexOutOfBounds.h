#ifndef INDEX_OUT_OF_BOUNDS_H
#define INDEX_OUT_OF_BOUNDS_H

#include <stdexcept>

class IndexOutOfBounds : public virtual std::runtime_error {

public:

	IndexOutOfBounds(const char* message) : runtime_error(message) {}

	const char* what() const throw()
	{
		return "Index specified is out of bounds!";
	}

};

#endif /* INDEX_OUT_OF_BOUNDS_H */
