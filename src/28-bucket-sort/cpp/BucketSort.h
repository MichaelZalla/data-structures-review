#ifndef BUCKET_SORT_H
#define BUCKET_SORT_H

#include <vector>

#include "../../utils/Assert.h"

typedef std::vector<int> Bucket;

void bucketSort(
	std::vector<int>& collection)
{


	int size = collection.size();

	assert("Collection is not empty.", size > 0);

	if(size < 2)
	{
		return;
	}

	std::vector<Bucket> buckets(size);

	for(
		std::vector<int>::iterator pos = collection.begin();
		pos != collection.end();
		++pos)
	{
		int key = *pos;

		buckets[key].push_back(key);
	}

	collection.clear();

	assert("Some bucket lists have been populated.", buckets.size() > 0);

	for(
		std::vector<Bucket>::iterator bucketPos = buckets.begin();
		bucketPos != buckets.end();
		++bucketPos)
	{
		Bucket bucket = *bucketPos;

		for(
			Bucket::iterator entryPos = bucket.begin();
			entryPos != bucket.end();
			++entryPos)
		{
			collection.push_back(*entryPos);
		}

	}

	return;

}

#endif
