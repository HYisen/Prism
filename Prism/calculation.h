#pragma once

#include <string>
#include <memory>
#include <vector>
#include <utility>

struct Slice
{
public:
	Slice(double refractiveIndex, double width) :n(refractiveIndex), d(width) {}

	double n;//refractive index
	double d;//width
	double i;//angle

	double dy;//change in y axis when light pass through
};

class Chunk
{
public:
	
private:
	std::string info;
	std::shared_ptr<std::vector<Slice>> data;

	void calculate(std::shared_ptr<Slice> previous, std::shared_ptr<Slice> present);
};