#include "stdafx.h"
#include "debug.h"

void debug()
{
	debugSlice();
}

void debugSlice()
{
	using std::cout;
	using std::endl;

	auto one = std::make_shared<Slice>(1, 1, 3.1415925/3);
	auto two = std::make_shared<Slice>(1.5, 1);

	cout << one->toString() << endl;
	cout << two->toString() << endl;

	auto chunk = std::make_shared<Chunk>();
	chunk->cal(one, two);

	cout << one->toString() << endl;
	cout << two->toString() << endl;
}
