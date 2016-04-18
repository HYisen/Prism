#pragma once

#include <string>
#include <memory>
#include <vector>
#include <utility>
#include <iostream>

struct Slice
{
public:
	Slice(double refractiveIndex, double width, double angle = 0) :n(refractiveIndex), d(width), i(angle) {}

	double n;//refractive index
	double d;//width

	double i;//angle
	double dy=0;//change in y axis when light pass through

	std::string toString();
};

class Chunk
{
public:
	Chunk(double length, int slice, double n(double x), std::string information = "None");
	Chunk() = delete;

	void execute();
	void print(std::ostream  &os = std::cout);
	void setEnvironment(double n = 1, double d = 50);
	void setIncidentAngle(double angle = 3.1415926 / 6.0);
	
	void cal(std::shared_ptr<Slice> previous, std::shared_ptr<Slice> present)
	{
		calculate(previous, present);
	}
	/* using for debug test only, should be removed later. */
	
private:
	std::string info;
	std::vector<std::shared_ptr<Slice>> data;
	std::shared_ptr<Slice> in, out;

	void calculate(std::shared_ptr<Slice> previous, std::shared_ptr<Slice> present);
};