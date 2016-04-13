#include "stdafx.h"
#include "calculation.h"

#include <math.h>

void Chunk::calculate(std::shared_ptr<Slice> previous, std::shared_ptr<Slice> present)
{
	present->i = asin((previous->n)*sin(previous->i) / present->n);
	present->dy = (present->d)*sin(present->i);
}
