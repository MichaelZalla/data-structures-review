#ifndef INTEGER_LESS_THAN_COMPARATOR_H
#define INTEGER_LESS_THAN_COMPARATOR_H

class IntegerLessThanComparator {

public:

	bool operator()(
		int a,
		int b)
	{
		return a < b;
	}

};

#endif
