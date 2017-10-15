#include <iostream>

#include "./assert.h"

template <typename T>
class Emptyable {

public:

	virtual Emptyable() {}

	virtual const bool isEmpty() = 0;

protected:

	virtual void assertNotEmpty()
	{

		if(this->isEmpty())
		{
			throw std::runtime_error("List is empty!");
		}

	}

};
