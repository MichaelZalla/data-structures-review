#ifndef RADIX_SORT_H
#define RADIX_SORT_H

// #include <iostream>
#include <vector>

#include "../../utils/cpp/Assert.h"

int getFirstDigit(
	int value)
{
	return value % 10;
}

int getDigit(
	int value,
	unsigned int digitIndex)
{
	int remainder = value;

	for(int i = 0; i < digitIndex; i++)
	{
		remainder = remainder / 10;
	}

	return getFirstDigit(remainder);
}

int getDigitCount(
	const int value)
{

	int digitCount = 1;
	int remainder = value;

	// @NOTE(mzalla) 9 serves as our first-digit boundary

	while(remainder > 9)
	{
		digitCount++;

		remainder = remainder / 10;
	}

	return digitCount;

}

int getMax(
	const std::vector<int> sequence)
{

	// @NOTE(mzalla) Alternately we could use std::max_element from <algorithm>;

	std::vector<int>::const_iterator pos = sequence.begin();

	int max = *pos;

	for(; pos != sequence.end(); ++pos)
	{
		if(*pos > max)
		{
			max = *pos;
		}
	}

	return max;

}

void radixSort(
	std::vector<int>& sequence)
{

	// Check base case where sequence is trivially sorted;

	if(sequence.size() < 2)
	{
		return;
	}

	// The number of key components (digits) is determined by the largest key in the input sequence;

	int maxKey = getMax(sequence);

	int digitCount = getDigitCount(maxKey);

	// For each digit (component) in the key(s)

	for(
		int digitIndex = 0;
		digitIndex < digitCount;
		digitIndex++)
	{

		// std::cout << "Sorting by " << digitIndex << "-th digit..." << std::endl;

		// Perform bucket-sort of the sequence elements, using the component as the key for sorting

		std::vector<int> buckets[10] = {};

		// Populate the bucket array

		for(
			std::vector<int>::iterator pos = sequence.begin();
			pos != sequence.end();
			++pos)
		{
			int digit = getDigit(*pos, digitIndex);

			// std::cout << "Element " << *pos << " to be sorted using digit value " << digit << "." << std::endl;

			buckets[digit].push_back(*pos);
		}

		// Rebuild the sequence in local order

		sequence.clear();

		for(int bucketIndex = 0; bucketIndex < 10; bucketIndex++)
		{
			std::vector<int> bucket = buckets[bucketIndex];

			sequence.insert(sequence.end(), bucket.begin(), bucket.end());
		}

	}

}

#endif
