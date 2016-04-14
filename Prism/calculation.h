#pragma once

#include <string>
#include <memory>
#include <vector>
#include <utility>

struct Slice
{
public:
	Slice(double refractiveIndex, double width, double angle = 0) :n(refractiveIndex), d(width), i(angle), dy(0) {}

	double n;//refractive index
	double d;//width
	double i;//angle

	double dy;//change in y axis when light pass through

	std::string toString();
};

class Chunk
{
public:
	void cal(std::shared_ptr<Slice> previous, std::shared_ptr<Slice> present)
	{
		calculate(previous, present);
	}
	/* using for debug test only, should be removed later. */
	
private:
	std::string info;
	std::shared_ptr<std::vector<Slice>> data;

	void calculate(std::shared_ptr<Slice> previous, std::shared_ptr<Slice> present);
};