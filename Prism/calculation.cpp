#include "stdafx.h"
#include "calculation.h"

#include <math.h>
#include <sstream>

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
