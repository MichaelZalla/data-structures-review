#ifndef INTEGER_COMPARATOR_H
#define INTEGER_COMPARATOR_H

class IntegerComparator {

public:

	bool operator()(int a, int b)
	{
		return a < b;
	}

};

#endif
