#include "debug.h"

#include <memory>
#include <iostream>
#include <fstream>
#include <math.h>

void debug()
{
	//debugSlice();
	debugChunk();
	

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

void debugChunk()
{
	using std::cout;
	using std::endl;

	auto one = std::make_shared<Chunk>(10, 1000, realfunc);
	cout << "initialized" << endl;

	one->execute();
	cout << "executed" << endl;

	std::ofstream os("00.csv", std::ofstream::out);
	one->print(os);
	os.close();
	os.open("0.csv");
	one->tube(os);
	one->report();
}

double debugfunc(double x)
{
	return 1+x/100;
}

const double nSi = 3.42;
const double nGe = 4.00;

double realfunc(double x)
{
	return sqrt((x / 10.0)*nSi*nSi + (1.0 - x / 10.0)*nGe*nGe);
}

