#include "stdafx.h"
#include "calculation.h"

#include <math.h>
#include <sstream>
#include <iterator>

Chunk::Chunk(double length, int slice, double n(double x), std::string information):info(information)
{
	const double d = length / slice;
	for (int k = 0; k < slice; ++k)
	{
		data.push_back(std::make_shared<Slice>(n(k*d), d));
	}
	out = std::make_shared<Slice>(1, 50);
	setEnvironment();
	setIncidentAngle();
}

void Chunk::execute()
{
	auto one = data.begin();

	if (one == data.cend())
	{
		calculate(in, out);
	}
	else
	{
		calculate(in, *one);
		while ((++one) != data.end())
		{
			calculate(*(one - 1), *one);
		}
		calculate(*(one-1), out);
	}
}

void Chunk::print(std::ostream & os)
{
	using std::endl;
	os << "id,n,d,i,dy" << endl;
	os << "in," << in->toString() << endl;
	int k(0);
	for (auto one : data)
	{
		os << ++k << "," << one->toString() << endl;
	}
	os << "out," << out->toString() << endl;;
}

void Chunk::setEnvironment(double n, double d)
{
	in = std::make_shared<Slice>(n, d);
	out = std::make_shared<Slice>(n, d);
}

void Chunk::setIncidentAngle(double angle)
{
	in->i = angle;
}

void Chunk::calculate(std::shared_ptr<Slice> previous, std::shared_ptr<Slice> present)
{
	present->i = asin((previous->n)*sin(previous->i) / (present->n));
	present->dy = (present->d)*tan(present->i);
}

std::string Slice::toString()
{
	std::ostringstream os;

	os << n << "," << d << "," << i << "," << dy;

	return os.str();
}
