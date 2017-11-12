#ifndef INTEGER_GREATER_THAN_COMPARATOR_H
#define INTEGER_GREATER_THAN_COMPARATOR_H

class IntegerGreaterThanComparator {

public:

	bool operator()(
		int a,
		int b)
	{
		return a > b;
	}

};

#endif
